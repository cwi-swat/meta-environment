

/* $Id$ */

#include <ptable.h>

PT_Production PTA_LookUpProduction(PTA_ParseTable pt, int label)
{
  PTA_Labels labels = PTA_getParseTableLabels(pt);
  ATermInt num = ATmakeInt(label);
  PTA_Label head;

  for (; !PTA_isLabelsEmpty(labels); labels = PTA_getLabelsTail(labels)) {
    head = PTA_getLabelsHead(labels);
   
    if (ATisEqual(PTA_getLabelNumber(head), num)) {
     return PTA_getLabelProduction(head);
    } 
  }

  ATwarning("PTA_LookUpProduction: production %d not found\n", label);
  return NULL;
}

int PTAgetGotosLength(PTA_Gotos gotos)
{
  return ATgetLength((ATermList)PTA_makeTermFromGotos(gotos));
}

int PTAgetActionsLength(PTA_Actions actions)
{
  return ATgetLength((ATermList)PTA_makeTermFromActions(actions));
}

int PTAgetStatesLength(PTA_States states) 
{
  return ATgetLength((ATermList)PTA_makeTermFromStates(states));
}

int PTAgetLabelsLength(PTA_Labels labels)
{
  return ATgetLength((ATermList)PTA_makeTermFromLabels(labels));
}
