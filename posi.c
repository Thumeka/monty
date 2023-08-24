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
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
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

/**
 * sub - minus the elements
 * @stack: lists on top
 * @line_number: byte input
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div - divide the elements
 * @stack: stacks
 * @line_number: the input
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zer\n", line_number);
	}
	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
	
