#include <PTMEPT.h>
#include <aterm2.h>

/*{{{  PTPT_TreeList PTPT_reverseTreeList(PTPT_TreeList args) */

PTPT_TreeList PTPT_reverseTreeList(PTPT_TreeList args)
{
  return (PTPT_TreeList) ATreverse((ATermList) args);
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_reverseSymbolList(PTPT_SymbolList args) */

PTPT_SymbolList PTPT_reverseSymbolList(PTPT_SymbolList args)
{
  return (PTPT_SymbolList) ATreverse((ATermList) args);
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_reverseAttrList(PTPT_AttrList args) */

PTPT_AttrList PTPT_reverseAttrList(PTPT_AttrList args)
{
  return (PTPT_AttrList) ATreverse((ATermList) args);
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_reverseCharRangeList(PTPT_CharRangeList args) */

PTPT_CharRangeList PTPT_reverseCharRangeList(PTPT_CharRangeList args)
{
  return (PTPT_CharRangeList) ATreverse((ATermList) args);
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_reverseATermElems(PTPT_ATermElems args) */

PTPT_ATermElems PTPT_reverseATermElems(PTPT_ATermElems args)
{
  return (PTPT_ATermElems) ATreverse((ATermList) args);
}

/*}}}  */
