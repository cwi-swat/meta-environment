package argusviewer.view.architectureview;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;
import javax.swing.JScrollPane;

import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.assignment.ColorAction;
import prefuse.controls.Control;
import prefuse.controls.ControlAdapter;
import prefuse.controls.PanControl;
import prefuse.controls.ZoomControl;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;
import argusviewer.toolbus.DataComm;
import argusviewer.view.architectureview.performance.tree.PerformanceTreeTable;

/**
 * This class implements the PerformanceView for the Argus Viewer
 * 
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 * @author John Franse
 * @author Tigran Kalaidjan
 */
public class ArchitectureView extends JPanel {
	private static final long serialVersionUID = 2560820747109793313L;
	
	private static final double HORIZONTAL_DISPLAY_OFFSET = 75;
	private static final double VERTICAL_DISPLAY_OFFSET = 50;
	
	public static final String PROCESS_LABEL = "_processlabel";
	public static final String TOOL_LABEL = "_toollabel";

	private static final int RGB_COLOR_PROCESS_HIGHLIGHTED = ColorLib.rgb(152, 251, 152);
	
	private static final String ACTIONS_ID = "actions";
	
	private final ArchitectureData m_archData;
	private final Visualization m_visualization;
	private final PerformanceTreeTable m_performanceTreeTable;
	
	private Display m_display;
	private JPanel m_visualComponent;
	private MessageVisibility m_messageFilter;
	private ProcessLayout m_processLayout;
	/*
	 * The graphical components 
	 */
	private JScrollPane m_scrollPane = new JScrollPane(null);
	
	/**
	 * Constructs the Architecture View Panel
	 * @param dataComm the dataComm this view will retrieve it's data from
	 * @param archData the data model used in this view
	 * @param archVisualization the visualization to use
	 * @param performanceTreeTable an instance of the PerformanceTreeTable
	 */
	public ArchitectureView(DataComm dataComm, ArchitectureData archData, Visualization archVisualization,
			PerformanceTreeTable performanceTreeTable) {
		m_archData = archData;
		m_visualization = archVisualization;
		m_performanceTreeTable = performanceTreeTable;
		
		this.setLayout(new BorderLayout());
		this.add(m_scrollPane, BorderLayout.CENTER);
		
		setupVisualization();
	}
	
	/**
	 * Sets up the visualization information.
	 */
	private void setupVisualization() {
		m_visualization.add(Process.TABLE_NAME, m_archData.getProcessesTable());
		m_visualization.addDecorators(PROCESS_LABEL, Process.TABLE_NAME);

		m_visualization.add(Tool.TABLE_NAME, m_archData.getToolsTable());
		m_visualization.addDecorators(TOOL_LABEL, Tool.TABLE_NAME);

		m_visualization.add(ToolbusSingleton.TABLE_NAME, m_archData.getToolbusSingletonTable());
		
		m_visualization.add(Message.TABLE_NAME, m_archData.getMessageTable());
	
		// The visual components cannot be 'controlled' by the user
		m_visualization.setInteractive(Process.TABLE_NAME, null, false);
		m_visualization.setInteractive(Tool.TABLE_NAME, null, false);
		m_visualization.setInteractive(ToolbusSingleton.TABLE_NAME, null, false);
		m_visualization.setInteractive(Message.TABLE_NAME, null, false);

		// Actions go first as the ToolbusSingletonRenderer needs the
		// ProcessLayout.
		createActions();
		createRenderers();
	}

    /**
	 * Get the Visual Component of the Architecture View.
	 * The Visual Component holds the PreFuse Display that is placed
	 * on the Visualization of the Architecture View.
	 *
	 * @return visual component of the Architecture View
	 */
	public JPanel getVisualComponent() {
		if (m_visualComponent == null) {
			createVisualComponent();
		}

		return m_visualComponent;
	}

	private void createVisualComponent() {
		createDisplay();
		createDisplayControls();

		m_visualComponent = new JPanel(new BorderLayout());
		m_visualComponent.add(m_display, BorderLayout.CENTER);
	}
	
	private void createDisplay() {
		m_display = new Display(m_visualization);
		m_display.setDoubleBuffered(true);
		m_display.panAbs(HORIZONTAL_DISPLAY_OFFSET, VERTICAL_DISPLAY_OFFSET);
		m_display.setItemSorter(new ArchitectureItemSorter());

		Control hoverc = new ControlAdapter() {
            public void itemClicked(VisualItem item, MouseEvent evt) {
     			m_messageFilter.setSelectedVisualItem(item);
     			
     			// If item is a tool, ask Performance Tree Table to focus on it
     			if (item.getGroup().equals(Tool.TABLE_NAME)) {
     				String toolName = item.get(Tool.TOOL_FIELDNAME).toString();
     				m_performanceTreeTable.setFocus(toolName);
     			}
         		updateVisualization();
            }
        };
		m_display.addControlListener(hoverc);

		updateVisualization();
	}
	
