#include "SDFME-utils.h"

/*{{{  ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName) */

ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName)
{
  SDF_ModuleId modid = SDF_getModuleNameModuleId(moduleName);
  char *lex = SDF_getModuleIdString(modid);
  ATerm result = ATmake("<str>", lex);

  free(lex);

  return result;
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
  return SDF_makeOptLayoutPresent(" ");
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeLayoutNewline() */

SDF_OptLayout SDF_makeLayoutNewline()
{
  return SDF_makeOptLayoutPresent("\n");
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
