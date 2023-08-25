#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    ENDMARKER,
    NAME,
    NUMBER_TOKENTYPE,
    STRING_TOKENTYPE,
    INDENT,
    DEDENT,
    WHITESPACE,
    LINE_BREAK,
    NEWLINE,
    LETTER,
    DIGIT,
    OPERATOR,
    STRING_QUOTE,
    SINGLE_LINE_COMMENT,
    MULTI_LINE_COMMENT_START,
    MULTI_LINE_COMMENT_END,
    UNKNOWN,
    TYPE_IGNORE,
    TYPE_COMMENT,
    SOFT_KEYWORD,
    FSTRING_START,
    FSTRING_MIDDLE,
    FSTRING_END,
    ERROR_TOKEN_TYPE,
    ENCODING,
    SPECIAL,
    ENDOF,
    COMM,
    EXPLAM,
    AMPER,
    DEFAULT,
    RESERVED,
    LEX
} Token_Type;

const char* Token_Type_Name[] = {
    "ENDMARKER",
    "NAME",
    "NUMBER_TOKENTYPE",
    "STRING_TOKENTYPE",
    "INDENT",
    "DEDENT",
    "WHITESPACE",
    "LINE_BREAK",
    "NEWLINE",
    "LETTER",
    "DIGIT",
    "OPERATOR",
    "STRING_QUOTE",
    "SINGLE_LINE_COMMENT",
    "MULTI_LINE_COMMENT_START",
    "MULTI_LINE_COMMENT_END",
    "UNKNOWN",
    "TYPE_IGNORE",
    "TYPE_COMMENT",
    "SOFT_KEYWORD",
    "FSTRING_START",
    "FSTRING_MIDDLE",
    "FSTRING_END",
    "ERROR_TOKEN_TYPE",
    "ENCODING",
    "SPECIAL",
    "ENDOF",
    "COMM",
    "EXPLAM",
    "AMPER",
    "DEFAULT",
    "RESERVED",
    "LEX"
} ;

typedef struct { 
    Token_Type type;
    const char* value;
} Lex;

typedef struct { 
    Lex lex;
    Token_Type type;
    char* token_type_name_string;
} Token;

Token create_Token(Token_Type type, Token_Type lex_type, Lex lex){
    Token token;
    token.type = lex_type;
    token.token_type_name_string = Token_Type_Name[type];
    return token;
}

Lex create_lex(Token_Type type, const char* value) {
    Lex lex;
    lex.type = type;
    lex.value = value;
    return lex;
}


