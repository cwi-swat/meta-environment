/**
 * 
 */
package argusviewer.util;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import argusviewer.ExceptionReporter;



/**
 * This class can be used to store settings or variables that have to last more than
 * just one debugging session. These settings are serialized to the settings file at
 * the end of the execution  and will be loaded once the viewer is started.
 * 
 * @author M. van Beest
 *
 */
public final class ArgusSettings {
	private static ArgusSettings instance = null;
	private static final int INITIAL_CAPACITY = 3;
	
	private HashMap<String, HashMap<String, String>> m_settings;
	
	public static final String SETTINGS_FILE = "settings.cfg";
	
	/**
	 * Returns the current instance of the ArgusSettings class (Singleton)
	 * @return The instance of ArgusSettings
	 */
	public static ArgusSettings getInstance() {
		if (instance == null) {
			instance = new ArgusSettings();
		}
		return instance;
	}
	
	/**
	 * Constructs the class and initializes the datastructure
	 * Loads the configuration file.
	 */
	private ArgusSettings() {
		m_settings = new HashMap<String, HashMap<String, String>>(INITIAL_CAPACITY);
		readFromFile(SETTINGS_FILE);
	}
	
	
	/**
	 * Sets a value to the attribute in the given entry. If the attribute or the
	 * entry doesnt exist, create it.
	 * @param entry The entry to store the attribute in
	 * @param attribute The attribute to store the value in
	 * @param value The value to store in the attribute in the entry
	 */
	public void setAttribute(String entry, String attribute, String value) {
		HashMap<String, String> entryStore;
		if (m_settings.containsKey(entry)) {
			entryStore = m_settings.get(entry);
		} else {
			entryStore = new HashMap<String, String>(INITIAL_CAPACITY);
		}
		
		entryStore.put(attribute, value);
		m_settings.put(entry, entryStore);
	}
	
	/**
	 * Gets the requested attribute value from the settings file. It returns an
	 * empty string if the attribute cannot be found.
	 * @param entry The entry for the attribute
	 * @param attribute The attribute with the value.
	 * @param defaultValue when the requested value cannot be found, return this default value.
	 * @return The requested value or the defaultValue when it cannot be found
	 */
	public String getAttributeValue(String entry, String attribute, String defaultValue) {
		if ((m_settings.containsKey(entry))
			&& (m_settings.get(entry).containsKey(attribute))) {
				return m_settings.get(entry).get(attribute);
		}
			
		//the attribute is not found so return the defaultValue
		return defaultValue;
	}
	
	/**
	 * gets the content of the settings in a String format.
	 * @return A string with the settings
	 */
	public String getSettings() {
		return m_settings.toString();
	}
	
	/**
	 * prints the content of the settings to the String.
	 */
	public void printSettings() {
		System.out.println(m_settings.toString());
	}
	
	/**
	 * Sends the settings to a file in a serialized way.
	 * @param fileName the file to store the serialized data to.
	 */
	public void storeToFile(String fileName) {		
		try {
			FileOutputStream output = new FileOutputStream(fileName);
			ObjectOutputStream outputStream = new ObjectOutputStream(output);
			
			//serialize the settings object to the file
			outputStream.writeObject(m_settings);
			outputStream.close();
		} catch (IOException e) {
			ExceptionReporter.report("ArgusViewer could not store settings file.");
		}
	}
	
	/**
	 * Clears the settings from the internal structure. This is saved after calling storeToFile().
	 */
	public void clearSettings() {
		m_settings.clear();
	}
	
	/**
	 * Reads the settings from a file. The settings will be de-serialized and
	 * then put into use.
	 * 
	 * @param fileName the file to read the settings object from
	 */
	@SuppressWarnings("unchecked") //Unchecked casts are suppressed because of the casting of an Object to the HashMap
	private void readFromFile(String fileName) {		
		try {
			FileInputStream input = new FileInputStream(fileName);
			ObjectInputStream objectInputStream = new ObjectInputStream(input);
			
			//suppresswarnings(unchecked)
			m_settings = (HashMap<String, HashMap<String, String>>) objectInputStream.readObject();
			objectInputStream.close();
		} catch (IOException e) {
			ExceptionReporter.report("ArgusViewer could not read settings file.");
		} catch (ClassNotFoundException e) {
			ExceptionReporter.report("ArgusViewer detected a corrupt settings file.");
		}		
	}
}
