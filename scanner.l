%{
#include "parser.tab.h"
%}

%%

 /* how to it works */
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
"("	{ return LPA; }
")"	{ return RPA; }
[0-9]+	{ yylval.value = atoi(yytext); return NUMBER; }
[ \t]	{}
\n	{ return EOL; }
.	{ printf("Unknown character '%c'\n", *yytext); }

%%


