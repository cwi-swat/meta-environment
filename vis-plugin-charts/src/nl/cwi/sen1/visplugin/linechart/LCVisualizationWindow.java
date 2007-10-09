package nl.cwi.sen1.visplugin.linechart;

import java.awt.Color;

import javax.swing.JLabel;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.idcon.IdCon;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

/**
 * LineChart Plugin VisualisationWindow. Shows a line chart.
 * Original code : PieChart plugin ( A. Belgraver, R. van Remortel )
 * @author Raymond Bergen
 */
public class LCVisualizationWindow extends VisualizationPluginWindow {

    /**
     * Render the RTuple in a Line Chart.
     * 
     * @param fact
     *            RTuple with the information
     * @return JPanel holding the bar chart
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Raymond Bergen
     * @date 07-3-2007
     */
    public JPanel render(RTuple fact) {
        // Check if the fact is a supported Rtype.
        if (!isTypeSupported(fact)) {
            // for not supported type show an error message.
            JPanel jp = new JPanel();
            jp.add(new JLabel("Not a supported type"+fact.getRtype().toString()));
            return jp;
        }

        // Create and return the piechart.
        String graphTitle = "LineChart";
        XYSeriesCollection dataset = convertRTupleToDataset(fact);
        JFreeChart chart = createLineChart(graphTitle, dataset);

        return new ChartPanel(chart,true,false,true,true,true);
    }

    /**
     * Set a new Factory object, for testing purposes.
     * 
     * @param factory
     * Factory to use
     * @author A. Belgraver
     * @date 07-3-2007
     */
    public void setFactory(Factory factory) {
        m_factory = factory;
    }

    /**
     * Check if a given RType is supported by this visualisation.
     * 
     * @param fact
     *            The facts for which to verify if the type is supported
     * @return True if it itype is supported
     * @author Raymond Bergen
     * @date 12-03-2007
     */
    public boolean isTypeSupported(RTuple fact) {
        boolean match = isRelIntInt(fact);

        return match;
    }


    private boolean isRelIntInt(RTuple fact) {
        RType rType = m_factory.RTypeFromString("relation([int,int])");
        boolean match = rType.equals(fact.getRtype());

        return match;
    }
    /**
     * Get the name of the RTuple.
     * 
     * @param fact
     *            RTuple holding information
     * @return String holding the name of the tuple
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G.
     */
    public String getRTupleName(RTuple fact) {
        IdCon idCon = (IdCon) fact.getVariable();
        return idCon.getString();
    }

    /**
     * Create the line chart.
     * 
     * @param title
     *            Name to display on screen
     * @param dataset
     *            Dataset to show
     * @return a JFreeChart chart
     * @author Raymond Bergen
     * @date 12-03-2007
     */
private JFreeChart createLineChart(String title, XYSeriesCollection dataset) {
    // create the chart...
	 final JFreeChart chart = ChartFactory.createXYLineChart(
	            title,      // chart title
	            "X",                      // x axis label
	            "Y",                      // y axis label
	            dataset,                  // data
	            PlotOrientation.VERTICAL,
	            true,                     // include legend
	            true,                     // tooltips
	            false                     // urls
	        );

    // set the background color for the chart...
    chart.setBackgroundPaint(Color.white);

    return chart;
        
    }

    /**
     * Convert RTuple into a LineChart Dataset.
     * Supports relation([int,int]) This can be extended to support multiple lines in a chart
     * 
     * @param fact
     *            RTuple with the data
     * @return LineChart dataset
     * @author Raymond Bergen
     * @date 12-03-2007
     */
    public XYSeriesCollection convertRTupleToDataset(RTuple fact) {
        RElem set = fact.getValue();
        RElemElements elements = set.getElements();
        
        String name = getRTupleName(fact);
        XYSeries series = new XYSeries(name);  
        
        while (elements.hasTail()) {
            RElem headElement = elements.getHead();
            // Replace the current looping set with: ( set - head ).
            elements = elements.getTail();

            // HeadElement itselfs is a tuple <int,int>
            RElemElements tuple = headElement.getElements();

            // Disassemble the tuple into its parts.
            nl.cwi.sen1.relationstores.types.Integer xValue = null;
            nl.cwi.sen1.relationstores.types.Integer yValue = null;
            
            
            xValue = tuple.getRElemAt(0).getInteger();
            yValue = tuple.getRElemAt(1).getInteger();
    
            // Store the current tuple in the dataset.
            series.add(Double.valueOf(xValue.getNatCon()),Double.valueOf(yValue.getNatCon()));
        }
        
        final XYSeriesCollection dataset = new XYSeriesCollection();
        dataset.addSeries(series);
        
        return dataset;
    }
}