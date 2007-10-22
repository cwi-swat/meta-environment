package nl.cwi.sen1.tide;

import java.awt.Font;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

public class PreferenceSet {
	public static final String PREFS_FILE = ".tiderc";

	private List<String> preferenceNames;
	private Properties preferences;
	private List<PreferenceListener> listeners;

	private boolean is_clean;

	public PreferenceSet(Properties defaults) {
		preferenceNames = new ArrayList<String>();
		preferences = new Properties(defaults);
		listeners = new ArrayList<PreferenceListener>();
	}

	public void registerPreference(String name) {
		preferenceNames.add(name);
	}

	public Iterator<String> preferenceNameIterator(String prefix) {
		return new PreferenceIterator(prefix, preferenceNames);
	}

	public void addPreferenceListener(PreferenceListener listener) {
		listeners.add(listener);
	}

	public void removePreferenceListener(PreferenceListener listener) {
		listeners.remove(listener);
	}

	public void firePreferenceChanged(String name, String oldValue,
			String newValue) {
		System.out.println("preference changed: " + name + " from " + oldValue
				+ " into " + newValue);

		Iterator<PreferenceListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			PreferenceListener listener = iter.next();
			listener.preferenceChanged(this, name, oldValue, newValue);
		}
	}

	public void firePreferencesChanged() {
		Iterator<PreferenceListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			PreferenceListener listener = iter.next();
			listener.preferencesChanged(this);
		}
	}

	public void firePreferencesStatusChanged(boolean new_status) {
		Iterator<PreferenceListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			PreferenceListener listener = iter.next();
			listener.preferencesStatusChanged(this, new_status);
		}
	}

	public void loadPreferences() throws IOException {
		String path = System.getProperty("user.home");
		File file = new File(path, PREFS_FILE);
		FileInputStream input = new FileInputStream(file);
		loadPreferences(input);
	}

	public void loadPreferences(InputStream input) throws IOException {
		preferences.load(input);
		firePreferencesChanged();
	}

	public void savePreferences() throws IOException {
		FileOutputStream stream = new FileOutputStream(PREFS_FILE);
		savePreferences(stream);
	}

	public void savePreferences(OutputStream stream) throws IOException {
		preferences.store(stream, "Tide Preferences");
		setClean();
	}

	public void setClean() {
		setStatus(true);
	}

	private void setStatus(boolean status) {
		if (is_clean != status) {
			is_clean = status;
			firePreferencesStatusChanged(is_clean);
		}
	}

	public void setPreference(String name, String value) {
		String oldValue = (String) preferences.setProperty(name, value);
		if (oldValue == null || !oldValue.equals(value)) {
			firePreferenceChanged(name, oldValue, value);
			setStatus(false);
		}
	}

	public void setBooleanPreference(String name, boolean value) {
		setPreference(name, new Boolean(value).toString());
	}

	public void setIntegerPreference(String name, int value) {
		setPreference(name, new Integer(value).toString());
	}

	public String getPreference(String name) {
		return preferences.getProperty(name);
	}

	public Boolean getBooleanPreference(String name) {
		String value = getPreference(name);
		if (value == null) {
			return null;
		}

		return Boolean.valueOf(value);
	}

	public Integer getIntegerPreference(String name) {
		String value = getPreference(name);
		if (value == null) {
			return null;
		}

		return Integer.valueOf(value);
	}

	public Font getFontPreference(String name) {
		return Font.decode(getPreference(name));
	}
}

class PreferenceIterator implements Iterator<String> {
	private String prefix;
	private List<String> names;
	private int index;
	private String curName;

	public PreferenceIterator(String prefix, List<String> names) {
		this.prefix = prefix;
		this.names = names;

		index = 0;

		forward();
	}

	private void forward() {
		while (index < names.size()) {
			curName = names.get(index);
			if (curName.startsWith(prefix)) {
				break;
			}
		}
	}

	public boolean hasNext() {
		return index < names.size();
	}

	public String next() {
		String name = curName;
		index++;
		forward();

		return name;
	}

	public void remove() {
		throw new UnsupportedOperationException();
	}
}
