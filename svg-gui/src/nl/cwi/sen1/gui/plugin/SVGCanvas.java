package nl.cwi.sen1.gui.plugin;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JLabel;

import nl.cwi.sen1.gui.component.StudioComponentImpl;

import org.apache.batik.swing.JSVGCanvas;

public class SVGCanvas extends StudioComponentImpl {
	JButton button = new JButton("Load...");
	JLabel label = new JLabel();
	JSVGCanvas svgCanvas = new JSVGCanvas();

	public SVGCanvas(String name) {
		super(name, null);
		svgCanvas.loadSVGDocument("file:///home/jurgenv/example.svg");
	}

	@Override
	public JComponent getViewComponent() {
		return svgCanvas;
	}
}
