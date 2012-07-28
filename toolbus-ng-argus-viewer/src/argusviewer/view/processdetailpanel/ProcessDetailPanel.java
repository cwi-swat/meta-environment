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

public class ProcessDetailPanel extends JPanel implements IView, IHighlightListener{
	private static final long serialVersionUID = 3494914345486450890L;

	private JTable stateTable;

	private DefaultTableModel subscriptionsTableModel;
	private DefaultTableModel variablesTableModel;
	private DefaultTableModel noteQueueTableModel;
	private DefaultTableModel stateTableModel;

	private final static TBTermFactory TBFACTORY = TBTermFactory.getInstance();
	private final static ATerm EMPTYTERM = TBFACTORY.makeAppl(TBFACTORY.makeAFun("...", 0, false));
	private final static int VERTICAL_DIVIDER_LOC = 350;
	private final static int HORIZONTAL_DIVIDER_LOC = 200;
	
	private final static int SUB_SUBSCRIPTION = 3;
	private final static int SUB_VARIABLE = 2;
	private final static int SUB_NOTE = 3;
	
	public ProcessDetailPanel(DataComm dataComm){
		dataComm.getFocusSync().register(this);
		
		setLayout(new GridLayout(1, 1));
		
		JSplitPane topSplitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, createSubscriptionsPanel(), createNoteQueuePanel());
		topSplitPane.setOneTouchExpandable(true);

