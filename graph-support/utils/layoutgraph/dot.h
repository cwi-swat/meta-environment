
#ifndef DOT_H
#define DOT_H

#include "Graph.h"

typedef enum {
  UNDIRECTED=0,
  DIRECTED,
} edge_direction;

typedef union {
  char *string;
  edge_direction direction;
  NodeId nodeId;
  ATermList attributes;
} yystype;

#define YYSTYPE yystype   /* Yacc stack entries */
extern YYSTYPE yylval;

void yyerror(char*);
int yylex(void);

int yyparse();

void protectTerm(ATerm term);
AFun getAttributeType(Attribute attr);
void mergeNodeAttributes(NodeId nodeId, AttributeList attrs);
void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs);

#endif

