package toolbus.viewer;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Iterator;
import java.util.List;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultCellEditor;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
import javax.swing.border.BevelBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableCellRenderer;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.commandline.CommandLine;
import toolbus.environment.Binding;
import toolbus.environment.Environment;
import toolbus.process.ProcessInstance;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Viewer implements IViewer{
	protected final DebugToolBus debugToolBus;
	
	private final JFrame frame;
	private final JLabel status;
	protected final JButton runButton;
	protected final JButton stopButton;
	protected final JButton stepButton;
	protected final JButton killButton;
	
	protected final JTextField lastExecutedProcessInstanceField;
	protected final JTextField lastExecutedStateElementField;
	
	protected final JTable processesTable;
	private final String[] processesTableHeader;
	protected final JTable stateTable;
	private final String[] stateTableHeader;
	
	private final DefaultTableModel processesTableModel;
	private final DefaultTableModel subscriptionsTableModel;
	private final DefaultTableModel variablesTableModel;
	private final DefaultTableModel noteQueueTableModel;
	private final DefaultTableModel stateTableModel;
	
	private final JScrollPane processesScrollPane;
	
	private volatile int stepHighlightedRow = -1;
	private volatile int breakHighlightedRow = -1;
	
	public Viewer(String[] args){
		super();
		
		debugToolBus = new DebugToolBus(args, this, null);
		
		frame = new JFrame("ToolBus Viewer");
		frame.setSize(800, 600);
		frame.setLayout(new BorderLayout());
		frame.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
		
		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				debugToolBus.doTerminate();
			}
		});
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new GridLayout(2, 2));
		
		TableSelectionListener tableSelectionListener = new TableSelectionListener();

		JPanel processesPanel = new JPanel();
		processesPanel.setLayout(new BorderLayout());
		processesTableHeader = new String[]{"Break", "Process name", "Identifier"};
		processesTableModel = new DefaultTableModel(new Object[0][0], processesTableHeader){
			private static final long serialVersionUID = 6515489257737761296L;
			
			public boolean isCellEditable(int row, int column){
				return (column == 0); // Only the checkbox is editable.
			}
			public void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
				
				if(column == 0){
					int processId = ((Integer) processesTable.getValueAt(row, 2)).intValue();
					
					if(((Boolean) aValue).booleanValue()) debugToolBus.addProcessInstanceBreakPoint(processId);
					else debugToolBus.removeProcessInstanceBreakPoint(processId);
				}
			}
		};
		processesTable = new JTable(processesTableModel){
			private static final long serialVersionUID = -3338875681802391368L;

			public Component prepareRenderer(TableCellRenderer cr, int row, int col){
                Component c = super.prepareRenderer(cr, row, col);
                
                if(row == stepHighlightedRow) c.setBackground(Color.GREEN);
                else if(row == breakHighlightedRow) c.setBackground(Color.YELLOW);
                else c.setBackground(Color.WHITE);
                
                return c;
            }
        };
		TableColumnModel processesTableColumnModel = processesTable.getColumnModel();
		TableColumn breakPointColumn = processesTableColumnModel.getColumn(0);
		breakPointColumn.setCellRenderer(new DefaultTableCellRenderer(){
			private static final long serialVersionUID = 5811556489112969680L;

			public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
				JCheckBox checkBox = new JCheckBox();
		        if(Boolean.TRUE.equals(value)) checkBox.setSelected(true);
		        return checkBox;
		    }
		});
		breakPointColumn.setCellEditor(new DefaultCellEditor(new JCheckBox()));
		breakPointColumn.setMinWidth(40);
		breakPointColumn.setMaxWidth(40);
		TableColumn identifierColumn = processesTableColumnModel.getColumn(2);
		identifierColumn.setMinWidth(60);
		identifierColumn.setMaxWidth(100);
		identifierColumn.setPreferredWidth(60);
		ListSelectionModel processesSelectionModel = processesTable.getSelectionModel();
		processesSelectionModel.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		processesSelectionModel.addListSelectionListener(tableSelectionListener);
		processesScrollPane = new JScrollPane(processesTable);
		processesPanel.add(processesScrollPane, BorderLayout.CENTER);
		frame.add(processesPanel, BorderLayout.WEST);
		
		JPanel subscriptionsPanel = new JPanel();
		subscriptionsPanel.setLayout(new BorderLayout());
		subscriptionsTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Subscriptions"}){
			private static final long serialVersionUID = 2407227292333227911L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		JTable subscriptionsTable = new JTable(subscriptionsTableModel);
		JScrollPane subscriptionsScrollPane = new JScrollPane(subscriptionsTable);
		subscriptionsPanel.add(subscriptionsScrollPane, BorderLayout.CENTER);
		mainPanel.add(subscriptionsPanel);
		
		JPanel statePanel = new JPanel();
		statePanel.setLayout(new BorderLayout());
		stateTableHeader = new String[]{"State"};
		stateTableModel = new DefaultTableModel(new Object[0][0], stateTableHeader){
			private static final long serialVersionUID = 7405647403653515348L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		stateTable = new JTable(stateTableModel);
		ListSelectionModel stateSelectionModel = stateTable.getSelectionModel();
		stateSelectionModel.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		stateSelectionModel.addListSelectionListener(tableSelectionListener);
		JScrollPane stateScrollPane = new JScrollPane(stateTable);
		statePanel.add(stateScrollPane, BorderLayout.CENTER);
		mainPanel.add(statePanel);
		
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
		mainPanel.add(noteQueuePanel);

		JPanel variablesPanel = new JPanel();
		variablesPanel.setLayout(new BorderLayout());
		variablesTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Variable", "Value"}){
			private static final long serialVersionUID = 4345972041423779621L;

			public boolean isCellEditable(int row, int column){
				return false;
			}
		};
		JTable variablesTable = new JTable(variablesTableModel);
		JScrollPane variablesScrollPane = new JScrollPane(variablesTable);
		variablesPanel.add(variablesScrollPane, BorderLayout.CENTER);
		mainPanel.add(variablesPanel);
		
		JPanel controlPanel = new JPanel();
		controlPanel.setLayout(new BorderLayout());
		controlPanel.setBorder(new BevelBorder(BevelBorder.RAISED));
		
		JPanel statusBar = new JPanel();
		statusBar.setLayout(new GridLayout(1, 1));
		status = new JLabel();
		statusBar.add(status);
		controlPanel.add(statusBar, BorderLayout.WEST);
		
		JPanel bottomPanel = new JPanel();
		bottomPanel.setLayout(new BorderLayout());
		
		JPanel lastExecutedAtomPanel = new JPanel();
		lastExecutedAtomPanel.setLayout(new GridLayout(2, 1));
		Box topBox = new Box(BoxLayout.X_AXIS);
		JLabel lastExecutedProcessInstanceLabel = new JLabel("Last executed process instance: ");
		topBox.add(lastExecutedProcessInstanceLabel);
		lastExecutedProcessInstanceField = new JTextField();
		lastExecutedProcessInstanceField.setEditable(false);
		lastExecutedProcessInstanceField.setBackground(Color.WHITE);
		topBox.add(lastExecutedProcessInstanceField);
		lastExecutedAtomPanel.add(topBox);
		Box bottomBox = new Box(BoxLayout.X_AXIS);
		JLabel lastExecutedStateElementLabel = new JLabel("Last executed state element: ");
		bottomBox.add(lastExecutedStateElementLabel);
		lastExecutedStateElementField = new JTextField();
		lastExecutedStateElementField.setEditable(false);
		lastExecutedStateElementField.setBackground(Color.WHITE);
		bottomBox.add(lastExecutedStateElementField);
		lastExecutedAtomPanel.add(bottomBox);
		bottomPanel.add(lastExecutedAtomPanel, BorderLayout.NORTH);
		
		JPanel controlBar = new JPanel();
		controlBar.setLayout(new FlowLayout());
		ButtonActionListener buttonActionListener = new ButtonActionListener();
		runButton = new JButton("Run");
		runButton.addActionListener(buttonActionListener);
		controlBar.add(runButton);
		stopButton = new JButton("Stop");
		stopButton.addActionListener(buttonActionListener);
		controlBar.add(stopButton);
		stepButton = new JButton("Step");
		stepButton.addActionListener(buttonActionListener);
		controlBar.add(stepButton);
		killButton = new JButton("Terminate");
		killButton.addActionListener(buttonActionListener);
		controlBar.add(killButton);
		controlPanel.add(controlBar, BorderLayout.EAST);
		bottomPanel.add(controlPanel, BorderLayout.CENTER);
		
		frame.add(bottomPanel, BorderLayout.SOUTH);
		
		frame.add(mainPanel, BorderLayout.CENTER);
	}
	
	public DebugToolBus getDebugToolBus(){
		return debugToolBus;
	}
	
	public void toolbusStarting(){
		frame.setVisible(true);
	}
	
	public void toolbusTerminating(){
		frame.dispose();
	}
	
	// Update the state of the given process after the execution of the step.
	public void stepExecuted(final ProcessInstance processInstance, final StateElement executedStateElement, final ProcessInstance[] partners){
		if(executedStateElement.getPosInfo() == null){
			// If the posInfo was 'null', the stateElement isn't related directly related to anything in the ToolBus script (it will be an atom that was inserted during the creation of the statemachine, by the parser).
			// In this case do another step.
			debugToolBus.doStep();
			return;
		}
		
		//if(partners.length > 0) System.out.println(processInstance+" -> "+partners[0]);
		
		//System.out.println(executedStateElement+" - "+executedStateElement.getPosInfo());
		
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				lastExecutedProcessInstanceField.setText(processInstance.getProcessName()+":"+processInstance.getProcessId());
				lastExecutedProcessInstanceField.setCaretPosition(0);
				lastExecutedStateElementField.setText(executedStateElement.toString());
				lastExecutedStateElementField.setCaretPosition(0);
				
				stepHighlightedRow = -1;
				for(int row = processesTableModel.getRowCount() - 1; row >= 0; row--){
					int processId = ((Integer) processesTableModel.getValueAt(row, 2)).intValue();
					if(processId == processInstance.getProcessId()){
						stepHighlightedRow = row;
						processesTable.scrollRectToVisible(processesTable.getCellRect(row, 1, true));
						ListSelectionModel selectionModel = processesTable.getSelectionModel();
						selectionModel.clearSelection();
						selectionModel.setSelectionInterval(row, row);
						break;
					}
				}
				processesTable.repaint();
			}
		});
	}
	
	public void updateState(int state){
		switch(state){
			case IViewerConstants.UNKNOWN_STATE:
				status.setText("Unkown");
				break;
			case IViewerConstants.STOPPING_STATE:
				status.setText("Stopping");
				break;
			case IViewerConstants.WAITING_STATE:
				status.setText("Waiting");
				break;
			case IViewerConstants.READY_STATE:
				status.setText("Ready");
				break;
			case IViewerConstants.RUNNING_STATE:
				status.setText("Running");
				break;
			case IViewerConstants.STEPPING_STATE:
				status.setText("Stepping");
				break;
			default:
				System.err.println("Unknown state: "+state);
		}
	}
	
	public void processInstanceStarted(final ProcessInstance processInstance){
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				processesTableModel.insertRow(0, new Object[]{Boolean.FALSE, processInstance.getProcessName(), Integer.valueOf(processInstance.getProcessId())});
			}
		});
	}
	
	public void processInstanceTerminated(final ProcessInstance processInstance){
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				for(int i = processesTableModel.getRowCount() - 1; i >= 0; i--){
					if(new Integer(processInstance.getProcessId()).equals(processesTableModel.getValueAt(i, 2))){
						debugToolBus.removeProcessInstanceBreakPoint(processInstance.getProcessId()); // Remove breakpoints (if present).
						processesTableModel.removeRow(i);
					}
				}
			}
		});
	}
	
	public void processBreakPointHit(ProcessInstance processInstance){
		debugToolBus.doStop();
		final int processId = processInstance.getProcessId();
		SwingUtilities.invokeLater(new Runnable(){
			public void run(){
				breakHighlightedRow = -1;
				for(int row = processesTableModel.getRowCount() - 1; row >= 0; row--){
					int pid = ((Integer) processesTableModel.getValueAt(row, 2)).intValue();
					if(pid == processId){
						breakHighlightedRow = row;
						processesTable.scrollRectToVisible(processesTable.getCellRect(row, 1, true));
						ListSelectionModel selectionModel = processesTable.getSelectionModel();
						selectionModel.clearSelection();
						selectionModel.setSelectionInterval(row, row);
						break;
					}
				}
				processesTable.repaint();
			}
		});
	}
	
	public void stateElementBreakPointHit(StateElement stateElement){
		// Ignore, this viewer doesn't support breakpoints on state elements (yet).
	}
	
	public void sourceBreakPointHit(StateElement stateElement){
		// Ignore, this viewer doesn't support breakpoints on source code coordinates (yet).
	}
	
	private void clearSubscriptionsTable(){
		for(int i = subscriptionsTableModel.getRowCount() - 1; i >= 0; i--){
			subscriptionsTableModel.removeRow(i);
		}
	}
	
	private void clearNoteQueueTable(){
		for(int i = noteQueueTableModel.getRowCount() - 1; i >= 0; i--){
			noteQueueTableModel.removeRow(i);
		}
	}
	
	private void clearStateTable(){
		for(int i = stateTableModel.getRowCount() - 1; i >= 0; i--){
			stateTableModel.removeRow(i);
		}
	}
	
	private void clearVariablesTable(){
		for(int i = variablesTableModel.getRowCount() - 1; i >= 0; i--){
			variablesTableModel.removeRow(i);
		}
	}
	
	private void fillProcessTables(ProcessInstance processInstance){
		clearSubscriptionsTable();
		
		List<ATerm> subscriptions = processInstance.getSubscriptions();
		Iterator<ATerm> subscriptionIterator = subscriptions.iterator();
		while(subscriptionIterator.hasNext()){
			String subscription = getSubscriptionSignature(subscriptionIterator.next());
			subscriptionsTableModel.addRow(new Object[]{subscription});
		}
		
		
		clearNoteQueueTable();
		
		List<ATerm> noteQueue = processInstance.getNoteQueue();
		Iterator<ATerm> noteQueueIterator = noteQueue.iterator();
		while(noteQueueIterator.hasNext()){
			String note = getNoteSignature(noteQueueIterator.next());
			noteQueueTableModel.addRow(new Object[]{note});
		}
		
		
		clearStateTable();
		
		List<StateElement> stateElements = processInstance.getCurrentState().getElementsAsList();
		Iterator<StateElement> stateElementIterator = stateElements.iterator();
		while(stateElementIterator.hasNext()){
			StateElement stateElement = stateElementIterator.next();
			stateTableModel.addRow(new Object[]{stateElement});
		}
	}
	
	private void fillVariables(StateElement stateElement){
		// Insert the new data in case the state element is an atom (and thus has an environment).
		if(stateElement != null && stateElement instanceof Atom){
			Atom atom = (Atom) stateElement;
			Environment environment = atom.getEnv();
			List<Binding> bindings = environment.getBindingsAsList();
			Iterator<Binding> bindingIterator = bindings.iterator();
			while(bindingIterator.hasNext()){
				Binding binding = bindingIterator.next();
				String var = binding.getVar().toString();
				String val = getVariableSignature(binding.getVal());
				variablesTableModel.addRow(new Object[]{var, val});
			}
		}
	}
	
	private class TableSelectionListener implements ListSelectionListener{
		
		public TableSelectionListener(){
			super();
		}
		
		public void valueChanged(ListSelectionEvent e){
			if(e.getSource() == processesTable.getSelectionModel() && !e.getValueIsAdjusting()){
				clearSubscriptionsTable();
				clearNoteQueueTable();
				clearStateTable();
				clearVariablesTable();
				
				int row = processesTable.getSelectedRow();
				if(row != -1){
					int processId = ((Integer) processesTableModel.getValueAt(row, 2)).intValue();
					
					List<ProcessInstance> processInstances = debugToolBus.getProcesses();
					Iterator<ProcessInstance> processInstancesIterator = processInstances.iterator();
					while(processInstancesIterator.hasNext()){
						ProcessInstance pi = processInstancesIterator.next();
						if(pi.getProcessId() == processId){
							fillProcessTables(pi);
							break;
						}
					}
				}
            }else if(e.getSource() == stateTable.getSelectionModel() && !e.getValueIsAdjusting()){
            	clearVariablesTable();
            	
            	int row = stateTable.getSelectedRow();
            	if(row != -1){
	            	StateElement stateElement = (StateElement) stateTableModel.getValueAt(row, 0);
	            	fillVariables(stateElement);
            	}
            }else{
            	// This never happens, unless someone messed up the code.
            }
		}
	}
	
	private void clearProcessTableModifications(){
		lastExecutedProcessInstanceField.setText("");
		lastExecutedStateElementField.setText("");
		stepHighlightedRow = -1;
		breakHighlightedRow = -1;
		ListSelectionModel selectionModel = processesTable.getSelectionModel();
		selectionModel.clearSelection();
		processesTable.repaint();
	}
	
	private class ButtonActionListener implements ActionListener{
		
		public ButtonActionListener(){
			super();
		}

		public void actionPerformed(ActionEvent e){
			Object source = e.getSource();
			if(source == runButton){
				clearProcessTableModifications();
				debugToolBus.doRun();
			}else if(source == stopButton){
				clearProcessTableModifications();
				debugToolBus.doStop();
			}else if(source == stepButton){
				clearProcessTableModifications();
				debugToolBus.doStep();
			}else if(source == killButton){
				debugToolBus.doTerminate();
				frame.dispose();
			}else{
				// This never happens, unless someone messed up the code.
			}
		}
	}
	
	private final static TBTermFactory tbFactory = TBTermFactory.getInstance();
	private final static ATerm emptyTerm = tbFactory.makeAppl(tbFactory.makeAFun("...", 0, false));
	
	private static ATerm substituteTerm(ATerm term, int maxDept){
		int termType = term.getType();
		switch(termType){
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) term;
				if(apt.getArity() == 0) return term;
				
				AFun afun = apt.getAFun();
				ATerm args[] = apt.getArgumentArray();
				ATermList annos = tbFactory.EmptyList; // Strip the annotations.
				
				if(maxDept <= 0) return tbFactory.makeAppl(tbFactory.makeAFun(afun.getName(), 1, false), new ATerm[]{emptyTerm}, annos);
				
				int nargs = args.length;
				ATerm vargs[] = new ATerm[nargs];
				for(int i = 0; i < nargs; i++){
					vargs[i] = substituteTerm(args[i], maxDept - 1);
				}
				return tbFactory.makeAppl(afun, vargs, annos);
				
			case ATerm.LIST:
				if(maxDept <= 0){
					ATermList emptyListTerm = tbFactory.EmptyList;
					return emptyListTerm.insert(emptyTerm);
				}
				
				ATermList tlst = (ATermList) term;
				
				if(tlst == tbFactory.EmptyList) return term;
				
				int len = tlst.getLength();
				ATerm[] listContent = new ATerm[len];
				for(int i = len - 1; i >= 0; i--){
					listContent[i] = tlst.getFirst();
					tlst = tlst.getNext();
				}
				
				ATermList lst = tbFactory.EmptyList;
				for(int i = 0; i < len; i++){
					lst = lst.insert((substituteTerm(listContent[i], maxDept - 1)));
				}
				
				// We can ignore annotations, since lists with annotations aren't supported anyway
				
				return lst;
			default:
				return term;
		}
	}
	
	private static String getSubscriptionSignature(ATerm term){
		ATerm result = substituteTerm(term, 3);
		
		return result.toString();
	}
	
	private static String getNoteSignature(ATerm term){
		ATerm result = substituteTerm(term, 3);
		
		return result.toString();
	}
	
	private static String getVariableSignature(ATerm term){
		ATerm result = substituteTerm(term, 2);
		
		return result.toString();
	}
	
	public static void main(String[] args){
		Viewer viewer = new Viewer(args);
		DebugToolBus debugToolBus = viewer.getDebugToolBus();
		debugToolBus.setBreakWhileStepping(false);
		
		CommandLine.createCommandLine(debugToolBus, System.in);
		
		debugToolBus.doStop(); // The initial state is stopped.
		
		try{
			if(debugToolBus.parsecup()){
				debugToolBus.execute();
			}else{
				System.err.println("Failed to parse");
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
