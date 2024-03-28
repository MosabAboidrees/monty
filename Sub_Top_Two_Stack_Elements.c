#include "monty.h"

/**
 * Sub_Top_Two_Stack_Elements - Subtracts the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number currently being processed.
 * Description: The top two elements of the stack are subtracted.
 */
void Sub_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n; /*Subtract the top two elements*/
	temp = *stack; /*Store the address of the first node*/
	*stack = (*stack)->next; /*Set the head to the second node*/
	(*stack)->prev = NULL; /*Set the prev of the new head to NULL*/
	free(temp);
}
