%code requires {
    #include <vector>
    #include <string>

    #include "ast/AstNode.h"
    #include "ast/block/CmmProgram.h"
    #include "ast/NullNode.h"
    #include "ast/keyword-instruction/ReturnInstruction.h"
    #include "ast/keyword-instruction/BreakInstruction.h"
    #include "ast/keyword-instruction/ContinueInstruction.h"

    // Includes for expressions
    #include "ast/expression/Expression.h"
    #include "ast/expression/LiteralNumberExpression.h"
    #include "ast/expression/UnaryBinaryOperationOnExpression.h"
    #include "ast/expression/UnaryBinaryOperationOnVariable.h"
    #include "ast/expression/BinaryBinaryOperation.h"
    #include "ast/expression/BinaryArithmeticOperation.h"
    #include "ast/expression/BinaryAffectionOperation.h"
    #include "ast/expression/BinaryLogicOperation.h"
    #include "ast/expression/ParenthesisExpression.h"
    #include "ast/expression/FunctionExpression.h"
    #include "ast/expression/VariableExpression.h"
    #include "ast/expression/ArrayExpression.h"
    #include "ast/expression/LValueExpression.h"
    #include "ast/expression/NullExpression.h"

    // Includes for blocks
    #include "ast/definition/FunctionDefinition.h"
    #include "ast/block/conditional-structure/While.h"
    #include "ast/block/conditional-structure/For.h"

    // Includes for declarations
    #include "ast/declaration/Declaration.h"
    #include "ast/declaration/VariableDeclaration.h"
    #include "ast/declaration/ArrayDeclaration.h"
    #include "ast/declaration/FunctionDeclaration.h"
    #include "ast/declaration/Type.h"

    extern "C" int yyparse (CmmProgram&);
}

%{
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

#include "ast/AstNode.h"
#include "ast/block/CmmProgram.h"
#include "ast/NullNode.h"
#include "ast/keyword-instruction/ReturnInstruction.h"
#include "ast/keyword-instruction/BreakInstruction.h"
#include "ast/keyword-instruction/ContinueInstruction.h"

// Includes for expressions
#include "ast/expression/Expression.h"
#include "ast/expression/LiteralNumberExpression.h"
#include "ast/expression/UnaryBinaryOperationOnExpression.h"
#include "ast/expression/UnaryBinaryOperationOnVariable.h"
#include "ast/expression/BinaryBinaryOperation.h"
#include "ast/expression/BinaryArithmeticOperation.h"
#include "ast/expression/BinaryAffectionOperation.h"
#include "ast/expression/BinaryLogicOperation.h"
#include "ast/expression/ParenthesisExpression.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/expression/VariableExpression.h"
#include "ast/expression/ArrayExpression.h"
#include "ast/expression/LValueExpression.h"
#include "ast/expression/NullExpression.h"

// Includes for blocks
#include "ast/definition/FunctionDefinition.h"
#include "ast/block/conditional-structure/While.h"
#include "ast/block/conditional-structure/For.h"

// Includes for declarations
#include "ast/declaration/Declaration.h"
#include "ast/declaration/VariableDeclaration.h"
#include "ast/declaration/ArrayDeclaration.h"
#include "ast/declaration/FunctionDeclaration.h"
#include "ast/declaration/Type.h"

void yyerror(CmmProgram& cmmp, char const* s) {
    std::cout << "Syntax error: " << s << std::endl;
}
int yylex(void);
%}

%union {
    int             ival;
    char*           sval;

    AstNode*                            statement_type;
    std::vector<AstNode*>*              bloc_expr_type;
    Block*                              bloc_type;
    CmmProgram*                         prog_cmm_type;

    Declaration*                        decl_type;
    Definition*                         def_type;
    Expression*                         expr_type;

    std::vector<VariableDeclaration*>*  decl_arg_type;
    FunctionDefinition*                 def_func_type;
    LValueExpression*                   l_val_type;

    std::vector<Expression*>*           args_type;
    Type                                type_type;
}

%type <statement_type>      statement
%type <bloc_expr_type>      bloc_expr
%type <bloc_type>           bloc for_stat while_stat
//%type <def_type>
%type <def_func_type>       def_func
%type <decl_type>           decl_func decl_var
%type <expr_type>           expr for_init expr_or_null function_expr
%type <l_val_type>          l_val
%type <decl_arg_type>       decl_arg
%type <args_type>           args
%type <prog_cmm_type>       prog_c--
%type <type_type>           type type_retour

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
          | K_RETURN SYM_SEMICOLON { $$ = new ReturnInstruction(nullptr); }
          | K_RETURN expr SYM_SEMICOLON { /*$$ = new ReturnInstruction($2);*/ }
          | SYM_SEMICOLON { $$ = new NullNode(); }
          ;

