package toolbus;

import java.io.File;
import java.io.FileFilter;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.IConfigurationElement;
import org.eclipse.core.runtime.IExtension;
import org.eclipse.core.runtime.IExtensionPoint;
import org.eclipse.core.runtime.IExtensionRegistry;
import org.eclipse.core.runtime.Platform;
import org.eclipse.core.runtime.Plugin;
import org.eclipse.ui.IStartup;
import org.osgi.framework.Bundle;

import toolbus.execution.EclipseToolExecutorFactory;
import aterm.pure.PureFactory;

public class ToolBusEclipsePlugin extends Plugin implements IStartup{
	private static final String PLUGIN_ID = "toolbus";

	private static final String TOOLBUS_CONFIG = "config";
	private static final String TOOLBUS_BINARY_PROVIDER = "binaryProvider";
	private static final String TOOLBUS_INCLUDE_PATH = "includePath";

	private static class SingletonToolBus{
		private final ToolBus toolbus;

		private SingletonToolBus(){
			super();
			String configFile = getConfigFile();
			
			if(configFile != null){
			  toolbus = new ToolBus(new String[]{"-properties", configFile});
			  toolbus.setToolExecutorFactory(new EclipseToolExecutorFactory(getBinaryPaths()));
			}else{
				throw new RuntimeException("There was no proper toolbus extension found, so the ToolBus will not function");
			}
		}
		
		public ToolBus getToolBus(){
			return toolbus;
		}
	}

	private static class InstanceKeeper{
		private static SingletonToolBus instance;
		static{instance = new SingletonToolBus();
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
			toolbus.parsecup();
			toolbus.prepare();
			Thread thread = new Thread(new Runnable(){
				public void run(){
					toolbus.execute();
				}
			});
			thread.setName(PLUGIN_ID);
			thread.start();

			DebugConsole debugConsole = new DebugConsole(toolbus);
			debugConsole.show();
		}catch(Exception rex){
			rex.printStackTrace();
			throw new RuntimeException(rex);
		}
	}

	private static String getConfigFile(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(PLUGIN_ID, TOOLBUS_CONFIG);

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
	
	public static List<String> getBinaryPaths(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(PLUGIN_ID, TOOLBUS_BINARY_PROVIDER);

		IExtension extensions[] = point.getExtensions();
		int nrOfExtensions = extensions.length;
		List<String> searchPaths = new ArrayList<String>(nrOfExtensions);
		for(int i = nrOfExtensions - 1; i >= 0; i--){
			IConfigurationElement[] binaryProviderElements = extensions[i].getConfigurationElements();
			IConfigurationElement ce = binaryProviderElements[0];
			String path = ce.getAttribute("path");

			Bundle bundle = Platform.getBundle(ce.getContributor().getName());
			
			try{
				searchPaths.add(FileLocator.toFileURL(bundle.getResource(path)).getPath());
			}catch(IOException ioex){
				// TODO Handle this exception properly.
				ioex.printStackTrace();
			}
		}
		
		return searchPaths;
	}
	
	public static List<String> getIncludesPath(){
		List<String> includePath = new ArrayList<String>();
		
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(PLUGIN_ID, TOOLBUS_INCLUDE_PATH);

		IExtension extensions[] = point.getExtensions();
		for(int i = extensions.length - 1; i >= 0; i--){
			IConfigurationElement[] binaryProviderElements = extensions[i].getConfigurationElements();
			IConfigurationElement ce = binaryProviderElements[0];
			String path = ce.getAttribute("path");

			Bundle bundle = Platform.getBundle(ce.getContributor().getName());
			
			try{
				List<String> recursiveDirectoryList = listDirectoriesRecursively(FileLocator.toFileURL(bundle.getEntry(path)).getPath());
				includePath.addAll(recursiveDirectoryList);
			}catch(IOException ioex){
				// TODO Handle this exception properly.
				ioex.printStackTrace();
			}
		}
		
		return includePath;
	}
	
	private static List<String> listDirectoriesRecursively(String path){
		List<String> directories = new LinkedList<String>();
		
		if(!new File(path).isDirectory()) return directories;
		
		directories.add(path);
		
		int index = 0;
		do{
			String dir = directories.get(index++);
			File directory = new File(dir);
			File[] subDirectories = directory.listFiles(new FileFilter(){
				public boolean accept(File pathname){
					return pathname.isDirectory();
				}
			});
			
			for(int i = subDirectories.length - 1; i >= 0; i--){
				directories.add(subDirectories[i].getAbsolutePath());
			}
		}while(index < directories.size());
		
		return directories;
	}

	/**
	 * This method finds the file pointing to by resourcePath in bundle, and returns its file handle.
	 * 
	 * @param bundle
	 * @param resourcePath
	 * @return
	 * @throws IOException
	 */
	public static File getFile(Bundle bundle, String resourcePath) throws IOException{
		URL url = bundle.getEntry(resourcePath);

		File file = null;

		if(url != null){
			file = new File(FileLocator.toFileURL(url).getPath());
		}

		return file;
	}
}
