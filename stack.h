#ifndef STACK_
#define STACK_

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node{
    int val;
    struct stack_node *prev;
} st_node_t;

void init(st_node_t*);
void push(st_node_t**, int);
int pop(st_node_t**);
int empty(st_node_t*);

#endif /* STACK_ */