		JSplitPane bottomSplitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT, createStateTableModel(), createVariablesPanel());
		bottomSplitPane.setOneTouchExpandable(true);
		
		JSplitPane mainSplitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, topSplitPane, bottomSplitPane);
		bottomSplitPane.setOneTouchExpandable(true);		
		
		add(mainSplitPane);		
				
		topSplitPane.setDividerLocation(HORIZONTAL_DIVIDER_LOC);
		bottomSplitPane.setDividerLocation(HORIZONTAL_DIVIDER_LOC);
		mainSplitPane.setDividerLocation(VERTICAL_DIVIDER_LOC);
	}
	
	private JPanel createStateTableModel(){
		JPanel statePanel = new JPanel();
		statePanel.setLayout(new BorderLayout());
		String[] stateTableHeader = new String[]{"State"};

		StateTableSelectionListener stateTableSelectionListener = new StateTableSelectionListener();
		stateTableModel = new DefaultTableModel(new Object[0][0], stateTableHeader){
			private static final long serialVersionUID = 7405647403653515348L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		stateTable = new JTable(stateTableModel);
		ListSelectionModel stateSelectionModel = stateTable.getSelectionModel();
		stateSelectionModel.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		stateSelectionModel.addListSelectionListener(stateTableSelectionListener);
		
		JScrollPane stateScrollPane = new JScrollPane(stateTable);
		statePanel.add(stateScrollPane, BorderLayout.CENTER);
		return statePanel;
	}

	private JPanel createNoteQueuePanel(){
		JPanel noteQueuePanel = new JPanel();
		noteQueuePanel.setLayout(new BorderLayout());
		noteQueueTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Note Queue"}){
			private static final long serialVersionUID = -5038729871288100318L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		JTable noteQueueTable = new JTable(noteQueueTableModel);
		JScrollPane noteQueueScrollPane = new JScrollPane(noteQueueTable);
		noteQueuePanel.add(noteQueueScrollPane, BorderLayout.CENTER);
		return noteQueuePanel;
	}

	private JPanel createVariablesPanel(){
		JPanel variablesPanel = new JPanel();
		variablesPanel.setLayout(new BorderLayout());
		variablesTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Variable", "Value"}) {
			private static final long serialVersionUID = 4345972041423779621L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		JTable variablesTable = new JTable(variablesTableModel);
		
		JScrollPane variablesScrollPane = new JScrollPane(variablesTable);
		variablesPanel.add(variablesScrollPane, BorderLayout.CENTER);
		return variablesPanel;
	}

	private JPanel createSubscriptionsPanel(){
		JPanel subscriptionsPanel = new JPanel();
		subscriptionsPanel.setLayout(new BorderLayout());
		subscriptionsTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Subscriptions"}) {
			private static final long serialVersionUID = 2407227292333227911L;

			public boolean isCellEditable(int row, int column) {
				return false;
			}
		};
		JTable subscriptionsTable = new JTable(subscriptionsTableModel);
		
		JScrollPane subscriptionsScrollPane = new JScrollPane(subscriptionsTable);
		subscriptionsPanel.add(subscriptionsScrollPane, BorderLayout.CENTER);
		return subscriptionsPanel;
	}
	
	private void clearTable(DefaultTableModel tableModel){
		for(int i = tableModel.getRowCount() - 1; i >= 0; i--){
			tableModel.removeRow(i);
		}		
	}
	
	private class StateTableSelectionListener implements ListSelectionListener{
		public StateTableSelectionListener(){
			super();
		}

		public void valueChanged(ListSelectionEvent e){
			clearTable(variablesTableModel);

        	int row = stateTable.getSelectedRow();
        	if(row != -1){
            	StateElement stateElement = (StateElement) stateTableModel.getValueAt(row, 0);
            	fillVariables(stateElement);
        	}
		}
	}
	
	private void fillProcessTables(ProcessInstance processInstance){
		clearTable(subscriptionsTableModel);
		
		List<ATerm> subscriptions = processInstance.getSubscriptions();
        for(ATerm subscription1 : subscriptions){
            String subscription = getSubscriptionSignature(subscription1);
            subscriptionsTableModel.addRow(new Object[]{subscription});
        }
		
		
        clearTable(noteQueueTableModel);
		
		List<ATerm> noteQueue = processInstance.getNoteQueue();
        for(ATerm aNoteQueue : noteQueue){
            String note = getNoteSignature(aNoteQueue);
            noteQueueTableModel.addRow(new Object[]{note});
        }
		
		
        clearTable(stateTableModel);
		
		List<StateElement> stateElements = processInstance.getCurrentState().getElementsAsList();
		for(StateElement stateElement1 : stateElements){
			StateElement stateElement = stateElement1;
			stateTableModel.addRow(new Object[]{stateElement});
        }
	}

	private void fillVariables(StateElement stateElement){
		// Insert the new data in case the state element is an atom (and thus has an environment).
		if(stateElement != null && stateElement instanceof Atom){
			Atom atom = (Atom) stateElement;
			Environment environment = atom.getEnv();
			java.util.List<Binding> bindings = environment.getBindingsAsList();
            for (Binding binding1 : bindings){
                Binding binding = binding1;
                String var = binding.getVar().toString();
                String val = getVariableSignature(binding.getVal());
                variablesTableModel.addRow(new Object[]{var, val});
            }
		}
	}

	private static String getSubscriptionSignature(ATerm term){
		ATerm result = substituteTerm(term, SUB_SUBSCRIPTION);		
		return result.toString();
	}

	private static String getVariableSignature(ATerm term){
		ATerm result = substituteTerm(term, SUB_VARIABLE);		
		return result.toString();
	}

	private static String getNoteSignature(ATerm term){
		ATerm result = substituteTerm(term, SUB_NOTE);		
		return result.toString();
	}

	private static ATerm substituteTerm(ATerm term, int maxDept){
		int termType = term.getType();
		switch (termType){
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) term;
				if(apt.getArity() == 0) return term;

				AFun afun = apt.getAFun();
				ATerm[] args = apt.getArgumentArray();
				ATermList annos = TBFACTORY.EmptyList; // Strip the annotations.

				if(maxDept <= 0) return TBFACTORY.makeAppl(TBFACTORY.makeAFun(afun.getName(), 1, false), new ATerm[]{EMPTYTERM}, annos);

				int nargs = args.length;
				ATerm[] vargs = new ATerm[nargs];
				for(int i = 0; i < nargs; i++){
					vargs[i] = substituteTerm(args[i], maxDept - 1);
				}
				return TBFACTORY.makeAppl(afun, vargs, annos);

			case ATerm.LIST:
				if(maxDept <= 0){
					ATermList emptyListTerm = TBFACTORY.EmptyList;
					return emptyListTerm.insert(EMPTYTERM);
				}

				ATermList tlst = (ATermList) term;

				if(tlst == TBFACTORY.EmptyList) return term;

				int len = tlst.getLength();
				ATerm[] listContent = new ATerm[len];
				for(int i = len - 1; i >= 0; i--){
					listContent[i] = tlst.getFirst();
					tlst = tlst.getNext();
				}

				ATermList lst = TBFACTORY.EmptyList;
				for(int i = 0; i < len; i++){
					lst = lst.insert((substituteTerm(listContent[i], maxDept - 1)));
				}

				// We can ignore annotations, since lists with annotations aren't supported anyway

				return lst;
			default:
				return term;
		}
	}
	
	public void setHighlight(final ProcessInstance processInstance){
		clearTable(subscriptionsTableModel);
		clearTable(noteQueueTableModel);
		clearTable(stateTableModel);
		clearTable(variablesTableModel);
		fillProcessTables(processInstance);
	}
	
    public Map<String, Container> getVisualComponents(){
        HashMap<String, Container> nameContainerHashMap = new HashMap<String, Container>();
        nameContainerHashMap.put("Process Details", this);
    	return nameContainerHashMap;
    }
	
    public String getPreferredPosition(){
		return "TopRight";
	}
    
    public void setHighlight(ToolInstance toolInstance){
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}
    
    public void setHighlightByProcessName(String processName){
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}
    
    public void setHighlightByToolName(String toolName){
    	// Empty, because ProcessDetailView only highlights ProcessInstances.
	}
    
    public String getPluginName(){
		return "Process Detail Panel";
	}
}
