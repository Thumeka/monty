#include "monty.h"

/**
 * _push - adds nodes at the start
 * @head: pointer
 * @line_number: bytcode input
 * @n: number integer
 */

void _push(stack_t **head, unsigned int line_number, const char *n)
{
	if (!head)
		return;
	if (is_integer(n) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_link(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_dnodeint_end(head, atoi(n)) == -1)
		{
			free_link(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * is_integer - character of string
 * @n: integer
 * Return: 0
 *
 */
int is_integer(const char *n)
{
	int j = 0;

	if (*n == '-')
		j = 1;
	for (; *(n + j) != '\0'; j++)
	{
		if (isdigit(*(n + j)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * _pall - print all nodes
 * @head: header
 * @line_number: bytecode input
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
