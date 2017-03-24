%code requires {
    #include <vector>
    #include <string>

    #include "ast/AstNode.h"
    #include "ast/CmmProgram.h"
    #include "ast/NullNode.h"
    #include "ast/Return.h"
    #include "ast/BreakInstruction.h"
    #include "ast/ContinueInstruction.h"

    // Includes for expressions
    #include "ast/expression/Expression.h"
    #include "ast/expression/LiteralNumber.h"
    #include "ast/expression/UnaryBinaryOperationOnExpression.h"
    #include "ast/expression/UnaryBinaryOperationOnVariable.h"
    #include "ast/expression/BinaryBinaryOperation.h"
    #include "ast/expression/BinaryArithmetic.h"
    #include "ast/expression/BinaryAffection.h"
    #include "ast/expression/BinaryLogic.h"
    #include "ast/expression/Parenthesis.h"
    #include "ast/expression/FunctionExpression.h"
    #include "ast/expression/VariableExpression.h"
    #include "ast/expression/ArrayExpression.h"
    #include "ast/expression/LValueExpression.h"
    #include "ast/expression/NullExpression.h"

    // Includes conditional structures
    #include "ast/block/block-class/FunctionDefinition.h"
    #include "ast/block/block-class/Else.h"
    #include "ast/block/block-class/conditional-structure/While.h"
    #include "ast/block/block-class/conditional-structure/For.h"

    // Includes for symbols table
    #include "ast/symbol_table/Symbol.h"
    #include "ast/symbol_table/Variable.h"
    #include "ast/symbol_table/Array.h"
    #include "ast/symbol_table/Type.h"

    extern "C" int yyparse (CmmProgram&);
}

%{
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

#include "ast/AstNode.h"
#include "ast/CmmProgram.h"
#include "ast/NullNode.h"

#include "ast/Return.h"
#include "ast/BreakInstruction.h"
#include "ast/ContinueInstruction.h"

// Includes for expressions
#include "ast/expression/Expression.h"
#include "ast/expression/LiteralNumber.h"
#include "ast/expression/UnaryBinaryOperationOnExpression.h"
#include "ast/expression/UnaryBinaryOperationOnVariable.h"
#include "ast/expression/BinaryBinaryOperation.h"
#include "ast/expression/BinaryArithmetic.h"
#include "ast/expression/BinaryAffection.h"
#include "ast/expression/BinaryLogic.h"
#include "ast/expression/Parenthesis.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/expression/VariableExpression.h"
#include "ast/expression/ArrayExpression.h"
#include "ast/expression/LValueExpression.h"
#include "ast/expression/NullExpression.h"

#include "ast/block/block-class/FunctionDefinition.h"

// Includes for symbols table
#include "ast/symbol_table/Variable.h"
#include "ast/symbol_table/Type.h"

void yyerror(CmmProgram& cmmp, char const* s) {
    std::cout << "Syntax error: " << s << std::endl;
}
int yylex(void);
%}

%union {
    int             ival;
    char*           sval;

    AstNode*                        statement_type;
    std::vector<AstNode*>*          bloc_expr_type;
    Block*                          bloc_type;
    FunctionDefinition*             def_func_type;
    Expression*                     expr_type;
    LValueExpression*               l_val_type;
    FunctionExpression*             function_expr_type;
    std::vector<Expression*>*       args_type;
    For*                            for_stat_type;
    While*                          while_type;
    Else*                           else_stat_type;
    Symbol*                         decl_var_type;
    Type                            type_type;

    CmmProgram*                     prog_cmm_type;
}

%type <statement_type>      statement
%type <bloc_expr_type>      bloc_expr
%type <bloc_type>           bloc
%type <def_func_type>       def_func
%type <function_expr_type>  function_expr
%type <args_type>           args
%type <expr_type>           expr for_init expr_or_null
%type <for_stat_type>       for_stat
%type <while_type>          while_stat
%type <l_val_type>          l_val
%type <prog_cmm_type>       prog_c--
%type <sval>                decl_func
%type <decl_var_type>       decl_arg
%type <decl_var_type>       decl_var
%type <type_type>           type
%type <type_type>           type_retour
%type <else_stat_type>      else_stat

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

%token <ival> V_CHAR
%token <ival> V_INT

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

%token <sval> IDENTIFIER
%token ERROR

%left OP_PLUS OP_MINUS OP_TIMES OP_DIV OP_MOD
%left OP_OR OP_AND OP_XOR OP_GREATER OP_LESSER OP_NOT
%left OP_EQ OP_EQ_NOT OP_EQ_GREATER OP_EQ_LESSER
%left OP_BIN_OR OP_BIN_AND OP_BIN_XOR OP_BIN_NOT OP_BIN_RSHIFT OP_BIN_LSHIFT
%left OP_ASSIGN OP_ASSIGN_ADD OP_ASSIGN_MINUS OP_ASSIGN_DIV OP_ASSIGN_TIMES OP_ASSIGN_MOD OP_ASSIGN_OR OP_ASSIGN_AND OP_ASSIGN_XOR OP_ASSIGN_RSHIFT OP_ASSIGN_LSHIFT
%left OP_UN_INC OP_UN_DEC

