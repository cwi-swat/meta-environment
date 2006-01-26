package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import aterm.ATerm;

public class InheritedAttributeMap {
	private Map map;

	public InheritedAttributeMap() {
		this.map = new HashMap();
	}


	private ATerm getKey(ATerm namespace, ATerm key, ATerm value) {
		return namespace.getFactory().makeList(namespace).insert(key).insert(value);
	}
	
	public InheritedAttribute put(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm newValue, ATerm type) {

		InheritedAttribute attr = makeInheritedAttribute(namespace, key,
				oldValue, newValue, type);

		map.put(getKey(namespace, key, newValue), attr);
		return attr;
	}

	public Iterator iterator() {
		return map.values().iterator();
	}

	public void remove(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm newValue) {
		map.remove(getKey(namespace, key, newValue));
	}

	public InheritedAttribute get(ATerm namespace, ATerm key, ATerm newValue) {
		return (InheritedAttribute) map.get(getKey(namespace, key, newValue));
	}

	private InheritedAttribute makeInheritedAttribute(ATerm namespace,
			ATerm key, ATerm oldValue, ATerm newValue, ATerm type) {
		int inheritanceType = InheritedAttribute.INHERIT_FROM_ALL;

		if (type != null && type.isEqual(type.getFactory().parse("one"))) {
			inheritanceType = InheritedAttribute.INHERIT_FROM_ONE;
		}

		InheritedAttribute attr = new InheritedAttribute(namespace, key,
				oldValue, newValue, inheritanceType);
		return attr;
	}

}
