/*
 * asfix_utils.c
 *
 * Extra utility functions on asfix that the evaluator uses.
 * This utility module is ment only to be used in evaluator.c
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

/* the KEEP_WHITESPACE macro is supposed to be set at the commandline
 * of the compiler.
 */
#ifdef KEEP_WHITESPACE
ATbool keep_whitespace = ATtrue;
#else
ATbool keep_whitespace = ATfalse;
#endif

extern ATerm tagCurrentRule;

ATbool isEqualModuloWhitespace(ATerm asfix1, ATerm asfix2)
{
	/*	ATwarning("COMPARING IN %t:\n%t\nWITH\n%t\n",asource(tagCurrentRule),
			asource(asfix1),asource(asfix2));
	 */

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
				ATwarning("ABORT IN %t: %t AND %t\n",asource(tagCurrentRule),
									asource(asfix1),asource(asfix2));
				ATabort("Normal term compared with whitespace.\n");
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
		ATerror("MRF in text");
	}
	AFsource(asfix,temp);

	term = ATmake("<str>",temp);
	free(temp);

	return term;
}

ATermList skipWhitespace(ATermList list)
{
	ATerm elem;

	/* assert(asfix_is_whitespace(ATgetFirst(list)) || 
		 asfix_is_list_sep(ATgetFirst(list))); */

	if(!ATisEmpty(list)) {
		for(elem = ATgetFirst(list); !ATisEmpty(list) && 
					(asfix_is_whitespace(elem) || asfix_is_list_sep(elem));
				list = ATgetNext(list), elem = ATgetFirst(list));
	}

	assert(ATisEmpty(list) || (!asfix_is_whitespace(ATgetFirst(list)) && 
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

	assert(ATisEmpty(list) || asfix_is_whitespace(ATgetFirst(prev)) || asfix_is_list_sep(ATgetFirst(prev)));
	return prev;
}
