package metastudio.graph;

abstract public class Node_DefaultImpl
extends Node
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_id = 0;
  private static int index_attributes = 1;
  public shared.SharedObject duplicate() {
    Node_Default clone = new Node_Default();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeNode_Default(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("node(<term>,<term>)");
  }

  static public Node fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Node tmp = getStaticMetaGraphFactory().makeNode_Default(NodeId.fromTerm( (aterm.ATerm) children.get(0)), AttributeList.fromTerm( (aterm.ATerm) children.get(1)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public boolean isDefault()
  {
    return true;
  }

  public boolean hasId()
  {
    return true;
  }

  public boolean hasAttributes()
  {
    return true;
  }

  public NodeId getId()
  {
    return (NodeId) this.getArgument(index_id) ;
  }

  public Node setId(NodeId _id)
  {
    return (Node) super.setArgument(_id, index_id);
  }

  public AttributeList getAttributes()
  {
    return (AttributeList) this.getArgument(index_attributes) ;
  }

  public Node setAttributes(AttributeList _attributes)
  {
    return (Node) super.setArgument(_attributes, index_attributes);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof NodeId)) { 
          throw new RuntimeException("Argument 0 of a Node_Default should have type NodeId");
        }
        break;
      case 1:
        if (! (arg instanceof AttributeList)) { 
          throw new RuntimeException("Argument 1 of a Node_Default should have type AttributeList");
        }
        break;
      default: throw new RuntimeException("Node_Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = 0x9e3779b9;
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }
}
