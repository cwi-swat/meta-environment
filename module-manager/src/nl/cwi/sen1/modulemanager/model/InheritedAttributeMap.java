package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import aterm.ATerm;

public class InheritedAttributeMap {
    private Map<ATerm, InheritedAttribute> map;

    public InheritedAttributeMap() {
        this.map = new HashMap<ATerm, InheritedAttribute>();
    }

    private ATerm getKey(ATerm namespace, ATerm key, ATerm oldValue,
            ATerm childValue, ATerm value) {
        return namespace.getFactory().makeList(namespace).insert(key).insert(
                oldValue).insert(childValue).insert(value);
    }

    public InheritedAttribute put(ATerm namespace, ATerm key, ATerm negation,
            ATerm oldValue, ATerm childValue, ATerm newValue, ATerm type) {

        InheritedAttribute attr = makeInheritedAttribute(namespace, key,
                negation, oldValue, childValue, newValue, type);

        map.put(getKey(namespace, key, oldValue, childValue, newValue), attr);
        return attr;
    }

    public Iterator<InheritedAttribute> iterator() {
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
            ATerm key, ATerm negation, ATerm oldValue, ATerm childValue,
            ATerm newValue, ATerm type) {
        int negOldValue = InheritedAttribute.IS_SET;
        int inheritanceType = InheritedAttribute.INHERIT_FROM_ALL;

        if (negation != null && negation.isEqual(negation.getFactory().parse("is-not-set"))) {
            negOldValue = InheritedAttribute.IS_NOT_SET;
        }
        
        if (type != null && type.isEqual(type.getFactory().parse("one"))) {
            inheritanceType = InheritedAttribute.INHERIT_FROM_ONE;
        }

        InheritedAttribute attr = new InheritedAttribute(namespace, key, negOldValue,
                oldValue, childValue, newValue, inheritanceType);
        return attr;
    }

    public int size() {
        return map.size();
    }

    public Set<InheritedAttribute> getByChildValue(ATerm namespace, ATerm key,
            ATerm value) {
        Set<InheritedAttribute> attrs = new HashSet<InheritedAttribute>();

        for (Iterator<InheritedAttribute> iter = map.values().iterator(); iter
                .hasNext();) {
            InheritedAttribute attr = iter.next();
            if (attr.getNamespace().equals(namespace)
                    && attr.getKey().equals(key)
                    && attr.getChildValue().equals(value)) {
                attrs.add(attr);
            }
        }

        return attrs;
    }
}
