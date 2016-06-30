%{
    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    #define YYDEBUG 1
    void yyerror(char *s);
    int yylex(void);
    int tempcount = 0;

%}

%union{
    char string[64];
}

%token STRING DOMAIN 
%token NEWLINE

%%

email: 
         address NEWLINE { printf("Valid email address\n"); return; } ;
    
address:
         STRING '@' STRING '.' STRING;
    

%%
void main(int argc, char *argv[]) {

	yyparse();
	printf("\n");


}

void yyerror(char *s){
    printf("Invalid email.\n");
   }

