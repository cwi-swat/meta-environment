package org.autocode.property;

import java.util.*;

public class PropertyForest
{
  private List tree;

  //{{{ public PropertyForest()

  public PropertyForest()
  {
    tree = new LinkedList();
  }

  //}}}
  //{{{ public void addTree(PropertyTree tree)

  public void addTree(PropertyTree tree)
  {
    if (!this.tree.contains(tree)) {
      this.tree.add(tree);
    }
  }

  //}}}

  //{{{ public boolean isEmpty()

  public boolean isEmpty()
  {
    return tree.isEmpty();
  }

  //}}}

  //{{{ public Iterator fetchTreeIterator()

  public Iterator fetchTreeIterator()
  {
    return tree.iterator();
  }

  //}}}

  //{{{ public void merge(PropertyForest forest)

  public void merge(PropertyForest forest)
  {
    Iterator iter = forest.tree.iterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();
      addTree(tree);
    }
  }

  //}}}
  //{{{ public void merge(PropertyContext context, PropertyForest forest)

  public void merge(PropertyContext context, PropertyForest forest)
  {
    Iterator iter = forest.tree.iterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();
      addTree(tree);
    }
  }

  //}}}

  //{{{ public String toString(int indent)

  public String toString(int indent)
  {
    StringBuffer buf = new StringBuffer();

    Iterator iter = tree.iterator();
    boolean first = true;
    while (iter.hasNext()) {
      /*
      if (first) {
	first = false;
      } else {
	buf.append(' ');
      }
      */
      buf.append(((PropertyTree)iter.next()).toString(indent));
    }

    return buf.toString();
  }

  //}}}
  //{{{ public String toString()

  public String toString()
  {
    return toString(0);
  }

  //}}}
}
