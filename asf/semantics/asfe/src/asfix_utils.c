/*
    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum,
                        Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
    USA

*/
/*
 * asfix_utils.c
 *
 * Extra utility functions on asfix that the evaluator uses.
 * This utility module is ment only to be used in asfe.c
 *
 *
 * $Id$
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix-access.h>
#include <AsFix2src.h>
#include <string.h>
#include <deprecated.h>
#include <assert.h>

#include "asfix_utils.h"
#include "asfe.h"

/* the KEEP_LAYOUT macro is supposed to be set at the commandline
 * of the compiler.
 */
#ifdef KEEP_LAYOUT
ATbool keep_layout = ATtrue;
#else
ATbool keep_layout = ATfalse;
#endif

extern ATerm tagCurrentRule;

ATbool isEqualModuloWhitespace(ATerm asfix1, ATerm asfix2)
{
	/* ATwarning("COMPARING\n%t\nWITH\n%t\n", asfix1,asfix2); */
	
	if(!ATisEqual(asfix1, asfix2)) {
		if(asfix_is_appl(asfix1) && asfix_is_appl(asfix2)) {
			/* If it is an appl, prods should be ATequal and kids should be
			 * equal modulo whitespace 
			 */
			ATerm prod1 = asfix_get_appl_prod(asfix1);
			ATerm prod2 = asfix_get_appl_prod(asfix2);
			
			if(ATisEqual(prod1,prod2)) {
				ATermList args1 = asfix_get_appl_args(asfix1);
				ATermList args2 = asfix_get_appl_args(asfix2);
				ATbool ok = ATtrue;

				for(;!ATisEmpty(args1) && !ATisEmpty(args2) && ok;
						args1 = ATgetNext(args1), args2 = ATgetNext(args2)) {
					ok = isEqualModuloWhitespace(ATgetFirst(args1), ATgetFirst(args2));
				}

				if(ok && ATisEqual(args1,args2)) {
					return ATtrue;
				} 
			} else {
				/* prods not equal */
				return ATfalse;
			}
		} else if(asfix_is_list(asfix1) && asfix_is_list(asfix2)) {
			/* If it is a list skip the whitespace while checking
			 * equality modulo whitespace for each element.
			 * Also, we must checks the list sort and separators!
			 */
			ATbool ok;
			ATerm sym1 = asfix_get_list_sym(asfix1);
			ATerm sym2 = asfix_get_list_sym(asfix2);
			
			if(asfix_is_iter(sym1) && asfix_is_iter(sym2)) {
				ok = (asfix_get_iter_sort(sym1) == asfix_get_iter_sort(sym2));
			} else if(asfix_is_itersep(sym1) && asfix_is_itersep(sym2)) {
				ok = (asfix_get_itersep_sort(sym1) == asfix_get_itersep_sort(sym2));
				ok = ok && (asfix_get_itersep_sep(sym1) == asfix_get_itersep_sep(sym2));
			} else {
				ok = ATfalse;
			}
			
			if(ok) {
				ATermList elems1 = (ATermList) asfix_get_list_elems(asfix1);
				ATermList elems2 = (ATermList) asfix_get_list_elems(asfix2);
				
				for(;!ATisEmpty(elems1) && !ATisEmpty(elems2) && ok; 
						elems1 = ATgetNext(elems1), elems2 = ATgetNext(elems2)) {
					ok = isEqualModuloWhitespace(ATgetFirst(elems1), ATgetFirst(elems2));
				}
				
				if(ATisEqual(elems1, elems2) && ok) { /* both ATempty */
					return ATtrue;
				}
			}
			return ATfalse;
		} else if(asfix_is_whitespace(asfix1) && asfix_is_whitespace(asfix2)) {
			/* here we treat all whitespace equally */
			return ATtrue;
		} else {
			/* different or not handled types of asfix terms are not equal by definition */
			
			if(asfix_is_whitespace(asfix1) || asfix_is_whitespace(asfix2)) {
				ATabort("Internal error. Normal term compared with whitespace in %t\n", asource(tagCurrentRule));
			}
			
			return ATfalse;
		}

		return ATfalse;
	}
	
	/* asfix1 and asfix2 are ATequal */
	return ATtrue;
}

