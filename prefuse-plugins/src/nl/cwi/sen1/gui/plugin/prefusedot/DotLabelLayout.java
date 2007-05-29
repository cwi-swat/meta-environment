package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.geom.Rectangle2D;
import java.util.Iterator;

import prefuse.action.layout.Layout;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;

public class DotLabelLayout extends Layout {

	public DotLabelLayout(String group) {
		super(group);
	}

	public void run(double frac) {
		Iterator<?> iter = m_vis.items(m_group);
		while (iter.hasNext()) {
			DecoratorItem item = (DecoratorItem) iter.next();
			VisualItem node = item.getDecoratedItem();
			Rectangle2D bounds = node.getBounds();
			
			setX(item, null, bounds.getCenterX());
			setY(item, null, bounds.getCenterY());
		}
	}

}
