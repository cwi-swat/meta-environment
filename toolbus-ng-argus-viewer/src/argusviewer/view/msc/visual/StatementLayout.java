package argusviewer.view.msc.visual;

import prefuse.action.layout.Layout;
import prefuse.data.Tuple;
import prefuse.data.expression.parser.ExpressionParser;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;

import java.util.Iterator;
import java.util.LinkedList;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.MSCData;
import argusviewer.view.msc.data.Statement;

/**
 * The layout used to align statements under their corresponding process or tool.
 * Note that statements are set to invisible if the corresponding entity is invisble.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Roberto van der Linden
 * @author Arne Timmerman
 */
public class StatementLayout extends Layout {

	public static final int VERTICAL_OFFSET = 100;
	public static final int VERTICAL_STEP = 40;

	/**
	 * Create a new Statement layout for the specified group.
	 *
	 * @param group The group of visual items on which the layout will be applied
	 */
	public StatementLayout(String group) {
		super(group);
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double frac) {
		double currentX;
		double currentY = VERTICAL_OFFSET;
		boolean statementCollapseEnabled = MSCVisualizationUtil.isStatementCollapseEnabled();

		// This should be cloned, because the list can be modified during executing of this action.
		LinkedList<Tuple> statements = (LinkedList<Tuple>) MSCData.getStatementList().clone();
		for (Tuple statement : statements) {

			VisualItem currentStatement = m_vis.getVisualItem(Statement.TABLE_NAME, statement);

			// Find all the entities this statement belongs to, should be only one
			String parentId = currentStatement.getString(Statement.PARENTID_FIELDNAME);
			String searchPredicateText = "CONCAT(" + Entity.NAME_FIELDNAME + "," + Entity.ID_FIELDNAME
					+ ")" + " == '" + parentId + "'";

			Iterator<VisualItem> matchingEntities = m_vis.items(Entity.TABLE_NAME, ExpressionParser.predicate(searchPredicateText));
			if (matchingEntities.hasNext()) {
				VisualItem matchingEntity = matchingEntities.next();
				currentX = matchingEntity.getX();

				setX(currentStatement, null, currentX);
				setY(currentStatement, null, currentY);

				// If collapsing is enabled, set correct positions only to visible statements or visible targets
				if (statementCollapseEnabled) {
					if (matchingEntity.isVisible() || MSCVisualizationUtil.isTargetEntityVisible(m_vis, currentStatement)) {
						currentY += VERTICAL_STEP;
					}

				// If collapsing is disabled, set correct positions to all statements
				} else {
					currentY += VERTICAL_STEP;
				}

				PrefuseLib.updateVisible(currentStatement, matchingEntity.isVisible());
			} else {
				// A statement has no parent entity, hide it
				PrefuseLib.updateVisible(currentStatement, false);
			}
		}
	}

}
