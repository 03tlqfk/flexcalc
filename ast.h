/* node in the ast */
struct ast {
	int type;
	struct ast *l;
	struct ast *r;
};

struct ast_leaf {
	int type;
	int value;
};

/* build ast node */
struct ast *alloc_ast(int, struct ast *, struct ast *);
struct ast *alloc_ast_leaf(int);

/* evaluate ast */
int eval_ast(struct ast *);

/* delete and free ast */
void free_ast(struct ast *);

