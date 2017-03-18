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
%token OP_GREATER
%token OP_LESSER
%token OP_EQ
%token OP_EQ_GREATER
%token OP_EQ_LESSER
%token OP_EQ_NOT
%token OP_AND
%token OP_OR
%token OP_BIN_OR
%token OP_BIN_AND
%token OP_BIN_XOR
%token OP_BIN_NOT
%token OP_BIN_RSHIFT
%token OP_BIN_LSHIFT
%token OP_ASSIGN_ADD
%token OP_ASSIGN_MINUS
%token OP_ASSIGN_DIV
%token OP_ASSIGN_TIMES
%token OP_ASSIGN_MOD
%token OP_ASSIGN_OR
%token OP_ASSIGN_AND
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
%token SYM_TAB_OPEN
%token SYM_TAB_CLOSE
%token SYM_SEMICOLON
%token SYM_COMMA

%token IDENTIFIER
%token ERROR

%left OP_PLUS OP_MINUS OP_TIMES OP_DIV OP_MOD
%left OP_OR OP_AND OP_XOR OP_GREATER OP_LESSER OP_NOT
%left OP_EQ OP_EQ_NOT OP_EQ_GREATER OP_EQ_LESSER
%left OP_BIN_OR OP_BIN_AND OP_BIN_XOR OP_BIN_NOT OP_BIN_RSHIFT OP_BIN_LSHIFT
%left OP_ASSIGN OP_ASSIGN_ADD OP_ASSIGN_MINUS OP_ASSIGN_DIV OP_ASSIGN_TIMES OP_ASSIGN_MOD OP_ASSIGN_OR OP_ASSIGN_AND OP_ASSIGN_XOR OP_ASSIGN_RSHIFT OP_ASSIGN_LSHIFT
%left OP_UN_INC OP_UN_DEC

%parse-param { int * resultat }

%%

prog_c--  : prog_c-- def_func
          | prog_c-- decl_func
          |
          ;
          
type      : T_CHAR
          | T_INT32
          | T_INT64
          ;
          
type_retour : type
            | T_VOID
            ;

bloc      : SYM_BLOCK_OPEN bloc_expr SYM_BLOCK_CLOSE
          | SYM_BLOCK_OPEN SYM_BLOCK_CLOSE
          ;
          
bloc_expr : bloc_expr statement
          | statement
          ;

statement : decl_def_stat SYM_SEMICOLON
          | if_bloc
          | for_stat
          | while_stat
          | expr SYM_SEMICOLON
          | bloc
          | K_BREAK SYM_SEMICOLON
          | K_CONTINUE SYM_SEMICOLON
          | K_RETURN SYM_SEMICOLON
          | K_RETURN expr SYM_SEMICOLON
          | SYM_SEMICOLON
          ;
          
decl_arg  : decl_arg SYM_COMMA type decl_var_arg
          | type decl_var_arg
          | T_VOID
          |
          ;
          
decl_func : type_retour IDENTIFIER SYM_OPEN decl_arg SYM_CLOSE
          ;
          
def_func  : decl_func bloc
          ;

decl_var_arg  : decl_var
              |
              ;

decl_var  : IDENTIFIER
          | IDENTIFIER SYM_TAB_OPEN SYM_TAB_CLOSE
          | IDENTIFIER SYM_TAB_OPEN V_INT SYM_TAB_CLOSE
          ;

def_prim  : decl_var OP_ASSIGN expr
          ;

def_tab   : decl_var OP_ASSIGN SYM_BLOCK_OPEN args SYM_BLOCK_CLOSE
          | decl_var OP_ASSIGN expr
          ;
          
def_var   : def_prim
          | def_tab
          ;
          
decl_def_var  : decl_var
              | def_var
              ;
              
decl_def_stat : decl_def_stat SYM_COMMA decl_def_var
              | type decl_def_var
              ;
              
if_stat   : K_IF SYM_OPEN expr SYM_CLOSE statement
          ;
          
else_stat : K_ELSE statement
          |
          ;
          
if_bloc   : if_stat else_stat
          ;

for_init  : decl_var
          | expr
          | def_var
          |
          ;
          
for_stat  : K_FOR SYM_OPEN for_init SYM_SEMICOLON expr_or_null SYM_SEMICOLON expr_or_null SYM_CLOSE statement
          ;

while_stat  : K_WHILE SYM_OPEN expr SYM_CLOSE statement
            ;

expr      : l_val
          | V_INT 
          | OP_NOT expr
          | l_val OP_UN_INC
          | l_val OP_UN_DEC
          | OP_UN_INC l_val
          | OP_UN_DEC l_val
          | OP_MINUS expr
          | OP_BIN_NOT expr
          | expr OP_BIN_XOR expr
          | expr OP_BIN_OR expr
          | expr OP_BIN_AND expr 
          | expr OP_BIN_LSHIFT expr
          | expr OP_BIN_RSHIFT expr
          | expr OP_PLUS expr
          | expr OP_MINUS expr
          | expr OP_TIMES expr
          | expr OP_DIV expr
          | expr OP_MOD expr 
          | l_val OP_ASSIGN expr
          | l_val OP_ASSIGN_AND expr
          | l_val OP_ASSIGN_MINUS expr
          | l_val OP_ASSIGN_TIMES expr
          | l_val OP_ASSIGN_DIV expr
          | l_val OP_ASSIGN_MOD expr
          | l_val OP_ASSIGN_XOR expr
          | l_val OP_ASSIGN_OR expr
          | l_val OP_ASSIGN_AND expr
          | expr OP_OR expr
          | expr OP_AND expr 
          | expr OP_GREATER expr
          | expr OP_EQ_LESSER expr
          | expr OP_EQ_GREATER expr
          | expr OP_EQ_NOT expr
          | expr OP_EQ expr
          | expr OP_LESSER expr
          | SYM_OPEN expr SYM_CLOSE
          | const_char
          | function_expr
          ;
          
function_expr : IDENTIFIER SYM_OPEN args SYM_CLOSE
              | IDENTIFIER SYM_OPEN T_VOID SYM_CLOSE
              | IDENTIFIER SYM_OPEN SYM_CLOSE
              ;
              
args      : args SYM_COMMA expr
          | expr
          ;

const_char  : V_CHAR
            ;

l_val     : IDENTIFIER
          | IDENTIFIER SYM_BLOCK_OPEN expr SYM_BLOCK_CLOSE
          ;

expr_or_null  : expr
              |
              ;
%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

