#include "stack.h"

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))

void init(st_node_t *top)
{
    top->val = -1;
    top->prev = NULL;
}

void push(st_node_t **top, int v)
{
    st_node_t *p;
    if((p = malloc(sizeof(st_node_t))) == NULL)
        ERR("malloc");
    
    p->prev = *top;
    p->val = v;

    *top = p;
}

int pop(st_node_t **top)
{
    int v = (*top)->val;
    st_node_t *p = (*top)->prev;

    free(*top);
    *top = p;
    return v;
}

int empty(st_node_t *top)
{
    if(top->val < 0)
        return 1;
    return 0;
}