package nl.cwi.sen1.graph;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_Graph_Default;
  private aterm.ATerm pattern_Graph_Default;


  private aterm.AFun fun_Node_Node;
  private aterm.ATerm pattern_Node_Node;
  private aterm.AFun fun_Node_Subgraph;
  private aterm.ATerm pattern_Node_Subgraph;

  private aterm.AFun fun_NodeId_Default;
  private aterm.ATerm pattern_NodeId_Default;


  private aterm.AFun fun_Attribute_BoundingBox;
  private aterm.ATerm pattern_Attribute_BoundingBox;
  private aterm.AFun fun_Attribute_Color;
  private aterm.ATerm pattern_Attribute_Color;
  private aterm.AFun fun_Attribute_CurvePoints;
  private aterm.ATerm pattern_Attribute_CurvePoints;
  private aterm.AFun fun_Attribute_Direction;
  private aterm.ATerm pattern_Attribute_Direction;
  private aterm.AFun fun_Attribute_FillColor;
  private aterm.ATerm pattern_Attribute_FillColor;
  private aterm.AFun fun_Attribute_Info;
  private aterm.ATerm pattern_Attribute_Info;
  private aterm.AFun fun_Attribute_Label;
  private aterm.ATerm pattern_Attribute_Label;
  private aterm.AFun fun_Attribute_Tooltip;
  private aterm.ATerm pattern_Attribute_Tooltip;
  private aterm.AFun fun_Attribute_Location;
  private aterm.ATerm pattern_Attribute_Location;
  private aterm.AFun fun_Attribute_Shape;
  private aterm.ATerm pattern_Attribute_Shape;
  private aterm.AFun fun_Attribute_Size;
  private aterm.ATerm pattern_Attribute_Size;
  private aterm.AFun fun_Attribute_Style;
  private aterm.ATerm pattern_Attribute_Style;
  private aterm.AFun fun_Attribute_Level;
  private aterm.ATerm pattern_Attribute_Level;
  private aterm.AFun fun_Attribute_File;
  private aterm.ATerm pattern_Attribute_File;

  private aterm.AFun fun_File_External;
  private aterm.ATerm pattern_File_External;

  private aterm.AFun fun_Color_Rgb;
  private aterm.ATerm pattern_Color_Rgb;

  private aterm.AFun fun_Style_Bold;
  private aterm.ATerm pattern_Style_Bold;
  private aterm.AFun fun_Style_Dashed;
  private aterm.ATerm pattern_Style_Dashed;
  private aterm.AFun fun_Style_Dotted;
  private aterm.ATerm pattern_Style_Dotted;
  private aterm.AFun fun_Style_Filled;
  private aterm.ATerm pattern_Style_Filled;
  private aterm.AFun fun_Style_Invisible;
  private aterm.ATerm pattern_Style_Invisible;
  private aterm.AFun fun_Style_Solid;
  private aterm.ATerm pattern_Style_Solid;

  private aterm.AFun fun_Shape_Box;
  private aterm.ATerm pattern_Shape_Box;
  private aterm.AFun fun_Shape_Circle;
  private aterm.ATerm pattern_Shape_Circle;
  private aterm.AFun fun_Shape_Diamond;
  private aterm.ATerm pattern_Shape_Diamond;
  private aterm.AFun fun_Shape_Egg;
  private aterm.ATerm pattern_Shape_Egg;
  private aterm.AFun fun_Shape_Ellipse;
  private aterm.ATerm pattern_Shape_Ellipse;
  private aterm.AFun fun_Shape_Hexagon;
  private aterm.ATerm pattern_Shape_Hexagon;
  private aterm.AFun fun_Shape_House;
  private aterm.ATerm pattern_Shape_House;
  private aterm.AFun fun_Shape_Octagon;
  private aterm.ATerm pattern_Shape_Octagon;
  private aterm.AFun fun_Shape_Parallelogram;
  private aterm.ATerm pattern_Shape_Parallelogram;
  private aterm.AFun fun_Shape_Plaintext;
  private aterm.ATerm pattern_Shape_Plaintext;
  private aterm.AFun fun_Shape_Trapezium;
  private aterm.ATerm pattern_Shape_Trapezium;
  private aterm.AFun fun_Shape_Triangle;
  private aterm.ATerm pattern_Shape_Triangle;

  private aterm.AFun fun_Direction_Forward;
  private aterm.ATerm pattern_Direction_Forward;
  private aterm.AFun fun_Direction_Back;
  private aterm.ATerm pattern_Direction_Back;
  private aterm.AFun fun_Direction_Both;
  private aterm.ATerm pattern_Direction_Both;
  private aterm.AFun fun_Direction_None;
  private aterm.ATerm pattern_Direction_None;


  private aterm.AFun fun_Edge_Default;
  private aterm.ATerm pattern_Edge_Default;


  private aterm.AFun fun_Point_Default;
  private aterm.ATerm pattern_Point_Default;

  private nl.cwi.sen1.graph.types.NodeList empty_NodeList;
  private nl.cwi.sen1.graph.types.AttributeList empty_AttributeList;
  private nl.cwi.sen1.graph.types.EdgeList empty_EdgeList;
  private nl.cwi.sen1.graph.types.Polygon empty_Polygon;

  private Factory(aterm.pure.PureFactory factory) {
    this.factory = factory;
  }

  private static Factory instance = null;

  public synchronized static Factory getInstance(aterm.pure.PureFactory factory) {
    if (instance == null) {
        instance = new Factory(factory);
        instance.initialize();
    }
    if (instance.factory != factory) {
        throw new RuntimeException("Don't create two Factory factories with differents PureFactory ");
    }
    return instance;
  }

  public aterm.pure.PureFactory getPureFactory() {
    return factory;
  }

  private void initialize() {

    pattern_Graph_Default = factory.parse("graph(<term>,<term>,<term>)");
    fun_Graph_Default = factory.makeAFun("_Graph_default", 3, false);

    empty_NodeList = (nl.cwi.sen1.graph.types.NodeList) factory.build(new nl.cwi.sen1.graph.types.NodeList(this, factory.getEmpty(), null, null));
    pattern_Node_Node = factory.parse("node(<term>,<term>)");
    fun_Node_Node = factory.makeAFun("_Node_node", 2, false);

    pattern_Node_Subgraph = factory.parse("subgraph(<term>,<term>,<term>,<term>)");
    fun_Node_Subgraph = factory.makeAFun("_Node_subgraph", 4, false);

    pattern_NodeId_Default = factory.parse("<term>");
    fun_NodeId_Default = factory.makeAFun("_NodeId_default", 1, false);

    empty_AttributeList = (nl.cwi.sen1.graph.types.AttributeList) factory.build(new nl.cwi.sen1.graph.types.AttributeList(this, factory.getEmpty(), null, null));
    pattern_Attribute_BoundingBox = factory.parse("bounding-box(<term>,<term>)");
    fun_Attribute_BoundingBox = factory.makeAFun("_Attribute_bounding-box", 2, false);

    pattern_Attribute_Color = factory.parse("color(<term>)");
    fun_Attribute_Color = factory.makeAFun("_Attribute_color", 1, false);

    pattern_Attribute_CurvePoints = factory.parse("curve-points(<term>)");
    fun_Attribute_CurvePoints = factory.makeAFun("_Attribute_curve-points", 1, false);

    pattern_Attribute_Direction = factory.parse("direction(<term>)");
    fun_Attribute_Direction = factory.makeAFun("_Attribute_direction", 1, false);

    pattern_Attribute_FillColor = factory.parse("fill-color(<term>)");
    fun_Attribute_FillColor = factory.makeAFun("_Attribute_fill-color", 1, false);

    pattern_Attribute_Info = factory.parse("info(<str>,<term>)");
    fun_Attribute_Info = factory.makeAFun("_Attribute_info", 2, false);

    pattern_Attribute_Label = factory.parse("label(<str>)");
    fun_Attribute_Label = factory.makeAFun("_Attribute_label", 1, false);

    pattern_Attribute_Tooltip = factory.parse("tooltip(<str>)");
    fun_Attribute_Tooltip = factory.makeAFun("_Attribute_tooltip", 1, false);

    pattern_Attribute_Location = factory.parse("location(<int>,<int>)");
    fun_Attribute_Location = factory.makeAFun("_Attribute_location", 2, false);

    pattern_Attribute_Shape = factory.parse("shape(<term>)");
    fun_Attribute_Shape = factory.makeAFun("_Attribute_shape", 1, false);

    pattern_Attribute_Size = factory.parse("size(<int>,<int>)");
    fun_Attribute_Size = factory.makeAFun("_Attribute_size", 2, false);

    pattern_Attribute_Style = factory.parse("style(<term>)");
    fun_Attribute_Style = factory.makeAFun("_Attribute_style", 1, false);

    pattern_Attribute_Level = factory.parse("level(<str>)");
    fun_Attribute_Level = factory.makeAFun("_Attribute_level", 1, false);

    pattern_Attribute_File = factory.parse("file(<term>)");
    fun_Attribute_File = factory.makeAFun("_Attribute_file", 1, false);

    pattern_File_External = factory.parse("<term>");
    fun_File_External = factory.makeAFun("_File_external", 1, false);

    pattern_Color_Rgb = factory.parse("rgb(<int>,<int>,<int>)");
    fun_Color_Rgb = factory.makeAFun("_Color_rgb", 3, false);

    pattern_Style_Bold = factory.parse("bold");
    fun_Style_Bold = factory.makeAFun("_Style_bold", 0, false);

    pattern_Style_Dashed = factory.parse("dashed");
    fun_Style_Dashed = factory.makeAFun("_Style_dashed", 0, false);

    pattern_Style_Dotted = factory.parse("dotted");
    fun_Style_Dotted = factory.makeAFun("_Style_dotted", 0, false);

    pattern_Style_Filled = factory.parse("filled");
    fun_Style_Filled = factory.makeAFun("_Style_filled", 0, false);

    pattern_Style_Invisible = factory.parse("invisible");
    fun_Style_Invisible = factory.makeAFun("_Style_invisible", 0, false);

    pattern_Style_Solid = factory.parse("solid");
    fun_Style_Solid = factory.makeAFun("_Style_solid", 0, false);

    pattern_Shape_Box = factory.parse("box");
    fun_Shape_Box = factory.makeAFun("_Shape_box", 0, false);

    pattern_Shape_Circle = factory.parse("circle");
    fun_Shape_Circle = factory.makeAFun("_Shape_circle", 0, false);

    pattern_Shape_Diamond = factory.parse("diamond");
    fun_Shape_Diamond = factory.makeAFun("_Shape_diamond", 0, false);

    pattern_Shape_Egg = factory.parse("egg");
    fun_Shape_Egg = factory.makeAFun("_Shape_egg", 0, false);

    pattern_Shape_Ellipse = factory.parse("ellipse");
    fun_Shape_Ellipse = factory.makeAFun("_Shape_ellipse", 0, false);

    pattern_Shape_Hexagon = factory.parse("hexagon");
    fun_Shape_Hexagon = factory.makeAFun("_Shape_hexagon", 0, false);

    pattern_Shape_House = factory.parse("house");
    fun_Shape_House = factory.makeAFun("_Shape_house", 0, false);

    pattern_Shape_Octagon = factory.parse("octagon");
    fun_Shape_Octagon = factory.makeAFun("_Shape_octagon", 0, false);

    pattern_Shape_Parallelogram = factory.parse("parallelogram");
    fun_Shape_Parallelogram = factory.makeAFun("_Shape_parallelogram", 0, false);

    pattern_Shape_Plaintext = factory.parse("plaintext");
    fun_Shape_Plaintext = factory.makeAFun("_Shape_plaintext", 0, false);

    pattern_Shape_Trapezium = factory.parse("trapezium");
    fun_Shape_Trapezium = factory.makeAFun("_Shape_trapezium", 0, false);

    pattern_Shape_Triangle = factory.parse("triangle");
    fun_Shape_Triangle = factory.makeAFun("_Shape_triangle", 0, false);

    pattern_Direction_Forward = factory.parse("forward");
    fun_Direction_Forward = factory.makeAFun("_Direction_forward", 0, false);

    pattern_Direction_Back = factory.parse("back");
    fun_Direction_Back = factory.makeAFun("_Direction_back", 0, false);

    pattern_Direction_Both = factory.parse("both");
    fun_Direction_Both = factory.makeAFun("_Direction_both", 0, false);

    pattern_Direction_None = factory.parse("none");
    fun_Direction_None = factory.makeAFun("_Direction_none", 0, false);

    empty_EdgeList = (nl.cwi.sen1.graph.types.EdgeList) factory.build(new nl.cwi.sen1.graph.types.EdgeList(this, factory.getEmpty(), null, null));
    pattern_Edge_Default = factory.parse("edge(<term>,<term>,<term>)");
    fun_Edge_Default = factory.makeAFun("_Edge_default", 3, false);

    empty_Polygon = (nl.cwi.sen1.graph.types.Polygon) factory.build(new nl.cwi.sen1.graph.types.Polygon(this, factory.getEmpty(), null, null));
    pattern_Point_Default = factory.parse("point(<int>,<int>)");
    fun_Point_Default = factory.makeAFun("_Point_default", 2, false);

  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.graph.types.graph.Default makeGraph_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.graph.Default) factory.build( new nl.cwi.sen1.graph.types.graph.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.graph.Default makeGraph_Default(nl.cwi.sen1.graph.types.NodeList _nodes, nl.cwi.sen1.graph.types.EdgeList _edges, nl.cwi.sen1.graph.types.AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_nodes, _edges, _attributes};
    return makeGraph_Default(fun_Graph_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Graph Graph_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Graph_Default);

    if (children != null) {
      return makeGraph_Default(
        NodeListFromTerm((aterm.ATerm) children.get(0)),
        EdgeListFromTerm((aterm.ATerm) children.get(1)),
        AttributeListFromTerm((aterm.ATerm) children.get(2))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.graph.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getNodes().toTerm());
    args.add(arg.getEdges().toTerm());
    args.add(arg.getAttributes().toTerm());
    return factory.make(pattern_Graph_Default, args);
  }

  public nl.cwi.sen1.graph.types.node.Node makeNode_Node(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.node.Node) factory.build( new nl.cwi.sen1.graph.types.node.Node(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.node.Node makeNode_Node(nl.cwi.sen1.graph.types.NodeId _id, nl.cwi.sen1.graph.types.AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id, _attributes};
    return makeNode_Node(fun_Node_Node, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Node Node_NodeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Node_Node);

    if (children != null) {
      return makeNode_Node(
        NodeIdFromTerm((aterm.ATerm) children.get(0)),
        AttributeListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.node.Node arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId().toTerm());
    args.add(arg.getAttributes().toTerm());
    return factory.make(pattern_Node_Node, args);
  }

  public nl.cwi.sen1.graph.types.node.Subgraph makeNode_Subgraph(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.node.Subgraph) factory.build( new nl.cwi.sen1.graph.types.node.Subgraph(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.node.Subgraph makeNode_Subgraph(nl.cwi.sen1.graph.types.NodeId _id, nl.cwi.sen1.graph.types.NodeList _nodes, nl.cwi.sen1.graph.types.EdgeList _edges, nl.cwi.sen1.graph.types.AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id, _nodes, _edges, _attributes};
    return makeNode_Subgraph(fun_Node_Subgraph, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Node Node_SubgraphFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Node_Subgraph);

    if (children != null) {
      return makeNode_Subgraph(
        NodeIdFromTerm((aterm.ATerm) children.get(0)),
        NodeListFromTerm((aterm.ATerm) children.get(1)),
        EdgeListFromTerm((aterm.ATerm) children.get(2)),
        AttributeListFromTerm((aterm.ATerm) children.get(3))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.node.Subgraph arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId().toTerm());
    args.add(arg.getNodes().toTerm());
    args.add(arg.getEdges().toTerm());
    args.add(arg.getAttributes().toTerm());
    return factory.make(pattern_Node_Subgraph, args);
  }

  public nl.cwi.sen1.graph.types.nodeid.Default makeNodeId_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.nodeid.Default) factory.build( new nl.cwi.sen1.graph.types.nodeid.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.nodeid.Default makeNodeId_Default(aterm.ATerm _id) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id};
    return makeNodeId_Default(fun_NodeId_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.NodeId NodeId_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_NodeId_Default);

    if (children != null) {
      return makeNodeId_Default(
        (aterm.ATerm) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.nodeid.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId());
    return factory.make(pattern_NodeId_Default, args);
  }

  public nl.cwi.sen1.graph.types.attribute.BoundingBox makeAttribute_BoundingBox(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.BoundingBox) factory.build( new nl.cwi.sen1.graph.types.attribute.BoundingBox(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.BoundingBox makeAttribute_BoundingBox(nl.cwi.sen1.graph.types.Point _first, nl.cwi.sen1.graph.types.Point _second) {
    aterm.ATerm[] args = new aterm.ATerm[] {_first, _second};
    return makeAttribute_BoundingBox(fun_Attribute_BoundingBox, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_BoundingBoxFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_BoundingBox);

    if (children != null) {
      return makeAttribute_BoundingBox(
        PointFromTerm((aterm.ATerm) children.get(0)),
        PointFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.BoundingBox arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFirst().toTerm());
    args.add(arg.getSecond().toTerm());
    return factory.make(pattern_Attribute_BoundingBox, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Color makeAttribute_Color(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Color) factory.build( new nl.cwi.sen1.graph.types.attribute.Color(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Color makeAttribute_Color(nl.cwi.sen1.graph.types.Color _color) {
    aterm.ATerm[] args = new aterm.ATerm[] {_color};
    return makeAttribute_Color(fun_Attribute_Color, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_ColorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Color);

    if (children != null) {
      return makeAttribute_Color(
        ColorFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Color arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColor().toTerm());
    return factory.make(pattern_Attribute_Color, args);
  }

  public nl.cwi.sen1.graph.types.attribute.CurvePoints makeAttribute_CurvePoints(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.CurvePoints) factory.build( new nl.cwi.sen1.graph.types.attribute.CurvePoints(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.CurvePoints makeAttribute_CurvePoints(nl.cwi.sen1.graph.types.Polygon _points) {
    aterm.ATerm[] args = new aterm.ATerm[] {_points};
    return makeAttribute_CurvePoints(fun_Attribute_CurvePoints, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_CurvePointsFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_CurvePoints);

    if (children != null) {
      return makeAttribute_CurvePoints(
        PolygonFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.CurvePoints arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getPoints().toTerm());
    return factory.make(pattern_Attribute_CurvePoints, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Direction makeAttribute_Direction(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Direction) factory.build( new nl.cwi.sen1.graph.types.attribute.Direction(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Direction makeAttribute_Direction(nl.cwi.sen1.graph.types.Direction _direction) {
    aterm.ATerm[] args = new aterm.ATerm[] {_direction};
    return makeAttribute_Direction(fun_Attribute_Direction, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_DirectionFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Direction);

    if (children != null) {
      return makeAttribute_Direction(
        DirectionFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Direction arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDirection().toTerm());
    return factory.make(pattern_Attribute_Direction, args);
  }

  public nl.cwi.sen1.graph.types.attribute.FillColor makeAttribute_FillColor(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.FillColor) factory.build( new nl.cwi.sen1.graph.types.attribute.FillColor(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.FillColor makeAttribute_FillColor(nl.cwi.sen1.graph.types.Color _color) {
    aterm.ATerm[] args = new aterm.ATerm[] {_color};
    return makeAttribute_FillColor(fun_Attribute_FillColor, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_FillColorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_FillColor);

    if (children != null) {
      return makeAttribute_FillColor(
        ColorFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.FillColor arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColor().toTerm());
    return factory.make(pattern_Attribute_FillColor, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Info makeAttribute_Info(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Info) factory.build( new nl.cwi.sen1.graph.types.attribute.Info(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Info makeAttribute_Info(String _key, aterm.ATerm _value) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_key, 0, true)), _value};
    return makeAttribute_Info(fun_Attribute_Info, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_InfoFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Info);

    if (children != null) {
      return makeAttribute_Info(
        (String) children.get(0),
        (aterm.ATerm) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Info arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getKey());
    args.add(arg.getValue());
    return factory.make(pattern_Attribute_Info, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Label makeAttribute_Label(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Label) factory.build( new nl.cwi.sen1.graph.types.attribute.Label(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Label makeAttribute_Label(String _label) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_label, 0, true))};
    return makeAttribute_Label(fun_Attribute_Label, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_LabelFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Label);

    if (children != null) {
      return makeAttribute_Label(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Label arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLabel());
    return factory.make(pattern_Attribute_Label, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Tooltip makeAttribute_Tooltip(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Tooltip) factory.build( new nl.cwi.sen1.graph.types.attribute.Tooltip(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Tooltip makeAttribute_Tooltip(String _tooltip) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_tooltip, 0, true))};
    return makeAttribute_Tooltip(fun_Attribute_Tooltip, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_TooltipFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Tooltip);

    if (children != null) {
      return makeAttribute_Tooltip(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Tooltip arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getTooltip());
    return factory.make(pattern_Attribute_Tooltip, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Location makeAttribute_Location(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Location) factory.build( new nl.cwi.sen1.graph.types.attribute.Location(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Location makeAttribute_Location(int _x, int _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_x), factory.makeInt(_y)};
    return makeAttribute_Location(fun_Attribute_Location, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_LocationFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Location);

    if (children != null) {
      return makeAttribute_Location(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Location arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getX()));
    args.add(new Integer(arg.getY()));
    return factory.make(pattern_Attribute_Location, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Shape makeAttribute_Shape(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Shape) factory.build( new nl.cwi.sen1.graph.types.attribute.Shape(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Shape makeAttribute_Shape(nl.cwi.sen1.graph.types.Shape _shape) {
    aterm.ATerm[] args = new aterm.ATerm[] {_shape};
    return makeAttribute_Shape(fun_Attribute_Shape, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_ShapeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Shape);

    if (children != null) {
      return makeAttribute_Shape(
        ShapeFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Shape arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getShape().toTerm());
    return factory.make(pattern_Attribute_Shape, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Size makeAttribute_Size(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Size) factory.build( new nl.cwi.sen1.graph.types.attribute.Size(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Size makeAttribute_Size(int _width, int _height) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_width), factory.makeInt(_height)};
    return makeAttribute_Size(fun_Attribute_Size, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_SizeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Size);

    if (children != null) {
      return makeAttribute_Size(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Size arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getWidth()));
    args.add(new Integer(arg.getHeight()));
    return factory.make(pattern_Attribute_Size, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Style makeAttribute_Style(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Style) factory.build( new nl.cwi.sen1.graph.types.attribute.Style(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Style makeAttribute_Style(nl.cwi.sen1.graph.types.Style _style) {
    aterm.ATerm[] args = new aterm.ATerm[] {_style};
    return makeAttribute_Style(fun_Attribute_Style, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_StyleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Style);

    if (children != null) {
      return makeAttribute_Style(
        StyleFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Style arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getStyle().toTerm());
    return factory.make(pattern_Attribute_Style, args);
  }

  public nl.cwi.sen1.graph.types.attribute.Level makeAttribute_Level(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.Level) factory.build( new nl.cwi.sen1.graph.types.attribute.Level(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.Level makeAttribute_Level(String _level) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_level, 0, true))};
    return makeAttribute_Level(fun_Attribute_Level, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_LevelFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Level);

    if (children != null) {
      return makeAttribute_Level(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.Level arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLevel());
    return factory.make(pattern_Attribute_Level, args);
  }

  public nl.cwi.sen1.graph.types.attribute.File makeAttribute_File(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.attribute.File) factory.build( new nl.cwi.sen1.graph.types.attribute.File(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.attribute.File makeAttribute_File(nl.cwi.sen1.graph.types.File _file) {
    aterm.ATerm[] args = new aterm.ATerm[] {_file};
    return makeAttribute_File(fun_Attribute_File, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Attribute Attribute_FileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_File);

    if (children != null) {
      return makeAttribute_File(
        FileFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.attribute.File arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFile().toTerm());
    return factory.make(pattern_Attribute_File, args);
  }

  public nl.cwi.sen1.graph.types.file.External makeFile_External(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.file.External) factory.build( new nl.cwi.sen1.graph.types.file.External(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.file.External makeFile_External(aterm.ATerm _file) {
    aterm.ATerm[] args = new aterm.ATerm[] {_file};
    return makeFile_External(fun_File_External, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.File File_ExternalFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_File_External);

    if (children != null) {
      return makeFile_External(
        (aterm.ATerm) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.file.External arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFile());
    return factory.make(pattern_File_External, args);
  }

  public nl.cwi.sen1.graph.types.color.Rgb makeColor_Rgb(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.color.Rgb) factory.build( new nl.cwi.sen1.graph.types.color.Rgb(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.color.Rgb makeColor_Rgb(int _red, int _green, int _blue) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_red), factory.makeInt(_green), factory.makeInt(_blue)};
    return makeColor_Rgb(fun_Color_Rgb, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Color Color_RgbFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Color_Rgb);

    if (children != null) {
      return makeColor_Rgb(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue(),
        ((Integer) children.get(2)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.color.Rgb arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getRed()));
    args.add(new Integer(arg.getGreen()));
    args.add(new Integer(arg.getBlue()));
    return factory.make(pattern_Color_Rgb, args);
  }

  public nl.cwi.sen1.graph.types.style.Bold makeStyle_Bold(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Bold) factory.build( new nl.cwi.sen1.graph.types.style.Bold(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Bold makeStyle_Bold() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Bold(fun_Style_Bold, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_BoldFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Bold);

    if (children != null) {
      return makeStyle_Bold(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Bold arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Bold, args);
  }

  public nl.cwi.sen1.graph.types.style.Dashed makeStyle_Dashed(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Dashed) factory.build( new nl.cwi.sen1.graph.types.style.Dashed(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Dashed makeStyle_Dashed() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Dashed(fun_Style_Dashed, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_DashedFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Dashed);

    if (children != null) {
      return makeStyle_Dashed(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Dashed arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Dashed, args);
  }

  public nl.cwi.sen1.graph.types.style.Dotted makeStyle_Dotted(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Dotted) factory.build( new nl.cwi.sen1.graph.types.style.Dotted(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Dotted makeStyle_Dotted() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Dotted(fun_Style_Dotted, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_DottedFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Dotted);

    if (children != null) {
      return makeStyle_Dotted(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Dotted arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Dotted, args);
  }

  public nl.cwi.sen1.graph.types.style.Filled makeStyle_Filled(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Filled) factory.build( new nl.cwi.sen1.graph.types.style.Filled(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Filled makeStyle_Filled() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Filled(fun_Style_Filled, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_FilledFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Filled);

    if (children != null) {
      return makeStyle_Filled(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Filled arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Filled, args);
  }

  public nl.cwi.sen1.graph.types.style.Invisible makeStyle_Invisible(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Invisible) factory.build( new nl.cwi.sen1.graph.types.style.Invisible(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Invisible makeStyle_Invisible() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Invisible(fun_Style_Invisible, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_InvisibleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Invisible);

    if (children != null) {
      return makeStyle_Invisible(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Invisible arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Invisible, args);
  }

  public nl.cwi.sen1.graph.types.style.Solid makeStyle_Solid(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.style.Solid) factory.build( new nl.cwi.sen1.graph.types.style.Solid(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.style.Solid makeStyle_Solid() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeStyle_Solid(fun_Style_Solid, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Style Style_SolidFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Style_Solid);

    if (children != null) {
      return makeStyle_Solid(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.style.Solid arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Style_Solid, args);
  }

  public nl.cwi.sen1.graph.types.shape.Box makeShape_Box(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Box) factory.build( new nl.cwi.sen1.graph.types.shape.Box(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Box makeShape_Box() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Box(fun_Shape_Box, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_BoxFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Box);

    if (children != null) {
      return makeShape_Box(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Box arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Box, args);
  }

  public nl.cwi.sen1.graph.types.shape.Circle makeShape_Circle(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Circle) factory.build( new nl.cwi.sen1.graph.types.shape.Circle(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Circle makeShape_Circle() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Circle(fun_Shape_Circle, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_CircleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Circle);

    if (children != null) {
      return makeShape_Circle(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Circle arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Circle, args);
  }

  public nl.cwi.sen1.graph.types.shape.Diamond makeShape_Diamond(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Diamond) factory.build( new nl.cwi.sen1.graph.types.shape.Diamond(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Diamond makeShape_Diamond() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Diamond(fun_Shape_Diamond, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_DiamondFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Diamond);

    if (children != null) {
      return makeShape_Diamond(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Diamond arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Diamond, args);
  }

  public nl.cwi.sen1.graph.types.shape.Egg makeShape_Egg(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Egg) factory.build( new nl.cwi.sen1.graph.types.shape.Egg(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Egg makeShape_Egg() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Egg(fun_Shape_Egg, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_EggFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Egg);

    if (children != null) {
      return makeShape_Egg(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Egg arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Egg, args);
  }

  public nl.cwi.sen1.graph.types.shape.Ellipse makeShape_Ellipse(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Ellipse) factory.build( new nl.cwi.sen1.graph.types.shape.Ellipse(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Ellipse makeShape_Ellipse() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Ellipse(fun_Shape_Ellipse, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_EllipseFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Ellipse);

    if (children != null) {
      return makeShape_Ellipse(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Ellipse arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Ellipse, args);
  }

  public nl.cwi.sen1.graph.types.shape.Hexagon makeShape_Hexagon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Hexagon) factory.build( new nl.cwi.sen1.graph.types.shape.Hexagon(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Hexagon makeShape_Hexagon() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Hexagon(fun_Shape_Hexagon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_HexagonFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Hexagon);

    if (children != null) {
      return makeShape_Hexagon(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Hexagon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Hexagon, args);
  }

  public nl.cwi.sen1.graph.types.shape.House makeShape_House(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.House) factory.build( new nl.cwi.sen1.graph.types.shape.House(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.House makeShape_House() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_House(fun_Shape_House, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_HouseFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_House);

    if (children != null) {
      return makeShape_House(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.House arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_House, args);
  }

  public nl.cwi.sen1.graph.types.shape.Octagon makeShape_Octagon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Octagon) factory.build( new nl.cwi.sen1.graph.types.shape.Octagon(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Octagon makeShape_Octagon() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Octagon(fun_Shape_Octagon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_OctagonFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Octagon);

    if (children != null) {
      return makeShape_Octagon(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Octagon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Octagon, args);
  }

  public nl.cwi.sen1.graph.types.shape.Parallelogram makeShape_Parallelogram(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Parallelogram) factory.build( new nl.cwi.sen1.graph.types.shape.Parallelogram(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Parallelogram makeShape_Parallelogram() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Parallelogram(fun_Shape_Parallelogram, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_ParallelogramFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Parallelogram);

    if (children != null) {
      return makeShape_Parallelogram(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Parallelogram arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Parallelogram, args);
  }

  public nl.cwi.sen1.graph.types.shape.Plaintext makeShape_Plaintext(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Plaintext) factory.build( new nl.cwi.sen1.graph.types.shape.Plaintext(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Plaintext makeShape_Plaintext() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Plaintext(fun_Shape_Plaintext, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_PlaintextFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Plaintext);

    if (children != null) {
      return makeShape_Plaintext(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Plaintext arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Plaintext, args);
  }

  public nl.cwi.sen1.graph.types.shape.Trapezium makeShape_Trapezium(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Trapezium) factory.build( new nl.cwi.sen1.graph.types.shape.Trapezium(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Trapezium makeShape_Trapezium() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Trapezium(fun_Shape_Trapezium, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_TrapeziumFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Trapezium);

    if (children != null) {
      return makeShape_Trapezium(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Trapezium arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Trapezium, args);
  }

  public nl.cwi.sen1.graph.types.shape.Triangle makeShape_Triangle(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.shape.Triangle) factory.build( new nl.cwi.sen1.graph.types.shape.Triangle(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.shape.Triangle makeShape_Triangle() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeShape_Triangle(fun_Shape_Triangle, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Shape Shape_TriangleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Shape_Triangle);

    if (children != null) {
      return makeShape_Triangle(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.shape.Triangle arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Shape_Triangle, args);
  }

  public nl.cwi.sen1.graph.types.direction.Forward makeDirection_Forward(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.direction.Forward) factory.build( new nl.cwi.sen1.graph.types.direction.Forward(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.direction.Forward makeDirection_Forward() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Forward(fun_Direction_Forward, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Direction Direction_ForwardFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Direction_Forward);

    if (children != null) {
      return makeDirection_Forward(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.direction.Forward arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Direction_Forward, args);
  }

  public nl.cwi.sen1.graph.types.direction.Back makeDirection_Back(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.direction.Back) factory.build( new nl.cwi.sen1.graph.types.direction.Back(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.direction.Back makeDirection_Back() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Back(fun_Direction_Back, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Direction Direction_BackFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Direction_Back);

    if (children != null) {
      return makeDirection_Back(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.direction.Back arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Direction_Back, args);
  }

  public nl.cwi.sen1.graph.types.direction.Both makeDirection_Both(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.direction.Both) factory.build( new nl.cwi.sen1.graph.types.direction.Both(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.direction.Both makeDirection_Both() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_Both(fun_Direction_Both, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Direction Direction_BothFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Direction_Both);

    if (children != null) {
      return makeDirection_Both(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.direction.Both arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Direction_Both, args);
  }

  public nl.cwi.sen1.graph.types.direction.None makeDirection_None(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.direction.None) factory.build( new nl.cwi.sen1.graph.types.direction.None(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.direction.None makeDirection_None() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeDirection_None(fun_Direction_None, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Direction Direction_NoneFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Direction_None);

    if (children != null) {
      return makeDirection_None(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.direction.None arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Direction_None, args);
  }

  public nl.cwi.sen1.graph.types.edge.Default makeEdge_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.edge.Default) factory.build( new nl.cwi.sen1.graph.types.edge.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.edge.Default makeEdge_Default(nl.cwi.sen1.graph.types.NodeId _from, nl.cwi.sen1.graph.types.NodeId _to, nl.cwi.sen1.graph.types.AttributeList _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_from, _to, _attributes};
    return makeEdge_Default(fun_Edge_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Edge Edge_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Edge_Default);

    if (children != null) {
      return makeEdge_Default(
        NodeIdFromTerm((aterm.ATerm) children.get(0)),
        NodeIdFromTerm((aterm.ATerm) children.get(1)),
        AttributeListFromTerm((aterm.ATerm) children.get(2))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.edge.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFrom().toTerm());
    args.add(arg.getTo().toTerm());
    args.add(arg.getAttributes().toTerm());
    return factory.make(pattern_Edge_Default, args);
  }

  public nl.cwi.sen1.graph.types.point.Default makePoint_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.graph.types.point.Default) factory.build( new nl.cwi.sen1.graph.types.point.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.graph.types.point.Default makePoint_Default(int _x, int _y) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_x), factory.makeInt(_y)};
    return makePoint_Default(fun_Point_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.graph.types.Point Point_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Point_Default);

    if (children != null) {
      return makePoint_Default(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.graph.types.point.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getX()));
    args.add(new Integer(arg.getY()));
    return factory.make(pattern_Point_Default, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.graph.types.NodeList makeNodeList() {
    return empty_NodeList;
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem) {
    return makeNodeList(elem, empty_NodeList);
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node head, nl.cwi.sen1.graph.types.NodeList tail) {
    return makeNodeList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.graph.types.NodeList) factory.build(new nl.cwi.sen1.graph.types.NodeList(this, annos, head, tail));
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem0, nl.cwi.sen1.graph.types.Node elem1) {
    return makeNodeList(elem0, makeNodeList(elem1));
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem0, nl.cwi.sen1.graph.types.Node elem1, nl.cwi.sen1.graph.types.Node elem2) {
    return makeNodeList(elem0, makeNodeList(elem1, elem2));
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem0, nl.cwi.sen1.graph.types.Node elem1, nl.cwi.sen1.graph.types.Node elem2, nl.cwi.sen1.graph.types.Node elem3) {
    return makeNodeList(elem0, makeNodeList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem0, nl.cwi.sen1.graph.types.Node elem1, nl.cwi.sen1.graph.types.Node elem2, nl.cwi.sen1.graph.types.Node elem3, nl.cwi.sen1.graph.types.Node elem4) {
    return makeNodeList(elem0, makeNodeList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.graph.types.NodeList makeNodeList(nl.cwi.sen1.graph.types.Node elem0, nl.cwi.sen1.graph.types.Node elem1, nl.cwi.sen1.graph.types.Node elem2, nl.cwi.sen1.graph.types.Node elem3, nl.cwi.sen1.graph.types.Node elem4, nl.cwi.sen1.graph.types.Node elem5) {
    return makeNodeList(elem0, makeNodeList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.graph.types.NodeList reverse(nl.cwi.sen1.graph.types.NodeList arg) {
    nl.cwi.sen1.graph.types.NodeList reversed = makeNodeList();
    while (!arg.isEmpty()) {
      reversed = makeNodeList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.graph.types.NodeList concat(nl.cwi.sen1.graph.types.NodeList arg0, nl.cwi.sen1.graph.types.NodeList arg1) {
    nl.cwi.sen1.graph.types.NodeList result = arg1;

    for (nl.cwi.sen1.graph.types.NodeList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeNodeList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.graph.types.NodeList append(nl.cwi.sen1.graph.types.NodeList list, nl.cwi.sen1.graph.types.Node elem) {
    return concat(list, makeNodeList(elem));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList() {
    return empty_AttributeList;
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem) {
    return makeAttributeList(elem, empty_AttributeList);
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute head, nl.cwi.sen1.graph.types.AttributeList tail) {
    return makeAttributeList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.graph.types.AttributeList) factory.build(new nl.cwi.sen1.graph.types.AttributeList(this, annos, head, tail));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem0, nl.cwi.sen1.graph.types.Attribute elem1) {
    return makeAttributeList(elem0, makeAttributeList(elem1));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem0, nl.cwi.sen1.graph.types.Attribute elem1, nl.cwi.sen1.graph.types.Attribute elem2) {
    return makeAttributeList(elem0, makeAttributeList(elem1, elem2));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem0, nl.cwi.sen1.graph.types.Attribute elem1, nl.cwi.sen1.graph.types.Attribute elem2, nl.cwi.sen1.graph.types.Attribute elem3) {
    return makeAttributeList(elem0, makeAttributeList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem0, nl.cwi.sen1.graph.types.Attribute elem1, nl.cwi.sen1.graph.types.Attribute elem2, nl.cwi.sen1.graph.types.Attribute elem3, nl.cwi.sen1.graph.types.Attribute elem4) {
    return makeAttributeList(elem0, makeAttributeList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.graph.types.AttributeList makeAttributeList(nl.cwi.sen1.graph.types.Attribute elem0, nl.cwi.sen1.graph.types.Attribute elem1, nl.cwi.sen1.graph.types.Attribute elem2, nl.cwi.sen1.graph.types.Attribute elem3, nl.cwi.sen1.graph.types.Attribute elem4, nl.cwi.sen1.graph.types.Attribute elem5) {
    return makeAttributeList(elem0, makeAttributeList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.graph.types.AttributeList reverse(nl.cwi.sen1.graph.types.AttributeList arg) {
    nl.cwi.sen1.graph.types.AttributeList reversed = makeAttributeList();
    while (!arg.isEmpty()) {
      reversed = makeAttributeList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.graph.types.AttributeList concat(nl.cwi.sen1.graph.types.AttributeList arg0, nl.cwi.sen1.graph.types.AttributeList arg1) {
    nl.cwi.sen1.graph.types.AttributeList result = arg1;

    for (nl.cwi.sen1.graph.types.AttributeList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeAttributeList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.graph.types.AttributeList append(nl.cwi.sen1.graph.types.AttributeList list, nl.cwi.sen1.graph.types.Attribute elem) {
    return concat(list, makeAttributeList(elem));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList() {
    return empty_EdgeList;
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem) {
    return makeEdgeList(elem, empty_EdgeList);
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge head, nl.cwi.sen1.graph.types.EdgeList tail) {
    return makeEdgeList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.graph.types.EdgeList) factory.build(new nl.cwi.sen1.graph.types.EdgeList(this, annos, head, tail));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem0, nl.cwi.sen1.graph.types.Edge elem1) {
    return makeEdgeList(elem0, makeEdgeList(elem1));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem0, nl.cwi.sen1.graph.types.Edge elem1, nl.cwi.sen1.graph.types.Edge elem2) {
    return makeEdgeList(elem0, makeEdgeList(elem1, elem2));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem0, nl.cwi.sen1.graph.types.Edge elem1, nl.cwi.sen1.graph.types.Edge elem2, nl.cwi.sen1.graph.types.Edge elem3) {
    return makeEdgeList(elem0, makeEdgeList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem0, nl.cwi.sen1.graph.types.Edge elem1, nl.cwi.sen1.graph.types.Edge elem2, nl.cwi.sen1.graph.types.Edge elem3, nl.cwi.sen1.graph.types.Edge elem4) {
    return makeEdgeList(elem0, makeEdgeList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.graph.types.EdgeList makeEdgeList(nl.cwi.sen1.graph.types.Edge elem0, nl.cwi.sen1.graph.types.Edge elem1, nl.cwi.sen1.graph.types.Edge elem2, nl.cwi.sen1.graph.types.Edge elem3, nl.cwi.sen1.graph.types.Edge elem4, nl.cwi.sen1.graph.types.Edge elem5) {
    return makeEdgeList(elem0, makeEdgeList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.graph.types.EdgeList reverse(nl.cwi.sen1.graph.types.EdgeList arg) {
    nl.cwi.sen1.graph.types.EdgeList reversed = makeEdgeList();
    while (!arg.isEmpty()) {
      reversed = makeEdgeList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.graph.types.EdgeList concat(nl.cwi.sen1.graph.types.EdgeList arg0, nl.cwi.sen1.graph.types.EdgeList arg1) {
    nl.cwi.sen1.graph.types.EdgeList result = arg1;

    for (nl.cwi.sen1.graph.types.EdgeList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeEdgeList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.graph.types.EdgeList append(nl.cwi.sen1.graph.types.EdgeList list, nl.cwi.sen1.graph.types.Edge elem) {
    return concat(list, makeEdgeList(elem));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon() {
    return empty_Polygon;
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem) {
    return makePolygon(elem, empty_Polygon);
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point head, nl.cwi.sen1.graph.types.Polygon tail) {
    return makePolygon(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.graph.types.Polygon) factory.build(new nl.cwi.sen1.graph.types.Polygon(this, annos, head, tail));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem0, nl.cwi.sen1.graph.types.Point elem1) {
    return makePolygon(elem0, makePolygon(elem1));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem0, nl.cwi.sen1.graph.types.Point elem1, nl.cwi.sen1.graph.types.Point elem2) {
    return makePolygon(elem0, makePolygon(elem1, elem2));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem0, nl.cwi.sen1.graph.types.Point elem1, nl.cwi.sen1.graph.types.Point elem2, nl.cwi.sen1.graph.types.Point elem3) {
    return makePolygon(elem0, makePolygon(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem0, nl.cwi.sen1.graph.types.Point elem1, nl.cwi.sen1.graph.types.Point elem2, nl.cwi.sen1.graph.types.Point elem3, nl.cwi.sen1.graph.types.Point elem4) {
    return makePolygon(elem0, makePolygon(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.graph.types.Polygon makePolygon(nl.cwi.sen1.graph.types.Point elem0, nl.cwi.sen1.graph.types.Point elem1, nl.cwi.sen1.graph.types.Point elem2, nl.cwi.sen1.graph.types.Point elem3, nl.cwi.sen1.graph.types.Point elem4, nl.cwi.sen1.graph.types.Point elem5) {
    return makePolygon(elem0, makePolygon(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.graph.types.Polygon reverse(nl.cwi.sen1.graph.types.Polygon arg) {
    nl.cwi.sen1.graph.types.Polygon reversed = makePolygon();
    while (!arg.isEmpty()) {
      reversed = makePolygon(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.graph.types.Polygon concat(nl.cwi.sen1.graph.types.Polygon arg0, nl.cwi.sen1.graph.types.Polygon arg1) {
    nl.cwi.sen1.graph.types.Polygon result = arg1;

    for (nl.cwi.sen1.graph.types.Polygon list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makePolygon(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.graph.types.Polygon append(nl.cwi.sen1.graph.types.Polygon list, nl.cwi.sen1.graph.types.Point elem) {
    return concat(list, makePolygon(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.graph.types.Graph GraphFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Graph tmp;
    tmp = Graph_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Graph: " + trm);
  }

  public nl.cwi.sen1.graph.types.NodeList NodeListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.graph.types.NodeList result = makeNodeList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.graph.types.Node elem = NodeFromTerm(list.getFirst());
            result = makeNodeList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a NodeList: " + trm);
  }

  public nl.cwi.sen1.graph.types.Node NodeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Node tmp;
    tmp = Node_NodeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Node_SubgraphFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Node: " + trm);
  }

  public nl.cwi.sen1.graph.types.NodeId NodeIdFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.NodeId tmp;
    tmp = NodeId_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a NodeId: " + trm);
  }

  public nl.cwi.sen1.graph.types.AttributeList AttributeListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.graph.types.AttributeList result = makeAttributeList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.graph.types.Attribute elem = AttributeFromTerm(list.getFirst());
            result = makeAttributeList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a AttributeList: " + trm);
  }

  public nl.cwi.sen1.graph.types.Attribute AttributeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Attribute tmp;
    tmp = Attribute_BoundingBoxFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_ColorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_CurvePointsFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_DirectionFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_FillColorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_InfoFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_LabelFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_TooltipFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_LocationFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_ShapeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_SizeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_StyleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_LevelFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attribute_FileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Attribute: " + trm);
  }

  public nl.cwi.sen1.graph.types.File FileFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.File tmp;
    tmp = File_ExternalFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a File: " + trm);
  }

  public nl.cwi.sen1.graph.types.Color ColorFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Color tmp;
    tmp = Color_RgbFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Color: " + trm);
  }

  public nl.cwi.sen1.graph.types.Style StyleFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Style tmp;
    tmp = Style_BoldFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Style_DashedFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Style_DottedFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Style_FilledFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Style_InvisibleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Style_SolidFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Style: " + trm);
  }

  public nl.cwi.sen1.graph.types.Shape ShapeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Shape tmp;
    tmp = Shape_BoxFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_CircleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_DiamondFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_EggFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_EllipseFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_HexagonFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_HouseFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_OctagonFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_ParallelogramFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_PlaintextFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_TrapeziumFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Shape_TriangleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Shape: " + trm);
  }

  public nl.cwi.sen1.graph.types.Direction DirectionFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Direction tmp;
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

    throw new IllegalArgumentException("This is not a Direction: " + trm);
  }

  public nl.cwi.sen1.graph.types.EdgeList EdgeListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.graph.types.EdgeList result = makeEdgeList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.graph.types.Edge elem = EdgeFromTerm(list.getFirst());
            result = makeEdgeList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a EdgeList: " + trm);
  }

  public nl.cwi.sen1.graph.types.Edge EdgeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Edge tmp;
    tmp = Edge_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Edge: " + trm);
  }

  public nl.cwi.sen1.graph.types.Polygon PolygonFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.graph.types.Polygon result = makePolygon();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.graph.types.Point elem = PointFromTerm(list.getFirst());
            result = makePolygon(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a Polygon: " + trm);
  }

  public nl.cwi.sen1.graph.types.Point PointFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.graph.types.Point tmp;
    tmp = Point_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Point: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.graph.types.Graph GraphFromString(String str) {
    return GraphFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Graph GraphFromFile(java.io.InputStream stream) throws java.io.IOException {
    return GraphFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.NodeList NodeListFromString(String str) {
    return NodeListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.NodeList NodeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Node NodeFromString(String str) {
    return NodeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Node NodeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.NodeId NodeIdFromString(String str) {
    return NodeIdFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.NodeId NodeIdFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NodeIdFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.AttributeList AttributeListFromString(String str) {
    return AttributeListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.AttributeList AttributeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Attribute AttributeFromString(String str) {
    return AttributeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Attribute AttributeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.File FileFromString(String str) {
    return FileFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.File FileFromFile(java.io.InputStream stream) throws java.io.IOException {
    return FileFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Color ColorFromString(String str) {
    return ColorFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Color ColorFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ColorFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Style StyleFromString(String str) {
    return StyleFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Style StyleFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StyleFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Shape ShapeFromString(String str) {
    return ShapeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Shape ShapeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ShapeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Direction DirectionFromString(String str) {
    return DirectionFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Direction DirectionFromFile(java.io.InputStream stream) throws java.io.IOException {
    return DirectionFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.EdgeList EdgeListFromString(String str) {
    return EdgeListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.EdgeList EdgeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return EdgeListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Edge EdgeFromString(String str) {
    return EdgeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Edge EdgeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return EdgeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Polygon PolygonFromString(String str) {
    return PolygonFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Polygon PolygonFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PolygonFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.graph.types.Point PointFromString(String str) {
    return PointFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.graph.types.Point PointFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PointFromTerm(factory.readFromFile(stream));
  }

/*genForwardingAlternativeMethods*/
/*genForwardingMakeLists*/
/*genForwardingTypeFromTermMethods*/
/*TODOgenForwardingTypeFromMethods*/
  public static String charsToString(aterm.ATerm arg) {
    aterm.ATermList list = (aterm.ATermList) arg;
    StringBuffer str = new StringBuffer();

    for ( ; !list.isEmpty(); list = list.getNext()) {
      str.append((char) ((aterm.ATermInt) list.getFirst()).getInt());
    }

    return str.toString();
  }

  public static char charToByte(aterm.ATerm arg) {

      return((char) ((aterm.ATermInt) arg).getInt());
  }

  public aterm.ATerm stringToChars(String str) {
    int len = str.length();
    byte chars[] = str.getBytes();
    aterm.ATermList result = getPureFactory().makeList();

    for (int i = len - 1; i >= 0; i--) {
      result = result.insert(getPureFactory().makeInt(chars[i]));
    }

    return result;
  }

  public aterm.ATerm byteToChar(char ch) {
      return getPureFactory().makeInt(ch);
  }

}
