package nl.cwi.sen1.visplugin.barchart;

import javax.swing.JFrame;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

/**
 * BarChart Demo/Example class
 * Original code : PieChart plugin ( A. Belgraver, R. van Remortel )
 * @author Srinivasan Tharmarajah

 */

public class BarChartExample {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// create visualization
		RTuple fact = buildRTuple();
		
		Factory m_factory = VisualizationFactorySingleton.getFactoryInstance();

        BCVisualizationController controller = new BCVisualizationController();
        BCVisualizationWindow visualization = (BCVisualizationWindow) controller.createWindow();

		visualization.setFactory(m_factory);

		JPanel barPanel = visualization.render(fact);
		showBarChart("Bar Chart Visualization", barPanel);
	}

	private static RTuple buildRTuple() {
		RTuple rTuple = createRTuple();
		System.out.println(rTuple.toString());

        return rTuple;
	}

	private static RTuple createRTuple() {
        Factory factory = VisualizationFactorySingleton.getFactoryInstance();
        RTuple rTuple = factory.RTupleFromString("rtuple(\"StatementHistogram\",relation([str,int]),set([tuple([str(\"Assignment\"),int(nat-con(7))]), tuple([str(\"Assignment2\"),int(nat-con(6))]), tuple([str(\"Assignment3\"),int(nat-con(5))]), tuple([str(\"Assignment4\"),int(nat-con(2))])]))");
        
		return rTuple;
		
	}
	
	/**
	 * Show a panel on screen.
	 * 
	 * @param panel
	 */
	private static void showBarChart(String windowTitle, JPanel panel) {
		// create and set up the window.
		JFrame frame = new JFrame(windowTitle);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// show chart
		frame.setContentPane(panel);
		frame.pack();
		frame.setVisible(true);
	}
}
