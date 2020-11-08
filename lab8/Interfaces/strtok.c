/************************************************************
 *
 * strtok.c - exploring behavior of strtok
 *
 * May 2018
 *
 * gcc (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609 on
 * Linux 4.4.0-104-generic #127-Ubuntu SMP Mon Dec 11 12:16:42 UTC 2017 x86_64 GNU/Linux
 *
 ************************************************************/

#include <string.h>
#include <stdio.h>

int main( void )
{
	char input[] = "aXbcYXXXdYe" ;
	int len = strlen( input ) ;
	int i ;

	char *p = strtok( input, "XY" ) ;
	while( p != NULL )
	{
		for( i=0; i<len; ++i )
			printf( "%02d %c\n", i, input[i] ) ;
		printf( "---------------\n" ) ;
		p = strtok( NULL, "XY" ) ;
	}

	return( 0 ) ;
}
