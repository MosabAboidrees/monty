#include "monty.h"

/**
 * Nop - Does nothing.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number currently being processed.
 * Description: This function does nothing.
 */
void Nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /*This is to avoid compiler warnings about unused parameters*/
	(void)line_number;
}
