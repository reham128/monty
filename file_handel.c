#include "monty.h"
/**
 * tokanize - function to toknize lines
 * @b: is the line to be toknize
 * @lineNum: is the number of the line
 * @type: to select to enter stack or queue
 * Return: type 0 for stack or 1 for queue
 */
int tokanize(char *b, int lineNum, int type)
{
	char *opcode, *data, *dlim = "\n ";

	if (b == NULL)
	{
		fprintf(stderr, "Error:malloc failed\n");
		return;
	}
	opcode = strtok(b, dlim);
	if (opcode == NULL)
		return (type);
	data = strtok(NULL, dlim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	select(opcode, data, lineNum, type);
	return (type);
}
/**
 * select - function to select the needed function to opcode
 * @opcode: is the desired opcode
 * @data: is the arg of o[pcode
 * @lineNum: is the number of line
 * @type: to select either stack or queue
 * Return: void function return nothing
 */
void select(char *opcode, char *data, int lineNum, int type)
{
	int i, j;

	instruction_t code_lists[] = {
	};
	if (opcode[0] == '#')
		return;
	for (j =1, i = 0; code_lists[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, code_lists[i].opcode) == 0)
		{
			haveCode(code_lists[i].f, opcode, data, lineNum, type);
			j = 0;
		}
	}
	if (j == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * haveCode - function to have the approprate code.
 * @func: is a pointer to function 
 * @opcode: is the desired opcode
 * @data: is the arg of o[pcode
 * @lineNum: is the number of line
 * @type: to select either stack or queue
 *Return: void
 * */
void haveCode(op_func func, char *opcode, char *data, int lineNum, int type)
{
	int i;
	int j = 1;
	stack_t *nNode;

	if (strcmp(opcode, "push") == 0)
	{
		if (data[0] == '-' && data != NULL)
		{
			data = data + 1;
			j = -1;
		}
		if (data == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNum);
			exit(EXIT_FAILURE);
		}
		for (i = 0; data[i] != "\0"; i++)
		{
			if (isdigit(data[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNum);
				exit(EXIT_FAILURE);
			}
		}
		nNode = newNode(atoi(data) * j);
		if (type = 0)
		{
			func(&nNode, lineNum);
		}
		if (type == 1)
		{
			add_to_queue(&nNode, lineNum);
		}
	}
	else
	{
		func(&head, lineNum);
	}
}
/**
 * fileHandel - function to handel the given file
 * @fileNam: the path to the file
 * Return: void function return nothing
 */
void fileHandel(char *fileNam)
{
	int lineNum, type = 0;
	size_t length = 0;
	char *b = NULL;
	FILE *file_des = fopen(fileNam, "r");

	if (file_des == NULL || fileNam == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileNam);
		exit(EXIT_FAILURE);
	}
	for (lineNum = 1; getline(&b, &length, file_des) != -1; lineNum++)
	{
		type = tokanize(b, lineNUM, type);
	}
	free(b);
	fclose(file_des);
}
