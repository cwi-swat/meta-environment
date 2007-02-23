package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.pure.PureFactory;

public class ModuleDatabase {
	private int moduleCount;

	protected Map<ModuleId, Module> modules;

	protected Map<ModuleId, Set<ModuleId>> descendants;

	private Map<ModuleId, Set<ModuleId>> transDescendants;

	private AttributeUpdateRuleMap attributeUpdateRules;

	private Map<ModuleId, Set<ModuleId>> ascendants;

	private AttributeSetListener listener;

	private AFun modalAND, modalOR, modalNOT, modalONE, modalALL, modalSET;

	public ModuleDatabase(AttributeSetListener l, PureFactory factory) {
		moduleCount = 0;
		modules = new HashMap<ModuleId, Module>();
		descendants = new HashMap<ModuleId, Set<ModuleId>>();
		transDescendants = new HashMap<ModuleId, Set<ModuleId>>();
		ascendants = new HashMap<ModuleId, Set<ModuleId>>();
		listener = l;
		attributeUpdateRules = new AttributeUpdateRuleMap();

		modalAND = factory.makeAFun("and", 2, false);
		modalOR = factory.makeAFun("or", 2, false);
		modalNOT = factory.makeAFun("not", 1, false);
		modalONE = factory.makeAFun("one", 1, false);
		modalALL = factory.makeAFun("all", 1, false);
		modalSET = factory.makeAFun("set", 3, false);
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

	private void triggerAllAttributeUpdateRulesOnAllModules() {
		for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
				.hasNext();) {
			triggerAllAttributeUpdateRules(iter.next());
		}
	}

