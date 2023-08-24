#include "monty.h"

/**
 * nop - do nothing
 * @head: header
 * @line_number: bytecode input
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	printf("Executing nop instruction\n");
}
