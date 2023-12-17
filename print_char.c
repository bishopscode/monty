#include "monty.h"

/**
 * f_pcar - Prints the character at the top of the stack, followed by a new line.
 * @head: Pointer to the stack's head
 * @line_number: Line number in the Monty file
 * Return: No return value
 */
void f_pcar(stack_t **head, unsigned int line_number)
{
    stack_t *current;

    current = *head;

    if (!current)
    {
        fprintf(stderr, "L%d: can't pcar, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (current->n > 127 || current->n < 0)
    {
        fprintf(stderr, "L%d: can't pcar, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", current->n);
}
