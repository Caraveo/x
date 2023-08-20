
X FUN[
    STRING String: Hello World! + 'Hello'
    INDEX: ARRAY/LIST
    FLOAT Float: 12.0 ::Extended Float High Precision - Memory Intensive
    INTEGER Integer: Integer
    BOOL Check: TRUE/FALSE/EXIST
]

STRING, INTEGER FUN(STRING Param, INTEGER Param)[

    RETURN "Hello", 10
]

FUN()[]
FUN[].STRING
FUN[].INTEGER

METHODS
    API[] #Returns an JSON Object-like Index.
    OPERATOR + - * / % @  #
    ASSIGN:
    DO()[]
    COMPARISON( < > ! OR &&)
    DISPLAY[]
    RESUME| CONCATINATION
    INDEX{}
    COMMENT :: "This is a comment"
    ESCAPE \\ :: "Need to figure out Escape"
    CHAIN.
    EXIST?
    VAR$
    SEPERATE,

FUN.String :: Calls the function/class/method and returns the string in the chain.


FOR Int IN Cats[
    DISPLAY[Int[i]] 
]

DO()[
    
    ESCAPE
]


INDEX Cats = ["Hello", "Hello", "Hello"]
INDEX Vertices = 

STRING Hello = The value is OPERATOR[1 +  2]

API[
    URL = localhost, 
    TOKEN=X, 
    AUTHTYPE=OPEN
].CREATE[
    key = value :: Can Specify Specific KEY::VALUE Pair to Write
].READ[
    { } ::Returns JSON OBJECT
].UPDATE[

].DELETE[

]

JSON{} :: OBJECT

IF(1 < 2)[
    BOOL Hello = TRUE
].ELSE(Hello = EXIST)[
    :: THIS IS ELSE IF
    DISPLAY[Hello is not null.]
].ELSE[
    :: THIS IS ELSE
]

INTEGER Average: @ 10 10 10 10 10

DISPLAY[Hello My name is $Average]
Hello my name is 10

DISPLAY[This is money \\$$Average.]
This is money $10

DISPLAY[This is money \\$$Average|10]
This is money $1010


INTEGER ThisIsASum = 10 + 10




