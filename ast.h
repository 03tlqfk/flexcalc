/* node in the abstract syntax tree */
struct ast {
	int type;
	struct ast *l;
	struct ast *r;
};

struct ast_leaf {
	int type;
	int value;
};

/* build an AST node */
struct ast *alloc_ast(int, struct ast *, struct ast *);
struct ast *alloc_ast_leaf(int);

/* evaluate an AST */
int eval_ast(struct ast *);

/* delete and free an AST */
void free_ast(struct ast *);

/* print an AST */
void print_ast(struct ast *);
