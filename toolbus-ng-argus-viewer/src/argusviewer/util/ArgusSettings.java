package argusviewer.util;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Properties;

public final class ArgusSettings{
	private final static String SETTINGS_FILE = "settings.properties";
	
	private final Properties settings;
	
	private static class InstanceKeeper{
		public final static ArgusSettings instance = new ArgusSettings();
	}
	
	private ArgusSettings(){
		super();
		
		settings = new Properties();
		load();
	}
	
	private void load(){
		InputStream propertiesInputstream = null;
		try{
			propertiesInputstream = new FileInputStream(SETTINGS_FILE);
			settings.load(propertiesInputstream);
		}catch(IOException ioex){
			// Ignore this; just use the defaults when we're unable to read the properties file.
		}finally{
			if(propertiesInputstream != null){
				try{
					propertiesInputstream.close();
				}catch(IOException ioex){
					ioex.printStackTrace(); // Ugly, but who cares.
				}
			}
		}
	}
	
	public static ArgusSettings getInstance(){
		return InstanceKeeper.instance;
	}
	
	public void setAttribute(String key, String value){
		settings.setProperty(key, value);
	}
	
	public String getAttribute(String key, String defaultValue){
		return settings.getProperty(key, defaultValue);
	}
	
	public void save(){
		OutputStream propertiesOutputstream = null;
		try{
			propertiesOutputstream = new FileOutputStream(SETTINGS_FILE);
			settings.store(propertiesOutputstream, null);
		}catch(IOException ioex){
			ioex.printStackTrace(); // Ugly, but who cares.
		}finally{
			if(propertiesOutputstream != null){
				try{
					propertiesOutputstream.close();
				}catch(IOException ioex){
					ioex.printStackTrace(); // Ugly, but who cares.
				}
			}
		}
	}
}
