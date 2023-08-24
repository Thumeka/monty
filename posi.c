#include "monty.h"

/**
 * _add - adds the elements
 * @head: header
 * @line_number: input
 */

void _add(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * _swap - swaps the elements
 * @head: header
 * @line_number: input
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;

	if (temp->next != NULL)
	{
		(*head)->next = temp->next;
		(*head)->next->prev = *head;
	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *head;
	(*head) = temp;
}
