
#include "Graph.h"

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
/*{{{  static void printAttribute(Attribute attr, FILE *file) */

static void printAttribute(Attribute attr, FILE *file)
{
  if (isAttributeLabel(attr)) {
    ATfprintf(file, "label=%y", ATmakeAFun(getAttributeLabel(attr), 0, ATtrue));
  } else if (isAttributeShape(attr)) {
    ATfprintf(file, "shape=%t", ShapeToTerm(getAttributeShape(attr)));
  } else if (isAttributeLocation(attr)) {
    ATfprintf(file, "pos=\"%f,%f\"", pixelToInch(getAttributeX(attr)),
	      pixelToInch(getAttributeY(attr)));
  } else if (isAttributeSize(attr)) {
    ATfprintf(file, "width=\"%f\" ", pixelToInch(getAttributeWidth(attr)));
    ATfprintf(file, "height=\"%f\"", pixelToInch(getAttributeHeight(attr)));
  } else if (isAttributeCurvePoints(attr)) {
    printPolygon(getAttributePoints(attr), file);
  } else if (isAttributeDirection(attr)) {
    ATfprintf(file, "dir=%t", DirectionToTerm(getAttributeDirection(attr)));   
  } else {
    ATwarning("unknown attribute type: %t\n", attr);
  }
}

/*}}}  */
/*{{{  static void printAttributes(AttributeList attrs, FILE *file) */

static void printAttributes(AttributeList attrs, FILE *file)
{
  while (!isAttributeListEmpty(attrs)) {
    printAttribute(getAttributeListHead(attrs), file);
    attrs = getAttributeListTail(attrs);
    fprintf(file, " ");
  }
}

/*}}}  */
/*{{{  static void printNode(Node node, FILE *file) */

static void printNode(Node node, FILE *file)
{
  ATfprintf(file, "%t [", NodeIdToTerm(getNodeId(node)));
  printAttributes(getNodeAttributes(node), file);
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
  ATfprintf(file, "%t -> %t ", getEdgeTo(edge), getEdgeFrom(edge));
  if (!isAttributeListEmpty(getEdgeAttributes(edge))) {
    ATfprintf(file,"[");
  }
  printAttributes(getEdgeAttributes(edge), file);


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
/*{{{  static void printGraph(Graph graph, FILE *file) */

static void printGraph(Graph graph, FILE *file)
{
  fprintf(file, "digraph TheGraph { ordering=out;\n");

  printNodes(getGraphNodes(graph), file);
  printEdges(getGraphEdges(graph), file);

  fprintf(file, "\n}\n");
}

/*}}}  */

void graph2dot(Graph graph, FILE *file) 
{
  printGraph(graph, file);
}
