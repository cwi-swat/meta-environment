
#include "Graph.h"

static ATermTable levels;

/*{{{  static void storeLevel(ATerm id, ATerm level) */

static void storeLevel(ATerm id, ATerm level)
{
  ATermList list = (ATermList) ATtableGet(levels, level);
  if (list == NULL) {
    list = ATmakeList1(id);
  }
  else {
    list = ATinsert(list, id);
  }
  ATtablePut(levels, level, (ATerm) list);
}

/*}}}  */

/*{{{  static float pixelToInch(int pixel) */

static float pixelToInch(int pixel)
{
  return ((float)pixel)/72.0;
}

/*}}}  */
/*{{{  static void printPoint(Point point, FILE *file) */

static void printPoint(Point point, FILE *file)
{
  fprintf(file, "%d,%d", getPointX(point), getPointY(point));
}

/*}}}  */
/*{{{  static void printPolygon(Polygon poly, FILE *file) */

static void printPolygon(Polygon poly, FILE *file)
{
  ATfprintf(file, "pos=\"");
  while (!isPolygonEmpty(poly)) {
    printPoint(getPolygonHead(poly), file);
    poly = getPolygonTail(poly);
    if (!isPolygonEmpty(poly)) {
      fputc(' ', file);
    }
  }
  ATfprintf(file, "\"");
}

/*}}}  */
/*{{{  static void printColor(Color color, FILE *file) */

static void printColor(Color color, FILE *file)
{
  fprintf(file, "\"#%02x%02x%02x\"",
	  getColorRed(color),
	  getColorGreen(color),
	  getColorBlue(color));
}

/*}}}  */
/*{{{  static void printAttribute(Attribute attr, FILE *file) */

static void printAttribute(ATerm id, Attribute attr, FILE *file)
{
  if (isAttributeLabel(attr)) {
    ATfprintf(file, "label=%y", ATmakeAFun(getAttributeLabel(attr), 0, ATtrue));
  }
  else if (isAttributeColor(attr)) {
    fprintf(file, "color=");
    printColor(getAttributeColor(attr), file);
  }
  else if (isAttributeFillColor(attr)) {
    fprintf(file, "fillcolor=");
    printColor(getAttributeColor(attr), file);
  }
  else if (isAttributeStyle(attr)) {
    ATfprintf(file, "style=%t\n", StyleToTerm(getAttributeStyle(attr)));
  }
  else if (isAttributeShape(attr)) {
    ATfprintf(file, "shape=%t", ShapeToTerm(getAttributeShape(attr)));
  }
  else if (isAttributeLocation(attr)) {
    ATfprintf(file, "pos=\"%f,%f\"", pixelToInch(getAttributeX(attr)),
	      pixelToInch(getAttributeY(attr)));
  }
  else if (isAttributeSize(attr)) {
    ATfprintf(file, "width=\"%f\" ", pixelToInch(getAttributeWidth(attr)));
    ATfprintf(file, "height=\"%f\"", pixelToInch(getAttributeHeight(attr)));
  }
  else if (isAttributeCurvePoints(attr)) {
    printPolygon(getAttributePoints(attr), file);
  }
  else if (isAttributeDirection(attr)) {
    ATfprintf(file, "dir=%t", DirectionToTerm(getAttributeDirection(attr)));   
  }
  else if (isAttributeInfo(attr)) {
  }
  else if (isAttributeLevel(attr)) {
    ATerm level = ATmake("<str>", getAttributeLevel(attr));
    storeLevel(id, level);
  }
  else if (isAttributeFile(attr)) {
  }
  else {
    ATwarning("unknown attribute type: %t\n", attr);
  }
}

/*}}}  */
/*{{{  static void printAttributes(AttributeList attrs, FILE *file) */

static void printAttributes(ATerm id, AttributeList attrs, FILE *file)
{
  while (!isAttributeListEmpty(attrs)) {
    printAttribute(id, getAttributeListHead(attrs), file);
    attrs = getAttributeListTail(attrs);
    fprintf(file, " ");
  }
}

/*}}}  */
/*{{{  static void printNode(Node node, FILE *file) */

static void printNode(Node node, FILE *file)
{
  ATerm id = NodeIdToTerm(getNodeId(node));
  ATfprintf(file, "\"%t\" [", id);
  printAttributes(id, getNodeAttributes(node), file);
  fprintf(file, "]\n");
}

/*}}}  */
/*{{{  static void printNodes(NodeList nodes, FILE *file) */

static void printNodes(NodeList nodes, FILE *file)
{
  while (!isNodeListEmpty(nodes)) {
    printNode(getNodeListHead(nodes), file);
    nodes = getNodeListTail(nodes);
  }
}

/*}}}  */
/*{{{  static void printEdge(Edge edge, FILE *file) */

static void printEdge(Edge edge, FILE *file)
{
  // Edges are reversed to get the graph in the Meta-Environt to look 'right'
  ATfprintf(file, "\"%s\" ", ATwriteToString(NodeIdToTerm(getEdgeFrom(edge))));
  ATfprintf(file, "-> \"%s\" ", ATwriteToString(NodeIdToTerm(getEdgeTo(edge))));
  if (!isAttributeListEmpty(getEdgeAttributes(edge))) {
    ATfprintf(file,"[");
  }
  printAttributes(ATparse("\"***edge***\""),getEdgeAttributes(edge), file);

  if (!isAttributeListEmpty(getEdgeAttributes(edge))) {
    ATfprintf(file, "]");
  }

  ATfprintf(file,"\n");
}

/*}}}  */
/*{{{  static void printEdges(EdgeList edges, FILE *file) */

static void printEdges(EdgeList edges, FILE *file)
{
  while (!isEdgeListEmpty(edges)) {
    printEdge(getEdgeListHead(edges), file);
    edges = getEdgeListTail(edges);
  }
}

/*}}}  */
/*{{{  static void printLevels(FILE* file)  */

static void printLevels(FILE* file) 
{
  ATermList keys = ATtableKeys(levels);

  for ( ; !ATisEmpty(keys); keys = ATgetNext(keys)) {
    ATerm key = ATgetFirst(keys);
    ATermList level = (ATermList) ATtableGet(levels, key);

    fprintf(file, "{rank=same ");
    for ( ; !ATisEmpty(level); level = ATgetNext(level)) {
      ATfprintf(file, "\"%t\" ", ATgetFirst(level));
    }
    fprintf(file," }\n");
  }
}

/*}}}  */
/*{{{  static void printGraph(Graph graph, FILE *file) */

static void printGraph(Graph graph, FILE *file)
{
  levels = ATtableCreate(1024, 75);
  fprintf(file, "digraph TheGraph { \n");

  printNodes(getGraphNodes(graph), file);
  printEdges(getGraphEdges(graph), file);
  printLevels(file);
  fprintf(file, "\n}\n");
  ATtableDestroy(levels);
}

/*}}}  */

void graph2dot(Graph graph, FILE *file) 
{
  printGraph(graph, file);
}
