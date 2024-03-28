#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

stack_t *CreateNode(int num);
void FreeNodes(void);
void AddToQueue(stack_t **, unsigned int);
void PushToStack(stack_t **, unsigned int);
void OpenFile(char *file_path);
int ParseInput(char *buffer, int line_number, int format);
void ReadsInstructions(FILE *);
void FindAndExecute(char *, char *, int, int);
void CallFunction(op_func, char *, char *, int, int);
void print_all_stack_elements(stack_t **, unsigned int);
void Prints_Top_Stack(stack_t **stack, unsigned int);
void Remove_Top_Stack(stack_t **stack, unsigned int);
void Swap_Top_Two_Stack_Elements(stack_t **stack, unsigned int);
void Add_Top_Two_Element(stack_t **stack, unsigned int line_number);
void Nop(stack_t **stack, unsigned int line_number);
void Sub_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number);
void Div_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number);
void Mul_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number);
void Mod_Top_Two_Stack_Elements(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
