/**
 *	aterm-html.h
 *
 *	Erik Post
 *	epost@science.uva.nl
 *	Universiteit van Amsterdam
 *	
 */

#ifndef __ATERM_HTML_H__
#define __ATERM_HTML_H__


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
 *	This function could do with some extra tinkering in the way of
 *	checks; check the comments in the .c file.
 *	Just make sure you pass it correct input ATerms and an
 *	output buffer (at &html_output) that is large enough.
 */
void ATparseHTML( ATerm input, char* html_output, int max_output_size );


#endif	/* __ATERM_HTML_H__ */
