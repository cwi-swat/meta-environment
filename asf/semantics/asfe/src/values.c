#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>
#include "values.h"

/* The values for the asf rewriter are parse trees. The AsFix formalism is
 * extended with Slices here to tailor for efficient access to sublists
 * of AsFix lists
 */

/*{{{  ATbool isListSeparator(PT_Tree elem, PT_Production listProd) */

ATbool isListSeparator(PT_Tree elem, PT_Production listProd)
{
  PT_Symbol symbol, listSymbol;
  PT_Symbol separator;
  char *str;
  PT_Production prod;

  listSymbol = PT_getProductionRhs(listProd);

  if (PT_isIterSepSymbol(listSymbol)) { 
    separator = PT_getIterSepSeparator(listSymbol);
    if (PT_isTreeAppl(elem)) {
      prod = PT_getTreeProd(elem);
      symbol = PT_getSymbolSymbol(PT_getProductionRhs(prod));
      return PT_isEqualSymbol(separator, symbol);
    }
    else {
      str = PT_getTreeString(elem);
      if (PT_isSymbolLit(separator)) {
	return strcmp(str, PT_getSymbolString(separator)) == 0;
      }
    }
  }
  return ATfalse;
}

/*}}}  */

/*{{{   PT_Args getSliceFirst(Slice slice) */

 PT_Args getSliceFirst(Slice slice)
{
  return PT_makeArgsFromTerm(ATgetArgument((ATermAppl) slice, 1));
}

/*}}}  */
/*{{{   PT_Args getSliceLast(Slice slice) */

 PT_Args getSliceLast(Slice slice)
{
  return PT_makeArgsFromTerm(ATgetArgument((ATermAppl) slice, 2));
}

/*}}}  */
/*{{{   PT_Args prepend(PT_Args first, PT_Args last, PT_Args list) */

/*
 * Prepend a slice to the front of a list
 */

 PT_Args prepend(PT_Args first, PT_Args last, PT_Args list)
{
  PT_Args temp;
  PT_Tree elem;

  if (PT_isEqualArgs(first, last)) {
    return list;
  }

  elem = PT_getArgsHead(first);
  temp = prepend(PT_getArgsTail(first), last, list);

  if (PT_isArgsEmpty(temp) && PT_isTreeLayout(elem)) {
    return PT_makeArgsEmpty();
  }

  return PT_makeArgsList(elem, temp);
}

/*}}}  */
/*{{{   PT_Args prependSlice(Slice slice, PT_Args list) */

PT_Args prependSlice(Slice slice, PT_Args list)
{
  PT_Args first = getSliceFirst(slice);
  PT_Args last = getSliceLast(slice);

  return prepend(first, last, list);
}

/*}}}  */
/*{{{  PT_Args appendSlice(PT_Args list, Slice slice) */

/*
 * Append a slice to a list
 */

PT_Args appendSlice(PT_Args list, Slice slice)
{
  return PT_concatArgs(list, prependSlice(slice, PT_makeArgsEmpty()));
}

/*}}}  */
/*{{{   PT_Args concatElems(listProd, PT_Args elems, PT_Args newElems) */

/* The list of elements is rewritten and a new elementlist
   is constructed. */


PT_Args concatElems(PT_Production listProd, PT_Args elems, PT_Args newElems)
{
  PT_Args newList;
  PT_Symbol sym = PT_getProductionRhs(listProd);
  int seplen = 0;

  if (PT_isSymbolLex(sym)) {
    if (PT_isIterSepSymbol(sym)) {
      seplen = 1;
    }
    else {
      seplen = 0;
    }
  }
  else if (PT_isSymbolCf(sym)) {
    if (PT_isIterSepSymbol(sym)) {
      seplen = 3;
    }
    else {
      seplen = 1;
    }
  }

  if (PT_isArgsEmpty(elems)) {
    newList = newElems;
  }
  else {
    if (!PT_isArgsEmpty(newElems)) {
      newList = PT_concatArgs(elems, newElems);
    }
    else {
      int length = PT_getArgsLength(elems);
      if (length > seplen) {
	newList = PT_sliceArgs(elems, 0, length-seplen);
      }
      else {
	newList = PT_makeArgsEmpty();
      }
    }
  }

  return newList;
}

/*}}}  */
/*{{{   PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem) */

PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem)
{
  if (PT_isArgsEmpty(elems)) {
    if (PT_isTreeLayout(elem)) {
      return elems;
    }
    else if (isListSeparator(elem, listProd)) {
      return elems; 
    }
  }
  return PT_appendArgs(elems, elem);
}

/*}}}  */
/*{{{   PT_Args addElemsToArgs(PT_Production listProd, PT_Args elems, PT_Args args)  */

PT_Args addElemsToArgs(PT_Production listProd, PT_Args elems, PT_Args args) 
{
  PT_Tree listArg = PT_makeTreeAppl(listProd, elems);
  return PT_makeArgsList(listArg, args);
}

/*}}}  */
/*{{{   ATerm getFirstArgument(PT_Tree trm) */

PT_Tree getFirstArgument(PT_Tree trm)
{
  PT_Args args;

  if (!PT_hasTreeArgs(trm)) {
    return NULL;
  }

  args = PT_getTreeArgs(trm);

  while (PT_hasArgsHead(args) &&
	 (PT_isTreeLit(PT_getArgsHead(args)) ||
	  PT_isTreeLayout(PT_getArgsHead(args)))) {
    args = PT_getArgsTail(args);
  }

  if (PT_hasArgsHead(args)) {
    return PT_getArgsHead(args);
  }

  return NULL;
}

/*}}}  */


/*{{{  ATbool isEqualModuloWhitespace(PT_Tree asfix1, PT_Tree asfix2) */

ATbool isEqualModuloWhitespace(PT_Tree asfix1, PT_Tree asfix2)
{
  asfix1 = PT_makeTreeFromTerm(
	       ATremoveAnnotations(PT_makeTermFromTree(asfix1)));
  asfix2 = PT_makeTreeFromTerm(
	       ATremoveAnnotations(PT_makeTermFromTree(asfix2)));

  if (!PT_isEqualTree(asfix1, asfix2)) {
    if (PT_isTreeAppl(asfix1) && PT_isTreeAppl(asfix2)) {
      PT_Production prod1 = PT_getTreeProd(asfix1);
      PT_Production prod2 = PT_getTreeProd(asfix2);

      if (PT_isOptLayoutProd(prod1) && PT_isOptLayoutProd(prod2)) {
	return ATtrue;
      }

      /* If it is an appl, prods should be ATequal and kids should be
       * equal modulo whitespace 
       */
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
    else {
      /* different or not handled types of asfix terms are not equal by definition */

      assert(!PT_isTreeLayout(asfix1) && !PT_isTreeLayout(asfix2));

      return ATfalse;
    }

    return ATfalse;
  }

  /* asfix1 and asfix2 are ATequal */
  return ATtrue;
}

/*}}}  */

/*{{{  PT_Args skipWhitespace(PT_Args list) */

PT_Args skipWhitespace(PT_Args list)
{
  PT_Tree elem;

  if (PT_hasArgsHead(list)) {
    elem = PT_getArgsHead(list);
    if (PT_isTreeLayout(elem)) {
      list = PT_getArgsTail(list);
    }
  }

  return list;
}

/*}}}  */
/*{{{  PT_Args skipWhitespaceAndSeparator(PT_Args list, PT_Production listProd) */

PT_Args skipWhitespaceAndSeparator(PT_Args list, PT_Production listProd)
{
  list = skipWhitespace(list);

  if (PT_hasArgsHead(list) &&
      isListSeparator(PT_getArgsHead(list), listProd)) {
    list = skipWhitespace(PT_getArgsTail(list));
  }

  return list;
}

/*}}}  */
/*{{{  PT_Args skipToEndOfWhitespace(PT_Args list) */

PT_Args skipToEndOfWhitespace(PT_Args list)
{
  PT_Tree elem;
  PT_Args prev = list;

  if (!PT_isArgsEmpty(list)) {
    for (elem = PT_getArgsHead(list); 
         PT_hasArgsHead(list) && PT_isTreeLayout(elem);
	 prev = list, list = PT_getArgsTail(list), elem = PT_getArgsHead(list));
  }

  return prev;
}

/*}}}  */


/* isValidList checks:
 *    - if no consecutive whitespaces nodes occur
 *    - if it doesn't begin or end with whitespace
 */
/*{{{  ATbool isValidList(PT_Args list) */

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

/*}}}  */

/* isValidSlice does the same as isValidList but for a slice */
/*{{{  ATbool isValidSlice(PT_Args begin, PT_Args end) */

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

/*}}}  */
