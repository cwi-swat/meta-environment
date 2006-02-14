package toolbus;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Properties;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PropertyManager {
	
	private Properties properties;
	private String propertyFileName;
	private HashMap<String,String> defines = new HashMap<String,String>();
	private String includes = "";
	
	public PropertyManager(String[] args){
		handleComandLineArguments(args);
		
		properties = new Properties(System.getProperties());
		try {
			String pname = getPropertyFile();
			File configfile = new File(pname);
			properties.load(new FileInputStream(configfile));
			for(String key: defines.keySet()){
				set(key,defines.get(key));
			}
			if(includes != ""){
				set("include.path", includes);
			}
			
		} catch(Exception e){
			System.err.println("Cannot open configuration file; using built-in settings");
		}
	}
	
	public void handleComandLineArguments(String args[]){
		for(String arg : args){
			System.err.println(arg);
		}
		Pattern pdefine = Pattern.compile("-D(.*)=(.*)");
		Pattern pinclude = Pattern.compile("-I(.*)");

		for(int i = 0; i < args.length; i++){
			String arg = args[i];
			if(arg.equals("-properties") && i + 1 < args.length){
				propertyFileName = args[i+1];
				i++;
				continue;	
			}
			Matcher mdefine = pdefine.matcher(arg);
			if(mdefine.matches()){
				String name = mdefine.group(1);
				String val  = mdefine.group(2);
				System.err.println("define: name = " + name + ", " + " val = " + val);
				defines.put(name,val);
			} else {
				Matcher idefine = pinclude.matcher(arg);
				if(idefine.matches()){
					String name = idefine.group(1);
					System.err.println("include: name = " + name);
					includes = (includes == "") ? name : includes + ", " + name;
				}
			}
		}
	}

	/**
	 * Get the name of the property file to be used
	 */
	
	private String getPropertyFile() throws FileNotFoundException{
		if(propertyFileName != null){
			File f = new File(propertyFileName);
			return propertyFileName;
		}
		String user = System.getProperty("user.name");
	
		String hostname = ToolBus.getHostName();
		
		String[] prefix = new String[] {user + "@" + hostname + "-", user + "-", ""};
		for(String pref : prefix){
			String fname = pref + "toolbus.props";
			File f = new File(fname);
			if (f.exists()) {
				return fname;
			}
		}
	
		throw new FileNotFoundException("Property file");
	}

	/**
	 * Get workspace
	 */
	
	public String getWorkspace() {
		return properties.getProperty("workspace.path");
	}
	
	public String get(String p){
		return properties.getProperty(p);
	}
	
	public String get(String p, String def){
		return properties.getProperty(p, def);
	}
	
	public void set(String key, String val){
		properties.setProperty(key, val);
	}
}
