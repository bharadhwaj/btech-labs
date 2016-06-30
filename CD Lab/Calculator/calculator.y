%{	#include<stdio.h>
	void yyerror(char *s);
	int yylex(void);
%}

%union {
	float val;
}

%token <val> NUMBER
%token END
%token NEWLINE

%type <val> expression

%left '+' '-' 
%left '*' '/'


%%

calculator : statements END { return; }
statements : statement statements 
			 | statement
			 ;
statement  : expression NEWLINE{ printf("Answer : %.2f \n\n", $1); }
			 ;
expression : NUMBER { $$ = $1; }
			 | expression '+' expression { $$ = $1 + $3; }
			 | expression '-' expression { $$ = $1 - $3; }
			 | expression '*' expression { $$ = $1 * $3; }
			 | expression '/' expression { $$ = $1 / $3; }
			 ;
%%

int main() {
	printf("\n DESKTOP CALCULATOR \n\n");
	yyparse();
}

void yyerror(char *s) {
    printf("Error: %s \n", s);
}

