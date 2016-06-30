%{
#include<stdio.h>
#define YYDEBUG 1
void yyerror(char *s);
int yylex(void);
%}


%token IF ELSE OP BLOCK_START BLOCK_END P_OPEN P_CLOSE ASSIGNMENT PRINTF SCANF NUMBER IDENTIFIER
%nonassoc IFX
%nonassoc ELSE

%left '+' '-'
%left '*' '/'


%%

program: 
    statement
    | IF P_OPEN expression P_CLOSE if_statements %prec IFX { printf("Syntax OK\n"); return ; }
    | IF P_OPEN expression P_CLOSE if_statements ELSE program { printf("Syntax OK\n"); return ; }
    ;

if_statements:
	|expression_statement
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
     compound_statement
    |expression_statement
    ;
    
    
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

	printf("\n \t CHECK IF\n");
	yyparse();


}

void yyerror(char *s){
    printf("Error %s\n", s);
   }

