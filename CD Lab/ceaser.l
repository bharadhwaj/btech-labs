%{  #include<stdio.h>
	char STR[256];
	int count = 0;
%}

TEXT [a-z\n\t" "]

%%

{TEXT} {    STR[count] = yytext[0];
			if(STR[count] == ' ' || STR[count] == '\n' || STR[count] == '\t')
				STR[count++] = ' ';
			else if(STR[count] < 'x')
				STR[count++] -= 29;
	   		else
	   			STR[count++] -= 55;
	   }	

%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
	yylex();
	printf("\n Cipher Text: %s \n", STR);
	fclose(yyin);
}
