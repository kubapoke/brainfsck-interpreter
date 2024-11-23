#include<stdio.h>
#include <stdlib.h>
#include "bf-interpreter.h"
#include "argument-parser.h"

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))
#define MAX_INSTRUCTIONS_SIZE_DEFAULT 32768
#define MAX_CELLS_SIZE_DEFAULT 32768
#define MAX_ALLOCATION_VALUE 1048576

void usage(char* pname)
{
    fprintf(stderr, "USAGE:%s -n file_name [-i max_instructions_size] [-c max_cells_size] [-v]\n", pname);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int max_instructions_size = MAX_INSTRUCTIONS_SIZE_DEFAULT, max_cells_size = MAX_CELLS_SIZE_DEFAULT,
    verbose_mode = 0, max_allocation_value = MAX_ALLOCATION_VALUE;
    char *file_name;

    if(parse_arguments(argc, argv, &file_name, &max_instructions_size, &max_cells_size, &verbose_mode, max_allocation_value))
        usage(argv[0]);

    return bf_interpreter_main(file_name, max_instructions_size, max_cells_size, verbose_mode);
}