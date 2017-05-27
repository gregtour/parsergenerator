/* generator.c */

#include "lr_parser.h"


#define gRuleNameBufferLength       32
char gRuleNameBuffer[gRuleNameBufferLength];

unsigned int IsSyntax(int token, GRAMMAR_TABLE grammar)
{
    const char* name = GetElement(token, grammar);
    unsigned int isSyntax = 1;

    int i;
    for (i = 0; name && name[i]; i++)
    {
        if (isAlpha(name[i]) || isNumeric(name[i]))
        {
            isSyntax = 0;
            break;
        }
    }

    return isSyntax;
}

const char* RuleName(int r, GRAMMAR_TABLE grammar)
{
    const char* name;
    int i, j;
    int capitalize = 1;
    int index, count;

    name = GetElement(grammar.rules[r].lhs, grammar);
    for (j = 0, i = 0; name[j]; j++)
    {
        if (i == gRuleNameBufferLength - 3) break;
        if (name[j] != '<' && name[j] != '>')
        {
            if (isAlpha(name[j]))
            {
                if (capitalize &&
                    name[j] <= 'z' && name[j] >= 'a')
                {
                    gRuleNameBuffer[i++] = name[j] - 'a' + 'A';
                }
                else
                {
                    gRuleNameBuffer[i++] = name[j];
                }
                capitalize = 0;
            }
            else if (isNumeric(name[j]))
            {
                gRuleNameBuffer[i++] = name[j];
                capitalize = 1;
            }
            else if (name[j] == '+' && i < gRuleNameBufferLength-6)
            {
                gRuleNameBuffer[i++] = 'P';
                gRuleNameBuffer[i++] = 'l';
                gRuleNameBuffer[i++] = 'u';
                gRuleNameBuffer[i++] = 's';
                capitalize = 1;
            }
            else if (name[j] == '*' && i < gRuleNameBufferLength-6)
            {
                gRuleNameBuffer[i++] = 'S';
                gRuleNameBuffer[i++] = 't';
                gRuleNameBuffer[i++] = 'a';
                gRuleNameBuffer[i++] = 'r';
                capitalize = 1;
            }
            else
            {
                capitalize = 1;
            }
        }
    }
    
    count = 0;
    index = 0;
    for (j = 0; j < grammar.numRules; j++)
    {
        if (grammar.rules[j].lhs == grammar.rules[r].lhs)
            count++;
        if (j == r)
            index = count;
    }
    
    if (count > 1)
    {
        gRuleNameBuffer[i++] = 'A' + ((index-1) % 26);
        index = (index - 1) / 26;
        if (index) gRuleNameBuffer[i++] = 'A' + ((index-1) % 26);
    }
    gRuleNameBuffer[i] = '\0';
    return gRuleNameBuffer;
}

/* define constants for language symbols */
void SaveDefines(FILE* file, GRAMMAR_TABLE grammar)
{
    int i, j, chars;
    const char* name;
    int index, count;
    
    // symbols
    fprintf(file, "/* symbol constants */\n");
    for (i = 1; i <= grammar.numSymbols; i++)
    {
        fprintf(file, "#define SYMBOL_");
        name = GetElement(i | K_SYMBOL, grammar);
        for (j = 0, chars = 0; name[j]; j++)
        {
            if (name[j] != '<' && name[j] != '>')
            {
                if (isAlpha(name[j]))
                {
                    if (name[j] <= 'z' && name[j] >= 'a')
                        fprintf(file, "%c", name[j] - 'a' + 'A');
                    else
                        fprintf(file, "%c", name[j]);
                }
                else if (isNumeric(name[j]))
                {
                    fprintf(file, "%c", name[j]);
                }
                else if (name[j] == '+')
                {
                    fprintf(file, "_PLUS");
                    chars += 4;
                }
                else if (name[j] == '*')
                {
                    fprintf(file, "_STAR");
                    chars += 4;
                }
                else
                {
                    fprintf(file, "_");
                }
                chars++;
            }
        }
        
        while (++chars < 28) { fprintf(file, " "); }
        fprintf(file, "0x%.4X", i | K_SYMBOL);
        fprintf(file, "\n");
    }
    fprintf(file, "\n\n");

    // productions
    fprintf(file, "/* production constants */\n");
    for (i = 1; i < grammar.numRules; i++)
    {
        fprintf(file, "#define PROD_");

        name = GetElement(grammar.rules[i].lhs, grammar);
        for (j = 0, chars = 0; name[j]; j++)
        {
            if (name[j] != '<' && name[j] != '>')
            {
                if (isAlpha(name[j]))
                {
                    if (name[j] <= 'z' && name[j] >= 'a')
                        fprintf(file, "%c", name[j] - 'a' + 'A');
                    else
                        fprintf(file, "%c", name[j]);
                }
                else if (isNumeric(name[j]))
                {
                    fprintf(file, "%c", name[j]);
                }
                else if (name[j] == '+')
                {
                    fprintf(file, "_PLUS");
                    chars += 4;
                }
                else if (name[j] == '*')
                {
                    fprintf(file, "_STAR");
                    chars += 4;
                }
                else
                {
                    fprintf(file, "_");
                }
                chars++;
            }
        }

        if (grammar.rules[i].rhsLength > 0
            && !IsSyntax(grammar.rules[i].rhs[0], grammar))
        {
            name = GetElement(grammar.rules[i].rhs[0], grammar);
            fprintf(file, "_"); chars++;

            for (j = 0; name[j]; j++)
            {
                if (name[j] != '<' && name[j] != '>')
                {
                    if (isAlpha(name[j]))
                    {
                        if (name[j] <= 'z' && name[j] >= 'a')
                            fprintf(file, "%c", name[j] - 'a' + 'A');
                        else
                            fprintf(file, "%c", name[j]);
                    }
                    else if (isNumeric(name[j]))
                    {
                        fprintf(file, "%c", name[j]);
                    }
                    else if (name[j] == '+')
                    {
                        fprintf(file, "_PLUS");
                        chars += 4;
                    }
                    else if (name[j] == '*')
                    {
                        fprintf(file, "_STAR");
                        chars += 4;
                    }
                    else
                    {
                        fprintf(file, "_");
                    }
                    chars++;
                }
            }
        }

        count = 0;
        index = 0;
        for (j = 0; j < grammar.numRules; j++)
        {
            if (grammar.rules[j].lhs == grammar.rules[i].lhs &&
                ((grammar.rules[i].rhsLength == 0 && grammar.rules[j].rhsLength == 0) ||
                 (grammar.rules[j].rhs[0] == grammar.rules[i].rhs[0]) ||
                 (IsSyntax(grammar.rules[i].rhs[0], grammar) && 
                  IsSyntax(grammar.rules[j].rhs[0], grammar))))
            {
                count++;
            }
            if (j == i)
            {
                index = count;
            }
        }
    
        if (count > 1)
        {
            fprintf(file, "_"); chars++;
            fprintf(file, "%c", 'A' + ((index-1) % 26)); chars++;
            while (index)
            {
                index = (index - 1) / 26;
                if (index) 
                { 
                    fprintf(file, "%c", 'A' + ((index-1) % 26)); 
                    chars++;
                }
            }
        }
        
        while (++chars < 39) { fprintf(file, " "); }
        fprintf(file, " ");
        fprintf(file, "0x%.4X", i);
        fprintf(file, "\n");
    }
    fprintf(file, "\n\n");
}

