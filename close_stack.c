#include "monty.h"

/**
 * close_stack - Makes surs the build of the interpreter gets
 * closed/free, frees the node in the stacks and set the
 * appropiate exit status
 * @stack: front of the stack
 * @status: desired exit status
 */
void close_stack(int status)
{
	if (b.fd)
		fclose(b.fd);
	sfree(&b.buf);
	if (b.tok)
		freeStrArr(b.tok);
	free_stack(b.stack);
	exit(status);
}
