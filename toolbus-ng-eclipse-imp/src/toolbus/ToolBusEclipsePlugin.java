package toolbus;

import java.io.File;
import java.io.IOException;
import java.net.URL;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.IConfigurationElement;
import org.eclipse.core.runtime.IExtension;
import org.eclipse.core.runtime.IExtensionPoint;
import org.eclipse.core.runtime.IExtensionRegistry;
import org.eclipse.core.runtime.Platform;
import org.eclipse.core.runtime.Plugin;
import org.eclipse.ui.IStartup;
import org.osgi.framework.Bundle;

import aterm.pure.PureFactory;

public class ToolBusEclipsePlugin extends Plugin implements IStartup{
	private static final String pluginId = "toolbus";

	private static final String toolbusConfig = "config";

	private static class SingletonToolBus{
		private final ToolBus toolbus;

		private SingletonToolBus(){
			super();
			String configFile = getConfigFile();
			
			if (configFile != null) {
			  toolbus = new ToolBus(new String[]{"-properties", getConfigFile()});
			}
			else {
				throw new RuntimeException("There was no proper toolbus extension found, so the ToolBus will not function");
			}
		}

		public ToolBus getToolBus(){
			return toolbus;
		}
	}

	private static class InstanceKeeper{
		private static SingletonToolBus instance;
		static{
			instance = new SingletonToolBus();
			runToolBus(instance.getToolBus());
		}
	}

	/**
	 * This constructor should only be called by the Eclipse Workbench.
	 */
	public ToolBusEclipsePlugin(){
		super();
	}

	public void earlyStartup(){
		getInstance(); // Initialize this thing.
	}

	/**
	 * The plugin activator is a singleton. Use this method to obtain the
	 * instance.
	 */
	private static SingletonToolBus getInstance(){
		return InstanceKeeper.instance;
	}

	/**
	 * This method is needed for other plugins to connect to the Bus.
	 * 
	 * @return The port number to connect to using the adapter.
	 */
	public static int getPort(){
		return getInstance().getToolBus().getPort();
	}

	public static PureFactory getFactory(){
		return getInstance().getToolBus().getTBTermFactory();
	}

	public static ToolBus getToolBus(){
		return getInstance().getToolBus();
	}

	private static void runToolBus(final ToolBus toolbus){
		try{
			if (toolbus != null && toolbus.parsecup()){
				toolbus.prepare();
				Thread thread = new Thread(new Runnable(){
					public void run() {
						toolbus.execute();
					}
				});
				thread.setName(pluginId);
				thread.start();

				DebugConsole debugConsole = new DebugConsole(toolbus);
				debugConsole.show();
			}else{
				System.err.println("Failed to parse ToolBus script");
			}
		}catch(RuntimeException rex){
			rex.printStackTrace();
			throw rex;
		}
	}

	private static String getConfigFile(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(pluginId, toolbusConfig);

		IExtension extensions[] = point.getExtensions();

		if(extensions.length == 1){
			IConfigurationElement[] configElements = extensions[0].getConfigurationElements();
			for(int i = configElements.length - 1; i >= 0; i--){
				IConfigurationElement ce = configElements[i];
				if(ce.getName().equals("toolbus")){
					String configPath = ce.getAttribute("config");

					Bundle bundle = Platform.getBundle(ce.getContributor().getName());
					File file;

					try{
						file = getFile(bundle, configPath);

						if (file != null) {
							return file.getAbsolutePath();
						}
					}catch(IOException e){
						System.err.println("Failed to get config file: " + configPath);
						e.printStackTrace();
					}
				}
			}
		}

		return null;
	}

	/**
	 * This method finds the file pointing to by resourcePath in bundle, and returns its file handle.
	 * 
	 * @param bundle
	 * @param resourcePath
	 * @return
	 * @throws IOException
	 */
	public static File getFile(Bundle bundle, String resourcePath) throws IOException {
		URL url = bundle.getEntry(resourcePath);

		File file = null;

		if(url != null){
			file = new File(FileLocator.toFileURL(url).getPath());
		}

		return file;
	}

}