/* *** */
void SaveJSTables(FILE* file, GRAMMAR_TABLE grammar, LR_TABLE parser) 
{
    int* gotoTable = parser.gotoTable;
    ACTION* actionTable = parser.actionTable;
    unsigned int gotoLength = parser.numSymbols * parser.numStates;
    unsigned int actionLength = parser.numStates * parser.numTokens;
    unsigned int start, end, count = 0;
    unsigned int s, t;

    const int GOTO_NIL = -1;

    fprintf(file, 
        "/* DUCK LANGUAGE PARSER AND GRAMMAR */\n"
        "var GRAMMAR = {\n"
        "  tokens: [\""
    );

    int j = grammar.numTokens;
    for (int i = 0; j; i++) {
        if (grammar.tokens[i] == 0) {
            j--;
            if (j) {
                fprintf(file, "\",\"");
            } else {
                fprintf(file, "\"");
            }
        } else {
            char character = grammar.tokens[i];
            if (character == '"' || character == '\'') {
                fprintf(file, "\\");
            }
            fprintf(file, "%c", character);
        }
    }

    fprintf(file, 
        "],\n"
        "  symbols: [\""
    );
    
    j = grammar.numSymbols;
    for (int i = 0; j; i++) {
        if (grammar.symbols[i] == 0) {
            j--;
            if (j) {
                fprintf(file, "\",\"");
            } else {
                fprintf(file, "\"");
            }
        } else {
            char character = grammar.symbols[i];
            if (character == '"' || character == '\'') {
                fprintf(file, "\\");
            }
            fprintf(file, "%c", character);
        }
    }

    fprintf(file, 
        "],\n"
        "  ruleSymbol: ["
    );

    for (int i = 0; i < grammar.numRules; i++) {
        if (i) {
            fprintf(file, ",");
        }
        int symbol = grammar.rules[i].lhs;
        if (symbol & K_SYMBOL) symbol ^= K_SYMBOL;
        fprintf(file, "%i", symbol);
    }

    fprintf(file, 
        "],\n"
        "  ruleLen: ["
    );

    for (int i = 0; i < grammar.numRules; i++) {
        if (i) {
            fprintf(file, ",");
        }
        fprintf(file, "%i", grammar.rules[i].rhsLength);
    }

    fprintf(file, 
        "],\n"
        "  numRules: %i\n};\n",
        grammar.numRules
    );



    fprintf(file, 
        "var PARSER = {\n  GOTO_TABLE: [],\n  ACTION_TABLE: [],\n  numTokens: %i,\n  numSymbols: %i,\n  numStates: %i\n};\n"
        "/* TABLE ROUTINES */\n"
        "var X = function(data)\n{\n"
        "  for (var a = 0; a < data.length; a += 2)\n  {\n"
        "    var index = data[a], sequence = data[a+1];\n"
        "    for (var i = 0; i < sequence.length; i++)\n"
        "      PARSER.GOTO_TABLE[index+i] = sequence[i];\n"
        "  }\n};\n"
        "var Z = function(data)\n{\n"
        "  for (var a = 0; a < data.length; a += 2)\n  {\n"
        "    var index = data[a], sequence = data[a+1];\n"
        "    for (var i = 0, j = 0; j < sequence.length; i++,j+=2)\n"
        "      PARSER.ACTION_TABLE[index+i] = {\"type\": sequence[j], \"value\": sequence[j+1]};\n"
        "  }\n};\n",
        parser.numTokens, parser.numSymbols, parser.numStates
    );

    fprintf(file, "/* GOTO TABLE */\n");

    start = 0;
    fprintf(file, "X([\n");
    while (start < gotoLength) {
        if (gotoTable[start] == GOTO_NIL) {
            start++;
        } else {
            if (count) fprintf(file, ",\n");
            fprintf(file, "%i,[", start);
            for (end = start; end < gotoLength; end++) {
                if (gotoTable[end] == GOTO_NIL) break;
                if (end != start) fprintf(file, ",");
                fprintf(file, "%i", gotoTable[end]);
            }
            fprintf(file, "]");
            start = end;
            count++;
        }
    }
    fprintf(file, "\n]);\n");

    fprintf(file, "\n/* ACTION TABLE */\n");

    count = 0; start = 0;
    fprintf(file, "Z([\n");
    while (start < actionLength) {
        if (actionTable[start].type == ACTION_ERROR) {
            start++; 
        } else {
            if (count) fprintf(file, ",\n");
            fprintf(file, "%i,[", start);
            for (end = start; end < actionLength; end++) {
                if (actionTable[end].type == ACTION_ERROR) break;
                if (end != start) fprintf(file, ",");
                fprintf(file, "%i,%i", actionTable[end].type, actionTable[end].value);
            }
            fprintf(file, "]");
            start = end;
            count++;
        }
    }

    fprintf(file, "\n]);\n");

}

