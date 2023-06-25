#ifndef MONTY_TASK
#define MONTY_TASK
#define UNUSED_ARG(arg) (void)(arg)
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * struct file_handler - file pointer and its current line pointing to
 * @fptr: file pointer
 * @line: file current line value
 */
typedef struct file_handler
{
	FILE *fptr;
	char *line;
} file_h;
extern file_h file;

void read_lines(char *lines);
void trim(char *buffer);
void check_opcode(stack_t **s, unsigned int line_number);
instruction_t get_opcode(char *op);
void error_handler(char *str, unsigned int l);
void free_stack(stack_t **s);
void push(stack_t **s, unsigned int line_number, int value);
void pall(stack_t **s, unsigned int line_number);
void pint(stack_t **s, unsigned int line_number);
void pop(stack_t **s, unsigned int line_number);
void swap(stack_t **s, unsigned int line_number);
void add(stack_t **s, unsigned int line_number);
void sub(stack_t **s, unsigned int line_number);
void _div(stack_t **s, unsigned int line_number);
void mul(stack_t **s, unsigned int line_number);
void mod(stack_t **s, unsigned int line_number);
void pchar(stack_t **s, unsigned int line_number);
void pstr(stack_t **s, unsigned int line_number);
#endif
