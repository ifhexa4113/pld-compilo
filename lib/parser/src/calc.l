%{
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
#include "ast/block/conditional-structure/While.h"
#include "ast/block/conditional-structure/For.h"
#include "ast/block/conditional-structure/If.h"

// Includes for declarations
#include "ast/declaration/Declaration.h"
#include "ast/declaration/LValueDeclaration.h"
#include "ast/declaration/VariableDeclaration.h"
#include "ast/declaration/ArrayDeclaration.h"
#include "ast/declaration/FunctionDeclaration.h"
#include "ast/declaration/Type.h"

// Includes for definitions
#include "ast/definition/Definition.h"
#include "ast/definition/FunctionDefinition.h"
#include "ast/definition/VariableDefinition.h"
#include "ast/definition/ArrayDefinition.h"
#include "ast/definition/ArrayListDefinition.h"

#include "calc.tab.h"
#include "char_literal_parse.h"
#include "errors.h"
%}
%option noyywrap

type_char   char
type_int32  uint32_t
type_int64  uint64_t
type_void   void
key_break   break
key_cont    continue
key_return  return
key_if      if
key_else    else
key_while   while
key_for     for

int         [0-9]+
char_single '[^\\\t\n\r]'
char_octal  '\\[0-8]{1,3}'
char_hexa   '(\\x([0-9a-fA-F][0-9a-fA-F])+)'
ignored     [\n\r\t ]|#include\ \<.*\>

id_error    [0-9][A-Za-z_][A-Za-z_0-9]*
id_name     [A-Za-z_][A-Za-z_0-9]*


%%
{ignored}     { /* ignore */ }
{int}         { yylval.ival = atoi(yytext); return V_INT; }
{char_single} { yylval.ival = yytext[1]; return V_CHAR; }
{char_octal}  { yylval.ival = string_char_oct_to_int(yytext); return V_CHAR; }
{char_hexa}   { yylval.ival = string_char_oct_to_int(yytext); return V_CHAR; }
"'\\n'"       { yylval.ival = '\n'; return V_CHAR; }
"'\\a'"       { yylval.ival = '\a'; return V_CHAR; }
"'\\b'"       { yylval.ival = '\b'; return V_CHAR; }
"'\\t'"       { yylval.ival = '\t'; return V_CHAR; }
"'\\v'"       { yylval.ival = '\v'; return V_CHAR; }
"'\\f'"       { yylval.ival = '\f'; return V_CHAR; }
"'\\r'"       { yylval.ival = '\r'; return V_CHAR; }
"'\\e'"       { yylval.ival = '\e'; return V_CHAR; }
"'\\''"       { yylval.ival = '\''; return V_CHAR; }
"'\\\\'"      { yylval.ival = '\\'; return V_CHAR; }

{type_char}   { return T_CHAR; }
{type_int32}  { return T_INT32; }
{type_int64}  { return T_INT64; }
{type_void}   { return T_VOID; }

{key_break}   { return K_BREAK; }
{key_cont}    { return K_CONTINUE; }
{key_return}  { return K_RETURN; }
{key_if}      { return K_IF; }
{key_else}    { return K_ELSE; }
{key_while}   { return K_WHILE; }
{key_for}     { return K_FOR; }

{id_error}    { yylval.ival = ERROR_UNEXPECTED_NUMBER_SUFFIX; return ERROR; }
{id_name}     { yylval.sval = strdup(yytext); return IDENTIFIER; }

"+"           { return OP_PLUS; }
"-"           { return OP_MINUS; }
"/"           { return OP_DIV; }
"*"           { return OP_TIMES; }
"%"           { return OP_MOD; }
"="           { return OP_ASSIGN; }
"!"           { return OP_NOT; }
">"           { return OP_GREATER; }
"<"           { return OP_LESSER; }
"=="          { return OP_EQ; }
">="          { return OP_EQ_GREATER; }
"<="          { return OP_EQ_LESSER; }
"!="          { return OP_EQ_NOT; }
"&&"          { return OP_AND; }
"||"          { return OP_OR; }
"|"           { return OP_BIN_OR; }
"&"           { return OP_BIN_AND; }
"^"           { return OP_BIN_XOR; }
"~"           { return OP_BIN_NOT; }
">>"          { return OP_BIN_RSHIFT; }
"<<"          { return OP_BIN_LSHIFT; }
"+="          { return OP_ASSIGN_ADD; }
"-="          { return OP_ASSIGN_MINUS; }
"/="          { return OP_ASSIGN_DIV; }
"*="          { return OP_ASSIGN_TIMES; }
"%="          { return OP_ASSIGN_MOD; }
"|="          { return OP_ASSIGN_OR; }
"&="          { return OP_ASSIGN_AND; }
"^="          { return OP_ASSIGN_XOR; }
">>="         { return OP_ASSIGN_RSHIFT; }
"<<="         { return OP_ASSIGN_LSHIFT; }
"++"          { return OP_UN_INC; }
"--"          { return OP_UN_DEC; }

"("           { return SYM_OPEN; }
")"           { return SYM_CLOSE; }
"{"           { return SYM_BLOCK_OPEN; }
"}"           { return SYM_BLOCK_CLOSE; }
"["           { return SYM_TAB_OPEN; }
"]"           { return SYM_TAB_CLOSE; }
";"           { return SYM_SEMICOLON; }
","           { return SYM_COMMA; }

%%