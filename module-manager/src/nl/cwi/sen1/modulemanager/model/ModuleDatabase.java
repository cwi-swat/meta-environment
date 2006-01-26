package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public class ModuleDatabase {
	private int moduleCount;

	protected Map modules;

	protected Map children;

	private InheritedAttributeMap inheritedAttributes;

	private Map parents;

	private AttributeSetListener listener;

	public ModuleDatabase(AttributeSetListener l) {
		moduleCount = 0;
		modules = new HashMap();
		children = new HashMap();
		parents = new HashMap();
		listener = l;
		inheritedAttributes = new InheritedAttributeMap();
	}

	public int getNextModuleId() {
		return moduleCount++;
	}

	public void addModule(Module module, ModuleId moduleId) {
		modules.put(moduleId, module);
		children.put(moduleId, new HashSet());
		parents.put(moduleId, new HashSet());
	}

	public void removeModule(ModuleId moduleId) {
		deleteAllDependencies(moduleId);
		modules.remove(moduleId);
		children.remove(moduleId);
		parents.remove(moduleId);
	}

	public void registerInheritedAttribute(ATerm namespace, ATerm key,
			ATerm oldValue, ATerm newValue, ATerm type) {
		InheritedAttribute attr = inheritedAttributes.put(namespace, key,
				oldValue, newValue, type);
		triggerAttributeOnAllModules(attr);
		System.err.println("registered: " + attr);
	}

	public void unregisterInheritedAttribute(ATerm namespace, ATerm key,
			ATerm oldValue, ATerm newValue) {
		inheritedAttributes.remove(namespace, key, oldValue, newValue);
	}

	private void triggerAttributeOnAllModules(InheritedAttribute attr) {
		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			triggerAttributeOnModule(attr, moduleId);
		}
	}

	private void triggerAttributeOnModule(InheritedAttribute attr,
			ModuleId moduleId) {
		Module module = (Module) modules.get(moduleId);
		ATerm value = module.getAttribute(attr.getNamespace(), attr.getKey());

		if (value != null && value.isEqual(attr.getNewValue())) {
			propagateToParents(moduleId, attr);
		}
	}

	private void triggerAllInheritedAttributes(ModuleId id) {
		for (Iterator iter = inheritedAttributes.iterator(); iter.hasNext();) {
			InheritedAttribute attr = (InheritedAttribute) iter.next();
			inherit(attr, id);
		}
	}
	
	/**
	 * Set an attribute of a module to a new value if: - the new value is
	 * different from the old value
	 * 
	 * @param moduleId
	 * @param namespace
	 * @param key
	 * @param value
	 */
	public void setAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
			ATerm value) {
		Module module = (Module) modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - addAttribute: module [" + moduleId
					+ "] doesn't exist");
			return;
		}

		ATerm oldValue = module.getAttribute(namespace, key);

		if (oldValue == null || !oldValue.isEqual(value)) {
			module.setAttribute(namespace, key, value);

			fireAttributeSetListener(moduleId, namespace, key, oldValue, value);

			InheritedAttribute attr = inheritedAttributes.get(namespace, key,
					value);

			if (attr != null) {
				propagateToParents(moduleId, attr);
			}

			/* check if the new attribute value triggers an inherited attribute */
			triggerAllInheritedAttributes(moduleId);
		} else {
			System.err.println("attribute not set" + moduleId + namespace + " "
					+ key + " " + value);
		}

	}

	private void fireAttributeSetListener(ModuleId id, ATerm namespace,
			ATerm key, ATerm oldValue, ATerm newValue) {
		listener.attributeSet(id, namespace, key, oldValue, newValue);
	}

	private void propagateToParents(ModuleId id, InheritedAttribute attr) {
		Set parents = getParents(id);

		System.err.println("propagateInheritedAttribute: " + id + "," + attr);

		for (Iterator iter = parents.iterator(); iter.hasNext();) {
			ModuleId parent = (ModuleId) iter.next();

			inherit(attr, parent);
		}
	}

	/**
	 * Changes an attribute of a certain module if: - the old value of the
	 * attribute matches the registered old value - {all,one} of it's
	 * dependencies is set to the new value
	 * 
	 * Note the hidden recursion this function call setAttribute again which may
	 * trigger this method.
	 * 
	 * @param attr
	 *            all info about an inherited attribute
	 * @param moduleId
	 *            reference to a module
	 */
	private void inherit(InheritedAttribute attr, ModuleId moduleId) {
		Module module = (Module) modules.get(moduleId);
		ATerm comparedValue = module.getAttribute(attr.getNamespace(), attr
				.getKey());

		System.err.println("inherit: an attribute (" + attr + ") for " + moduleId);
		// The first precondition is that the oldValue matches
		if (comparedValue == null
				|| (comparedValue != null && !attr.getOldValue().isEqual(
						comparedValue))) {
			System.err.println("inherit: old value does not match for " + moduleId + "("  + comparedValue + "==" + attr.getOldValue() + ")");
			return;
		}

		Set children = getChildren(moduleId);
		boolean allSet = true;
		boolean oneSet = false;

		for (Iterator innerIter = children.iterator(); innerIter.hasNext();) {
			ModuleId child = (ModuleId) innerIter.next();
			Module innerModule = (Module) modules.get(child);

			ATerm value = innerModule.getAttribute(attr.getNamespace(), attr
					.getKey());

			if (!value.isEqual(attr.getNewValue())) {
				allSet = false;
			} else {
				oneSet = true;
			}
		}

		if ((attr.inheritFromAll() && allSet)
				|| (attr.inheritFromOne() && oneSet)) {
			System.err.println("Inheriting an attribute on " + moduleId);
			setAttribute(moduleId, attr.getNamespace(), attr.getKey(), attr
					.getNewValue());
		}
		else {
			System.err.println("inherit: not all children of " + moduleId + " had the attribute");
		}
	}

	public ATerm getModuleAttribute(ModuleId moduleId, ATerm namespace,
			ATerm key) {
		Module module = (Module) modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - geModuleAttribute: module [" + moduleId
					+ "] doesn't exist");
			return null;
		}

		ATerm value = module.getAttribute(namespace, key);

		return value;
	}

	public ModuleId getModuleIdByAttribute(ATerm namespace, ATerm key,
			ATerm value) {
		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			Module module = (Module) modules.get(moduleId);

			if (module.getAttribute(namespace, key).equals(value)) {
				return moduleId;
			}
		}

		return null;
	}

	public Set getAllModules() {
		Set allModules = new HashSet();

		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			allModules.add(moduleId);
		}

		return allModules;
	}

	public void deleteModuleAttribute(ModuleId moduleId, ATerm namespace,
			ATerm key) {
		Module module = (Module) modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - deleteModuleAttribute: module ["
					+ moduleId + "] doesn't exist");
			return;
		}

		module.deleteAttribute(namespace, key);
	}

	public AttributeStore getAllAttributes(ModuleId moduleId) {
		Module module = (Module) modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - getAllAttributes: module [" + moduleId
					+ "] doesn't exist");
			return null;
		}

		return module.getAttributes();
	}

	public void addDependency(ModuleId moduleFromId, ModuleId moduleToId) {
		Set dependencies;
		Module moduleFrom = (Module) modules.get(moduleFromId);
		Module moduleTo = (Module) modules.get(moduleToId);

		if (moduleFrom == null) {
			System.err.println("MM - addDependency: module [" + moduleFromId
					+ "] doesn't exist");
			return;
		}

		if (moduleTo == null) {
			System.err.println("MM - addDependency: module [" + moduleToId
					+ "] doesn't exist");
			return;
		}

		dependencies = (Set) children.get(moduleFromId);
		dependencies.add(moduleToId);

		dependencies = (Set) parents.get(moduleToId);
		dependencies.add(moduleFromId);

	}

	public Set getChildren(ModuleId moduleId) {
		return (Set) children.get(moduleId);
	}

	public Set getAllChildren(ModuleId moduleId) {
		Set dependencies = new HashSet();
		LinkedList temp = new LinkedList();

		temp.add(moduleId);

		while (!temp.isEmpty()) {
			ModuleId tempId = (ModuleId) temp.getFirst();
			if (!dependencies.contains(tempId)) {
				dependencies.add(tempId);
				temp.addAll(getChildren(tempId));
			}
			temp.removeFirst();
		}

		return dependencies;
	}

	public Set getParents(ModuleId moduleId) {
		return (Set) parents.get(moduleId);
	}

	public Set getAllParents(ModuleId moduleId) {
		Set dependencies = new HashSet();
		LinkedList temp = new LinkedList();

		temp.add(moduleId);

		while (!temp.isEmpty()) {
			ModuleId tempId = (ModuleId) temp.getFirst();
			if (!dependencies.contains(tempId)) {
				dependencies.add(tempId);
				temp.addAll(getParents(tempId));
			}
			temp.removeFirst();
		}

		return dependencies;
	}

	public Set getClosableModules(ModuleId moduleId) {
		Set dependencies = getAllChildren(moduleId);
		LinkedList temp = new LinkedList();

		temp.addAll(dependencies);

		while (!temp.isEmpty()) {
			ModuleId tempId = (ModuleId) temp.getFirst();
			Set parents = getParents(tempId);

			if (!dependencies.containsAll(parents)) {
				Set children = getAllChildren(tempId);
				dependencies.removeAll(children);
			}

			temp.removeFirst();
		}

		return dependencies;
	}

	public void deleteDependency(ModuleId moduleFromId, ModuleId moduleToId) {
		LinkedList deps;
		Module moduleFrom = (Module) modules.get(moduleFromId);

		if (moduleFrom == null) {
			System.err.println("MM - deleteDependency: module [" + moduleFromId
					+ "] doesn't exist");
			return;
		}

		Module moduleTo = (Module) modules.get(moduleToId);

		if (moduleTo == null) {
			System.err.println("MM - deleteDependency: module [" + moduleToId
					+ "] doesn't exist");
			return;
		}

		deps = (LinkedList) children.get(moduleFromId);
		deps.remove(moduleToId);

		deps = (LinkedList) parents.get(moduleToId);
		deps.remove(moduleFromId);

	}

	public void deleteDependencies(ModuleId moduleId) {
		Set dependencies;

		Module module = (Module) modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - deleteDependencies: module [" + moduleId
					+ "] doesn't exist");
			return;
		}

		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId tempId = (ModuleId) iter.next();
			dependencies = getParents(tempId);
			if (dependencies.contains(moduleId)) {
				dependencies.remove(moduleId);
			}
		}

		dependencies = (Set) children.get(moduleId);
		dependencies.clear();
	}

	private void deleteAllDependencies(ModuleId moduleId) {
		deleteDependencies(moduleId);

		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId tempId = (ModuleId) iter.next();
			Set dependencies = getChildren(tempId);
			if (dependencies.contains(moduleId)) {
				dependencies.remove(moduleId);
			}
		}

	}

	public Map getDependencies() {
		return children;
	}
}
