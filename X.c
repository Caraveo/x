 #include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "INCLUDE/lex.h"
#include "INCLUDE/lexem.c"
#include "INCLUDE/lexer.c"

void Lexer(char line[100]){
    Rex rex;
    rex.line = line;
    char LEX_NAME[100][100];
    Lex rLex;
    int lex_index = 0;
    int counter = 1;
    int position = 0;
    int encounter = 0;
    int lex_count = 0;
    int token_count = 0;

    for (int i = 0; i < strlen(line); i++) {
        char lexem = line[i];
        rLex = Process_Lexem(lexem);
        Token token = Process_Lex(rLex);
        Token Final_Token;
        if (token.type == OPERATOR) {
            printf("[%s]", Token_Type_Name[rLex.type]);
        }
        if(token.type == WHITESPACE){
            printf("[%s]", Token_Type_Name[rLex.type]);
        }
        if(token.type == NEWLINE){
            printf("[%s]", Token_Type_Name[rLex.type]);
        }
        if(token.type == NUMBER_TYPE){
            printf("[%s]", Token_Type_Name[rLex.type]);
        }
        if(token.type == SPECIAL){
            printf("[%s]", Token_Type_Name[token.type]);
        }
        if(token.type == LEX || token.type == CAP_LEX){
            counter = 0;
            LEX_NAME[encounter++][counter + position++] = lexem;
            printf("[%s]", Token_Type_Name[token.type]);
        }
        counter++;

    }
    printf("%s\n", LEX_NAME[encounter]);
}

void Process_File(char* file_name){
    int line_count = 0;
    FILE* file = fopen(file_name, "r");
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        Lexer(line);
        line_count++;
    }
    fclose(file);
}

int main() {
    Process_File("SRC/pro.x");
    return 0;
}