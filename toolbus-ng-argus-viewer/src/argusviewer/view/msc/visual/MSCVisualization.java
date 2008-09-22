package argusviewer.view.msc.visual;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.assignment.ColorAction;
import prefuse.activity.Activity;
import prefuse.data.Tuple;
import prefuse.data.expression.ColumnExpression;
import prefuse.data.expression.ComparisonPredicate;
import prefuse.data.expression.ObjectLiteral;
import prefuse.data.expression.Predicate;
import prefuse.data.expression.parser.ExpressionParser;
import prefuse.data.tuple.TupleSet;
import prefuse.render.DefaultRendererFactory;
import prefuse.util.ColorLib;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;
import toolbus.StateElement;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.view.msc.action.EntityVisibilityFilter;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.MSCData;
import argusviewer.view.msc.data.Message;
import argusviewer.view.msc.data.Statement;

/**
 * This class initializes and creates the visualization of
 * the Visualization of the Message Sequence Chart. The visualization
 * specifies the representation of the Message Sequence Chart data model.
 *
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Arne Timmerman
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author Alexander Bij
 * @author Roberto vd Linden
 */
public class MSCVisualization {

	private static final int RGB_COLOR_ASYNC_COMMUNICATION = ColorLib.rgb(216, 191, 216);
	private static final int RGB_COLOR_SYNC_COMMUNICATION = ColorLib.rgb(255, 242, 72);
	private static final int RGB_COLOR_TOOL_COMMUNICATION = ColorLib.rgb(179, 215, 143);
	private static final int RGB_COLOR_ENTITY_HIGHLIGHTED = ColorLib.rgb(152, 251, 152);
	private static final int RGB_COLOR_ENTITY_TERMINATED = ColorLib.rgb(211, 211, 211);

	private static final String ENTITY_SWIMLANE_NAME = "_swimlanes";
	private static final String ACTIONS_ID = "actions";

	private final MSCData mscData;

	private final Visualization m_visualization;
	private EntityVisibilityFilter m_entityVisiblityFilter;

	/**
	 * Construct a Visualization component for the Message Sequence Chart
	 * that visualizes the given data model.
	 *
	 * @param mscData the data model of the Message Sequence Chart
	 */
	public MSCVisualization(MSCData mscData) {
		this(mscData, new Visualization());
	}

	/**
	 * Construct a Visualization component for the Message Sequence Chart
	 * that visualizes the given data model on the given Prefuse Visualization.
	 *
	 * @param mscData	   the data model of the Message Sequence Chart
	 * @param visualization the Prefuse Visualization of the Message Sequence Chart Visualization
	 */
	private MSCVisualization(MSCData mscData, Visualization visualization) {
		this.mscData = mscData;
		this.m_visualization = visualization;
		
		// Do not show Prefuse INFO messages, only warnings and worse
		// Mind you: prefuse uses the java.util.logging.Logger, not our log4j logger...
		Logger.getLogger("prefuse").setLevel(Level.SEVERE);
		
		createVisualization();
	}

	/**
	 * Sets up the visualization information.
	 */
	private void createVisualization(){
		mscData.setVisualization(m_visualization);

		m_visualization.add(Entity.TABLE_NAME, mscData.getEntitiesTable());
		m_visualization.add(Statement.TABLE_NAME, mscData.getStatementsTable());
		m_visualization.add(Message.TABLE_NAME, mscData.getMessagesTable());

		// The visual statements and messages cannot be 'controlled' by the user
		m_visualization.setInteractive(Statement.TABLE_NAME, null, false);
		m_visualization.setInteractive(Message.TABLE_NAME, null, false);

		// Add swimlanes to the visualization of processes and tools
		m_visualization.addDecorators(ENTITY_SWIMLANE_NAME, Entity.TABLE_NAME);

		createRenderers();
		createActions();
	}

	/**
	 * Sets up the renderers for the individual visual items.
	 */
	private void createRenderers(){
		DefaultRendererFactory rendererFactory = new DefaultRendererFactory();

		rendererFactory.add(new InGroupPredicate(Entity.TABLE_NAME), new EntityRenderer());
		rendererFactory.add(new InGroupPredicate(Statement.TABLE_NAME), new StatementRenderer());
		rendererFactory.add(new InGroupPredicate(Message.TABLE_NAME), new MessageRenderer());
		rendererFactory.add(new InGroupPredicate(ENTITY_SWIMLANE_NAME), new SwimlaneRenderer(mscData));

		m_visualization.setRendererFactory(rendererFactory);
	}

