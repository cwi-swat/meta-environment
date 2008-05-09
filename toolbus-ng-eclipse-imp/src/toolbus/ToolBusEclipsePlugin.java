package toolbus;

import org.eclipse.core.runtime.IConfigurationElement;
import org.eclipse.core.runtime.IExtension;
import org.eclipse.core.runtime.IExtensionPoint;
import org.eclipse.core.runtime.IExtensionRegistry;
import org.eclipse.core.runtime.Platform;
import org.eclipse.core.runtime.Plugin;
import org.eclipse.ui.IStartup;
import org.eclipse.ui.console.ConsolePlugin;
import org.eclipse.ui.console.IConsole;
import org.eclipse.ui.console.IConsoleManager;
import org.eclipse.ui.console.IOConsole;

import toolbus.commandline.CommandLine;
import aterm.pure.PureFactory;

public class ToolBusEclipsePlugin extends Plugin implements IStartup{
	private static final String pluginId = "toolbus";
	private static final String toolbusConfig = "config";

	private static ToolBusEclipsePlugin instance;
	private static ToolBus toolbus;

	/**
	 * This constructor should only be called by the Eclipse Workbench.
	 */
	public ToolBusEclipsePlugin(){
		super();
	}
	
	public void earlyStartup() {
		getInstance(); // Initialize this thing.
	}

	/**
	 * The plugin activator is a singleton. Use this method to obtain the instance.
	 */
	public synchronized static ToolBusEclipsePlugin getInstance(){
		if(instance == null){
			instance = new ToolBusEclipsePlugin();
			toolbus = new ToolBus(new String[]{"-properties", getConfigFile()});
			runToolBus(toolbus);
		}
		return instance;
	}

	/**
	 * This method is needed for other plugins to connect to the Bus.
	 * 
	 * @return The port number to connect to using the adapter.
	 */
	public int getPort(){
		return toolbus.getPort();
	}

	public PureFactory getFactory(){
		return toolbus.getTBTermFactory();
	}

	private static void runToolBus(final ToolBus toolbus){
		if(toolbus.parsecup()){
			toolbus.prepare();
			Thread thread = new Thread(new Runnable(){
				public void run(){
					toolbus.execute();
				}
			});
			thread.setName(pluginId);
			thread.start();
			createConsole();
		}else{
			System.err.println("Failed to parse ToolBus script");
		}
	}

	private static void createConsole(){
		ConsolePlugin plugin = ConsolePlugin.getDefault();
		IConsoleManager manager = plugin.getConsoleManager();
		IOConsole console = new IOConsole("ToolBus", null);
		manager.addConsoles(new IConsole[]{console});
		
		CommandLine.createCommandLine(toolbus, console.getInputStream(), false);
	}

	private static String getConfigFile(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(pluginId, toolbusConfig);

		IExtension extensions[] = point.getExtensions();

		if(extensions.length == 1){
			IConfigurationElement[] configElements = extensions[0].getConfigurationElements();
			for(int i = configElements.length -1; i >= 0; i--){
				IConfigurationElement ce = configElements[i];
				if(ce.getName().equals("toolbus")){
					return ce.getAttribute("config");
				}
			}
		}

		return null;
	}
}