decl_arg  : decl_arg SYM_COMMA decl_var
          | decl_var { /* TODO: decl_arg is not a decl_var, it's a list ? */ }
          | T_VOID { $$ = nullptr; }
          | { $$ = nullptr; }
          ;
          
decl_func : type_retour IDENTIFIER SYM_OPEN decl_arg SYM_CLOSE {
                int size = 0;
                if($4 != nullptr)
                {
                    size = static_cast<int>($4->size());
                }
                $$ = new FunctionDeclaration(std::string($2), $1, size);
            }
          ;
       
def_func  : decl_func bloc  { $$ = new FunctionDefinition($1->getName(), $2->getChildren()); }
          ;

decl_var  : type IDENTIFIER { $$ = new VariableDeclaration($2, $1); }
          | type IDENTIFIER SYM_TAB_OPEN SYM_TAB_CLOSE { $$ = new ArrayDeclaration($2, $1, 0); }
          | type IDENTIFIER SYM_TAB_OPEN V_INT SYM_TAB_CLOSE { $$ = new ArrayDeclaration($2, $1, $4); }
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
          | { /* $$ = nullptr; */ }
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
                $$ = new For($5, $3, $7, v); }
          ;

while_stat  : K_WHILE SYM_OPEN expr SYM_CLOSE statement {
                std::vector<AstNode*> v;
                v.push_back($5);
                $$ = new While($3, v); }
            ;

expr      : l_val { $$ = $1; }
          | V_INT { $$ = new LiteralNumberExpression($1); }
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
          | expr OP_PLUS expr { $$ = new BinaryArithmeticOperation(ArithmeticOperator::PLUS, $1, $3); }
          | expr OP_MINUS expr { $$ = new BinaryArithmeticOperation(ArithmeticOperator::MINUS, $1, $3); }
          | expr OP_TIMES expr { $$ = new BinaryArithmeticOperation(ArithmeticOperator::MUL, $1, $3); }
          | expr OP_DIV expr { $$ = new BinaryArithmeticOperation(ArithmeticOperator::DIV, $1, $3); }
          | expr OP_MOD expr { $$ = new BinaryArithmeticOperation(ArithmeticOperator::MOD, $1, $3); }
          | l_val OP_ASSIGN expr { $$ = new BinaryAffectionOperation(AffectionOperator::EQUAL, $1, $3); } // TODO missing +=
          | l_val OP_ASSIGN_AND expr { $$ = new BinaryAffectionOperation(AffectionOperator::AND_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_MINUS expr { $$ = new BinaryAffectionOperation(AffectionOperator::MINUS_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_TIMES expr { $$ = new BinaryAffectionOperation(AffectionOperator::MUL_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_DIV expr { $$ = new BinaryAffectionOperation(AffectionOperator::DIV_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_MOD expr { $$ = new BinaryAffectionOperation(AffectionOperator::MOD_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_XOR expr { $$ = new BinaryAffectionOperation(AffectionOperator::XOR_EQUAL, $1, $3); }
          | l_val OP_ASSIGN_OR expr { $$ = new BinaryAffectionOperation(AffectionOperator::OR_EQUAL, $1, $3); }
          | expr OP_OR expr { $$ = new BinaryLogicOperation(LogicOperator::OR, $1, $3); }
          | expr OP_AND expr { $$ = new BinaryLogicOperation(LogicOperator::AND, $1, $3); }
          | expr OP_GREATER expr { $$ = new BinaryLogicOperation(LogicOperator::GREATER, $1, $3); }
          | expr OP_EQ_LESSER expr { $$ = new BinaryLogicOperation(LogicOperator::LESSER_EQUAL, $1, $3); }
          | expr OP_EQ_GREATER expr { $$ = new BinaryLogicOperation(LogicOperator::GREATER_EQUAL, $1, $3); }
          | expr OP_EQ_NOT expr { $$ = new BinaryLogicOperation(LogicOperator::NOT_EQUAL, $1, $3); }
          | expr OP_EQ expr { $$ = new BinaryLogicOperation(LogicOperator::EQUAL, $1, $3); }
          | expr OP_LESSER expr { $$ = new BinaryLogicOperation(LogicOperator::LESSER, $1, $3); }
          | SYM_OPEN expr SYM_CLOSE { $$ = new ParenthesisExpression($2); }
          | V_CHAR { $$ = new LiteralNumberExpression($1); } // TODO lose character state information, refactor ?
          | function_expr { $$ = $1; }
          ;
          
function_expr : IDENTIFIER SYM_OPEN args SYM_CLOSE { $$ = new FunctionExpression($1, *$3); delete $3; }
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

