/*{{{  file header */

/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
  $Id$  
 */

/*
 * The version of se is written by Mark van den Brand.
 */

/*}}}  */
/*{{{  includes */

#include <stdlib.h>

#include "se.h"
#include "sort.h"

/*}}}  */

/*{{{  ATerm newSort(char *sort) */

/**
 * Create sort definition given the sort name as a string.
 */

ATerm
newSort(char *sort)
{
  return ATmake("sort(<str>)", sort);
}

/*}}}  */
/*{{{  ATerm getReadableSort(ATerm sort) */

/**
 * Convert type specs to human readable representation of AsFix sort:
 * - sort(<str>) is left untouched
 * - iter(<sort>)[*+] is transformed into sort(<sort>[*+])
 * - iter-sep(<sort>,<sep>)[*+] is transformed into sort(<sort><sep>[*+])
 */

ATerm
getReadableSort(ATerm sort)
{
  ATerm iterSort, iterSep, newSort;
  char *sortText, *sepText;
  char *newTextSort;

  if (ATmatch(sort, "sort(<str>)", &sortText)) {
    return sort;
  }
  else if (ATmatchTerm(sort, pattern_asfix_iter_star, &iterSort)) {
    if (ATmatch(iterSort, "sort(<str>)", &sortText)) {
      newTextSort = (char *) malloc(strlen(sortText) + 2);
      sprintf(newTextSort, "%s*", sortText);
      newSort = ATmake("sort(<str>)", newTextSort);
      free(newTextSort);
      return newSort;
    }
  }
  else if (ATmatchTerm(sort, pattern_asfix_iter_plus, &iterSort)) {
    if (ATmatch(iterSort, "sort(<str>)", &sortText)) {
      newTextSort = (char *) malloc(strlen(sortText) + 2);
      sprintf(newTextSort, "%s+", sortText);
      newSort = ATmake("sort(<str>)", newTextSort);
      free(newTextSort);
      return newSort;
    }
  }
  else if (ATmatchTerm(sort, pattern_asfix_itersep_star, &iterSort, &iterSep)) {
    if (ATmatch(iterSort, "sort(<str>)", &sortText)) {
      if (ATmatch(iterSep, "ql(<str>)", &sepText)) {
	newTextSort = (char *) malloc(strlen(sortText) + strlen(sepText) + 4);
	sprintf(newTextSort, "{%s%s}*", sortText, sepText);
	newSort = ATmake("sort(<str>)", newTextSort);
	free(newTextSort);
	return newSort;
      }
    }
  }
  else if (ATmatchTerm(sort, pattern_asfix_itersep_plus, &iterSort, &iterSep)) {
    if (ATmatch(iterSort, "sort(<str>)", &sortText)) {
      if (ATmatch(iterSep, "ql(<str>)", &sepText)) {
	newTextSort = (char *) malloc(strlen(sortText) + strlen(sepText) + 4);
	sprintf(newTextSort, "{%s%s}+", sortText, sepText);
	newSort = ATmake("sort(<str>)", newTextSort);
	free(newTextSort);
	return newSort;
      }
    }
  }
  ATerror("Unknown sort: %t\n", sort);
  return NULL;
}

/*}}}  */
/*{{{  ATbool isStartSymbol(ATerm sort, ATermList symbols) */

ATbool
isStartSymbol(ATerm sort, ATermList symbols)
{
  return ATindexOf(symbols, sort, 0) != -1;
}

/*}}}  */
