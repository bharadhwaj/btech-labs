%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#define YYDEBUG 1
void yyerror(char *);
int yylex(void);
void printsymtab();
%}

%union {
    int intval;  /* For returning numbers.                   */
    char charval;
    float floatval;
    char type[32];
    struct symrec  *tptr;   /* For returning symbol-table pointers      */
}

%token <tptr> IDENTIFIER 
%token <charval> CHAR 
%token <floatval> FLOAT
%token <intval> INT
%token <type> TYPE
%token BLOCK_START BLOCK_END EQUALS OP

%%

program: statements { return; }

statements: 
      statements statement
    | statement
    ;
statement:
      compound_statement
    | expression
    ;
    
    
compound_statement
	: BLOCK_START BLOCK_END
	| BLOCK_START statements BLOCK_END
	;
	
expression: declaration ';'

declaration:
	| TYPE IDENTIFIER 	{	strcpy($2->type,$1); 
							printf("Declaration found. \n");
					  	}
    | TYPE IDENTIFIER EQUALS CHAR 
    				  	{ 	if(strcmp($1 ,"char") != 0)
     							printerror($1,$2->name); 
     						else {
     							strcpy($2->type, $1);
     							printf("No error in this statement. \n");
     						}
     					}
    | TYPE IDENTIFIER EQUALS INT 
    					{  	if(strcmp($1 ,"int") != 0) 
    							printerror($1,$2->name); 
    						else { 
    							strcpy($2->type, $1);
    							printf("No error in this statement. \n");
    						}
    					}
    | TYPE IDENTIFIER EQUALS FLOAT 
    					{ 	if(strcmp($1 ,"float") != 0) 
    							printerror($1,$2->name); 
    						else {
    							strcpy($2->type, $1);
    							printf("No error in this statement. \n");
    						}
    					}
    | IDENTIFIER EQUALS CHAR 
    					{ 	if(strcmp($1->type ,"char") != 0) 
    							printerror($1->type,$1->name); 
    						else  
    							printf("No error in this statement. \n");
    					}
    | IDENTIFIER EQUALS FLOAT 
    					{	if(strcmp($1->type ,"float") != 0) 
    							printerror($1->type,$1->name); 
    						else  
    							printf("No error in this statement. \n"); 
    					}
    | IDENTIFIER EQUALS INT 
    					{	if(strcmp($1->type ,"int") != 0) 
    							printerror($1->type,$1->name); 
    						else  
    							printf("No error in this statement. \n");
    					}
    | IDENTIFIER EQUALS IDENTIFIER OP IDENTIFIER
    					{	if(strcmp($3->type ,$5->type) == 0)  
    							if(strcmp($1->type ,$3->type) == 0)
    								printf("No error in this statement. \n");
    							else 
    								printerror($1->type,$1->name);
    						else 
    							printerror($3->type,$3->name);
    					}
    ;
    
    
%%

void yyerror(char *s) {
	printf("\n ERROR:%s. Exiting.\n",s);
	return;
}

void main(int argc, char *argv[]) {
	yyparse();
}
symrec* sym_table = (symrec *)0;

void printerror(char type[], char id[]) {
	printf("Error: Type mismatch. '%s' is of type %s. \n",id, type);
}

symrec* putsym(char *sym_name, int scope_depth) {
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  ptr->scope_depth = scope_depth;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec* getsym (char *sym_name, int scope_depth) {
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0 && ptr->scope_depth == scope_depth)
      return ptr;
  return 0;
}
