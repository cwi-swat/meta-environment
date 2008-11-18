package toolbus;

import java.io.File;
import java.io.FileFilter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.IConfigurationElement;
import org.eclipse.core.runtime.IExtension;
import org.eclipse.core.runtime.IExtensionPoint;
import org.eclipse.core.runtime.IExtensionRegistry;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Platform;
import org.eclipse.core.runtime.Plugin;
import org.eclipse.ui.IStartup;
import org.osgi.framework.Bundle;

import toolbus.execution.EclipseToolExecutorFactory;
import aterm.pure.PureFactory;

public class ToolBusEclipsePlugin extends Plugin implements IStartup{
	private static final String PLUGIN_ID = "toolbus";

	private static final String TOOLBUS_MAIN_SCRIPT = "mainScript";
	private static final String TOOLBUS_BINARY_PROVIDER = "binaryProvider";
	private static final String TOOLBUS_INCLUDE_PATH = "includePath";

	private static class SingletonToolBus{
		private final ToolBus toolbus;

		private SingletonToolBus(){
			super();
			try{
			String mainScript = getMainScript();
			if(mainScript != null){
				List<String> includePath = getIncludesPath();
				String[] toolBusCommand = buildToolBusCommand(mainScript, includePath);
				
				toolbus = new ToolBus(toolBusCommand);
				toolbus.setToolExecutorFactory(new EclipseToolExecutorFactory(getBinaryPaths()));
			}else{
				throw new RuntimeException("There was no proper toolbus extension found, so the ToolBus will not function");
			}
			}catch(Exception ex){
				ex.printStackTrace();
				throw new RuntimeException(ex);
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
	
	private static String[] buildToolBusCommand(String mainScript, List<String> includePath){
		int nrOfIncludes = includePath.size();
		String[] toolBusCommand = new String[includePath.size() + 1];
		for(int i = nrOfIncludes - 1; i >= 0; i--){
			toolBusCommand[i + 1] = "-I"+includePath.get(i);
		}
		toolBusCommand[0] = "-S"+mainScript;
		
		return toolBusCommand;
	}

	private static String getMainScript(){
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(PLUGIN_ID, TOOLBUS_MAIN_SCRIPT);

		IExtension extensions[] = point.getExtensions();

		if(extensions.length == 1){
			IConfigurationElement[] configElements = extensions[0].getConfigurationElements();
			IConfigurationElement ce = configElements[0];
			String path = ce.getAttribute("path");

			Bundle bundle = Platform.getBundle(ce.getContributor().getName());
			
			try{
				return getFile(bundle, path);
			}catch(RuntimeException rex){
				System.err.println("Unable to load main ToolBus script file: "+path+", from bundle: "+bundle);
				throw rex;
			}
		}
		
		throw new RuntimeException(extensions.length+" main ToolBus scripts defined.");
	}
	
	private static List<String> getBinaryPaths(){
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
			
			searchPaths.add(getFile(bundle, path));
		}
		
		return searchPaths;
	}
	
	private static List<String> getIncludesPath(){
		List<String> includePath = new ArrayList<String>();
		
		IExtensionRegistry registry = Platform.getExtensionRegistry();
		IExtensionPoint point = registry.getExtensionPoint(PLUGIN_ID, TOOLBUS_INCLUDE_PATH);

		IExtension extensions[] = point.getExtensions();
		for(int i = extensions.length - 1; i >= 0; i--){
			IConfigurationElement[] binaryProviderElements = extensions[i].getConfigurationElements();
			IConfigurationElement ce = binaryProviderElements[0];
			String path = ce.getAttribute("path");

			Bundle bundle = Platform.getBundle(ce.getContributor().getName());
			
			List<String> recursiveDirectoryList = listDirectoriesRecursively(getFile(bundle, path));
			includePath.addAll(recursiveDirectoryList);
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
	
	private static String getFile(Bundle bundle, String path){
		String fileURL;
		try{
			fileURL = FileLocator.toFileURL(bundle.getEntry(path)).getPath();
		}catch(Exception ex){
			try{
				fileURL = FileLocator.toFileURL(bundle.getResource(path)).getPath();
			}catch(Exception ex2){
				fileURL = FileLocator.find(bundle, new Path(path), null).getPath();
			}
		}
		return fileURL;
	}
}
