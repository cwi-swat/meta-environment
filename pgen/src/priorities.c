#include <aterm2.h>

#include "priorities.h"
#include "ksdf2table.h"

#define PRIORITY_EXISTS(prio) (ATindexedSetGetIndex(priority_table,(prio)) >= 0)

ATbool isPrioArgument(ATerm prioentry)
{
  AFun symbol = ATgetAFun((ATermAppl)prioentry);
  return ATisEqual(symbol, afun_arg_gtr_prio);
}

ATerm getPrioRight(ATerm prioentry)
{
  if (isPrioArgument(prioentry)) {
    return ATgetArgument((ATermAppl)prioentry, 2);
  }
  else {
    return ATgetArgument((ATermAppl)prioentry, 1);
  }
}

ATerm setPrioRight(ATerm prioentry, ATerm prodNr)
{
  if (isPrioArgument(prioentry)) {
    return (ATerm)ATsetArgument((ATermAppl)prioentry, prodNr, 2);
  }
  else {
    return (ATerm)ATsetArgument((ATermAppl)prioentry, prodNr, 1);
  }
}

ATerm getPrioLeft(ATerm prioentry)
{
  return ATgetArgument((ATermAppl)prioentry, 0);
}

ATerm setPrioLeft(ATerm prioentry, ATerm prodNr)
{
  return (ATerm)ATsetArgument((ATermAppl)prioentry, prodNr, 0);
}

/*{{{  ATbool conflicts(Item item, ATerm label) */

ATbool conflicts(Item item, ATerm label)
{
  ATbool result;
  ATerm prodnr = (ATerm)ATmakeInt(IT_getProdNr(item));
  int iptr = IT_getDotPosition(item);
  ATerm priorel = (ATerm)ATmakeAppl2(afun_gtr_prio, prodnr, label);

  if (PRIORITY_EXISTS(priorel)) {
    result = ATtrue;
  }
  else {
    priorel = (ATerm)ATmakeAppl3(afun_arg_gtr_prio, 
				 prodnr, 
				 (ATerm)ATmakeInt(iptr),
				 label);
    if (PRIORITY_EXISTS(priorel)) {
      result = ATtrue;
    }
    else {
      result = ATfalse;
    }
  }

  return result;
}

/*}}}  */

