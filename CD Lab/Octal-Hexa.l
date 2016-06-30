%{
#include<stdio.h>
%}

character [a-f]
digit [0-9]

%%

	[0-7]+ {printf("\n It is both Hexadecimal and Octal");}
	({digit}*|{character}*)+ {printf("\n Only Hexadecimal");}
	.+ {printf("\n Neither Hexadecimal nor Octal");}

%%

main() {
	yylex();
}
