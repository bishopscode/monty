#include "monty.h"

/**
 * f_tack - Sets the stack behavior to lifo (LIFO).
 * @head: Pointer to the stack's head
 * @counter: Line number in the Monty file (not used)
 * Return: No return value
 */
void f_tack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifo = 0;
}
