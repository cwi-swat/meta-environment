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

import javax.swing.DefaultCellEditor;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
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
import toolbus.environment.Binding;
import toolbus.environment.Environment;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

public class Viewer{
	protected volatile DebugToolBus debugToolBus;
	
	private final JFrame frame;
	private final JLabel status;
	protected final JButton runButton;
	protected final JButton stopButton;
	protected final JButton stepButton;
	protected final JButton killButton;
	
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
	
	private volatile int highlightedRow = -1;
	
	public Viewer(){
		super();
		
		frame = new JFrame("ToolBus Viewer");
		frame.setSize(800, 600);
		frame.setLayout(new BorderLayout());
		frame.setDefaultCloseOperation(WindowConstants.DO_NOTHING_ON_CLOSE);
		
		frame.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				debugToolBus.doTerminate();
				stop();
			}
		});
		
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new GridLayout(2, 2));
		
		TableSelectionListener tableSelectionListener = new TableSelectionListener();

		JPanel processesPanel = new JPanel();
		processesPanel.setLayout(new BorderLayout());
		processesTableHeader = new String[]{"Break", "Process name", "Identifier"};
		processesTableModel = new DefaultTableModel(new Object[0][0], processesTableHeader){
			public synchronized Object getValueAt(int row, int column){
				return super.getValueAt(row, column);
			}
			public synchronized void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
			}
		};
		processesTable = new JTable(processesTableModel){
			public Component prepareRenderer(TableCellRenderer cr, int row, int col){
                Component c = super.prepareRenderer(cr, row, col);
                if(row == highlightedRow) c.setBackground(Color.GREEN);
                else c.setBackground(Color.WHITE);
                return c;
            }
        };
		TableColumnModel processesTableColumnModel = processesTable.getColumnModel();
		TableColumn breakPointColumn = processesTableColumnModel.getColumn(0);
		breakPointColumn.setCellRenderer(new DefaultTableCellRenderer(){
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
		processesPanel.add(processesTable, BorderLayout.CENTER);
		processesScrollPane = new JScrollPane(processesTable);
		frame.add(processesScrollPane, BorderLayout.WEST);
		
		JPanel subscriptionsPanel = new JPanel();
		subscriptionsPanel.setLayout(new BorderLayout());
		subscriptionsTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Subscriptions"}){
			public synchronized Object getValueAt(int row, int column){
				return super.getValueAt(row, column);
			}
			public synchronized void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
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
			public synchronized Object getValueAt(int row, int column){
				return super.getValueAt(row, column);
			}
			public synchronized void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
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
			public synchronized Object getValueAt(int row, int column){
				return super.getValueAt(row, column);
			}
			public synchronized void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
			}
		};
		JTable noteQueueTable = new JTable(noteQueueTableModel);
		JScrollPane noteQueueScrollPane = new JScrollPane(noteQueueTable);
		noteQueuePanel.add(noteQueueScrollPane, BorderLayout.CENTER);
		mainPanel.add(noteQueuePanel);

		JPanel variablesPanel = new JPanel();
		variablesPanel.setLayout(new BorderLayout());
		variablesTableModel = new DefaultTableModel(new Object[0][0], new String[]{"Variable", "Value"}){
			public synchronized Object getValueAt(int row, int column){
				return super.getValueAt(row, column);
			}
			public synchronized void setValueAt(Object aValue, int row, int column){
				super.setValueAt(aValue, row, column);
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
		
		frame.add(controlPanel, BorderLayout.SOUTH);
		
		frame.add(mainPanel, BorderLayout.CENTER);
	}
	
	public void setToolBus(DebugToolBus debugToolBus){
		this.debugToolBus = debugToolBus;
	}
	
	public void start(){
		gather(); // Gather the intial data.
		
		frame.setVisible(true);
	}
	
	public void stop(){
		frame.dispose();
	}

	// Get all necessary data.
	private void gather(){
		clearProcessesTable();
		
		List<ProcessInstance> processInstances = debugToolBus.getProcesses();
		Iterator<ProcessInstance> processInstancesIterator = processInstances.iterator();
		while(processInstancesIterator.hasNext()){
			ProcessInstance pi = processInstancesIterator.next();
			processesTableModel.addRow(new Object[]{Boolean.FALSE, pi.getProcessName(), Integer.valueOf(pi.getProcessId())});
		}
	}
	
	// Update the state of the given process.
	public void update(ProcessInstance processInstance){
		highlightedRow = -1;
		for(int row = processesTableModel.getRowCount() - 1; row >= 0; row--){
			int processId = ((Integer) processesTableModel.getValueAt(row, 2)).intValue();
			if(processId == processInstance.getProcessId()){
				highlightedRow = row;
				final int hlr = row;
				SwingUtilities.invokeLater(new Runnable(){
					public void run(){
						processesTable.scrollRectToVisible(processesTable.getCellRect(hlr, 1, true));
						processesTable.getSelectionModel().setSelectionInterval(hlr, hlr);
					}
				});
				break;
			}
		}
	}
	
	private void clearProcessesTable(){
		for(int i = processesTableModel.getRowCount() - 1; i >= 0; i--){
			processesTableModel.removeRow(i);
		}
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
			String subscription = getTermSignature(subscriptionIterator.next());
			subscriptionsTableModel.addRow(new Object[]{subscription});
		}
		
		
		clearNoteQueueTable();
		
		List<ATerm> noteQueue = processInstance.getNoteQueue();
		Iterator<ATerm> noteQueueIterator = noteQueue.iterator();
		while(noteQueueIterator.hasNext()){
			String note = getTermSignature(noteQueueIterator.next());
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
		clearVariablesTable();
		
		// Insert the new data in case the state element is an atom (and thus has an environment).
		if(stateElement != null && stateElement instanceof Atom){
			Atom atom = (Atom) stateElement;
			Environment environment = atom.getEnv();
			List<Binding> bindings = environment.getBindingsAsList();
			Iterator<Binding> bindingIterator = bindings.iterator();
			while(bindingIterator.hasNext()){
				Binding binding = bindingIterator.next();
				String var = getTermSignature(binding.getVar());
				String val = getTermSignature(binding.getVal());
				variablesTableModel.addRow(new Object[]{var, val});
			}
		}
	}
	
	public void updateState(int state){
		switch(state){
			case DebugToolBus.UNKNOWN_STATE:
				status.setText("Unkown");
				break;
			case DebugToolBus.STOPPING_STATE:
				status.setText("Stopping");
				break;
			case DebugToolBus.WAITING_STATE:
				status.setText("Waiting");
				break;
			case DebugToolBus.READY_STATE:
				status.setText("Ready");
				break;
			case DebugToolBus.RUNNING_STATE:
				status.setText("Running");
				break;
			case DebugToolBus.STEPPING_STATE:
				status.setText("Stepping");
				break;
			default:
				System.err.println("Unknown state: "+state);
		}
	}
	
	private class TableSelectionListener implements ListSelectionListener{
		
		public TableSelectionListener(){
			super();
		}
		
		public void valueChanged(ListSelectionEvent e){
			if(e.getSource() == processesTable.getSelectionModel() && !e.getValueIsAdjusting()){
				int row = processesTable.getSelectedRow();
				if(row != -1){
					int processId = ((Integer) processesTableModel.getValueAt(row, 2)).intValue();
					
					List<ProcessInstance> processInstances = debugToolBus.getProcesses();
					Iterator<ProcessInstance> processInstancesIterator = processInstances.iterator();
					while(processInstancesIterator.hasNext()){
						ProcessInstance pi = processInstancesIterator.next();
						if(pi.getProcessId() == processId){
							clearSubscriptionsTable();
							clearNoteQueueTable();
							clearStateTable();
							clearVariablesTable();
							
							fillProcessTables(pi);
							break;
						}
					}
				}
            }else if(e.getSource() == stateTable.getSelectionModel() && !e.getValueIsAdjusting()){
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
	
	private class ButtonActionListener implements ActionListener{
		
		public ButtonActionListener(){
			super();
		}

		public void actionPerformed(ActionEvent e){
			Object source = e.getSource();
			if(source == runButton){
				debugToolBus.doRun();
			}else if(source == stopButton){
				debugToolBus.doStop();
				gather();
			}else if(source == stepButton){
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
	private final static ATerm emptyTerm = tbFactory.makeAppl(tbFactory.makeAFun("...", 0, true));
	
	private static String getTermSignature(ATerm term){
		
		
		
		// TODO
		
		return term.toString(); // Temp.
	}
	
	public static void main(String[] args){
		Viewer viewer = new Viewer();

		DebugToolBus debugToolBus = new DebugToolBus(args, viewer);
		viewer.setToolBus(debugToolBus);
		
		debugToolBus.doStop(); // The initial state is stopped.
		
//		String tbScript = "/ufs/lankamp/metaNG/installed/share/asfsdf-meta/start-meta-studio.tb";
		
		try{
			if(debugToolBus.parsecup()){
				viewer.start(); // Delay showing the viewer till the ToolBus is started.
				
				debugToolBus.execute();
			}else{
				System.err.println("Failed to parse");
			}
		}catch(Exception e){
			e.printStackTrace();
			System.exit(0);
		}
	}
}
