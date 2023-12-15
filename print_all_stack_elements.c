#include "monty.h"
/**
 * print_all_stack_elements - Prints all the values in the stack.
 * @stack: Pointer to a pointer to the top node of the stack.
 * @line_number: The line number where the print operation is called (unused).
 * Description: Iterates through the stack and prints each element's value.
 * This function traverses from the top to the bottom of the stack
 * and prints the value of each node.
 */
void print_all_stack_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node; /* Declaration of a pointer to a stack node */

	/* Explicitly casting line_number to void to denote unused parameter */
	(void) line_number;

	/* Validate if the stack is NULL */
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/* Initialize current_node to point to the top of the stack */
	current_node = *stack;

	/* Iterate through the stack and print each node's integer value */
	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;  /* Move to the next node in the stack */
	}
}
