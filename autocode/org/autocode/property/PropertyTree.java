package org.autocode.property;

import java.util.*;

public class PropertyTree
{
  private String key;
  private String value;

  private PropertyForest property;

  //{{{ public PropertyTree(String key, String value, PropertyForest property)

  public PropertyTree(String key, String value, PropertyForest property)
  {
    this.key = key;
    this.value = value;
    this.property = property;
  }

  //}}}
}
