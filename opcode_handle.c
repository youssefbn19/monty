#include "monty.h"
/**
 * check_opcode - check opcode in a given line
 *
 * @s: pointer to pointer to a stack_t linked list head.
 * @line_number: opcode line number
 *
 * Description: check_opcode check the given line if it has a valid opcode
 * if so the opcode will executed otherwise an error will be shown
 * if the opcode is not valid
 */
void check_opcode(stack_t **s, unsigned int line_number)
{
	char *opcode = NULL, *arg = NULL;
	int push_val = 0;
	instruction_t inst;

	opcode = strtok(file.line, " \t");
	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t");

		if (arg == NULL || (strcmp(arg, "0") != 0 && atoi(arg) == 0))
		{
			free_stack(s);
			error_handler("usage: push integer", line_number);
		}
		push_val = atoi(arg);
		push(s, line_number, push_val);
	}
	else
	{
		if (strcmp(opcode, "nop") != 0)
		{
			inst = get_opcode(opcode);
			if (inst.f == NULL && inst.opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free_stack(s);
				free(file.line);
				fclose(file.fptr);
				exit(EXIT_FAILURE);
			}
			else if (inst.opcode != NULL)
			{
				inst.f(s, line_number);
			}
		}
	}
}

/**
 * get_opcode - gives an instruction_t struct of a given opcode
 *
 * @op: opcode that will be using for searching for its instruction_t
 *
 * Return: return intruction_t struct, NULL if it fails
 */
instruction_t get_opcode(char *op)
{
	instruction_t opcode_list[] = {{"pall", pall}, {"pint", pint},
					{"pop", pop}, {"swap", swap},
					{"add", add}, {"nop", NULL},
					{NULL, NULL}};
	int i = 0;

	while (opcode_list[i].opcode)
	{
		if (strcmp(opcode_list[i].opcode, op) == 0)
			break;
		i++;
	}
	return (opcode_list[i]);
}

/**
 * error_handler - print an error message to the standard error
 *
 * @str: error message.
 * @l: line number that has the error.
 */
void error_handler(char *str, unsigned int l)
{
	fprintf(stderr, "L%d: %s\n", l, str);
	free(file.line);
	fclose(file.fptr);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - frees memory allocated by a istack_t nodes
 *
 * @s: pointer to pointer to a stack_t linked list head.
 */
void free_stack(stack_t **s)
{
	stack_t *temp = NULL;

	if (s && *s)
	{
		temp = (*s);
		while (temp)
		{
			(*s) = (*s)->next;
			free(temp);
			temp = (*s);
		}
		temp = (*s) = NULL;
	}
}
