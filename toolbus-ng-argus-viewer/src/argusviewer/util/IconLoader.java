package argusviewer.util;

import java.net.URL;

import javax.swing.ImageIcon;

public class IconLoader{
	private final static String LOCALPATHPREFIX = "resources/icons/";
	private final static String JARPATHPREFIX = "/resources/icons/";
	
	private IconLoader(){
		super();
	}
	
	public static ImageIcon loadIcon(String iconName){
		URL jarIconURL = ClassLoader.getSystemResource(JARPATHPREFIX+iconName);
		if(jarIconURL != null) return new ImageIcon(jarIconURL);
		
		return new ImageIcon(LOCALPATHPREFIX+iconName);
	}
}