	private void triggerAllAttributeUpdateRules(ModuleId id) {
		for (Iterator<AttributeUpdateRule> iter = attributeUpdateRules
				.iterator(); iter.hasNext();) {
			propagate(iter.next(), id);
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
		ATerm oldPredicate = module.getPredicate(namespace, key);

		module.deletePredicate(namespace, key);

		if (oldValue == null || !oldValue.isEqual(value)) {
			module.setAttribute(namespace, key, value);
			if (oldPredicate != null) {
				fireAttributeSetListener(moduleId, namespace, key,
						oldPredicate, value);
			} else {
				fireAttributeSetListener(moduleId, namespace, key, oldValue,
						value);
			}
			propagateToParents(moduleId);
			triggerAllAttributeUpdateRules(moduleId);
		}
	}

	private void updatePredicate(ModuleId moduleId, ATerm namespace, ATerm key,
			ATerm predicate) {
		Module module = modules.get(moduleId);
		ATerm oldValue = module.getPredicate(namespace, key);
		// If there was no predicate get the old value. The listener gives the
		// new value as well as the old value.
		if (oldValue == null) {
			oldValue = module.getAttribute(namespace, key);
		}

		if (oldValue == null || !oldValue.isEqual(predicate)) {
			module.setPredicate(namespace, key, predicate);
			fireAttributeSetListener(moduleId, namespace, key, oldValue,
					predicate);
			propagateToParents(moduleId);
		}
	}

	private void fireAttributeSetListener(ModuleId id, ATerm namespace,
			ATerm key, ATerm oldValue, ATerm newValue) {
		listener.attributeSet(id, namespace, key, oldValue, newValue);
	}

	private void propagateToParents(ModuleId id) {
		Set<ModuleId> parents = getParents(id);
		for (Iterator<ModuleId> iter = parents.iterator(); iter.hasNext();) {
			triggerAllAttributeUpdateRules(iter.next());
		}
	}

	private void propagate(AttributeUpdateRule rule, ModuleId id) {
		Module module = modules.get(id);
		ATerm namespace = rule.getNamespace();
		ATerm key = rule.getKey();

		ATerm oldPredicate = module.getPredicate(namespace, key);
		ATerm newPredicate = rule.getPredicateValue();

		ATerm oldValue = module.getAttribute(namespace, key);

		ATerm formula = rule.getFormula();
		Boolean result = innermostRuleEvaluation(formula, id);

		if (result) {
			updatePredicate(id, namespace, key, newPredicate);
		} else {
			/* Fall back to attribute value by removing predicate */
			if (oldPredicate != null && newPredicate.equals(oldPredicate)) {
				module.deletePredicate(namespace, key);
				fireAttributeSetListener(id, namespace, key, oldPredicate,
						oldValue);
				propagateToParents(id);
			}
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

		transDescendants = new HashMap<ModuleId, Set<ModuleId>>();
	}

	public Set<ModuleId> getChildren(ModuleId moduleId) {
		return descendants.get(moduleId);
	}

	public Set<ModuleId> getAllChildren(ModuleId moduleId) {
		Set<ModuleId> dependencies = transDescendants.get(moduleId);

		if (dependencies == null) {
			dependencies = new HashSet<ModuleId>();
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

			transDescendants.put(moduleId, dependencies);
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
			Set<ModuleId> parents = getParents(tempId);

			if (!dependencies.containsAll(parents)) {
				Set<ModuleId> children = getAllChildren(tempId);
				dependencies.removeAll(children);
				dependencies.remove(tempId);
			}

			temp.removeFirst();
		}

		return dependencies;
	}

	public void deleteDependency(ModuleId moduleFromId, ModuleId moduleToId) {
		LinkedList<ModuleId> deps;
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

		deps = new LinkedList<ModuleId>(descendants.get(moduleFromId));
		deps.remove(moduleToId);

		deps = new LinkedList<ModuleId>(ascendants.get(moduleToId));
		deps.remove(moduleFromId);

		transDescendants = new HashMap<ModuleId, Set<ModuleId>>();
	}

	public void deleteDependencies(ModuleId moduleId) {
		Set<ModuleId> dependencies;

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
			Set<ModuleId> dependencies = getChildren(iter.next());
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
		for (Iterator<AttributeUpdateRule> iter = attributeUpdateRules
				.iterator(); iter.hasNext();) {
			AttributeUpdateRule check = iter.next();
			if (checkRuleViolation(check.getNamespace(), check.getKey(), check
					.getPredicateValue(), rule)) {
				System.err.println("Rule " + rule + " violates " + check);
				return;
			}
		}
		attributeUpdateRules.put(namespace, key, rule, value);
		triggerAllAttributeUpdateRulesOnAllModules();
	}

	private Boolean checkRuleViolation(ATerm namespace, ATerm key,
			ATerm predicate, ATerm rule) {
		if (((ATermAppl) rule).getAFun().equals(modalSET)) {
			return (rule.getChildAt(0).equals(namespace)
					&& rule.getChildAt(1).equals(key) && rule.getChildAt(2)
					.equals(predicate));
		}

		Boolean violation = false;
		for (int i = 0; i < rule.getChildCount(); i++) {
			violation = violation
					|| checkRuleViolation(namespace, key, predicate,
							(ATerm) rule.getChildAt(i));
		}
		return violation;
	}

	private Boolean innermostRuleEvaluation(ATerm rule, ModuleId id) {
		if (((ATermAppl) rule).getAFun().equals(modalAND)) {
			return evaluateAnd((ATerm) rule.getChildAt(0), (ATerm) rule
					.getChildAt(1), id);
		}
		if (((ATermAppl) rule).getAFun().equals(modalOR)) {
			return evaluateOr((ATerm) rule.getChildAt(0), (ATerm) rule
					.getChildAt(1), id);
		}
		if (((ATermAppl) rule).getAFun().equals(modalNOT)) {
			return evaluateNot((ATerm) rule.getChildAt(0), id);
		}
		if (((ATermAppl) rule).getAFun().equals(modalONE)) {
			return evaluateOne((ATerm) rule.getChildAt(0), id);
		}
		if (((ATermAppl) rule).getAFun().equals(modalALL)) {
			return evaluateAll((ATerm) rule.getChildAt(0), id);
		}
		if (((ATermAppl) rule).getAFun().equals(modalSET)) {
			return evaluateSet((ATerm) rule.getChildAt(2), id, (ATerm) rule
					.getChildAt(0), (ATerm) rule.getChildAt(1));
		}

		System.err.println("Error evaluating attribute update rule [" + rule
				+ "]; forgot set?");
		return false;
	}

	private Boolean evaluateAnd(ATerm op1, ATerm op2, ModuleId id) {
		return (innermostRuleEvaluation(op1, id) && innermostRuleEvaluation(
				op2, id));
	}

	private Boolean evaluateOr(ATerm op1, ATerm op2, ModuleId id) {
		return (innermostRuleEvaluation(op1, id) || innermostRuleEvaluation(
				op2, id));
	}

	private Boolean evaluateNot(ATerm op, ModuleId id) {
		return !(innermostRuleEvaluation(op, id));
	}

	private Boolean evaluateOne(ATerm op, ModuleId id) {
		Boolean result = false;
		Set<ModuleId> children = getAllChildren(id);
		Iterator<ModuleId> iter = children.iterator();

		while (iter.hasNext() && result == false) {
			ModuleId childId = iter.next();
			result = innermostRuleEvaluation(op, childId);
		}

		return result;
	}

	private Boolean evaluateAll(ATerm op, ModuleId id) {
		Boolean result = true;
		Set<ModuleId> children = getAllChildren(id);
		Iterator<ModuleId> iter = children.iterator();

		while (iter.hasNext() && result == true) {
			ModuleId childId = iter.next();
			result = innermostRuleEvaluation(op, childId);
		}

		return result;
	}

	private Boolean evaluateSet(ATerm op, ModuleId id, ATerm namespace,
			ATerm key) {
		ATerm value = modules.get(id).getAttribute(namespace, key);

		return op.equals(value);
	}
}
