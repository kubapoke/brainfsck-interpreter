#ifndef BF_INTERPRETER_
#define BF_INTERPRETER_

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

int bf_interpreter_main(char*, int, int, int);
void read_file(char*, char*, int);
void fill_bracket_array(const char*, int*);
void interpret(char*, char*, const int*, int, int);
void zero_fill(char*, int);
void write_state(char*, char*, int, int, int);
char replace_with_space(char);

#endif /* BF_INTERPRETER_ */