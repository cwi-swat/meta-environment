/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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

*/
#include "ksdf2table.h"

extern ATermTable priority_table;

/*{{{ ATbool pgen_cnf(ATerm prodnr1, int iptr, int len, ATerm prodnr2) */

ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2)
{
  ATerm priorel, entry;

  if(iptr == 0) {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_right_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                     (ATerm)prodnr1, (ATerm)prodnr2);
        entry = ATtableGet(priority_table,priorel);
        if(entry)
          return ATtrue;
        else {
          priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio,
                                       (ATerm)prodnr1, (ATerm)prodnr2);
          entry = ATtableGet(priority_table,priorel);
          if(entry)
            return ATtrue;
          else
            return ATfalse;
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else
        return ATfalse;
    }
  }
  else {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_left_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                     (ATerm)prodnr1, (ATerm)prodnr2);
        entry = ATtableGet(priority_table,priorel);
        if(entry)
          return ATtrue;
        else {
          priorel = (ATerm)ATmakeAppl2(afun_assoc_prio,
                                       (ATerm)prodnr1, (ATerm)prodnr2);
          entry = ATtableGet(priority_table,priorel);
          if(entry)
            return ATtrue;
          else {
            priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio,
                                         (ATerm)prodnr1, (ATerm)prodnr2);
            entry = ATtableGet(priority_table,priorel);
            if(entry)
              return ATtrue;
            else
              return ATfalse;
          }
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio,
                                   (ATerm)prodnr1, (ATerm)prodnr2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else
        return ATfalse;
    }
  }
}

/*}}} */
