/* Syntax for dot graphs, subgraphs are not supported!
 * vim:ts=2
 */


%{
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Graph.h"
#include "dot.h"
#include "layoutgraph.h"

static ATermList buildDotAttributes(NodeId key, NodeId value, ATermList attrs);
static AttributeList buildAttributeList(int type,ATermList dotAttributes);
static NodeId buildNodeId(char *id);

%}

%token DIGRAPH
%token EDGE
%token GRAPH
%token NODE
%token STRICT
%token SUBGRAPH
%token INT
%token ID
%token EDGEOP

%start graph
%%
graph:
	opt_strict graph_or_digraph opt_id '{' stmt_list '}' { }
	;

opt_strict:
	{ }
	| STRICT { }
	;

graph_or_digraph:
	GRAPH { }
	| DIGRAPH { }
	;

opt_id:
	{ }
	| ID { }
	;

stmt_list:
	{ }
	| stmt opt_semi stmt_list { }
	;

opt_semi:
	{ }
	| ';' { }
	;

stmt:
	node_stmt { }
	| edge_stmt { }
	| attr_stmt { }
	| ID '=' ID { }
	;

attr_stmt:
  GRAPH attr_list  { mergeGraphAttributes(buildAttributeList(GRAPH,
                                                             $2.attributes)); }
  | NODE attr_list { }
  | EDGE attr_list { };

opt_attr_list:
	{ $$.attributes = ATempty; }
	| attr_list { $$.attributes = $1.attributes; }
	;

attr_list:
	'[' opt_a_list ']' opt_attr_list {
		if (!ATisEmpty($4.attributes)) {
			yyerror("extra attribute list not supported");
		}
		$$.attributes = $2.attributes;
	}
	;

opt_a_list:
	{ $$.attributes = ATempty; }
	| a_list { $$.attributes = $1.attributes; }
	;

a_list:
	ID opt_value opt_comma opt_a_list {
		$$.attributes = buildDotAttributes(buildNodeId($1.string), $2.nodeId, $4.attributes);
	}

	;

opt_value:
	{ $$.nodeId = buildNodeId(strdup("true")); }
	| '=' ID { $$.nodeId = buildNodeId($2.string); }
	;

opt_comma:
	{ }
	| ',' { }
	;

node_stmt:
	node_id opt_attr_list {
		mergeNodeAttributes($1.nodeId, buildAttributeList(NODE,$2.attributes));
	}
	;

edge_stmt:
	node_id edge_rhs opt_attr_list {
		addEdge($1.nodeId, $2.nodeId, buildAttributeList(EDGE,$3.attributes));
	}
	;

node_id:
	ID opt_port { $$.nodeId = buildNodeId($1.string); }
	;

opt_port:
	{ }
	| port { }
	;

port:
	port_location opt_port_angle { }
	| port_angle opt_port_location { }
	;

opt_port_location:
	{ }
	| port_location { }
	;

port_location:
	':' ID { }
	| ':' '(' ID ',' ID ')' { }
	;

opt_port_angle:
	{ }
	| port_angle { }
	;

port_angle:
	'@' ID { }
	;

opt_edge_rhs:
	{ }
	| edge_rhs { yyerror("multiple edges not supported"); }
	;

edge_rhs:
	EDGEOP node_id opt_edge_rhs { $$.nodeId = $2.nodeId; }
	;

%%


static int inchToPixel(float inches)
{
  return (int)(inches*72.0+0.5);
}

static Point parsePoint(char *s)
{
  int x, y;
  char *ptr = strchr(s, ',');

  assert(ptr);
  *ptr = '\0';
  x = atoi(s);
  y = atoi(ptr+1);
  *ptr = ',';

	return makePointDefault(x, y);
}

static Polygon parseCoordinateList(char *coords, ATbool endToBegin)
{
  char *token;
	Polygon poly = makePolygonEmpty();
	Point last = NULL;

	token = strtok(coords, " ");
	if (endToBegin) {
    last = parsePoint(token);
		token = strtok(NULL, " ");
		assert(token);
	}
	do {
    Point point = parsePoint(token);
		poly = makePolygonMulti(point, poly);
	} while ((token = strtok(NULL, " ")));
  
  if (endToBegin) {
	  poly = makePolygonMulti(last, poly);
  }

  if (endToBegin) {
		return PolygonFromTerm((ATerm)ATreverse((ATermList)PolygonToTerm(poly)));
  }
  else {
    return poly;
  }
}