/*

void SaveProductions(FILE*         file,
                     LR_TABLE      parser,
                     GRAMMAR_TABLE grammar)
{
    RULE rule;
    int r, rhs;
    const char* name;
    int j, count, index;

    fprintf(file, "/* production stubs *\/\n\n");
    for (r = 1; r < grammar.numRules; r++)
    {
        rule = grammar.rules[r];

        fprintf(file, "/* ");
        fprintf(file, "%i. ", r);
        fprintf(file, "%s -> ", GetElement(rule.lhs, grammar));
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            fprintf(file, "%s ", GetElement(rule.rhs[rhs], grammar));
        }
        fprintf(file, "*\/\n");
        
        fprintf(file, "int Reduce%s(SYNTAX_TREE* node)\n",
            RuleName(r, grammar));
        fprintf(file, "{\n");
        //fprintf(file, "    if (node->numChildren != %i) return %i;\n",
        //    rule.rhsLength, r);
        fprintf(file, "    Assert(node->numChildren == %i);\n", rule.rhsLength);
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            int symbol = rule.rhs[rhs];
            if (symbol & K_SYMBOL ||
                symbol == gSymbolInteger ||
                symbol == gSymbolFloat ||
                symbol == gSymbolString ||
                symbol == gSymbolIdentifier)
            {
                fprintf(file, "    SYNTAX_TREE* ");
                
                name = GetElement(symbol, grammar);
                for (j = 0; name[j]; j++)
                {
                    if (name[j] != '<' && name[j] != '>')
                    {
                        if (isAlpha(name[j]) || isNumeric(name[j]))
                            fprintf(file, "%c", name[j]);
                        else
                            fprintf(file, "_");
                    }
                }
                
                count = 0;
                for (j = 0; j < rule.rhsLength; j++)
                {
                    if (rule.rhs[j] == symbol)
                        count++;
                    if (j == rhs)
                        index = count;
                }
                
                fprintf(file, "%i", index);
                
                fprintf(file, " = ");
                fprintf(file, "node->children[%i];\n", rhs);
            }
        }
        
        fprintf(file, "\n");
        fprintf(file, "    int error = 0;\n");
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            int symbol = rule.rhs[rhs];
            if (symbol & K_SYMBOL ||
                symbol == gSymbolInteger ||
                symbol == gSymbolFloat ||
                symbol == gSymbolString ||
                symbol == gSymbolIdentifier)
            {
                fprintf(file, "    error = (error ? error : ProcessNode(");

                name = GetElement(symbol, grammar);
                for (j = 0; name[j]; j++)
                {
                    if (name[j] != '<' && name[j] != '>')
                    {
                        if (isAlpha(name[j]) || isNumeric(name[j]))
                            fprintf(file, "%c", name[j]);
                        else
                            fprintf(file, "_");
                    }
                }

                count = 0;
                for (j = 0; j < rule.rhsLength; j++)
                {
                    if (rule.rhs[j] == symbol)
                        count++;
                    if (j == rhs)
                        index = count;
                }

                fprintf(file, "%i", index);
                fprintf(file, "));\n");
            }
        }
        
        fprintf(file, "\n");
        fprintf(file, "    return error;\n");
        fprintf(file, "}\n");

        fprintf(file, "\n");
    }
}

void SaveCompiler(FILE*         file,
                  LR_TABLE      parser,
                  GRAMMAR_TABLE grammar)
{
    int r;

    fprintf(file, "/* reduce one node *\/\n");
    fprintf(file, "int ProcessNode(SYNTAX_TREE* node)\n");
    fprintf(file, "{\n");
    fprintf(file, "    if (node == NULL || node->production == 0)\n");
    fprintf(file, "        return 1;\n\n");
    fprintf(file, "    switch (node->production)\n");
    fprintf(file, "    {\n");
    
    for (r = 1; r < grammar.numRules; r++)
    {
        fprintf(file, "        ");
        fprintf(file, "case 0x%.2X: return Reduce%s(node);\n", r,
            RuleName(r, grammar));
    }

    fprintf(file, "    default:\n");
    fprintf(file, "        printf(\"Unknown production %%i.\\n\",");
    fprintf(file, " node->production);\n");
    fprintf(file, "        return 1;\n");
    fprintf(file, "    }\n");
    fprintf(file, "}\n");
}

*/

