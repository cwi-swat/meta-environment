/**
 *	utf8.h
 *
 *	Erik Post
 *	epost@science.uva.nl
 *	Universiteit van Amsterdam
 *
 */

#ifndef __UTF8_H__
#define __UTF8_H__


/*
 *	use:  translates things like "myfunc%28%29" to "myfunc()"
 *	- will only decode sequences of the form <percent sign><hex digit><hex digit>
 */
void utf8_to_ascii( char* dest, char* src );


#endif		/* __UTF8_H__ */
