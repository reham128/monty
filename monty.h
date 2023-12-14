#ifndef MONTY_PR_H
#define MONTY_PR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *head;
stack_t *newNode(int data);
int main(int argc, char *argv[]);
int tokanize(char *b, int lineNum, int type);
void select(char *opcode, char *data, int lineNum, int type);
void haveCode(op_func func, char *opcode, char *data, int lineNum, int type);
void fileHandel(char *fileNam);
void pushStak(stack_t **nNode, __attribute__((unused))unsigned int lineNum);
void popStak(stack_t **stack, unsigned int lineNum);
void displayAll(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum);
void no_thing(stack_t **stack, unsigned int lineNum);
void swap_nums(stack_t **stack, unsigned int lineNum);
void add_nums(stack_t **stack, unsigned int lineNum);
typedef void (*op_func)(stack_t **, unsigned int);
void addToQueue(stack_t **qNode, __attribute__((unused))unsigned int lineNum);
#endif