int blank(RULE rule) {
    int rhs;
    for (rhs = 0; rhs < rule.rhsLength; rhs++) {
        int symbol = rule.rhs[rhs];
        if (symbol != gSymbolEpsilon && gSymbolEpsilon != gSymbolEOF && 
            symbol != gSymbolEndLine)
        {
            return 0;
        }
    }
    return 1;
}

void fprintrule(FILE* file, RULE rule, GRAMMAR_TABLE grammar) {
    int rhs;
    fprintf(file, "%s -> ", GetElement(rule.lhs, grammar));
    for (rhs = 0; rhs < rule.rhsLength; rhs++)
    {
        fprintf(file, "%s ", GetElement(rule.rhs[rhs], grammar));
    }
}

/* *** */
/* *** */
void SaveJSCode(FILE* file, GRAMMAR_TABLE grammar, LR_TABLE parser) 
{
    RULE rule;
    int r, rhs;
    const char* name;
    int j, count, index;

    fprintf(file,
        "/* parser generator ast walk */\n"
        "var _DISPATCH;\n");
    fprintf(file,
        "function Dispatch(subtree) {\n"
        "\tvar rule = subtree.rule;\n"
        "\tif (_DISPATCH[rule]) {\n"
        "\t\treturn _DISPATCH[rule](subtree);\n"
        "\t}\n"
        "}\n"
        "\n");

    for (r = 1; r < grammar.numRules; r++)
    {
        rule = grammar.rules[r];

        if (!blank(rule)) {
            // print CFG comment hint
            fprintf(file, "// ");
            fprintrule(file, rule, grammar);
            fprintf(file, "\n");
            fprintf(file, "function %s(subtree) {\n\treturn;\n}",
                RuleName(r, grammar));

            fprintf(file, "\n\n");
        }
    }

    fprintf(file, "_DISPATCH = [null, ");
    for (r = 1; r < grammar.numRules; r++)
    {
        rule = grammar.rules[r];
        fprintf(file, "%s", (blank(rule) ? "null" : RuleName(r, grammar)));
        if (r < grammar.numRules - 1) {
            fprintf(file, ", ");
        }
    }    
    fprintf(file, "];\n\n");



}
/* *** */

/* save the binary data of a grammar file to a header */
void SaveGrammar(FILE* file, GRAMMAR_TABLE grammar, unsigned int bExtern)
{
    int i, j, length;
    
    // count symbols
    j = grammar.numSymbols;
    length = 0;
    for (i = 0; i < SYMBOL_BUFFER_SIZE; i++)
    {
        length++;
        if (grammar.symbols[i] == 0) {
            j--;
            if (j == 0) break;
        }
    }
    
    // symbols
    fprintf(file, "/* Grammar Symbols */\n");
    if (bExtern == 0) { fprintf(file, "extern "); }
    fprintf(file, "char GRAMMAR_SYMBOLS[%i]", length+1);
    if (bExtern)
    {
        fprintf(file, " =\n    \"");
    
        j = grammar.numSymbols;
        for (i = 0; i < SYMBOL_BUFFER_SIZE; i++)
        {
            if ((i+1) % 45 == 0) { fprintf(file, "\"\n    \""); }
            if (grammar.symbols[i])
                fprintf(file, "%c", grammar.symbols[i]);
            else
            {
                fprintf(file, "\\0");
                //fprintf(file, "\"");
                j--;
                if (j) {
                    //fprintf(file, "\n    \"");
                }
                else
                {
                    break;
                }
            }
        }
        fprintf(file, "\"");
    }
    fprintf(file, ";\n");
    fprintf(file, "\n");
    
    // count tokens
    j = grammar.numTokens;
    length = 0;
    for (i = 0; i < SYMBOL_BUFFER_SIZE; i++)
    {
        length++;
        if (grammar.tokens[i] == 0) {
            j--;
            if (j == 0) break;
        }
    }
    
    // tokens
    fprintf(file, "/* Grammar Tokens */\n");
    if (bExtern == 0) { fprintf(file, "extern "); }
    fprintf(file, "char GRAMMAR_TOKENS[%i]", length+1);
    if (bExtern)
    {
        fprintf(file, " =\n    \"");
        j = grammar.numTokens;
        for (i = 0; i < TOKEN_BUFFER_SIZE; i++)
        {
            if ((i+1) % 45 == 0) { fprintf(file, "\"\n    \""); }
            if (grammar.tokens[i])
                fprintf(file, "%c", grammar.tokens[i]);
            else
            {
                fprintf(file, "\\0");
                //fprintf(file, "\"");
                j--;
                if (j) {
                    //fprintf(file, "\n    \"");
                }
                else
                {
                    break;
                }
            }
        }
        fprintf(file, "\"");
    }
    fprintf(file, ";\n");
    fprintf(file, "\n\n");
    
    // rules
    if (bExtern)
    {
        fprintf(file, "/* Rule Right Hand Sides */\n");
        for (i = 0; i < grammar.numRules; i++)
        {
            fprintf(file, "int RULE_%i_RHS[] = ", i);
            fprintf(file, "{");
            fprintf(file, "");
            for (j = 0; j < RULE_RHS_SIZE; j++)
            {
                fprintf(file, "%i, ", grammar.rules[i].rhs[j]);
                if (grammar.rules[i].rhs[j] == 0) break;
            }
            fprintf(file, "};\n");
        }
        fprintf(file, "\n");
    
        fprintf(file, "/* CFG Productions */\n");
        fprintf(file, "RULE GRAMMAR_RULES[%i] =\n",
            grammar.numRules);
        fprintf(file, "{\n");
        for (i = 0; i < grammar.numRules; i++)
        {
            fprintf(file, "    %i, %i, RULE_%i_RHS,\n",
                grammar.rules[i].lhs,
                grammar.rules[i].rhsLength,
                i);
        }
        fprintf(file, "};\n");
        fprintf(file, "\n");
    }

    // CFG struct
    if (bExtern == 0)
    {
        fprintf(file, "/* Context Free Grammar */\n");    
        fprintf(file, "extern GRAMMAR_TABLE CONTEXT_FREE_GRAMMAR;\n");
    }
    else
    {
        fprintf(file, "/* Context Free Grammar */\n");
        fprintf(file, "GRAMMAR_TABLE CONTEXT_FREE_GRAMMAR =\n");
        fprintf(file, "{\n");
        fprintf(file, "    %i, GRAMMAR_SYMBOLS,\n", grammar.numSymbols);
        fprintf(file, "    %i, GRAMMAR_TOKENS,\n", grammar.numTokens);
        fprintf(file, "    %i, GRAMMAR_RULES,\n", grammar.numRules);
        fprintf(file, "};\n");
    }
    fprintf(file, "\n\n");
}

