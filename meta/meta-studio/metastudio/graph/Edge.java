package metastudio.graph;

abstract public class Edge extends EdgeImpl {

	//{{{ private Attribute_CurvePoints getCurvePointsAttribute()

	private Attribute_CurvePoints getCurvePointsAttribute() {
		AttributeList attrs = getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isCurvePoints()) {
				return (Attribute_CurvePoints) attr;
			}
			attrs = attrs.getTail();
		}

		return null;
	}

	//}}}

	//{{{ public boolean isPositioned()

	public boolean isPositioned() {
		return getCurvePointsAttribute() != null;
	}

	//}}}
	//{{{ public Polygon getPolygon()

	public Polygon getPolygon() {
		return getCurvePointsAttribute().getPoints();
	}

	//}}}

	//{{{ public boolean connectedTo(Node node)

	public boolean connectedTo(Node node) {
		if (node == null) {
			return false;
		}

		return getFrom().equals(node.getId()) || getTo().equals(node.getId());
	}

	//}}}
}
