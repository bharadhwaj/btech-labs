%{
#include<stdio.h>
#include "y.tab.h"
%}

digit [0-9]

%%

[-]?{digit}+ {  strcpy(yylval.str, yytext);
                return NUMBER; }

[-]?{digit}+\.{digit}+ { strcpy(yylval.str, yytext); return NUMBER; }


[_a-zA-Z]+[_a-zA-Z0-9]* { strcpy(yylval.str, yytext); return NUMBER; }


[+] { strcpy(yylval.str, yytext);  return '+'; }
[-] { strcpy(yylval.str, yytext); return '-'; }
[*] { strcpy(yylval.str, yytext); return '*'; }
[/] { strcpy(yylval.str, yytext); return '/'; }


[(] { return P_OPEN; } 
[)] { return P_CLOSE; }     
      

[\n] {return NEWLINE; }
[ \t] {}


%%

