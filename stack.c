#include "stack.h"

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))

void init(st_node *top)
{
    top->val = -1;
    top->prev = NULL;
}

void push(st_node **top, int v)
{
    st_node *p;
    if((p = malloc(sizeof(st_node))) == NULL)
        ERR("malloc");
    
    p->prev = *top;
    p->val = v;

    *top = p;
}

int pop(st_node **top)
{
    int v = (*top)->val;
    st_node *p = (*top)->prev;

    free(*top);
    *top = p;
    return v;
}

int empty(st_node *top)
{
    if(top->val < 0)
        return 1;
    return 0;
}