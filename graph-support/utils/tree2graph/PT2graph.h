#ifndef _PT2GRAPH_H
#define _PT2GRAPH_H

#include "Graph.h"

Graph PT_printAnyToGraph(const char *name, ATerm term, ATbool characters,
                         ATbool productions,
                         ATbool layout, ATbool literals, ATbool sharing);
Graph PT_printParseTreeToGraph(const char *name, PT_ParseTree parsetree,
                             ATbool characters,
                             ATbool productions, ATbool layout,
                             ATbool literals, ATbool sharing);
Graph PT_printTreeToGraph(const char *name, PT_Tree tree, ATbool characters,
                          ATbool productions,
                          ATbool layout, ATbool literals, ATbool sharing);
#endif
