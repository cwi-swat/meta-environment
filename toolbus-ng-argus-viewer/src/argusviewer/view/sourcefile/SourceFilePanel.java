package argusviewer.view.sourcefile;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JViewport;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableColumn;

import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;



/**
 * Classname SourceFilePanel
 * Represents a panel, contains a JTabel to view the source code of the processes
 * 
 * revision 13/2/2008
 *  
 * @author Qais & Bas
 * @author M. van Beest
 *
 */
public class SourceFilePanel extends JPanel implements TableModelListener, IView {
	private static final long serialVersionUID = 5903220341851733896L;
	
	private JTable m_sourceCode; // is used to view the source code
	private SourceFileTableModel m_sourceModel; // table model used to put objects in JTable  
	private String m_source; // source code viewed on the current panel 
	private String m_scriptName; // the script name
	private static final Color SELECTED_ROW_COLOR = new Color(255, 255, 215); // the color of a row if selected by user
	private static final Color BREAKPOINT_ROW_COLOR = new Color(255, 112, 112); // the color of a row if a breakpoint is reached
	private static final Color STEP_ROW_COLOR = new Color(126, 192, 238); // the color of a row during steps

	private static final int FIRST_COLUMN_INDEX = 0;	
	private static final int FIRST_COLUMN_WIDTH = 20;
	private static final int SECOND_COLUMN_INDEX = 1;
	private static final int SECOND_COLUMN_WIDTH = 50;
	
	private DataComm m_dataComm;

