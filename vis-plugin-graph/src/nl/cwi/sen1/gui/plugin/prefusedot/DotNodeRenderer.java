package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.FontMetrics;
import java.awt.Graphics2D;
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
        int dotWidth = item.getInt(DotAdapter.DOT_WIDTH);
        double width = Math.max(dotWidth, bounds.getWidth());
        int dotHeight = item.getInt(DotAdapter.DOT_HEIGHT);
        double height = Math.max(dotHeight, bounds.getHeight());
        String shapeName = item.getString(DotAdapter.DOT_SHAPE);
        Shape result;

        // TODO: implement diamond and other shapes
        if (shapeName != null) {
          if (shapeName.equals("box")) {
        	  result = getBoxShape(x, y, width, height);
          }
          else if (shapeName.equals("circle")) {
        	  result = getCircleShape(x, y, width, height);
          }
          else if (shapeName.equals("ellipse")) {
        	  result = getEllipseShape(x, y, width, height);
          }
          else {
        	  result = getBoxShape(x, y, width, height);
          }
        }
        else {
          result = getBoxShape(x, y, width, height);
        }

        return new DotShape(super.getRawShape(item), result);
    }

    private Shape getBoxShape(double x, double y, double width, double height) {
        return new Rectangle2D.Double(x, y, width, height);
    }

    private Shape getCircleShape(double x, double y, double width, double height) {
        double radius = Math.max(width, height);
        return new Ellipse2D.Double(x, y, radius, radius);
    }

    private Shape getEllipseShape(double x, double y, double width,
            double height) {
        return new Ellipse2D.Double(x, y, width, height);
    }

    public void render(Graphics2D g, VisualItem item) {
        DotShape comp = (DotShape) getShape(item);

        Shape outer = comp.getOuterShape();
        drawShape(g, item, outer);

        Shape inner = comp.getInnerShape();
        renderText(g, item, inner, outer);
    }

    public void renderText(Graphics2D g, VisualItem item, Shape shape, Shape outer) {
        String s = getText(item);
        int textColor = item.getTextColor();
        if (s != null) {
            Rectangle2D r = shape.getBounds2D();
            Rectangle2D o = outer.getBounds2D();
            g.setPaint(ColorLib.getColor(textColor));
            g.setFont(m_font);
            FontMetrics fm = g.getFontMetrics();
            double x = r.getX() + (o.getWidth() / 2) - (r.getWidth() / 2);
            double y = r.getY() + (o.getHeight() / 2) - (r.getHeight() / 2);
            g.drawString(s, (float) x, (float) y + fm.getAscent());
        }
    }
}