%{
	#include<stdio.h>
	int i;
%}

DIGIT [0-9]
SYMBOL [~`<>!@$%^&*()-=+|/\\\]\}\[\{\':,?]

%%
		
(["].*["]|[//].*[//]|[/*].*[*/])	{ printf("%s",yytext); }
					
({SYMBOL}|{DIGIT}|[_][_]+)+(.)*		{ printf("%s",yytext); }

. 									{ 
										for(i = 0; i < yyleng; i++) {
											if((yytext[i] >= 'a') && (yytext[i] <= 'z'))
												yytext[i]-=32;
											printf("%c",yytext[i]);
										}
									}

%%

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	fclose(yyin);
}
