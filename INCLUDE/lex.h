#ifndef LEX_H
#define LEX_H

typedef enum{
    ENDMARKER,
    NAME,
    TAB,
    NUMBER_TYPE,
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
    EXLAM,
    AMPER,
    DEFAULT,
    RESERVED,
    CAP_LEX,
    LEX
} Token_Type;

const char* Token_Type_Name[] = {
    "ENDMARKER",
    "NAME",
    "TAB",
    "NUMBER_TYPE",
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
    "EXLAMATION",
    "AMPER",
    "DEFAULT",
    "RESERVED",
    "CAP_LEX",
    "LEX"
} ;

typedef enum{
    NUMBER_RESERVED,
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

typedef struct {
    char* line;
    int index;
} Rex;

typedef struct {
    Rex rex;
    const char* set[100];
    int index;
} Tex;

Tex Create_Tex(const char* line[100], Rex rex){
    Tex tex;
    tex.rex = rex;
    for (int i = 0; i < 100; i++) {
        tex.set[i] = line[i];
    }
    return tex;
}

#endif