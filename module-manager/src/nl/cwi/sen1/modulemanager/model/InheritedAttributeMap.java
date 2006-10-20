package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import aterm.ATerm;

public class InheritedAttributeMap {
	private Map<ATerm, InheritedAttribute> map;

	public InheritedAttributeMap() {
		this.map = new HashMap<ATerm, InheritedAttribute>();
	}

	private ATerm getKey(ATerm namespace, ATerm key, ATerm value) {
		return namespace.getFactory().makeList(namespace).insert(key).insert(
				value);
	}

	public InheritedAttribute put(ATerm namespace, ATerm key, ATerm rule,
			ATerm newValue) {
		InheritedAttribute attr = makeInheritedAttribute(namespace, key, rule,
				newValue);

		map.put(getKey(namespace, key, newValue), attr);
		return attr;
	}

	public Iterator<InheritedAttribute> iterator() {
		return map.values().iterator();
	}

	public void remove(ATerm namespace, ATerm key, ATerm newValue) {
		map.remove(getKey(namespace, key, newValue));
	}

	private InheritedAttribute makeInheritedAttribute(ATerm namespace,
			ATerm key, ATerm rule, ATerm newValue) {
		InheritedAttribute attr = new InheritedAttribute(namespace, key, rule,
				newValue);
		return attr;
	}

	public int size() {
		return map.size();
	}
}