/* save the binary data of an slr parse table to a header file */
void SaveParser(FILE* file, LR_TABLE parser, unsigned int bExtern)
{
    int i;
    
    // goto table
#ifdef _SLR
    fprintf(file, "/* SLR GOTO table */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) GOTO table */\n");
#endif
    if (bExtern == 0) { fprintf(file, "extern "); }
    fprintf(file, "int GOTO_TABLE[%i]", parser.numStates * parser.numSymbols);
    if (bExtern)
    {
        fprintf(file, " =\n{");
        for (i = 0; i < parser.numStates * parser.numSymbols; i++)
        {
            if ((i%16) == 0)
            {
                fprintf(file, "\n    ");
            }
            fprintf(file, "%i, ",
                parser.gotoTable[i]);
        }
        fprintf(file, "\n}");
    }
    fprintf(file, ";\n\n\n");

    // action table
#ifdef _SLR
    fprintf(file, "/* SLR ACTION table */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) ACTION table */\n");
#endif
    if (bExtern == 0) { fprintf(file, "extern "); };
    fprintf(file, "ACTION ACTION_TABLE[%i]", parser.numStates * parser.numTokens);
    if (bExtern)
    {
        fprintf(file, " =\n{");
        for (i = 0; i < parser.numStates * parser.numTokens; i++)
        {
            if ((i%8) == 0)
            {
                fprintf(file, "\n    ");
            }
            fprintf(file, "%i, %i, ",
                parser.actionTable[i].type,
                parser.actionTable[i].value);
        }
        fprintf(file, "\n}");
    }
    fprintf(file, ";\n\n\n");

    // LR_TABLE object
#ifdef _SLR
    fprintf(file, "/* SLR parse table struct */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) parse table struct */\n");
#endif
    if (bExtern == 0)
    {
        fprintf(file, "extern LR_TABLE PARSE_TABLE;");
    }
    else
    {
        fprintf(file, "LR_TABLE PARSE_TABLE =\n");
        fprintf(file, "{\n");
        fprintf(file, "    %i, %i, %i,\n",
            parser.numTokens,
            parser.numSymbols,
            parser.numStates);
        fprintf(file, "    ACTION_TABLE,\n");
        fprintf(file, "    GOTO_TABLE\n");
        fprintf(file, "};");
    }
    fprintf(file, "\n\n");
}

int CompressedSize(int* source_data, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int write_index = 0;
    int lengthRep = 0;
    int copy_value = 0;

    while (index < total_size)
    {
        if (mode == 0)
        {
            unsigned int counter_loc = write_index;
            write_index++;
            // find the number of non-repeated characters
            lengthRep = 1;
            while (index < total_size)
            {
                write_index++; index++;
                if (index == total_size || source_data[index] == source_data[index - 1])
                {
                    break;
                }
                lengthRep++;
            }
            mode = 1;
        } 
        else if (mode == 1)
        {
            unsigned int repeat_value;
            repeat_value = source_data[index];
            lengthRep = 1;
            index++;
            while (index < total_size && source_data[index] == repeat_value)
            {
                lengthRep++;
                index++;
            }
            write_index += 2;
            mode = 0;
        }
    }
    return write_index;
}

void CompressGotoTable(int* source_data, int* dest_data, unsigned int* compressed_size, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int write_index = 0;
    int lengthRep = 0;
    int copy_value = 0;

    while (index < total_size)
    {
        if (mode == 0)
        {
            unsigned int counter_loc = write_index;
            write_index++;
            // find the number of non-repeated characters
            lengthRep = 1;
            while (index < total_size)
            {
                dest_data[write_index] = source_data[index];
                write_index++; index++;
                if (index == total_size || source_data[index] == source_data[index - 1])
                {
                    break;
                }
                lengthRep++;
            }
            dest_data[counter_loc] = lengthRep;
            mode = 1;
        } 
        else if (mode == 1)
        {
            unsigned int repeat_value;
            repeat_value = source_data[index];
            lengthRep = 1;
            index++;
            while (index < total_size && source_data[index] == repeat_value)
            {
                lengthRep++;
                index++;
            }
            dest_data[write_index] = lengthRep;
            write_index++;
            dest_data[write_index] = repeat_value;
            write_index++;
            mode = 0;
        }
    }

    //*compressed_size = write_index;
}


