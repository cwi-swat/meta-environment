# $Id$

JAVAROOT = ${top_builddir}/meta-studio
javadir	 = ${prefix}/classes/metastudio/graph

CLASSPATH_ENV	= CLASSPATH=${JAVAROOT}:${top_srcdir}/meta-studio:${JAVA_ATERM}:${SHARED_OBJECTS}

api:
	adt-to-java \
		--input ${TOOLBUS}/share/toolbus/Graph.adt \
		--folding \
		--package metastudio.graph \
		--name MetaGraph \
		--verbose

# This breaks automake's "make distcheck" functionality, so explicit
# naming of all .java files is needed :-) :-)
#java_JAVA = $(wildcard *.java)

java_JAVA = \
	Attribute.java \
	AttributeImpl.java \
	AttributeList.java \
	AttributeListImpl.java \
	AttributeList_Empty.java \
	AttributeList_EmptyImpl.java \
	AttributeList_Multi.java \
	AttributeList_MultiImpl.java \
	Attribute_CurvePoints.java \
	Attribute_CurvePointsImpl.java \
	Attribute_Label.java \
	Attribute_LabelImpl.java \
	Attribute_Location.java \
	Attribute_LocationImpl.java \
	Attribute_Shape.java \
	Attribute_ShapeImpl.java \
	Attribute_Size.java \
	Attribute_SizeImpl.java \
	Edge.java \
	EdgeImpl.java \
	EdgeList.java \
	EdgeListImpl.java \
	EdgeList_Empty.java \
	EdgeList_EmptyImpl.java \
	EdgeList_Multi.java \
	EdgeList_MultiImpl.java \
	Edge_Default.java \
	Edge_DefaultImpl.java \
	Graph.java \
	GraphImpl.java \
	Graph_Default.java \
	Graph_DefaultImpl.java \
	MetaGraphConstructor.java \
	MetaGraphFactory.java \
	Node.java \
	NodeId.java \
	NodeIdImpl.java \
	NodeId_Default.java \
	NodeId_DefaultImpl.java \
	NodeImpl.java \
	NodeList.java \
	NodeListImpl.java \
	NodeList_Empty.java \
	NodeList_EmptyImpl.java \
	NodeList_Multi.java \
	NodeList_MultiImpl.java \
	NodeSizer.java \
	Node_Default.java \
	Node_DefaultImpl.java \
	Point.java \
	PointImpl.java \
	Point_Default.java \
	Point_DefaultImpl.java \
	Polygon.java \
	PolygonImpl.java \
	Polygon_Empty.java \
	Polygon_EmptyImpl.java \
	Polygon_Multi.java \
	Polygon_MultiImpl.java \
	Shape.java \
	ShapeImpl.java \
	Shape_Box.java \
	Shape_BoxImpl.java \
	Shape_Circle.java \
	Shape_CircleImpl.java \
	Shape_Diamond.java \
	Shape_DiamondImpl.java \
	Shape_Egg.java \
	Shape_EggImpl.java \
	Shape_Ellipse.java \
	Shape_EllipseImpl.java \
	Shape_Hexagon.java \
	Shape_HexagonImpl.java \
	Shape_House.java \
	Shape_HouseImpl.java \
	Shape_Octagon.java \
	Shape_OctagonImpl.java \
	Shape_Parallelogram.java \
	Shape_ParallelogramImpl.java \
	Shape_Plaintext.java \
	Shape_PlaintextImpl.java \
	Shape_Trapezium.java \
	Shape_TrapeziumImpl.java \
	Shape_Triangle.java \
	Shape_TriangleImpl.java
