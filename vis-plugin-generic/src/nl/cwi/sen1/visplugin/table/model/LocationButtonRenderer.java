package nl.cwi.sen1.visplugin.table.model;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.geom.Rectangle2D;

import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;

/**
 * Location button renderer. Class responisible for creating the buttons which
 * are rendered when a location is specified in an Rtuple.
 *
 * @author Anton Lycklama a Nijeholt
 * @author Bas Basten
 * @author Anton Gerdessen (Javadoc + review)
 * @date 13-03-2007
 */
public class LocationButtonRenderer extends JLabel implements TableCellRenderer {

    private static final long serialVersionUID = 1L;

    private int m_lineWidth = 0;

    private int m_lineHeight = 0;

    /**
     * Constructor.
     *
     * @author Anton Lycklama a Nijeholt
     * @author Bas Basten
     * @author Anton Gerdessen (Javadoc + review)
     * @date 13-03-2007
     */
    public LocationButtonRenderer() {
        initialize();
    }

    /**
     * Set the visible parameters for this label.
     *
     * @author Anton Lycklama a Nijeholt
     * @author Bas Basten
     * @author Anton Gerdessen (Javadoc + review)
     * @date 13-03-2007
     */
    public void initialize() {
        setOpaque(true);
        setText("<b>Location</b>");
        setForeground(Color.blue);
    }

    /**
     * Make the label invisible when its not selected.
     *
     * @author Anton Lycklama a Nijeholt
     * @author Bas Basten
     * @author Anton Gerdessen (Javadoc + review)
     * @date 13-03-2007
     * @see javax.swing.table.TableCellRenderer#getTableCellRendererComponent(javax.swing.JTable,
     *      java.lang.Object, boolean, boolean, int, int)
     */
    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {

        if (isSelected) {
            setBackground(table.getSelectionBackground());
        } else {
            setBackground(table.getBackground());
        }

        setText((value == null) ? "" : value.toString());
        return this;
    }

    /**
     * Calculate the bounds of the underline. This method will be called one for
     * each label. This method cannot be called in the initialize because the
     * graphics bounds are not set at that time.
     *
     * @author Anton Gerdessen
     * @date 14-03-2007
     */
    public void calculateUnderLineBounds() {
        // Calculate the lineSize for the underline once and store it.
        Rectangle2D textBounds = getFontMetrics(getFont()).getStringBounds(
                getText(), getGraphics());

        int textWidth = (int) textBounds.getWidth();
        int iconWidth = (getIcon() == null ? 0 : getIcon().getIconWidth()
                + getIconTextGap());

        m_lineWidth = iconWidth + textWidth;
        m_lineHeight = getHeight() / 2 + (int) (textBounds.getHeight() / 2);

    }

    /**
     * Overwrite the paint method, call super to paint the label itself. Draw
     * the underline afterwards.
     *
     * @author Anton Lycklama a Nijeholt
     * @author Bas Basten
     * @author Anton Gerdessen (Javadoc + review)
     * @date 13-03-2
     */
    public void paint(Graphics g) {
        super.paint(g);

        // If the bounds have not yet been calculated, calculate them.
        if (m_lineWidth == 0 || m_lineWidth != 0) {
            calculateUnderLineBounds();
        }

        g.setColor(getForeground());
        g.drawLine(0, m_lineHeight, m_lineWidth, m_lineHeight);
    }

}
