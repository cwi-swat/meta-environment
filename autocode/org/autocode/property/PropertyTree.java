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

  //{{{ public PropertyTree(String key, int type)

  public PropertyTree(String key, int type)
  {
    this(key, null, new PropertyForest());
    this.type = type;
  }

  //}}}
  //{{{ public PropertyTree(String key, String value, PropertyForest properties)

  public PropertyTree(String key, String value, PropertyForest properties)
  {
    this.key = key;
    this.value = value;
    this.properties = properties;
    this.type = ADD;
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

  //{{{ public String toString(int indent)

  public String toString(int indent)
  {
    StringBuffer buf = new StringBuffer();

    for (int i=0; i<indent; i++) {
      buf.append("  ");
    }
    String prefix = buf.toString();

    buf.append(key);
    buf.append(" ");

    if (type == SET) {
      buf.append(":= ");
      if (value == null) {
	buf.append("{ }");
      } else {
	buf.append(value);
      }
      if (!properties.isEmpty()) {
	throw new RuntimeException("SET tree must be empty: " +
				   properties.toString());
      }
    } else if (properties.isEmpty()
	       && (value == null || !value.equals("*"))) {
      buf.append("+= ");
      if (value == null) {
	buf.append("{ }");
      } else {
	buf.append(value);
      }
    } else {
      buf.append(value);
      buf.append(" {");
      buf.append("\n");
      buf.append(properties.toString(indent+1));
      buf.append(prefix);
      buf.append("}");
    }
    buf.append("\n");

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
