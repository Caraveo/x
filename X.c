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
        if(token.type == LEX){
            while (token.type == LEX) {
                LEX_NAME[i] = rLex.value;
                lexem = line[i++];
                rLex = Process_Lexem(lexem);
                token = Process_Lex(rLex);
                printf("[%s]", Token_Type_Name[rLex.type]);
            }
            Final_Token = Create_Token(LEX, token.type, rLex);
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