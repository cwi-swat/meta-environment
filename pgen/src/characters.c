#include "ksdf2table.h"

/*{{{  ATermList insert_range_in_charrange_list(ATerm cr, ATermList crl) */

ATermList insert_range_in_charrange_list(ATerm cr, ATermList crl)
{
  int icre, ilr1, ilr2, irr1, irr2;
  ATbool success;
  ATerm cre, newcre;
  ATermInt lr1, rr1, lr2, rr2;
  ATermList newcrl = ATempty;

  if(ATisEmpty(crl))
    return ATmakeList1((ATerm)cr);
  else {
    if(IS_RANGE(cr)) {
      lr1 = GET_INT_ARG(cr, 0);
      rr1 = GET_INT_ARG(cr, 1);
      success = ATfalse;
      ilr1 = ATgetInt(lr1);
      irr1 = ATgetInt(rr1);
      while(!ATisEmpty(crl)) {
        cre = ATgetFirst(crl);
        if(IS_RANGE(cre)) {
          lr2 = GET_INT_ARG(cre, 0);
          rr2 = GET_INT_ARG(cre, 1);
          ilr2 = ATgetInt(lr2);
          irr2 = ATgetInt(rr2);
          if(ilr2 > irr1) {
            if(ilr2-1 == irr1) {
              newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr1, (ATerm)rr2);
              newcrl = ATappend(newcrl, newcre);
              crl = ATgetNext(crl);
            }
            else
              newcrl = ATappend(newcrl, (ATerm)cr);
            newcrl = ATconcat(newcrl, crl);
            crl = ATempty;
            success = ATtrue;
          }
          else if(ilr1 > irr2) {
            if(ilr1-1 == irr2) {
              newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr2, (ATerm)rr1);
	      newcrl = ATconcat(newcrl, 
                                insert_range_in_charrange_list(newcre, crl));
              crl = ATempty;
              success = ATtrue;
            }
            else {
              newcrl = ATappend(newcrl, cre);
              crl = ATgetNext(crl);
            }
          }
          else if(ilr1 >= ilr2 && irr1 <= irr2) {
            newcrl = ATconcat(newcrl, crl);
            crl = ATempty;
            success = ATtrue;
          }
          else if(ilr1 < ilr2 && irr1 > irr2) {
/*
ATwarning("ilr1=%d irr1=%d ilr2=%d irr2=%d\n", ilr1, irr1, ilr2, irr2);
*/

            newcrl = ATconcat(newcrl,
                              insert_range_in_charrange_list(cr, 
                                                             ATgetNext(crl)));
/*
            newcrl = ATappend(newcrl, (ATerm)cr);
            newcrl = ATconcat(newcrl, ATgetNext(crl));
*/
            crl = ATempty;
            success = ATtrue;
          }
          else {
/*
ATwarning("ilr1=%d irr1=%d ilr2=%d irr2=%d\n", ilr1, irr1, ilr2, irr2);
*/
            if(ilr1 < ilr2) {
              cr = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr1, (ATerm)rr2);
              rr1 = rr2;
              irr1 = irr2;
            }
            else {
              cr = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr2, (ATerm)rr1);
              lr1 = lr2;
              ilr1 = ilr2;
            }
            crl = ATgetNext(crl);
          }
        }
        else {
          icre = ATgetInt((ATermInt)cre);
          if(icre < ilr1) {
            if(icre+1 == ilr1) {
              newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)cre, (ATerm)rr1);
              newcrl = ATappend(newcrl, newcre);;
              newcrl = ATconcat(newcrl, ATgetNext(crl));
              crl = ATempty;
              success = ATtrue;
            }
            else {
              newcrl = ATappend(newcrl, cre);
              crl = ATgetNext(crl);
            }
          }
          else if(icre > irr1) {
            if(icre-1 == irr1) {
              newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr1, (ATerm)cre);
	      newcrl = ATconcat(newcrl, 
                                insert_range_in_charrange_list(newcre, crl));
              crl = ATempty;
              success = ATtrue;
            }
            else {
              newcrl = ATappend(newcrl, (ATerm)cr);
              newcrl = ATconcat(newcrl, crl);
              crl = ATempty;
              success = ATtrue;
            }
          }
          else {
	    newcrl = ATconcat(newcrl, 
                              insert_range_in_charrange_list(cr, 
                              ATgetNext(crl)));
/*
            newcrl = ATappend(newcrl, (ATerm)cr);
            crl = ATgetNext(crl);
            newcrl = ATconcat(newcrl, crl);
*/
            crl = ATempty;
            success = ATtrue;
          }
        }
      }
      if(!success)
        newcrl = ATappend(newcrl,cr);
    }
  }
  return newcrl;
}

