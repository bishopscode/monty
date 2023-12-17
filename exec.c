#include "monty.h"

/**
 * execute_opcode - Executes the opcode based on the given instruction.
 * @content: Line content from the Monty file
 * @stack: Pointer to the head of the stack
 * @counter: Line counter
 * @file: Pointer to the Monty file
 * Return: 0 on success, 1 if the opcode is unknown
 */
int execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", f_pushy}, {"pall", f_priz}, {"pint", f_ptop},
        {"pop", f_pop},
        {"swap", f_switch},
        {"add", f_adz},
        {"nop", f_nil},
        {"sub", f_sstack},
        {"div", f_divz},
        {"mul", f_mulz},
        {"mod", f_modz},
        {"pchar", f_pcar},
        {"pstr", f_str},
        {"rotl", f_rol},
        {"rotr", f_rot},
        {"queue", f_queue},
        {"stack", f_tack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode && opcode[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}
