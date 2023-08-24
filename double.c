#include "monty.h"

/**
 * free_link - free nodes
 * @head : header
 */

void free_link(stack_t **head)
{
	if (!head)
		return;
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}

/**
 * delete_dnodeint_at_end - delete at the end only
 * @head: pointer
 */

void delete_dnodeint_at_end(stack_t **head)
{
	stack_t *remove = NULL;

	remove = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(remove);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(remove);
	}
}

/**
* add_dnodeint_end - new node at the start
* @head: header
* @n: node
*
* Return: element or NULL
*/
int add_dnodeint_end(stack_t **head, int n)
{
	stack_t *n_node;

	if (!head)
		return (-1);

	n_node = malloc(sizeof(struct stack_s));

	if (!n_node)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	n_node->n = n;

	if (*head == NULL)
	{
		*head = n_node;
		n_node->next =  NULL;
		n_node->prev = NULL;
	}
	else
	{
		n_node->next = *head;
		(*head)->prev = n_node;
		*head = n_node;
	}
	return (0);
}
