#include "monty.h"
stack_t *head = NULL;
/**
 * newNode - function to creat a new node
 * @data: data to add to the node
 * Return: pointer to the new node if success or Null if fail
 */
stack_t *newNode(int data)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = data;
	return (new_node);
}
/**
 * main - entry point to the code
 * @argc: args counter
 * @argv: args vector
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	stack_t *ptr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileHandel(argv[1]);
	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
	return (0);
}