void DecompressGotoTable(int* source_data, int* dest_data, unsigned int compressed_size, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int read_index = 0;
    int lengthRep = 0;
    int copy_value = 0;

    while (read_index < compressed_size && index < total_size)
    {
        if (mode == 0)
        {
            lengthRep = source_data[read_index];
            read_index++;
            while (lengthRep && read_index < compressed_size
                    && index < total_size)
            {
                dest_data[index] = source_data[read_index];
                index++; read_index++;
                lengthRep--;
            }
            lengthRep = 0;
            mode = 1;
        } 
        else if (mode == 1) 
        {
            lengthRep = source_data[read_index];
            read_index++;
            copy_value = source_data[read_index];
            read_index++;
            while (lengthRep && index < total_size)
            {
                dest_data[index] = copy_value;
                index++;
                lengthRep--;
            }
            lengthRep = 0;
            mode = 0;
        }
    }
}

int CompressedActionTableSize(ACTION* source_data, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int write_index = 0;
    int lengthRep = 0;
    ACTION copy_value;
    copy_value.type = 0;
    copy_value.value = 0;

    while (index < total_size)
    {
        if (mode == 0)
        {
            unsigned int counter_loc = write_index;
            write_index++;
            // find the number of non-repeated characters
            lengthRep = 1;
            while (index < total_size)
            {
                write_index += 2;
                index++;
                if (index == total_size || 
                    (source_data[index].type == source_data[index - 1].type
                     && source_data[index].value == source_data[index - 1].value))
                {
                    break;
                }
                lengthRep++;
            }
            mode = 1;
        } 
        else if (mode == 1)
        {
            ACTION repeat_value;
            repeat_value.type = source_data[index].type;
            repeat_value.value = source_data[index].value;
            lengthRep = 1;
            index++;
            while (index < total_size && 
                source_data[index].type == repeat_value.type
                && source_data[index].value == repeat_value.value)
            {
                lengthRep++;
                index++;
            }
            write_index += 3;
            mode = 0;
        }
    }

    return write_index;
}


void CompressActionTable(ACTION* source_data, int* dest_data, unsigned int* compressed_size, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int write_index = 0;
    int lengthRep = 0;
    ACTION copy_value;
    copy_value.type = 0;
    copy_value.value = 0;

    while (index < total_size)
    {
        if (mode == 0)
        {
            unsigned int counter_loc = write_index;
            write_index++;
            // find the number of non-repeated characters
            lengthRep = 1;
            while (index < total_size)
            {
                dest_data[write_index] = source_data[index].type;
                write_index++;
                dest_data[write_index] = source_data[index].value;
                write_index++; index++;
                if (index == total_size || 
                    (source_data[index].type == source_data[index - 1].type
                     && source_data[index].value == source_data[index - 1].value))
                {
                    break;
                }
                lengthRep++;
            }
            dest_data[counter_loc] = lengthRep;
            mode = 1;
        } 
        else if (mode == 1)
        {
            ACTION repeat_value;
            repeat_value.type = source_data[index].type;
            repeat_value.value = source_data[index].value;
            lengthRep = 1;
            index++;
            while (index < total_size && 
                source_data[index].type == repeat_value.type
                && source_data[index].value == repeat_value.value)
            {
                lengthRep++;
                index++;
            }
            dest_data[write_index] = lengthRep;
            write_index++;
            dest_data[write_index] = repeat_value.type;
            write_index++;
            dest_data[write_index] = repeat_value.value;
            write_index++;
            mode = 0;
        }
    }

    //*compressed_size = write_index;
}


void DecompressActionTable(int* source_data, ACTION* dest_data, unsigned int compressed_size, unsigned int total_size)
{
    unsigned int mode = 0;
    unsigned int index = 0;
    unsigned int read_index = 0;
    int lengthRep = 0;
    ACTION copy_value;
    copy_value.type = 0;
    copy_value.value = 0;

    while (read_index < compressed_size && index < total_size)
    {
        if (mode == 0)
        {
            lengthRep = source_data[read_index];
            read_index++;
            while (lengthRep && read_index < compressed_size
                    && index < total_size)
            {
                dest_data[index].type = source_data[read_index];
                read_index++;
                dest_data[index].value = source_data[read_index];
                read_index++;
                index++;
                lengthRep--;
            }
            lengthRep = 0;
            mode = 1;
        } 
        else if (mode == 1) 
        {
            lengthRep = source_data[read_index];
            read_index++;
            copy_value.type = source_data[read_index];
            read_index++;
            copy_value.value = source_data[read_index];
            read_index++;
            while (lengthRep && index < total_size)
            {
                dest_data[index].type = copy_value.type;
                dest_data[index].value = copy_value.value;
                index++;
                lengthRep--;
            }
            lengthRep = 0;
            mode = 0;
        }
    }
}

