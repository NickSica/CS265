/*
 * csv.c - Implementation for a csv library
 *
 * Modified from code in Kernighan & Pike, _The Practice of Programming_
 *   Copyright (C) 1999 Lucent Technologies 
 *   Excerpted from 'The Practice of Programming' 
 *   by Brian W. Kernighan and Rob Pike 
 *
 * Kurt Schmidt
 * 3/2018
 *
 * gcc 5.4.0 20160609 on
 * Linux 4.13.0-32-generic
 *
 * EDITOR:  tabstop=2 cols=120
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "csv.h"


static char fieldsep[] = "," ; /* field separator chars */

	/***** Prototypes for local helper functions ******/
static char *advquoted( char* ) ;
static int split( csv_t* ) ;

	/* endofline: check for and consume \r, \n, \r\n, or EOF */
static int endofline( csv_t* c, int ch )
{
	int eol ;

	eol = ( ch=='\r' || ch=='\n' ) ;
	if( ch=='\r' ) {
		ch = getc( c->fin ) ;
		if( ch!='\n' && ch != EOF )
			ungetc( ch, c->fin ) ;	/* read too far; put c back */
	}
	return eol ;
}


	/* reset: set variables back to starting values */
static void reset( csv_t* c )
{
	free( c->line );	 /* free(NULL) permitted by ANSI C */
	free( c->sline ) ;
	free( c->field ) ;
	c->line = NULL ;
	c->sline = NULL ;
	c->field = NULL ;
	c->maxline = c->maxfield = c->nfield = 0 ;
}

	/* csvgetline:  get one line, grow as needed */
	/* sample input: "LU",86.25,"11/4/1998","2:19PM",+4.0625 */
char* csvgetline( csv_t* c )
{	
	int i, ch ;
	char *newl, *news ;

	if( c->line==NULL ) {			/* allocate on first call */
		c->maxline = c->maxfield = 1 ;
		c->line = (char*) malloc( c->maxline ) ;
		c->sline = (char*) malloc( c->maxline ) ;
		c->field = (char**) malloc( c->maxfield*sizeof( c->field[0] )) ;
		if( c->line==NULL || c->sline==NULL || c->field==NULL) {
			reset(c) ;
			return NULL ;		/* out of memory */
		}
	}

	for( i=0; (ch=getc( c->fin ))!=EOF && ! endofline(c,ch); i++ ) {
		if( i>=c->maxline-1 ) {	  /* grow line */
			c->maxline *= 2;		    /* double current size */
			newl = (char*) realloc( c->line, c->maxline ) ;
			if( newl==NULL ) {
				reset(c) ;
				return NULL ;
			}
			c->line = newl ;
			news = (char*) realloc( c->sline, c->maxline ) ;
			if( news==NULL ) {
				reset(c) ;
				return NULL ;
			}
			c->sline = news ;
		}
		c->line[i] = ch ;
	}  /* for i */

	c->line[i] = '\0' ;
	if( split(c)==NOMEM ) {
		reset(c) ;
		return NULL;			/* out of memory */
	}
	return (ch==EOF && i==0) ? NULL : c->line ;
}

/* split: split line into fields */
static int split( csv_t* c )
{
	char *p, **newf ;
	char *sepp; /* pointer to temporary separator character */
	int sepc;   /* temporary separator character */

	c->nfield = 0 ;
	if( c->line[0]=='\0' )
		return 0 ;
	strcpy( c->sline, c->line ) ;
	p = c->sline ;

	do {
		if( c->nfield>=c->maxfield ) {
			c->maxfield *= 2;			/* double current size */
			newf = (char**) realloc( c->field, 
							c->maxfield * sizeof( c->field[0] )) ;
			if( newf==NULL )
				return NOMEM ;
			c->field = newf ;
		}
		if( *p=='"' )
			sepp = advquoted( ++p ) ;	/* skip initial quote */
		else
			sepp = p + strcspn( p, fieldsep ) ;
		sepc = sepp[0] ;
		sepp[0] = '\0' ;			/* terminate field */
		c->field[c->nfield++] = p ;
		p = sepp + 1 ;
	} while( sepc==',' ) ;

	return c->nfield ;
}

/* advquoted: quoted field; return pointer to next separator */
static char *advquoted( char* p )
{
	int i, j ;

	for( i=j=0; p[j]!='\0'; ++i, ++j ) {
		if( p[j]=='"' && p[++j]!='"' ) {
				/* copy up to next separator or \0 */
			int k = strcspn( p+j, fieldsep ) ;
			memmove( p+i, p+j, k ) ;
			i += k ;
			j += k ;
			break ;
		}
		p[i] = p[j] ;
	}
	p[i] = '\0' ;
	return p + j ;
}

/* csvfield:  return pointer to n-th field */
char* csvfield( csv_t* c, int n )
{
	if( n<0 || n>=c->nfield )
		return NULL ;
	return c->field[n] ;
}

/* csvnfield:  return number of fields */ 
int csvnfield( csv_t* c )
{
	return c->nfield ;
}

csv_t* csv_init( FILE *f )
{
	csv_t *rv = (csv_t*) malloc( sizeof( csv_t )) ;
	rv->fin = f ;
	reset( rv ) ;

	return( rv ) ;
}


void kill( csv_t* s )
{
	reset( s ) ;
	free( s ) ;
}
