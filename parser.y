 /* declarations */
%{
#include <stdio.h>
#include "ast.h"
int yylex();
void yyerror(char *);
%}

%union {
	struct ast *node;
	int value;
}
%token ADD SUB MUL DIV EOL
%token <value> NUMBER
%type <node> exp factor term

%%

 /* rules & actions */
goal: 
| goal exp EOL		{ print_ast($2); printf("= %d\n", eval_ast($2)); free_ast($2); }
;

exp: term		{ $$ = $1; }
| exp ADD term		{ $$ = alloc_ast(ADD, $1, $3); }
| exp SUB term		{ $$ = alloc_ast(SUB, $1, $3); }
;

term: factor		{ $$ = $1; }
| term MUL factor	{ $$ = alloc_ast(MUL, $1, $3); }
| term DIV factor	{ $$ = alloc_ast(DIV, $1, $3); }
;

factor: NUMBER		{ $$ = alloc_ast_leaf($1); }
;

%%

 /* C code */
int main(void) {
	yyparse();
	return 0;
}

void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
}
