/* 
 * This unit test tests the reduction with whitespace by reducing a term with
 * and without whitespace and comparing the results using isEqualModuloWhitespace.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../preparation.h"
#include <AsFix.h>

ATerm reduce_test(ATerm eqs, ATerm term, ATbool with_whitespace);

/* externs */
extern ATerm equations_db;
extern ATerm fail_env;
extern ATerm posinfo;
extern AFun list_var, plain_var;
extern ATbool keep_whitespace; 
extern ATermList rewrite_errors;
extern ATerm rewrite(ATerm trm, ATerm env);

int main(int argc, char *argv[])
{
	ATbool usage = ATfalse;
	FILE *eqsfile, *termfile;
	ATerm eqs, term, result[2];
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

	/* first we use normal reduction */
	result[0] = reduce_test(eqs,term, ATfalse);

	/* re-init db */
	ATunprotect(&equations_db);
	equations_db = ATdictCreate();
	ATprotect(&equations_db);

	/* then we reduce with whitespace */
	result[1] = reduce_test(eqs, term,ATtrue);
	
	if(!isEqualModuloWhitespace(result[0],result[1]))
		ATerror("isEqualModuloWhitespace returns false instead of true.\n");

	return 0;
}

ATerm reduce_test(ATerm eqs, ATerm term, ATbool with_whitespace)
{
	ATermList preparedeqs;
	ATerm oldterm;
	char name[] = "Reduce_test";

	/* set the global */
	keep_whitespace = with_whitespace;

	/* prepare equations */
	preparedeqs =  RWprepareEqs((ATermList) eqs);
	enter_equations(name, preparedeqs);

	/* prepare term */
	term = ATremoveAllAnnotations(term);
	oldterm = term;
	term = asfix_get_term(term);
	term = RWprepareTerm(term);

	/* rewrite */
	select_equations(name);
	rewrite_errors = ATempty;
	
	term = rewrite(term,(ATerm) ATempty);
	term = RWrestoreTerm(term);
	term = asfix_put_term(oldterm,term);
	
	if(!ATisEmpty(rewrite_errors))
		ATerror("errors during rewriting: %l", rewrite_errors);

	return term;
}
