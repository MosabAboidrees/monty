#include "monty.h"
/**
 * OpenFile - Opens a file for reading.
 * @file_path: Path to the file to be opened.
 * Description: Opens a file and triggers reading the file.
 * If the file cannot be opened, an error is raised.
 */
void OpenFile(char *file_path)
{
	FILE *file_descriptor = fopen(file_path, "r");
		/*Check if the file path is null or file could not be opened*/
		if (file_path == NULL || file_descriptor == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", file_path);
			FreeNodes();
			exit(EXIT_FAILURE);
		}
	/*Read the file*/
	ReadsInstructions(file_descriptor);
	/*Close the file after reading*/
	fclose(file_descriptor);
}
/**
 * ReadsInstructions - Reads instructions from a file.
 * @filed: File descriptor for the opened file.
 * Description: Reads each line from the file and processes it.
 */
void ReadsInstructions(FILE *filed)
{
	int line_number;
	int storage_format = 0; /* 0 for stack, 1 for queue*/
	char *buffer = NULL;
	size_t blen = 0;

	/*Iterate through each line in the file*/
	for (line_number = 1; getline(&buffer, &blen, filed) != -1; line_number++)
	{
		storage_format = ParseInput(buffer, line_number, storage_format);
	}
	free(buffer);
}
/**
 * ParseInput - Parses a single line of input.
 * @line_buffer: Buffer containing the line read from the file.
 * @line_number: Current line number being processed.
 * @storage_format: Current storage format (stack or queue).
 * Description: Separates each line into
 * tokens to determine the opcode and its arguments.
 * Return: Returns 0 if opcode is 'stack', 1 if 'queue',
 * otherwise returns current format.
 */
int ParseInput(char *line_buffer, int line_number, int storage_format)
{
	char *opcode;
	char *argument_value;
	const char *delimiter = "\n ";

	if (line_buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		FreeNodes();
		exit(EXIT_FAILURE);
	}
	opcode = strtok(line_buffer, delimiter);
	/*If line is empty or comment, skip processing*/
	if (opcode == NULL || opcode[0] == '#')
		return (storage_format);
	argument_value = strtok(NULL, delimiter);
	/*Check if the opcode is 'stack' or 'queue' and update the format*/
	if (strcmp(opcode, "stack") == 0)
		return (0); /*Stack format*/
	if (strcmp(opcode, "queue") == 0)
		return (1); /*Queue format*/
	FindAndExecute(opcode, argument_value, line_number, storage_format);
	return (storage_format);
}
/**
 * FindAndExecute - Finds and executes the appropriate
 * function for a given opcode.
 * @opcode: Opcode read from the file.
 * @argument_value: Argument value associated with the opcode, if any.
 * @line_number: Line number of the opcode in the file.
 * @storage_format: Current storage format (stack or queue).
 * Description: Matches the opcode to the correct function and calls it.
 */
void FindAndExecute(char *opcode, char *argument_value,
int line_number, int storage_format)
{
	int i;
	int is_opcode_found;

	/*List of supported opcodes and their corresponding functions*/
	instruction_t func_list[] = {
		{"push", PushToStack},
		{"pall", print_all_stack_elements},
		{"pint", Prints_Top_Stack},
		{"pop", Remove_Top_Stack},
		{"swap", Swap_Top_Two_Stack_Elements},
		{"add", Add_Top_Two_Element},
		{"nop", Nop},
		{"sub", Sub_Top_Two_Stack_Elements},
		{"div", Div_Top_Two_Stack_Elements},
		{"mul", Mul_Top_Two_Stack_Elements},
		{"mod", Mod_Top_Two_Stack_Elements},
		{NULL, NULL}
	};
	/*Skip processing if the line is a comment*/
	if (opcode[0] == '#')
		return;
	/*Iterate through the function list to find the matching opcode*/
	for (is_opcode_found = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			CallFunction(func_list[i].f, opcode,
argument_value, line_number, storage_format);
			is_opcode_found = 0;
			break;
		}
	}
	/*If no matching opcode is found, raise an error*/
	if (is_opcode_found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		FreeNodes();
		exit(EXIT_FAILURE);
	}
}
/**
 * CallFunction - Calls the required function based on the opcode.
 * @func: Pointer to the function to be called.
 * @opcode: Opcode string.
 * @value: Argument value for the opcode.
 * @line_number: Line number in the file.
 * @storage_format: Current storage format (stack or queue).
 * Description: Validates the arguments and calls the respective function.
 */
void CallFunction(op_func func, char *opcode, char *value,
int line_number, int storage_format)
{
	stack_t *new_node;
	int sign_flag;
	int i;

	sign_flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		/*Check for negative numbers*/
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			sign_flag = -1;
		}
		/*Validate the value for push opcode*/
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			FreeNodes();
			exit(EXIT_FAILURE);
		}
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				FreeNodes();
				exit(EXIT_FAILURE);
			}
		}
		/*Create a new node with the given value*/
		new_node = CreateNode(atoi(value) * sign_flag);
		/*Add the node to the stack or queue based on the current format*/
		if (storage_format == 0) /*Stack format*/
			func(&new_node, line_number);
		if (storage_format == 1) /*Queue format*/
			AddToQueue(&new_node, line_number);
	}
	else
		func(&head, line_number);
}
