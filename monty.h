#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MODE 1
#define QUEUE_MODE 0


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct build - an instance of a Monty interpreter
 * @fd: file stream for file being read from
 * @buf: holds the current line being processed
 * @tok: ByteCodes read from current line
 * @stack: front of the stack
 * @mode: keeps track is linked list if being treated
 * as a stack or a queue (stack = 1, queue = 0)
 *
 * On exit fd must be closed and toks must be freed;
 */

typedef struct build
{
	FILE *fd;
	char *buf;
	char **tok;
	stack_t *stack;
	int mode;
} build_t;

extern build_t b;

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);

void validate_args(int, char**);

void (*get_inst(char *))(stack_t **, unsigned int);

/*---string manipulation----*/
int _wc(char *str, char *delims);
int strHasChar(char *str, char c);
char **_strtok(char *str, char *delims);
int isint(char *);
/*-----------------------------*/

void close_stack(int exit_val);

/*---FREEING----*/
void sfree(char **toFree);
void freeStrArr(char **array);
void free_stack(stack_t *stack);
/*---------------*/

void malloc_failed(void);

#endif