/*}}}  */
/*{{{  ATermList insert_char_in_charrange_list(ATermInt cr,ATermList crl) */

ATermList insert_char_in_charrange_list(ATermInt cr, ATermList crl)
{
  int icr, icre, ilr, irr;
  ATbool success;
  ATerm cre, newcre;
  ATermInt lr, rr;
  ATermList newcrl = ATempty;

  if(ATisEmpty(crl))
    return ATmakeList1((ATerm)cr);
  else {
    icr = ATgetInt(cr);
    success = ATfalse;
    while(!ATisEmpty(crl)) {
      cre = ATgetFirst(crl);
      crl = ATgetNext(crl);
      if(IS_RANGE(cre)) {
        lr = GET_INT_ARG(cre, 0);
        rr = GET_INT_ARG(cre, 1);
        irr = ATgetInt(rr);
        ilr = ATgetInt(lr);
        if(icr < ilr) {
          if(icr+1 == ilr) {
            newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)cr, (ATerm)rr);
            newcrl = ATappend(newcrl, newcre);
          }
          else {
            newcrl = ATappend(newcrl, (ATerm)cr);
            newcrl = ATappend(newcrl, cre);
          }
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
          success = ATtrue;
        }
        else if(icr > irr) {
          if(icr-1 == irr) {
            newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)lr, (ATerm)cr);
	    newcrl = ATconcat(newcrl, 
                              insert_range_in_charrange_list(newcre, crl));
            crl = ATempty;
            success = ATtrue;
          }
          else {
            newcrl = ATappend(newcrl, cre);
          }
        }
        else {
          newcrl = ATappend(newcrl, cre);
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
          success = ATtrue;
        }
      }
      else {
        icre = ATgetInt((ATermInt)cre);
        if(icr < icre) {
          if(icr+1 == icre) {
            newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)cr, (ATerm)cre);
            newcrl = ATappend(newcrl, newcre);
          }
          else {
            newcrl = ATappend(newcrl, (ATerm)cr);
            newcrl = ATappend(newcrl, (ATerm)cre);
          }
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
          success = ATtrue;
        }
        else if(icr == icre) {
          newcrl = ATappend(newcrl, (ATerm)cre);
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
          success = ATtrue;
        }
        else {
          if(icr-1 == icre) {
            newcre = (ATerm)ATmakeAppl2(afun_range, (ATerm)cre, (ATerm)cr);
	    newcrl = ATconcat(newcrl, 
                              insert_range_in_charrange_list(newcre, crl));
            crl = ATempty;
            success = ATtrue;
          }
          else {
            newcrl = ATappend(newcrl, cre);
          }
        }
      }   
    }
    if(!success)
      newcrl = ATappend(newcrl, (ATerm)cr);
    return newcrl;
  }
}

/*}}}  */
/*{{{  ATermList charrange_union(ATermList cr1,ATermList cr2) */

ATermList charrange_union(ATermList crl1, ATermList crl2)
{
  ATerm cr1;

  if(ATisEmpty(crl1)) {
    return crl2;
  }
  else if(ATisEmpty(crl2)) {
    return crl1;
  }
  else {
    while(!ATisEmpty(crl1)) {
      cr1 = ATgetFirst(crl1);
      crl1 = ATgetNext(crl1);
      if(IS_RANGE(cr1))
        crl2 = insert_range_in_charrange_list(cr1,crl2);
      else
        crl2 = insert_char_in_charrange_list((ATermInt)cr1, crl2);
    }
    return crl2;
  }
}

/*}}}  */
/*{{{  ATerm charclass_union(ATerm cc1,ATerm cc2) */

