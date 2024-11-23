#include "argument-parser.h"

int parse_arguments(int argc, char **argv, char **file_name, int *max_instructions_size,
                    int *max_cells_size, int *verbose_mode, int max_allocation_value)
{
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-n") == 0)
        {
            if(++i < argc)
                *file_name = argv[i];
            else
                return -1;
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            if(++i < argc)
                *max_instructions_size = strtol(argv[i], NULL, 10);
            else
                return -1;

            if(errno != 0 || *max_instructions_size <= 0 || *max_instructions_size > max_allocation_value)
                return -1;
        }
        else if (strcmp(argv[i], "-c") == 0)
        {
            if(++i < argc)
                *max_cells_size = strtol(argv[i], NULL, 10);
            else
                return -1;

            if(errno != 0 || *max_cells_size <= 0 || *max_cells_size > max_allocation_value)
                return -1;
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            *verbose_mode = 1;
        }
        else
        {
            return -1;
        }
    }

    if(*file_name == NULL)
        return -1;

    return 0;
}