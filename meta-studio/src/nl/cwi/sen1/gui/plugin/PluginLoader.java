package nl.cwi.sen1.gui.plugin;

import java.io.IOException;
import java.net.JarURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.StringTokenizer;
import java.util.jar.Attributes;


import aterm.ATermAppl;
import aterm.ATermList;

public class PluginLoader extends URLClassLoader {
	private static final String CLASSPATH_SEPARATORS = ":";

	private URL pluginURL;

	public PluginLoader(String pluginName) {
		super(new URL[] {});
		this.pluginURL = createURL(pluginName);
		addURL(pluginURL);
	}

	public PluginLoader(String pluginName, ATermList classPathEntries) {
		this(pluginName);
		for (int i = 0; !classPathEntries.isEmpty(); i++) {
			String entry = ((ATermAppl) classPathEntries.getFirst()).getName();
			addURL(createURL(entry));
			classPathEntries = classPathEntries.getNext();
		}
	}

	public PluginLoader(String pluginName, String classPath) {
		this(pluginName);
		StringTokenizer tok = new StringTokenizer(classPath,
				CLASSPATH_SEPARATORS);
		while (tok.hasMoreTokens()) {
			String url = tok.nextToken();
			try {
				addURL(new URL("file:" + url));
			} catch (MalformedURLException e) {
				System.err.println("Ignoring malformed url: " + url);
			}
		}
	}

	private URL createURL(String jarName) {
		URL url = null;
		try {
			url = new URL(jarName);
		} catch (MalformedURLException e) {
			System.err.println("Invalid URL: " + jarName);
		}
		return url;
	}

	/**
	 * Returns the name of the jar file main class, or null if no "Main-Class"
	 * manifest attribute was defined.
	 */
	private String findPluginMain() throws IOException {
	  String pluginMain = null;
	  URL u = new URL("jar", "", pluginURL + "!/");
	  JarURLConnection uc = (JarURLConnection) u.openConnection();
	  Attributes attr = uc.getMainAttributes();
	  if (attr == null) {
	      System.err.println("Unable to find a Main-Class attribute in plugin: " + pluginURL);
	      return null;
	  }
	  pluginMain = attr.getValue(Attributes.Name.MAIN_CLASS);
	  if (pluginMain == null) {
	      System.err.println("Unable to find a Main-Class in plugin: " + pluginURL);
	      return null;
	  }
	  return pluginMain;
	}

	public StudioPlugin instantiatePlugin() {
	  try {
	    String pluginMain = null;
	    pluginMain = findPluginMain();
	    StudioPlugin plugin = null;
	    Class<?> cl = loadClass(pluginMain);
	    return (StudioPlugin) cl.newInstance();
	  } catch (Exception e) {
	      System.err.println("Failed to instantiate plugin: " + pluginURL + "\n"  + e.getMessage());
	    return null;
	  }
	}
}