	/**
	 * Sets up the actions for the visualization.
	 */
	private void createActions() {
		ActionList actions = new ActionList();

		ActionList colorActions = createColorActions();
		ActionList layoutActions = createLayoutActions();
		ActionList filterActions = createFilterActions();

		// Filter actions should be executed first, layout actions last
		actions.add(filterActions);
		actions.add(colorActions);
		actions.add(layoutActions);

		m_visualization.putAction(ACTIONS_ID, actions);
	}

	/**
	 * Sets up the actions for the layout.
	 *
	 * @return an ActionList that contains all layout actions
	 */
	private ActionList createLayoutActions() {
		ActionList layout = new ActionList();

		layout.add(new EntityLayout(Entity.TABLE_NAME, ENTITY_SWIMLANE_NAME));
		layout.add(new StatementLayout(mscData, Statement.TABLE_NAME));
		layout.add(new MessageLayout(Message.TABLE_NAME));
		layout.add(new RepaintAction());

		return layout;
	}

	/**
	 * Sets up the actions for the colors of the items in the visualization.
	 *
	 * @return an ActionList that contains all color actions
	 */
	private ActionList createColorActions() {
		ActionList colorActions = new ActionList();

		ActionList entityColorActions = createEntityColorActions();
		ActionList statementColorActions = createStatementColorAction();
		ActionList messageColorActions = createMessageColorActions();

		colorActions.add(entityColorActions);
		colorActions.add(statementColorActions);
		colorActions.add(messageColorActions);

		return colorActions;
	}

