/** 
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


typedef struct
{
	char utf8[3];
	char ascii[2];
} transl_tbl_t;


transl_tbl_t utf8_to_ascii_tbl[] =
{
	{"22", "\""},
	{"28", "("},
	{"29", ")"},
	{"2D", "-"}
};
#define UTF8_TBL_SIZE 3
#define UTF8_START_CHAR '%'
#define UTF8_WIDTH 3




/*
 *	This function could be easily generalized to perform other translation
 *	tasks with a bit of twiddling, since most all of it uses macros instead
 *	of hardcoded constants, so a search and replace would get us a long way.
 */
void utf8_to_ascii_backend( char* dest, char* src, transl_tbl_t tt[] )
{
	char aux[3];
	char aux_ascii;
	int i_src = 0;
	int i_dest = 0;
	int i_utf8;
	int is_match;
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
			/*
			 *	search through table of UTF-8 chars
			 */
			is_match = 0;
			for( i_utf8=0; 
				(i_utf8<UTF8_TBL_SIZE) && (!is_match); 
				i_utf8++ )
			{	
				#ifdef DEBUG
					printf( "\tcomparing to %s\n", tt[i_utf8].utf8 );
					printf( "\tis_match: %d\n", is_match );
				#endif
				if( strncmp( &src[i_src], tt[i_utf8].utf8, (UTF8_WIDTH-1))==0 )
				{
					aux_ascii = *(tt[i_utf8].ascii);
					dest[i_dest] = aux_ascii;
					i_dest++;				
					#ifdef DEBUG
						printf( "\tmatch: %c\n", aux_ascii );
					#endif
					is_match = 1;
				}
			}
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



void utf8_to_ascii( char* dest, char* src )
{
	utf8_to_ascii_backend( dest, src, utf8_to_ascii_tbl );
}


/*
int main( int argc, char* argv[] )
{
	char* s = "Er %28 staat %9 een paard in de gang";
	char t[100];
	
	utf8_to_ascii( t, s, utf8_to_ascii_tbl ); 
	printf( "src: %s\ndest: %s\n", s,t  );
		
	return 0;
}
*/

