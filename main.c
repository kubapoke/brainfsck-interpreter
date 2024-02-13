#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include "bf-interpreter.h"
#include "stack.h"

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
    int c, max_instructions_size = MAX_INSTRUCTIONS_SIZE_DEFAULT, max_cells_size = MAX_CELLS_SIZE_DEFAULT, verbose_mode = 0;
    char *file_name, *input_file_name = NULL;

    while((c = getopt(argc, argv, "n:f:i:c:v")) != -1)
    {
        switch (c)
        {
        case 'n':
            file_name = optarg;
            break;
        case 'f':
            input_file_name = optarg;
            break;
        case 'i':
            max_instructions_size = atoi(optarg);
            if(max_instructions_size <=0 || max_instructions_size > MAX_ALLOCATION_VALUE)
                usage(argv[0]);
            break;
        case 'c':
            max_cells_size = atoi(optarg);
            if(max_cells_size <=0 || max_cells_size > MAX_ALLOCATION_VALUE)
                usage(argv[0]);
            break;
        case 'v':
            verbose_mode = 1;
            break;
        case '?':
        default:
            usage(argv[0]);
            break;
        }
    }
    if (argc > optind)
        usage(argv[0]);

    if(file_name == NULL)
        usage(argv[0]);

    return bf_interpreter_main(file_name, max_instructions_size, max_cells_size, verbose_mode);
}