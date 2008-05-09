package toolbus;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

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
import org.osgi.framework.BundleContext;

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
			toolbus = new ToolBus(new String[0]);
			instance.runToolBus();
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

	/**
	 * This method is called by the Eclipse workbench
	 */
	public void stop(BundleContext context) throws Exception{
		toolbus.shutdown(toolbus.getTBTermFactory().parse("\"Eclipse shutdown\""));
	}

	protected void runToolBus(){
		setProperties(getConfigFile());

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

	private void createConsole(){
		ConsolePlugin plugin = ConsolePlugin.getDefault();
		IConsoleManager manager = plugin.getConsoleManager();
		IOConsole console = new IOConsole("ToolBus", null);
		manager.addConsoles(new IConsole[]{console});
		
		CommandLine.createCommandLine(toolbus, console.getInputStream());
	}

	private void setProperties(String file){
		Properties properties = new Properties();
		try{
			properties.load(new FileInputStream(file));

			for(Object key : properties.keySet()){
				toolbus.setProperty((String) key, properties.getProperty((String) key));
			}
		}catch(FileNotFoundException e){
			System.err.println("ToolBus: config file could not be loaded: " + e.getMessage());
		}catch(IOException e){
			System.err.println("ToolBus: config file could not be loaded: " + e.getMessage());
		}
	}

	private String getConfigFile(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(pluginId, toolbusConfig);

		IExtension extensions[] = point.getExtensions();

		if(extensions.length == 1){
			for(IConfigurationElement e : extensions[0].getConfigurationElements()){
				if(e.getName().equals("toolbus")){
					return e.getAttribute("config");
				}
			}
		}

		return null;
	}
}
