#include "SDFME-utils.h"
#include <MEPT-utils.h>

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

SDF_Layout SDF_makeLayoutEmpty()
{
  return (SDF_Layout)PT_makeTermFromTree(PT_makeTreeLayoutEmpty());
}
