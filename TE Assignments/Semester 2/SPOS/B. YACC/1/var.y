%{
#include<stdio.h>
%}

%token DATATYPE COMMA SEMICOLON TOKEN NEWLINE

%%
start:
    DATATYPE varlist SEMICOLON NEWLINE {    printf("\n*** SYNTAX VALID ***");   }
    |
varlist:
    varlist COMMA TOKEN|TOKEN;
%%

int yyerror(char *str)
{
    printf("\n !!! SYNTAX INVALID !!!");
}

int yywrap()
{
    return 0;
}

int main()
{
    yyparse();
}
