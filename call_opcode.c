#include "monty.h"

/**
 * call_opc - calls the functions
 * @opc: bytecodes input
 *
 * Return: pointer
 */

void (*call_opc(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t opc_d[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", nop},
		{"div", m_div},
		{"sub", sub},
		{NULL, NULL}
	};
	int j = 0;

	while (opc_d[j].f != NULL)
	{
		if (strcmp(opc, opc_d[j].opcode) == 0)
			return (opc_d[j].f);
		j++;
	}
	return (NULL);
}
