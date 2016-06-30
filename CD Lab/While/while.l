%{
#include<stdio.h>
#include "y.tab.h"
%}

digit [0-9]

%%

[-]?{digit}+ { return NUMBER; }

[-]?{digit}+\.{digit}+ { return NUMBER; }

while { return WHILE; }



[a-zA-Z_]+([a-zA-Z0-9_]+)?=([0-9]+|[a-zA-Z_]+([a-zA-Z0-9_]+)?); { return ASSIGNMENT; }

"printf"[^;]* { return PRINTF; }
"scanf"[^;]*  { return SCANF; }


[_a-zA-Z]+[_a-zA-Z0-9]* { return IDENTIFIER; }

"=="  {  return OP; }
"<="  {  return OP; }
">="  {  return OP; }
"!="  {  return OP; }
"++"  {  return OP; }
"--"  {  return OP; }
[+-/*><]  {  return OP; }

[{] { return BLOCK_START; }
[}] { return BLOCK_END; }  

[(] { return P_OPEN; } 
[)] { return P_CLOSE; }     

[;] { return ';'; }            


[ \t\n] {}


%%

