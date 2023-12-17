#include "monty.h"

/**
 * f_priz - Prints the elements of the stack.
 * @head: Pointer to the stack's head
 * @line_number: Line number in the Monty file (not used)
 * Return: No return value
 */
void f_priz(stack_t **head, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;

    current = *head;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
