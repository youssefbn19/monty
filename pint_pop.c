#include "monty.h"
/**
 * pint -  prints the value at the top of the stack, followed by a new line.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode.
 */
void pint(stack_t **s, unsigned int line_number)
{
	if (s && *s)
		printf("%d\n", (*s)->n);
	else
		error_handler("can't pint, stack empty", line_number);
}
/**
 * pop - removes the top element of the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode.
 */
void pop(stack_t **s, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (s && *s)
	{
		temp = *s;
		(*s) = (*s)->next;
		free(temp);
		temp = NULL;
	}
	else
		error_handler("can't pop an empty stack", line_number);
}
