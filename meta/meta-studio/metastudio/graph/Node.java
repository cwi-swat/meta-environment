package metastudio.graph;

import aterm.*;

abstract public class Node
extends NodeImpl
{
	Node(MetaGraphFactory factory) {
		super(factory);
	}

	private Attribute_Location getLocationAttribute()
  {
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (attr.isLocation()) {
	return (Attribute_Location)attr;
      }
      attrs = attrs.getTail();
    }

    return null;
  }

  //{{{ private Attribute_Label getLabelAttribute()

  private Attribute_Label getLabelAttribute()
  {
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (attr.isLabel()) {
	return (Attribute_Label)attr;
      }
      attrs = attrs.getTail();
    }

    return null;
  }

  //}}}
  //{{{ private Attribute_Size getSizeAttribute()

  private Attribute_Size getSizeAttribute()
  {
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (attr.isSize()) {
	return (Attribute_Size)attr;
      }
      attrs = attrs.getTail();
    }

    return null;
  }

  //}}}
  //{{{ private void setSizeAttribute(Attribute_Size attr)

  private Node setSizeAttribute(Attribute_Size sizeAttr)
  {
    MetaGraphFactory factory = (MetaGraphFactory)getFactory();
    AttributeList result = factory.makeAttributeList_Empty();
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (!attr.isSize()) {
	result = factory.makeAttributeList_Multi(attr, result);
      }
      attrs = attrs.getTail();
    }

    result = factory.makeAttributeList_Multi(sizeAttr, result);
    return setAttributes(result);
  }

  //}}}

  private Attribute_Info getInfoAttribute(String s)
  {
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (attr.isInfo()) {
        if (attr.getKey().equals(s)) {
	  return (Attribute_Info)attr;
        }
      }
      attrs = attrs.getTail();
    }

    return null;
  }

  private Node setInfoAttribute(Attribute_Info infoAttr)
  {
    MetaGraphFactory factory = (MetaGraphFactory)getFactory();
    AttributeList result = factory.makeAttributeList_Empty();
    AttributeList attrs = getAttributes();
    while (!attrs.isEmpty()) {
      Attribute attr = attrs.getHead();
      if (!attr.isInfo()) {
	result = factory.makeAttributeList_Multi(attr, result);
      }
      attrs = attrs.getTail();
    }

    result = factory.makeAttributeList_Multi(infoAttr, result);
    return setAttributes(result);
  }

  //{{{ public int getX()

  public int getX()
  {
    Attribute_Location location = getLocationAttribute();
    return location.getX().intValue();
  }

  //}}}
  //{{{ public int getY()

  public int getY()
  {
    Attribute_Location location = getLocationAttribute();
    return location.getY().intValue();
  }

  //}}}
  //{{{ public int getWidth()

  public int getWidth()
  {
    Attribute_Size size = getSizeAttribute();
    return size.getWidth().intValue();
  }

  //}}}
  //{{{ public int getHeight()

  public int getHeight()
  {
    Attribute_Size size = getSizeAttribute();
    return size.getHeight().intValue();
  }

  //}}}
  //{{{ public String getLabel()

  public String getLabel()
  {
    Attribute_Label label = getLabelAttribute();
    if (label == null) {
      return getId().getId();
    }
    
    return label.getLabel();
  }

  //}}}

  //{{{ public void setSize(int width, int height)

  public Node setSize(int width, int height)
  {
    MetaGraphFactory f = (MetaGraphFactory)getFactory();
    // Ugly cast can be removed when java-apigen is improved
    return setSizeAttribute((Attribute_Size)f.makeAttribute_Size(new Integer(width), new Integer(height)));
  }

  //}}}

  //{{{ public boolean isPositioned()

  public boolean isPositioned()
  {
      return getLocationAttribute() != null;
  }

  //}}}

  public boolean hasInfo(String s)
  {
    Attribute_Info attr = getInfoAttribute(s);
    return attr != null;
  }

  public ATerm getInfo(String s) 
  {
    Attribute_Info attr = getInfoAttribute(s);
    if (attr != null) {
      return attr.getValue();
    }

    return null;
  }

}
