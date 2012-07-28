package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import aterm.ATerm;

public class AttributeUpdateRuleMap {
	private Map<ATerm, AttributeUpdateRule> map;

	public AttributeUpdateRuleMap() {
		this.map = new HashMap<ATerm, AttributeUpdateRule>();
	}

	private ATerm getKey(ATerm namespace, ATerm key, ATerm value) {
		return namespace.getFactory().makeList(namespace).insert(key).insert(
				value);
	}

	public AttributeUpdateRule put(ATerm namespace, ATerm key, ATerm rule,
			ATerm predicateValue) {
		AttributeUpdateRule attr = makeInheritedAttribute(namespace, key, rule,
				predicateValue);

		map.put(getKey(namespace, key, predicateValue), attr);
		return attr;
	}

	public Iterator<AttributeUpdateRule> iterator() {
		return map.values().iterator();
	}

	public void remove(ATerm namespace, ATerm key, ATerm predicateValue) {
		map.remove(getKey(namespace, key, predicateValue));
	}

	private AttributeUpdateRule makeInheritedAttribute(ATerm namespace,
			ATerm key, ATerm rule, ATerm predicateValue) {
		AttributeUpdateRule attr = new AttributeUpdateRule(namespace, key, rule,
				predicateValue);
		return attr;
	}

	public int size() {
		return map.size();
	}
}
