#include "SDFME-utils.h"

SDF_Import SDFmakeImport(char *moduleName)
{
  return SDF_makeImportModule(
           SDF_makeModuleNameUnparameterized(
	     SDF_makeModuleIdWord(SDF_makeCHARLISTString(moduleName))));
}

SDF_ImportList SDF_concatImportList(SDF_ImportList l1,
                                    SDF_ImportList l2)
{
  if (!SDF_isImportListEmpty(l2)) {
    if (SDF_hasImportListHead(l1)) {
      SDF_Import head = SDF_getImportListHead(l1);
      if (SDF_hasImportListTail(l1)) {
        SDF_ImportList tail = SDF_getImportListTail(l1);

        return SDF_makeImportListMany(head, 
                 SDF_makeLayoutEmpty(),
                 SDF_concatImportList(tail, l2));
      }
      else {
        return SDF_makeImportListMany(head, 
                 SDF_makeLayoutEmpty(), l2);
      }
    }
    else {
      return l2;
    }
  }          

  return l1;
}

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

SDF_Production SDF_removeAttributes(SDF_Production prod)
{
  SDF_Attributes emptyAttrs = SDF_makeAttributesNoAttrs();
  return SDF_setProductionAttributes(prod, emptyAttrs);
}

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

SDF_OptLayout SDF_makeLayoutEmpty()
{
  return SDF_makeOptLayoutAbsent();
}

SDF_OptLayout SDF_makeLayoutSpace()
{
  return SDF_makeOptLayoutPresent(SDF_makeCHARLISTString(" "));
}

SDF_OptLayout SDF_makeLayoutNewline()
{
  return SDF_makeOptLayoutPresent(SDF_makeCHARLISTString("\n"));
}

ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName)
{
  SDF_ModuleId   modid   = SDF_getModuleNameModuleId(moduleName);
  char          *lex     = SDF_getCHARLISTString(SDF_getModuleIdChars(modid));
  return ATmake("<str>", lex);
}

SDF_Module SDF_addModuleImport(SDF_Module module, SDF_Import import)
{
  SDF_OptLayout s = SDF_makeLayoutSpace();
  SDF_OptLayout nl = SDF_makeLayoutNewline();

  SDF_ImpSectionList list = SDF_getModuleList(module);
  SDF_ImportList ilist = SDF_makeImportListSingle(import);
  SDF_Imports imports = SDF_makeImportsDefault(ilist);
  SDF_ImpSection section = SDF_makeImpSectionImports(s, imports);
  
  list = SDF_makeImpSectionListMany(section, nl, list);

  return SDF_setModuleList(module, list);
}
