/*

    MEPT -- The Meta-Environment Parse Tree library

    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

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

   $Id$
*/         

#ifndef _ME_PT_H
#define _ME_PT_H

#include <aterm2.h>
#include <deprecated.h>

void   PT_initMEPTApi(void);

ATerm PT_makeParseTreeTree(ATerm tree, ATerm cnt);
ATerm PT_makeTreeAppl(ATerm prod, ATermList args);
ATerm PT_makeSymbolLit(char *str);
ATerm PT_makeSymbolLex(ATerm arg);
ATerm PT_makeSymbolCf(ATerm arg);
ATerm PT_makeSymbolOpt(ATerm arg);
ATerm PT_makeSymbolSort(ATerm arg);
ATerm PT_makeSymbolLayout();

ATbool PT_isParseTreeTree(ATerm arg);
ATbool PT_isTreeAppl(ATerm arg);
ATbool PT_isProductionDefault(ATerm arg);
ATbool PT_isSymbolLit(ATerm arg);
ATbool PT_isSymbolLex(ATerm arg);
ATbool PT_isSymbolCf(ATerm arg);
ATbool PT_isSymbolOpt(ATerm arg);
ATbool PT_isSymbolSort(ATerm arg);
ATbool PT_isSymbolLayout(ATerm arg);

ATerm     PT_getParseTreeTree(ATerm arg);
ATerm     PT_getParseTreeAmbCnt(ATerm arg);
ATerm     PT_getTreeProd(ATerm arg);
ATermList PT_getTreeArgs(ATerm arg);
ATerm     PT_getProductionRhs(ATerm arg);
char     *PT_getLitString(ATerm arg);
ATerm     PT_getLexSymbol(ATerm arg);
ATerm     PT_getCfSymbol(ATerm arg);
ATerm     PT_getOptSymbol(ATerm arg);
ATerm     PT_getSortSymbol(ATerm arg);

ATbool PT_prodHasLitAsRhs(ATerm arg);
ATbool PT_prodHasLexSortAsRhs(ATerm arg);
ATbool PT_prodHasLexLayoutAsRhs(ATerm arg);
ATbool PT_prodHasCfLayoutAsRhs(ATerm arg);
ATbool PT_prodHasCfOptLayoutAsRhs(ATerm arg);

#endif /* _ME_PT_H */ 
