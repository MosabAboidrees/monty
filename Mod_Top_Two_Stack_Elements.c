#include "monty.h"

/**
 * Mod_Top_Two_Stack_Elements - Modulo the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number currently being processed.
 * Description: The top two elements of the stack are modulo.
 */
void Mod_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/*Check if the stack has less than two elements*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0) /*Check if the divisor is zero*/
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n; /*Modulo the top two elements*/
	temp = *stack; /*Store the address of the first node*/
	*stack = (*stack)->next; /*Set the head to the second node*/
	(*stack)->prev = NULL; /*Set the prev of the new head to NULL*/
	free(temp);
}