	private void createDisplayControls() {
		m_display.addControlListener(new PanControl(true)); // Pan over item also
		m_display.addControlListener(new ZoomControl());
	}
	
	/**
	 * Sets up the actions for the visualization.
	 */
	private void createActions() {

		ActionList colorActions = createColorActions();
		ActionList filterActions = createFilterActions();
		ActionList layoutActions = createLayoutActions();
		
		
		// Color actions should be executed first, layout actions last
		ActionList actions = new ActionList();
		actions.add(colorActions);
		actions.add(filterActions);
		actions.add(layoutActions);

		m_visualization.putAction(ACTIONS_ID, actions);
	}

	/**
	 * Sets up the actions for the layout.
	 * @return an ActionList that contains all layout actions
	 */
	private ActionList createLayoutActions() {
		ActionList layout = new ActionList();
		m_processLayout = new ProcessLayout(Process.TABLE_NAME);
		layout.add(m_processLayout);
		layout.add(new ToolLayout(Tool.TABLE_NAME, m_processLayout));
		
		layout.add(new ToolbusSingletonLayout(ToolbusSingleton.TABLE_NAME, m_processLayout));
		
		layout.add(new RepaintAction());

		return layout;
	}

	/**
	 * Sets up the actions for the colors of the items in the visualization.
	 * @return an ActionList that contains all color actions
	 */
	private ActionList createColorActions() {

		// Color Actions for Process items
		ColorAction processStroke = new ColorAction(Process.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));
		ColorAction processFill = new ColorAction(Process.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.WHITE));

		// Color Actions for Tool items
		ColorAction toolStroke = new ColorAction(Tool.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));
		ColorAction toolFill = new ColorAction(Process.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.WHITE));
		
		// Color Actions for label items
		ColorAction processLabelText = new ColorAction(PROCESS_LABEL,
				VisualItem.TEXTCOLOR, ColorLib.color(Color.BLACK));
		ColorAction toolLabelText = new ColorAction(TOOL_LABEL,
				VisualItem.TEXTCOLOR, ColorLib.color(Color.BLACK));		
	
		// Color Actions for Message items
		ColorAction messageStroke = new ColorAction(Message.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLUE));
		ColorAction messageFill = new ColorAction(Message.TABLE_NAME,
				VisualItem.FILLCOLOR, ColorLib.color(Color.BLUE));

		// Color Actions for ToolbusSingleton item
		ColorAction toolbusStroke = new ColorAction(ToolbusSingleton.TABLE_NAME,
				VisualItem.STROKECOLOR, ColorLib.color(Color.BLACK));

		processFill.add(VisualItem.HIGHLIGHT, RGB_COLOR_PROCESS_HIGHLIGHTED);

		ActionList colorActions = new ActionList();
		colorActions.add(processStroke);
		colorActions.add(processFill);
		
		colorActions.add(toolStroke);
		colorActions.add(toolFill);

		colorActions.add(processLabelText);
		colorActions.add(toolLabelText);

		colorActions.add(messageStroke);
		colorActions.add(messageFill);

		colorActions.add(toolbusStroke);

		ActionList allColorActions = new ActionList();
		allColorActions.add(colorActions);

		return allColorActions;
	}
	
	/**
	 * Create actions for filter functionality.
	 * @return an ActionList that contains all filter actions
	 */
	private ActionList createFilterActions() {

		ActionList filterActions = new ActionList();
		m_messageFilter = new MessageVisibility();
		filterActions.add(m_messageFilter);
		return filterActions;
	}

	/**
	 * Sets up the renderers for the individual visual items.
	 */
	private void createRenderers() {
		DefaultRendererFactory rendererFactory = new DefaultRendererFactory();

		rendererFactory.add(new InGroupPredicate(Process.TABLE_NAME),
				new ProcessRenderer());
		rendererFactory.add(new InGroupPredicate(Tool.TABLE_NAME),
				new ToolRenderer());
		
		rendererFactory.add(new InGroupPredicate(ToolbusSingleton.TABLE_NAME),
				new ToolbusSingletonRenderer(m_processLayout));
		rendererFactory.add(new InGroupPredicate(Message.TABLE_NAME), new MessageRenderer());
		
		rendererFactory.add(new InGroupPredicate(PROCESS_LABEL),
				new LabelRenderer(Process.PROCESS_FIELDNAME));
		rendererFactory.add(new InGroupPredicate(TOOL_LABEL),
				new LabelRenderer(Tool.TOOL_FIELDNAME));

		
		m_visualization.setRendererFactory(rendererFactory);
	}
	
	/**
	 * This function processes the visualization redrawing, by running all the actions that 
	 * are attached to the visualization.
	 */
	public void updateVisualization() {
		m_visualization.run(ACTIONS_ID);
	}
}
