package metastudio.graph;

import aterm.pure.PureFactory;
public class MetaGraphFactory extends PureFactory
{
  private aterm.AFun funGraph_Default;
  private Graph protoGraph_Default;
  private aterm.AFun funNodeList_Empty;
  private NodeList protoNodeList_Empty;
  private aterm.AFun funNodeList_Multi;
  private NodeList protoNodeList_Multi;
  private aterm.AFun funNode_Default;
  private Node protoNode_Default;
  private aterm.AFun funNodeId_Default;
  private NodeId protoNodeId_Default;
  private aterm.AFun funAttributeList_Empty;
  private AttributeList protoAttributeList_Empty;
  private aterm.AFun funAttributeList_Multi;
  private AttributeList protoAttributeList_Multi;
  private aterm.AFun funAttribute_Label;
  private Attribute protoAttribute_Label;
  private aterm.AFun funAttribute_Shape;
  private Attribute protoAttribute_Shape;
  private aterm.AFun funAttribute_Location;
  private Attribute protoAttribute_Location;
  private aterm.AFun funAttribute_Size;
  private Attribute protoAttribute_Size;
  private aterm.AFun funAttribute_CurvePoints;
  private Attribute protoAttribute_CurvePoints;
  private aterm.AFun funAttribute_Direction;
  private Attribute protoAttribute_Direction;
  private aterm.AFun funShape_Plaintext;
  private Shape protoShape_Plaintext;
  private aterm.AFun funShape_Ellipse;
  private Shape protoShape_Ellipse;
  private aterm.AFun funShape_Circle;
  private Shape protoShape_Circle;
  private aterm.AFun funShape_Egg;
  private Shape protoShape_Egg;
  private aterm.AFun funShape_Triangle;
  private Shape protoShape_Triangle;
  private aterm.AFun funShape_Box;
  private Shape protoShape_Box;
  private aterm.AFun funShape_Diamond;
  private Shape protoShape_Diamond;
  private aterm.AFun funShape_Trapezium;
  private Shape protoShape_Trapezium;
  private aterm.AFun funShape_Parallelogram;
  private Shape protoShape_Parallelogram;
  private aterm.AFun funShape_House;
  private Shape protoShape_House;
  private aterm.AFun funShape_Hexagon;
  private Shape protoShape_Hexagon;
  private aterm.AFun funShape_Octagon;
  private Shape protoShape_Octagon;
  private aterm.AFun funDirection_Forward;
  private Direction protoDirection_Forward;
  private aterm.AFun funDirection_Back;
  private Direction protoDirection_Back;
  private aterm.AFun funDirection_Both;
  private Direction protoDirection_Both;
  private aterm.AFun funDirection_None;
  private Direction protoDirection_None;
  private aterm.AFun funEdgeList_Empty;
  private EdgeList protoEdgeList_Empty;
  private aterm.AFun funEdgeList_Multi;
  private EdgeList protoEdgeList_Multi;
  private aterm.AFun funEdge_Default;
  private Edge protoEdge_Default;
  private aterm.AFun funPolygon_Empty;
  private Polygon protoPolygon_Empty;
  private aterm.AFun funPolygon_Multi;
  private Polygon protoPolygon_Multi;
  private aterm.AFun funPoint_Default;
  private Point protoPoint_Default;
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
    Graph.initialize(this);

    Graph_Default.initializePattern();
    funGraph_Default = makeAFun("default", 2, false);
    protoGraph_Default = new Graph_Default();

    NodeList.initialize(this);

    NodeList_Empty.initializePattern();
    funNodeList_Empty = makeAFun("empty", 0, false);
    protoNodeList_Empty = new NodeList_Empty();

    NodeList_Multi.initializePattern();
    funNodeList_Multi = makeAFun("multi", 2, false);
    protoNodeList_Multi = new NodeList_Multi();

    Node.initialize(this);

    Node_Default.initializePattern();
    funNode_Default = makeAFun("default", 2, false);
    protoNode_Default = new Node_Default();

    NodeId.initialize(this);

    NodeId_Default.initializePattern();
    funNodeId_Default = makeAFun("default", 1, false);
    protoNodeId_Default = new NodeId_Default();

    AttributeList.initialize(this);

    AttributeList_Empty.initializePattern();
    funAttributeList_Empty = makeAFun("empty", 0, false);
    protoAttributeList_Empty = new AttributeList_Empty();

    AttributeList_Multi.initializePattern();
    funAttributeList_Multi = makeAFun("multi", 2, false);
    protoAttributeList_Multi = new AttributeList_Multi();

    Attribute.initialize(this);

    Attribute_Label.initializePattern();
    funAttribute_Label = makeAFun("label", 1, false);
    protoAttribute_Label = new Attribute_Label();

    Attribute_Shape.initializePattern();
    funAttribute_Shape = makeAFun("shape", 1, false);
    protoAttribute_Shape = new Attribute_Shape();

    Attribute_Location.initializePattern();
    funAttribute_Location = makeAFun("location", 2, false);
    protoAttribute_Location = new Attribute_Location();

    Attribute_Size.initializePattern();
    funAttribute_Size = makeAFun("size", 2, false);
    protoAttribute_Size = new Attribute_Size();

    Attribute_CurvePoints.initializePattern();
    funAttribute_CurvePoints = makeAFun("curve-points", 1, false);
    protoAttribute_CurvePoints = new Attribute_CurvePoints();