/* save the binary data of an lr1/slr parse table to a header file (compressed) */
void SaveParserCompressed(FILE* file, LR_TABLE parser, unsigned int bExtern)
{
    unsigned int gotoSize;
    unsigned int actionSize;
    unsigned int i;
    
    // goto table
#ifdef _SLR
    fprintf(file, "/* SLR GOTO table */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) GOTO table */\n");
#endif

    /* calculate size */

   gotoSize = CompressedSize(parser.gotoTable, parser.numStates * parser.numSymbols);

    /* output */
    if (bExtern == 0) { fprintf(file, "extern "); }
    fprintf(file, "int COMPRESSED_GOTO_TABLE[%i]", gotoSize);
    if (bExtern)
    {
        int* compressedTable = (int*)malloc(sizeof(int) * gotoSize);
        CompressGotoTable(parser.gotoTable, compressedTable, &gotoSize, parser.numStates * parser.numSymbols);

        fprintf(file, " =\n{");
        for (i = 0; i < gotoSize; i++)
        {
            if ((i%24) == 0) { fprintf(file, "\n    "); }
            fprintf(file, "%i, ", compressedTable[i]);
        }

        fprintf(file, "\n}");
        
        free(compressedTable);
    }
    fprintf(file, ";\n\n\n");

    // action table
#ifdef _SLR
    fprintf(file, "/* SLR ACTION table */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) ACTION table */\n");
#endif

    actionSize = CompressedActionTableSize(parser.actionTable, parser.numStates * parser.numTokens);

    if (bExtern == 0) { fprintf(file, "extern "); };
    fprintf(file, "int COMPRESSED_ACTION_TABLE[%i]", actionSize);
    if (bExtern)
    {
        int* compressedTable = (int*)malloc(sizeof(int) * actionSize);
        CompressActionTable(parser.actionTable, compressedTable, &actionSize, parser.numStates * parser.numTokens);


        fprintf(file, " =\n{");
        for (i = 0; i < actionSize; i++)
        {
            if ((i%24) == 0) { fprintf(file, "\n    "); }
            fprintf(file, "%i, ", compressedTable[i]);
        }

        fprintf(file, "\n}");

        free(compressedTable);
    }
    fprintf(file, ";\n\n\n");

    // LR_TABLE object
#ifdef _SLR
    fprintf(file, "/* SLR parse table struct */\n");
#endif
#ifdef _LR1
    fprintf(file, "/* LR(1) parse table struct */\n");
#endif
    if (bExtern == 0)
    {
        fprintf(file, "extern LR_TABLE PARSE_TABLE;");
    }
    else
    {
        fprintf(file, "LR_TABLE PARSE_TABLE =\n");
        fprintf(file, "{\n");
        fprintf(file, "    %i, %i, %i,\n",
            parser.numTokens,
            parser.numSymbols,
            parser.numStates);
        fprintf(file, "    0l,\n");
        fprintf(file, "    0l\n");
        fprintf(file, "};");
    }
    fprintf(file, "\n\n");
}

void SaveProductions(FILE*         file,
                     LR_TABLE      parser,
                     GRAMMAR_TABLE grammar)
{
    RULE rule;
    int r, rhs;
    const char* name;
    int j, count, index;

    fprintf(file, "/* production stubs */\n\n");
    for (r = 1; r < grammar.numRules; r++)
    {
        rule = grammar.rules[r];

        fprintf(file, "/* ");
        fprintf(file, "%i. ", r);
        fprintf(file, "%s -> ", GetElement(rule.lhs, grammar));
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            fprintf(file, "%s ", GetElement(rule.rhs[rhs], grammar));
        }
        fprintf(file, "*/\n");
        
        fprintf(file, "int Reduce%s(SYNTAX_TREE* node)\n",
            RuleName(r, grammar));
        fprintf(file, "{\n");
        //fprintf(file, "    if (node->numChildren != %i) return %i;\n",
        //    rule.rhsLength, r);
        fprintf(file, "    Assert(node->numChildren == %i);\n", rule.rhsLength);
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            int symbol = rule.rhs[rhs];
            if (symbol & K_SYMBOL ||
                symbol == gSymbolInteger ||
                symbol == gSymbolFloat ||
                symbol == gSymbolString ||
                symbol == gSymbolIdentifier)
            {
                fprintf(file, "    SYNTAX_TREE* ");
                
                name = GetElement(symbol, grammar);
                for (j = 0; name[j]; j++)
                {
                    if (name[j] != '<' && name[j] != '>')
                    {
                        if (isAlpha(name[j]) || isNumeric(name[j]))
                            fprintf(file, "%c", name[j]);
                        else
                            fprintf(file, "_");
                    }
                }
                
                count = 0;
                for (j = 0; j < rule.rhsLength; j++)
                {
                    if (rule.rhs[j] == symbol)
                        count++;
                    if (j == rhs)
                        index = count;
                }
                
                fprintf(file, "%i", index);
                
                fprintf(file, " = ");
                fprintf(file, "node->children[%i];\n", rhs);
            }
        }
        
        fprintf(file, "\n");
        fprintf(file, "    int error = 0;\n");
        for (rhs = 0; rhs < rule.rhsLength; rhs++)
        {
            int symbol = rule.rhs[rhs];
            if (symbol & K_SYMBOL ||
                symbol == gSymbolInteger ||
                symbol == gSymbolFloat ||
                symbol == gSymbolString ||
                symbol == gSymbolIdentifier)
            {
                fprintf(file, "    error = (error ? error : ProcessNode(");

                name = GetElement(symbol, grammar);
                for (j = 0; name[j]; j++)
                {
                    if (name[j] != '<' && name[j] != '>')
                    {
                        if (isAlpha(name[j]) || isNumeric(name[j]))
                            fprintf(file, "%c", name[j]);
                        else
                            fprintf(file, "_");
                    }
                }

                count = 0;
                for (j = 0; j < rule.rhsLength; j++)
                {
                    if (rule.rhs[j] == symbol)
                        count++;
                    if (j == rhs)
                        index = count;
                }

                fprintf(file, "%i", index);
                fprintf(file, "));\n");
            }
        }
        
        fprintf(file, "\n");
        fprintf(file, "    return error;\n");
        fprintf(file, "}\n");

        fprintf(file, "\n");
    }
}

