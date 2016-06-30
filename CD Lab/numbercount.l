DIGIT [0-9]
SPACE [\n\t" "]
SYMBOL [+-]
%{  #include<stdio.h>
    int intcount = 0, floatcount = 0;    

%}

%%

{SPACE}* {}
{SYMBOL}?{DIGIT}+ {intcount++;}
{SYMBOL}?{DIGIT}*"."{DIGIT}+(e{SYMBOL}?{DIGIT}+)*  {floatcount++;}

%%

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1],"r");
    yylex();
    printf("\n Integer count = %d \n Float count = %d \n",intcount,floatcount);
    fclose(yyin); 
}
