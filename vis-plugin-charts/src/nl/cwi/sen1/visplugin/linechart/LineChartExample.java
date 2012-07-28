package nl.cwi.sen1.visplugin.linechart;

import javax.swing.JFrame;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

/**
 * lineChart Demo/Example class
 * @author Raymond Bergen
 */

public class LineChartExample {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// create visualization
		RTuple fact = buildRTuple();
		
		Factory m_factory = VisualizationFactorySingleton.getFactoryInstance();

        LCVisualizationController controller = new LCVisualizationController();
        LCVisualizationWindow visualization = (LCVisualizationWindow) controller.createWindow();

		visualization.setFactory(m_factory);

		JPanel barPanel = visualization.render(fact);
		showLineChart("Line Chart Visualization", barPanel);
	}

	private static RTuple buildRTuple() {
		RTuple rTuple = createRTuple();
		System.out.println(rTuple.toString());

        return rTuple;
	}

	private static RTuple createRTuple() {
        Factory factory = VisualizationFactorySingleton.getFactoryInstance();
        
        RTuple rTuple = factory.RTupleFromString("rtuple(\"StatementHistogram\",relation([int,int]),set([tuple([int(nat-con(7)),int(nat-con(7))]), tuple([int(nat-con(2)),int(nat-con(2))])]))");
       
		return rTuple;
		
	}
	
	/**
	 * Show a panel on screen.
	 * 
	 * @param panel
	 */
	private static void showLineChart(String windowTitle, JPanel panel) {
		// create and set up the window.
		JFrame frame = new JFrame(windowTitle);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// show chart
		frame.setContentPane(panel);
		frame.pack();
		frame.setVisible(true);
	}
}