	/**
	 * Constructs a Panel with a line-number, breakpoint, source-text
	 * 
	 * @param dataComm the datacomm object for interaction with the ToolBus
	 * @param scriptName the name of the script that is used by the toolbus
	 * @param source the source of an toolbus file
	 */
	public SourceFilePanel(DataComm dataComm, String scriptName, String source) {
		m_dataComm = dataComm;
		this.setLayout(new BorderLayout());
		m_scriptName = scriptName;
		m_source = source;
		m_sourceModel = new SourceFileTableModel(m_source);
		m_sourceCode = new JTable(m_sourceModel);
		m_sourceCode.setSelectionBackground(SELECTED_ROW_COLOR);
		m_sourceCode.setSelectionForeground(Color.BLACK);
		m_sourceCode.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		// to set the background color back to default
		m_sourceCode.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if (e.getClickCount() == MouseEvent.BUTTON1) {
					m_sourceCode.setSelectionBackground(SELECTED_ROW_COLOR);         
			    }
			}
		} 
		);
		
		m_sourceCode.getModel().addTableModelListener(this);
		m_sourceCode.setShowGrid(false);
		m_sourceCode.setColumnSelectionAllowed(false);
		m_sourceCode.setRowSelectionAllowed(true);
		
		m_sourceCode.getColumnModel().getColumn(0).setCellRenderer(new CheckBoxCellRenderer());
		m_sourceCode.getColumnModel().getColumn(0).setCellEditor(new CheckBoxCellRenderer());	
	
	    TableColumn firstColumn = m_sourceCode.getColumnModel().getColumn(FIRST_COLUMN_INDEX);
	    firstColumn.setMaxWidth(FIRST_COLUMN_WIDTH);
	    
	    TableColumn secondColumn = m_sourceCode.getColumnModel().getColumn(SECOND_COLUMN_INDEX);
	    DefaultTableCellRenderer tcrColumn = new DefaultTableCellRenderer();
	    tcrColumn.setHorizontalAlignment(SwingConstants.LEFT);
	    secondColumn.setCellRenderer(tcrColumn);
	    secondColumn.setMaxWidth(SECOND_COLUMN_WIDTH);
	    
	    JScrollPane sourceScrollPane = new JScrollPane(m_sourceCode);
	    sourceScrollPane.getViewport().setBackground(Color.WHITE);
	    this.add(sourceScrollPane, BorderLayout.CENTER);
		setVisible(true);
	}
	
	/**
	 * @param tableModelEvent change-events from table model 
	 * handles the breakpoint-status changes 
	 * 
	 */
	public void tableChanged(TableModelEvent tableModelEvent) {
		int row = tableModelEvent.getFirstRow();
		boolean isChecked = m_sourceModel.getBreakPoint(row);
		if (isChecked) {
			m_dataComm.getBreakPointSync().addBreakpoint(m_scriptName, row);				
		} else {
			m_dataComm.getBreakPointSync().removeBreakpoint(m_scriptName, row);	
		}
	}		
	
	
    /**
     * add a breakpoint to a line number of a code
     * @param lineNumber line number of a breakpoint 
     */
    public void addBreakPoint(int lineNumber) {
    	boolean isSet = m_sourceModel.getBreakPoint(lineNumber);
    	boolean isChecked = true;
    	if (!isSet) {
    		m_sourceModel.setBreakPoint(isChecked, lineNumber);
    	}
	}


    /**
     *  remove a breakpoint to a line number of a code
     * @param lineNumber line number of a breakpoint
     */
    public void removeBreakPoint(int lineNumber) {
    	boolean isSet = m_sourceModel.getBreakPoint(lineNumber);
    	boolean isChecked = false;
    	if (isSet) {
    		m_sourceModel.setBreakPoint(isChecked, lineNumber);
    		m_sourceCode.removeRowSelectionInterval(lineNumber, lineNumber);
    	}
	}
    
    /**
     * Gets the breakpoint on the given line number
     * @param lineNumber the lineNumber of the script
     * @return break point status
     */
    public boolean getBreakPointStatus(int lineNumber) {
    	boolean result = false;
    	int lineNumbers = m_sourceModel.getLineNumbers();
    	if ((lineNumber >= 0)
    		&& (lineNumber < lineNumbers)) {
    		result = m_sourceModel.getBreakPoint(lineNumber);
    	}
    	return result;
    }
    
    /**
     * Sets highlight for an executed step
     * 
     * @param startLine start position of the line in the script
     * @param endLine end position of the line in the script
     */
    public void setStepLineSelection(int startLine, int endLine) {
    	setLineSelectionHighlight(startLine, endLine, STEP_ROW_COLOR);
	}

    /**
     * Sets highlight for a reached breakpoint
     * 
     * @param startLine start position of the line in the script
     * @param endLine end position of the line in the script
     */
    public void setBreakpointLineSelection(int startLine, int endLine) {
    	setLineSelectionHighlight(startLine, endLine, BREAKPOINT_ROW_COLOR);
	}

	/**
	 * Sets a specified highlight on a specified location in the script.
	 * 
	 * @param startLine the line to start the highlight on
	 * @param endLine the line to end the highlight
	 * @param backgroundColor the background color to use for the highlight
	 */
	private void setLineSelectionHighlight(int startLine, int endLine, Color backgroundColor) {
		int lineNumbers = m_sourceModel.getLineNumbers();
    	if ((startLine >= 0)
    		&& (endLine < lineNumbers)
    		&& (startLine <= endLine)) {
   			m_sourceCode.setSelectionBackground(backgroundColor);
    		m_sourceCode.addRowSelectionInterval(startLine, endLine);
    	}
	}

    /**
     * removes highlight
     * @param startLine start position of the line in the script
     * @param endLine end position of the line in the script
     * 
     */
    public void removeLineSelection(int startLine, int endLine) {
    	m_sourceCode.removeRowSelectionInterval(startLine, endLine);
	}
	
    /**
     * Remove all line selections in the current file.
     */
    public void removeAllLineSelection() {
    	int scriptLineNumbers = m_sourceModel.getLineNumbers() - 1;
    	m_sourceCode.removeRowSelectionInterval(0, scriptLineNumbers);
	}    
    
    /**
     * scrolls to selected line number 
     * @param lineNumber the line number to scroll to
     * @param toTop display on the top row 
     * @return true if .. , false if 
     */
    public boolean scrollToLine(int lineNumber, boolean toTop) {
    	int lineNumbers = m_sourceModel.getLineNumbers();
    	
        if ((lineNumber >= 0) 
        		&& (lineNumber < lineNumbers)) {        
        	int viewColumnIndex = 0;
        	
        	Rectangle rect = m_sourceCode.getCellRect(lineNumber, viewColumnIndex, true);
        	
        	JViewport viewport = (JViewport) m_sourceCode.getParent();

        	if (toTop) {
	        	Rectangle lastRect = m_sourceCode.getCellRect(lineNumbers - 1, viewColumnIndex, true);
	        	viewport.scrollRectToVisible(lastRect);
        	}
        	
        	Point pt = viewport.getViewPosition();
        	rect.setLocation(rect.x - pt.x, rect.y - pt.y);   
        	
        	// Scroll the area into view
        	
        	viewport.scrollRectToVisible(rect);
        	
        	m_sourceCode.repaint();
        	return true;
        }
        return false;
    }

    /**
     *  just for testing
     *  @return JTabel m_sourceCode of this panel 
     */
    public JTable getJTable() {
    	return m_sourceCode;
	}

	/**
	 * Gets the preferred position in the window
	 * @return the string position
	 */
    public String getPreferredPosition() {
		return "TopRight";
	}

	/**
	 * Gets the name of the plugin
	 * @return the name of this plugin
	 */
	public String getPluginName() {
		return m_scriptName;
	}

	/**
	 * {@inheritDoc}
	 */
	public Map<String, Container> getVisualComponents() {		
		return null;
	}
}