ATerm charclass_union(ATerm cc1,ATerm cc2)
{
  ATermList newcrl = ATempty;

  if(IS_CHARCLASS(cc1) && IS_CHARCLASS(cc2))
      newcrl = charrange_union(GET_LIST_ARG(cc1, 0),
                               GET_LIST_ARG(cc2, 0));
  return (ATerm)ATmakeAppl(afun_char_class, (ATerm)newcrl);
}

/*}}}  */
/*{{{  ATerm range_in_charrange_list(ATerm cr,ATermList crl) */

ATermList range_in_charrange_list(ATerm range, ATermList crl)
{
  int ilr1, irr1, ilr2, irr2, icre;
  ATermInt lr1, rr1, lr2, rr2;
  ATerm cre, newrange;
  ATermList newcrl = ATempty;

/* 
ATwarning("Range = %t and crl = %t\n", range, crl);
*/

  if(ATisEmpty(crl))
    return NULL;
  else {
    if(IS_RANGE(range)) {
      lr1 = GET_INT_ARG(range, 0);
      rr1 = GET_INT_ARG(range, 1);
      ilr1 = ATgetInt(lr1);
      irr1 = ATgetInt(rr1);
      while(!ATisEmpty(crl)) {
        cre = ATgetFirst(crl);
        if(IS_RANGE(cre)) {
          lr2 = GET_INT_ARG(cre, 0);
          rr2 = GET_INT_ARG(cre, 1);
          ilr2 = ATgetInt(lr2);
          irr2 = ATgetInt(rr2);
	  
/*
ATwarning("ilr1=%d irr1=%d ilr2=%d irr2=%d\n", ilr1, irr1, ilr2, irr2); 
*/

          if(ilr1 >= ilr2 && irr1 <= irr2)
            newcrl = ATappend(newcrl,range);
          else if(ilr1 >= ilr2 && irr1 > irr2) {
            if(irr2 == ilr1) {
              newrange = (ATerm)ATmakeInt(irr2);
              newcrl = ATappend(newcrl,newrange);
            }
            else if(irr2 > ilr1) {
              newrange = (ATerm)ATmakeAppl2(afun_range, 
                                            (ATerm)lr1, (ATerm)rr2);
              newcrl = ATappend(newcrl,newrange);
            }
          }
          else if(ilr1 < ilr2 && irr1 <= irr2) {
            if(irr1 == ilr2) {
              newrange = (ATerm)ATmakeInt(irr1);
              newcrl = ATappend(newcrl,newrange);
            }
            else if(irr1 > ilr2) {
              newrange = (ATerm)ATmakeAppl2(afun_range, 
                                            (ATerm)lr2, (ATerm)rr1);
              newcrl = ATappend(newcrl,newrange);
            }
          }
          else if(ilr1 <= ilr2 && irr1 >= irr2) {
            newcrl = ATappend(newcrl, cre);
          }
        }
        else {
          icre = ATgetInt((ATermInt)cre);
          if(ilr1 <= icre && icre <= irr1) 
            newcrl = ATappend(newcrl,cre);
        }
        crl = ATgetNext(crl);
      }
    }
  }
  return newcrl;
}

/*}}}  */
/*{{{  ATerm char_in_charrange_list(ATermInt cr,ATermList crl) */

ATerm char_in_charrange_list(ATermInt cr, ATermList crl)
{
  int icr, irr, ilr, icre;
  ATerm cre;
  ATermInt lr, rr;

  if(ATisEmpty(crl))
    return NULL;
  else {
    icr = ATgetInt(cr);
    while(!ATisEmpty(crl)) {
      cre = ATgetFirst(crl);
      if(IS_RANGE(cre)) {
        lr = GET_INT_ARG(cre, 0);
        rr = GET_INT_ARG(cre, 1);
        ilr = ATgetInt(lr);
        irr = ATgetInt(rr);
        if(icr >= ilr && icr <= irr)
          return (ATerm)cr;
      }
      else {
        icre = ATgetInt((ATermInt)cre);
        if(icr == icre) 
          return (ATerm)cr;
      }
      crl = ATgetNext(crl);
    }
  }
  return NULL;
}

