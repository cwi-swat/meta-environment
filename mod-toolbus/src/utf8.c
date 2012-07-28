/*
 *	utf8.c
 *
 *	Erik Post
 *	epost@science.uva.nl
 *	Universiteit van Amsterdam
 *
 */
 
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utf8.h"


#define UTF8_START_CHAR '%'
#define UTF8_WIDTH 3


/*
 *	returns integer value of hexdigit, or -1 if hexdigit was not a valid
 *	hex digit
 */
int hexdigit2int( char hexdigit )
{
	char d;
	 
	d = tolower(hexdigit);
	if( !isxdigit(d) ) 
	{
		return -1;
	}
	else if( isdigit(hexdigit) )
	{
		return (int) hexdigit - (int) '0';
	}
	else	/* d must be a character [a-f] */
	{
		return 10 + (int) hexdigit - (int) 'a';
	}
}


/*
 *	pre		s contains at least num_chars hex digits
 *	post	the integer value of the hexadecimal number with num_chars
 *			digits is returned
 */
int hex2int( char* s, int num_chars )
{
	int i;
	char c;
	int digit_weight;
	int rv;
	
	rv = 0;
	digit_weight = 1;
	for( i=0; i<num_chars; i++ )
	{
		c = s[num_chars-i-1];
		rv += hexdigit2int(c) * digit_weight;
		digit_weight *= 16;
	}
	return rv;
}


void utf8_to_ascii( char* dest, char* src )
{
	int i_src = 0;
	int i_dest = 0;
	int len_src;
	
	/*
	 *	Go through source string.
	 *	Iterate up to strlen(src)-2 because an UTF-8 char is at least 3 
	 *	chars wide so it cannot occur within 2 chars before the end of 
	 *	the string.
	 */
	len_src = strlen(src);
	
	for( i_src=0; i_src <= len_src; i_src++ )
	{
		#ifdef DEBUG
			printf( "src char: %c\n", src[i_src] );
		#endif
		/*
		 *	If we encounter a UTF8_START_CHAR, decode the UTF-8 char sequence
		 *	(code sequence can't occur within UTF*_WIDTH chars before the 
		 *	end of the string)
		 */ 
		if( (src[i_src] == UTF8_START_CHAR) 
			&& isxdigit(src[i_src+1]) && isxdigit(src[i_src+2])
			&& (i_src < len_src-(UTF8_WIDTH-1)))
		{
			i_src++;				/* skip UTF8_START_CHAR character */
			dest[i_dest] = (char) hex2int(&src[i_src], UTF8_WIDTH-1 );
			i_dest++;				
			i_src+=(UTF8_WIDTH-2);	/* last hex digit of UTF-8 sequence */
		}
		else /* we're not scanning an UTF8-char right now */
		{
			/* simply copy next char */
			dest[i_dest] = src[i_src];
			i_dest++;
		}
	}	
}


#if 0

/* 
 *	example and test
 */
int main( int argc, char* argv[] )
{
	char* s = "Er %28 staat %9 een paard in de gang";
	char t[100];
	utf8_to_ascii( t, s );
	printf( "string: %s\ndecoded: %s\n", s, t );	
	/* printf( "3f =  %d\n", hex2int("3f") ); */
	return 0;
}
#endif
