package argusviewer.view.architectureview;

import java.awt.Polygon;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.util.Iterator;

import org.apache.log4j.Logger;

import prefuse.data.expression.parser.ExpressionParser;
import prefuse.render.AbstractShapeRenderer;
import prefuse.visual.VisualItem;

/**
 * 
 * @author John Franse
 * @author Tigran Kalaidjan
 *
 * Renderer for messages passed between process and tools
 * Note that messages are not drawn if one of the processes or tools is invisible.
 */
public class MessageRenderer extends AbstractShapeRenderer {

    private final int m_initialArrowWidth  = 8;
    private final int m_initialArrowHeight = 12;
    private final int m_finalArrowSize = 3;
    private Polygon m_arrowHead = updateArrowHead(m_initialArrowWidth, m_initialArrowHeight);
    private AffineTransform m_arrowTrans = new AffineTransform();
    private Shape m_curArrow;
    private static final double HALF_PI = Math.PI / 2;

    private Logger m_logger = Logger.getLogger(MessageRenderer.class);

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {

		String sourceName = (String) item.get(Message.SOURCENAME_FIELDNAME);
		String targetName = (String) item.get(Message.TARGETNAME_FIELDNAME);
		
		String sourceType = (String) item.get(Message.SOURCETYPE_FIELDNAME);
		String targetType = (String) item.get(Message.TARGETTYPE_FIELDNAME);
		
		Point2D source = getPosition(sourceName, sourceType, targetName, item);
		Point2D target = getPosition(targetName, targetType, sourceName, item);
		
		
		// create the arrow head shape
        AffineTransform at = getArrowTrans(source, target, m_finalArrowSize);
        m_curArrow = at.createTransformedShape(m_arrowHead);
        
		GeneralPath path = new GeneralPath();
		path.append(m_curArrow, false);
		path.append(new Line2D.Double(source, target), false);
		
		return path; 
	}

	private Point2D getPosition(String name, String type, String targetName, VisualItem item) {
		
		String searchPredicateText;
		Iterator<VisualItem> matchingStatements = null;
		// Find all the statements where the timestamp matches the message source id
		if (type.equals("Process")) {
			searchPredicateText = Process.PROCESS_FIELDNAME + " == '" + name + "'";
			matchingStatements = item.getVisualization().items(Process.TABLE_NAME, ExpressionParser.predicate(searchPredicateText));
		} else {
			assert (type.equals("Tool"));
			searchPredicateText = Tool.TOOL_FIELDNAME + " == '" + name + "'";
            m_logger.debug(searchPredicateText);
            matchingStatements = item.getVisualization().items(Tool.TABLE_NAME, ExpressionParser.predicate(searchPredicateText));
		}
		if ((matchingStatements != null) 
			&& (matchingStatements.hasNext())) {
			VisualItem visualItem = matchingStatements.next();
			return new Point2D.Double(visualItem.getX(), visualItem.getY());		
		}
		return new Point2D.Double(0, 0);
	}
	
	/**
     * Returns an affine transformation that maps the arrowhead shape
     * to the position and orientation specified by the provided
     * line segment end points.
     */
    private AffineTransform getArrowTrans(Point2D p1, Point2D p2, double width)
    {
        m_arrowTrans.setToTranslation(p2.getX(), p2.getY());
        m_arrowTrans.rotate(-HALF_PI + Math.atan2(p2.getY() - p1.getY(), p2.getX() - p1.getX()));
        final int scaleFactor = 4; 
        if (width > 1) {
            double scalar = width / scaleFactor;
            m_arrowTrans.scale(scalar, scalar);
        }
        return m_arrowTrans;
    }
    
    /**
     * Update the dimensions of the arrow head, creating a new
     * arrow head if necessary. The return value is also set
     * as the member variable <code>m_arrowHead</code>
     * @param w the width of the untransformed arrow head base, in pixels
     * @param h the height of the untransformed arrow head, in pixels
     * @return the untransformed arrow head shape
     */
    protected Polygon updateArrowHead(int w, int h) {
        if (m_arrowHead == null) {
            m_arrowHead = new Polygon();
        } else {
            m_arrowHead.reset();
        }
        m_arrowHead.addPoint(0, 0);
        m_arrowHead.addPoint(-w / 2, -h);
        m_arrowHead.addPoint(w / 2, -h);
        m_arrowHead.addPoint(0, 0);
        return m_arrowHead;
    }
}
