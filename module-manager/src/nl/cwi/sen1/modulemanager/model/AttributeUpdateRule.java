package nl.cwi.sen1.modulemanager.model;

import aterm.ATerm;

public class AttributeUpdateRule {
	private ATerm namespace;

	private ATerm key;

	private ATerm rule;

	private ATerm newValue;

	public AttributeUpdateRule(ATerm namespace, ATerm key, ATerm rule,
			ATerm newValue) {
		this.namespace = namespace;
		this.key = key;
		this.newValue = newValue;
		this.rule = rule;
	}

	public ATerm getKey() {
		return key;
	}

	public ATerm getNamespace() {
		return namespace;
	}

	public ATerm getNewValue() {
		return newValue;
	}

	public ATerm getRule() {
		return rule;
	}

	public boolean equals(Object o) {
		AttributeUpdateRule attr = (AttributeUpdateRule) o;
		return attr.namespace.isEqual(namespace) && attr.key.isEqual(key)
				&& attr.newValue.isEqual(newValue)
				&& attr.rule.isEqual(rule);
	}

	public String toString() {
		return "attr[" + namespace + ", " + key + ", rule:" + rule
				+ ", new:" + newValue + "]";
	}
}