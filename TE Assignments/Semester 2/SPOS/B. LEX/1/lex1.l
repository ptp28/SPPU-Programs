%{
	int spaceCount = 0;
	int wordCount = 0;
	int lineCount = 0;
	int numCount = 0;
	int vowelCount = 0;
	int lowerCaseCount = 0;
	int upperCaseCount = 0;
	int consonantCount = 0;
%}


%%
\ 			{ spaceCount++; wordCount++; }
\n			{ lineCount++; wordCount++; }
[0-9]		{ numCount++; }
a|e|i|o|u	{ vowelCount++; lowerCaseCount++; }
A|E|I|O|U	{ vowelCount++; upperCaseCount++; }
[a-z]		{ lowerCaseCount++; consonantCount++; }
[A-Z]		{ upperCaseCount++; consonantCount++; }
%%


int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		yyin = fopen(argv[1],"r");
	}
	yylex();
	printf("\n SPACE count 		    : %d" , spaceCount);
	printf("\n WORD count		    : %d" , wordCount);
	printf("\n LINE count 		    : %d" , lineCount);
	printf("\n NUMBER count		    : %d" , numCount);
	printf("\n VOWEL count 		    : %d" , vowelCount);
	printf("\n CONSONANT count 	    : %d" , consonantCount);
	printf("\n UPPERCASE count 	    : %d" , upperCaseCount);
	printf("\n LOWERCASE count 	    : %d" , lowerCaseCount);
	printf("\n");
	return 1;
}

int yywrap()
{
	return 1;
}
