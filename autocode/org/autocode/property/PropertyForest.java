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

  //{{{ public String getSingletonValue(String key)

  public String getSingletonValue(String key)
  {
    Set value = getValue(key);
    if (value.size() != 1) {
      throw new RuntimeException("not a singleton value: key=" + key
				 + ", value=" + value);
    }
    return (String)value.iterator().next();
  }

  //}}}
  //{{{ public Set getValue(String key)

  public Set getValue(String key)
  {
    Set values = new HashSet();

    getValue(key, values);

    return values;
  }

  //}}}
  //{{{ private void getValue(String keyhead, String keytail, Set values)

  private void getValue(String keyhead, String keytail, Set values)
  {
    Iterator iter = tree.iterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();
      if (keyhead.equals(tree.getValue())) {
	if (tree.getType() == PropertyTree.ADD) {
	  tree.getProperties().getValue(keytail, values);
	}
      }
    }
  }

  //}}}
  //{{{ private void getEndValues(String keyhead, String keytail, Set values)

  private void getEndValues(String keyhead, Set values)
  {
    Iterator iter = tree.iterator();
    while (iter.hasNext()) {
      PropertyTree tree = (PropertyTree)iter.next();
      if (keyhead.equals(tree.getKey())) {
	String value = tree.getValue();
	if (!value.equals("*")) {
	  if (tree.getType() == PropertyTree.SET) {
	    values.clear();
	  }
	  values.add(tree.getValue());
	}
      }
    }
  }

  //}}}
  //{{{ private void getValue(String key, Set values)

  private void getValue(String key, Set values)
  {
    int sep = key.indexOf('.');

    if (sep == -1) {
      getEndValues("*", values);
      getEndValues(key, values);
    } else {
      String keyhead = key.substring(0, sep);
      String keytail = key.substring(sep + 1);
      getValue("*", keytail, values);
      getValue(keyhead, keytail, values);
    }
  }

  //}}}

  //{{{ public Iterator fetchTreeIterator()

  public Iterator fetchTreeIterator()
  {
    return tree.iterator();
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
