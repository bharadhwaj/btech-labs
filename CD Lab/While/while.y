%{
#include<stdio.h>
#define YYDEBUG 1
void yyerror(char *s);
int yylex(void);
%}


%token WHILE OP BLOCK_START BLOCK_END P_OPEN P_CLOSE ASSIGNMENT PRINTF SCANF NUMBER IDENTIFIER


%left '+' '-'
%left '*' '/'


%%

program: 
    WHILE P_OPEN expression P_CLOSE while_statements { printf("Syntax OK\n");
                                                return ; }
    ;

while_statements:
	|statement
	|compound_statement
	;
	

    
compound_statement: 
    BLOCK_START BLOCK_END
	| BLOCK_START statements BLOCK_END
	; 
	
statements: 
      statements statement
    | statement
    ;
    
statement: 
    expression_statement;
    
    
expression_statement: 
    ';'
    |expression';'
    ;
    
expression:
    NUMBER
    |NUMBER OP NUMBER
    |IDENTIFIER OP NUMBER
    |IDENTIFIER OP IDENTIFIER
    |ASSIGNMENT
    |PRINTF
    |SCANF
    ;
    

%%
void main(int argc, char *argv[]) {

	printf("\n \t CHECK WHILE\n");
	yyparse();


}

void yyerror(char *s){
    printf("Error %s\n", s);
   }

