#include "monty.h"

/**
 * nop - do nothing
 * @stack: header
 * @line_number: bytecode input
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
		return;
}