/*}}}  */
/*{{{  ATermList charrange_intersection(ATermList cr1,ATermList cr2) */

ATermList charrange_intersection(ATermList crl1,ATermList crl2)
{
  ATerm cr1;
  ATermList newcrl = ATempty, newrange;
  ATerm newchar;

/*
ATwarning("Intersection(%t,%t) = ", crl1, crl2); 
*/

  if(ATisEmpty(crl1))
    return ATempty;
  else if(ATisEmpty(crl2))
    return ATempty;
  else {
    while(!ATisEmpty(crl1)) {
      cr1 = ATgetFirst(crl1);
      crl1 = ATgetNext(crl1);
      if(IS_RANGE(cr1)) {
        newrange = range_in_charrange_list(cr1,crl2);
        if(!ATisEmpty(newrange))
          newcrl = ATconcat(newcrl,newrange);
      }
      else {
        newchar = char_in_charrange_list((ATermInt)cr1,crl2);
        if(newchar)
          newcrl = ATappend(newcrl,newchar);
      }
    }
/*
ATwarning("%t\n", newcrl); 
*/
    return newcrl;
  }
}

/*}}}  */
/*{{{  ATerm charclass_intersection(ATerm cc1,ATerm cc2) */

ATerm charclass_intersection(ATerm cc1,ATerm cc2)
{
  ATermList newcrl = ATempty;

  if(IS_CHARCLASS(cc1) && IS_CHARCLASS(cc2))
    newcrl = charrange_intersection(GET_LIST_ARG(cc1, 0),
                                    GET_LIST_ARG(cc2, 0));
  return (ATerm)ATmakeAppl(afun_char_class, (ATerm)newcrl);
}

/*}}}  */
/*{{{  ATermList remove_range_from_charrange_list(ATerm cr,ATermList crl) */

ATermList remove_range_from_charrange_list(ATerm range,ATermList crl)
{
  int ilr1, irr1, ilr2, irr2, icre;
  ATermInt lr1, rr1, lr2, rr2;
  ATerm newcre, cre;
  ATermList newcrl = ATempty;

/*
ATwarning("range = %t and crl =%t\n", range, crl);
*/

  if(ATisEmpty(crl))
    return newcrl;
  else {
    if(IS_RANGE(range)) {
      lr1 = GET_INT_ARG(range, 0);
      rr1 = GET_INT_ARG(range, 1);
      ilr1 = ATgetInt(lr1);
      irr1 = ATgetInt(rr1);
      while(!ATisEmpty(crl)) {
        cre = ATgetFirst(crl);
        crl = ATgetNext(crl);
        if(IS_RANGE(cre)) {
          lr2 = GET_INT_ARG(cre, 0);
          rr2 = GET_INT_ARG(cre, 1);
          ilr2 = ATgetInt(lr2);
          irr2 = ATgetInt(rr2);
          if(irr2 < ilr1)
            newcrl = ATappend(newcrl, cre); 
          else if(irr1 < ilr2) {
            newcrl = ATappend(newcrl, cre); 
            newcrl = ATconcat(newcrl, crl);
            crl = ATempty;
          }
          else if(ilr1 <= ilr2) {
            if(irr1+1 == irr2) {
              newcre = (ATerm)ATmakeInt(irr2);
              newcrl = ATappend(newcrl, newcre);
            }
            else if(irr1 < irr2) {
              newcre = (ATerm)ATmakeAppl2(afun_range, 
                                         (ATerm)ATmakeInt(irr1+1),
                                         (ATerm)ATmakeInt(irr2));
              newcrl = ATappend(newcrl, newcre);
            }
          }
          else { /* ilr1 > ilr2 */
            if(ilr2+1 == ilr1) {
              newcre = (ATerm)ATmakeInt(ilr2);
              newcrl = ATappend(newcrl, newcre);
            }
            else {
              newcre = (ATerm)ATmakeAppl2(afun_range, 
                                          (ATerm)ATmakeInt(ilr2),
                                          (ATerm)ATmakeInt(ilr1-1));
              newcrl = ATappend(newcrl, newcre);
	    }
            if(irr1+1 == irr2) {
              newcre = (ATerm)ATmakeInt(irr2);
              newcrl = ATappend(newcrl, newcre);
            }
            else if(irr1 < irr2) {
              newcre = (ATerm)ATmakeAppl2(afun_range, 
                                         (ATerm)ATmakeInt(irr1+1),
                                         (ATerm)ATmakeInt(irr2));
              newcrl = ATappend(newcrl, newcre);
            }
	  }
        }
        else {
          icre = ATgetInt((ATermInt)cre);
          if(ilr1 > icre || irr1 < icre)
            newcrl = ATappend(newcrl, cre); 
        }
      }
    }
  }
  return newcrl;
}

