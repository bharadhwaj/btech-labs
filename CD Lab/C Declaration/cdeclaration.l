%{
	#include<stdio.h>
	#include "y.tab.h"
%}

char [a-zA-Z]
digit [0-9]
%%

"int"|"float"|"char"|"double" { return DATATYPE; }
END {  return END; }
"[" 								{ return '['; }
"]" 								{ return ']'; }
[;] 								{ return ';'; }
[,] 								{ return ','; }
[=] 								{ return '='; }

[-]?{digit}+("."{digit}+)? 			{ return DIGIT; }

([_]?|{char}+)({char}|{digit}|[_])* { return IDENTIFIER; }

"\n" 								{ return NEWLINE;}

" "								;

%%
