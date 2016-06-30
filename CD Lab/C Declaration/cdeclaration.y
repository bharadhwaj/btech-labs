%{
#include<stdio.h>
void yyerror(char *s);
int yylex(void);
%}

%token IDENTIFIER DATATYPE END NEWLINE DIGIT PREFIX

%%

program: statements NEWLINE NEWLINE{ return ; }
    ;


statements: statement statements NEWLINE { printf("Correct Syntax \n");} statements
	| statement NEWLINE { printf("Correct Syntax \n");} statements
	;

statement: DATATYPE variables';'
	;

variables:
	variable ',' variables
	| variable;

variable: IDENTIFIER
	| IDENTIFIER'[' DIGIT ']'
	| IDENTIFIER '=' DIGIT
	| IDENTIFIER '=' IDENTIFIER ;


%%

void main(int argc, char *argv[]) {
	printf("\n \t C DECLARATION\n");
	yyparse();
}

void yyerror(char *s){
	printf("Error: %s\n", s);
   }
