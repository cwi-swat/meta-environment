package org.autocode.property;

import java.util.*;

public class PropertyTree
{
  public static final int ADD = 0;
  public static final int SET = 1;

  private int type = ADD;
  private String key;
  private String value;

  private PropertyForest properties;

  //{{{ public PropertyTree(String key, String value, PropertyForest properties)

  public PropertyTree(String key, String value, PropertyForest properties)
  {
    this.key = key;
    this.value = value;
    this.properties = properties;
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

  //{{{ public String getKey()

  public String getKey()
  {
    return key;
  }

  //}}}
  //{{{ public String getValue()

  public String getValue()
  {
    return value;
  }

  //}}}
  //{{{ public PropertyForest getProperties()

  public PropertyForest getProperties()
  {
    return properties;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    return key + " " + value + " {" + properties.toString() + "}";
  }

  //}}}
}
