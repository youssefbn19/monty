#include "monty.h"
/**
 * sub - subtracts the top element of the stack from 
 * the second top element of the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 */
void sub(stack_t **s, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (s && *s && (*s)->next)
	{
		temp = (*s);
		(*s) = (*s)->next;
		(*s)->n -= temp->n;
		free(temp);
		temp = NULL;
	}
	else
		error_handler("can't sub, stack too short", line_number);
}

/**
 * _div - divides the second top element of the stack 
 * by the top element of the stack. 
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 */
void _div(stack_t **s, unsigned int line_number)
{
	stack_t *temp = NULL;
	if (s && *s && (*s)->next)
	{
		if ((*s)->n != 0)
		{
			temp = (*s);
			(*s) = (*s)->next;
			(*s)->n /= temp->n;
			free(temp);
		}
		else
			error_handler("division by zero", line_number);	
	}
	else
		error_handler("can't div, stack too short", line_number);
}
