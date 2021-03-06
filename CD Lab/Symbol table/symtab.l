%{
	#include <stdlib.h>
	void yyerror(char *);
	void yyprint(char *);
	#include "y.tab.h"
	#include "symtab.h"
	int scope_depth=0;
	int depth_id = 0;
%}

%%

int { strcpy(yylval.type, yytext); return TYPE; }
float { strcpy(yylval.type, yytext); return TYPE; }
char { strcpy(yylval.type, yytext); return TYPE; }

[_a-zA-Z]+[_a-zA-Z0-9]* {
                               
								symrec *s;
								s = getsym(yytext,scope_depth,depth_id);
								if(s == 0)
									s = putsym(yytext,scope_depth,depth_id);
									
							
								yylval.tptr = s;
								return (IDENTIFIER); 
					    }
					    
					    
[0-9]+\.[0-9]+ {yylval.floatval = atof(yytext); return FLOAT; }
[0-9]+ {yylval.intval = atoi(yytext); return INT; }
\'.\' {yylval.charval = yytext[1]; return CHAR; }

[{] { scope_depth++; depth_id++; return BLOCK_START;}
[}] { scope_depth--; return BLOCK_END;}


[;] { return ';';}
[=] { return EQUALS; }


[ \t\n]+ {/* Do nothing. \n*/}
%%


