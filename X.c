 #include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "INCLUDE/lex.h"
#include "INCLUDE/lexem.c"
#include "INCLUDE/lexer.c"

Rex Lexer(char line[100]){
    Rex rex;
    rex.line = line;
    const char* LEX_NAME[100];
    Tex tex;
    Lex rLex;
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
        if(token.type == LEX || token.type == CAP_LEX){
            int lex_length = 0;
            while (token.type == LEX || token.type == CAP_LEX) {
                lexem = line[i++];
                rLex = Process_Lexem(lexem);
                token = Process_Lex(rLex);
                LEX_NAME[i] = rLex.value;
                printf("[%s]", Token_Type_Name[token.type]);
                lex_length += strlen(LEX_NAME[i]);
                
            }
            char token_lex[lex_length];
            token_lex[0] = '\0';
            for (int j = 0; LEX_NAME[j] != NULL; j++) {
                strcat(token_lex, LEX_NAME[j]);
            }

            printf("%s", token_lex);
        }
        
        if(token.type == SPECIAL){
            printf("[%s]", Token_Type_Name[rLex.type]);
        }
       tex = Create_Tex(LEX_NAME, rex);
    }

    printf("\n %s \n", tex.rex.line);
    return rex;
}


void Process_File(char* file_name){
    int line_count = 0;
    FILE* file = fopen(file_name, "r");
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        Rex rRex = Lexer(line);
        rRex.index = line_count;
        line_count++;
    }
    
    fclose(file);
}

int main() {
    Process_File("SRC/pro.x");
    return 0;
}