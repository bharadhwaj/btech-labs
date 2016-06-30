%{
#include<stdio.h>
int decimal;
int thousands;
int hundreds;
int tens;
int ones;
int i;
char ones_str[][5] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
%}

digit [0-9]

%%

{digit}+ { decimal = atoi(yytext);
           thousands = decimal / 1000;
           for(i = 0; i < thousands; i++)
                printf("M");
           decimal = decimal % 1000;
           hundreds = decimal / 100;
           if(hundreds == 9)
                printf("CM");
           else if(hundreds == 4)
                printf("CD");
           else if(hundreds == 5)
                printf("D");
           else if(hundreds < 4){
                for(i = 0;i < hundreds; i++)
                        printf("C");
           }
           else if(hundreds > 5){
                printf("D");
                for(i = 0; i < hundreds-5; i++)
                        printf("C");
           }
           decimal  = decimal % 100;
           tens = decimal / 10;
           if(tens == 9)
                printf("XC");
           else if(tens == 4)
                printf("XL");
           else if(tens == 5)
                printf("L");
           else if(tens < 4){
                for(i = 0;i < tens; i++)
                        printf("X");
           }
           else if(tens > 5){
                printf("L");
                for(i = 0; i < tens-5; i++)
                        printf("X");
           }
           decimal = decimal % 10;
           if(decimal > 0)
                printf("%s", ones_str[decimal-1]);
           printf("\n");
           }                     
           

[\.]* { printf("%s",yytext); }


%%

main()
{

yylex();

}
