package argusviewer.view.msc.control;

import prefuse.Display;
import prefuse.controls.ControlAdapter;
import prefuse.visual.VisualItem;

import java.awt.event.MouseEvent;
import java.util.ArrayList;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.Message;
import argusviewer.view.msc.data.Statement;
import argusviewer.view.msc.visual.MSCVisualizationUtil;

/**
 * Prefuse ControlAdapter for ToolTips in the Message Sequence Chart.
 * This Control creates ToolTips for Messages, Statement and Entities.
 *
 * @author: Arne Timmerman
 * @author: Roberto van der Linden
 */
public class MSCToolTipControl extends ControlAdapter {

	private StringBuffer m_tooltipContents;
	protected static final int CHARACTERS_PER_LINE = 100;

	/**
	 * Create a new ToolTip control for message in the Message Sequence Chart.
	 */
	public MSCToolTipControl() {
		m_tooltipContents = new StringBuffer();
	}

	/**
	 * {@inheritDoc}
	 */
    @Override
	@SuppressWarnings("unchecked")
	public void itemEntered(VisualItem item, MouseEvent e) {
        Display display = (Display) e.getSource();

		if (item.isInGroup(Message.TABLE_NAME)) {
			display.setToolTipText(getMessageToolTip(item));
		} else if (item.isInGroup(Statement.TABLE_NAME)) {
			display.setToolTipText(getStatementToolTip(item));
		} else if (item.isInGroup(Entity.TABLE_NAME)) {
			display.setToolTipText(getEntityToolTip(item));
		} else {
			display.setToolTipText(null);
		}
	}

	/**
	 * Get the contents of a ToolTip for a Message by the given
	 * VisualItem.
	 *
	 * @param message the VisualItem that represents the message
	 * @return a String representation for a Message ToolTip
	 */
	@SuppressWarnings("unchecked")
	protected String getMessageToolTip(VisualItem message) {
		m_tooltipContents.delete(0, m_tooltipContents.length());

		int sourceId = (Integer) message.get(Message.SOURCEID_FIELDNAME);
		VisualItem sourceStatement = MSCVisualizationUtil.getStatement(message.getVisualization(), sourceId);

		String sourceEntity = (String) sourceStatement.get(Statement.PARENTID_FIELDNAME);
		String messageContent = (String) message.get(Message.MESSAGE_FIELDNAME);
		ArrayList<String> targetEntities = (ArrayList<String>) message.get(Message.TARGETIDS_FIELDNAME);

		m_tooltipContents.append("<html>");
		m_tooltipContents.append("<b>Source:</b><br>");
		m_tooltipContents.append(sourceEntity);
		m_tooltipContents.append("<br><br><b>Message:</b><br>");
		m_tooltipContents.append(createMultilineString(messageContent));
		m_tooltipContents.append("<br><br><b>Destination(s):</b>");

		for (String targetEntity : targetEntities) {
			m_tooltipContents.append("<br>");
			m_tooltipContents.append(targetEntity);
		}

		m_tooltipContents.append("</html>");
		return m_tooltipContents.toString();
	}

	/**
	 * Get the contents of a ToolTip for a Statement by the given
	 * VisualItem.
	 *
	 * @param statement the VisualItem that represents the Statement
	 * @return a String representation for a Statement ToolTip
	 */
	protected String getStatementToolTip(VisualItem statement) {
		m_tooltipContents.delete(0, m_tooltipContents.length());

		String statementContent = (String) statement.get(Statement.STATEMENT_FIELDNAME);

		m_tooltipContents.append("<html>");
		m_tooltipContents.append("<b>Statement:</b><br>");
		m_tooltipContents.append(createMultilineString(statementContent));
		m_tooltipContents.append("</html>");

		return m_tooltipContents.toString();
	}

	/**
	 * Get the contents of a ToolTip for an Entity by the given
	 * VisualItem.
	 *
	 * @param entity the VisualItem that represents the Entity
	 * @return a String representation for an Entity ToolTip
	 */
	protected String getEntityToolTip(VisualItem entity) {
		m_tooltipContents.delete(0, m_tooltipContents.length());

		int entityId = (Integer) entity.get(Entity.ID_FIELDNAME);
		String entityName = (String) entity.get(Entity.NAME_FIELDNAME);
		Entity.Type entityType = (Entity.Type) entity.get(Entity.TYPE_FIELDNAME);

		m_tooltipContents.append("<html>");
		m_tooltipContents.append("<b>");
		m_tooltipContents.append(entityName);
		m_tooltipContents.append(" ");
		m_tooltipContents.append(entityId);
		m_tooltipContents.append("<br><br>Type:</b><br>");
		m_tooltipContents.append(entityType);
		m_tooltipContents.append("</html>");

		return m_tooltipContents.toString();
	}

	/**
	 * Create a multiline string of a single line string.
	 * The lines are separated by HTML <br> tags and have
	 * a maximum length of the constant field CHARACTERS_PER_LINE.
	 *
	 * @param text the single line text to convert to multiline text
	 * @return a multiline representation of the text
	 */
	protected String createMultilineString(String text) {
		if (text.length() <= CHARACTERS_PER_LINE) {
			return text;
		}

		StringBuilder multilineText = new StringBuilder();
		int linesCount = text.length() / CHARACTERS_PER_LINE;
		for (int i = 0; i < linesCount; i++) {
			int beginIndex = i * CHARACTERS_PER_LINE;
			int endIndex = beginIndex + CHARACTERS_PER_LINE;

			String line = text.substring(beginIndex, endIndex);
			multilineText.append(line);
			multilineText.append("<br>");
		}

		int beginIndex = CHARACTERS_PER_LINE * linesCount;
		int endIndex = text.length();
		String lastLine = text.substring(beginIndex, endIndex);
		multilineText.append(lastLine);

		return multilineText.toString();
	}

	/**
	 * {@inheritDoc}
	 */
    @Override
    public void itemExited(VisualItem item, MouseEvent e) {
        Display display = (Display) e.getSource();
        display.setToolTipText(null);
    }

}
