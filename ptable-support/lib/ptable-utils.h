/* $Id$ */

#include <ptable.h>

PT_Production PTA_LookUpProduction(PTA_ParseTable pt, int label);
int PTAgetGotosLength(PTA_Gotos gotos);
int PTAgetActionsLength(PTA_Actions actions);
int PTAgetLabelsLength(PTA_Labels labels);
int PTAgetStatesLength(PTA_States states);
