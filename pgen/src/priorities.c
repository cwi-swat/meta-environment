#include "ksdf2table.h"

#define PRIORITY_EXISTS(prio) \
  (ATindexedSetGetIndex(priority_table,(prio)) >= 0)

/*{{{ ATbool pgen_cnf(ATerm prodnr1, int iptr, int len, ATerm prodnr2) */

ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2)
{
  ATerm priorel;
  ATbool result;

  if(iptr == 0) {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_right_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      if (PRIORITY_EXISTS(priorel)) {
        result = ATtrue;
      }
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                     (ATerm)prodnr1, (ATerm)prodnr2);
	if (PRIORITY_EXISTS(priorel)) {
          result = ATtrue;
        }
        else {
          priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio,
                                       (ATerm)prodnr1, (ATerm)prodnr2);
	  if (PRIORITY_EXISTS(priorel)) {
            result = ATtrue;
          }
          else {
            result = ATfalse;
          }
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      if (PRIORITY_EXISTS(priorel)) {
        result = ATtrue;
      }
      else {
        result = ATfalse;
      }
    }
  }
  else {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_left_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      if (PRIORITY_EXISTS(priorel)) {
        result = ATtrue;
      }
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                     (ATerm)prodnr1, (ATerm)prodnr2);
	if (PRIORITY_EXISTS(priorel)) {
          result = ATtrue;
	}
        else {
          priorel = (ATerm)ATmakeAppl2(afun_assoc_prio,
                                       (ATerm)prodnr1, (ATerm)prodnr2);
	  if (PRIORITY_EXISTS(priorel)) {
            result = ATtrue;
	  }
          else {
            priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio,
                                         (ATerm)prodnr1, (ATerm)prodnr2);
	    if (PRIORITY_EXISTS(priorel)) {
              result = ATtrue;
	    }
            else {
              result = ATfalse;
	    }
          }
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      if (PRIORITY_EXISTS(priorel)) {
        result = ATtrue;
      }
      else {
        result = ATfalse;
      }
    }
  }

  return result;
}

/*}}} */
