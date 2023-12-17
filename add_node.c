#include "monty.h"

/**
 * add_node - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack
 * @n: Value for the new node
 * Return: No return value
 */
void add_node(stack_t **head, int n)
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

    if (current)
        current->prev = new_node;

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    *head = new_node;
}
