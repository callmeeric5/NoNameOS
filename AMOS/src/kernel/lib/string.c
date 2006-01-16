/*
 *     AAA    M M    OOO    SSSS
 *    A   A  M M M  O   O  S 
 *    AAAAA  M M M  O   O   SSS
 *    A   A  M   M  O   O      S
 *    A   A  M   M   OOO   SSSS 
 *
 *    Author:  Stephen Fewer
 *    Contact: steve [AT] harmonysecurity [DOT] com
 *    Web:     http://amos.harmonysecurity.com/
 *    License: GNU General Public License (GPL)
 */

// these functions are from the linux-2.0.40 kernel libc (GNU GPL).
 
#include <kernel/lib/string.h>

int strlen( char * srs )
{
	char * s;
	for( s =srs ; *s!='\0' ; ++s );
	return s-srs;
}

int strcmp( char * src, char * dest )
{
	register signed char res;

	while( TRUE )
	{
		if( (res = *src - *dest++) != 0 || !*src++ )
			break;
	}
	return res;
}

int strncmp( char * src, char * dest, int count )
{
	register signed char res = 0;

	while( count )
	{
		if( (res = *src - *dest++) != 0 || !*src++ )
			break;
		count--;
	}

	return res;
}

char * strcpy( char * dest, char * src )
{
	char *tmp = dest;

	while( (*dest++ = *src++) != '\0' );

	return tmp;
}

char * strncpy( char * dest, char * src, int count )
{
	char *tmp = dest;

	while( count && (*dest++ = *src++) != '\0' )
		count--;

	return tmp;
}

char * strstr( char *s1, char *s2 )
{
	int l1, l2;
	l2 = strlen( s2 );
	if( !l2 )
		return (char *)s1;
	l1 = strlen( s1 );
	while( l1 >= l2 )
	{
		l1--;
		if( !memcmp( s1, s2, l2 ) )
			return (char *)s1;
		s1++;
	}
	return NULL;
}

void * memset( void * dest, BYTE val, int count )
{
    register char * d = (char *)dest;
    while( count-- )
    	*d++ = val;
    return dest;
}

void memcpy( void * dest, void * src, int count )
{
	register char * d = (char *)dest;
	register char * s = (char *)src;
	while( count-- )
		*d++ = *s++;
}

int memcmp( void *cs, void *ct, int count )
{
	const unsigned char *su1, *su2;
	signed char res = 0;

	for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
		if ((res = *su1 - *su2) != 0)
			break;
	return res;
}