#ifndef ARGUMENT_PARSER_
#define ARGUMENT_PARSER_

#include<stdlib.h>
#include<string.h>

int parse_arguments(int argc, char **argv, char **file_name, int *max_instructions_size,
                    int *max_cells_size, int *verbose_mode, int max_allocation_value);

#endif //ARGUMENT_PARSER_
