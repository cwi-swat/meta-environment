#ifndef _PT2GRAPH_H
#define _PT2GRAPH_H

#include "Graph.h"

Graph PT_printAnyToGraph(ATerm term, ATbool characters,
                         ATbool productions,
                         ATbool layout, ATbool literals);
Graph PT_printParseTreeToGraph(PT_ParseTree parsetree,
                             ATbool characters,
                             ATbool productions, ATbool layout,
                             ATbool literals);
Graph PT_printTreeToGraph(PT_Tree tree, ATbool characters,
                          ATbool productions,
                          ATbool layout, ATbool literals);
#endif
