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
/**
 * m_mod - mod element
 * @stack: elements
 * @line_number: byte codes
 * Return: void
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	temp = ((*stack)->next->n) % ((*stack)->n);
	_pop(stack, line_number);
	(*stack)->n = temp;
}
/**
 * _rotl - to rotate elements
 * @stack: elements
 * @line_number: byte codes
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *stk;
	stack_t *under;

	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
	{
		under = stk = *stack;

		while (under->next)
			under = under->next;
		under->next = stk;
		stk->prev = under;
		*stack = stk->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
/**
 * _rotr - rotate only bottom
 * @stack: element
 * @line_number: node
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *stk;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		stk = *stack;
		while (stk->next != NULL)
			stk = stk->next;
		(*stack)->prev = stk;
		stk->next = *stack;
		stk->prev->next = NULL;
		stk->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
