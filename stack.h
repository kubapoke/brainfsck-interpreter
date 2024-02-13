#ifndef STACK_
#define STACK_

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

typedef struct stack_node_t{
    int val;
    struct stack_node_t *prev;
} st_node;

void init(st_node*);
void push(st_node**, int);
int pop(st_node**);
int empty(st_node*);

#endif /* STACK_ */