/* stack.h - Interface for an array-based stack of integers
 *
 * Kurt Schmidt
 * 3/2018
 *
 * gcc 5.4.0 20160609 on
 * Linux 4.13.0-32-generic
 *
 * EDITOR:  tabstop=2 cols=120
 */

#ifndef __KS_STACK_
#define __KS_STACK_

#include <stdio.h>

typedef enum { False, True } Bool ;

typedef struct
{
	int *a ;   /* array, actual data */
	int size ; /* number of elements in the stack */
	int cap ;  /* capacity of underlying array */
} stack_t ;

	/* Returns ptr to new (empty) stack data */
stack_t* stack_init() ;

	/* Returns True if stack S is empty */
Bool is_empty( stack_t *S ) ;

	/* Pushes x onto stack S */
Bool push( stack_t* S, int x ) ;

	/* Returns element at top of stack S
	 * Behavior undefined if stack is empty. */
int pop( stack_t* S ) ;

	/* Should be called when done w/stack */
void kill( stack_t* S ) ;

#endif /* __KS_STACK_ */