Lex process_lexem(char lex)
{
    Lex LEFT_PARANTHESIS = create_lex(OPERATOR, "(");
    Lex RIGHT_PARANTHESIS = create_lex(OPERATOR, ")");
    Lex LEFT_SQUAREBRACKET = create_lex(OPERATOR, "[");
    Lex RIGHT_SQUAREBRACKET = create_lex(OPERATOR, "]");
    Lex COLON = create_lex(OPERATOR, ":");
    Lex COMMA = create_lex(OPERATOR, ","); 
    Lex SEMI = create_lex(OPERATOR, ";");
    Lex PLUS = create_lex(OPERATOR, "+");
    Lex MINUS = create_lex(OPERATOR, "-");
    Lex STAR = create_lex(OPERATOR, "");
    Lex SLASH = create_lex(OPERATOR, "/");
    Lex VERTICAL_BAR =  create_lex(OPERATOR, "|");
    Lex AMPER_SIGN = create_lex(OPERATOR, "&");
    Lex LESS_THAN = create_lex(OPERATOR, "<");
    Lex GREATER_THAN = create_lex(OPERATOR, ">");
    Lex EQUAL = create_lex(OPERATOR, "=");
    Lex DOT = create_lex(OPERATOR, ".");
    Lex PERCENT = create_lex(OPERATOR, "%");
    Lex LEFT_BRACE = create_lex(OPERATOR, "{");
    Lex RIGHT_BRACE = create_lex(OPERATOR, "}");
    Lex EQUAL_EQUAL = create_lex(OPERATOR, "==");
    Lex NOT_EQUAL = create_lex(OPERATOR, "!=");
    Lex LESS_THAN_EQUAL_TO = create_lex(OPERATOR, "<=");
    Lex GREATER_THAN_EQUAL_TO = create_lex(OPERATOR, ">=");
    Lex TILDE = create_lex(OPERATOR, "~");
    Lex CIRCUMFLEX = create_lex(OPERATOR, "^");
    Lex LEFT_SHIFT = create_lex(OPERATOR, "<<");
    Lex RIGHT_SHIFT = create_lex(OPERATOR, ">>");
    Lex DOUBLE_STAR = create_lex(OPERATOR, "");
    Lex PLUS_EQUAL = create_lex(OPERATOR, "+=");
    Lex MINUS_EQUAL = create_lex(OPERATOR, "-=");
    Lex STAR_EQUAL = create_lex(OPERATOR, "=");
    Lex DIVIDE_EQUAL = create_lex(OPERATOR, "/=");
    Lex PERCENT_EQUAL = create_lex(OPERATOR, "%=");
    Lex AMPER_SIGN_EQUAL = create_lex(OPERATOR, "&=");
    Lex VERTICAL_BAR_EQUAL = create_lex(OPERATOR, "|=");
    Lex CIRCUM_EQUAL = create_lex(OPERATOR, "^=");
    Lex LEFT_SHIFT_EQUAL = create_lex(OPERATOR, "<<=");
    Lex RIGHT_SHIT_EQUAL = create_lex(OPERATOR, ">>=");
    Lex DOUBLE_STAR_EQUAL = create_lex(OPERATOR, "**=");
    Lex DOUBLE_SLASH = create_lex(OPERATOR, "//");
    Lex DOUBLE_SLASH_EQUAL = create_lex(OPERATOR, "//=");
    Lex AT = create_lex(OPERATOR, "@");
    Lex AT_EQUAL = create_lex(OPERATOR, "@=");
    Lex RIGHT_ARROW = create_lex(OPERATOR, "->");
    Lex ELLIPSIS = create_lex(OPERATOR, "...");
    Lex COLON_EQUAL = create_lex(OPERATOR, ":=");
    Lex EXPLAMATION = create_lex(OPERATOR, "!");
    Lex COMMENT = create_lex(OPERATOR, "#");
    Lex UNKNOWN_LEX = create_lex(UNKNOWN, "Unknown Lex");
    
    char lexi[2] = {lex, '\0'};

    Lex WHITESPACE_LEX = create_lex(WHITESPACE, lexi);
    Lex LEX_LEX = create_lex(LEX, lexi);

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
            return EXPLAMATION;
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

typedef enum{
    NUMBER,
    IF,
    CREATE,
    VOID,
    NEW,
    CALL,
    GRAB,
    IN,
    TYPE,
    STRING,
    INDEX,
    FLOAT,
    INTEGER,
    BOOL,
    OBJECT,
    CAPITAL
} RESERVE;


Token process_Lex(Lex lex){
    switch (lex.type) {
        case LEX:
            return create_Token(LEX, lex.type, lex);
        break;
        case OPERATOR:
            return create_Token(OPERATOR, lex.type, lex);
        break;
        case UNKNOWN:
            return create_Token(UNKNOWN, lex.type, lex);
        break;
        case WHITESPACE:
            return create_Token(WHITESPACE, lex.type, lex);
        break;
        case COMM:
            return create_Token(TYPE_COMMENT, lex.type, lex);
        break;
        case EXPLAM:
            return create_Token(EXPLAM, lex.type, lex);
        break;
        case AMPER:
            return create_Token(AMPER, lex.type, lex);
        break;
        case NUMBER:
            return create_Token(AMPER, lex.type, lex);
        break;
        case NAME:
            return create_Token(AMPER, lex.type, lex);
        break;
        default:
            return create_Token(DEFAULT, lex.type, lex);
        break;
    }
}

typedef struct {
    char* line;
    int index;
} Rex;

typedef struct {
    Rex rex;
    char* set;
    int index;
} Tex;

Tex create_tex(char* line, Rex rex){
    Tex tex;
    tex.set = rex.line;
    return tex;
}

Rex Lexer(char line[100]){
    Rex rex;
    rex.line = line;
    for (int i = 0; i < strlen(line); i++) {
        char lexem = line[i];
        Lex rLex = process_lexem(lexem);
        Token token = process_Lex(rLex);

        Token Final_Token = create_Token(LEX, token.type, rLex);

        char* LEX_NAME[30];

        if(token.type == LEX){
            int line_count = 0;
            while (token.type == LEX) {
                lexem = line[i++];
                rLex = process_lexem(lexem);
                token = process_Lex(rLex);
                line_count++;
                strcat(LEX_NAME, rLex.value);
            }
            line_count = 0;
        }

        Tex tex = create_tex(*LEX_NAME, rex);

        if(token.type == OPERATOR){
            int line_count = 0;
            while (token.type == LEX) {
                lexem = line[i++];
                rLex = process_lexem(lexem);
                token = process_Lex(rLex);
                line_count++;
            }
            line_count = 0;
        }
        
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
        Process_Line(rRex);
    }
    fclose(file);
}


int main() {
    Process_File("pro.x");
    return 0;
}