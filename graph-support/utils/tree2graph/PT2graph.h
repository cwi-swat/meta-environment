#ifndef _PT2GRAPH_H
#define _PT2GRAPH_H

#include "Graph.h"

Graph PT_printAnyToGraph(char *name, ATerm term, ATbool characters,
                         ATbool productions,
                         ATbool layout, ATbool literals);
Graph PT_printParseTreeToGraph(char *name, PT_ParseTree parsetree,
                             ATbool characters,
                             ATbool productions, ATbool layout,
                             ATbool literals);
Graph PT_printTreeToGraph(char *name, PT_Tree tree, ATbool characters,
                          ATbool productions,
                          ATbool layout, ATbool literals);
#endif
