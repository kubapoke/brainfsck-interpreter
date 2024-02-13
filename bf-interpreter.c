#include "bf-interpreter.h"
#include "stack.h"

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))
#define MIN_CELL_VALUE 0
#define MAX_CELL_VALUE 127

int bf_interpreter_main(char *file_name, int max_instructions_size, int max_cells_size, int verbose_mode)
{
    char *instructions, *cells;
    int *brackets;

    if((instructions = malloc(sizeof(char) * max_instructions_size)) == NULL)
        ERR("malloc");
    if((cells = malloc(sizeof(char) * max_cells_size)) == NULL)
        ERR("malloc");
    if((brackets = malloc(sizeof(int) * max_cells_size)) == NULL)
        ERR("malloc");

    zero_fill(cells, max_cells_size);
    read_file(file_name, instructions, max_instructions_size);
    fill_bracket_array(instructions, brackets);
    interpret(instructions, cells, brackets, max_cells_size);

    free(instructions);
    free(cells);
    free(brackets);
}

void read_file(char *file_name, char *instructions, int max_instructions_size)
{
    FILE *file;
    if((file = fopen(file_name, "r")) == NULL)
        ERR("fopen");

    int d, n = 0;
    char c;
    while((d = fgetc(file)) != EOF)
    {
        c = (char)d;
        if(c == '+' || c == '-' || c == '<' || c == '>' || c == '[' || c == ']' || c == '.' || c == ',')
        {
            if(n > max_instructions_size)
                ERR("too many input elements");
            instructions[n++] = c;
        }
    }

    if(n > max_instructions_size)
        ERR("too many input elements");
    instructions[n++] = '\0';

    if(fclose(file))
        ERR("fclose");
}

void fill_bracket_array(char *instructions, int *brackets)
{
    st_node *top;
    if((top = malloc(sizeof(st_node))) == NULL)
        ERR("malloc");

    init(top);
    for(int i = 0; instructions[i] != '\0'; ++i)
    {
        if(instructions[i] == '[')
        {
            push(&top, i);
        }
        else if(instructions[i] == ']')
        {
            if(empty(top))
                ERR("too many closing brackets");
            int v = pop(&top);
            brackets[v] = i;
            brackets[i] = v;
        }
        else
        {
            brackets[i] = -1; 
        }
    }

    /*
    for(int i = 0; instructions[i] != '\0'; ++i)
        printf("%c ", instructions[i]);
    printf("\n\n");
    for(int i = 0; instructions[i] != '\0'; ++i)
        printf("%d ", brackets[i]);
    printf("\n\n");
    */

    if(!empty(top))
        ERR("not enough closing brackets");

    free(top);
}

void interpret(char *instructions, char *cells, int *brackets, int max_cells_size)
{
    int instruction_pointer = 0, cell_pointer = 0, used_cells = 0;

    while (instructions[instruction_pointer] != '\0')
    {
        // printf("%d ", instruction_pointer);
        switch (instructions[instruction_pointer])
        {
        case '+':
            cells[cell_pointer]++;
            if(cells[cell_pointer] > MAX_CELL_VALUE)
                ERR("cell value exceeded");
            break;
        case '-':
            cells[cell_pointer]--;
            if(cells[cell_pointer] < MIN_CELL_VALUE)
                ERR("cell value exceeded");
            break;
        case '>':
            cell_pointer++;
            if(cell_pointer > used_cells)
                used_cells = cell_pointer;
            if(cell_pointer >= max_cells_size)
                ERR("cell pointer out of range");
            break;
        case '<':
            cell_pointer--;
            if(cell_pointer < 0)
                ERR("cell pointer out of range");
            break;
        case '.':
            fputc(cells[cell_pointer], stdout);
            break;
        case ',':
            cells[cell_pointer] = fgetc(stdin);
            if(cell_pointer >= max_cells_size || cell_pointer < 0)
                ERR("cell pointer out of range");
            break;
        case '[':
            if(cells[cell_pointer] == 0)
                instruction_pointer = brackets[instruction_pointer];
            break;
        case ']':
            if(cells[cell_pointer] != 0)
                instruction_pointer = brackets[instruction_pointer];
            break;
        default:
            ERR("invalid symbol loaded");
        }

        instruction_pointer++;
    }   
}

void zero_fill(char *cells, int max_cells_size)
{
    for(int i = 0; i < max_cells_size; ++i)
        cells[i] = 0;
}