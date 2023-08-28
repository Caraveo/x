 #include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "INCLUDE/lex.h"
#include "INCLUDE/lexem.c"
#include "INCLUDE/lexer.c"

void Lexer(char line[100]){
    char LEX_NAME[100][100];
    Lex rLex;
    int lex_index = 0;
    int counter = 0;
    int position = 0;
    int token_count = 0;
    int counti = 0;
    int encounter = 0;
    int spacer = 0;

    int lexem_count = 0;
        
    for (int i = 0; i < strlen(line); i++) {
        char lexem = line[i];
        rLex = Process_Lexem(lexem);
        Token token = Process_Lex(rLex);
        Token Final_Token;

        lexem_count++;

        if(token.type == LEX || token.type == CAP_LEX){
            counter = 0;
            if (encounter == 0){
                LEX_NAME[encounter][counter + position++] = lexem;
                printf("[%s]", Token_Type_Name[token.type]);
                token_count++;
            } else if(encounter == 1){
                LEX_NAME[1][counter + position++] = lexem;
            } else if(encounter > 1){
                LEX_NAME[encounter][counter + position++] = lexem;
            }
        } else if (token.type == OPERATOR) {
            printf("[%s]", Token_Type_Name[rLex.type]);
        } else if(token.type == WHITESPACE){
            spacer++;
            printf("[%s]", Token_Type_Name[rLex.type]);
        } else if(token.type == NEWLINE){
            printf("[%s]", Token_Type_Name[rLex.type]);
        } else if(token.type == NUMBER_TYPE){
            printf("[%s]", Token_Type_Name[rLex.type]);
        } else if(token.type == SPECIAL){
            printf("[%s]", Token_Type_Name[token.type]);
            encounter++;
            position = 0;
        } else {
            printf("[%s]", Token_Type_Name[token.type]);}
        counter++;
    }

    printf("<%s>", LEX_NAME[0]);
    printf("<%s>", LEX_NAME[1]);
    

    LEX_NAME[0][0] = '\0';
    memset(LEX_NAME[0],0,sizeof(LEX_NAME[0]));

    LEX_NAME[1][0] = '\0';
    memset(LEX_NAME[1],0,sizeof(LEX_NAME[1]));
    

    printf("\n");
    printf("Lex Iteration Count: %d\n", lexem_count);
    printf("Encounter: %d\n", encounter);
    printf("LEX Count: %d\n", token_count);
    printf("TOKEN Count: %d\n", counter);
    printf("\n");
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