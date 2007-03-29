package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;


import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.visual.VisualItem;

public class DotNodeRenderer extends LabelRenderer {

    public DotNodeRenderer(String string) {
        super(string);
    }

    protected Shape getRawShape(VisualItem item) {
        Rectangle2D bounds = super.getRawShape(item).getBounds2D();
        double x = bounds.getX();
        double y = bounds.getY();
        double width = bounds.getWidth();
        double height = bounds.getHeight();
        Shape result = getBoxShape(x, y, width, height);

        return new DotShape(super.getRawShape(item), result);
    }

    private Shape getBoxShape(double x, double y, double width, double height) {
        return new Rectangle2D.Double(x, y, width, height);
    }

    public void render(Graphics2D g, VisualItem item) {
        DotShape comp = (DotShape) getShape(item);

        Shape outer = comp.getOuterShape();
        drawShape(g, item, outer);

        Shape inner = comp.getInnerShape();
        renderText(g, item, inner);
    }

    public void renderText(Graphics2D g, VisualItem item, Shape shape) {
        String s = getText(item);
        int textColor = item.getTextColor();
        if (s != null) {
            Rectangle2D r = shape.getBounds2D();
            g.setPaint(ColorLib.getColor(textColor));
            g.setFont(m_font);
            FontMetrics fm = g.getFontMetrics();
            double size = item.getSize();
            double x = r.getX() + size * m_horizBorder;
            double y = r.getY() + size * m_vertBorder;
            g.drawString(s, (float) x, (float) y + fm.getAscent());
        }
    }
}