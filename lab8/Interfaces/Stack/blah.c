
int* data ;
int cap ;
int size ;

bool isEmpty()
{
	return( size==0 ) ;
}

	/* don't pop an empty stack */
int pop()
{
	size -= 1 ;
	return( data[size] ) ;
}
