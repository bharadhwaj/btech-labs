%{
#include<stdio.h>
#include "y.tab.h"
%}

digit [0-9]
char [a-zA-Z]
%%

[-]?{digit}+ {  strcpy(yylval.str, yytext);
                return NUMBER; }

[-]?{digit}+\.{digit}+ { strcpy(yylval.str, yytext); return NUMBER; }

{char} { strcpy(yylval.str, yytext); return NUMBER; }


[+] { strcpy(yylval.str, yytext);  return '+'; }
[-] { strcpy(yylval.str, yytext); return '-'; }
[*] { strcpy(yylval.str, yytext); return '*'; }
[/] { strcpy(yylval.str, yytext); return '/'; }


[(] { return P_OPEN; } 
[)] { return P_CLOSE; }     

[;] { return ';'; }            

[\n] {return NEWLINE; }
[ \t] {}


%%

