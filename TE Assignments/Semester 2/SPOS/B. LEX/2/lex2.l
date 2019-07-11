%{
	int keywordCount = 0;
	int tokenCount = 0;
	int statementCount = 0;
	int stringCount = 0;
	int otherCount = 0;
	int lineCount = 0;
	int relationalOperator = 0;
	int dataTypeCount = 0;
	
	int flagClass = 0;
	int flagImport = 0;
	int flagVariable = 0;
	
%}


%%
"break" |
"case" |
"continue" |
"default" |
"do" |
"else" |
"for" |
"if" |
"new" |
"package" |
"private" |
"protected" |
"public" |
"return" |
"static" |
"switch" |
"this" |
"void" |
"while" |
"true" |
"false" |
"null"                      {      
                                printf("\nKEYWORD : %s",yytext);   
                                keywordCount++;
                            }
"class"				        { 
                                printf("\nKEYWORD : %s",yytext);
                                keywordCount++; 
                                flagClass = 1;
                            }
"import"					{       
        						printf("\nKEYWORD : %s",yytext);
                                keywordCount++;
                                flagImport = 1; 
                            }
"int" |
"String" |
"float" |
"double" |
"long" |
"char" |
"byte" |
"boolean" |
"short"						{
					  			dataTypeCount++;
					  			printf("\nDATA TYPE : %s",yytext );
					  			flagVariable = 1;
				      		}
[;]                         {     statementCount++; }  
\"[^"]*\"                   {     stringCount++;    }
[a-zA-Z][a-zA-Z0-9]*        {
								if(flagClass)
								{
									printf("\nCLASS NAME : %s",yytext);
									flagClass = 0; 	
								}
								else if(flagImport)
								{
									printf("\nBASE PACKAGE NAME : %s",yytext);
									flagImport = 0;
								}
								else if(flagVariable)
								{
									printf("\nVARIABLE NAME : %s",yytext);
									flagVariable = 0;
								}
								else
								{
                                	printf("\nTOKEN : %s",yytext);     
                                }
                                tokenCount++;
                            }
[\n]                        {     lineCount++;      }
[=|+|-|*|/|<|>]					{
								printf("\nOPERATOR : %s",yytext);
								relationalOperator++;	
							}
.                           {     otherCount++;     }
%%


int main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\n\n*** SUMMARY ***\n");
	printf("\nKEYWORD count : %d", keywordCount);
	printf("\nSTATEMENT count : %d", statementCount);
	printf("\nSTRING count : %d", stringCount);
	printf("\nTOKEN count : %d", tokenCount);
	printf("\nOPERATOR count : %d", relationalOperator);
	printf("\nLINE count : %d", lineCount);
	printf("\n\n***\n");
	return 1;
}

int yywrap()
{
	return 1;
}
