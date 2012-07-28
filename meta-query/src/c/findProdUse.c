/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>

#include <PT2SDF.h>
#include <MEPT-utils.h>

#include "findProdUse.h"

/*}}}  */
ATbool productionsMatch(SDF_Production p1, SDF_Production p2, void *cargo);

/*{{{  static ASF_CondEquation findProductionInEquation(SDF_Production needle, ASF_EquationList haystack) */

static ASF_CondEquation findProductionInEquation(SDF_Production needle,
					     ASF_Equations haystack)
{
  ASF_CondEquationList equations = ASF_getEquationsList(haystack);

  while (!ASF_isCondEquationListEmpty(equations)) {
    ASF_CondEquation suspect = ASF_getCondEquationListHead(equations);
    ASF_Equation equation = ASF_getCondEquationEquation(suspect);
    ASF_Tree lhs = ASF_getEquationLhs(equation);
    PT_Tree tree = PT_TreeFromTerm(ASF_TreeToTerm(lhs));
    PT_Production prod = PT_getTreeProd(tree);
    SDF_Production sdfProd = PTProductionToSDFProduction(prod);

    ATwarning("prod = %s\n", PT_yieldTree((PT_Tree)sdfProd));
    ATwarning("needle = %s\n", PT_yieldTree((PT_Tree)needle));
    if (productionsMatch(needle, sdfProd, NULL)) {
      return suspect;
    }

    if (ASF_hasCondEquationListTail(equations)) {
      equations = ASF_getCondEquationListTail(equations);
    }
    else {
      break;
    }
  }

  return NULL;
}

/*}}}  */

/*{{{  ATerm queryProdUse(ASF_Equations equations, SDF_Production production) */

ATerm queryProdUse(ASF_Equations equations, SDF_Production sdfProduction)
{
  ASF_CondEquation found;
  ATerm pos = NULL;

  found = findProductionInEquation(sdfProduction, equations);

  if (found != NULL) {
    pos = ATgetAnnotation(ASF_CondEquationToTerm(found), ATmake("pos-info"));
  }

  return pos;
}

/*}}}  */
