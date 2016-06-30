%{
	#include<stdio.h>
	int number, rem;
	int decimal = 0, flag = 0, pos = 1;
%}

%%

([0-9]*[89]+)*  { 
				  	printf(" Error: Not an octal number.");
				  	flag=1;
				}

[0-7]+ 			{
					number = atoi(yytext);
					while(number != 0) {
						rem = number % 10;
						decimal += rem * pos;
						pos *= 8;
						number /= 10;
					}
				}


%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1],"r");
	yylex();
	if(!flag)
		printf("Decimal equivalent is %d  \n", decimal);
	fclose(yyin);
}
