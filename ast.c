#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "parser.tab.h"
void yyerror(char *s);


/* build an AST node */
struct ast *alloc_ast(int type, struct ast *l, struct ast *r)
{
	struct ast *node = malloc(sizeof(struct ast));
	if (!node) {
		yyerror("out of space");
		exit(0);
	}
	node->type = type;
	node->l = l;
	node->r = r;
	return node;
}

struct ast *alloc_ast_leaf(int value)
{
	struct ast_leaf *node = malloc(sizeof(struct ast_leaf));
	if (!node) {
		yyerror("out of space");
		exit(0);
	}
	node->type = NUMBER;
	node->value = value;
	return (struct ast *)node;
}

/* evaluate an AST */
int eval_ast(struct ast *node)
{
	int result;

	switch(node->type) {
		case ADD:
			result = eval_ast(node->l) + eval_ast(node->r);
			break;
		case SUB:
			result = eval_ast(node->l) - eval_ast(node->r);
			break;
		case MUL:
			result = eval_ast(node->l) * eval_ast(node->r);
			break;
		case DIV:
			result = eval_ast(node->l) / eval_ast(node->r);
			break;
		case NUMBER:
			result = ((struct ast_leaf *)node)->value;
			break;
		default:
			printf("internal error: bad node %d\n", node->type);
	}
	return result;
}
/* delete and free an AST */
void free_ast(struct ast *node)
{
	switch(node->type) {
		case ADD:
		case SUB:
		case MUL:
		case DIV:
			free_ast(node->l);
			free_ast(node->r);
		case NUMBER:
			free(node);
			break;
		default:
			printf("internal error: free bad node %d\n", node->type);
	}
}

void print_ast(struct ast *node)
{
	switch(node->type) {
		case ADD:
			print_ast(node->l);
			printf("+");
			print_ast(node->r);
			break;
		case SUB:
			print_ast(node->l);
			printf("-");
			print_ast(node->r);
			break;
		case MUL:
			print_ast(node->l);
			printf("*");
			print_ast(node->r);
			break;
		case DIV:
			print_ast(node->l);
			printf("/");
			print_ast(node->r);
			break;
		case NUMBER:
			printf("%d", ((struct ast_leaf *)node)->value);
	}
}
