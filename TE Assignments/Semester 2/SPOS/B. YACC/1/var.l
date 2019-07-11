%{
    #include<stdio.h>
    #include "y.tab.h"
%}
%%
"int" |
"String" |
"float" |
"double" |
"long" |
"char" |
"byte" |
"boolean" |
"short"                    {    return DATATYPE;    }
","                        {    return COMMA;       }
";"                        {    return SEMICOLON;   }
[a-zA-Z]+[a-zA-Z0-9]*      {    return TOKEN;       }
"\n"                       {    return NEWLINE;     }
%%

