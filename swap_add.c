#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @ln: number line of the opcode
 */
void swap(stack_t **s, unsigned int ln)
{
	stack_t *temp = NULL;

	if (s && *s && (*s)->next)
	{
		temp = (*s)->next;
		temp->prev = NULL;
		(*s)->prev = temp;
		(*s)->next = temp->next;
		temp->next = *s;
		*s = temp;
	}
	else
		error_handler("can't swap, stack too short", ln);
}
/**
 * add - adds the top two elements of the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @ln: number line of the opcode
 */
void add(stack_t **s, unsigned int ln)
{
	stack_t *temp = NULL;

	if (s && *s && (*s)->next)
	{
		temp = (*s);
		(*s) = (*s)->next;
		(*s)->n += temp->n;
		free(temp);
		temp = NULL;
	}
	else
		error_handler("can't add, stack too short", ln);
}
