#ifndef LEXER_C
#define LEXER_C

#include <stdio.h>

#include "lex.h"

typedef struct { 
    Lex lex;
    Token_Type type;
    const char* token_type_name_string;
} Token;

Token Create_Token(Token_Type type, Token_Type lex_type, Lex lex){
    Token token;
    token.type = lex_type;
    token.token_type_name_string = Token_Type_Name[type];
    token.lex = lex;
    return token;
}

Token Process_Lex(Lex lex){
    switch (lex.type) {
        case LEX:
            return Create_Token(LEX, lex.type, lex);
        break;
        case CAP_LEX:
            return Create_Token(CAP_LEX, lex.type, lex);
        break;
        case OPERATOR:
            return Create_Token(OPERATOR, lex.type, lex);
        break;
        case UNKNOWN:
            return Create_Token(UNKNOWN, lex.type, lex);
        break;
        case NEWLINE:
            return Create_Token(NEWLINE, lex.type, lex);
        break;
        case TAB:
            return Create_Token(TAB, lex.type, lex);
        break;
        case WHITESPACE:
            return Create_Token(WHITESPACE, lex.type, lex);
        break;
        case COMM:
            return Create_Token(TYPE_COMMENT, lex.type, lex);
        break;
        case EXLAM:
            return Create_Token(EXLAM, lex.type, lex);
        break;
        case AMPER:
            return Create_Token(AMPER, lex.type, lex);
        break;
        case NUMBER_TYPE:
            return Create_Token(NUMBER_TYPE, lex.type, lex);
        break;
        case SPECIAL:
            return Create_Token(SPECIAL, lex.type, lex);
        break;
        case NAME:
            return Create_Token(AMPER, lex.type, lex);
        break;
    }
}

#endif