#include "monty.h"
file_h file = {NULL, NULL};
/**
 * main - entry point
 *
 * @argc: number of arguments will be entered on command line program
 * @argv: array of pointers to the command line arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	if (argc > 2 || argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_lines(argv[1]);
	return (0);
}

/**
 * trim - removes trailing and preceding spaces from a given string
 *
 * @s: string that we want to remove the spaces from
 */
void trim(char *s)
{
	int i, j;

	for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++)
	;

	for (j = 0; s[i]; i++)
	{
		s[j++] = s[i];
	}
	s[j] = '\0';

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			j = i;
	}
	s[j + 1] = '\0';
}

/**
 * read_lines - reads lines whithin a given file path
 *
 * @f_name: file path name
 */
void read_lines(char *f_name)
{
	unsigned int line_number = 1;
	size_t size = 0;
	stack_t *s = NULL;

	file.line = NULL;
	file.fptr = fopen(f_name, "r");
	if (file.fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&file.line, &size, file.fptr) != -1)
	{
		trim(file.line);
		if (strlen(file.line) > 0)
			check_opcode(&s, line_number);
		line_number++;
	}
	free(file.line);
	free_stack(&s);
	fclose(file.fptr);
}

