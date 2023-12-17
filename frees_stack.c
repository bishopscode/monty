#include "monty.h"

/**
 * free_stack - Frees a doubly linked list representing a stack.
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *current;

    current = head;

    while (head)
    {
        current = head->next;
        free(head);
        head = current;
    }
}
