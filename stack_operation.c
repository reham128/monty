#include "monty.h"
/**
 * pushStak - function to push to stack
 * @nNode: is a pointer to the added node
 * @lineNum: is the line number
 * Return: void func
 */
void pushStak(stack_t **nNode, __attribute__((unused))unsigned int lineNum)
{
	stack_t *ptr;

	if (*nNode == NULL || nNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *nNode;
		return;
	}
	ptr = head;
	head = *nNode;
	head->next = ptr;
	ptr->prev = head;
}
/**
 * popStak - function to delete from top
 * @stack: is a pointer to top
 * @lineNum: is the line number
 * Return: void function
 */
void popStak(stack_t **stack, unsigned int lineNum)
{
	stack_t *ptr;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(ptr);
}
/**
 * displayAll - function to print the stack
 * @stack: is a pointer to top
 * @lineNum: is the line number
 * Return: void function
*/
void displayAll(stack_t **stack, unsigned int lineNum)
{
	stack_t *ptr;

	(void) lineNum;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
