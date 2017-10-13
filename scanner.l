 /* declarations */
%{
#include "parser.tab.h"
%}

%%

 /* patterns & actions */
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
[0-9]+	{ yylval.value = atoi(yytext); return NUMBER; }
[ \t]	{}
\n	{ return EOL; }
.	{ printf("Mystery character '%c'\n", *yytext); }

%%

 /* C code */
