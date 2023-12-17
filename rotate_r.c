#include "monty.h"

/**
 * f_rot - Rotates the stack to the bottom.
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty file (unused)
 * Return: No return value
 */
void f_rot(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    while (copy->next)
    {
        copy = copy->next;
    }

    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}