/*}}}  */
/*{{{  ATermList remove_char_from_charrange_list(ATermInt cr,ATermList crl) */

ATermList remove_char_from_charrange_list(ATermInt cr, ATermList crl)
{
  int icr, icre, ilr, irr;
  ATerm cre, newcre;
  ATermInt lr, rr;
  ATermList newcrl = ATempty;

  if(ATisEmpty(crl))
    return newcrl;
  else {
    icr = ATgetInt(cr);
    while(!ATisEmpty(crl)) {
      cre = ATgetFirst(crl);
      crl = ATgetNext(crl);
      if(IS_RANGE(cre)) {
        lr = GET_INT_ARG(cre, 0);
        rr = GET_INT_ARG(cre, 1);
        ilr = ATgetInt(lr);
        irr = ATgetInt(rr);
        if(irr < icr)
          newcrl = ATappend(newcrl, cre); 
        else if(icr < ilr) {
          newcrl = ATappend(newcrl, cre); 
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
        }
        else {
          if(ilr != icr) {
            if(ilr+1 == icr) {
              newcre = (ATerm)ATmakeInt(ilr);
              newcrl = ATappend(newcrl, newcre);
            }
            else {
              newcre = (ATerm)ATmakeAppl2(afun_range, 
                                          (ATerm)ATmakeInt(ilr),
                                          (ATerm)ATmakeInt(icr-1));
              newcrl = ATappend(newcrl, newcre);
            }
          }
          if(irr != icr) {
            if(icr+1 == irr) {
              newcre = (ATerm)ATmakeInt(irr);
              newcrl = ATappend(newcrl, newcre);
              newcrl = ATconcat(newcrl, crl); /* return an empty set */
              crl = ATempty;
            }
            else {
              newcre = (ATerm)ATmakeAppl2(afun_range,
                                          (ATerm)ATmakeInt(icr+1),
                                          (ATerm)ATmakeInt(irr));
              newcrl = ATappend(newcrl, newcre);
              newcrl = ATconcat(newcrl, crl); /* return an empty set */
              crl = ATempty;
            }
          }
        }
      }
      else {
/*
ATwarning("cr = %t and cre = %t\n", cr, cre);
*/
        icre = ATgetInt((ATermInt)cre);
        if(icr == icre) {
          newcrl = ATconcat(newcrl, crl);
          crl = ATempty;
        }
        else {
          newcrl = ATappend(newcrl, (ATerm)cre);
        }
      }   
    }
    return newcrl;
  }
}

/*}}}  */
/*{{{  ATermList charrange_difference(ATermList cr1,ATermList cr2) */

ATermList charrange_difference(ATermList crl1,ATermList crl2)
{
  ATerm cr1;

/*
ATwarning("difference(%t,%t) = ", crl1, crl2);
*/


  if(ATisEmpty(crl1))
    return ATempty;
  else if(ATisEmpty(crl2))
    return crl1;
  else {
    while(!ATisEmpty(crl2)) {
      cr1 = ATgetFirst(crl2);
      crl2 = ATgetNext(crl2);
      if(IS_RANGE(cr1))
        crl1 = remove_range_from_charrange_list(cr1,crl1);
      else
        crl1 = remove_char_from_charrange_list((ATermInt)cr1,crl1);
    }

/*
ATwarning("%t\n", crl1);
*/

    return crl1;
  }
}

/*}}}  */
/*{{{  ATerm charclass_difference(ATerm cc1,ATerm cc2) */

