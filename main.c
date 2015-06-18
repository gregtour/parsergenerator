// LR Parser

#define malloc malloc
#include <stdlib.h>
#include "lr_parser.h"

// memory tracker
#ifdef _MEM_TRACKING
int gTotalMemoryUsage = 0;
int gMallocCalls = 0;
int gFreeCalls = 0;

#ifdef malloc
#undef malloc
#endif

#ifdef free
#undef free
#endif

void* MallocTrackMemory(size_t size)
{
    gTotalMemoryUsage += (int)size; // gTotalMemoryUsage + size;
    gMallocCalls++;
    return malloc(size);
}

void FreeTrackMemory(void* data)
{
    free(data);
    gFreeCalls++;
    return;
}

#ifndef malloc
#define malloc      MallocTrackMemory
#endif

#ifndef free
#define free        FreeTrackMemory
#endif

void PrintMemoryUsage()
{
    int b = gTotalMemoryUsage % 1000;
    int kb = (gTotalMemoryUsage / 1000) % 1000;
    int mb = (gTotalMemoryUsage / 1000000) % 1000;
    if (mb) {
        printf("Total memory usage: %i.%i mb\n", mb, kb);
    } else {
        printf("Total memory usage: %i.%i kb\n", kb, b);
    }

    printf("%i calls to malloc() with %i calls to free()\n", 
        gMallocCalls, 
        gFreeCalls);
}
#endif // _MEM_TRACKING

int ParserGenerator(const char* language,
                    const char* compiler)
{
    GRAMMAR_TABLE grammar;
    LR_TABLE      parser;
    int           error;

    printf("\n");

    // load grammar
    error = LoadGrammar(language, &grammar);
    if (error)
    {
        printf("Error loading context free grammar file\n");
        FreeGrammarTable(&grammar);
        PrintMemoryUsage();
        return 1;
    }
    PrintGrammar(grammar);

    // build parse tables
    error = BuildLRParser(grammar, &parser);
    if (error)
    {
        printf("Error building canonical LR parse tables.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        PrintMemoryUsage();
        return 2;
    }
    PrintLRParser(parser, grammar);
    
    error = SaveLRParser(compiler, parser, grammar);
    if (error)
    {
        printf("Failed to generate parser.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        return 3;
    }
    
    printf("Successfully generated parser!\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    PrintMemoryUsage();
    return 0;
}

int TestParser(const char* language,
               const char* program)
{
    GRAMMAR_TABLE grammar;
    LR_TABLE      parser;
    L_TOKEN*      lexing;
    SYNTAX_TREE*  ast;
    char*         buffer;
    int           error;

    printf("\n");

    // load grammar
    error = LoadGrammar(language, &grammar);
    if (error)
    {
        printf("Error loading context free grammar file\n");
        FreeGrammarTable(&grammar);
        PrintMemoryUsage();
        return 1;
    }
    PrintGrammar(grammar);

    // build parse tables
    error = BuildLRParser(grammar, &parser);
    if (error)
    {
        printf("Error building canonical LR parse tables.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        PrintMemoryUsage();
        return 2;
    }
    PrintLRParser(parser, grammar);

    // lex source
    buffer = 0;
    lexing = LexSource(program, &buffer, grammar);
    if (lexing == NULL)
    {
        printf("Error lexing source or empty source file.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        FreeLexing(lexing, buffer);
        PrintMemoryUsage();
        return 3;
    }
    PrintLexing(lexing);

    // parse source
    ast = ParseSource(lexing, parser, grammar);
    if (ast == NULL)
    {
        printf("Error parsing source.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        FreeLexing(lexing, buffer);
        //FreeParseTree(parseTree);
        PrintMemoryUsage();
        return 4;
    }
    PrintParseTree(ast, grammar);

    printf("Success.\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    FreeLexing(lexing, buffer);
    //FreeParseTree(ast);
    PrintMemoryUsage();
    getchar();
    return 0;
}

void ReduceProgramAST(SYNTAX_TREE** program);
int GenerateParserAndTest(const char* language, 
                          const char* program, 
                          const char* output)
{
    GRAMMAR_TABLE grammar;
    LR_TABLE      parser;
    L_TOKEN*      lexing;
    SYNTAX_TREE*  ast;
    char*         buffer;
    int           error;

    printf("\n");

    // load grammar
    error = LoadGrammar(language, &grammar);
    if (error)
    {
        printf("Error loading context free grammar file\n");
        FreeGrammarTable(&grammar);
        PrintMemoryUsage();
        return 1;
    }
    PrintGrammar(grammar);

    // build parse tables
    error = BuildLRParser(grammar, &parser);
    if (error)
    {
        printf("Error building canonical LR parse tables.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        PrintMemoryUsage();
        return 2;
    }
    PrintLRParser(parser, grammar);
    
    error = SaveLRParser(output, parser, grammar);
    if (error)
    {
        printf("Failed to generate parser.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        return 3;
    }

	getchar();
// ////////////////////////////////

    // lex source
    buffer = 0;
    lexing = LexSource(program, &buffer, grammar);
    if (lexing == NULL)
    {
        printf("Error lexing source or empty source file.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        FreeLexing(lexing, buffer);
        PrintMemoryUsage();
        return 3;
    }
    PrintLexing(lexing);

    // parse source
    ast = ParseSource(lexing, parser, grammar);
    if (ast == NULL)
    {
        printf("Error parsing source.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        FreeLexing(lexing, buffer);
        //FreeParseTree(parseTree);
        PrintMemoryUsage();
        return 4;
    }
	ReduceProgramAST(&ast);
    PrintParseTree(ast, grammar);

    printf("Success.\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    FreeLexing(lexing, buffer);
    FreeParseTree(ast);
    PrintMemoryUsage();
    getchar();
    return 0;

// ////////////////////////////////
    
    printf("Successfully generated parser!\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    PrintMemoryUsage();
    return 0;
}

void ReduceProgramAST(SYNTAX_TREE** program)
{
    const unsigned int empty_production = 0xFF;
    
	//unsigned int child0_productions[] = { 35, 38, 40, 47, 50, 54, 57, 62 };
	unsigned int reducibleTokens[] = { 0x100A, 0x100D, 0x100E, 0x100F, 0x1010, 0x1011, 0x1012 };
    unsigned int i; 
    unsigned int reducible = 1;
    // continue while reducible
    while (reducible)
    {
        reducible = 0;

        /* productions that reduce to node->children[0] */
        /* 35, 38, 40, 47, 50, 54, 57 */
        //for (i = 0; i < sizeof(child0_productions)/sizeof(int); i++)
		for (i = 0; i < sizeof(reducibleTokens)/sizeof(int); i++)
        {
            if ((*program)->token == reducibleTokens[i] &&
				(*program)->numChildren == 1)
            {
                SYNTAX_TREE* cur = *program;
                unsigned int child;

                for (child = 1; child < cur->numChildren; child++)
                {
                    FreeParseTree(cur->children[child]);
                }

                *program = (*program)->children[0];
                free(cur->children);
                free(cur);
                reducible = 1;
            }
        }
    }

    // apply for all sub-trees
    for (i = 0; i < (*program)->numChildren; i++)
    {
        ReduceProgramAST(&(*program)->children[i]);
    }
}

// compiler frontend
int main(int argc, char** argv)
{
    int           error;

    GenerateParserAndTest("static-syntax.txt", "static-test.txt", "output/strongly_typed");
    getchar();
    return 0;
}
