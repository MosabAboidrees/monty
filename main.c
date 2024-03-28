#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	/* Check if the correct number of arguments is provided*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*Open the Monty bytecode file and process it*/
	OpenFile(argv[1]);
	/* Free all nodes in the stack before exiting*/
	FreeNodes();
	return (0);
}

/**
 * CreateNode - Creates a new node for the stack.
 * @num: The integer value to store in the new node.
 * Return: Pointer to the newly created node, or NULL if malloc fails.
 */
stack_t *CreateNode(int num)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	/*Initialize the new node*/
	new_node->next = NULL; /*Set the next pointer to NULL*/
	new_node->prev = NULL; /*Set the previous pointer to NULL*/
	new_node->n = num; /*Set the value of the new node*/
	return (new_node);
}

/**
 * FreeNodes - Frees all nodes in the stack.
 */
void FreeNodes(void)
{
	stack_t *temp_node;
	/*Check if the stack is empty*/
	if (head == NULL)
		return;
	/*Loop through the stack and free each node*/
	while (head != NULL)
	{
		temp_node = head;
		head = head->next;
		free(temp_node);
	}
}
/**
 * Add_Top_Two_Element - Adds a new node to the top of the stack.
 * @new_node: Pointer to the new node to add.
 * @line_number: The line number of the opcode being processed.
 */
void Add_Top_Two_Element(stack_t **new_node, __attribute__((unused))
		unsigned int line_number)
{
	stack_t *temp_node;
	/*Validate the new node*/
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	/*Check if the queue (stack) is empty*/
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	/*Find the last node in the queue*/
	temp_node = head;
	while (temp_node->next != NULL)
		temp_node = temp_node->next;
	/*Add the new node to the end of the queue*/
	temp_node->next = *new_node;
	(*new_node)->prev = temp_node;
}
