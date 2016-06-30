%{
	#include<stdio.h>
%}

%%

[A-Z] 		{
				char letter = yytext[0];
				letter += 32;
				printf("%c",letter); 
			}
		
[\t " "]+ 	{ printf(" "); }

.			;


%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yylex();
	fclose(yyin);
}
