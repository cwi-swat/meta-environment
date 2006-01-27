package nl.cwi.sen1.tide.tool;

import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Properties;

import javax.swing.JOptionPane;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.tide.PreferenceSet;
import nl.cwi.sen1.tide.tool.ruleinspector.RuleInspector;
import nl.cwi.sen1.tide.tool.ruleinspector.RuleInspectorFactory;
import nl.cwi.sen1.tide.tool.support.DebugAdapter;
import nl.cwi.sen1.tide.tool.support.DebugProcess;
import nl.cwi.sen1.tide.tool.support.Rule;

public class ToolManager {
	private Studio studio;

	private Map tideTools;

	private java.util.List processToolList;

	private java.util.List processActionList;

	private Map processTools;

	private java.util.List adapterToolList;

	private java.util.List adapterActionList;

	private Map adapterTools;

	private Map toolInstances;

	private PreferenceSet preferences;

	// {{{ public ToolManager(JDesktopPane desktop, Properties defaults)

	public ToolManager(Studio studio, Properties defaults) {
		this.studio = studio;

		tideTools = new HashMap();

		processToolList = new LinkedList();
		processActionList = new LinkedList();
		processTools = new HashMap();

		adapterToolList = new LinkedList();
		adapterActionList = new LinkedList();
		adapterTools = new HashMap();

		toolInstances = new HashMap();

		preferences = new PreferenceSet(defaults);

		try {
			preferences.loadPreferences();
		} catch (IOException e) {
			// Preferences could not be loaded because ~/.tiderc does not exist
			// probably
		}
	}

	public PreferenceSet getPreferences() {
		return preferences;
	}

	public TideTool getTool(String toolName, Object target) {
		Map tools = (Map) toolInstances.get(toolName);
		if (tools != null) {
			return (TideTool) tools.get(target);
		}

		return null;
	}

	public void putTool(String toolName, Object target, TideTool tool) {
		tool.setName(toolName);
		tool.setTarget(target);
		Map tools = (Map) toolInstances.get(toolName);
		if (tools == null) {
			tools = new HashMap();
			toolInstances.put(toolName, tools);
		}

		tools.put(target, tool);
	}

	public void removeTool(TideTool tool) {
		Map tools = (Map) toolInstances.get(tool.getName());
		studio.removeComponent(tool);
		tools.remove(tool.getTarget());
	}

	public void registerTool(TideToolFactory factory) {
		String name = factory.getName();
		tideTools.put(name, factory);
	}

	public void registerProcessTool(ProcessToolFactory factory) {
		String name = factory.getName();
		processToolList.add(name);
		processActionList.add(new ProcessAction(name, factory.getIcon(), this));
		processTools.put(name, factory);
	}

	// }}}
	// {{{ public void registerAdapterTool(AdapterToolFactory factory)

	public void registerAdapterTool(AdapterToolFactory factory) {
		String name = factory.getName();

		adapterToolList.add(name);
		adapterActionList.add(new AdapterAction(name, factory.getIcon(), this));
		adapterTools.put(name, factory);
	}

	public Iterator processToolIterator() {
		return processToolList.iterator();
	}

	public Iterator adapterToolIterator() {
		return adapterToolList.iterator();
	}

	public Iterator processActionIterator() {
		return processActionList.iterator();
	}

	public Iterator adapterActionIterator() {
		return adapterActionList.iterator();
	}

	public void displayError(String msg) {
		JOptionPane.showMessageDialog(null, "Tide error", msg,
				JOptionPane.ERROR_MESSAGE);
	}

	public TideTool launchTool(String toolName) {
		TideTool tool = getTool(toolName, this);
		if (tool == null) {
			TideToolFactory factory = (TideToolFactory) tideTools.get(toolName);
			tool = factory.createTool();
			putTool(toolName, this, tool);
			
			((StudioImplWithPredefinedLayout) studio).addComponent(tool,
					StudioImplWithPredefinedLayout.TOP_LEFT);
		}
		
		return tool;
		
	}
	
	public ProcessTool launchProcessTool(String toolName, DebugProcess process) {
		ProcessTool tool = (ProcessTool) getTool(toolName, process);
		if (tool == null) {
			ProcessToolFactory factory = (ProcessToolFactory) processTools
					.get(toolName);
			tool = factory.createTool(process);
			putTool(toolName, process, tool);

			((StudioImplWithPredefinedLayout) studio).addComponent(tool,
					StudioImplWithPredefinedLayout.TOP_RIGHT);
		}

		return tool;
	}

	public AdapterTool launchAdapterTool(String toolName, DebugAdapter adapter) {
		AdapterTool tool = (AdapterTool) getTool(toolName, adapter);
		if (tool == null) {
			AdapterToolFactory factory = (AdapterToolFactory) adapterTools
					.get(toolName);
			tool = factory.createTool(adapter);
			putTool(toolName, adapter, tool);
			((StudioImplWithPredefinedLayout) studio).addComponent(tool, 
					StudioImplWithPredefinedLayout.BOTTOM_RIGHT);
		}
		return tool;
	}

	public void setCurrentProcess(DebugProcess process) {
		Iterator iter = processActionIterator();
		while (iter.hasNext()) {
			ProcessAction action = (ProcessAction) iter.next();
			action.setProcess(process);
		}
	}

	public void setCurrentAdapter(DebugAdapter adapter) {
		Iterator iter = adapterActionIterator();
		while (iter.hasNext()) {
			AdapterAction action = (AdapterAction) iter.next();
			action.setAdapter(adapter);
		}
	}

	public void editRule(DebugProcess process, Rule rule) {
		String toolName = RuleInspectorFactory.NAME;
		RuleInspector inspector = (RuleInspector) launchProcessTool(toolName,
				process);
		inspector.editRule(rule);
	}

}
