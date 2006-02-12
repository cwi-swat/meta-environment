package toolbus;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

public class PropertyManager {
	
	static Properties props;
	
	static String sglr = "/ufs/paulk/software/installed/bin/sglr";

	static String parseTable = "/ufs/paulk/workspace/toolbusNG/toolbus/parser/Tscript.trm.tbl";

	static String implodePT = "/ufs/paulk/software/installed/bin/implodePT";

	static String workspace = "/ufs/paulk/eclipse/workspace";

	/**
	 * Get the name of the property file to be used
	 */
	
	private static String getPropertyFile() throws FileNotFoundException{
		String stdName = "toolbus.props";
		String user = System.getProperty("user.name");
	
		String hostname = ToolBus.getHostName();
	
		File f;
		String fname;
		fname = user + "@" + hostname + "-" + stdName;
		f = new File(fname);
		if (f.exists()) {
			return fname;
		}
	
		fname = user + "-" + stdName;
		f = new File(fname);
		if (f.exists()) {
			return fname;
		}
		fname = stdName;
		f = new File(fname);
		if (f.exists()) {
			return fname;
		}
		throw new FileNotFoundException(fname);
	}

	/**
	 * Load properties from property file; use defaults if absent
	 */
	
	public static void loadProperties() {
		Properties defaults = new Properties();
		defaults.setProperty("sglr.path", sglr);
		defaults.setProperty("parsetable.path", parseTable);
		defaults.setProperty("implodePT.path", implodePT);
		defaults.setProperty("workspace.path", workspace);
		
		props = new Properties(defaults);
		try {
			String pname = getPropertyFile();
			File configfile = new File(pname);
			props.load(new FileInputStream(configfile));
		} catch(Exception e){
			System.err.println("Cannot open configuration file; using built-in settings");
		}
	}

	/**
	 * Get workspace
	 */
	
	public static String getWorkspace() {
		return props.getProperty("workspace.path");
	}
	
	public static String get(String p){
		return props.getProperty(p);
	}
	
	public static String get(String p, String def){
		return props.getProperty(p, def);
	}
}
