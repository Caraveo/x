#ifndef LEXEM_C
#define LEXEM_C

#include "lex.h"

typedef struct { 
    Token_Type type;
    const char* value;
} Lex;

Lex Create_Lex(Token_Type type, const char* value) {
    Lex lex;
    lex.type = type;
    lex.value = value;
    return lex;
}

Lex Process_Lexem(char lex)
{
    Lex LEFT_PARANTHESIS = Create_Lex(OPERATOR, "(");
    Lex RIGHT_PARANTHESIS = Create_Lex(OPERATOR, ")");
    Lex LEFT_SQUAREBRACKET = Create_Lex(OPERATOR, "[");
    Lex RIGHT_SQUAREBRACKET = Create_Lex(OPERATOR, "]");
    Lex COLON = Create_Lex(OPERATOR, ":");
    Lex COMMA = Create_Lex(OPERATOR, ","); 
    Lex SEMI = Create_Lex(OPERATOR, ";");
    Lex PLUS = Create_Lex(OPERATOR, "+");
    Lex MINUS = Create_Lex(OPERATOR, "-");
    Lex STAR = Create_Lex(OPERATOR, "");
    Lex SLASH = Create_Lex(OPERATOR, "/");
    Lex VERTICAL_BAR =  Create_Lex(OPERATOR, "|");
    Lex AMPER_SIGN = Create_Lex(OPERATOR, "&");
    Lex LESS_THAN = Create_Lex(OPERATOR, "<");
    Lex GREATER_THAN = Create_Lex(OPERATOR, ">");
    Lex EQUAL = Create_Lex(OPERATOR, "=");
    Lex DOT = Create_Lex(OPERATOR, ".");
    Lex PERCENT = Create_Lex(OPERATOR, "%");
    Lex LEFT_BRACE = Create_Lex(OPERATOR, "{");
    Lex RIGHT_BRACE = Create_Lex(OPERATOR, "}");
    Lex EQUAL_EQUAL = Create_Lex(OPERATOR, "==");
    Lex NOT_EQUAL = Create_Lex(OPERATOR, "!=");
    Lex LESS_THAN_EQUAL_TO = Create_Lex(OPERATOR, "<=");
    Lex GREATER_THAN_EQUAL_TO = Create_Lex(OPERATOR, ">=");
    Lex TILDE = Create_Lex(OPERATOR, "~");
    Lex CIRCUMFLEX = Create_Lex(OPERATOR, "^");
    Lex LEFT_SHIFT = Create_Lex(OPERATOR, "<<");
    Lex RIGHT_SHIFT = Create_Lex(OPERATOR, ">>");
    Lex DOUBLE_STAR = Create_Lex(OPERATOR, "");
    Lex PLUS_EQUAL = Create_Lex(OPERATOR, "+=");
    Lex MINUS_EQUAL = Create_Lex(OPERATOR, "-=");
    Lex STAR_EQUAL = Create_Lex(OPERATOR, "=");
    Lex DIVIDE_EQUAL = Create_Lex(OPERATOR, "/=");
    Lex PERCENT_EQUAL = Create_Lex(OPERATOR, "%=");
    Lex AMPER_SIGN_EQUAL = Create_Lex(OPERATOR, "&=");
    Lex VERTICAL_BAR_EQUAL = Create_Lex(OPERATOR, "|=");
    Lex CIRCUM_EQUAL = Create_Lex(OPERATOR, "^=");
    Lex LEFT_SHIFT_EQUAL = Create_Lex(OPERATOR, "<<=");
    Lex RIGHT_SHIT_EQUAL = Create_Lex(OPERATOR, ">>=");
    Lex DOUBLE_STAR_EQUAL = Create_Lex(OPERATOR, "**=");
    Lex DOUBLE_SLASH = Create_Lex(OPERATOR, "//");
    Lex DOUBLE_SLASH_EQUAL = Create_Lex(OPERATOR, "//=");
    Lex AT = Create_Lex(OPERATOR, "@");
    Lex AT_EQUAL = Create_Lex(OPERATOR, "@=");
    Lex RIGHT_ARROW = Create_Lex(OPERATOR, "->");
    Lex ELLIPSIS = Create_Lex(OPERATOR, "...");
    Lex COLON_EQUAL = Create_Lex(OPERATOR, ":=");
    Lex EXLAMATION = Create_Lex(OPERATOR, "!");
    Lex COMMENT = Create_Lex(OPERATOR, "#");
    Lex UNKNOWN_LEX = Create_Lex(UNKNOWN, "Unknown Lex");
    
    char lexi[2] = {lex, '\0'};

    Lex WHITESPACE_LEX = Create_Lex(WHITESPACE, lexi);
    Lex LEX_LEX = Create_Lex(LEX, lexi);

    switch (lex) {
        case '{':
            return LEFT_BRACE;
        break;
        case '}':
            return RIGHT_BRACE;
        break;
        case '(':
            return LEFT_PARANTHESIS;
        break;
        case ')':
            return RIGHT_PARANTHESIS;
        break;
        case '[':
            return LEFT_SQUAREBRACKET ;
        break;
        case ']':
            return RIGHT_SQUAREBRACKET;
        break;
        case ':':
            return COLON;
        break;
        case ',':
            return COMMA;
        break;
        case ';':
            return SEMI;
        break;
        case '+':
            return PLUS;
        break;
        case '-':
            return MINUS;
        break;
        case '*':
            return STAR;
        break;
        case '/':
            return SLASH;
        break;
        case '|':
            return VERTICAL_BAR;
        break;
        case '&':
            return AMPER_SIGN;
        break;
        case '<':
            return LESS_THAN;
        break;
        case '>':
            return GREATER_THAN;
        break;
        case '=':
            return EQUAL;
        break;
        case '.':
            return DOT;
        break;
        case '%':
            return PERCENT;
        break;
        case '#':
            return COMMENT;
        break;
        case '!':
            return EXLAMATION;
        case '@':
            return AT;
        break;
        case ' ':
            return WHITESPACE_LEX;
        break;
        default:
            return LEX_LEX;
        break;
    }
}

#endif