/* stack.c - Implementation for an array-based stack of integers
 *
 * Kurt Schmidt
 * 3/2018
 *
 * gcc 5.4.0 20160609 on
 * Linux 4.13.0-32-generic
 *
 * EDITOR:  tabstop=2 cols=120
 */

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

enum { INIT_SIZE=2, GROWTH_FACTOR=2 } ;


Bool grow( stack_t* S )
{
	int ns = GROWTH_FACTOR * S->cap ;
	int *t = realloc( S->a, ns*sizeof(int) ) ;
	if( t == NULL )
		return False ;
	S->cap = ns ;
	return True ;
}


stack_t* stack_init()
{
	stack_t *rv = malloc( sizeof( stack_t )) ;
	if( rv == NULL )
		return NULL ;
	rv->a = malloc( sizeof(int)*INIT_SIZE ) ;
	if( rv->a == NULL )
		return NULL ;
	rv->size = 0 ;
	rv->cap = INIT_SIZE ;

	return rv ;
}


Bool is_empty( stack_t *S ) 
{
	return S->size == 0 ;
}


Bool push( stack_t* S, int x )
{
	if( S->size >= S->cap )
		if( ! grow( S ))
			return False ;
	
	S->a[S->size] = x ;
	S->size += 1 ;

	return True ;
}


int pop( stack_t* S ) 
{
	S->size -= 1 ;
	return S->a[S->size] ;
}


void kill( stack_t* S )
{
	free( S->a ) ;
	free( S ) ;
}

