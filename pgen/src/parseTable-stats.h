/* $Id$ */

#ifndef __PARSETABLESTATS_H__
#define __PARSETABLESTATS_H__

void PGEN_initParseTableStats();
int  PGEN_getNumberOfActions();
void PGEN_increaseNumberOfActions(int value);
int  PGEN_getNumberOfGotos();
void PGEN_increaseNumberOfGotos(int value);
int  PGEN_getNumberOfItems();
void PGEN_increaseNumberOfItems(int value);
void PGEN_printStats();

#endif /* __PARSETABLESTATS_H__ */
