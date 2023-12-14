#include "monty.h"
/**
 * pint - function to print top
 * @stack: pointer 
 * @lineNum: is the line number
 * Return: void function
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",lineNum);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * no_thing - for nop operation
 * @stack: pointer
 * @lineNum: is the line number
 * Return: void function
 */
void no_thing(stack_t **stack, unsigned int lineNum)
{
	(void) lineNum;
	(void) stack;
}
/**
 * swap_nums - to swap tow top element
 * @stack: pointer
 * @lineNum: is the line number
 * Return: void function
 */
void swap_nums(stack_t **stack, unsigned int lineNum)
{
	stack_t *ptr;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	if (ptr->next != NULL)
	{
		ptr->next->prev = *stack;
	}
	ptr->next =*stack;
	(*stack)->prev = ptr;
	ptr->prev = NULL;
	*stack = ptr;
}
/**
 * add_nums - function to added two top elements os stack
 * @stack: pointer
 * @lineNum: is the line number
 * Return: void function
 */
void add_nums(stack_t **stack, unsigned int lineNum)
{
	unsigned int result;

	if ((*stack)->next == NULL || *stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
