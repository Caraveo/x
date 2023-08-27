#ifndef LEXEM_C
#define LEXEM_C

#include "lex.h"
#include <string.h>

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
    Lex LEFT_PARANTHESIS = Create_Lex(SPECIAL, "(");
    Lex RIGHT_PARANTHESIS = Create_Lex(SPECIAL, ")");
    Lex LEFT_SQUAREBRACKET = Create_Lex(SPECIAL, "[");
    Lex RIGHT_SQUAREBRACKET = Create_Lex(SPECIAL, "]");
    Lex LEFT_BRACE = Create_Lex(SPECIAL, "{");
    Lex RIGHT_BRACE = Create_Lex(SPECIAL, "}");

    Lex COLON = Create_Lex(OPERATOR, ":");
    Lex COMMA = Create_Lex(OPERATOR, ","); 
    Lex SEMI = Create_Lex(OPERATOR, ";");
    Lex PLUS = Create_Lex(OPERATOR, "+");
    Lex MINUS = Create_Lex(OPERATOR, "-");
    Lex STAR = Create_Lex(OPERATOR, "*");
    Lex SLASH = Create_Lex(OPERATOR, "/");
    Lex VERTICAL_BAR =  Create_Lex(OPERATOR, "|");
    Lex AMPER_SIGN = Create_Lex(OPERATOR, "&");
    Lex LESS_THAN = Create_Lex(OPERATOR, "<");
    Lex GREATER_THAN = Create_Lex(OPERATOR, ">");
    Lex EQUAL = Create_Lex(OPERATOR, "=");
    Lex DOT = Create_Lex(OPERATOR, ".");
    Lex PERCENT = Create_Lex(OPERATOR, "%");
    Lex TILDE = Create_Lex(OPERATOR, "~");
    Lex CIRCUMFLEX = Create_Lex(OPERATOR, "^");
    Lex AT = Create_Lex(OPERATOR, "@");
    Lex EXLAMATION = Create_Lex(OPERATOR, "!");
    Lex COMMENT = Create_Lex(OPERATOR, "#");

    char lexi[2] = {lex, '\0'};

    Lex UNKNOWN_LEX = Create_Lex(UNKNOWN, lexi);

    Lex WHITESPACE_LEX = Create_Lex(WHITESPACE, lexi);
    Lex LEX_LEX = Create_Lex(LEX, lexi);
    Lex CAPLEX = Create_Lex(CAP_LEX, lexi);
    Lex NUMBER = Create_Lex(NUMBER_TYPE, lexi);
    Lex NEWLIN = Create_Lex(NEWLINE, lexi);
    Lex TABB = Create_Lex(TAB, lexi);


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
        
        case '\n':
            return NEWLIN;
        break;

        case 'a':
            return LEX_LEX;
        break;
        case 'b':
            return LEX_LEX;
        break;
        case 'c':
            return LEX_LEX;
        break;
        case 'd':
            return LEX_LEX;
        break;
        case 'e':
            return LEX_LEX;
        break;
        case 'f':
            return LEX_LEX;
        break;
        case 'g':
            return LEX_LEX;
        break;
        case 'h':
            return LEX_LEX;
        break;
        case 'i':
            return LEX_LEX;
        break;
        case 'j':
            return LEX_LEX;
        break;
        case 'k':
            return LEX_LEX;
        break;
        case 'l':
            return LEX_LEX;
        break;
        case 'm':
            return LEX_LEX;
        break;
        case 'n':
            return LEX_LEX;
        break;
        case 'o':
            return LEX_LEX;
        break;
        case 'p':
            return LEX_LEX;
        break;
        case 'q':
            return LEX_LEX;
        break;
        case 'r':
            return LEX_LEX;
        break;
        case 's':
            return LEX_LEX;
        break;
        case 't':
            return LEX_LEX;
        break;
        case 'u':
            return LEX_LEX;
        break;
        case 'v':
            return LEX_LEX;
        break;
        case 'w':
            return LEX_LEX;
        break;
        case 'x':
            return LEX_LEX;
        break;
        case 'y':
            return LEX_LEX;
        break;
        case 'z':
            return LEX_LEX;
        break;

        case 'A':
            return CAPLEX;
        break;
        case 'B':
            return CAPLEX;
        break;
        case 'C':
            return CAPLEX;
        break;
        case 'D':
            return CAPLEX;
        break;
        case 'E':
            return CAPLEX;
        break;
        case 'F':
            return CAPLEX;
        break;
        case 'G':
            return CAPLEX;
        break;
        case 'H':
            return CAPLEX;
        break;
        case 'I':
            return CAPLEX;
        break;
        case 'J':
            return CAPLEX;
        break;
        case 'K':
            return CAPLEX;
        break;
        case 'L':
            return CAPLEX;
        break;
        case 'M':
            return CAPLEX;
        break;
        case 'N':
            return CAPLEX;
        break;
        case 'O':
            return CAPLEX;
        break;
        case 'P':
            return CAPLEX;
        break;
        case 'Q':
            return CAPLEX;
        break;
        case 'R':
            return CAPLEX;
        break;
        case 'S':
            return CAPLEX;
        break;
        case 'T':
            return CAPLEX;
        break;
        case 'U':
            return CAPLEX;
        break;
        case 'V':
            return CAPLEX;
        break;
        case 'W':
            return CAPLEX;
        break;
        case 'X':
            return CAPLEX;
        break;
        case 'Y':
            return CAPLEX;
        break;
        case 'Z':
            return CAPLEX;
        break;

        case '0':
            return NUMBER;
        break;
        case '1':
            return NUMBER;
        case '2':
            return NUMBER;
        break;
        case '3':
            return NUMBER;
        break;
        case '4':
            return NUMBER;
        break;
        case '5':
            return NUMBER;
        break;
        case '6':
            return NUMBER;
        break;
        case '7':
            return NUMBER;
        break;
        case '8':
            return NUMBER;
        break;
        case '9':
            return NUMBER;
        break;

        default:
            return UNKNOWN_LEX;
        break;
    }
}

#endif