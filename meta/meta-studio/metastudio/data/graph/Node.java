package metastudio.data.graph;

import aterm.*;

abstract public class Node extends NodeImpl {
    Node(MetaGraphFactory factory) {
        super(factory);
    }

    private Attribute_Location getLocationAttribute() {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isLocation()) {
                return (Attribute_Location) attr;
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    private Attribute_Color getColorAttribute() {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isColor()) {
                return (Attribute_Color) attr;
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    private Attribute_FillColor getFillColorAttribute() {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isFillColor()) {
                return (Attribute_FillColor) attr;
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    private Attribute_Label getLabelAttribute() {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isLabel()) {
                return (Attribute_Label) attr;
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    private Attribute_Size getSizeAttribute() {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isSize()) {
                return (Attribute_Size) attr;
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    private Node setSizeAttribute(Attribute_Size sizeAttr) {
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

    private Attribute_Info getInfoAttribute(String s) {
        AttributeList attrs = getAttributes();
        while (!attrs.isEmpty()) {
            Attribute attr = attrs.getHead();
            if (attr.isInfo()) {
                if (attr.getKey().equals(s)) {
                    return (Attribute_Info) attr;
                }
            }
            attrs = attrs.getTail();
        }

        return null;
    }

    public int getX() {
        Attribute_Location location = getLocationAttribute();
        return location.getX();
    }

    public int getY() {
        Attribute_Location location = getLocationAttribute();
        return location.getY();
    }

    public int getWidth() {
        Attribute_Size size = getSizeAttribute();
        return size.getWidth();
    }

    public int getHeight() {
        Attribute_Size size = getSizeAttribute();
        return size.getHeight();
    }

    public String getLabel() {
        Attribute_Label label = getLabelAttribute();
        if (label == null) {
            return getId().getId();
        }

        return label.getLabel();
    }

    private static java.awt.Color makeColor(Attribute attr) {
	if (attr == null || !attr.hasColor()) {
	  return null;
	}
	else {
	  Color color = attr.getColor();
	  int r = color.getRed();
	  int g = color.getGreen();
	  int b = color.getBlue();
	  return new java.awt.Color(r, g, b);
	}
    }

    public java.awt.Color getColor() {
      return makeColor(getColorAttribute());
    }

    public java.awt.Color getFillColor() {
	return makeColor(getFillColorAttribute());
    }

    public Node setSize(int width, int height) {
        return setSizeAttribute(factory.makeAttribute_Size(width, height));
    }

    public boolean isPositioned() {
        return getLocationAttribute() != null;
    }

    public boolean hasInfo(String s) {
        Attribute_Info attr = getInfoAttribute(s);
        return attr != null;
    }

    public ATerm getInfo(String s) {
        Attribute_Info attr = getInfoAttribute(s);
        if (attr != null) {
            return attr.getValue();
        }

        return null;
    }

}
