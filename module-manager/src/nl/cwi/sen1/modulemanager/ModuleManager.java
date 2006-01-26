package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.Dependency;
import nl.cwi.sen1.moduleapi.types.DependencyList;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import nl.cwi.sen1.moduleapi.types.ModuleIdList;
import nl.cwi.sen1.modulemanager.model.AttributeSetListener;
import nl.cwi.sen1.modulemanager.model.Module;
import nl.cwi.sen1.modulemanager.model.ModuleGraph;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class ModuleManager implements ModuleManagerTif, AttributeSetListener {
	private ModuleGraph moduleDB;

	private PureFactory pureFactory = new PureFactory();

	private Factory factory = Factory.getInstance(pureFactory);

	private ModuleManagerBridge bridge;

	public ModuleManager(String[] args) {
		moduleDB = new ModuleGraph(pureFactory, this);

		bridge = new ModuleManagerBridge(pureFactory, this);
		try {
			bridge.init(args);
			bridge.connect();
		} catch (IOException e) {
			System.err.println("Could not establish connection to ToolBus: "
					+ e);
			System.exit(1);
		}

		Thread thread = new Thread(new Runnable() {
			public void run() {
				bridge.run();
			}
		});
		thread.setName("ModuleManager");
		thread.start();
	}

	public ATerm createModule() {
		ModuleId moduleId = factory
				.makeModuleId_Mid(moduleDB.getNextModuleId());
		moduleDB.addModule(new Module(factory), moduleId);
		return pureFactory.make("snd-value(module-id(<term>))", moduleId
				.toTerm());
	}

	public ATerm getModuleIdByAttribute(ATerm namespace, ATerm key, ATerm value) {
		ModuleId moduleId = moduleDB.getModuleIdByAttribute(namespace, key,
				value);

		if (moduleId == null) {
			return pureFactory.parse("snd-value(no-such-module)");
		}

		return pureFactory.make("snd-value(module-id(<term>))", moduleId
				.toTerm());
	}

	public ATerm getAllModules() {
		Set modules = moduleDB.getAllModules();

		return pureFactory.make("snd-value(modules(<list>))",
				extractATermList(modules));
	}

	public ATerm getAllAttributes(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);
		AttributeStore attributes = moduleDB.getAllAttributes(moduleId);

		return pureFactory.make("snd-value(attributes(<term>))", attributes
				.toTerm());
	}

	public void deleteModule(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);
		moduleDB.removeModule(moduleId);
	}

	public void addAttribute(ATerm id, ATerm namespace, ATerm key, ATerm value) {
		System.err.println("addAttribute:" + id + " " + namespace + " " + key + " " + value);
		ModuleId moduleId = factory.ModuleIdFromTerm(id);
		moduleDB.setAttribute(moduleId, namespace, key, value);
	}

	public ATerm getAttribute(ATerm id, ATerm namespace, ATerm key) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);
		ATerm value = moduleDB.getModuleAttribute(moduleId, namespace, key);

		if (value == null) {
			return pureFactory.parse("snd-value(no-such-key)");
		}

		return pureFactory.make("snd-value(attribute(<term>))", value);
	}

	public void deleteAttribute(ATerm id, ATerm namespace, ATerm key) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		moduleDB.deleteModuleAttribute(moduleId, namespace, key);
	}

	public void addDependency(ATerm from, ATerm to) {
		ModuleId moduleFromId = factory.ModuleIdFromTerm(from);
		ModuleId moduleToId = factory.ModuleIdFromTerm(to);

		moduleDB.addDependency(moduleFromId, moduleToId);
	}

	public ATerm getChildrenModules(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		Set dependencies = moduleDB.getChildren(moduleId);

		if (dependencies == null) {
			return pureFactory.parse("snd-value(no-such-module)");
		}

		return pureFactory.make("snd-value(children-modules(<list>))",
				extractATermList(dependencies));
	}

	public ATerm getAllParentModules(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		Set dependencies = moduleDB.getAllParents(moduleId);

		if (dependencies == null) {
			return pureFactory.parse("snd-value(no-such-module)");
		}

		return pureFactory.make("snd-value(all-parent-modules(<list>))",
				extractATermList(dependencies));

	}

	public ATerm getParentModules(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		Set dependencies = moduleDB.getParents(moduleId);

		if (dependencies == null) {
			return pureFactory.parse("snd-value(no-such-module)");
		}

		return pureFactory.make("snd-value(parent-modules(<list>))",
				extractATermList(dependencies));

	}

	public ATerm getAllChildrenModules(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		Set dependencies = moduleDB.getAllChildren(moduleId);

		if (dependencies == null) {
			return pureFactory.parse("snd-value(no-such-module)");
		}

		return pureFactory.make("snd-value(all-children-modules(<list>))",
				extractATermList(dependencies));
	}

	public ATerm getClosableModules(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);

		Set closableModules = moduleDB.getClosableModules(moduleId);

		return pureFactory.make("snd-value(closable-modules(<list>))",
				extractATermList(closableModules));
	}

	public ATerm getDependencies() {
		DependencyList list = factory.makeDependencyList();
		Map dependencies = moduleDB.getDependencies();

		for (Iterator iter = dependencies.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			Set deps = (Set) dependencies.get(moduleId);

			ModuleIdList moduleList = factory.makeModuleIdList();
			for (Iterator depsIter = deps.iterator(); depsIter.hasNext();) {
				ModuleId dependencyId = (ModuleId) depsIter.next();
				moduleList = moduleList.append(dependencyId);
			}

			Dependency dependency = factory.makeDependency_Dependency(moduleId,
					moduleList);
			list = list.append(dependency);
		}
		return pureFactory.make("snd-value(dependencies(<term>))", list
				.toTerm());
	}

	private ATermList extractATermList(Set dependencies) {
		ATermList list = pureFactory.makeList();
		for (Iterator iter = dependencies.iterator(); iter.hasNext();) {
			list = list.append(((ModuleId) iter.next()).toTerm());
		}
		return list;
	}

	public void deleteDependency(ATerm from, ATerm to) {
		ModuleId moduleFromId = factory.ModuleIdFromTerm(from);
		ModuleId moduleToId = factory.ModuleIdFromTerm(to);

		moduleDB.deleteDependency(moduleFromId, moduleToId);
	}

	public void deleteDependencies(ATerm id) {
		ModuleId moduleId = factory.ModuleIdFromTerm(id);
		moduleDB.deleteDependencies(moduleId);
	}

	public ATerm getModuleGraph(ATerm namespace) {
		Graph graph = moduleDB.getModuleGraph(namespace);

		return pureFactory.make("snd-value(module-graph(<term>))", graph
				.toTerm());
	}

	public void recTerminate(ATerm t0) {
	}

	public static void main(String[] args) {
		new ModuleManager(args);
	}

	public void attributeSet(ModuleId id, ATerm namespace, ATerm key,
			ATerm oldValue, ATerm newValue) {
		System.err.println("listener: " + id + " " + namespace + " " +key + " " +oldValue + " " +newValue);
		
		if (oldValue == null) {
			/* The old value is unknown, so we construct a pattern that may mean any term */
			oldValue = key.getFactory().parse("undefined"); 
		}
		
		bridge.postEvent(pureFactory.make(
				"attribute-changed(<term>,<term>,<term>,<term>,<term>)", id
						.toTerm(), namespace, key, oldValue, newValue));
	}

	public void registerInheritedAttribute(ATerm namespace, ATerm key, ATerm oldValue, ATerm newValue, ATerm type) {
		moduleDB.registerInheritedAttribute(namespace, key, oldValue, newValue, type);
	}

	public void recAckEvent(ATerm t0) {
		System.err.println("ack event received:" + t0);
		
	}
}
