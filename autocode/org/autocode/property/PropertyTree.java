package org.autocode.property;

import java.util.*;

public class PropertyTree
{
  public static final int ADD = 0;
  public static final int SET = 1;

  private int type = ADD;
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

  //{{{ public int getType()

  public int getType()
  {
    return type;
  }

  //}}}
  //{{{ public void setType(int type)

  public void setType(int type)
  {
    this.type = type;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    return key + " " + value + " {" + property.toString() + "}";
  }

  //}}}
}
