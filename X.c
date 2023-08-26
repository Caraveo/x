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
    char* LEX_NAME[30];
    Tex tex;
    for (int i = 0; i < strlen(line); i++) {
        char lexem = line[i];
        Lex rLex = Process_Lexem(lexem);
        Token token = Process_Lex(rLex);
        
        Token Final_Token;

        if(token.type == LEX){
            int line_count = 0;
            while (token.type == LEX) {
                lexem = line[i++];
                rLex = Process_Lexem(lexem);
                token = Process_Lex(rLex);
                line_count++;
            }
            line_count = 0;
            Final_Token = Create_Token(LEX, token.type, rLex);
        }
        tex = Create_Tex(*LEX_NAME, rex);
    }
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
        printf("%s", line);code 
    }
    
    fclose(file);
}

int main() {
    Process_File("SRC/pro.x");
    return 0;
}