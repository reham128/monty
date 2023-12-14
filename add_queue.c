#include "monty.h"
/**
 * addToQueue - function to add nod to the Que
 * @qNode: is the pointer to added node
 * @lineNum: is the line num
 * Return: void function
*/
void addToQueue(stack_t **qNode, __attribute__((unused))unsigned int lineNum)
{
	stack_t *ptr;

	if (*qNode == NULL || qNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *qNode;
		return;
	}
	ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *qNode;
	(*qNode)->prev = ptr;
}