static Attribute parseBoundaries(char *coords)
{
  char *token;
  Point p1, p2;
  int x,y;

	token = strtok(coords, ",");
  assert(token);
  x = atoi(token);

	token = strtok(NULL, ",");
  assert(token);
  y = atoi(token);

  p1 = makePointDefault(x,y);

	token = strtok(NULL, ",");
  assert(token);
  x = atoi(token);

	token = strtok(NULL, ",");
  assert(token);
  y = atoi(token);

  p2 = makePointDefault(x,y);

  return makeAttributeBoundingBox(p1,p2);
}

static AttributeList buildAttributeList(int type, ATermList dotAttributes)
{
  AttributeList list = makeAttributeListEmpty();
	int width = -1, height = -1;

	/*ATwarning("dotAttributes=%t\n", dotAttributes); */
  while (!ATisEmpty(dotAttributes)) {
    ATermList pair = (ATermList)ATgetFirst(dotAttributes);
		ATerm key = ATgetFirst(pair);
		ATerm value = ATgetFirst(ATgetNext(pair));
		char *sval = ATgetName(ATgetAFun((ATermAppl)value));
		/* ATwarning("key=%t, value=%s\n", key, sval);  */

    if (ATisEqual(key, ATparse("\"bb\""))) {
       Attribute attr = parseBoundaries(sval);
			 list = makeAttributeListMulti(attr, list);
    }
		else if (ATisEqual(key, ATparse("\"width\""))) {
      width = inchToPixel(atof(sval));
		} else if (ATisEqual(key, ATparse("\"height\""))) {
      height = inchToPixel(atof(sval));
		} else if (ATisEqual(key, ATparse("\"shape\""))) {
      Shape shape = ShapeFromTerm(ATparse(sval));
      list = makeAttributeListMulti(makeAttributeShape(shape), list);
		}
    else if (ATisEqual(key, ATparse("\"dir\""))) {
      Direction dir = DirectionFromTerm(ATparse(sval));
      list = makeAttributeListMulti(makeAttributeDirection(dir), list);
		} else if (ATisEqual(key, ATparse("\"pos\""))) {
      if (sval[0] == 'e') {
        /* List of coordinates, last element first but the rest in order */
        Attribute attr = makeAttributeCurvePoints(
                           parseCoordinateList(sval+2, ATtrue));
				list = makeAttributeListMulti(attr, list);
			} else if (sval[0] == 's') {
        /* List of coordinates, all in order */
        Attribute attr = makeAttributeCurvePoints(
                           parseCoordinateList(sval+2, ATfalse));
				list = makeAttributeListMulti(attr, list);
			} else {
        if (type == NODE) {
					/* x,y pair */
					char *sep = strchr(sval, ',');
					int x, y;
					assert(sep);

					*sep = '\0';
					x = atoi(sval);
					*sep++ = ',';
					y = atoi(sep);
					list = makeAttributeListMulti(makeAttributeLocation(x, y), list);
				}
        else {
          Attribute attr = makeAttributeCurvePoints(
                             parseCoordinateList(sval, ATfalse));
				  list = makeAttributeListMulti(attr, list);
        }

			}
		}

		dotAttributes = ATgetNext(dotAttributes);
	}

	if (width != -1 && height != -1) {
    list = makeAttributeListMulti(makeAttributeSize(width, height), list);
	}

	return list;
}

static ATermList
buildDotAttributes(NodeId key, NodeId value, ATermList attrs)
{
  ATermList result = ATinsert(attrs, (ATerm)ATmakeList2(NodeIdToTerm(key),
													NodeIdToTerm(value)));
	protectTerm((ATerm)result);

	return result;
}

static NodeId buildNodeId(char *id)
{
  NodeId nodeId = makeNodeIdDefault(id);

  free(id);
	protectTerm(NodeIdToTerm(nodeId));

  return nodeId;
}

void yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  exit(1);
}

#ifndef HAVE_YYWRAP
int yywrap()
{
  return 1;
}
#endif

