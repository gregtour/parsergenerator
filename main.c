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

#ifdef ADDRESS_TRACKING
typedef struct MEMTRACK
{
    void* data;
    int lineNum;
    const char* sourceFile;
    unsigned int size;
    int unfreed;
} MEMTRACK;

#define MAX_COUNT   5120
unsigned int index_m = 0;
MEMTRACK indices[MAX_COUNT];
#endif

#ifndef ADDRESS_TRACKING
void* MallocTrackMemory(size_t size)
#else
void* MallocTrackMemory(size_t size, int lineNumber, const char* sourceFile)
#endif
{
    void* data;
    gTotalMemoryUsage += (int)size; // gTotalMemoryUsage + size;
    gMallocCalls++;
    data = malloc(size);
#ifdef ADDRESS_TRACKING
    if (index_m < MAX_COUNT)
    {
        indices[index_m].data = data;
        indices[index_m].lineNum = lineNumber;
        indices[index_m].sourceFile = sourceFile;
        indices[index_m].unfreed = 1;
        indices[index_m].size = size;
        index_m++;
    }
#endif
    return data;
}

void FreeTrackMemory(void* data)
{
#ifdef ADDRESS_TRACKING
    unsigned int i;
    for (i = 0; i < index_m; i++)
    {
        if (indices[i].data == data
            && indices[i].unfreed == 1)
        {
            indices[i].unfreed = 0;
            break;
        }
    }
#endif

    if (data == NULL) return;
    free(data);
    gFreeCalls++;
}

#ifndef malloc
#define malloc      MallocTrackMemory
#endif

#ifndef free
#define free        FreeTrackMemory
#endif

void PrintMemoryUsage()
{
#ifdef ADDRESS_TRACKING
    unsigned int count = 0;
    unsigned int i = 0;
#endif

    int b = gTotalMemoryUsage % 1000;
    int kb = (gTotalMemoryUsage / 1000) % 1000;
    int mb = (gTotalMemoryUsage / 1000000) % 1000;
    if (mb) {
        printf("Total memory usage: %i.%i mb\n", mb, kb);
    } else {
        printf("Total memory usage: %i.%i kb\n", kb, b);
    }

    printf("%i calls to malloc() with %i calls to free()\n\n", 
        gMallocCalls, 
        gFreeCalls);

    printf("Analyzing unfreed blocks...\n");

#ifdef ADDRESS_TRACKING
    for (i = 0; i < index_m; i++)
    {
        if (indices[i].unfreed)
        {
            count++;
            printf("(%i.) Block of %i bytes starting at 0x%p has not been freed. Allocation from %s at line %i.\n", 
                count, indices[i].size, indices[i].data, indices[i].sourceFile, indices[i].lineNum);
        }
    }
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
    PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
        return 4;
    }
    PrintParseTree(ast, grammar);

    printf("Success.\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    FreeLexing(lexing, buffer);
    FreeParseTree(ast);
#ifdef _MEM_TRACKING
    PrintMemoryUsage();
#endif
    getchar();
    return 0;
}

int GenerateParserAndTest(const char* language, 
                          const char* program, 
                          const char* output)
{
    GRAMMAR_TABLE grammar;
    LR_TABLE      parser;
    L_TOKEN*      lexing;
    SYNTAX_TREE*  ast;
    char*         buffer;
    int           result;
    int           error;

    printf("\n");

    // load grammar
    error = LoadGrammar(language, &grammar);
    if (error)
    {
        printf("Error loading context free grammar file\n");
        FreeGrammarTable(&grammar);
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
        return 2;
    }
    PrintLRParser(parser, grammar);
    
    error = SaveLRParser(output, parser, grammar);
    if (error)
    {
        printf("Failed to generate parser.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
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
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
        return 3;
    }
    PrintLexing(lexing);


    result = ParseSucceeds(lexing, parser, grammar);
    printf("Result: %i\n\n", result);

    // parse source
    ast = ParseSource(lexing, parser, grammar);
    if (ast == NULL)
    {
        printf("Error parsing source.\n");
        FreeGrammarTable(&grammar);
        FreeLRParser(&parser);
        FreeLexing(lexing, buffer);
#ifdef _MEM_TRACKING
        PrintMemoryUsage();
#endif
        return 4;
    }
    PrintParseTree(ast, grammar);

    printf("Success.\n");
    FreeGrammarTable(&grammar);
    FreeLRParser(&parser);
    FreeLexing(lexing, buffer);
    FreeParseTree(ast);
#ifdef _MEM_TRACKING
    PrintMemoryUsage();
#endif
    getchar();
    return 0;
}

// compiler frontend
int main(int argc, char** argv)
{
    int error = 0;

    GenerateParserAndTest("duck2.cfg", "test.duck", "output/duck");
    getchar();
    return error;
}
