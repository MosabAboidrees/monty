#include "monty.h"

/**
 * Swap_Top_Two_Stack_Elements - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number currently being processed.
 * Description: The top two elements of the stack are swapped.
 */
void Swap_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*Store the value of the first node*/
	temp = (*stack)->n;
	/*Set the value of the first node to the value of the second node*/
	(*stack)->n = (*stack)->next->n;
	/*Set the value of the second node to the value of the first node*/
	(*stack)->next->n = temp;
}
