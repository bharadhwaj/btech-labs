%{
#include<stdio.h>
#include "y.tab.h"
%}


%%

 
int { strcpy(yylval.str,yytext); return TYPE; }
float { strcpy(yylval.str,yytext); return TYPE; }
char { strcpy(yylval.str,yytext); return TYPE; }
                 


[_a-zA-Z]+[_0-9a-zA-Z]* { return IDENTIFIER; }
  

[(] { return P_OPEN; }
[)] { return P_CLOSE; }
[,] { return ','; }
[;] { return ';'; }

[\t\n ] {}
                       
%%

