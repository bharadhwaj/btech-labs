%{
#include<stdio.h>
#include<string.h>
#define YYDEBUG 1
void yyerror(char *s);
int yylex(void);
%}

%union {
    char str[32];
}


%token P_OPEN P_CLOSE NUMBER NEWLINE

%type <str> NUMBER
%type <str> expression


%left '+' '-'
%left '*' '/'


%%

program: 
    statement NEWLINE { return; } ;
    

statement:	
    expression { printf("Postfix form: %s\n",$1);} ;
    
expression: 
         expression '+' expression {  sprintf($$, "%s %s + ", $1, $3); }
       | expression '-' expression {  sprintf($$, "%s %s - ", $1, $3); }
       | expression '*' expression {  sprintf($$, "%s %s * ", $1, $3); }
       | expression '/' expression {  sprintf($$, "%s %s / ", $1, $3); }
       | P_OPEN expression P_CLOSE {  strcpy($$, $2); }
       | NUMBER { strcpy($$, $1); }
       ;

    

%%
void main(int argc, char *argv[]) {

	printf("\n \t INFIX TO POSTFIX\n");
	yyparse();
	printf("\n");


}

void yyerror(char *s){
    printf("Error %s\n", s);
   }

