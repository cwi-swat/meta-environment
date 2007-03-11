package nl.cwi.sen1.gui.plugin;

import java.io.File;

import javax.swing.JComponent;

import nl.cwi.sen1.gui.component.StudioComponentImpl;

import org.apache.batik.swing.JSVGCanvas;

public class SVGCanvas extends StudioComponentImpl {
	private JSVGCanvas svgCanvas = new JSVGCanvas();

	public SVGCanvas(String name, String file) {
		super(name, null);
		svgCanvas.loadSVGDocument("file://" + file);
	}

	@Override
	public JComponent getViewComponent() {
		return svgCanvas;
	}
}
