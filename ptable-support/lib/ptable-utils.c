/* $Id$ */

#include <ptable-utils.h>

PTBL_Production PTBL_LookUpProduction(PTBL_ParseTable pt, int label) {
  PTBL_Labels labels = PTBL_getParseTableLabels(pt);
  ATermInt num = ATmakeInt(label);
  PTBL_Label head;

  for (; !PTBL_isLabelsEmpty(labels); labels = PTBL_getLabelsTail(labels)) {
    head = PTBL_getLabelsHead(labels);
   
    if (ATisEqual(PTBL_getLabelNumber(head), num)) {
     return PTBL_getLabelProduction(head);
    } 
  }

  ATwarning("PTBL_LookUpProduction: production %d not found\n", label);
  return NULL;
}
