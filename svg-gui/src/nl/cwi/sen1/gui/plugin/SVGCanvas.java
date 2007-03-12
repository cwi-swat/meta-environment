package nl.cwi.sen1.gui.plugin;

import java.net.URL;
import java.net.URLClassLoader;

import javax.swing.JComponent;

import nl.cwi.sen1.gui.component.StudioComponentImpl;

import org.apache.batik.swing.JSVGCanvas;
import org.apache.xerces.parsers.SAXParser;

public class SVGCanvas extends StudioComponentImpl {
	private JSVGCanvas svgCanvas = new JSVGCanvas();

	public SVGCanvas(String name, String file) {
		super(name, null);
		ClassLoader sysClassLoader = ClassLoader.getSystemClassLoader();
		sysClassLoader = SVGCanvas.class.getClassLoader();

		sysClassLoader = JSVGCanvas.class.getClassLoader();
		
        //Get the URLs
        URL[] urls = ((URLClassLoader)sysClassLoader).getURLs();

        for(int i=0; i< urls.length; i++)
        {
            System.out.println(urls[i].getFile());
        }       
		svgCanvas.loadSVGDocument("file://" + file);
	}

	@Override
	public JComponent getViewComponent() {
		return svgCanvas;
	}
}
