%{
#include<stdio.h>
#include "y.tab.h"
extern char domain[64];
%}

digit [0-9]

%%


[_a-zA-Z0-9]+ {  return STRING; }
[\@] { return '@'; }
[\.] { return '.'; }



[\n] {return NEWLINE; }
[ \t] {}


%%

