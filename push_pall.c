#include "monty.h"
/**
 * push - pushes an element to the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 * @value: new stack_t node value
 */
void push(stack_t **s, unsigned int line_number, int value)
{
	stack_t *s_node = NULL;

	UNUSED_ARG(line_number);
	if (s == NULL)
	{
		fprintf(stderr, "Can't find stack");
		free(file.line);
		fclose(file.fptr);
		exit(EXIT_FAILURE);
	}

	s_node = malloc(sizeof(stack_t));
	if (s_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(file.line);
		fclose(file.fptr);
		exit(EXIT_FAILURE);
	}

	s_node->n = value;
	if ((*s) == NULL)
	{
		s_node->next = NULL;
		*s = s_node;
	}
	else
	{
		(*s)->prev = s_node;
		s_node->next = *s;
		(*s) = s_node;
	}
	s_node->prev = NULL;
}
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: line number of the opcode
 */
void pall(stack_t **s, unsigned int line_number)
{
	stack_t *temp = NULL;

	UNUSED_ARG(line_number);
	if (s && *s)
	{
		temp = *s;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
