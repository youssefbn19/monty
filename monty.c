#include "monty.h"
unsigned int line_number = 1;
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
	FILE *fptr;
	char *buffer;
	size_t size = 0;
	stack_t *s = NULL;

	fptr = fopen(f_name, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &size, fptr) != -1)
	{
		trim(buffer);
		if (strlen(buffer) > 0)
			check_opcode(&s, buffer);
		line_number++;
	}
	free(buffer);
	fclose(fptr);
}

