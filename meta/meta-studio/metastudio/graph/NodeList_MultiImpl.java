package metastudio.graph;

  //{{{ imports

  //}}}
public class NodeList_MultiImpl
extends NodeList
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  private static int index_head = 0;
  private static int index_tail = 1;
  //}}}
  public shared.SharedObject duplicate() {
    NodeList_Multi clone = new NodeList_Multi();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeNodeList_Multi(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("[<term>,<list>]");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public NodeList fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      NodeList tmp = getStaticMetaGraphFactory().makeNodeList_Multi(Node.fromTerm( (aterm.ATerm) children.get(0)), NodeList.fromTerm( (aterm.ATerm) children.get(1)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  //}}}
  //{{{ isXXX and hasXXX properties

  public boolean isMulti()
  {
    return true;
  }

  public boolean hasHead()
  {
    return true;
  }

  public boolean hasTail()
  {
    return true;
  }

  //}}}
  //{{{ getters and setters

  public Node getHead()
  {
    return (Node) this.getArgument(index_head) ;
  }

  public NodeList setHead(Node _head)
  {
    return (NodeList) super.setArgument(_head, index_head);
  }

  public NodeList getTail()
  {
    return (NodeList) this.getArgument(index_tail) ;
  }

  public NodeList setTail(NodeList _tail)
  {
    return (NodeList) super.setArgument(_tail, index_tail);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof Node)) { 
          throw new RuntimeException("Argument 0 of a NodeList_Multi should have type Node");
        }
        break;
      case 1:
        if (! (arg instanceof NodeList)) { 
          throw new RuntimeException("Argument 1 of a NodeList_Multi should have type NodeList");
        }
        break;
      default: throw new RuntimeException("NodeList_Multi does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  //}}}
  protected int hashFunction() {
    int c = getArgument(1).hashCode() + (getAnnotations().hashCode()<<8);
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
