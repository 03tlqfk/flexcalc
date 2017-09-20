 /* declarations */
%{
#include <stdio.h>
int yylex();
void yyerror(char *);
%}
%token NUMBER ADD SUB MUL DIV EOL

%%

 /* rules & actions */
goal: 
| goal exp EOL		{ printf("= %d\n", $2); }
;

exp: term		{ $$ = $1; }
| exp ADD term		{ $$ = $1 + $3; }
| exp SUB term		{ $$ = $1 - $3; }
;

term: factor		{ $$ = $1; }
| term MUL factor	{ $$ = $1 * $3; }
| term DIV factor	{ $$ = $1 / $3; }
;

factor: NUMBER		{ $$ = $1; }
;

%%

 /* C code */
int main(void) {
	yyparse();
}

void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
}
