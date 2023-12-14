#include "monty.h"

/**
 * PushToStack - Pushes a new node to the top of the stack.
 * @new_node: Pointer to the new node to be pushed.
 * @line_number: The line number of the current opcode.
 * Description: Pushes a new node to the top of the stack.
 */
void PushToStack(stack_t **new_node,
__attribute__((unused))unsigned int line_number)
{
	stack_t *current_top_node;

	/*Validate the new node*/
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	/*If the stack is empty, set the new node as the head of the stack*/
	if (head == NULL)
	{
		head = *new_node; /*Set the new node as the head of the stack*/
		return;
	}

	/*Otherwise, insert the new node at the beginning of the stack*/
	current_top_node = head; /*Save the current top node*/
	head = *new_node; /*Set the new node as the new top node*/
	/*Set the next pointer of the new node to the previous top node*/
	head->next = current_top_node;
	/*Set the previous pointer of the previous top node to the new node*/
	current_top_node->prev = head;
}
