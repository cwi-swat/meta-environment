package org.autocode.property;

import java.util.*;

public class PropertyForest
{
  private Set tree;

  //{{{ public PropertyForest()

  public PropertyForest()
  {
    tree = new HashSet();
  }

  //}}}
  //{{{ public void addTree(PropertyTree tree)

  public void addTree(PropertyTree tree)
  {
    this.tree.add(tree);
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
