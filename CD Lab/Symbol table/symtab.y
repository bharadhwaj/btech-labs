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
%token BLOCK_START BLOCK_END EQUALS

%%

program: statements { printsymtab(); return; }

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
      TYPE IDENTIFIER EQUALS CHAR { strcpy($2->type, $1); $2->charval = $4; }
    | TYPE IDENTIFIER EQUALS INT {  strcpy($2->type, $1); $2->intval = $4; }
    | TYPE IDENTIFIER EQUALS FLOAT { strcpy($2->type, $1); $2->floatval = $4; }
    | IDENTIFIER EQUALS CHAR { $1->charval = $3; }
    | IDENTIFIER EQUALS FLOAT { $1->floatval = $3; }
    | IDENTIFIER EQUALS INT { $1->intval = $3; }
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

symrec* putsym(char *sym_name, int scope_depth, int depth_id) {
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  ptr->scope_depth = scope_depth;
  ptr->depth_id = depth_id;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec* getsym (char *sym_name, int scope_depth, int depth_id) {
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0 && ptr->scope_depth == scope_depth && ptr->depth_id == depth_id)
      return ptr;
  return 0;
}

void printsymtab(){
    symrec *ptr;
    printf("------------------------------------------\n");
    printf("| TYPE  | NAME       |  VALUE   |  DEPTH |\n");
    printf("--------+------------+----------+---------\n");
    for(ptr = sym_table; ptr != NULL; ptr = (symrec *)ptr->next)
        if(strcmp(ptr->type, "char") == 0)
            printf("| %-5s | %-10s | %-8c | %-5d  |\n", ptr->type, ptr->name, ptr->charval, ptr->scope_depth);
        else if(strcmp(ptr->type, "int") == 0)
            printf("| %-5s | %-10s | %-8d | %-5d  |\n",ptr->type, ptr->name, ptr->intval, ptr->scope_depth); 
        else if(strcmp(ptr->type, "float") == 0)
            printf("| %-5s | %-10s | %-6.2f   | %-5d  |\n", ptr->type,ptr->name, ptr->floatval, ptr->scope_depth);
   printf("------------------------------------------\n");
}
