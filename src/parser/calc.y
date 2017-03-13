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

%left OP_PLUS OP_MINUS OP_TIMES OP_DIV OP_MOD
%left OP_OR OP_AND OP_XOR OP_GREATER OP_LESSER OP_NOT
%left OP_EQ OP_EQ_NOT OP_EQ_GREATER OP_EQ_LESSER OP_EQ_NOT
%left OP_BIN_OR OP_BIN_OR OP_BIN_AND OP_BIN_AND OP_BIN_XOR OP_BIN_XOR OP_BIN_NOT OP_BIN_NOT OP_BIN_RSHIFT OP_BIN_LSHIFT
%left OP_ASSIGN OP_ASSIGN_ADD OP_ASSIGN_MINUS OP_ASSIGN_DIV OP_ASSIGN_TIMES OP_ASSIGN_MOD OP_ASSIGN_OR OP_ASSIGN_OR OP_ASSIGN_AND OP_ASSIGN_AND OP_ASSIGN_XOR OP_ASSIGN_XOR OP_ASSIGN_RSHIFT OP_ASSIGN_LSHIFT
%left OP_UN_INC OP_UN_DEC

%parse-param { int * resultat }

%%

Prog_c--  : Prog_c-- Def_func
          | Prog_c-- Decl_func
          |
          ;
          
Type      : T_CHAR
          | T_INT32
          | T_INT64
          ;
          
Type_retour : Type
            | T_VOID
            ;

Bloc      : SYM_BLOCK_OPEN Bloc_expr SYM_BLOCK_CLOSE
          | SYM_BLOCK_OPEN SYM_BLOCK_CLOSE
          ;
          
Bloc_expr : Bloc_expr Statement
          | Statement
          ;

Statement : Decl_Def_stat SYM_SEMICOLON
          | If_bloc
          | For_stat
          | While_stat
          | Expr SYM_SEMICOLON
          | Bloc
          | K_BREAK SYM_SEMICOLON
          | K_CONTINUE SYM_SEMICOLON
          | K_RETURN SYM_SEMICOLON
          | K_RETURN Expr SYM_SEMICOLON
          | SYM_SEMICOLON
          ;
          
Decl_Arg  : Decl_Arg SYM_COMMA Type Decl_var_arg
          | Type Decl_var_arg
          | T_VOID
          |
          ;
          
Decl_func : Type_retour Nom SYM_OPEN Decl_Arg SYM_CLOSE
          ;
          
Def_func  : Decl_func Bloc
          ;

Decl_var_arg  : Decl_var
              |
              ;

Decl_var  : Nom
          | Nom SYM_TAB_OPEN SYM_TAB_CLOSE
          | Nom SYM_TAB_OPEN const SYM_TAB_CLOSE
          ;

Def_prim  : Decl_var OP_ASSIGN Expr
          ;
          
Const_list  : Const_list SYM_COMMA const
            | const
            ;

Def_tab   : Decl_var OP_ASSIGN SYM_BLOCK_OPEN Const_list SYM_BLOCK_CLOSE
          | Decl_var OP_ASSIGN Expr
          ;
          
Def_var   : Def_prim
          | Def_tab
          ;
          
Decl_Def_var  : Decl_var
              | Def_var
              ;
              
Decl_Def_stat : Decl_Def_stat SYM_COMMA Decl_Def_var
              | Type Decl_Def_var
              ;
              
If_stat   : K_IF SYM_OPEN Expr SYM_CLOSE Statement
          ;
          
Else_stat : K_ELSE Statement
          |
          ;
          
If_bloc   : If_stat Else_stat
          ;

For_init  : Decl_var
          | Expr
          | Def_var
          |
          ;
          
For_stat  : K_FOR SYM_OPEN For_init SYM_SEMICOLON Expr_or_null SYM_SEMICOLON Expr_or_null SYM_CLOSE Statement
          ;

While_stat  : K_WHILE SYM_OPEN Expr SYM_CLOSE Statement
            ;

Expr      : L_val
          | V_INT 
          | OP_NOT Expr
          | L_val OP_UN_INC
          | L_val OP_UN_DEC
          | OP_UN_INC L_val
          | OP_UN_DEC L_val
          | OP_MINUS Expr
          | OP_BIN_NOT Expr
          | Expr OP_BIN_XOR Expr
          | Expr OP_BIN_OR Expr
          | Expr OP_BIN_AND Expr 
          | Expr OP_BIN_LSHIFT Expr
          | Expr OP_BIN_RSHIFT Expr
          | Expr OP_PLUS Expr
          | Expr OP_MINUS Expr
          | Expr OP_TIMES Expr
          | Expr OP_DIV Expr
          | Expr OP_MOD Expr 
          | L_val OP_ASSIGN Expr
          | L_val OP_ASSIGN_AND Expr
          | L_val OP_ASSIGN_MINUS Expr
          | L_val OP_ASSIGN_TIMES Expr
          | L_val OP_ASSIGN_DIV Expr
          | L_val OP_ASSIGN_MOD Expr
          | L_val OP_ASSIGN_XOR Expr
          | L_val OP_ASSIGN_OR Expr
          | L_val OP_ASSIGN_AND Expr
          | Expr OP_OR Expr
          | Expr OP_AND Expr 
          | Expr OP_GREATER Expr
          | Expr OP_EQ_LESSER Expr
          | Expr OP_EQ_GREATER Expr
          | Expr OP_EQ_NOT Expr
          | Expr OP_EQ Expr
          | Expr OP_LESSER Expr
          | SYM_OPEN Expr SYM_CLOSE
          | Const_char
          | Function_Expr
          ;
          
Function_Expr : Nom_Func SYM_OPEN Args SYM_CLOSE
              | Nom_Func SYM_OPEN T_VOID SYM_CLOSE
              | Nom_Func SYM_OPEN SYM_CLOSE
              ;
              
Args      : Args SYM_COMMA Expr
          | Expr
          ;

Const_char  : V_CHAR
            ;

L_val     : Nom
          | Nom SYM_BLOCK_OPEN Expr SYM_BLOCK_CLOSE
          ;

Expr_or_null  : Expr
              |
              ;
%%

void yyerror(int * res, const char * msg) {
   printf("Syntax error : %s\n",msg);
}

