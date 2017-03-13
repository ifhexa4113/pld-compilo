%{
#include<cstdio>

void yyerror(int *, const char *);
int yylex(void);
%}

%union {
   int ival;
   char * sval;
}

%token OP_PLUS
%token OP_MINUS
%token OP_DIV
%token OP_TIMES
%token OP_MOD
%token OP_ASSIGN
%token OP_NOT
%token OP_NOT
%token OP_GREATER
%token OP_LESSER
%token OP_EQ
%token OP_EQ_GREATER
%token OP_EQ_LESSER
%token OP_EQ_NOT
%token OP_EQ_NOT
%token OP_AND
%token OP_AND
%token OP_OR
%token OP_OR
%token OP_BIN_OR
%token OP_BIN_OR
%token OP_BIN_AND
%token OP_BIN_AND
%token OP_BIN_XOR
%token OP_BIN_XOR
%token OP_BIN_NOT
%token OP_BIN_NOT
%token OP_BIN_RSHIFT
%token OP_BIN_LSHIFT
%token OP_ASSIGN_ADD
%token OP_ASSIGN_MINUS
%token OP_ASSIGN_DIV
%token OP_ASSIGN_TIMES
%token OP_ASSIGN_MOD
%token OP_ASSIGN_OR
%token OP_ASSIGN_OR
%token OP_ASSIGN_AND
%token OP_ASSIGN_AND
%token OP_ASSIGN_XOR
%token OP_ASSIGN_XOR
%token OP_ASSIGN_RSHIFT
%token OP_ASSIGN_LSHIFT
%token OP_UN_INC
%token OP_UN_DEC

%token <ival> T_CHAR
%token <ival> T_INT32
%token <ival> T_INT64
%token T_VOID

%token V_CHAR
%token V_INT

%token K_BREAK
%token K_CONTINUE
%token K_RETURN
%token K_IF
%token K_ELSE
%token K_WHILE
%token K_FOR

%token SYM_OPEN
%token SYM_CLOSE
%token SYM_BLOCK_OPEN
%token SYM_BLOCK_CLOSE
%token SYM_TAB_CLOSE
%token SYM_TAB_CLOSE
%token SYM_SEMICOLON

%type <ival> expr

%left MOINS PLUS
%left MUL DIV

%parse-param { int * resultat }

%%

axiome : expr { *resultat = $1; }
       ;

expr : expr PLUS expr { $$ = $1 + $3; }
     | expr MUL expr  { $$ = $1 * $3; }
     | expr DIV expr  { $$ = $1 / $3; }
     | expr MOINS expr{ $$ = $1 - $3; }
     | OPEN expr CLOSE{ $$ = $2; }
     | ENTIER         { $$ = $1; }
     ;

%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