	/**
	 * Create actions for the colors of the entities and swimlanes in the visualization.
	 *
	 * @return an ActionList that contains entity color actions
	 */
	private ActionList createEntityColorActions() {
		ColorAction entityStroke = new ColorAction(Entity.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));
		ColorAction entityText = new ColorAction(Entity.TABLE_NAME,
				VisualItem.TEXTCOLOR, ColorLib.color(Color.BLACK));
		ColorAction entityFill = new ColorAction(Entity.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.WHITE));
		ColorAction swimlaneColor = new ColorAction(ENTITY_SWIMLANE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));

		entityFill.add(VisualItem.HIGHLIGHT, RGB_COLOR_ENTITY_HIGHLIGHTED);

		Predicate terminatedProcessPredicate = getTerminatedEntityComparePredicate(true);
		entityFill.add(terminatedProcessPredicate, RGB_COLOR_ENTITY_TERMINATED);

		ActionList entityColorActions = new ActionList();
		entityColorActions.add(entityStroke);
		entityColorActions.add(entityFill);
		entityColorActions.add(entityText);
		entityColorActions.add(swimlaneColor);
		return entityColorActions;
	}

	/**
	 * Create actions for the colors of the statements in the visualization.
	 *
	 * @return an ActionList that contains statement color actions
	 */
	private ActionList createStatementColorAction() {
		ColorAction statementStroke = new ColorAction(Statement.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));
		ColorAction statementFill = new ColorAction(Statement.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.WHITE));
		ColorAction statementText = new ColorAction(Statement.TABLE_NAME,
				VisualItem.TEXTCOLOR, ColorLib.color(Color.BLACK));

		Predicate toolCommPredicate = getStatementComparePredicate(Statement.TOOL_COMMUNICATION);
		statementFill.add(toolCommPredicate, RGB_COLOR_TOOL_COMMUNICATION);

		Predicate syncCommPredicate = getStatementComparePredicate(Statement.SYNC_COMMUNICATION);
		statementFill.add(syncCommPredicate, RGB_COLOR_SYNC_COMMUNICATION);

		Predicate aSyncCommPredicate = getStatementComparePredicate(Statement.ASYNC_COMMUNICATION);
		statementFill.add(aSyncCommPredicate, RGB_COLOR_ASYNC_COMMUNICATION);

		ActionList statementColorActions = new ActionList();
		statementColorActions.add(statementStroke);
		statementColorActions.add(statementFill);
		statementColorActions.add(statementText);
		return statementColorActions;
	}

	/**
	 * Create actions for the colors of the messages in the visualization.
	 *
	 * @return an ActionList that contains message color actions
	 */
	private ActionList createMessageColorActions() {
		ColorAction messageStroke = new ColorAction(Message.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));
		ColorAction messageFill = new ColorAction(Message.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.BLACK));
		messageFill.add(getMessageComparePredicate(Message.Type.ASYNC), RGB_COLOR_ASYNC_COMMUNICATION);
		messageFill.add(getMessageComparePredicate(Message.Type.SYNC), RGB_COLOR_SYNC_COMMUNICATION);
		messageFill.add(getMessageComparePredicate(Message.Type.TOOLCOMM), RGB_COLOR_TOOL_COMMUNICATION);

		ActionList messageColorActions = new ActionList();
		messageColorActions.add(messageStroke);
		messageColorActions.add(messageFill);
		return messageColorActions;
	}

	/**
	 * Create actions for filter functionality.
	 *
	 * @return an ActionList that contains all filter actions
	 */
	private ActionList createFilterActions() {

		ActionList filterActions = new ActionList();
		m_entityVisiblityFilter = new EntityVisibilityFilter();
		filterActions.add(m_entityVisiblityFilter);
		return filterActions;
	}

	/**
	 * Create a predicate to determine the type of statement (sync, async,
	 * toolcomm)
	 *
	 * @param statementTypes The statements that match the type of statement to
	 *                       search for.
	 * @return The predicate
	 */
	private Predicate getStatementComparePredicate(ArrayList<Class< ? extends StateElement>> statementTypes) {
		StringBuffer statementCmpPredicateText = new StringBuffer();

		for (int i = 0; i < statementTypes.size(); i++) {
			if (i != 0) {
				statementCmpPredicateText.append(" OR ");
			}

			String statementName = statementTypes.get(i).getSimpleName();

			// In order to use the substring we need
			// to check whether the string is long enough.
			// We fake an if statement by making 2 expressions
			// and combine them with a && so the left part of the
			// expressions is expressed first and if that's true it
			// continues to the right side of the expression
			statementCmpPredicateText.append("(LENGTH(");
			statementCmpPredicateText.append(Statement.STATEMENT_FIELDNAME);
			statementCmpPredicateText.append(") >= ");
			statementCmpPredicateText.append(statementName.length());
			statementCmpPredicateText.append(" && LOWER(LEFT(");
			statementCmpPredicateText.append(Statement.STATEMENT_FIELDNAME);
			statementCmpPredicateText.append(",");
			statementCmpPredicateText.append(statementName.length());
			statementCmpPredicateText.append(")) == LOWER('");
			statementCmpPredicateText.append(statementName);
			statementCmpPredicateText.append("'))");
		}
		return ExpressionParser.predicate(statementCmpPredicateText.toString());
	}

	/**
	 * Create a predicate to determine the current state of an entity from a table
	 *
	 * @param terminated Is the Entity terminated
	 * @return The predicate
	 */
	private Predicate getTerminatedEntityComparePredicate(boolean terminated) {
		ColumnExpression msgTypeColExpr = new ColumnExpression(Entity.RUNNING_FIELDNAME);
		ObjectLiteral msgTypeObjLit = new ObjectLiteral(Boolean.valueOf(!terminated));

		return new ComparisonPredicate(ComparisonPredicate.EQ, msgTypeColExpr, msgTypeObjLit);
	}

	/**
	 * Create a predicate to determine the type of message (async, sync, toolcomm)
	 *
	 * @param msgType The Message Type
	 * @return The predicate
	 */
	private Predicate getMessageComparePredicate(Message.Type msgType) {
		ColumnExpression msgTypeColExpr = new ColumnExpression(Message.TYPE_FIELDNAME);
		ObjectLiteral msgTypeObjLit = new ObjectLiteral(msgType);

		return new ComparisonPredicate(ComparisonPredicate.EQ, msgTypeColExpr, msgTypeObjLit);
	}

	/**
	 * Set an existing Entity as 'terminated' in the data model for this visualization.
	 *
	 * @param tick	   The current Tick
	 * @param entityType the type of the Entity
	 * @param entityId   the Id of the Entity
	 */
	public void setEntityTerminated(int tick, Entity.Type entityType, int entityId) {
		VisualItem entity = getEntity(entityType, entityId, false);

		if (entity != null) {
			entity.set(Entity.RUNNING_FIELDNAME, Boolean.FALSE);
			entity.set(Entity.ENDTICK_FIELDNAME, Integer.valueOf(tick));
			entity.setHighlighted(false);
		}
	}

	/**
	 * Set a Highlight on the Entity of the given type with the given id.
	 * The highlights of all other Entities are removed.
	 *
	 * @param entityType the type of the Entity to highlight
	 * @param entityId   the id of the Entity to highlight
	 */
	public void setEntityHighlight(Entity.Type entityType, int entityId) {
		VisualItem entity = getVisibleEntity(entityType, entityId);

		if (entity != null) {
			removeEntityHighlights();

			entity.setHighlighted(true);
		}
	}

	/**
	 * Set highlights on the Entities of the given type that has the
	 * given name.
	 * <p/>
	 * Note: entities of the same type can have the same name, they
	 * will all be highlighted
	 *
	 * @param entityType the type of the Entity to highlight
	 * @param entityName the name of the Entity to highlight
	 */
	public void setEntityHighlight(Entity.Type entityType, String entityName) {
		Iterator<VisualItem> entityIterator = m_visualization.visibleItems(Entity.TABLE_NAME);

		removeEntityHighlights();

		while (entityIterator.hasNext()) {
			VisualItem currentEntity = entityIterator.next();
			Entity.Type currentEntityType = (Entity.Type) currentEntity.get(Entity.TYPE_FIELDNAME);
			String currentEntityName = (String) currentEntity.get(Entity.NAME_FIELDNAME);

			if ((currentEntityType == entityType) && (currentEntityName.equals(entityName))) {
				currentEntity.setHighlighted(true);
			}
		}
	}

	/**
	 * Remove the highlights of all Entities.
	 */
	private void removeEntityHighlights() {
		TupleSet entityTuples = m_visualization.getVisualGroup(Entity.TABLE_NAME);
		Iterator<VisualItem> entityIterator = entityTuples.tuples();
		while (entityIterator.hasNext()) {
			VisualItem entity = entityIterator.next();
			entity.setHighlighted(false);
		}
	}

	/**
	 * Get the Visual representation of the visible Entity with
	 * given properties: type and id.
	 *
	 * @param entityType the type of the Entity, i.e. Entity.Type.TOOL
	 * @param entityId   the unique identifies of the Entity (per type)
	 * @return the visual representation of the Entity, null if there exists no Entity with the properties
	 */
	public VisualItem getVisibleEntity(Entity.Type entityType, int entityId) {
		return getEntity(entityType, entityId, true);
	}

	/**
	 * Get the Visual representation of the Entity with
	 * given properties: type and id. By setting visibleEntity to
	 * true this method only searches for visible Entities.
	 *
	 * @param entityType	the type of the Entity, i.e. Entity.Type.TOOL
	 * @param entityId	  the unique identifies of the Entity (per type)
	 * @param visibleEntity the visibility of the Entity
	 * @return the visual representation of the Entity, null if there exists no Entity with the properties
	 */
	private VisualItem getEntity(Entity.Type entityType, int entityId, boolean visibleEntity) {
		Iterator<VisualItem> entityIterator;

		if (visibleEntity) {
			entityIterator = m_visualization.visibleItems(Entity.TABLE_NAME);
		} else {
			entityIterator = m_visualization.items(Entity.TABLE_NAME);
		}

		while (entityIterator.hasNext()) {
			VisualItem currentEntity = entityIterator.next();
			Entity.Type currentEntityType = (Entity.Type) currentEntity.get(Entity.TYPE_FIELDNAME);
			int currentEntityId = ((Integer) currentEntity.get(Entity.ID_FIELDNAME)).intValue();

			if ((currentEntityType == entityType) && (currentEntityId == entityId)) {
				return currentEntity;
			}
		}

		return null;
	}

	/**
	 * Refresh the visualization by running all the actions that are
	 * attached to the visualization.
	 *
	 * @return the activity that represents the executing of all actions
	 */
	public Activity refreshVisualization() {
		return m_visualization.run(ACTIONS_ID);
	}

	//-------------------------------------------------------------------------------
	// Getters and Setters
	//-------------------------------------------------------------------------------

	/**
	 * Get the visualized representation of the given statement.
	 *
	 * @param statement the statement
	 * @return the visual representation of the Statement, null if there exists no such statement
	 */
	public VisualItem getVisibleStatement(Tuple statement) {
		return m_visualization.getVisualItem(Statement.TABLE_NAME, statement);
	}

	/**
	 * Get the Prefuse Visualization component that visualizes
	 * the Message Sequence Chart.
	 *
	 * @return the Prefuse Visualization of the Message Sequence Chart Visualization
	 */
	public Visualization getVisualization() {
		return m_visualization;
	}

	/**
	 * Set the ProcessInstances that should be visible in the Message Sequence Chart.
	 *
	 * @param visibleProcesses a list of ProcessInstances that should be visible
	 */
	public void setVisibleProcesses(List<ProcessInstance> visibleProcesses) {
		m_entityVisiblityFilter.setVisibleProcesses(visibleProcesses);
	}

	/**
	 * Set the ToolInstances that should be visible in the Message Sequence Chart.
	 *
	 * @param visibleTools a list of ToolInstances that should be visible
	 */
	public void setVisibleTools(List<ToolInstance> visibleTools) {
		m_entityVisiblityFilter.setVisibleTools(visibleTools);
	}


}
