package metastudio;

import java.io.*;
import java.net.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;

public class Preferences
{
  static private String title;
  static private Properties properties;
  static private ClassLoader loader;

  //{{{ static public void initialize(String title, defaults, loader)

  static public void initialize(String title, Properties defaults)
  {
    Preferences.title = title;
    properties = new Properties(defaults);
  }

  //}}}
  //{{{ static public void load(InputStream stream)

  static public void load(InputStream stream)
    throws IOException
  {
    properties.load(stream);
  }

  //}}}
  //{{{ static public void save(OutputStream stream)

  static public void save(OutputStream stream)
    throws IOException
  {
    properties.store(stream, title);
  }

  //}}}

  //{{{ static public String getString(String key)

  static public String getString(String key)
  {
    return properties.getProperty(key);
  }

  //}}}
  //{{{ static public Color getColor(String key)

  static public Color getColor(String key)
  {
    String spec = properties.getProperty(key);
    return spec == null ? null : Color.decode(spec);
  }

  //}}}
  //{{{ static public Font getFont(String key)

  static public Font getFont(String key)
  {
    String family = getString(key + ".family");
    int size = getInteger(key + ".size");
    boolean bold = Preferences.getBoolean(key + ".bold");
    boolean italic = Preferences.getBoolean(key + ".italic");

    int style = 0;
    if (bold) {
      style |= Font.BOLD;
    }
    if (italic) {
      style |= Font.ITALIC;
    }
    Font font = new Font(family, style, size);
    return font;
  }

  //}}}
  //{{{ static public Icon getIcon(String key)

  static public Icon getIcon(String key)
  {
    String path = properties.getProperty(key);
    URL url = path.getClass().getResource(path);

    return url == null ? null : new ImageIcon(url);
  }

  //}}}
  //{{{ static public int getInteger(String key)

  static public int getInteger(String key)
  {
    String spec = properties.getProperty(key);

    return Integer.parseInt(spec);
  }

  //}}}
  //{{{ static public boolean getBoolean(String key)

  static public boolean getBoolean(String key)
  {

    String spec = properties.getProperty(key);

    return "true".equals(spec);
  }

  //}}}
}
