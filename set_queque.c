#include "monty.h"

/**
 * f_queue - Sets the stack behavior to queue (FIFO).
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty file (not used)
 * Return: No return value
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifo = 1;
}

/**
 * add_queue - Adds a node to the tail of the stack (queue).
 * @head: Pointer to the stack's head
 * @n: New value
 * Return: No return value
 */
void add_queue(stack_t **head, int n)
{
    stack_t *new_node, *current;

    current = *head;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}
