package metastudio.graph;

import aterm.*;
import aterm.pure.PureFactory;
public class MetaGraphFactory extends PureFactory
{
  private aterm.AFun funGraph_Default;
  private Graph protoGraph_Default;
  private aterm.ATerm patternGraph_Default;
  private aterm.AFun funNodeList_Empty;
  private NodeList protoNodeList_Empty;
  private aterm.ATerm patternNodeList_Empty;
  private aterm.AFun funNodeList_Multi;
  private NodeList protoNodeList_Multi;
  private aterm.ATerm patternNodeList_Multi;
  private aterm.AFun funNode_Default;
  private Node protoNode_Default;
  private aterm.ATerm patternNode_Default;
  private aterm.AFun funNodeId_Default;
  private NodeId protoNodeId_Default;
  private aterm.ATerm patternNodeId_Default;
  private aterm.AFun funAttributeList_Empty;
  private AttributeList protoAttributeList_Empty;
  private aterm.ATerm patternAttributeList_Empty;
  private aterm.AFun funAttributeList_Multi;
  private AttributeList protoAttributeList_Multi;
  private aterm.ATerm patternAttributeList_Multi;
  private aterm.AFun funAttribute_Label;
  private Attribute protoAttribute_Label;
  private aterm.ATerm patternAttribute_Label;
  private aterm.AFun funAttribute_Shape;
  private Attribute protoAttribute_Shape;
  private aterm.ATerm patternAttribute_Shape;
  private aterm.AFun funAttribute_Location;
  private Attribute protoAttribute_Location;
  private aterm.ATerm patternAttribute_Location;
  private aterm.AFun funAttribute_Size;
  private Attribute protoAttribute_Size;
  private aterm.ATerm patternAttribute_Size;
  private aterm.AFun funAttribute_CurvePoints;
  private Attribute protoAttribute_CurvePoints;
  private aterm.ATerm patternAttribute_CurvePoints;
  private aterm.AFun funAttribute_BoundingBox;
  private Attribute protoAttribute_BoundingBox;
  private aterm.ATerm patternAttribute_BoundingBox;
  private aterm.AFun funAttribute_Direction;
  private Attribute protoAttribute_Direction;
  private aterm.ATerm patternAttribute_Direction;
  private aterm.AFun funAttribute_Info;
  private Attribute protoAttribute_Info;
  private aterm.ATerm patternAttribute_Info;
  private aterm.AFun funShape_Plaintext;
  private Shape protoShape_Plaintext;
  private aterm.ATerm patternShape_Plaintext;
  private aterm.AFun funShape_Ellipse;
  private Shape protoShape_Ellipse;
  private aterm.ATerm patternShape_Ellipse;
  private aterm.AFun funShape_Circle;
  private Shape protoShape_Circle;
  private aterm.ATerm patternShape_Circle;
  private aterm.AFun funShape_Egg;
  private Shape protoShape_Egg;
  private aterm.ATerm patternShape_Egg;
  private aterm.AFun funShape_Triangle;
  private Shape protoShape_Triangle;
  private aterm.ATerm patternShape_Triangle;
  private aterm.AFun funShape_Box;
  private Shape protoShape_Box;
  private aterm.ATerm patternShape_Box;
  private aterm.AFun funShape_Diamond;
  private Shape protoShape_Diamond;
  private aterm.ATerm patternShape_Diamond;
  private aterm.AFun funShape_Trapezium;
  private Shape protoShape_Trapezium;
  private aterm.ATerm patternShape_Trapezium;
  private aterm.AFun funShape_Parallelogram;
  private Shape protoShape_Parallelogram;
  private aterm.ATerm patternShape_Parallelogram;
  private aterm.AFun funShape_House;
  private Shape protoShape_House;
  private aterm.ATerm patternShape_House;
  private aterm.AFun funShape_Hexagon;
  private Shape protoShape_Hexagon;
  private aterm.ATerm patternShape_Hexagon;
  private aterm.AFun funShape_Octagon;
  private Shape protoShape_Octagon;
  private aterm.ATerm patternShape_Octagon;
  private aterm.AFun funDirection_Forward;
  private Direction protoDirection_Forward;
  private aterm.ATerm patternDirection_Forward;
  private aterm.AFun funDirection_Back;
  private Direction protoDirection_Back;
  private aterm.ATerm patternDirection_Back;
  private aterm.AFun funDirection_Both;
  private Direction protoDirection_Both;
  private aterm.ATerm patternDirection_Both;
  private aterm.AFun funDirection_None;
  private Direction protoDirection_None;
  private aterm.ATerm patternDirection_None;
  private aterm.AFun funEdgeList_Empty;
  private EdgeList protoEdgeList_Empty;
  private aterm.ATerm patternEdgeList_Empty;
  private aterm.AFun funEdgeList_Multi;
  private EdgeList protoEdgeList_Multi;
  private aterm.ATerm patternEdgeList_Multi;
  private aterm.AFun funEdge_Default;
  private Edge protoEdge_Default;
  private aterm.ATerm patternEdge_Default;
  private aterm.AFun funPolygon_Empty;
  private Polygon protoPolygon_Empty;
  private aterm.ATerm patternPolygon_Empty;
  private aterm.AFun funPolygon_Multi;
  private Polygon protoPolygon_Multi;
  private aterm.ATerm patternPolygon_Multi;
  private aterm.AFun funPoint_Default;
  private Point protoPoint_Default;
  private aterm.ATerm patternPoint_Default;
  public MetaGraphFactory()
  {
     super();
     initialize();
  }
  public MetaGraphFactory(int logSize)
  {
     super(logSize);
     initialize();
  }
  private void initialize()
  {

    patternGraph_Default = parse("graph(<term>,<term>,<term>)");
    funGraph_Default = makeAFun("_Graph_default", 3, false);
    protoGraph_Default = new Graph_Default(this);


    patternNodeList_Empty = parse("[]");
    funNodeList_Empty = makeAFun("_NodeList_empty", 0, false);
    protoNodeList_Empty = new NodeList_Empty(this);

    patternNodeList_Multi = parse("[<term>,<list>]");
    funNodeList_Multi = makeAFun("_NodeList_multi", 2, false);
    protoNodeList_Multi = new NodeList_Multi(this);


    patternNode_Default = parse("node(<term>,<term>)");
    funNode_Default = makeAFun("_Node_default", 2, false);
    protoNode_Default = new Node_Default(this);


    patternNodeId_Default = parse("<str>");
    funNodeId_Default = makeAFun("_NodeId_default", 1, false);
    protoNodeId_Default = new NodeId_Default(this);


    patternAttributeList_Empty = parse("[]");
    funAttributeList_Empty = makeAFun("_AttributeList_empty", 0, false);
    protoAttributeList_Empty = new AttributeList_Empty(this);

    patternAttributeList_Multi = parse("[<term>,<list>]");
    funAttributeList_Multi = makeAFun("_AttributeList_multi", 2, false);
    protoAttributeList_Multi = new AttributeList_Multi(this);


    patternAttribute_Label = parse("label(<str>)");
    funAttribute_Label = makeAFun("_Attribute_label", 1, false);
    protoAttribute_Label = new Attribute_Label(this);

    patternAttribute_Shape = parse("shape(<term>)");
    funAttribute_Shape = makeAFun("_Attribute_shape", 1, false);
    protoAttribute_Shape = new Attribute_Shape(this);

    patternAttribute_Location = parse("location(<int>,<int>)");
    funAttribute_Location = makeAFun("_Attribute_location", 2, false);
    protoAttribute_Location = new Attribute_Location(this);

    patternAttribute_Size = parse("size(<int>,<int>)");
    funAttribute_Size = makeAFun("_Attribute_size", 2, false);
    protoAttribute_Size = new Attribute_Size(this);

    patternAttribute_CurvePoints = parse("curve-points(<term>)");
    funAttribute_CurvePoints = makeAFun("_Attribute_curve-points", 1, false);
    protoAttribute_CurvePoints = new Attribute_CurvePoints(this);

    patternAttribute_BoundingBox = parse("bounding-box(<term>,<term>)");
    funAttribute_BoundingBox = makeAFun("_Attribute_bounding-box", 2, false);
    protoAttribute_BoundingBox = new Attribute_BoundingBox(this);

    patternAttribute_Direction = parse("direction(<term>)");
    funAttribute_Direction = makeAFun("_Attribute_direction", 1, false);
    protoAttribute_Direction = new Attribute_Direction(this);

    patternAttribute_Info = parse("info(<str>,<term>)");
    funAttribute_Info = makeAFun("_Attribute_info", 2, false);
    protoAttribute_Info = new Attribute_Info(this);


    patternShape_Plaintext = parse("plaintext");
    funShape_Plaintext = makeAFun("_Shape_plaintext", 0, false);
    protoShape_Plaintext = new Shape_Plaintext(this);

    patternShape_Ellipse = parse("ellipse");
    funShape_Ellipse = makeAFun("_Shape_ellipse", 0, false);
    protoShape_Ellipse = new Shape_Ellipse(this);

    patternShape_Circle = parse("circle");
    funShape_Circle = makeAFun("_Shape_circle", 0, false);
    protoShape_Circle = new Shape_Circle(this);

    patternShape_Egg = parse("egg");
    funShape_Egg = makeAFun("_Shape_egg", 0, false);
    protoShape_Egg = new Shape_Egg(this);

    patternShape_Triangle = parse("triangle");
    funShape_Triangle = makeAFun("_Shape_triangle", 0, false);
    protoShape_Triangle = new Shape_Triangle(this);

    patternShape_Box = parse("box");
    funShape_Box = makeAFun("_Shape_box", 0, false);
    protoShape_Box = new Shape_Box(this);

    patternShape_Diamond = parse("diamond");
    funShape_Diamond = makeAFun("_Shape_diamond", 0, false);
    protoShape_Diamond = new Shape_Diamond(this);

    patternShape_Trapezium = parse("trapezium");
    funShape_Trapezium = makeAFun("_Shape_trapezium", 0, false);
    protoShape_Trapezium = new Shape_Trapezium(this);

    patternShape_Parallelogram = parse("parallelogram");
    funShape_Parallelogram = makeAFun("_Shape_parallelogram", 0, false);
    protoShape_Parallelogram = new Shape_Parallelogram(this);

    patternShape_House = parse("house");
    funShape_House = makeAFun("_Shape_house", 0, false);
    protoShape_House = new Shape_House(this);

    patternShape_Hexagon = parse("hexagon");
    funShape_Hexagon = makeAFun("_Shape_hexagon", 0, false);
    protoShape_Hexagon = new Shape_Hexagon(this);

    patternShape_Octagon = parse("octagon");
    funShape_Octagon = makeAFun("_Shape_octagon", 0, false);
    protoShape_Octagon = new Shape_Octagon(this);


    patternDirection_Forward = parse("forward");
    funDirection_Forward = makeAFun("_Direction_forward", 0, false);
    protoDirection_Forward = new Direction_Forward(this);

    patternDirection_Back = parse("back");
    funDirection_Back = makeAFun("_Direction_back", 0, false);
    protoDirection_Back = new Direction_Back(this);

    patternDirection_Both = parse("both");
    funDirection_Both = makeAFun("_Direction_both", 0, false);
    protoDirection_Both = new Direction_Both(this);

    patternDirection_None = parse("none");
    funDirection_None = makeAFun("_Direction_none", 0, false);
    protoDirection_None = new Direction_None(this);


    patternEdgeList_Empty = parse("[]");
    funEdgeList_Empty = makeAFun("_EdgeList_empty", 0, false);
    protoEdgeList_Empty = new EdgeList_Empty(this);

    patternEdgeList_Multi = parse("[<term>,<list>]");
    funEdgeList_Multi = makeAFun("_EdgeList_multi", 2, false);
    protoEdgeList_Multi = new EdgeList_Multi(this);


    patternEdge_Default = parse("edge(<term>,<term>,<term>)");
    funEdge_Default = makeAFun("_Edge_default", 3, false);
    protoEdge_Default = new Edge_Default(this);


    patternPolygon_Empty = parse("[]");
    funPolygon_Empty = makeAFun("_Polygon_empty", 0, false);
    protoPolygon_Empty = new Polygon_Empty(this);

    patternPolygon_Multi = parse("[<term>,<list>]");
    funPolygon_Multi = makeAFun("_Polygon_multi", 2, false);
    protoPolygon_Multi = new Polygon_Multi(this);


    patternPoint_Default = parse("point(<int>,<int>)");
    funPoint_Default = makeAFun("_Point_default", 2, false);
    protoPoint_Default = new Point_Default(this);

  }
  protected Graph_Default makeGraph_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoGraph_Default) {
      protoGraph_Default.initHashCode(annos,fun,args);
      return (Graph_Default) build(protoGraph_Default);
    }
  }

  public Graph_Default makeGraph_Default(NodeList _nodes, EdgeList _edges, AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_nodes, _edges, _attributes};
    return makeGraph_Default( funGraph_Default, args, empty);
  }

  public Graph Graph_DefaultFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternGraph_Default);

    if (children != null) {
      Graph tmp = makeGraph_Default(NodeListFromTerm( (aterm.ATerm) children.get(0)), EdgeListFromTerm( (aterm.ATerm) children.get(1)), AttributeListFromTerm( (aterm.ATerm) children.get(2)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Graph_DefaultImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((NodeList)arg.getArgument(0)).toTerm());
    args.add(((EdgeList)arg.getArgument(1)).toTerm());
    args.add(((AttributeList)arg.getArgument(2)).toTerm());
    return make(patternGraph_Default, args);
  }

  protected NodeList_Empty makeNodeList_Empty(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoNodeList_Empty) {
      protoNodeList_Empty.initHashCode(annos,fun,args);
      return (NodeList_Empty) build(protoNodeList_Empty);
    }
  }

  public NodeList_Empty makeNodeList_Empty() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeNodeList_Empty( funNodeList_Empty, args, empty);
  }

  public NodeList NodeList_EmptyFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternNodeList_Empty);

    if (children != null) {
      NodeList tmp = makeNodeList_Empty();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(NodeList_EmptyImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternNodeList_Empty, args);
  }

  protected NodeList_Multi makeNodeList_Multi(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoNodeList_Multi) {
      protoNodeList_Multi.initHashCode(annos,fun,args);
      return (NodeList_Multi) build(protoNodeList_Multi);
    }
  }

  public NodeList_Multi makeNodeList_Multi(Node _head, NodeList _tail) {
    aterm.ATerm[] args = new aterm.ATerm[] {_head, _tail};
    return makeNodeList_Multi( funNodeList_Multi, args, empty);
  }

  public NodeList NodeList_MultiFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternNodeList_Multi);

    if (children != null) {
      NodeList tmp = makeNodeList_Multi(NodeFromTerm( (aterm.ATerm) children.get(0)), NodeListFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(NodeList_MultiImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Node)arg.getArgument(0)).toTerm());
    args.add(((NodeList)arg.getArgument(1)).toTerm());
    return make(patternNodeList_Multi, args);
  }

  protected Node_Default makeNode_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoNode_Default) {
      protoNode_Default.initHashCode(annos,fun,args);
      return (Node_Default) build(protoNode_Default);
    }
  }

  public Node_Default makeNode_Default(NodeId _id, AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id, _attributes};
    return makeNode_Default( funNode_Default, args, empty);
  }

  public Node Node_DefaultFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternNode_Default);

    if (children != null) {
      Node tmp = makeNode_Default(NodeIdFromTerm( (aterm.ATerm) children.get(0)), AttributeListFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Node_DefaultImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((NodeId)arg.getArgument(0)).toTerm());
    args.add(((AttributeList)arg.getArgument(1)).toTerm());
    return make(patternNode_Default, args);
  }

  protected NodeId_Default makeNodeId_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoNodeId_Default) {
      protoNodeId_Default.initHashCode(annos,fun,args);
      return (NodeId_Default) build(protoNodeId_Default);
    }
  }

  public NodeId_Default makeNodeId_Default(String _id) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeAppl(makeAFun(_id, 0, true))};
    return makeNodeId_Default( funNodeId_Default, args, empty);
  }

  public NodeId NodeId_DefaultFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternNodeId_Default);

    if (children != null) {
      NodeId tmp = makeNodeId_Default((String) children.get(0));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(NodeId_DefaultImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((aterm.ATermAppl)arg.getArgument(0)).getAFun().getName());
    return make(patternNodeId_Default, args);
  }

  protected AttributeList_Empty makeAttributeList_Empty(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttributeList_Empty) {
      protoAttributeList_Empty.initHashCode(annos,fun,args);
      return (AttributeList_Empty) build(protoAttributeList_Empty);
    }
  }

  public AttributeList_Empty makeAttributeList_Empty() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttributeList_Empty( funAttributeList_Empty, args, empty);
  }

  public AttributeList AttributeList_EmptyFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttributeList_Empty);

    if (children != null) {
      AttributeList tmp = makeAttributeList_Empty();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(AttributeList_EmptyImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternAttributeList_Empty, args);
  }

  protected AttributeList_Multi makeAttributeList_Multi(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttributeList_Multi) {
      protoAttributeList_Multi.initHashCode(annos,fun,args);
      return (AttributeList_Multi) build(protoAttributeList_Multi);
    }
  }

  public AttributeList_Multi makeAttributeList_Multi(Attribute _head, AttributeList _tail) {
    aterm.ATerm[] args = new aterm.ATerm[] {_head, _tail};
    return makeAttributeList_Multi( funAttributeList_Multi, args, empty);
  }

  public AttributeList AttributeList_MultiFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttributeList_Multi);

    if (children != null) {
      AttributeList tmp = makeAttributeList_Multi(AttributeFromTerm( (aterm.ATerm) children.get(0)), AttributeListFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(AttributeList_MultiImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Attribute)arg.getArgument(0)).toTerm());
    args.add(((AttributeList)arg.getArgument(1)).toTerm());
    return make(patternAttributeList_Multi, args);
  }

  protected Attribute_Label makeAttribute_Label(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Label) {
      protoAttribute_Label.initHashCode(annos,fun,args);
      return (Attribute_Label) build(protoAttribute_Label);
    }
  }

  public Attribute_Label makeAttribute_Label(String _label) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeAppl(makeAFun(_label, 0, true))};
    return makeAttribute_Label( funAttribute_Label, args, empty);
  }

  public Attribute Attribute_LabelFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Label);

    if (children != null) {
      Attribute tmp = makeAttribute_Label((String) children.get(0));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_LabelImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((aterm.ATermAppl)arg.getArgument(0)).getAFun().getName());
    return make(patternAttribute_Label, args);
  }

  protected Attribute_Shape makeAttribute_Shape(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Shape) {
      protoAttribute_Shape.initHashCode(annos,fun,args);
      return (Attribute_Shape) build(protoAttribute_Shape);
    }
  }

  public Attribute_Shape makeAttribute_Shape(Shape _shape) {
    aterm.ATerm[] args = new aterm.ATerm[] {_shape};
    return makeAttribute_Shape( funAttribute_Shape, args, empty);
  }

  public Attribute Attribute_ShapeFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Shape);

    if (children != null) {
      Attribute tmp = makeAttribute_Shape(ShapeFromTerm( (aterm.ATerm) children.get(0)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_ShapeImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Shape)arg.getArgument(0)).toTerm());
    return make(patternAttribute_Shape, args);
  }

  protected Attribute_Location makeAttribute_Location(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Location) {
      protoAttribute_Location.initHashCode(annos,fun,args);
      return (Attribute_Location) build(protoAttribute_Location);
    }
  }

  public Attribute_Location makeAttribute_Location(int _x, int _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_x), makeInt(_y)};
    return makeAttribute_Location( funAttribute_Location, args, empty);
  }

  public Attribute Attribute_LocationFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Location);

    if (children != null) {
      Attribute tmp = makeAttribute_Location(((Integer) children.get(0)).intValue(), ((Integer) children.get(1)).intValue());
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_LocationImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(0)).getInt()));
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(1)).getInt()));
    return make(patternAttribute_Location, args);
  }

  protected Attribute_Size makeAttribute_Size(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Size) {
      protoAttribute_Size.initHashCode(annos,fun,args);
      return (Attribute_Size) build(protoAttribute_Size);
    }
  }

  public Attribute_Size makeAttribute_Size(int _width, int _height) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_width), makeInt(_height)};
    return makeAttribute_Size( funAttribute_Size, args, empty);
  }

  public Attribute Attribute_SizeFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Size);

    if (children != null) {
      Attribute tmp = makeAttribute_Size(((Integer) children.get(0)).intValue(), ((Integer) children.get(1)).intValue());
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_SizeImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(0)).getInt()));
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(1)).getInt()));
    return make(patternAttribute_Size, args);
  }

  protected Attribute_CurvePoints makeAttribute_CurvePoints(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_CurvePoints) {
      protoAttribute_CurvePoints.initHashCode(annos,fun,args);
      return (Attribute_CurvePoints) build(protoAttribute_CurvePoints);
    }
  }

  public Attribute_CurvePoints makeAttribute_CurvePoints(Polygon _points) {
    aterm.ATerm[] args = new aterm.ATerm[] {_points};
    return makeAttribute_CurvePoints( funAttribute_CurvePoints, args, empty);
  }

  public Attribute Attribute_CurvePointsFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_CurvePoints);

    if (children != null) {
      Attribute tmp = makeAttribute_CurvePoints(PolygonFromTerm( (aterm.ATerm) children.get(0)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_CurvePointsImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Polygon)arg.getArgument(0)).toTerm());
    return make(patternAttribute_CurvePoints, args);
  }

  protected Attribute_BoundingBox makeAttribute_BoundingBox(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_BoundingBox) {
      protoAttribute_BoundingBox.initHashCode(annos,fun,args);
      return (Attribute_BoundingBox) build(protoAttribute_BoundingBox);
    }
  }

  public Attribute_BoundingBox makeAttribute_BoundingBox(Point _first, Point _second) {
    aterm.ATerm[] args = new aterm.ATerm[] {_first, _second};
    return makeAttribute_BoundingBox( funAttribute_BoundingBox, args, empty);
  }

  public Attribute Attribute_BoundingBoxFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_BoundingBox);

    if (children != null) {
      Attribute tmp = makeAttribute_BoundingBox(PointFromTerm( (aterm.ATerm) children.get(0)), PointFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_BoundingBoxImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Point)arg.getArgument(0)).toTerm());
    args.add(((Point)arg.getArgument(1)).toTerm());
    return make(patternAttribute_BoundingBox, args);
  }

  protected Attribute_Direction makeAttribute_Direction(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Direction) {
      protoAttribute_Direction.initHashCode(annos,fun,args);
      return (Attribute_Direction) build(protoAttribute_Direction);
    }
  }

  public Attribute_Direction makeAttribute_Direction(Direction _direction) {
    aterm.ATerm[] args = new aterm.ATerm[] {_direction};
    return makeAttribute_Direction( funAttribute_Direction, args, empty);
  }

  public Attribute Attribute_DirectionFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Direction);

    if (children != null) {
      Attribute tmp = makeAttribute_Direction(DirectionFromTerm( (aterm.ATerm) children.get(0)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_DirectionImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Direction)arg.getArgument(0)).toTerm());
    return make(patternAttribute_Direction, args);
  }

  protected Attribute_Info makeAttribute_Info(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Info) {
      protoAttribute_Info.initHashCode(annos,fun,args);
      return (Attribute_Info) build(protoAttribute_Info);
    }
  }

  public Attribute_Info makeAttribute_Info(String _key, aterm.ATerm _value) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeAppl(makeAFun(_key, 0, true)), _value};
    return makeAttribute_Info( funAttribute_Info, args, empty);
  }

  public Attribute Attribute_InfoFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternAttribute_Info);

    if (children != null) {
      Attribute tmp = makeAttribute_Info((String) children.get(0), (aterm.ATerm) children.get(1));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Attribute_InfoImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((aterm.ATermAppl)arg.getArgument(0)).getAFun().getName());
    args.add((aterm.ATerm)arg.getArgument(1));
    return make(patternAttribute_Info, args);
  }

  protected Shape_Plaintext makeShape_Plaintext(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Plaintext) {
      protoShape_Plaintext.initHashCode(annos,fun,args);
      return (Shape_Plaintext) build(protoShape_Plaintext);
    }
  }

  public Shape_Plaintext makeShape_Plaintext() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Plaintext( funShape_Plaintext, args, empty);
  }

  public Shape Shape_PlaintextFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Plaintext);

    if (children != null) {
      Shape tmp = makeShape_Plaintext();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_PlaintextImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Plaintext, args);
  }

  protected Shape_Ellipse makeShape_Ellipse(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Ellipse) {
      protoShape_Ellipse.initHashCode(annos,fun,args);
      return (Shape_Ellipse) build(protoShape_Ellipse);
    }
  }

  public Shape_Ellipse makeShape_Ellipse() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Ellipse( funShape_Ellipse, args, empty);
  }

  public Shape Shape_EllipseFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Ellipse);

    if (children != null) {
      Shape tmp = makeShape_Ellipse();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_EllipseImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Ellipse, args);
  }

  protected Shape_Circle makeShape_Circle(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Circle) {
      protoShape_Circle.initHashCode(annos,fun,args);
      return (Shape_Circle) build(protoShape_Circle);
    }
  }

  public Shape_Circle makeShape_Circle() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Circle( funShape_Circle, args, empty);
  }

  public Shape Shape_CircleFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Circle);

    if (children != null) {
      Shape tmp = makeShape_Circle();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_CircleImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Circle, args);
  }

  protected Shape_Egg makeShape_Egg(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Egg) {
      protoShape_Egg.initHashCode(annos,fun,args);
      return (Shape_Egg) build(protoShape_Egg);
    }
  }

  public Shape_Egg makeShape_Egg() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Egg( funShape_Egg, args, empty);
  }

  public Shape Shape_EggFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Egg);

    if (children != null) {
      Shape tmp = makeShape_Egg();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_EggImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Egg, args);
  }

  protected Shape_Triangle makeShape_Triangle(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Triangle) {
      protoShape_Triangle.initHashCode(annos,fun,args);
      return (Shape_Triangle) build(protoShape_Triangle);
    }
  }

  public Shape_Triangle makeShape_Triangle() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Triangle( funShape_Triangle, args, empty);
  }

  public Shape Shape_TriangleFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Triangle);

    if (children != null) {
      Shape tmp = makeShape_Triangle();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_TriangleImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Triangle, args);
  }

  protected Shape_Box makeShape_Box(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Box) {
      protoShape_Box.initHashCode(annos,fun,args);
      return (Shape_Box) build(protoShape_Box);
    }
  }

  public Shape_Box makeShape_Box() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Box( funShape_Box, args, empty);
  }

  public Shape Shape_BoxFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Box);

    if (children != null) {
      Shape tmp = makeShape_Box();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_BoxImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Box, args);
  }

  protected Shape_Diamond makeShape_Diamond(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Diamond) {
      protoShape_Diamond.initHashCode(annos,fun,args);
      return (Shape_Diamond) build(protoShape_Diamond);
    }
  }

  public Shape_Diamond makeShape_Diamond() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Diamond( funShape_Diamond, args, empty);
  }

  public Shape Shape_DiamondFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Diamond);

    if (children != null) {
      Shape tmp = makeShape_Diamond();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_DiamondImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Diamond, args);
  }

  protected Shape_Trapezium makeShape_Trapezium(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Trapezium) {
      protoShape_Trapezium.initHashCode(annos,fun,args);
      return (Shape_Trapezium) build(protoShape_Trapezium);
    }
  }

  public Shape_Trapezium makeShape_Trapezium() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Trapezium( funShape_Trapezium, args, empty);
  }

  public Shape Shape_TrapeziumFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Trapezium);

    if (children != null) {
      Shape tmp = makeShape_Trapezium();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_TrapeziumImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Trapezium, args);
  }

  protected Shape_Parallelogram makeShape_Parallelogram(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Parallelogram) {
      protoShape_Parallelogram.initHashCode(annos,fun,args);
      return (Shape_Parallelogram) build(protoShape_Parallelogram);
    }
  }

  public Shape_Parallelogram makeShape_Parallelogram() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Parallelogram( funShape_Parallelogram, args, empty);
  }

  public Shape Shape_ParallelogramFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Parallelogram);

    if (children != null) {
      Shape tmp = makeShape_Parallelogram();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_ParallelogramImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Parallelogram, args);
  }

  protected Shape_House makeShape_House(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_House) {
      protoShape_House.initHashCode(annos,fun,args);
      return (Shape_House) build(protoShape_House);
    }
  }

  public Shape_House makeShape_House() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_House( funShape_House, args, empty);
  }

  public Shape Shape_HouseFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_House);

    if (children != null) {
      Shape tmp = makeShape_House();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_HouseImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_House, args);
  }

  protected Shape_Hexagon makeShape_Hexagon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Hexagon) {
      protoShape_Hexagon.initHashCode(annos,fun,args);
      return (Shape_Hexagon) build(protoShape_Hexagon);
    }
  }

  public Shape_Hexagon makeShape_Hexagon() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Hexagon( funShape_Hexagon, args, empty);
  }

  public Shape Shape_HexagonFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Hexagon);

    if (children != null) {
      Shape tmp = makeShape_Hexagon();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_HexagonImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Hexagon, args);
  }

  protected Shape_Octagon makeShape_Octagon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoShape_Octagon) {
      protoShape_Octagon.initHashCode(annos,fun,args);
      return (Shape_Octagon) build(protoShape_Octagon);
    }
  }

  public Shape_Octagon makeShape_Octagon() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Octagon( funShape_Octagon, args, empty);
  }

  public Shape Shape_OctagonFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternShape_Octagon);

    if (children != null) {
      Shape tmp = makeShape_Octagon();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Shape_OctagonImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternShape_Octagon, args);
  }

  protected Direction_Forward makeDirection_Forward(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoDirection_Forward) {
      protoDirection_Forward.initHashCode(annos,fun,args);
      return (Direction_Forward) build(protoDirection_Forward);
    }
  }

  public Direction_Forward makeDirection_Forward() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Forward( funDirection_Forward, args, empty);
  }

  public Direction Direction_ForwardFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternDirection_Forward);

    if (children != null) {
      Direction tmp = makeDirection_Forward();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Direction_ForwardImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternDirection_Forward, args);
  }

  protected Direction_Back makeDirection_Back(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoDirection_Back) {
      protoDirection_Back.initHashCode(annos,fun,args);
      return (Direction_Back) build(protoDirection_Back);
    }
  }

  public Direction_Back makeDirection_Back() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Back( funDirection_Back, args, empty);
  }

  public Direction Direction_BackFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternDirection_Back);

    if (children != null) {
      Direction tmp = makeDirection_Back();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Direction_BackImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternDirection_Back, args);
  }

  protected Direction_Both makeDirection_Both(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoDirection_Both) {
      protoDirection_Both.initHashCode(annos,fun,args);
      return (Direction_Both) build(protoDirection_Both);
    }
  }

  public Direction_Both makeDirection_Both() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Both( funDirection_Both, args, empty);
  }

  public Direction Direction_BothFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternDirection_Both);

    if (children != null) {
      Direction tmp = makeDirection_Both();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Direction_BothImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternDirection_Both, args);
  }

  protected Direction_None makeDirection_None(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoDirection_None) {
      protoDirection_None.initHashCode(annos,fun,args);
      return (Direction_None) build(protoDirection_None);
    }
  }

  public Direction_None makeDirection_None() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_None( funDirection_None, args, empty);
  }

  public Direction Direction_NoneFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternDirection_None);

    if (children != null) {
      Direction tmp = makeDirection_None();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Direction_NoneImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternDirection_None, args);
  }

  protected EdgeList_Empty makeEdgeList_Empty(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoEdgeList_Empty) {
      protoEdgeList_Empty.initHashCode(annos,fun,args);
      return (EdgeList_Empty) build(protoEdgeList_Empty);
    }
  }

  public EdgeList_Empty makeEdgeList_Empty() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeEdgeList_Empty( funEdgeList_Empty, args, empty);
  }

  public EdgeList EdgeList_EmptyFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternEdgeList_Empty);

    if (children != null) {
      EdgeList tmp = makeEdgeList_Empty();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(EdgeList_EmptyImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternEdgeList_Empty, args);
  }

  protected EdgeList_Multi makeEdgeList_Multi(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoEdgeList_Multi) {
      protoEdgeList_Multi.initHashCode(annos,fun,args);
      return (EdgeList_Multi) build(protoEdgeList_Multi);
    }
  }

  public EdgeList_Multi makeEdgeList_Multi(Edge _head, EdgeList _tail) {
    aterm.ATerm[] args = new aterm.ATerm[] {_head, _tail};
    return makeEdgeList_Multi( funEdgeList_Multi, args, empty);
  }

  public EdgeList EdgeList_MultiFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternEdgeList_Multi);

    if (children != null) {
      EdgeList tmp = makeEdgeList_Multi(EdgeFromTerm( (aterm.ATerm) children.get(0)), EdgeListFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(EdgeList_MultiImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Edge)arg.getArgument(0)).toTerm());
    args.add(((EdgeList)arg.getArgument(1)).toTerm());
    return make(patternEdgeList_Multi, args);
  }

  protected Edge_Default makeEdge_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoEdge_Default) {
      protoEdge_Default.initHashCode(annos,fun,args);
      return (Edge_Default) build(protoEdge_Default);
    }
  }

  public Edge_Default makeEdge_Default(NodeId _from, NodeId _to, AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_from, _to, _attributes};
    return makeEdge_Default( funEdge_Default, args, empty);
  }

  public Edge Edge_DefaultFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternEdge_Default);

    if (children != null) {
      Edge tmp = makeEdge_Default(NodeIdFromTerm( (aterm.ATerm) children.get(0)), NodeIdFromTerm( (aterm.ATerm) children.get(1)), AttributeListFromTerm( (aterm.ATerm) children.get(2)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Edge_DefaultImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((NodeId)arg.getArgument(0)).toTerm());
    args.add(((NodeId)arg.getArgument(1)).toTerm());
    args.add(((AttributeList)arg.getArgument(2)).toTerm());
    return make(patternEdge_Default, args);
  }

  protected Polygon_Empty makePolygon_Empty(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoPolygon_Empty) {
      protoPolygon_Empty.initHashCode(annos,fun,args);
      return (Polygon_Empty) build(protoPolygon_Empty);
    }
  }

  public Polygon_Empty makePolygon_Empty() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makePolygon_Empty( funPolygon_Empty, args, empty);
  }

  public Polygon Polygon_EmptyFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternPolygon_Empty);

    if (children != null) {
      Polygon tmp = makePolygon_Empty();
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Polygon_EmptyImpl arg) {
    java.util.List args = new java.util.LinkedList();
    return make(patternPolygon_Empty, args);
  }

  protected Polygon_Multi makePolygon_Multi(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoPolygon_Multi) {
      protoPolygon_Multi.initHashCode(annos,fun,args);
      return (Polygon_Multi) build(protoPolygon_Multi);
    }
  }

  public Polygon_Multi makePolygon_Multi(Point _head, Polygon _tail) {
    aterm.ATerm[] args = new aterm.ATerm[] {_head, _tail};
    return makePolygon_Multi( funPolygon_Multi, args, empty);
  }

  public Polygon Polygon_MultiFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternPolygon_Multi);

    if (children != null) {
      Polygon tmp = makePolygon_Multi(PointFromTerm( (aterm.ATerm) children.get(0)), PolygonFromTerm( (aterm.ATerm) children.get(1)));
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Polygon_MultiImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(((Point)arg.getArgument(0)).toTerm());
    args.add(((Polygon)arg.getArgument(1)).toTerm());
    return make(patternPolygon_Multi, args);
  }

  protected Point_Default makePoint_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoPoint_Default) {
      protoPoint_Default.initHashCode(annos,fun,args);
      return (Point_Default) build(protoPoint_Default);
    }
  }

  public Point_Default makePoint_Default(int _x, int _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_x), makeInt(_y)};
    return makePoint_Default( funPoint_Default, args, empty);
  }

  public Point Point_DefaultFromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(patternPoint_Default);

    if (children != null) {
      Point tmp = makePoint_Default(((Integer) children.get(0)).intValue(), ((Integer) children.get(1)).intValue());
      return tmp;
    }
    else {
      return null;
    }
  }
  protected aterm.ATerm toTerm(Point_DefaultImpl arg) {
    java.util.List args = new java.util.LinkedList();
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(0)).getInt()));
    args.add(new Integer(((aterm.ATermInt)arg.getArgument(1)).getInt()));
    return make(patternPoint_Default, args);
  }

  public Graph GraphFromTerm(aterm.ATerm trm)
  {
    Graph tmp;
    tmp = Graph_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Graph: " + trm);
  }
  public NodeList NodeListFromTerm(aterm.ATerm trm)
  {
    NodeList tmp;
    tmp = NodeList_EmptyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = NodeList_MultiFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a NodeList: " + trm);
  }
  public Node NodeFromTerm(aterm.ATerm trm)
  {
    Node tmp;
    tmp = Node_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Node: " + trm);
  }
  public NodeId NodeIdFromTerm(aterm.ATerm trm)
  {
    NodeId tmp;
    tmp = NodeId_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a NodeId: " + trm);
  }
  public AttributeList AttributeListFromTerm(aterm.ATerm trm)
  {
    AttributeList tmp;
    tmp = AttributeList_EmptyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = AttributeList_MultiFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a AttributeList: " + trm);
  }
  public Attribute AttributeFromTerm(aterm.ATerm trm)
  {
    Attribute tmp;
    tmp = Attribute_LabelFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_ShapeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_LocationFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_SizeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_CurvePointsFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_BoundingBoxFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_DirectionFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_InfoFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Attribute: " + trm);
  }
  public Shape ShapeFromTerm(aterm.ATerm trm)
  {
    Shape tmp;
    tmp = Shape_PlaintextFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_EllipseFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_CircleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_EggFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_TriangleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_BoxFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_DiamondFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_TrapeziumFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_ParallelogramFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_HouseFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_HexagonFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_OctagonFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Shape: " + trm);
  }
  public Direction DirectionFromTerm(aterm.ATerm trm)
  {
    Direction tmp;
    tmp = Direction_ForwardFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Direction_BackFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Direction_BothFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Direction_NoneFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Direction: " + trm);
  }
  public EdgeList EdgeListFromTerm(aterm.ATerm trm)
  {
    EdgeList tmp;
    tmp = EdgeList_EmptyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = EdgeList_MultiFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a EdgeList: " + trm);
  }
  public Edge EdgeFromTerm(aterm.ATerm trm)
  {
    Edge tmp;
    tmp = Edge_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Edge: " + trm);
  }
  public Polygon PolygonFromTerm(aterm.ATerm trm)
  {
    Polygon tmp;
    tmp = Polygon_EmptyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Polygon_MultiFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Polygon: " + trm);
  }
  public Point PointFromTerm(aterm.ATerm trm)
  {
    Point tmp;
    tmp = Point_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Point: " + trm);
  }
  public Graph GraphFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return GraphFromTerm(trm);
  }
  public Graph GraphFromFile(java.io.InputStream stream) throws java.io.IOException {
    return GraphFromTerm(readFromFile(stream));
  }
  public NodeList NodeListFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return NodeListFromTerm(trm);
  }
  public NodeList NodeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeListFromTerm(readFromFile(stream));
  }
  public Node NodeFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return NodeFromTerm(trm);
  }
  public Node NodeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeFromTerm(readFromFile(stream));
  }
  public NodeId NodeIdFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return NodeIdFromTerm(trm);
  }
  public NodeId NodeIdFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeIdFromTerm(readFromFile(stream));
  }
  public AttributeList AttributeListFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return AttributeListFromTerm(trm);
  }
  public AttributeList AttributeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeListFromTerm(readFromFile(stream));
  }
  public Attribute AttributeFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return AttributeFromTerm(trm);
  }
  public Attribute AttributeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeFromTerm(readFromFile(stream));
  }
  public Shape ShapeFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return ShapeFromTerm(trm);
  }
  public Shape ShapeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ShapeFromTerm(readFromFile(stream));
  }
  public Direction DirectionFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return DirectionFromTerm(trm);
  }
  public Direction DirectionFromFile(java.io.InputStream stream) throws java.io.IOException {
    return DirectionFromTerm(readFromFile(stream));
  }
  public EdgeList EdgeListFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return EdgeListFromTerm(trm);
  }
  public EdgeList EdgeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return EdgeListFromTerm(readFromFile(stream));
  }
  public Edge EdgeFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return EdgeFromTerm(trm);
  }
  public Edge EdgeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return EdgeFromTerm(readFromFile(stream));
  }
  public Polygon PolygonFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return PolygonFromTerm(trm);
  }
  public Polygon PolygonFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PolygonFromTerm(readFromFile(stream));
  }
  public Point PointFromString(String str)
  {
    aterm.ATerm trm = parse(str);
    return PointFromTerm(trm);
  }
  public Point PointFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PointFromTerm(readFromFile(stream));
  }
}
