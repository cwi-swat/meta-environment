package metastudio.utils;

import java.awt.Color;
import java.awt.Font;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.util.Properties;

import javax.swing.Icon;
import javax.swing.ImageIcon;

public class Preferences {
	static private String title;
	static private Properties properties;

    public static final String PREF_NODE_BORDER_WIDTH = "node.border.width";
    public static final String PREF_NODE_BORDER_HEIGHT = "node.border.height";
    public static final String PREF_TREEPANE_BACKGROUND = "treepane.background";
	public static final String PREF_MSGPANE_BACKGROUND = "messagepane.background";
    public static final String PREF_MSGPANE_STATUS = "messagepane.status";
    public static final String PREF_GRAPHPANE_BACKGROUND = "graphpane.background";
    public static final String PREF_GRAPHPANE_SCALES = "graphpane.scales";
    public static final String PREF_STATUSPANE_BACKGROUND = "statuspane.background";
    
	static public void initialize(String title, Properties defaults) {
		Preferences.title = title;
		properties = new Properties(defaults);
	}

	static public void load(InputStream stream) throws IOException {
		properties.load(stream);
	}

	static public void save(OutputStream stream) throws IOException {
		properties.store(stream, title);
	}

	static public String getString(String key) {
		return properties.getProperty(key);
	}

	static public void setString(String key, String value) {
		properties.setProperty(key, value);
	}

	static public Color getColor(String key) {
		String spec = properties.getProperty(key);
		return spec == null ? null : Color.decode(spec);
	}

	static public Font getFont(String key) {
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

	static public Icon getIcon(String key) {
		String path = properties.getProperty(key);
		URL url = path.getClass().getResource(path);

		return url == null ? null : new ImageIcon(url);
	}

	static public int getInteger(String key) {
		String spec = properties.getProperty(key);

		return Integer.parseInt(spec);
	}

	static public boolean getBoolean(String key) {

		String spec = properties.getProperty(key);

		return "true".equals(spec);
	}
}
