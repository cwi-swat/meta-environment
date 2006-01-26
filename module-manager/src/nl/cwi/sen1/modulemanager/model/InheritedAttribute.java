package nl.cwi.sen1.modulemanager.model;

import aterm.ATerm;

public class InheritedAttribute {
	private ATerm namespace;

	private ATerm key;

	private ATerm oldValue;

	private ATerm newValue;

	private int type;

	public static final int INHERIT_FROM_ONE = 0;

	public static final int INHERIT_FROM_ALL = 1;

	public InheritedAttribute(ATerm namespace, ATerm key, ATerm oldValue,
			ATerm newValue, int type) {
		this.namespace = namespace;
		this.key = key;
		this.newValue = newValue;
		this.oldValue = oldValue;
		this.type = type;
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

	public ATerm getOldValue() {
		return oldValue;
	}
	
	public boolean inheritFromAll() {
		return type == INHERIT_FROM_ALL;
	}

	public boolean inheritFromOne() {
		return type == INHERIT_FROM_ONE;
	}

	public boolean equals(Object o) {
		InheritedAttribute attr = (InheritedAttribute) o;
		return attr.namespace.isEqual(namespace) && attr.key.isEqual(key)
				&& attr.newValue.isEqual(newValue)
				&& attr.oldValue.isEqual(oldValue);
	}

	public String toString() {
		return "attr[" + namespace + ", " + key + ", " + oldValue + ", "
				+ newValue + ", " + type + "]";
	}
}
