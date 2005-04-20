package nl.cwi.sen1.util;

import java.awt.Color;
import java.awt.Font;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.Properties;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.filechooser.FileSystemView;

// consider using java.util.prefs.Preferences as a replacement
public class Preferences {
	private Properties properties;

	public Preferences(InputStream propertyStream) {
		Properties defaultProperties = readDefaultProperties(propertyStream);
		this.properties = addUserProperties(defaultProperties);
	}

	private Properties readDefaultProperties(InputStream stream) {
		Properties defaultProperties = new Properties();
		loadProperties(defaultProperties, stream);
		return defaultProperties;
	}

	private Properties addUserProperties(Properties defaultProperties) {
		Properties props = new Properties(defaultProperties);

		File homeDir = FileSystemView.getFileSystemView().getHomeDirectory();
		File userPropertyFile = new File(homeDir, ".metarc");
		if (userPropertyFile.canRead()) {
			try {
				loadProperties(props, new FileInputStream(userPropertyFile));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		return props;
	}

	private Properties loadProperties(Properties props, InputStream stream) {
		try {
			props.load(stream);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return props;
	}

	public String getString(String key) {
		return properties.getProperty(key);
	}

	public void setString(String key, String value) {
		properties.setProperty(key, value);
	}

	public Color getColor(String key) {
		String spec = properties.getProperty(key);
		return spec == null ? null : Color.decode(spec);
	}

	public Font getFont(String key) {
		return Font.decode(getString(key));
	}

	public Icon getIcon(String key) {
		String path = properties.getProperty(key);
		URL url = path.getClass().getResource(path);

		return url == null ? null : new ImageIcon(url);
	}

	public int getInt(String key) {
		String spec = properties.getProperty(key);

		return Integer.parseInt(spec);
	}

	public double getDouble(String key) {
		String spec = properties.getProperty(key);
		return Double.parseDouble(spec);
	}

	public boolean getBoolean(String key) {

		String spec = properties.getProperty(key);

		return "true".equals(spec);
	}
}
