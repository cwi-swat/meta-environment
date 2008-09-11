#ifndef _PT2RELATION_H
#define _PT2RELATION_H

#include "RStore.h"

RS_RStore PT_printAnyToRelation(ATerm term, ATbool characters,
                         ATbool productions,
                         ATbool layout, ATbool literals, ATbool sharing);
RS_RStore PT_printParseTreeToRelation(PT_ParseTree parsetree,
                             ATbool characters,
                             ATbool productions, ATbool layout,
                             ATbool literals, ATbool sharing);
RS_RStore PT_printTreeToRelation(PT_Tree tree, ATbool characters,
                          ATbool productions,
                          ATbool layout, ATbool literals, ATbool sharing);
#endif
