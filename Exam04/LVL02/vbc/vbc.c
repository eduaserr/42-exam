#include <stdio.h>
#include <malloc.h> // change this to <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *parse_sum(char **s);               // <-- declaración

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
	exit(1);                                        //<-- agregar este exit
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

node    *parse_parth(char **s)                      // manejo de parentesis / factor
{
	if (isdigit(**s))
	{
		node n = {VAL, **s - '0', NULL, NULL};
		(*s)++;
		return (new_node(n));
	}
	if (accept(s, '('))
	{
		node *left = parse_sum(s);
		if (!expect(s, ')'))
		{
			destroy_tree(left);
			return NULL;
		}
		return (left);
	}
	unexpected(**s);
	return NULL;
}

node    *parse_mult(char **s)                       // manejo de multiplicaciones / term
{
	node *left = parse_parth(s);
	if (!left)
		return (NULL);
	while (accept(s, '*'))
	{
		node *right = parse_parth(s);
		if (!right)
		{
			destroy_tree(left);
			return NULL;
		}
		node n = {MULTI, 0, left, right};
		left = new_node(n);
		if (!left)
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}

node    *parse_sum(char **s)                        // manejo de sumas / expression
{
	node *left = parse_mult(s);
	if (!left)
		return (NULL);
	while (accept(s, '+'))
	{
		node *right = parse_mult(s);
		if (!right)
		{
			destroy_tree(left);
			return NULL;
		}
		node n = {ADD, 0, left, right};
		left = new_node(n);
		if (!left)
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
	char *s = argv[1];                  // puntero a primer argumento
    node *tree = parse_sum(&s);         // guardamos en una lista simple el parseo de args
    if (!tree || *s)                    // manejo de errores
	{
		if (*s)
			unexpected(*s);
		else
			unexpected(0);
		return (1);
	}
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
	return (0);
}