ATerm charclass_difference(ATerm cc1,ATerm cc2)
{
  ATermList newcrl = ATempty;

  if(IS_CHARCLASS(cc1) && IS_CHARCLASS(cc2))
    newcrl = charrange_difference(GET_LIST_ARG(cc1, 0),
                                  GET_LIST_ARG(cc2, 0));
  return (ATerm)ATmakeAppl1(afun_char_class, (ATerm)newcrl);
}

/*}}}  */
/*{{{  ATbool is_empty_charclass(ATerm cc) */

ATbool is_empty_charclass(ATerm cc)
{
  return ATisEqual(cc,
                   (ATerm)ATmakeAppl1(afun_char_class, (ATerm)ATempty));
}

/*}}}  */
/*{{{  ATbool range_subset_charrange_list(ATerm cr,ATermList crl) */

ATbool range_subset_charrange_list(ATerm range, ATermList crl)
{
  int ilr1, irr1, ilr2, irr2, icre;
  ATermInt lr1, rr1, lr2, rr2;
  ATerm cre;

/*ATwarning("range = %t and crl = %t\n", range, crl);*/

  if(ATisEmpty(crl))
    return ATfalse;
  else {
    if(IS_RANGE(range)) {
      lr1 = GET_INT_ARG(range, 0);
      rr1 = GET_INT_ARG(range, 1);
      ilr1 = ATgetInt(lr1);
      irr1 = ATgetInt(rr1);

      while(!ATisEmpty(crl)) {
        cre = ATgetFirst(crl);
        if(IS_RANGE(cre)) {
  	  lr2 = GET_INT_ARG(cre, 0);
	  rr2 = GET_INT_ARG(cre, 1);
          ilr2 = ATgetInt(lr2);
          irr2 = ATgetInt(rr2);
          if(ilr1 >= ilr2 && irr1 <= irr2)
            return ATtrue;
        }
        else {
          icre = ATgetInt((ATermInt)cre);
          if(ilr1 <= icre && icre <= irr1)
            return ATtrue;
        }
        crl = ATgetNext(crl);
      }
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool char_subset_charrange_list(ATermInt cr,ATermList crl) */

ATbool char_subset_charrange_list(ATermInt cr, ATermList crl)
{
  int icr, irr, ilr, icre;
  ATerm cre;
  ATermInt lr, rr;

  if(ATisEmpty(crl))
    return ATfalse;
  else {
    icr = ATgetInt(cr);
    while(!ATisEmpty(crl)) {
      cre = ATgetFirst(crl);
      if(IS_RANGE(cre)) {
	lr = GET_INT_ARG(cre, 0);
	rr = GET_INT_ARG(cre, 1);
        irr = ATgetInt(rr);
        ilr = ATgetInt(lr);
        if(icr >= ilr && icr <= irr)
          return ATtrue;
      }
      else {
        icre = ATgetInt((ATermInt)cre);
        if(icr == icre)
          return ATtrue;
      }
      crl = ATgetNext(crl);
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool charrange_subset(ATermList crl1, ATermList crl2) */

ATbool charrange_subset(ATermList crl1, ATermList crl2)
{
  ATbool result = ATtrue;
  ATerm cr1;
  
  if(ATisEmpty(crl1) && !ATisEmpty(crl2))
    return ATtrue;
  else if(!ATisEmpty(crl1) && ATisEmpty(crl2))
    return ATfalse;
  else {
    while(!ATisEmpty(crl1) && result) {
      cr1 = ATgetFirst(crl1);
      crl1 = ATgetNext(crl1);
      if(IS_RANGE(cr1)) {
        result = range_subset_charrange_list(cr1,crl2);
      }
      else
        result = char_subset_charrange_list((ATermInt)cr1,crl2);
    }
    return result;
  }
}

/*}}}  */
/*{{{  ATbool charclass_subset(ATerm cc1, ATerm cc2) */

ATbool charclass_subset(ATerm cc1, ATerm cc2)
{
  if(ATisEqual(cc1, cc2))
    return ATtrue;
  else {
    if(IS_CHARCLASS(cc1) && IS_CHARCLASS(cc2)) 
      return charrange_subset(GET_LIST_ARG(cc1, 0),
                              GET_LIST_ARG(cc2, 0));
    else
      return ATfalse;
  }
}

/*}}}  */
