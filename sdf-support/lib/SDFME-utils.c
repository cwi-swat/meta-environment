#include "SDFME-utils.h"

/*{{{  ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName) */

ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName)
{
  SDF_ModuleId   modid   = SDF_getModuleNameModuleId(moduleName);
  char          *lex     = SDF_getCHARLISTString(SDF_getModuleIdChars(modid));
  return ATmake("<str>", lex);
}

/*}}}  */

/*{{{  SDF_ProductionList SDF_concatProductionList(SDF_ProductionList l1, */

SDF_ProductionList SDF_concatProductionList(SDF_ProductionList l1,
                                            SDF_ProductionList l2)
{
  if (!SDF_isProductionListEmpty(l2)) {
    if (SDF_hasProductionListHead(l1)) {
      SDF_Production head = SDF_getProductionListHead(l1);
      if (SDF_hasProductionListTail(l1)) {
        SDF_ProductionList tail = SDF_getProductionListTail(l1);

        return SDF_makeProductionListMany(head, 
                 SDF_makeLayoutEmpty(),
                 SDF_concatProductionList(tail, l2));
      }
      else {
        return SDF_makeProductionListMany(head, 
                 SDF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  }          

  return l1;
}

/*}}}  */
/*{{{  SDF_PriorityList SDF_concatPriorityList(SDF_PriorityList l1, */

SDF_PriorityList SDF_concatPriorityList(SDF_PriorityList l1,
                                            SDF_PriorityList l2)
{
  if (!SDF_isPriorityListEmpty(l2)) {
    if (SDF_hasPriorityListHead(l1)) {
      SDF_Priority head = SDF_getPriorityListHead(l1);
      if (SDF_hasPriorityListTail(l1)) {
        SDF_PriorityList tail = SDF_getPriorityListTail(l1);

        return SDF_makePriorityListMany(head, 
                 SDF_makeLayoutEmpty(), 
                 ",", 
                 SDF_makeLayoutEmpty(),
                 SDF_concatPriorityList(tail, l2));
      }
      else {
        return SDF_makePriorityListMany(head, 
                 SDF_makeLayoutEmpty(), 
                 ",", 
                 SDF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  }          

  return l1;
}

/*}}}  */
/*{{{  SDF_RestrictionList SDF_concatRestrictionList(SDF_RestrictionList l1, */

SDF_RestrictionList SDF_concatRestrictionList(SDF_RestrictionList l1,
                                            SDF_RestrictionList l2)
{
    if (!SDF_isRestrictionListEmpty(l2)) {
    if (SDF_hasRestrictionListHead(l1)) {
      SDF_Restriction head = SDF_getRestrictionListHead(l1);
      if (SDF_hasRestrictionListTail(l1)) {
        SDF_RestrictionList tail = SDF_getRestrictionListTail(l1);

        return SDF_makeRestrictionListMany(head, 
                 SDF_makeLayoutEmpty(),
                 SDF_concatRestrictionList(tail, l2));
      }
      else {
        return SDF_makeRestrictionListMany(head, SDF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  }          

  return l1;
}

/*}}}  */

/*{{{  SDF_Production SDF_removeAttributes(SDF_Production prod) */

SDF_Production SDF_removeAttributes(SDF_Production prod)
{
  SDF_Attributes emptyAttrs = SDF_makeAttributesNoAttrs();
  return SDF_setProductionAttributes(prod, emptyAttrs);
}

/*}}}  */
/*{{{  ATbool SDF_hasRejectAttribute(SDF_Production prod) */

ATbool SDF_hasRejectAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributeReject(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */
/*{{{  ATbool SDF_hasPreferAttribute(SDF_Production prod) */

ATbool SDF_hasPreferAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributePrefer(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */
/*{{{  ATbool SDF_hasAvoidAttribute(SDF_Production prod) */

ATbool SDF_hasAvoidAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributeAvoid(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */

/*{{{  SDF_OptLayout SDF_makeLayoutEmpty() */

SDF_OptLayout SDF_makeLayoutEmpty()
{
  return SDF_makeOptLayoutAbsent();
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeLayoutSpace() */

SDF_OptLayout SDF_makeLayoutSpace()
{
  return SDF_makeOptLayoutPresent(SDF_makeCHARLISTString(" "));
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeLayoutNewline() */

SDF_OptLayout SDF_makeLayoutNewline()
{
  return SDF_makeOptLayoutPresent(SDF_makeCHARLISTString("\n"));
}

/*}}}  */

/*{{{  SDF_Symbol SDF_removeSymbolAnnotations(SDF_Symbol s) */

SDF_Symbol SDF_removeSymbolAnnotations(SDF_Symbol s)
{
  return SDF_SymbolFromTerm(ATremoveAllAnnotations(SDF_SymbolToTerm(s)));
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_removeModuleIdAnnotations(SDF_ModuleId s) */

SDF_ModuleId SDF_removeModuleIdAnnotations(SDF_ModuleId s)
{
  return SDF_ModuleIdFromTerm(ATremoveAllAnnotations(SDF_ModuleIdToTerm(s)));
}

/*}}}  */
/*{{{  SDF_Import SDF_removeImportAnnotations(SDF_Import s) */

SDF_Import SDF_removeImportAnnotations(SDF_Import s)
{
  return SDF_ImportFromTerm(ATremoveAllAnnotations(SDF_ImportToTerm(s)));
}

/*}}}  */
/*{{{  SDF_ImportList SDF_removeImportListAnnotations(SDF_ImportList l) */

SDF_ImportList SDF_removeImportListAnnotations(SDF_ImportList l)
{
  return SDF_ImportListFromTerm(ATremoveAllAnnotations(SDF_ImportListToTerm(l)));
}

/*}}}  */

/*{{{  SDF_RenamingList SDF_reverseRenamingList(SDF_RenamingList l)  */

SDF_RenamingList SDF_reverseRenamingList(SDF_RenamingList l) 
{
  return SDF_RenamingListFromTerm((ATerm) 
			   ATreverse((ATermList) SDF_RenamingListToTerm(l)));

}

/*}}}  */
/*{{{  SDF_RenamingList SDF_insertRenaming(SDF_Renaming r, SDF_RenamingList l) */

SDF_RenamingList SDF_insertRenaming(SDF_Renaming r, SDF_RenamingList l)
{
  if (SDF_isRenamingListEmpty(l)) {
    return SDF_makeRenamingListSingle(r);
  }
  else {
    return SDF_makeRenamingListMany(r, SDF_makeLayoutSpace(), l);
  }
}

/*}}}  */
/*{{{  SDF_RenamingList SDF_concatRenamingList(SDF_RenamingList l1, SDF_RenamingList l2) */

SDF_RenamingList SDF_concatRenamingList(SDF_RenamingList l1, SDF_RenamingList l2)
{
  SDF_RenamingList reversed = SDF_reverseRenamingList(l1);
  SDF_RenamingList result = l2;

  while (!SDF_isRenamingListEmpty(reversed)) {
    SDF_Renaming renaming = SDF_getRenamingListHead(reversed);

    result = SDF_insertRenaming(renaming, result);

    if (SDF_hasRenamingListTail(reversed)) {
      reversed = SDF_getRenamingListTail(reversed);
    }
    else {
      break;
    }
  }

  return result;
}

/*}}}  */

/*{{{  SDF_SymbolList SDF_reverseSymbolList(SDF_SymbolList l)  */

SDF_SymbolList SDF_reverseSymbolList(SDF_SymbolList l) 
{
  return SDF_SymbolListFromTerm((ATerm) 
			   ATreverse((ATermList) SDF_SymbolListToTerm(l)));

}

/*}}}  */
/*{{{  SDF_SymbolList SDF_insertSymbol(SDF_Symbol r, SDF_SymbolList l) */

SDF_SymbolList SDF_insertSymbol(SDF_Symbol r, SDF_SymbolList l)
{
  if (SDF_isSymbolListEmpty(l)) {
    return SDF_makeSymbolListSingle(r);
  }
  else {
    return SDF_makeSymbolListMany(r, SDF_makeLayoutSpace(), l);
  }
}

/*}}}  */


