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
}
