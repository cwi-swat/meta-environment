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
#include <string.h>
#include <deprecated.h>
#include <assert.h>

#include "asfix_utils.h"
#include "asfe.h"
#include "preparation.h"

ATbool isEqualModuloWhitespace(PT_Tree asfix1, PT_Tree asfix2)
{
  asfix1 = PT_makeTreeFromTerm(
	     ATremoveAllAnnotations(PT_makeTermFromTree(asfix1)));
  asfix2 = PT_makeTreeFromTerm(
	     ATremoveAllAnnotations(PT_makeTermFromTree(asfix2)));

  if (!PT_isEqualTree(asfix1, asfix2)) {
    if (PT_isTreeAppl(asfix1) && PT_isTreeAppl(asfix2)) {
      /* If it is an appl, prods should be ATequal and kids should be
       * equal modulo whitespace 
       */
      PT_Production prod1 = PT_getTreeProd(asfix1);
      PT_Production prod2 = PT_getTreeProd(asfix2);

      if (PT_isEqualProduction(prod1, prod2)) {
	PT_Args args1 = PT_getTreeArgs(asfix1);
	PT_Args args2 = PT_getTreeArgs(asfix2);
	ATbool ok = ATtrue;

	for (; PT_hasArgsHead(args1) && PT_hasArgsHead(args2) && ok;
	     args1 = PT_getArgsTail(args1), args2 = PT_getArgsTail(args2)) {
	  ok = isEqualModuloWhitespace(PT_getArgsHead(args1), 
                                       PT_getArgsHead(args2));
	}

	if (ok && PT_isEqualArgs(args1, args2)) {
	  return ATtrue;
	}
      }
      else {
	/* prods not equal */
	return ATfalse;
      }
    }
    else if (PT_isTreeLayout(asfix1) && PT_isTreeLayout(asfix2)) {
      /* here we treat all whitespace equally */
      return ATtrue;
    }
    else {
      /* different or not handled types of asfix terms are not equal by definition */

      if (PT_isTreeLayout(asfix1) || PT_isTreeLayout(asfix2)) {
	ATabort
	  ("Internal error. Normal term compared with whitespace in %t\n",
	   asource((PT_Tree)tagCurrentRule));
      }

      return ATfalse;
    }

    return ATfalse;
  }

  /* asfix1 and asfix2 are ATequal */
  return ATtrue;
}

ATerm asource(PT_Tree asfix)
{
  char *temp = strdup(PT_yieldTree(asfix));
  ATerm term;

  if (!temp) {
    ATerror("MRF in asource");
  }

  term = ATmake("<str>", temp);
  free(temp);

  return term;
}

PT_Args skipWhitespace(PT_Args list)
{
  PT_Tree elem;

  if (PT_hasArgsHead(list)) {
    elem = PT_getArgsHead(list); 

    while (PT_isTreeLayout(elem)) {
       if (PT_hasArgsTail(list)) {
         list = PT_getArgsTail(list);
         if (PT_hasArgsHead(list)) {
           elem = PT_getArgsHead(list); 
         }
       } 
       else {
         break;
       }
    }
  }

  assert(PT_isArgsEmpty(list) || !PT_isTreeLayout(PT_getArgsHead(list)));

  return list;
}

PT_Args skipToEndOfWhitespace(PT_Args list)
{
  PT_Tree elem;
  PT_Args prev = list;

  assert(PT_isTreeLayout(PT_getArgsHead(list)));

  if (!PT_isArgsEmpty(list)) {
    for (elem = PT_getArgsHead(list); 
         PT_hasArgsHead(list) && PT_isTreeLayout(elem);
	 prev = list, list = PT_getArgsTail(list), elem = PT_getArgsHead(list));
  }

  assert(PT_isArgsEmpty(list) ||
	 PT_isTreeLayout(PT_getArgsHead(prev)));

  return prev;
}

/* isValidList checks:
 *    - if no consecutive whitespaces nodes occur
 *    - if it doesn't begin or end with whitespace
 */
ATbool isValidList(PT_Args list)
{
  PT_Tree elem1, elem2;
  PT_Args orig = list, next;

  /* check if the first element is not whitespace */
  if (PT_hasArgsHead(list) && PT_isTreeLayout(PT_getArgsHead(list))) {
    ATwarning("Internal error. First element is whitespace in list:\n%t\n",
	      (ATerm) orig);
    return ATfalse;
  }

  /* check if no consecutive whitespace occurs */
  for (; PT_hasArgsHead(list); list = PT_getArgsTail(list)) {
    elem1 = PT_getArgsHead(list);
    next = PT_getArgsTail(list);
    
    if (PT_hasArgsHead(next)) {
      elem2 = PT_getArgsHead(next);
    }
    else {
      /* check if the last element is not whitespace */
      if (PT_isTreeLayout(elem1)) {
        ATwarning
	  ("Internal error. Last element is whitespace in list:\n%t\n", 
           (ATerm) orig);
        return ATfalse;
      }
      break;
    }

    if (PT_isTreeLayout(elem1) && PT_isTreeLayout(elem2)) {
      ATwarning("Internal error. Consecutive whitespace in list:\n%t\n",
		(ATerm) orig);
      return ATfalse;
    }

  }

  return ATtrue;
}

/* isValidSlice does the same as isValidList but for a slice */
ATbool isValidSlice(PT_Args begin, PT_Args end)
{
  PT_Tree elem1, elem2;
  PT_Args orig = begin, next;

  /* check if the first element is not whitespace */
  if (PT_hasArgsHead(begin) && PT_isTreeLayout(PT_getArgsHead(begin))) {
    ATwarning("Internal error. First element of slice is whitespace in:\n[");
    for (; !PT_isEqualArgs(orig,end); orig = PT_getArgsTail(orig)) {
      ATwarning(" %t,", (ATerm) PT_getArgsHead(orig));
    }
    ATwarning("]\n");

    return ATfalse;
  }

  /* check if no consecutive whitespace occurs */
  for (; PT_hasArgsHead(begin) && !PT_isEqualArgs(begin,end); 
        begin = PT_getArgsTail(begin)) {
    elem1 = PT_getArgsHead(begin);
    next = PT_getArgsTail(begin);
    if (PT_hasArgsHead(next)) {
      elem2 = PT_getArgsHead(next);
    } 
    else {
      break;
    }

    if (PT_isTreeLayout(elem1) && PT_isTreeLayout(elem2)) {
      ATwarning("Internal error. Consecutive whitespace in slice:\n[");
      for (; !PT_isEqualArgs(orig,end); orig = PT_getArgsTail(orig)) {
	ATwarning(" %t", (ATerm) PT_getArgsHead(orig));
      }
      ATwarning("]\n");
      return ATfalse;
    }

    /* check if the last element is not whitespace */
    if (PT_isEqualArgs(next,end) && PT_isTreeLayout(elem1)) {
      ATwarning("Internal error. Last element is whitespace in slice:\n[");
      for (; !PT_isEqualArgs(orig,end); orig = PT_getArgsTail(orig)) {
	ATwarning(" %t,", (ATerm) PT_getArgsHead(orig));
      }
      ATwarning("]\n");
      return ATfalse;
    }
  }

  return ATtrue;
}
