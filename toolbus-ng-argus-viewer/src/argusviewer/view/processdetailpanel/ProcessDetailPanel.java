package argusviewer.view.processdetailpanel;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTable;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.environment.Binding;
import toolbus.environment.Environment;
import toolbus.process.ProcessInstance;
import toolbus.tool.ToolInstance;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.listeners.IHighlightListener;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * 
 * This class is the Detailed Process View. 
 * This view is a ported version of the old toolbus-ng viewer. 
 * @see toolbus.viewer.Viewer
 *
 * @author Tim Van Laer
 * @author Jesper Wulffers
 */
public class ProcessDetailPanel extends JPanel implements IView, IHighlightListener {
	private static final long	serialVersionUID	= 1L;

	private JTable m_stateTable;

	private DefaultTableModel m_subscriptionsTableModel;
	private DefaultTableModel m_variablesTableModel;
	private DefaultTableModel m_noteQueueTableModel;
	private DefaultTableModel m_stateTableModel;

	private static final TBTermFactory TBFACTORY = TBTermFactory.getInstance();
	private static final ATerm EMPTYTERM = TBFACTORY.makeAppl(TBFACTORY.makeAFun("...", 0, false));
	private static final int VERTICAL_DIVIDER_LOC = 350;
	private static final int HORIZONTAL_DIVIDER_LOC = 200;
	
	// vars for subtitution of aterms.
	private static final int SUB_SUBSCRIPTION = 3;
	private static final int SUB_VARIABLE = 2;
	private static final int SUB_NOTE = 3;
	
	private DataComm m_dataComm;

	/**
	 * Constructor of the processDetailView
	 * @param dataComm the DataComm object used for data retrieval
	 */
	public ProcessDetailPanel(DataComm dataComm) {
		m_dataComm = dataComm;
		m_dataComm.getFocusSync().register(this);
		
		setLayout(new GridLayout(1, 1));
		
		JSplitPane topSplitPane = new JSplitPane(
				JSplitPane.VERTICAL_SPLIT,
				createSubscriptionsPanel(),
				createNoteQueuePanel()
		);
		
		topSplitPane.setOneTouchExpandable(true);

		JSplitPane bottomSplitPane = new JSplitPane(
				JSplitPane.VERTICAL_SPLIT,
				createStateTableModel(),
				createVariablesPanel()
		);
		
		bottomSplitPane.setOneTouchExpandable(true);
		
		JSplitPane mainSplitPane = new JSplitPane(
				JSplitPane.HORIZONTAL_SPLIT,
				topSplitPane,
				bottomSplitPane
		);
		
		bottomSplitPane.setOneTouchExpandable(true);		
		
		add(mainSplitPane);		
				
		topSplitPane.setDividerLocation(HORIZONTAL_DIVIDER_LOC);
		bottomSplitPane.setDividerLocation(HORIZONTAL_DIVIDER_LOC);
		mainSplitPane.setDividerLocation(VERTICAL_DIVIDER_LOC);
	}
	
	private JPanel createStateTableModel() {
		JPanel statePanel = new JPanel();
		statePanel.setLayout(new BorderLayout());
		String[] stateTableHeader = new String[]{"State"};

		StateTableSelectionListener stateTableSelectionListener = new StateTableSelectionListener();
		m_stateTableModel = new DefaultTableModel(new Object[0][0], stateTableHeader) {
			private static final long serialVersionUID = 7405647403653515348L;

			public boolean isCellEditable(int row, int column) {
				return false;
			}
		};
		m_stateTable = new JTable(m_stateTableModel);
		ListSelectionModel stateSelectionModel = m_stateTable.getSelectionModel();
		stateSelectionModel.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		stateSelectionModel.addListSelectionListener(stateTableSelectionListener);
		
		JScrollPane stateScrollPane = new JScrollPane(m_stateTable);
		statePanel.add(stateScrollPane, BorderLayout.CENTER);
		return statePanel;
	}

