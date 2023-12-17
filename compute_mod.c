#include "monty.h"

/**
 * f_modz - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Pointer to the stack's head
 * @line_number: Line number in the Monty file
 * Return: No return value
 */
void f_modz(stack_t **head, unsigned int line_number)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *head;

    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't modz, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    result = current->next->n % current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}
