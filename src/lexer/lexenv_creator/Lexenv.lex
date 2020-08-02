ONE_LINE_COMMENT:\/\/.*\R
COMMENT_START:\/\*
COMMENT_END:\*\/

SEMICOLON:[;]
COMMA:[,]
DOT:[\.]
EQ:[=]
EQEQ:==
PLUS:[\+]
MINUS:[\-]
LESS:[\<]
MORE:[\>]

LCURLY:[{]
RCURLY:[}]
LBRACKET:[\[]
RBRACKET:[\]]
LPAREN:[(]
RPAREN:[)]

GLOBAL:global
CLASS:class
STATIC:static
PRIVATE:private
PROTECTED:protected
PUBLIC:public

PRINT_FUNC:print

BOOL_TYPE:bool
SHORT_TYPE:short
INT_TYPE:int
LONG_TYPE:long
FLOAT_TYPE:float
DOUBLE_TYPE:double
CHAR_TYPE:char
STRING_TYPE:string
ARRAY_TYPE:array
NODE_TYPE:node
INTERN_TYPE:intern

IDENTIFIER:[a-zA-Z_][a-zA-Z0-9_]*

TRUE_VAL:true
FALSE_VAL:false
NULL_VAL:null|NULL
NUMBER_VAL:\-?[0-9]+(\.?[0-9])?[0-9]*
CHAR_VALUE:\'.\'
STRING_VALUE:\".*\"