#include "flatten.h"

/*{{{ ATerm SDFflattenLookAhead(ATerm la) */

/**
 * Converts the term representation of a lookahead.
 **/

ATerm SDFflattenLookAhead(SDF_Lookahead lookAhead, ATbool nested)
{
  ATerm atLookAhead;
  ATerm atCharClass;
  SDF_CharClass charClass;
  SDF_Lookaheads lookAheads;
  SDF_Lookahead localLookAhead;
  SDF_LookaheadList lookAheadList;
  ATermList newLookAheads;

  if (SDF_isLookaheadCharClass(lookAhead) && !nested) {
    charClass = SDF_getLookaheadCharClass(lookAhead);

    return PT_SymbolToTerm(SDFCharClassToPtSymbol(charClass));
  }
  else if (SDF_isLookaheadCharClass(lookAhead) && nested) {
    charClass = SDF_getLookaheadCharClass(lookAhead);
    atCharClass = PT_SymbolToTerm(SDFCharClassToPtSymbol(charClass));

    return ATmake("look(<term>,[<list>])", atCharClass, ATempty);
  }
  else if (SDF_isLookaheadSeq(lookAhead)) {
    charClass = SDF_getLookaheadHead(lookAhead);
    lookAheads = SDF_getLookaheadTail(lookAhead);

    atCharClass = PT_SymbolToTerm(SDFCharClassToPtSymbol(charClass));

    lookAheadList = SDF_getLookaheadsList(lookAheads);

    newLookAheads = ATempty;
    while (SDF_hasLookaheadListHead(lookAheadList)) {
      localLookAhead = SDF_getLookaheadListHead(lookAheadList);

      atLookAhead = SDFflattenLookAhead(localLookAhead, ATtrue);
      newLookAheads = ATappend(newLookAheads, atLookAhead);
      
      if (SDF_hasLookaheadListTail(lookAheadList)) {
        lookAheadList = SDF_getLookaheadListTail(lookAheadList);
      }
      else {
        break;
      }
    }
    return ATmake("look(<term>,[<list>])", atCharClass, newLookAheads);
  }
  else {
    ATerror("expected lookahead, got %t\n", lookAhead);
    return NULL;
  }
}

/*}}} */
