%{
	#include<stdio.h>
	int yylex(void);
	int yyerror(char *);
	char *yyin;
%}

%union {
	int ival;
	float fval;
}

%token <ival> INTEGER
%token <fval> FLOAT

%type <fval> stmt

%left '+' '-' '/' '*'
%start line



%%

line: line stmt '\n'	{ printf("%f",$2); }
	| line '\n'		{}
	|
	;
stmt: INTEGER		{
				$$=$1;
			}
	| FLOAT		{
				$$=$1;
			}
	| stmt  stmt '+'	{
				$$ = $1 + $2;
				
			}
	| stmt  stmt '-'	{
				$$=$1 - $2;
			}
	| stmt  stmt '*'	{
				$$=$1 * $2;}
	| stmt  stmt '/'	{
				$$=$1 / $2;
			}	
	;
%%

int yyerror(char *s)
{
	return 1;
}

int main(int argc,char *argv[])
{
	//yyin=fopen(argv[1],"r");
	yyparse();
//	fclose(yyin);
	return 1;
}
