/**
 *	aterm-html.c
 *
 *	Erik Post
 *	epost@science.uva.nl
 *	Universiteit van Amsterdam
 *	
 *	needs libraries: ATB(?) and ATERM
 *
 */

#include <aterm2.h>
#include <atb-tool.h>
 
/*
 *	converts 
 *	html(
 *		head([... , ...])
 *		,
 *		body(
 *			p( [word(), word() ] )
 *			)
 *		)
 *
 *	TODO: 
 *		- split function up into subfunctions; that way, we can
 *			also insert things like links back to a mod_toolbus UI-form
 *			or whatever
 *		- we might do some extra not-NULL checking on ATerm-API returnvalues
 *		- add list capability to certain tag levels, like <html> and <head>
 *		- this thing does not ACTUALLY check buffer overflow yet, but that is 
 *			easy (but tediously) added
 *  
 */
void ATparseHTML( ATerm input, char* html_output, int max_output_size )
{
	char* htmlbufptr = html_output;
	ATerm t;
	ATerm head;
	ATerm body;
	ATerm paraList;
	ATerm para; 
	ATerm word;
	ATerm temp;
	int i_para;
	int i_para_max;
	int i_word;
	int i_word_max;

	if( ATmatch(input, "html(<term>)", &t ) )
	{
		/* write <html> */
		strcat( htmlbufptr, "<html>\n" );												
		if( ATmatch( t, "[<term>,<term>]", &head, &body ) )
		{
			/*
			 *	we're just ignoring <head> ... </head> for now
			 */
			strcat( htmlbufptr, "<head></head>\n" );																										
			
			/*
			 *	decode body
			 */
			strcat( htmlbufptr, "\n</body>\n" );															
			if( ATmatch( body, "body(<term>)", &paraList ) )
			{				
				/*
				 *	match current paragraph in body
				 */				
				i_para_max = ATgetLength(paraList);				
				for( i_para=0; i_para<i_para_max; i_para++ )
				{
					strcat( htmlbufptr, "\t<p>" );										
					temp = (ATerm) ATgetSlice( (ATermList) paraList, 
						i_para, i_para+1 );
					/*
					 *	match words in current paragraph
					 */
					if( temp != NULL )
					{
						ATmatch( temp, "[p(<term>)]", &para );
						i_word_max = ATgetLength( para );
						for( i_word=0; i_word<i_word_max; i_word++ )
						{
							word = (ATerm) ATgetSlice( (ATermList) para, 
								i_word, i_word+1 );
							if( word != NULL )
							{
								ATmatch( word, "[<term>]", &word );
								/*** implement br() <br> tag ***/
								strcat( htmlbufptr, ATwriteToString( word ) );
								/* add a space, but not at end of paragraph */
								if( i_word != i_word_max-1 )
								{	
									strcat( htmlbufptr, " " );
								}
							}
						}
					}
					strcat( htmlbufptr, "</p>\n" );										
				}
			}
			strcat( htmlbufptr, "</body>\n\n" );												
		}	
		strcat( htmlbufptr, "</html>\n" );														
	}
}



/*
int main( int argc, char* argv[] )
{
	ATerm bottomOfStack;
	char mybuf[5000];
	
	ATinit( argc, argv, &bottomOfStack );
	ATparseHTML( ATmake("html([head(),body([p([Erik,Is,Lief]),p([hi,ho])])])"),
		mybuf, 5000 );
	fprintf( stderr, "%s\n", mybuf );
	return 0;
}
*/