%parse-param { CmmProgram& program }

%%

prog_c--  : prog_c-- def_func  { program.addFunction($2); }
          | prog_c-- decl_func
          | { $$ = nullptr; }
          ;
          
type      : T_CHAR { $$ = Type::CHAR_T; }
          | T_INT32 { $$ = Type::INT32_T; }
          | T_INT64 { $$ = Type::INT64_T; }
          ;
          
type_retour : type { $$ = $1; }
            | T_VOID { $$ = Type::VOID_T; }
            ;

bloc      : SYM_BLOCK_OPEN bloc_expr SYM_BLOCK_CLOSE  { $$ = new Block(*$2); delete $2; }
          | SYM_BLOCK_OPEN SYM_BLOCK_CLOSE { $$ = new Block(); }
          ;
          
bloc_expr : bloc_expr statement { $1->push_back($2); $$ = $1; }
          | statement { $$ = new std::vector<AstNode*>(1, $1); }
          ;

statement : decl_def_stat SYM_SEMICOLON { /* ?? */ }
          | if_bloc { /*$$ = $1;*/ }
          | for_stat { /*$$ = $1;*/ }
          | while_stat { /*$$ = $1;*/ }
          | expr SYM_SEMICOLON { $$ = $1; }
          | bloc { $$ = $1; }
          | K_BREAK SYM_SEMICOLON { $$ = new BreakInstruction(); }
          | K_CONTINUE SYM_SEMICOLON { $$ = new ContinueInstruction(); }
          | K_RETURN SYM_SEMICOLON { $$ = new Return(); }
          | K_RETURN expr SYM_SEMICOLON { /*$$ = new Return($2);*/ }
          | SYM_SEMICOLON { $$ = new NullNode(); }
          ;

decl_arg  : decl_arg SYM_COMMA decl_var
          | decl_var { /* TODO: decl_arg is not a decl_var, it's a list ? */ }
          | T_VOID { $$ = nullptr; }
          | { $$ = nullptr; }
          ;
          
decl_func : type_retour IDENTIFIER SYM_OPEN decl_arg SYM_CLOSE { $$ = $2; } // TODO add entry to symbol table
          ;
       
def_func  : decl_func bloc  { $$ = new FunctionDefinition($2, $1); }
          ;

decl_var  : type IDENTIFIER { $$ = new Variable($2, $1); }
          | type IDENTIFIER SYM_TAB_OPEN SYM_TAB_CLOSE { $$ = new Array($2, $1, 0); }
          | type IDENTIFIER SYM_TAB_OPEN V_INT SYM_TAB_CLOSE { $$ = new Array($2, $1, $4); }
          ;

def_prim  : decl_var OP_ASSIGN expr
          ;

def_tab   : decl_var OP_ASSIGN SYM_BLOCK_OPEN args SYM_BLOCK_CLOSE
          ;
          
def_var   : def_prim
          | def_tab
          ;
          
decl_def_var  : decl_var
              | def_var
              ;
              
decl_def_stat : decl_def_stat SYM_COMMA decl_def_var
              | decl_def_var
              ;
              
if_stat   : K_IF SYM_OPEN expr SYM_CLOSE statement
          ;
          
else_stat : K_ELSE statement
          | { $$ = nullptr; }
          ;
          
if_bloc   : if_stat else_stat
          ;

for_init  : decl_var
          | expr { $$ = $1; }
          | def_var
          | { $$ = new NullExpression(); }
          ;
          
for_stat  : K_FOR SYM_OPEN for_init SYM_SEMICOLON expr_or_null SYM_SEMICOLON expr_or_null SYM_CLOSE statement {
                std::vector<AstNode*> v;
                v.push_back($9);
                $$ = new For(new Block(v), $5, $3, $7); }
          ;

while_stat  : K_WHILE SYM_OPEN expr SYM_CLOSE statement {
                std::vector<AstNode*> v;
                v.push_back($5);
                $$ = new While(new Block(v), $3); }
            ;

