package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public class ModuleDatabase {
	private int moduleCount;

	protected Map<ModuleId, Module> modules;

	protected Map<ModuleId, Set<ModuleId>> descendants;

	private InheritedAttributeMap inheritedAttributes;

	private Map<ModuleId, Set<ModuleId>> ascendants;

	private AttributeSetListener listener;

	public ModuleDatabase(AttributeSetListener l) {
		moduleCount = 0;
		modules = new HashMap<ModuleId, Module>();
		descendants = new HashMap<ModuleId, Set<ModuleId>>();
		ascendants = new HashMap<ModuleId, Set<ModuleId>>();
		listener = l;
		inheritedAttributes = new InheritedAttributeMap();
	}

	public int getNextModuleId() {
		return moduleCount++;
	}

	public void addModule(Module module, ModuleId moduleId) {
		modules.put(moduleId, module);
		descendants.put(moduleId, new HashSet<ModuleId>());
		ascendants.put(moduleId, new HashSet<ModuleId>());
	}

	public void removeModule(ModuleId moduleId) {
		deleteAllDependencies(moduleId);
		modules.remove(moduleId);
		descendants.remove(moduleId);
		ascendants.remove(moduleId);
	}

	private void triggerAllAttributeOnAllModules() {
		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			triggerAllInheritedAttributes(iter.next());
		}
	}

	private void triggerAllInheritedAttributes(ModuleId id) {
		for (Iterator<InheritedAttribute> iter = inheritedAttributes.iterator(); iter
				.hasNext();) {
			inherit(iter.next(), id);
		}
	}

	public void setAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
			ATerm value) {
		Module module = modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - addAttribute: module [" + moduleId
					+ "] doesn't exist");
			return;
		}

		updateAttribute(moduleId, namespace, key, value);
	}

	private void updateAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
			ATerm value) {
		Module module = modules.get(moduleId);
		ATerm oldValue = module.getAttribute(namespace, key);

		module.deletePredicate(namespace, key);

		if (oldValue == null || !oldValue.isEqual(value)) {
			module.setAttribute(namespace, key, value);
			fireAttributeSetListener(moduleId, namespace, key, oldValue, value);
			propagateToParents(moduleId);
			triggerAllInheritedAttributes(moduleId);
		}
	}

	private void updatePredicate(ModuleId moduleId, ATerm namespace, ATerm key,
			ATerm value) {
		Module module = modules.get(moduleId);
		ATerm oldValue = module.getPredicate(namespace, key);
		if (oldValue == null) {
			oldValue = module.getAttribute(namespace, key);
		}

		if (oldValue == null || !oldValue.isEqual(value)) {
			module.setPredicate(namespace, key, value);
			fireAttributeSetListener(moduleId, namespace, key, oldValue, value);
			propagateToParents(moduleId);
		}
	}

	private void fireAttributeSetListener(ModuleId id, ATerm namespace,
			ATerm key, ATerm oldValue, ATerm newValue) {
		listener.attributeSet(id, namespace, key, oldValue, newValue);
		System.err.println("Module " + id + ": " + newValue);
	}

	private void propagateToParents(ModuleId id) {
		Set<ModuleId> parents = getParents(id);
		for (Iterator<ModuleId> iter = parents.iterator(); iter.hasNext();) {
			triggerAllInheritedAttributes(iter.next());
		}
	}

	private void inherit(InheritedAttribute attr, ModuleId id) {
		Module module = modules.get(id);
		ATerm namespace = attr.getNamespace();
		ATerm key = attr.getKey();
		
		ATerm oldPredicate = module.getPredicate(namespace, key);
		ATerm newPredicate = attr.getNewValue();

		ATerm oldValue = module.getAttribute(namespace, key);

		ATerm rule = attr.getRule();
		Boolean result = innermostRuleEvaluation(rule, id, namespace, key);
		System.err.println("Module " + id + ": " + rule + " = " + result);

		if (result) {
			updatePredicate(id, namespace, key, newPredicate);
		} 
		else if (oldPredicate != null && newPredicate.equals(oldPredicate)) {
			module.deletePredicate(namespace, key);
			fireAttributeSetListener(id, namespace, key, oldPredicate,
					oldValue);
			propagateToParents(id);
		}
	}

	public ATerm getModuleAttribute(ModuleId moduleId, ATerm namespace,
			ATerm key) {
		Module module = modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - getModuleAttribute: module [" + moduleId
					+ "] doesn't exist");
			return null;
		}

		ATerm value = module.getPredicate(namespace, key);
		if (value == null) {
			value = module.getAttribute(namespace, key);
		}

		return value;
	}

	public ModuleId getModuleIdByAttribute(ATerm namespace, ATerm key,
			ATerm value) {
		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			ModuleId moduleId = iter.next();
			Module module = modules.get(moduleId);

			if (value.equals(module.getPredicate(namespace, key))) {
				return moduleId;
			} else if (module.getAttribute(namespace, key).equals(value)) {
				return moduleId;
			}
		}

		return null;
	}

	public Set<ModuleId> getAllModules() {
		Set<ModuleId> allModules = new HashSet<ModuleId>();

		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			allModules.add(iter.next());
		}

		return allModules;
	}

	public void deleteModuleAttribute(ModuleId moduleId, ATerm namespace,
			ATerm key) {
		Module module = modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - deleteModuleAttribute: module ["
					+ moduleId + "] doesn't exist");
			return;
		}

		module.deleteAttribute(namespace, key);
	}

	public AttributeStore getAllAttributes(ModuleId moduleId) {
		Module module = modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - getAllAttributes: module [" + moduleId
					+ "] doesn't exist");
			return null;
		}

		return module.getAttributes();
	}

	public void addDependency(ModuleId moduleFromId, ModuleId moduleToId) {
		Set<ModuleId> dependencies;
		Module moduleFrom = modules.get(moduleFromId);
		Module moduleTo = modules.get(moduleToId);

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

		dependencies = descendants.get(moduleFromId);
		dependencies.add(moduleToId);

		dependencies = ascendants.get(moduleToId);
		dependencies.add(moduleFromId);
	}

	public Set<ModuleId> getChildren(ModuleId moduleId) {
		return descendants.get(moduleId);
	}

	public Set<ModuleId> getAllChildren(ModuleId moduleId) {
		Set<ModuleId> dependencies = new HashSet<ModuleId>();
		LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

		temp.addAll(getChildren(moduleId));

		while (!temp.isEmpty()) {
			ModuleId tempId = temp.getFirst();
			if (!dependencies.contains(tempId)) {
				dependencies.add(tempId);
				temp.addAll(getChildren(tempId));
			}
			temp.removeFirst();
		}

		return dependencies;
	}

	public Set<ModuleId> getParents(ModuleId moduleId) {
		return ascendants.get(moduleId);
	}

	public Set<ModuleId> getAllParents(ModuleId moduleId) {
		Set<ModuleId> dependencies = new HashSet<ModuleId>();
		LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

		temp.addAll(getParents(moduleId));

		while (!temp.isEmpty()) {
			ModuleId tempId = temp.getFirst();
			if (!dependencies.contains(tempId)) {
				dependencies.add(tempId);
				temp.addAll(getParents(tempId));
			}
			temp.removeFirst();
		}

		return dependencies;
	}

	public Set<ModuleId> getClosableModules(ModuleId moduleId) {
		Set<ModuleId> dependencies = getAllChildren(moduleId);
		LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

		dependencies.add(moduleId);
		temp.addAll(dependencies);

		while (!temp.isEmpty()) {
			ModuleId tempId = temp.getFirst();
			Set parents = getParents(tempId);

			if (!dependencies.containsAll(parents)) {
				Set children = getAllChildren(tempId);
				dependencies.removeAll(children);
				dependencies.remove(tempId);
			}

			temp.removeFirst();
		}

		return dependencies;
	}

	public void deleteDependency(ModuleId moduleFromId, ModuleId moduleToId) {
		LinkedList deps;
		Module moduleFrom = modules.get(moduleFromId);

		if (moduleFrom == null) {
			System.err.println("MM - deleteDependency: module [" + moduleFromId
					+ "] doesn't exist");
			return;
		}

		Module moduleTo = modules.get(moduleToId);

		if (moduleTo == null) {
			System.err.println("MM - deleteDependency: module [" + moduleToId
					+ "] doesn't exist");
			return;
		}

		deps = (LinkedList) descendants.get(moduleFromId);
		deps.remove(moduleToId);

		deps = (LinkedList) ascendants.get(moduleToId);
		deps.remove(moduleFromId);
	}

	public void deleteDependencies(ModuleId moduleId) {
		Set dependencies;

		Module module = modules.get(moduleId);

		if (module == null) {
			System.err.println("MM - deleteDependencies: module [" + moduleId
					+ "] doesn't exist");
			return;
		}

		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			ModuleId tempId = iter.next();
			dependencies = getParents(tempId);
			if (dependencies.contains(moduleId)) {
				dependencies.remove(moduleId);
			}
		}

		dependencies = descendants.get(moduleId);
		dependencies.clear();
	}

	private void deleteAllDependencies(ModuleId moduleId) {
		deleteDependencies(moduleId);

		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			Set dependencies = getChildren(iter.next());
			if (dependencies.contains(moduleId)) {
				dependencies.remove(moduleId);
			}
		}
	}

	public Map<ModuleId, Set<ModuleId>> getDependencies() {
		return descendants;
	}

	public void printStatistics() {
		int sumDeps = 0;
		for (Iterator<Set<ModuleId>> iter = descendants.values().iterator(); iter
				.hasNext();) {
			sumDeps += iter.next().size();
		}
		System.err.println(modules.size() + " modules");
		System.err.println(sumDeps + " dependencies");
	}

	public void registerAttributeUpdateRule(ATerm namespace, ATerm key,
			ATerm rule, ATerm value) {
		inheritedAttributes.put(namespace, key, rule, value);
		triggerAllAttributeOnAllModules();
	}

	private Boolean innermostRuleEvaluation(ATerm rule, ModuleId id,
			ATerm namespace, ATerm key) {
		List result;

		result = rule.match("and(<term>,<term>)");
		if (result != null) {
			return evaluateAnd((ATerm) result.get(0), (ATerm) result.get(1),
					id, namespace, key);
		}
		result = rule.match("or(<term>,<term>)");
		if (result != null) {
			return evaluateOr((ATerm) result.get(0), (ATerm) result.get(1), id,
					namespace, key);
		}
		result = rule.match("not(<term>)");
		if (result != null) {
			return evaluateNot((ATerm) result.get(0), id, namespace, key);
		}
		result = rule.match("one(<term>)");
		if (result != null) {
			return evaluateOne((ATerm) result.get(0), id, namespace, key);
		}
		result = rule.match("all(<term>)");
		if (result != null) {
			return evaluateAll((ATerm) result.get(0), id, namespace, key);
		}
		result = rule.match("set(<term>)");
		if (result != null) {
			return evaluateSet((ATerm) result.get(0), id, namespace, key);
		}

		System.err.println("Error evaluating attribute update rule [" + rule
				+ "]; forgot set?");
		System.exit(1);
		return null;
	}

	private Boolean evaluateAnd(ATerm op1, ATerm op2, ModuleId id,
			ATerm namespace, ATerm key) {
		return (innermostRuleEvaluation(op1, id, namespace, key) && innermostRuleEvaluation(
				op2, id, namespace, key));
	}

	private Boolean evaluateOr(ATerm op1, ATerm op2, ModuleId id,
			ATerm namespace, ATerm key) {
		return (innermostRuleEvaluation(op1, id, namespace, key) || innermostRuleEvaluation(
				op2, id, namespace, key));
	}

	private Boolean evaluateNot(ATerm op, ModuleId id, ATerm namespace,
			ATerm key) {
		return !(innermostRuleEvaluation(op, id, namespace, key));
	}

	private Boolean evaluateOne(ATerm op, ModuleId id, ATerm namespace,
			ATerm key) {
		Boolean result = false;
		Set<ModuleId> children = getChildren(id);
		Iterator<ModuleId> iter = children.iterator();

		while (iter.hasNext() && result == false) {
			ModuleId childId = iter.next();
			result = result
					&& innermostRuleEvaluation(op, childId, namespace, key);
		}

		return result;
	}

	private Boolean evaluateAll(ATerm op, ModuleId id, ATerm namespace,
			ATerm key) {
		Boolean result = true;
		Set<ModuleId> children = getAllChildren(id);
		Iterator<ModuleId> iter = children.iterator();

		while (iter.hasNext() && result == true) {
			ModuleId childId = iter.next();
			result = result
					&& innermostRuleEvaluation(op, childId, namespace, key);
		}

		return result;
	}

	private Boolean evaluateSet(ATerm op, ModuleId id, ATerm namespace,
			ATerm key) {
//		ATerm value = modules.get(id).getPredicate(namespace, key);
//		if (value == null) {
//			value = modules.get(id).getAttribute(namespace, key);
//		}
		ATerm value = modules.get(id).getAttribute(namespace, key);

		return op.equals(value);
	}
}
