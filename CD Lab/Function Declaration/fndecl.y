%{
#include<stdio.h>
#define YYDEBUG 1
void yyerror(char *s);
int yylex(void);
%}

%token IDENTIFIER NUMBER  P_OPEN P_CLOSE 
%token <str> TYPE
%union{
    char str[32];
}


%%

declaration:
    TYPE IDENTIFIER P_OPEN TYPE IDENTIFIER ',' TYPE IDENTIFIER P_CLOSE ';' {
                                             if(strcmp($1,$4)==0 && strcmp($4,$7) == 0)
                                                 printf("Declaration OK\n");
                                              else
                                                printf("Invalid declaration\n");
                                             return;
                                              }

    | TYPE IDENTIFIER P_OPEN TYPE ',' TYPE P_CLOSE ';' {
                                             if(strcmp($1,$4)==0 && strcmp($4,$6) == 0)
                                                 printf("Declaration OK\n");
                                              else
                                                printf("Invalid declaration\n");
                                             return;
                                              }
 
%%
void main(int argc, char *argv[]) {

	yyparse();


}

void yyerror(char *s){
    printf("Invalid declaration\n");
}

