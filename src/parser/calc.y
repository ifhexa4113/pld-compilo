%{
#include<cstdio>
void yyerror(int *, const char *);
int yylex(void);
%}
%union {
   int ival;
}

%token PLUS MOINS DIV OPEN CLOSE MUL
%token <ival> ENTIER

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

