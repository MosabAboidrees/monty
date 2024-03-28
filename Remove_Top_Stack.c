#include "monty.h"

/**
 * Remove_Top_Stack - removes the top element of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number in the script where the opcode appears.
 */
void Remove_Top_Stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack; /*Store the address of the top node*/
	*stack = (*stack)->next; /*Make the next node as the top node*/
	if (*stack != NULL) /*If the stack is not empty*/
		(*stack)->prev = NULL;
	free(temp); /*Free the old top node*/
}
