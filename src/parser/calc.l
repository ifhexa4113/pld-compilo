%{
#include "calc.tab.h"
%}
%option noyywrap
entier [0-9]+
%%
[ \n\t]      { /* ignore */ }
{entier}     { yylval.ival = atoi(yytext); return ENTIER; }
"+"          { return PLUS; }
"-"          { return MOINS; }
"/"          { return DIV; }
"*"          { return MUL; }
"("          { return OPEN; }
")"          { return CLOSE; }
