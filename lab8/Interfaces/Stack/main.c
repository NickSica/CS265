/* main.c - Test driver for an array-based stack of integers
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

int input[] = { 1, 2, 3, 4 } ;

int main()
{
	int i ;
	int r ;

	stack_t *s1 = stack_init() ;

	if( ! is_empty( s1 ))
		fprintf( stderr, "New stack isn't empty.\n" ) ;

	for( i=1; i<=8; ++i )
	{
		push( s1, i ) ;
		if( is_empty( s1 ))
			fprintf( stderr, "After pushing %d, stack is empty.\n", i ) ;
	}

	stack_t *s2 = stack_init() ;

	if( ! is_empty( s2 ))
		fprintf( stderr, "New stack s2 isn't empty.\n" ) ;

	for( i=21; i<=28; ++i )
	{
		push( s2, i ) ;
	}

		/* Empty s1 */
	
	for( i=8; i>=1; --i )
	{
		r = pop( s1 ) ;
		if( r != i )
			fprintf( stderr, "popping s1, expected %d, got %d\n", i, r ) ;
	}

	if( ! is_empty( s1 ))
		fprintf( stderr, "Popped all items, s1 is not empty.\n" ) ;

		/* Empty s2 */
	
	for( i=28; i>=21; --i )
	{
		r = pop( s2 ) ;
		if( r != i )
			fprintf( stderr, "popping s2, expected %d, got %d\n", i, r ) ;
	}

	if( ! is_empty( s2 ))
		fprintf( stderr, "Popped all items, s2 is not empty.\n" ) ;


	fprintf( stderr, "\nDone\n" ) ;

	return( 0 ) ;
}
