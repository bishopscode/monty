#include "monty.h"

/**
 * f_sstack - Subtracts the top element from the second element of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty file
 * Return: No return value
 */
void f_sstack(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int difference, nodes;

    current = *head;

    for (nodes = 0; current != NULL; nodes++)
        current = current->next;

    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    difference = current->next->n - current->n;
    current->next->n = difference;
    *head = current->next;
    free(current);
}
