package nl.cwi.sen1.tide;

import java.util.*;
import java.io.*;
import java.awt.Font;

public class PreferenceSet
{
  public static final String PREFS_FILE = ".tiderc";

  private List preferenceNames;
  private Properties preferences;
  private List listeners;

  private boolean is_clean;

  //{{{ public PreferenceSet()

  public PreferenceSet(Properties defaults)
  {
    preferenceNames = new LinkedList();
    preferences = new Properties(defaults);
    listeners   = new LinkedList();
  }

  //}}}

  //{{{ public void registerPreference(String name)

  public void registerPreference(String name)
  {
    preferenceNames.add(name);
  }

  //}}}
  //{{{ public Iterator preferenceNameIterator(String prefix)

  public Iterator preferenceNameIterator(String prefix)
  {
    return new PreferenceIterator(prefix, preferenceNames, preferences);
  }

  //}}}

  //{{{ public void addPreferenceListener(PreferenceListener listener)

  public void addPreferenceListener(PreferenceListener listener)
  {
    listeners.add(listener);
  }

  //}}}
  //{{{ public void removePreferenceListener(PreferenceListener listener)

  public void removePreferenceListener(PreferenceListener listener)
  {
    listeners.remove(listener);
  }

  //}}}
  //{{{ public void firePreferenceChanged(name, oldValue, newValue)

  public void firePreferenceChanged(String name,
				    String oldValue, String newValue)
  {
    System.out.println("preference changed: " + name + " from "
		       + oldValue + " into " + newValue);

    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      PreferenceListener listener = (PreferenceListener)iter.next();
      listener.preferenceChanged(this, name, oldValue, newValue);
    }
  }

  //}}}
  //{{{ public void firePreferencesChanged()

  public void firePreferencesChanged()
  {
    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      PreferenceListener listener = (PreferenceListener)iter.next();
      listener.preferencesChanged(this);
    }
  }

  //}}}
  //{{{ public void firePreferencesStatusChanged(boolean new_status)

  public void firePreferencesStatusChanged(boolean new_status)
  {
    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      PreferenceListener listener = (PreferenceListener)iter.next();
      listener.preferencesStatusChanged(this, new_status);
    }
  }

  //}}}

  //{{{ public void loadPreferences()stream

  public void loadPreferences()
    throws IOException
  {
    String path = System.getProperty("user.home");
    File file = new File(path, PREFS_FILE);
    FileInputStream input = new FileInputStream(file);
    loadPreferences(input);
  }

  //}}}
  //{{{ public void loadPreferences(InputStream stream)

  public void loadPreferences(InputStream input)
    throws IOException
  {
    preferences.load(input);
    firePreferencesChanged();
  }

  //}}}
  //{{{ public void savePreferences()

  public void savePreferences()
    throws IOException
  {
    FileOutputStream stream = new FileOutputStream(PREFS_FILE);
    savePreferences(stream);
  }

  //}}}
  //{{{ public void savePreferences(OutputStream stream)

  public void savePreferences(OutputStream stream)
    throws IOException
  {
    preferences.store(stream, "Tide Preferences");
    setClean();
  }

  //}}}
  //{{{ public void setClean()

  public void setClean()
  {
    setStatus(true);
  }

  //}}}
  //{{{ private void setStatus(boolean status)

  private void setStatus(boolean status)
  {
    if (is_clean != status) {
      is_clean = status;
      firePreferencesStatusChanged(is_clean);
    }
  }

  //}}}

  //{{{ public void setPreference(String name, String value)

  public void setPreference(String name, String value)
  {
    String oldValue = (String)preferences.setProperty(name, value);
    if (oldValue == null || !oldValue.equals(value)) {
      firePreferenceChanged(name, oldValue, value);
      setStatus(false);
    }
  }

  //}}}
  //{{{ public void setBooleanPreference(String name, boolean value)

  public void setBooleanPreference(String name, boolean value)
  {
    setPreference(name, new Boolean(value).toString());
  }

  //}}}
  //{{{ public void setIntegerPreference(String name, int value)

  public void setIntegerPreference(String name, int value)
  {
    setPreference(name, new Integer(value).toString());
  }

  //}}}

  //{{{ public String getPreference(String name)

  public String getPreference(String name)
  {
    return preferences.getProperty(name);
  }

  //}}}
  //{{{ public Boolean getBooleanPreference(String name)

  public Boolean getBooleanPreference(String name)
  {
    String value = getPreference(name);
    if (value == null) {
      return null;
    }

    return Boolean.valueOf(value);
  }

  //}}}
  //{{{ public Integer getIntegerPreference(String name)

  public Integer getIntegerPreference(String name)
  {
    String value = getPreference(name);
    if (value == null) {
      return null;
    }

    return Integer.valueOf(value);
  }

  //}}}
  //{{{ public Font getFontPreference(String name)

  public Font getFontPreference(String name)
  {
    return Font.decode(getPreference(name));
  }

  //}}}
}

class PreferenceIterator
  implements Iterator
{
  private String prefix;
  private List names;
  private Properties preferences;
  private int index;
  private String curName;

  //{{{ public PreferenceIterator(prefix, names, preferences)

  public PreferenceIterator(String prefix, List names,
			    Properties preferences)
  {
    this.prefix = prefix;
    this.names  = names;
    this.preferences = preferences;

    index = 0;

    forward();
  }

  //}}}

  //{{{ private void forward()

  private void forward()
  {
    while (index < names.size()) {
      curName = (String)names.get(index);
      if (curName.startsWith(prefix)) {
	break;
      }
    }
  }

  //}}}
  //{{{ public boolean hasNext()

  public boolean hasNext()
  {
    return index < names.size();
  }

  //}}}
  //{{{ public Object next()

  public Object next()
  {
    String name = curName;
    index++;
    forward();

    return name;
  }

  //}}}
  //{{{ public void remove()

  public void remove()
  {
    throw new UnsupportedOperationException();
  }

  //}}}
}
