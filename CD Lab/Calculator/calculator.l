%{ 
	#include<stdio.h>
  	#include "y.tab.h"
%}


DIGIT [0-9]
SPACE [\n" "]

%%


[-]?{DIGIT}+("."{DIGIT}+)? 	{	
								yylval.val = atof(yytext);
								return NUMBER;
							}

[+] { return '+'; }
[-] { return '-'; }
[*] { return '*'; }
[/] { return '/'; }

"\n" { return NEWLINE; }

END { return END; }

. ;

%%
