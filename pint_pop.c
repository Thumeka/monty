#include "monty.h"

/**
 * _pint - print the top element
 * @head: header
 * @line_number: byte input
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - remove elements
 * @head: header
 * @line_number: byte input
 */
void _pop(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_link(head);
		exit(EXIT_FAILURE);
	}
	else
		delete_dnodeint_at_end(head);
}
