package nl.cwi.sen1.modulemanager.model;

import aterm.ATerm;

public class InheritedAttribute {
	private ATerm namespace;

	private ATerm key;

	private ATerm oldValue;
	
	private ATerm childValue;

	private ATerm newValue;

    private int negation;
    
	private int type;

    public static final int IS_SET = 0;

    public static final int IS_NOT_SET = 1;
    
	public static final int INHERIT_FROM_ONE = 0;

	public static final int INHERIT_FROM_ALL = 1;

	public InheritedAttribute(ATerm namespace, ATerm key, int negation, ATerm oldValue,
			ATerm childValue, ATerm newValue, int type) {
		this.namespace = namespace;
		this.key = key;
        this.negation = negation;
		this.newValue = newValue;
		this.childValue = childValue;
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

	public ATerm getChildValue() {
		return childValue;
	}

	public ATerm getOldValue() {
		return oldValue;
	}

    public boolean isSet() {
        return negation == IS_SET;
    }
    
    public boolean isNotSet() {
        return negation == IS_NOT_SET;
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
		return "attr[" + namespace + ", " + key + ", old:" + oldValue + ", child:" + childValue + ", new:"
				+ newValue + ", " + type + "]";
	}
}
