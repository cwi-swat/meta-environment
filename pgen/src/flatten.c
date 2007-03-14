/* $Id$ */

#include "flatten.h"
#include <SDF2PT.h>

PTBL_CharClasses implodeLookaheadRecursive(SDF_Lookahead lookahead) {
  PTBL_CharClass ptblCharClass;
  PTBL_CharClasses ptblCharClasses = PTBL_makeCharClassesEmpty();
  PTBL_CharClasses recPTBLCharClasses;
  SDF_CharClass charClass;
  SDF_Lookaheads lookAheads;
  SDF_Lookahead localLookAhead;
  SDF_LookaheadList lookAheadList;

  if (SDF_isLookaheadCharClass(lookahead)) {
    charClass = SDF_getLookaheadCharClass(lookahead);
    ptblCharClass = (PTBL_CharClass)SDFCharClassToPtSymbol(charClass);
 
    return PTBL_makeCharClassesSingle(ptblCharClass); 
  }
  else if (SDF_isLookaheadSeq(lookahead)) {
    charClass = SDF_getLookaheadHead(lookahead);
    lookAheads = SDF_getLookaheadTail(lookahead);

    ptblCharClass = (PTBL_CharClass)SDFCharClassToPtSymbol(charClass);
    lookAheadList = SDF_getLookaheadsList(lookAheads);

    while (SDF_hasLookaheadListHead(lookAheadList)) {
      localLookAhead = SDF_getLookaheadListHead(lookAheadList);

      recPTBLCharClasses = implodeLookaheadRecursive(localLookAhead);
      ptblCharClasses = PTBL_concatCharClasses(ptblCharClasses, recPTBLCharClasses);
      
      if (SDF_hasLookaheadListTail(lookAheadList)) {
        lookAheadList = SDF_getLookaheadListTail(lookAheadList);
      }
      else {
        break;
      }
    }
    return PTBL_makeCharClassesMany(ptblCharClass, ptblCharClasses);
  }
  else {
    ATerror("expected lookahead, got %t\n", lookahead);
    return NULL;
  }
}

/* Converts the term representation of a lookahead. */
PTBL_Restriction implodeLookahead(SDF_Lookahead lookahead) {
  PTBL_CharClasses charClasses = implodeLookaheadRecursive(lookahead);

  return PTBL_makeRestrictionFollow(charClasses);
}
