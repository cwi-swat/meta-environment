package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import aterm.ATerm;

public class InheritedAttributeMap {
	private Map map;

	public InheritedAttributeMap() {
		this.map = new HashMap();
	}

	private ATerm getKey(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm childValue, ATerm value) {
		return namespace.getFactory().makeList(namespace).insert(key).insert(
				oldValue).insert(childValue).insert(value);
	}

	public InheritedAttribute put(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm childValue, ATerm newValue, ATerm type) {

		InheritedAttribute attr = makeInheritedAttribute(namespace, key,
				oldValue, childValue, newValue, type);

		map.put(getKey(namespace, key, oldValue, childValue, newValue), attr);
		return attr;
	}

	public Iterator iterator() {
		return map.values().iterator();
	}

	public void remove(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm childValue, ATerm newValue) {
		map.remove(getKey(namespace, key, oldValue, childValue, newValue));
	}

	// public InheritedAttribute get(ATerm namespace, ATerm key, ATerm oldValue,
	// ATerm childValue,
	// ATerm newValue) {
	// return (InheritedAttribute) map.get(getKey(namespace, key, oldValue,
	// childValue,
	// newValue));
	// }

	private InheritedAttribute makeInheritedAttribute(ATerm namespace,
			ATerm key, ATerm oldValue, ATerm childValue, ATerm newValue,
			ATerm type) {
		int inheritanceType = InheritedAttribute.INHERIT_FROM_ALL;

		if (type != null && type.isEqual(type.getFactory().parse("one"))) {
			inheritanceType = InheritedAttribute.INHERIT_FROM_ONE;
		}

		InheritedAttribute attr = new InheritedAttribute(namespace, key,
				oldValue, childValue, newValue, inheritanceType);
		return attr;
	}

	public int size() {
		return map.size();
	}

	public Set getByChildValue(ATerm namespace, ATerm key, ATerm value) {
		Set attrs = new HashSet();
		
		for (Iterator iter = map.values().iterator(); iter.hasNext();) {
			InheritedAttribute attr = (InheritedAttribute) iter.next();
			if (attr.getNamespace().equals(namespace) && attr.getKey().equals(key) && attr.getChildValue().equals(value)) {
				attrs.add(attr);
			}
		}
		
		return attrs;
	}
}
