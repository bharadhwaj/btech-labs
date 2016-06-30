CHARACTER [A-Za-z]
SPACE[\n\t' ']              
%{  #include<stdio.h>
    int length = 0, count = 0;
    char STR[50][100];
%}
 
%%
{SPACE} {}
{CHARACTER}+ { if(yyleng > length) {
                    count = 1;
                    length = yyleng;
                    strcpy(STR[count-1],yytext);
               }
               else if(yyleng == length) {
                    count++;
                    strcpy(STR[count-1],yytext);
               }
            }

%%
int main(int argc, char *argv[]) {
    int i;
    yyin = fopen(argv[1],"r");
    yylex();
    if(count == 1)
        printf("\n The longest character is %s with %d letter.",STR[0],length);
    else {
        printf("\n The longest characters are: ");
        for(i = 0; i < count; i++)
            printf("\n %s with %d character.",STR[i],length);
    }
    printf("\n");
    fclose(yyin); 
}
