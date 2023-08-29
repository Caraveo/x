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

        if(token.type == LEX || token.type == CAP_LEX || token.type == NUMBER_TYPE){
            counter = 0;
            if (encounter == 0 && spacer == 0){
                LEX_NAME[encounter][counter + position++] = lexem;
            }else if (spacer >= 1) {
                LEX_NAME[encounter][counter + position++] = lexem;
            }else if(encounter == 1){
                LEX_NAME[encounter][counter + position++] = lexem;
            }else if(encounter > 1){
                LEX_NAME[encounter][counter + position++] = lexem;
            } else {
                LEX_NAME[encounter][counter + position++] = lexem;
            }
        } else if (token.type == OPERATOR) {
            
        } else if(token.type == WHITESPACE){
            spacer++;
            counter = 0;
            position = 0;
            encounter++;
            
        } else if(token.type == NEWLINE){
            
        } else if(token.type == SPECIAL){
            spacer++;
            encounter++;
            position = 0;
            counter = 0;
        } else {
            printf("[%s]", Token_Type_Name[token.type]);
        }
        counter++;
    }


    int index = 0;
    while (LEX_NAME[index][0] != '\0') {
    if (LEX_NAME[index][0] != '\0') {
        printf("<%s>", LEX_NAME[index]);
        LEX_NAME[index][0] = '\0';
        memset(LEX_NAME[index], 0, sizeof(LEX_NAME[index]));
    }
    index++; // Move to the next element in the array
    }

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