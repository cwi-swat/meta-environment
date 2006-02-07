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
	
	private int indent = 0;

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
			ATerm oldValue, ATerm childValue, ATerm newValue, ATerm type) {
		InheritedAttribute attr = inheritedAttributes.put(namespace, key,
				oldValue, childValue, newValue, type);
		// TODO: needs only to be done for bottom modules??
		triggerAllAttributeOnAllModules(attr);
	}

	public void unregisterInheritedAttribute(ATerm namespace, ATerm key,
			ATerm oldValue, ATerm childValue, ATerm newValue) {
		inheritedAttributes.remove(namespace, key, oldValue, childValue,
				newValue);
	}

	private void triggerAllAttributeOnAllModules(InheritedAttribute attr) {
		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			triggerAllInheritedAttributes(moduleId);
		}
	}

	private void triggerAllInheritedAttributes(ModuleId id) {
		for (Iterator iter = inheritedAttributes.iterator(); iter.hasNext();) {
			InheritedAttribute attr = (InheritedAttribute) iter.next();
			inherit(attr, id);
		}
	}

	private void triggerInheritedAttributes(ModuleId id, Set attrs) {
		for (Iterator iter = attrs.iterator(); iter.hasNext();) {
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
			indent++;
			module.setAttribute(namespace, key, value);
			
			fireAttributeSetListener(moduleId, namespace, key, oldValue, value);

			// maybe the parents of this module now have to be updated
			Set attrs = inheritedAttributes.getByChildValue(namespace, key, value);
			if (!attrs.isEmpty()) {
				propagateToParents(moduleId, attrs);
			}
			
			// maybe this module now matches the preconditions for an inherited
			// attribute
			triggerAllInheritedAttributes(moduleId);
			indent--;
		}
	}

	private void fireAttributeSetListener(ModuleId id, ATerm namespace,
			ATerm key, ATerm oldValue, ATerm newValue) {
		listener.attributeSet(id, namespace, key, oldValue, newValue);
	}

	private void propagateToParents(ModuleId id, Set attrs) {
		Set parents = getParents(id);

		for (Iterator iter = parents.iterator(); iter.hasNext();) {
			ModuleId parent = (ModuleId) iter.next();
			triggerInheritedAttributes(parent, attrs);
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
	 * If the module is part of a cycle, and all elements of the cycle are set
	 * to the old value, we may set this module to the new value too.
	 * 
	 * @param attr
	 *            all info about an inherited attribute
	 * @param moduleId
	 *            reference to a module
	 */
	private void inherit(InheritedAttribute attr, ModuleId moduleId) {
		Module module = (Module) modules.get(moduleId);
		ATerm comparedValue = getValueOfInheritedAttribute(attr, module);

		// The first precondition is that the oldValue matches (guarantees
		// termination)

		if (noMatchForOldValue(attr, comparedValue)) {
			return;
		}

		Set children = getChildren(moduleId);
		boolean allSet = true;
		boolean oneSet = false;
		boolean isCyclic = isCyclic(moduleId);

		for (Iterator iter = children.iterator(); iter.hasNext();) {
			ModuleId child = (ModuleId) iter.next();
			Module innerModule = (Module) modules.get(child);

			ATerm value = getValueOfInheritedAttribute(attr, innerModule);

			if (isCyclic && getAllChildren(child).contains(moduleId)) {
				// check if all elements of cycle are set to oldvalue or
				// newvalue
				Set cycle = getModulesInCycle(moduleId);

				for (Iterator inner = cycle.iterator(); inner.hasNext();) {
					ModuleId elem = (ModuleId) inner.next();
					Module elemModule = (Module) modules.get(elem);

					ATerm elemValue = getValueOfInheritedAttribute(attr,
							elemModule);

					if (!elemValue.isEqual(attr.getChildValue())
							&& noMatchForOldValue(attr, elemValue)) {
						allSet = false;
					} else {
						if (elemValue.isEqual(attr.getChildValue())) {
							oneSet = true;
						}
					}
				}
			} else {
				if (!value.isEqual(attr.getChildValue())) {
					allSet = false;
				} else {
					oneSet = true;
				}
			}
		}

		if ((attr.inheritFromAll() && allSet)
				|| (attr.inheritFromOne() && oneSet)) {
			setAttribute(moduleId, attr.getNamespace(), attr.getKey(), attr
					.getNewValue());
		}
	}

	private ATerm getValueOfInheritedAttribute(InheritedAttribute attr,
			Module module) {
		return module.getAttribute(attr.getNamespace(), attr.getKey());
	}

	private boolean noMatchForOldValue(InheritedAttribute attr,
			ATerm comparedValue) {
		return (attr.getOldValue().getType() != ATerm.PLACEHOLDER)
				&& (comparedValue == null || (comparedValue != null && !attr
						.getOldValue().isEqual(comparedValue)));
	}

	private void findCycles(ModuleId current, Set modules, Set path) {
		if (path.contains(current)) {
			modules.addAll(path);
		} else {
			path.add(current);
			for (Iterator iter = getChildren(current).iterator(); iter
					.hasNext();) {
				ModuleId child = (ModuleId) iter.next();
				findCycles(child, modules, path);
			}
			path.remove(current);
		}
	}

	private Set getModulesInCycle(ModuleId moduleId) {
		Set cycle = new HashSet();
		findCycles(moduleId, cycle, new HashSet());
		indentedPrint("Cycle: " + cycle);
		return cycle;
	}

	private boolean isCyclic(ModuleId id) {
		Set parents = getAllParents(id);

		return parents.contains(id);
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

		temp.addAll(getChildren(moduleId));

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

		temp.addAll(getParents(moduleId));

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
	
	private void indentedPrint(String message) {
		for (int i = 0; i < indent; i++) {
			System.err.print(" ");
		}
		System.err.println(message);
	}
}
