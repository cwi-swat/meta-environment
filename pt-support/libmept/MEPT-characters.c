#include <MEPT.h>
#include <assert.h>

/**
 * \file
 * Functions for dealing with the leaf level of trees: characters
 * and character classes
 */

/** 
 * Tests if an element is included in a character class
 * \param character character to be searched for
 * \param charClass an ordered character class
 * \return ATtrue if #character is in #charClass, ATfalse otherwise
 */
ATbool PT_elementOfCharClass(PT_Tree character, PT_Symbol charClass)
{
  int ch = PT_getTreeCharacter(character);
  PT_CharRanges ranges = PT_getSymbolRanges(charClass);

  for (;!PT_isCharRangesEmpty(ranges); ranges = PT_getCharRangesTail(ranges)) {
    PT_CharRange range = PT_getCharRangesHead(ranges);
    
    if (PT_isCharRangeRange(range)) {
      int start = PT_getCharRangeStart(range);
      int end = PT_getCharRangeEnd(range);

      /* we know the ranges mutually exclusive and ordered on start position,
       * so we can guarantee that no other range will match if ch < start
       */
      if (ch < start) {
	return ATfalse;
      }
      else if (ch <= end) {
	return ATtrue;
      }
    }
    else {
      int comp = PT_getCharRangeStart(range);

      if (comp == ch) {
	return ATtrue;
      }
    }
  }

  return ATfalse;
}

/**
 * Tests if a characters class is a subset of another.
 * \param c1 first character class
 * \param c2 second character class
 * \return ATtrue if all characters of #c1 are in #c2, ATfalse otherwise
 */
ATbool PT_subsetOfCharClass(PT_Symbol c1, PT_Symbol c2)
{
  PT_CharRanges ranges1 = PT_getSymbolRanges(c1);
  PT_CharRanges ranges2 = PT_getSymbolRanges(c2);

  /* Note that we can assume that all ranges in a character class
   * are mutually exclusive, and ordered in increasing value of the
   * start of each range. And all consecutive ranges are compressed.
   * This is due to the SDF normalizer.
   */

  for ( ; !PT_isCharRangesEmpty(ranges2); 
	ranges2 = PT_getCharRangesTail(ranges2)) {

    PT_CharRange range2 = PT_getCharRangesHead(ranges2);
    int start2 = PT_getCharRangeStart(range2);
    int end2 = PT_isCharRangeRange(range2) ? 
      PT_getCharRangeEnd(range2) : start2;

    for ( ; !PT_isCharRangesEmpty(ranges1); 
	  ranges1 = PT_getCharRangesTail(ranges1)) {

      PT_CharRange range1 = PT_getCharRangesHead(ranges1);
      int start1 = PT_getCharRangeStart(range1);
      int end1 = PT_isCharRangeRange(range1) ? 
	PT_getCharRangeEnd(range1) : start1;

      if (start1 < start2) {
	return ATfalse; /* due to strict ordering of ranges */
      }
      else if (start1 > end2) {
	break; /* find next range to fit this one in */
      }
      else if (end1 < start2) {
	return ATfalse; /* due to strict ordering of ranges */
      }
      else if (end1 > end2) {
	return ATfalse; /* start fits, but end does not fit */
      }
      else {
	assert(start1 >= start2 && end1 <= end2);
	/* this one fits, let's get on with the next range */
	continue;
      }
    }

    if (PT_isCharRangesEmpty(ranges1)) {
      /* all ranges fit */
      return ATtrue;
    }
  }

  if (PT_isCharRangesEmpty(ranges2)) {
    return ATfalse;
  }
  else {
    return ATtrue;
  }
}


