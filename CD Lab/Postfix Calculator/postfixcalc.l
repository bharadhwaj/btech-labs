%{
	#include<stdio.h>
	#include "y.tab.h"
%}

%%

[-+/*]			{	return *yytext; }
[-]?[0-9]+ 		{
				yylval.ival = atoi(yytext);
				return INTEGER;
			}
[-]?[0-9]+"."[0-9]+	{
				yylval.fval = atof(yytext);
				return FLOAT;
			     }

[\n]			     { return yytext[0];}

.			     { }


%%


