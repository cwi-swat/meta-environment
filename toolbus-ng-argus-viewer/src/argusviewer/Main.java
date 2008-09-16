package argusviewer;

import java.util.ArrayList;

import argusviewer.gui.ArgusViewerGUI;
import argusviewer.toolbus.DataComm;
import argusviewer.view.IView;
import argusviewer.view.architectureview.ArchitecturePlugin;
import argusviewer.view.consoleview.ConsoleViewPanel;
import argusviewer.view.msc.MSCPlugin;
import argusviewer.view.processdetailpanel.ProcessDetailPanel;
import argusviewer.view.processlist.ProcessListView;
import argusviewer.view.sourcefile.SourceFileViewController;
import argusviewer.view.toollist.ToolListPlugin;


/**
 * Application entry point class for the ArgusViewer.
 * 
 * @author J. van den Bos
 * @author M. van Beest
 */
public class Main {
	/**
	 * Application entry point method for the ArgusViewer.
	 * 
	 * @param args arguments to pass to the ToolBus this viewer connects to.
	 * @see argusviewer.toolbus.DataComm#DataComm(String[])
	 * @see toolbus.viewer.DebugToolBus#DebugToolBus(String[], toolbus.viewer.IViewer, toolbus.viewer.IPerformanceMonitor)
	 */
	public static void main(final String[] args) throws Exception{
		final DataComm dataComm = new DataComm(args);
		
		javax.swing.SwingUtilities.invokeAndWait(new Runnable() {
			public void run() {
				// The ConsoleViewPanel must be initialized before the DataComm
				// is created, because the error and output streams are cached
				// in the ToolBus and we want them redirected to the ConsoleView.
				ArrayList<IView> views = new ArrayList<IView>();
				views.add(new ConsoleViewPanel());			
				
				// Views that have the same preferred position get ordered
				// back to front in the order they are added here.				
				views.add(new ArchitecturePlugin(dataComm));
				views.add(new ProcessDetailPanel(dataComm));
				views.add(new MSCPlugin(dataComm));
				views.add(new ProcessListView(dataComm));
				views.add(new SourceFileViewController(dataComm));
				views.add(new ToolListPlugin(dataComm));
				
				new ArgusViewerGUI(dataComm, views.toArray(new IView[views.size()]));
			}
		});
		
		dataComm.startToolBus();
	}

}
