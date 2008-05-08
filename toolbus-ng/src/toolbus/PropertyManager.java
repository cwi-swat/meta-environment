package toolbus;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Properties;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PropertyManager{
	private final Properties properties;
	private String propertyFileName = null;
	private final HashMap<String, String> defines;
	private String includes = "";
	private String tbscript = null;
	private int port;
	private boolean withConsole = false;
	
	public PropertyManager(String[] args){
		port = -1;
		
		defines = new HashMap<String, String>();
		
		properties = new Properties(System.getProperties());
		
		handleComandLineArguments(args);
		
		FileInputStream fis = null;
		try{
			fis = new FileInputStream(getPropertyFile());
			properties.load(fis);
		}catch(IOException ioex){
			System.err.println("Cannot open configuration file; using built-in settings.");
		}finally{
			if(fis != null){
				try{
					fis.close();
				}catch(IOException ioex){
					System.err.println("Unable to close properties file stream."+ioex.getMessage());
				}
			}
		}
		
		Iterator<String> definesIterator = defines.keySet().iterator();
		while(definesIterator.hasNext()){
			String key = definesIterator.next();
			
			set(key, defines.get(key));
		}
		if(includes != ""){
			set("include.path", includes);
		}
		if(tbscript != null){
			set("script.path", tbscript);
		}
	}
	
	private void handleComandLineArguments(String args[]){
		Pattern pdefine = Pattern.compile("-D(.*)=(.*)");
		Pattern pinclude = Pattern.compile("-I(.*)");
		Pattern pscript = Pattern.compile("-S(.*)");
		Pattern pport = Pattern.compile("-P(.*)");
		
		for(int i = 0; i < args.length; i++){
			String arg = args[i];
			if(arg.equals("-properties") && i + 1 < args.length){
				propertyFileName = args[++i];
			}else if(arg.equals("--with-console")){
				withConsole = true;
			}else if(arg.equals("-output") && i + 1 < args.length){
				set("gentifs.output", args[++i]);
			}else{
				Matcher mdefine = pdefine.matcher(arg);
				if(mdefine.matches()){
					String name = mdefine.group(1);
					String val = "\"" + mdefine.group(2) + "\"";
					//System.err.println("define: name = " + name + ", " + " val = " + val);
					defines.put(name, val);
				}else{
					Matcher idefine = pinclude.matcher(arg);
					if(idefine.matches()){
						String name = idefine.group(1);
						//System.err.println("include: name = " + name);
						includes = (includes == "") ? name : includes + ", " + name;
					}else{
						Matcher sdefine = pscript.matcher(arg);
						if (sdefine.matches()) {
							String name = sdefine.group(1);
							//System.err.println("tbscript: name = " + name);
							if (tbscript != null) {
								System.err.println("tbscript: already defined (" + tbscript + ")");
							}
							tbscript = name;					
						}else{
							Matcher portDefine = pport.matcher(arg);
							if(portDefine.matches()){
								String portNumber = portDefine.group(1);
								port = Integer.parseInt(portNumber);
							}
						}
					}
				}
			}
		}
	}
	
	/**
	 * Get the name of the property file to be used
	 */
	private String getPropertyFile() throws FileNotFoundException{
		if(propertyFileName != null){
			return propertyFileName;
		}
		String user = System.getProperty("user.name");
		
		String hostname = ToolBus.getHostName();
		
		String[] prefix = new String[]{user + "@" + hostname + "-", user + "-", ""};
		for(int i = 0; i < prefix.length; i++){
			String fname = prefix[i] + "toolbus.props";
			File f = new File(fname);
			if(f.exists()){
				return fname;
			}
		}
		
		throw new FileNotFoundException("Property file");
	}
	
	/**
	 * Get workspace
	 */
	public String getWorkspace(){
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
	
	public int getUserSpecifiedPort(){
		return port;
	}
	
	public boolean withConsole(){
		return withConsole;
	}
}