    Attribute_Direction.initializePattern();
    funAttribute_Direction = makeAFun("direction", 1, false);
    protoAttribute_Direction = new Attribute_Direction();

    Shape.initialize(this);

    Shape_Plaintext.initializePattern();
    funShape_Plaintext = makeAFun("plaintext", 0, false);
    protoShape_Plaintext = new Shape_Plaintext();

    Shape_Ellipse.initializePattern();
    funShape_Ellipse = makeAFun("ellipse", 0, false);
    protoShape_Ellipse = new Shape_Ellipse();

    Shape_Circle.initializePattern();
    funShape_Circle = makeAFun("circle", 0, false);
    protoShape_Circle = new Shape_Circle();

    Shape_Egg.initializePattern();
    funShape_Egg = makeAFun("egg", 0, false);
    protoShape_Egg = new Shape_Egg();

    Shape_Triangle.initializePattern();
    funShape_Triangle = makeAFun("triangle", 0, false);
    protoShape_Triangle = new Shape_Triangle();

    Shape_Box.initializePattern();
    funShape_Box = makeAFun("box", 0, false);
    protoShape_Box = new Shape_Box();

    Shape_Diamond.initializePattern();
    funShape_Diamond = makeAFun("diamond", 0, false);
    protoShape_Diamond = new Shape_Diamond();

    Shape_Trapezium.initializePattern();
    funShape_Trapezium = makeAFun("trapezium", 0, false);
    protoShape_Trapezium = new Shape_Trapezium();

    Shape_Parallelogram.initializePattern();
    funShape_Parallelogram = makeAFun("parallelogram", 0, false);
    protoShape_Parallelogram = new Shape_Parallelogram();

    Shape_House.initializePattern();
    funShape_House = makeAFun("house", 0, false);
    protoShape_House = new Shape_House();

    Shape_Hexagon.initializePattern();
    funShape_Hexagon = makeAFun("hexagon", 0, false);
    protoShape_Hexagon = new Shape_Hexagon();

    Shape_Octagon.initializePattern();
    funShape_Octagon = makeAFun("octagon", 0, false);
    protoShape_Octagon = new Shape_Octagon();

    Direction.initialize(this);

    Direction_Forward.initializePattern();
    funDirection_Forward = makeAFun("forward", 0, false);
    protoDirection_Forward = new Direction_Forward();

    Direction_Back.initializePattern();
    funDirection_Back = makeAFun("back", 0, false);
    protoDirection_Back = new Direction_Back();

    Direction_Both.initializePattern();
    funDirection_Both = makeAFun("both", 0, false);
    protoDirection_Both = new Direction_Both();

    Direction_None.initializePattern();
    funDirection_None = makeAFun("none", 0, false);
    protoDirection_None = new Direction_None();

    EdgeList.initialize(this);

    EdgeList_Empty.initializePattern();
    funEdgeList_Empty = makeAFun("empty", 0, false);
    protoEdgeList_Empty = new EdgeList_Empty();

    EdgeList_Multi.initializePattern();
    funEdgeList_Multi = makeAFun("multi", 2, false);
    protoEdgeList_Multi = new EdgeList_Multi();

    Edge.initialize(this);

    Edge_Default.initializePattern();
    funEdge_Default = makeAFun("default", 3, false);
    protoEdge_Default = new Edge_Default();

    Polygon.initialize(this);

    Polygon_Empty.initializePattern();
    funPolygon_Empty = makeAFun("empty", 0, false);
    protoPolygon_Empty = new Polygon_Empty();

    Polygon_Multi.initializePattern();
    funPolygon_Multi = makeAFun("multi", 2, false);
    protoPolygon_Multi = new Polygon_Multi();

    Point.initialize(this);

    Point_Default.initializePattern();
    funPoint_Default = makeAFun("default", 2, false);
    protoPoint_Default = new Point_Default();

  }

  protected Graph_Default makeGraph_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoGraph_Default) {
      protoGraph_Default.initHashCode(annos,fun,args);
      return (Graph_Default) build(protoGraph_Default);
    }
  }

  public Graph_Default makeGraph_Default(NodeList _nodes, EdgeList _edges) {
    aterm.ATerm[] args = new aterm.ATerm[] {_nodes, _edges};
    return makeGraph_Default( funGraph_Default, args, empty);
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

  protected Attribute_Location makeAttribute_Location(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Location) {
      protoAttribute_Location.initHashCode(annos,fun,args);
      return (Attribute_Location) build(protoAttribute_Location);
    }
  }

  public Attribute_Location makeAttribute_Location(Integer _x, Integer _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_x.intValue()), makeInt(_y.intValue())};
    return makeAttribute_Location( funAttribute_Location, args, empty);
  }

  protected Attribute_Size makeAttribute_Size(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoAttribute_Size) {
      protoAttribute_Size.initHashCode(annos,fun,args);
      return (Attribute_Size) build(protoAttribute_Size);
    }
  }

  public Attribute_Size makeAttribute_Size(Integer _width, Integer _height) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_width.intValue()), makeInt(_height.intValue())};
    return makeAttribute_Size( funAttribute_Size, args, empty);
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

  protected Point_Default makePoint_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    synchronized (protoPoint_Default) {
      protoPoint_Default.initHashCode(annos,fun,args);
      return (Point_Default) build(protoPoint_Default);
    }
  }

  public Point_Default makePoint_Default(Integer _x, Integer _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {makeInt(_x.intValue()), makeInt(_y.intValue())};
    return makePoint_Default( funPoint_Default, args, empty);
  }

}