	private JPanel createNoteQueuePanel() {
		JPanel noteQueuePanel = new JPanel();
		noteQueuePanel.setLayout(new BorderLayout());
		m_noteQueueTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Note Queue"}) {
			private static final long serialVersionUID = -5038729871288100318L;

			public boolean isCellEditable(int row, int column) {
				return false;
			}
		};
		JTable noteQueueTable = new JTable(m_noteQueueTableModel);
		JScrollPane noteQueueScrollPane = new JScrollPane(noteQueueTable);
		noteQueuePanel.add(noteQueueScrollPane, BorderLayout.CENTER);
		return noteQueuePanel;
	}

	private JPanel createVariablesPanel() {
		JPanel variablesPanel = new JPanel();
		variablesPanel.setLayout(new BorderLayout());
		m_variablesTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Variable", "Value"}) {
			private static final long serialVersionUID = 4345972041423779621L;

			public boolean isCellEditable(int row, int column) {
				return false;
			}
		};
		JTable variablesTable = new JTable(m_variablesTableModel);
		
		JScrollPane variablesScrollPane = new JScrollPane(variablesTable);
		variablesPanel.add(variablesScrollPane, BorderLayout.CENTER);
		return variablesPanel;
	}

	private JPanel createSubscriptionsPanel() {
		JPanel subscriptionsPanel = new JPanel();
		subscriptionsPanel.setLayout(new BorderLayout());
		m_subscriptionsTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Subscriptions"}) {
			private static final long serialVersionUID = 2407227292333227911L;

			public boolean isCellEditable(int row, int column) {
				return false;
			}
		};
		JTable subscriptionsTable = new JTable(m_subscriptionsTableModel);
		
		JScrollPane subscriptionsScrollPane = new JScrollPane(subscriptionsTable);
		subscriptionsPanel.add(subscriptionsScrollPane, BorderLayout.CENTER);
		return subscriptionsPanel;
	}
	
	private void clearSubscriptionsTable() {
		clearTable(m_subscriptionsTableModel);
	}

	private void clearNoteQueueTable() {
		clearTable(m_noteQueueTableModel);		
	}

	private void clearStateTable() {
		clearTable(m_stateTableModel);
	}

	private void clearVariablesTable() {
		clearTable(m_variablesTableModel);
	}
	
	private void clearTable(DefaultTableModel tableModel) {
		for (int i = tableModel.getRowCount() - 1; i >= 0; i--) {
			tableModel.removeRow(i);
		}		
	}

	/**
	 * ListSelectionListener for the StateTable 
	 */
	private class StateTableSelectionListener implements ListSelectionListener {
		public StateTableSelectionListener() {
			super();
		}

		public void valueChanged(ListSelectionEvent e) {
			clearVariablesTable();

        	int row = getStateTable().getSelectedRow();
        	if (row != -1) {
            	StateElement stateElement = (StateElement) m_stateTableModel.getValueAt(row, 0);
            	fillVariables(stateElement);
        	}
		}
	}
	
	/**
	 * get state jtable
	 * @return statetable
	 */
	public JTable getStateTable() {
		return m_stateTable;
	}
	
	private void fillProcessTables(ProcessInstance processInstance) {
		clearSubscriptionsTable();
		
		List<ATerm> subscriptions = processInstance.getSubscriptions();
        for (ATerm subscription1 : subscriptions) {
            String subscription = getSubscriptionSignature(subscription1);
            m_subscriptionsTableModel.addRow(new Object[]{subscription});
        }
		
		
		clearNoteQueueTable();
		
		List<ATerm> noteQueue = processInstance.getNoteQueue();
        for (ATerm aNoteQueue : noteQueue) {
            String note = getNoteSignature(aNoteQueue);
            m_noteQueueTableModel.addRow(new Object[]{note});
        }
		
		
		clearStateTable();
		
		List<StateElement> stateElements = processInstance.getCurrentState().getElementsAsList();
        for (StateElement stateElement1 : stateElements) {
            StateElement stateElement = stateElement1;
            m_stateTableModel.addRow(new Object[]{stateElement});
        }
	}

	private void fillVariables(StateElement stateElement) {
		// Insert the new data in case the state element is an atom (and thus has an environment).
		if (stateElement != null && stateElement instanceof Atom) {
			Atom atom = (Atom) stateElement;
			Environment environment = atom.getEnv();
			java.util.List<Binding> bindings = environment.getBindingsAsList();
            for (Binding binding1 : bindings) {
                Binding binding = binding1;
                String var = binding.getVar().toString();
                String val = getVariableSignature(binding.getVal());
                m_variablesTableModel.addRow(new Object[]{var, val});
            }
		}
	}

	private static String getSubscriptionSignature(ATerm term) {
		ATerm result = substituteTerm(term, SUB_SUBSCRIPTION);		
		return result.toString();
	}

	private static String getVariableSignature(ATerm term) {
		ATerm result = substituteTerm(term, SUB_VARIABLE);		
		return result.toString();
	}

	private static String getNoteSignature(ATerm term) {
		ATerm result = substituteTerm(term, SUB_NOTE);		
		return result.toString();
	}

	private static ATerm substituteTerm(ATerm term, int maxDept) {
		int termType = term.getType();
		switch (termType) {
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) term;
				if (apt.getArity() == 0) { return term; }

				AFun afun = apt.getAFun();
				ATerm[] args = apt.getArgumentArray();
				ATermList annos = TBFACTORY.EmptyList; // Strip the annotations.

				if (maxDept <= 0) { 
					return TBFACTORY.makeAppl(TBFACTORY.makeAFun(afun.getName(), 1, false), new ATerm[]{EMPTYTERM}, annos);
				}

				int nargs = args.length;
				ATerm[] vargs = new ATerm[nargs];
				for (int i = 0; i < nargs; i++) {
					vargs[i] = substituteTerm(args[i], maxDept - 1);
				}
				return TBFACTORY.makeAppl(afun, vargs, annos);

			case ATerm.LIST:
				if (maxDept <= 0) {
					ATermList emptyListTerm = TBFACTORY.EmptyList;
					return emptyListTerm.insert(EMPTYTERM);
				}

				ATermList tlst = (ATermList) term;

				if (tlst == TBFACTORY.EmptyList) {
					return term;
				}

				int len = tlst.getLength();
				ATerm[] listContent = new ATerm[len];
				for (int i = len - 1; i >= 0; i--) {
					listContent[i] = tlst.getFirst();
					tlst = tlst.getNext();
				}

				ATermList lst = TBFACTORY.EmptyList;
				for (int i = 0; i < len; i++) {
					lst = lst.insert((substituteTerm(listContent[i], maxDept - 1)));
				}

				// We can ignore annotations, since lists with annotations aren't supported anyway

				return lst;
			default:
				return term;
		}
	}

	/**	
	 * {@inheritDoc}
	 */
	public void setHighlight(ProcessInstance processInstance) {
			clearSubscriptionsTable();
			clearNoteQueueTable();
			clearStateTable();
			clearVariablesTable();
			fillProcessTables(processInstance);
	}

	/**
	 * 
	 * {@inheritDoc}
	 */
    public Map<String, Container> getVisualComponents() {
        HashMap< String, Container> nameContainerHashMap = new HashMap<String, Container>();
        nameContainerHashMap.put("Process Details", this);
    	return nameContainerHashMap;
    } 

    /**
     * get table model of subscriptions table
     * @return table model of subscriptions table
     */
	public TableModel getSubscriptionsTableModel() {
		return m_subscriptionsTableModel;
	}
	
	/**
     * get table model of variables table
     * @return table model of variables table
     */
	public TableModel getVariablesTableModel() {
		return m_variablesTableModel;
	}
	
	/**
     * get table model of notes table
     * @return table model of notes table
     */
	public TableModel getNotesTableModel() {
		return m_noteQueueTableModel;
	}

    /**
     * Return preferred position
     *
     * @return String preferred position
     */
    public String getPreferredPosition() {
		return "TopRight";
	}

    /**
     * {@inheritDoc}
     */
    public void setHighlight(ToolInstance toolInstance) {
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}

    /**
     * {@inheritDoc}
     */
    public void setHighlightByProcessName(String processName) {
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}

    /**
     * {@inheritDoc}
     */
    public void setHighlightByToolName(String toolName) {
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}

    /**
     * Returns the pluging Name
     * @return String Plugin Name
     */
    public String getPluginName() {
		return "Process Detail Panel";
	}
}

