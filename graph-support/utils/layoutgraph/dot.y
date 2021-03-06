/* Syntax for dot graphs, subgraphs are not supported!
 * vim:ts=2
 */

%{
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "Graph.h"
#include "dot.h"
#include "layout.h"

#define YYERROR_VERBOSE

static ATermList appendKeyValue(char *key, char *value, ATermList attrs);
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
%token CBO
%token CBC

%start graph
%%
graph:
	opt_strict graph_or_digraph opt_id CBO stmt_list CBC { 
    mergeNodeAttributes(makeNodeIdDefault(ATparse("graph")), 
                        buildAttributeList(GRAPH, $5.attributes));
  }
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
	{ $$.nodeId = buildNodeId("default"); }
	| ID { $$.nodeId = buildNodeId($1.string);}
	;

stmt_list:
	stmt opt_semi { $$.attributes = $1.attributes; }
  |				
	stmt_list stmt opt_semi { $$.attributes = ATconcat($1.attributes,
                                                     $2.attributes); }
	;

opt_semi:
	{ }
	| ';' { }
	;

stmt:
	node_stmt { $$.attributes = ATempty;}
	| edge_stmt { $$.attributes = ATempty;}
	| attr_stmt { $$.attributes = $1.attributes; }
  | subgraph_stmt {$$.attributes = ATempty; }
  | CBO stmt_list CBC { $$.attributes = $2.attributes; }
	| ID '=' ID { $$.attributes = ATempty;}
	;

attr_stmt:
  GRAPH attr_list  { $$.attributes = $2.attributes; }
  | NODE attr_list { $$.attributes = ATempty;}
  | EDGE attr_list { $$.attributes = ATempty;}
  ;

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
		$$.attributes = appendKeyValue($1.string, $2.string, $4.attributes);
	}

	;

opt_value:
	{ $$.string = strdup("true"); }
	| '=' ID { $$.string = $2.string; }
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
		mergeEdgeAttributes($1.nodeId, $2.nodeId, buildAttributeList(EDGE,$3.attributes));
	}
	;

subgraph_stmt:
  SUBGRAPH opt_id CBO stmt_list CBC { mergeNodeAttributes($2.nodeId, 
                                      buildAttributeList(GRAPH, $4.attributes)); }

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
		poly = makePolygonMany(point, poly);
	} while ((token = strtok(NULL, " ")));
  
  if (endToBegin) {
	  poly = makePolygonMany(last, poly);
  }

	return reversePolygon(poly);
}

static Attribute parseBoundaries(char *coords)
{
  char *token;
  Point p1, p2;
  int x,y;

	token = strtok(coords, ",");
  if (token == NULL) {
    return NULL;
  }
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

static Color parseColor(const char *rgb)
{
  int r, g, b;

	if (sscanf(rgb, "#%2x%2x%2x", &r, &g, &b) != 3) {
	  ATabort("parseColor: got invalid rgb specification: %s\n", rgb);
	}

  return makeColorRgb(r, g, b);
}

static AttributeList buildAttributeList(int type, ATermList dotAttributes)
{
  AttributeList list = makeAttributeListEmpty();
	int width = -1, height = -1;

	/*ATwarning("dotAttributes=%t\n", dotAttributes);*/
  while (!ATisEmpty(dotAttributes)) {
    ATermList pair = (ATermList)ATgetFirst(dotAttributes);
		ATerm key = ATgetFirst(pair);
		ATerm value = ATgetFirst(ATgetNext(pair));
		char *sval = ATgetName(ATgetAFun((ATermAppl)value));

		/*ATwarning("key=%t, value=%s\n", key, sval);*/

    if (ATisEqual(key, ATparse("\"bb\""))) {
       Attribute attr = parseBoundaries(sval);
       if (attr != NULL) {
			   list = makeAttributeListMany(attr, list);
       }
    }
		else if (ATisEqual(key, ATparse("\"fillcolor\""))) {
			Color color = parseColor(sval);
			list = makeAttributeListMany(makeAttributeFillColor(color), list);
		}
		else if (ATisEqual(key, ATparse("\"color\""))) {
			Color color = parseColor(sval);
			list = makeAttributeListMany(makeAttributeColor(color), list);
		}
		else if (ATisEqual(key, ATparse("\"style\""))) {
		  Style style = StyleFromTerm(ATparse(sval));
			list = makeAttributeListMany(makeAttributeStyle(style), list);
		}
		else if (ATisEqual(key, ATparse("\"width\""))) {
      width = inchToPixel(atof(sval));
		}
		else if (ATisEqual(key, ATparse("\"height\""))) {
      height = inchToPixel(atof(sval));
		}
		else if (ATisEqual(key, ATparse("\"shape\""))) {
      Shape shape = ShapeFromTerm(ATparse(sval));
      list = makeAttributeListMany(makeAttributeShape(shape), list);
		}
    else if (ATisEqual(key, ATparse("\"dir\""))) {
      Direction dir = DirectionFromTerm(ATparse(sval));
      list = makeAttributeListMany(makeAttributeDirection(dir), list);
		}
		else if (ATisEqual(key, ATparse("\"pos\""))) {
      if (sval[0] == 'e') {
        /* List of coordinates, last element first but the rest in order */
        Attribute attr = makeAttributeCurvePoints(
                           parseCoordinateList(sval+2, ATtrue));
				list = makeAttributeListMany(attr, list);
			}
			else if (sval[0] == 's') {
        /* List of coordinates, all in order */
        Attribute attr = makeAttributeCurvePoints(
                           parseCoordinateList(sval+2, ATfalse));
				list = makeAttributeListMany(attr, list);
			}
			else {
        if (type == NODE) {
					/* x,y pair */
					char *sep = strchr(sval, ',');
					int x, y;
					assert(sep);

					*sep = '\0';
					x = atoi(sval);
					*sep++ = ',';
					y = atoi(sep);
					list = makeAttributeListMany(makeAttributeLocation(x, y), list);
				}
        else {
          Attribute attr = makeAttributeCurvePoints(
                             parseCoordinateList(sval, ATfalse));
				  list = makeAttributeListMany(attr, list);
        }

			}
		}

		dotAttributes = ATgetNext(dotAttributes);
	}

	if (width != -1 && height != -1) {
    list = makeAttributeListMany(makeAttributeSize(width, height), list);
	}

	return list;
}

static ATermList
appendKeyValue(char *key, char *value, ATermList attrs)
{
  ATerm keyTerm = (ATerm)ATmakeAppl0(ATmakeAFun(key, 0, ATtrue));
  ATerm valueTerm = (ATerm)ATmakeAppl0(ATmakeAFun(value, 0, ATtrue));
  ATermList result = ATinsert(attrs, (ATerm)ATmakeList2(keyTerm, valueTerm));

	protectTerm((ATerm)result);
  key = NULL;
  free(key);
  value = NULL;
  free(value);

	return result;
}

static NodeId buildNodeId(char *id)
{
  char *tmp;

  if (!strncmp(id, "cluster", 7)) {
    tmp = id + 7;
  }
  else {
    tmp = id;
  }
    
  NodeId nodeId = makeNodeIdDefault(ATparse(tmp));

  free(id);
	protectTerm(NodeIdToTerm(nodeId));

  return nodeId;
}

void yyerror(char *s)
{
  fprintf(stderr, "during parsing of a dot file: %s\n", s);
  exit(1);
}

#ifndef HAVE_YYWRAP
int yywrap()
{
  return 1;
}
#endif

