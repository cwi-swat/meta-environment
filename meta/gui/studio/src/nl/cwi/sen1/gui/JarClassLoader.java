package nl.cwi.sen1.gui;

import java.io.IOException;
import java.net.JarURLConnection;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.jar.Attributes;

/**
 * A class loader for loading jar files, both local and remote.
 */
public class JarClassLoader extends URLClassLoader {
	private URL url;

	/**
	 * Creates a new JarClassLoader for the specified url.
	 * 
	 * @param url
	 *            the url of the jar file
	 */
	public JarClassLoader(URL url) {
		super(new URL[] { url });
		this.url = url;
	}

	/**
	 * Returns the name of the jar file main class, or null if no "Main-Class"
	 * manifest attributes was defined.
	 */
	public String getMainClassName() throws IOException {
		URL u = new URL("jar", "", url + "!/");
		JarURLConnection uc = (JarURLConnection) u.openConnection();
		Attributes attr = uc.getMainAttributes();
		return attr != null ? attr.getValue(Attributes.Name.MAIN_CLASS) : null;
	}

}
