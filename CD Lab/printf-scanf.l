%{
#include<stdio.h>

%}


%%

"printf" { printf("write"); }
"scanf"  { printf("read"); }

[\.]* { printf("%s",yytext); }


%%

main()
{

yylex();

}
