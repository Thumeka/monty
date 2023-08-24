#include "monty.h"

/**
 * main - run the the program
 * @argc: count
 * @argv: vector
 *
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	int psh, file_d = 0;
	ssize_t read_n;
	char *buff, *tok;
	stack_t *head = NULL;
	unsigned int line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_d = open(argv[1], O_RDONLY);

	if (file_d == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
		return (0);
	read_n = read(file_d, buff, 10000);
	if (read_n == -1)
	{
		free(buff);
		close(file_d);
		fprintf(stderr, "Read error\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(buff, "\n\t\a\r ;:");
	while (tok != NULL)
	{
		if (tok[0] == '#')
		{
			tok = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}

		if (psh == 1)
		{
			_push(&head, line, tok);
			psh = 0;
			tok = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(tok, "push") == 0)
		{
			psh = 1;
			tok = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (call_opc(tok) != 0)
			{
				call_opc(tok)(&head, line);
			}
			else
			{
				free_link(&head);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, tok);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		tok = strtok(NULL, "\n\t\a\r ;:");
	}
	free_link(&head);
	free(buff);
	close(file_d);
	return (0);
}
