package org.autocode.property;

import java.util.*;

public class PropertyContext
{
  private final static String VALUE_SEPARATOR = ".";
  private final static String KEY_SEPARATOR = "->";
  private PropertyForest forest;
  private List path;

  //{{{ public PropertyContext(PropertyForest forest)

  public PropertyContext(PropertyForest forest)
  {
    this.forest = forest;
    path = new LinkedList();
  }

  //}}}
  //{{{ public PropertyContext(PropertyContext context)

  public PropertyContext(PropertyContext context)
  {
    this.forest = context.forest;
    this.path = (List)((LinkedList)context.path).clone();
  }

  //}}}
  //{{{ public PropertyContext(PropertyContext context, key, value)

  public PropertyContext(PropertyContext context, String key, String value)
  {
    this(context);
    descend(key, value);
  }

  //}}}

  //{{{ public Set getValueSet(String key)

  public Set getValueSet(String key)
  {
    Set values = new HashSet();

    getValue(key, path, forest, values);

    return values;
  }

  //}}}
  //{{{ public String getSingletonValue(String key)

  public String getSingletonValue(String key)
  {
    Set value = getValueSet(key);
    if (value.size() != 1) {
      throw new RuntimeException("not a singleton value: key=" + key
				 + ", value=" + value);
    }
    return (String)value.iterator().next();
  }

  //}}}

  //{{{ private void getValue(leaf_key, path, forest, Set values)

  private void getValue(String leaf_key, List path, PropertyForest forest, Set values)
  {
    //System.out.println("getValue: " + leaf_key + ", " + forest);
    if (path.isEmpty()) {
      getLeafValues("*", forest, values);
      getLeafValues(leaf_key, forest, values);
    } else {
      String[] pair = (String[])path.get(0);
      String value = pair[1];
      pair[1] = "*";
      getValues(leaf_key, path, forest, values);

      pair[1] = value;
      getValues(leaf_key, path, forest, values);
    }
  }

  //}}}

  //{{{ private List skipComplexKey(String key, List path)

  private List skipComplexKey(String key, List path)
  {
    StringTokenizer tokens = new StringTokenizer(key, VALUE_SEPARATOR);
    while (tokens.hasMoreTokens()) {
      String token = tokens.nextToken();
      if (path.isEmpty()) {
	return null;
      } else {
	String[] pair = (String[])path.get(0);
	path = path.subList(1, path.size());
	if (!pair[1].equals(token)) {
	  return null;
	}
      }
    }

    return path;
  }

  //}}}
  //{{{ private void getValues(leaf_key, path, forest, values)

  private void getValues(String leaf_key, List path,
			 PropertyForest forest, Set values)
  {
    Iterator iter = forest.fetchTreeIterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();

      String complexKey = tree.getKey();
      int index = complexKey.indexOf(KEY_SEPARATOR);

      String lhs, rhs;
      if (index == -1) {
	lhs = complexKey;
	rhs = "";
      } else {
	lhs = complexKey.substring(index+KEY_SEPARATOR.length());
	rhs = complexKey.substring(0, index);
      }

      List pathLeft = skipComplexKey(rhs, path);

      if (pathLeft == null) {
	continue;
      }

      if (pathLeft.isEmpty()) {
	if (leaf_key.equals(lhs)) {
	  if (tree.getType() == PropertyTree.SET) {
	    values.clear();
	  }
	  values.add(tree.getValue());
	}
      } else {
	String[] pair = (String[])pathLeft.get(0);
	pathLeft = pathLeft.subList(1, pathLeft.size());
	String key = pair[0];
	String value = pair[1];

	if (key.equals(lhs) && value.equals(tree.getValue())) {
	  if (tree.getType() == PropertyTree.ADD) {
	    getValue(leaf_key, pathLeft, tree.getProperties(), values);
	  }
	}
      }
    }
  }

  //}}}
  //{{{ private void getLeafValues(String leaf_key, forest, Set values)

  private void getLeafValues(String leaf_key, PropertyForest forest, Set values)
  {
    Iterator iter = forest.fetchTreeIterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();
      if (leaf_key.equals(tree.getKey())) {
	String value = tree.getValue();
	if (!value.equals("*")) { // Skip trees that only augment children
	  if (tree.getType() == PropertyTree.SET) {
	    values.clear();
	  }
	  values.add(tree.getValue());
	}
      }
    }
  }

  //}}}

  //{{{ public void descend(String key, String value)

  public void descend(String key, String value)
  {
    String[] pair = { key, value };

    path.add(pair);
  }

  //}}}
}
