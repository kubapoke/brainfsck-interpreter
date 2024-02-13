#ifndef BF_INTERPRETER_
#define BF_INTERPRETER_

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

int bf_interpreter_main(char*, int, int, int);
void read_file(char*, char*, int);
void fill_bracket_array(char*, int*);
void interpret(char*, char*, int*, int);
void zero_fill(char*, int);

#endif /* BF_INTERPRETER_ */