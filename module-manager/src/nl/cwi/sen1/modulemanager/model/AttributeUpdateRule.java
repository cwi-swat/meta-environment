package nl.cwi.sen1.modulemanager.model;

import aterm.ATerm;

public class AttributeUpdateRule {
	private ATerm namespace;

	private ATerm key;

	private ATerm formula;

	private ATerm predicateValue;

	public AttributeUpdateRule(ATerm namespace, ATerm key, ATerm formula,
			ATerm predicateValue) {
		this.namespace = namespace;
		this.key = key;
		this.predicateValue = predicateValue;
		this.formula = formula;
	}

	public ATerm getKey() {
		return key;
	}

	public ATerm getNamespace() {
		return namespace;
	}

	public ATerm getPredicateValue() {
		return predicateValue;
	}

	public ATerm getFormula() {
		return formula;
	}

	public boolean equals(Object o) {
		AttributeUpdateRule attr = (AttributeUpdateRule) o;
		return attr.namespace.isEqual(namespace) && attr.key.isEqual(key)
				&& attr.predicateValue.isEqual(predicateValue)
				&& attr.formula.isEqual(formula);
	}

	public String toString() {
		return "attr[" + namespace + ", " + key + ", rule:" + formula
				+ ", new:" + predicateValue + "]";
	}
}