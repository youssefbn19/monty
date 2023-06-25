#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 */
void pchar(stack_t **s, unsigned int line_number)
{
	int chr;

	if (s && *s)
	{
		chr = (*s)->n;
		if (chr >= 0 && chr <= 127)
			printf("%c\n", chr);
		else
			error_handler("can't pchar, value out of range", line_number);
	}
	else
		error_handler("can't pchar, stack empty", line_number);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 */
void pstr(stack_t **s, unsigned int line_number)
{
	stack_t *temp = NULL;

	UNUSED_ARG(line_number);
	if (s && *s)
	{
		temp = (*s);
		while (temp)
		{
			if (temp->n <= 0 || temp->n > 127)
				break;
			printf("%c", temp->n);
			temp = temp->next;
		}
	}
	printf("\n");
}
