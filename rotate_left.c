#include "monty.h"

/**
 * f_rol - Rotates the stack to the top.
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty file (unused)
 * Return: No return value
 */
void f_rol(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *current;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    current = (*head)->next;
    current->prev = NULL;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = current;
}