expr      : l_val { $$ = $1; }
          | V_INT { $$ = new LiteralNumber($1); }
          | OP_NOT expr { $$ = new UnaryBinaryOperationOnExpression(UnaryBinaryOperator::NOT, $2); }
          | l_val OP_UN_INC { $$ = new UnaryBinaryOperationOnVariable(UnaryBinaryOperator::INCREMENT_RIGHT, $1); }
          | l_val OP_UN_DEC { $$ = new UnaryBinaryOperationOnVariable(UnaryBinaryOperator::DECREMENT_RIGHT, $1); }
          | OP_UN_INC l_val { $$ = new UnaryBinaryOperationOnVariable(UnaryBinaryOperator::INCREMENT_LEFT, $2); }
          | OP_UN_DEC l_val { $$ = new UnaryBinaryOperationOnVariable(UnaryBinaryOperator::DECREMENT_LEFT, $2); }
          | OP_MINUS expr { $$ = new UnaryBinaryOperationOnExpression(UnaryBinaryOperator::MINUS, $2); }
          | OP_BIN_NOT expr { $$ = new UnaryBinaryOperationOnExpression(UnaryBinaryOperator::BINARY_NOT, $2); }
          | expr OP_BIN_XOR expr { $$ = new BinaryBinaryOperation(BinaryBinaryOperator::XOR, $1, $3); }
          | expr OP_BIN_OR expr { $$ = new BinaryBinaryOperation(BinaryBinaryOperator::OR, $1, $3); }
          | expr OP_BIN_AND expr { $$ = new BinaryBinaryOperation(BinaryBinaryOperator::AND, $1, $3); }
          | expr OP_BIN_LSHIFT expr { $$ = new BinaryBinaryOperation(BinaryBinaryOperator::LEFT_SHIFT, $1, $3); }
          | expr OP_BIN_RSHIFT expr { $$ = new BinaryBinaryOperation(BinaryBinaryOperator::RIGHT_SHIFT, $1, $3); }
          | expr OP_PLUS expr { $$ = new BinaryArithmetic(ArithmeticOperator::PLUS, $1, $3); }
          | expr OP_MINUS expr { $$ = new BinaryArithmetic(ArithmeticOperator::MINUS, $1, $3); }
          | expr OP_TIMES expr { $$ = new BinaryArithmetic(ArithmeticOperator::MUL, $1, $3); }
          | expr OP_DIV expr { $$ = new BinaryArithmetic(ArithmeticOperator::DIV, $1, $3); }
          | expr OP_MOD expr { $$ = new BinaryArithmetic(ArithmeticOperator::MOD, $1, $3); }
          | l_val OP_ASSIGN expr { $$ = new BinaryAffection(AffectionOperator::EQUAL, $1, $3); } // TODO missing +=
          | l_val OP_ASSIGN_AND expr { $$ = new BinaryAffection(AffectionOperator::AND_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_MINUS expr { $$ = new BinaryAffection(AffectionOperator::MINUS_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_TIMES expr { $$ = new BinaryAffection(AffectionOperator::MUL_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_DIV expr { $$ = new BinaryAffection(AffectionOperator::DIV_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_MOD expr { $$ = new BinaryAffection(AffectionOperator::MOD_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_XOR expr { $$ = new BinaryAffection(AffectionOperator::XOR_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_OR expr { $$ = new BinaryAffection(AffectionOperator::OR_EQUAL, $1, $3); }
          | expr OP_OR expr { $$ = new BinaryLogic(LogicOperator::OR, $1, $3); }
          | expr OP_AND expr { $$ = new BinaryLogic(LogicOperator::AND, $1, $3); }
          | expr OP_GREATER expr { $$ = new BinaryLogic(LogicOperator::GREATER, $1, $3); }
          | expr OP_EQ_LESSER expr { $$ = new BinaryLogic(LogicOperator::LESSER_EQUAL, $1, $3); }
          | expr OP_EQ_GREATER expr { $$ = new BinaryLogic(LogicOperator::GREATER_EQUAL, $1, $3); }
          | expr OP_EQ_NOT expr { $$ = new BinaryLogic(LogicOperator::NOT_EQUAL, $1, $3); }
          | expr OP_EQ expr { $$ = new BinaryLogic(LogicOperator::EQUAL, $1, $3); }
          | expr OP_LESSER expr { $$ = new BinaryLogic(LogicOperator::LESSER, $1, $3); }
          | SYM_OPEN expr SYM_CLOSE { $$ = new Parenthesis($2); }
          | V_CHAR { $$ = new LiteralNumber($1); } // TODO lose character state information, refactor ?
          | function_expr { $$ = $1; }
          ;
          
function_expr : IDENTIFIER SYM_OPEN args SYM_CLOSE { $$ = new FunctionExpression(*$3, $1); delete $3; }
              | IDENTIFIER SYM_OPEN T_VOID SYM_CLOSE { $$ = new FunctionExpression($1); }
              | IDENTIFIER SYM_OPEN SYM_CLOSE { $$ = new FunctionExpression($1); }
              ;
              
args      : args SYM_COMMA expr { $1->push_back($3); $$ = $1; }
          | expr { $$ = new std::vector<Expression*>(1, $1);}
          ;

l_val     : IDENTIFIER { $$ = new VariableExpression($1); }
          | IDENTIFIER SYM_BLOCK_OPEN expr SYM_BLOCK_CLOSE { $$ = new ArrayExpression($1, $3); }
          ;

expr_or_null  : expr { $$ = $1; }
              | { $$ = new NullExpression(); }
              ;
%%