ATerm asource(ATerm asfix)
{
	char *temp = (char*) malloc(AFsourceSize(asfix)+1);
	ATerm term; 

	if(!temp) {
		ATerror("MRF in asource");
	}
	AFsource(asfix,temp);

	term = ATmake("<str>",temp);
	free(temp);

	return term;
}

ATermList skipWhitespace(ATermList list)
{
	ATerm elem;

	if(!ATisEmpty(list)) {
		for(elem = ATgetFirst(list); !ATisEmpty(list) && 
					(asfix_is_whitespace(elem) || asfix_is_list_sep(elem));
				list = ATgetNext(list), elem = ATgetFirst(list));
	}

	assert(ATisEmpty(list) || 
				 (!asfix_is_whitespace(ATgetFirst(list)) && 
					!asfix_is_list_sep(ATgetFirst(list))));

	return list;
}

ATermList skipToEndOfWhitespace(ATermList list)
{
	ATerm elem;
	ATermList prev = list;

	assert(asfix_is_whitespace(ATgetFirst(list)) || asfix_is_list_sep(ATgetFirst(list)));

	if(!ATisEmpty(list)) {
		for(elem = ATgetFirst(list); !ATisEmpty(list) &&
					(asfix_is_whitespace(elem) || asfix_is_list_sep(elem));
				prev = list, list = ATgetNext(list), elem = ATgetFirst(list));
	}

	assert(ATisEmpty(list) || 
				 asfix_is_whitespace(ATgetFirst(prev)) || 
				 asfix_is_list_sep(ATgetFirst(prev)));
	
	return prev;
}

/* isValidList checks:
 *    - if no consecutive whitespaces nodes occur
 *    - if it doesn't begin or end with whitespace
 */
ATbool isValidList(ATermList list)
{
	ATerm elem1, elem2;
	ATermList orig = list, next;

	/* check if the first element is not whitespace */
	if(!ATisEmpty(list) && asfix_is_whitespace(ATgetFirst(list))) {
		ATwarning("Internal error. First element is whitespace in list:\n%t\n", orig);
		return ATfalse;
	}

	/* check if no consecutive whitespace occurs */
	for(;!ATisEmpty(list); list = ATgetNext(list)) {
		elem1 = ATgetFirst(list);
		next =  ATgetNext(list);
		elem2 = ATgetFirst(next);

		if(asfix_is_whitespace(elem1) && asfix_is_whitespace(elem2)) {
			ATwarning("Internal error. Consecutive whitespace in list:\n%t\n", orig);
			return ATfalse;
		}

		/* check if the last element is not whitespace */
		if(ATisEmpty(next) && asfix_is_whitespace(elem1)) {
			ATwarning("Internal error. Last element is whitespace in list:\n%t\n", orig);
			return ATfalse;
		}
	}


	return ATtrue;
}

/* isValidSlice does the same as isValidList but for a slice */
ATbool isValidSlice(ATermList begin, ATermList end)
{
	ATerm elem1, elem2;
	ATermList orig = begin, next;

	/* check if the first element is not whitespace */
	if(!ATisEmpty(begin) && asfix_is_whitespace(ATgetFirst(begin))) {
			ATwarning("Internal error. First element of slice is whitespace in:\n[");
			for(; orig != end; orig = ATgetNext(orig)) {
				ATwarning(" %t,",ATgetFirst(orig));
			}
			ATwarning("]\n");

		return ATfalse;
	}

	/* check if no consecutive whitespace occurs */
	for(;!ATisEmpty(begin) && begin != end; begin = ATgetNext(begin)) {
		elem1 = ATgetFirst(begin);
		next = ATgetNext(begin);
		elem2 = ATgetFirst(next);

		if(asfix_is_whitespace(elem1) && asfix_is_whitespace(elem2)) {
			ATwarning("Internal error. Consecutive whitespace in slice:\n[");
			for(; orig != end; orig = ATgetNext(orig)) {
				ATwarning(" %t", ATgetFirst(orig));
			}
			ATwarning("]\n");
			return ATfalse;
		}
		
		/* check if the last element is not whitespace */
		if(next == end && asfix_is_whitespace(elem1)) {
			ATwarning("Internal error. Last element is whitespace in slice:\n[");
			for(; orig != end; orig = ATgetNext(orig)) {
				ATwarning(" %t,", ATgetFirst(orig));
			}
			ATwarning("]\n");
			return ATfalse;
		}
	}

	return ATtrue;
}		