void SaveCompiler(FILE*         file,
                  LR_TABLE      parser,
                  GRAMMAR_TABLE grammar)
{
    int r;

    fprintf(file, "/* reduce one node */\n");
    fprintf(file, "int ProcessNode(SYNTAX_TREE* node)\n");
    fprintf(file, "{\n");
    fprintf(file, "    if (node == NULL || node->production == 0)\n");
    fprintf(file, "        return 1;\n\n");
    fprintf(file, "    switch (node->production)\n");
    fprintf(file, "    {\n");
    
    for (r = 1; r < grammar.numRules; r++)
    {
        fprintf(file, "        ");
        fprintf(file, "case 0x%.2X: return Reduce%s(node);\n", r,
            RuleName(r, grammar));
    }

    fprintf(file, "    default:\n");
    fprintf(file, "        printf(\"Unknown production %%i.\\n\",");
    fprintf(file, " node->production);\n");
    fprintf(file, "        return 1;\n");
    fprintf(file, "    }\n");
    fprintf(file, "}\n");
}

/* save the LR_TABLE to a .C file and generate constants too */
int SaveLRParser(const char*   output,
                 LR_TABLE      parser,
                 GRAMMAR_TABLE grammar)
{
    FILE* file;
    char* header;
    char* header_name;
    char* tables;
    char* compressed_tables;
    char* source;
    char* tablesjs, *codejs;
    int length;
    
    if (output == NULL || output[0] == '\0')
    {
        printf("No output file given.\n");
        return 1;
    }
    
    length = strlen(output);
    header = (char*)malloc(length + 3);
    tables = (char*)malloc(length + 5);
    source = (char*)malloc(length + 3);
    tablesjs = (char*)malloc(length + 6);
    codejs = (char*)malloc(length + 4);
    compressed_tables = (char*)malloc(length + 16);
    
    sprintf(header, "%s.h", output);
    sprintf(tables, "%s_t.c", output);
    sprintf(source, "%s.c", output);
    sprintf(tablesjs, "%s_t.js", output);
    sprintf(codejs, "%s.js", output);
    sprintf(compressed_tables, "%s_compressed.h", output);

    // header name without directories
    header_name = header;
    while (*header_name) header_name++;
    while (header_name != header && *header_name != '/') header_name--;
    if (*header_name == '/') header_name++;

    // save header file
    file = fopen(header, "w");
    if (file == 0) {
        printf("Could not open header file for output.\n");
        return 1;
    }
    
    fprintf(file, "/* auto-generated lr parse tables */\n");
    fprintf(file, "#ifndef _GENERATED_PARSER_H\n"); // output);
    fprintf(file, "#define _GENERATED_PARSER_H\n"); //, output);
    fprintf(file, "\n");
    fprintf(file, "#include \"lr_parser.h\"\n");
    fprintf(file, "\n\n");
    fprintf(file, "/* main function */\n");
    fprintf(file, "int ProcessNode(SYNTAX_TREE* node);\n\n");
    
    SaveDefines(file, grammar);
    SaveGrammar(file, grammar, 0);
    SaveParser(file, parser, 0);
    
    fprintf(file, "#endif // _GENERATED_PARSER_H\n"); //, output);
    fclose(file);
    
    // save tables to a c file
#if 1
    file = fopen(tables, "w");
    if (file == 0) {
        printf("Could not open table file for output.\n");
        return 1;
    }

    fprintf(file, "/* Grammar and Parser Tables */\n");
    fprintf(file, "#include \"lr_parser.h\"\n\n");
    SaveGrammar(file, grammar, 1);
    SaveParser(file, parser, 1);
    
    fprintf(file, "");
    fclose(file);
#endif

#if 1
    file = fopen(tablesjs, "w");
    if (file == 0) {
        printf("Could not open js table file for output.\n");
        return 1;
    }

    SaveJSTables(file, grammar, parser);

    fprintf(file, "");
    fclose(file);


    file = fopen(codejs, "w");
    if (file == 0) {
        printf("Could not open js table file for output.\n");
        return 1;
    }

    SaveJSCode(file, grammar, parser);

    fprintf(file, "");
    fclose(file);

#endif

    // save source file
    file = fopen(source, "w");
    if (file == 0) {
        printf("Could not open source file for output.\n");
        return 1;
    }

    fprintf(file, "/* auto-generated compiler stubs */");
    fprintf(file, "\n");
    fprintf(file, "#include \"lr_parser.h\"\n");
    fprintf(file, "#include \"%s\"\n", header_name);
    fprintf(file, "\n\n");

    SaveProductions(file, parser, grammar);
    SaveCompiler(file, parser, grammar);
    fclose(file);

#if 1
    file = fopen(compressed_tables, "w");
    if (file == 0) {
        printf("Could not open source file for compressed output.\n");
        return 1;
    }

    fprintf(file, "/* auto-generated compressed parse tables */\n");
    fprintf(file, "#include \"lr_parser.h\"\n");
    fprintf(file, "#include \"%s\"\n", header_name);
    fprintf(file, "\n\n");

    SaveParserCompressed(file, parser, 1);

#endif
    
    free(tablesjs);
    free(codejs);
    free(header);
    free(tables);
    free(source);
    free(compressed_tables);
    return 0;
}
