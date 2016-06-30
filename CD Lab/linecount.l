LINE [\n]
SPACE [\t' ']

%{ #include<stdio.h>
    int linecount = 0, wordcount = 0, charcount = 0;
%}

%%
{SPACE} {wordcount++;}
{LINE} {linecount++;}
. {charcount++;}

%%


int main(int argc, char *argv[]) {
    yyin = fopen(argv[1],"r");
    yylex();
    printf("\n Line count = %d \n Word count = %d \n Character Count = %d \n",linecount,wordcount,charcount);
    fclose(yyin); 
}
