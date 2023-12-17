#include "monty.h"

/**
 * f_str - Prints the string starting at the top of the stack.
 * @head: Pointer to the stack's head
 * @line_number: Line number in the Monty file (not used)
 * Return: No return value
 */
void f_str(stack_t **head, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;

    current = *head;

    while (current)
    {
        if (current->n > 127 || current->n <= 0)
        {
            break;
        }
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}
