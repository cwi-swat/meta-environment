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

  //{{{ public String toString()

  public String toString()
  {
    StringBuffer buf = new StringBuffer();
    Iterator iter = tree.iterator();
    boolean first = true;
    while (iter.hasNext()) {
      if (first) {
	first = false;
      } else {
	buf.append(' ');
      }
      buf.append(iter.next().toString());
    }

    return buf.toString();
  }

  //}}}
}
