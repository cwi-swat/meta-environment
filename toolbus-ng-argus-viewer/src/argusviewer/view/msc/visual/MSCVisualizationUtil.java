package argusviewer.view.msc.visual;

import prefuse.Visualization;
import prefuse.data.expression.parser.ExpressionParser;
import prefuse.visual.VisualItem;

import java.util.ArrayList;
import java.util.Iterator;
import argusviewer.util.ArgusSettings;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.Message;
import argusviewer.view.msc.data.Statement;

/**
 * @author: Arne Timmerman
 */
public class MSCVisualizationUtil {

	/**
	 * Check if the target entity of a statement is visible.
	 *
	 * @param currentStatement the statement to check the target entities of.
	 * @param visualization the prefuse visualization to check
	 * @return true if the target Entity is visible
	 */
	public static boolean isTargetEntityVisible(Visualization visualization, VisualItem currentStatement) {
		int timestamp = ((Integer) currentStatement.get(Statement.TIMESTAMP_FIELDNAME)).intValue();

		// Find all messages that are send on this timestamp
		String searchText = Message.SOURCEID_FIELDNAME + " == " + timestamp;
		Iterator<VisualItem> matchingMessages = visualization.items(Message.TABLE_NAME,
				ExpressionParser.predicate(searchText));

		if (matchingMessages.hasNext()) {
			VisualItem message = matchingMessages.next();

			ArrayList<String> messageTargetIds = (ArrayList<String>) message.get(Message.TARGETIDS_FIELDNAME);

			for (String targetId : messageTargetIds) {
				String entitySearchText = "CONCAT(" + Entity.NAME_FIELDNAME + "," + Entity.ID_FIELDNAME
						+ ")" + " == '" + targetId + "'";

				Iterator<VisualItem> targetEntities = visualization.items(Entity.TABLE_NAME, ExpressionParser.predicate(entitySearchText));
				if (targetEntities.hasNext()) {
					VisualItem targetEntity = targetEntities.next();

					if (targetEntity.isVisible()) {
						return true;
					}
				}
			}
		}
		return false;
	}

	/**
	 * Get the Visual representation of the Statement that was executed on the
	 * given timestamp.
	 *
	 * @param visualization the Prefuse visualisation where the item is placed on
	 * @param timestamp the timestamp of the execution of the statement
	 * @return the visual representation of the Statement, null if there exists no Statement with the properties
	 */
	public static VisualItem getStatement(Visualization visualization, int timestamp) {
		Iterator<VisualItem> statementIterator = visualization.items(Statement.TABLE_NAME);

		while (statementIterator.hasNext()) {
			VisualItem currentStatement = statementIterator.next();
			int currentTimestamp = ((Integer) currentStatement.get(Statement.TIMESTAMP_FIELDNAME)).intValue();

			if (currentTimestamp == timestamp) {
				return currentStatement;
			}
		}

		return null;
	}

	/**
	 * Check if the automatic statement collapse is enabled.
	 * This setting is stored in the settings file.
	 * @return true if automatic statement collapse is enabled, else false
	 */
	public static boolean isStatementCollapseEnabled() {
		ArgusSettings settings = ArgusSettings.getInstance();
		String collapseSetting = settings.getAttribute("msc.collapse", "true");
		return collapseSetting.equals("true");
	}

}
