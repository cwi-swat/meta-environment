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

    $Id$
*/
/* 
 * This unit test tests the reduction with whitespace by reducing a term with
 * and without whitespace and comparing the results using isEqualModuloWhitespace.
 */

#include <stdio.h>
#include <stdlib.h>
#include "preparation.h"
#include "asfix_utils.h"
#include "evaluator.h"
#include <AsFix.h>

ATerm reduce_test(ATerm eqs, ATerm term, ATbool with_whitespace);

int main(int argc, char *argv[])
{
  FILE *eqsfile, *termfile;
  ATerm eqs = NULL, term = NULL, result[2] = {NULL};
  ATerm bottomOfStack;

  AFinit(argc, argv, &bottomOfStack);
	
  /* init */
  equations_db = ATdictCreate();
  ATprotect(&equations_db);

  fail_env = ATparse("[fail]");
  ATprotect(&fail_env);

  posinfo = ATparse("pos-info");
  ATprotect(&posinfo);

  list_var  = ATmakeAFun("*list-var*", 3, ATtrue);
  ATprotectAFun(list_var);

  plain_var = ATmakeAFun("*plain-var*", 2, ATtrue);
  ATprotectAFun(plain_var);
 
  ATprotectArray(result, 2);
  ATprotect(&eqs);
  ATprotect(&term);

  if(argc != 3) {
    ATerror("Usage: whitespace equationsfile termfile\n");
  }
  else {
    if(!(eqsfile = fopen(argv[1],"r")))
      ATerror("Could not open %s.\n", argv[1]);

    if(!(termfile = fopen(argv[2],"r")))
      ATerror("Could not open %s.\n", argv[2]);
  }

	
  eqs = ATreadFromFile(eqsfile);
  term = ATreadFromFile(termfile);

  fclose(eqsfile);
  fclose(termfile);


  if(run_verbose) {
    ATwarning("=====================%s=======================\n",argv[2]);
  }

  /* first we use normal reduction */
  result[0] = reduce_test(eqs,term, ATfalse);

  /* re-init db */
  equations_db = ATdictCreate();

  if(run_verbose) {
    ATwarning("=====================%s=======================\n",argv[2]);
  }

  /* then we reduce with whitespace */
  result[1] = reduce_test(eqs, term,ATtrue);
	
  if(!isEqualModuloWhitespace(result[0],result[1]))		{
    ATerror("Terms %t AND %t are different modulo whitespace.\n",
	    result[0],result[1]);
  }
	
  return 0;
}

ATerm reduce_test(ATerm eqs, ATerm term, ATbool with_whitespace)
{
  ATermList preparedeqs;
  char name[] = "Reduce_test";

  /* set the global */
  keep_layout = with_whitespace;

  /* prepare equations */
  preparedeqs =  RWprepareEqs((ATermList) eqs);
  enter_equations(name, preparedeqs);

	return evaluator(name, term);
}
