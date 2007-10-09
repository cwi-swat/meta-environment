package nl.cwi.sen1.visplugin.piechart;

import java.awt.Font;

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
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;

/**
 * PieChart Plugin VisualisationWindow. Shows a pie chart.
 * 
 * @author A. Belgraver
 * @author R. van Remortel
 * @author Aldert Boerhoop (reviewer)
 * @author Anton Gerdessen (reviewer)
 */
public class PCVisualizationWindow extends VisualizationPluginWindow {

    /**
     * Render the RTuple in a Pie Chart.
     * 
     * @param fact
     *            RTuple with the information
     * @return JPanel holding the pie chart
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
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
        String name = getRTupleName(fact);
        DefaultPieDataset dataset = convertRTupleToDataset(fact);
        JFreeChart chart = createPieChart(name, dataset);

        return new ChartPanel(chart,true,false,true,true,true);
    }

    /**
     * Set a new Factory object, for testing purposes.
     * 
     * @param factory
     *            Factory to use
     * @author A. Belgraver
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
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
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * 
     * @date 07-3-2007
     */
    public boolean isTypeSupported(RTuple fact) {
        boolean match = (isRelStrInt(fact) || isRelIntStr(fact) || isRelInt(fact));

        return match;
    }

    /**
     * Check to see if the RTuple is indeed a str,int relation.
     * 
     * @param fact
     *            RTuple to test
     * @return True if it is the correct str,int type
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 20-2-2007
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G.     * 
     */
    private boolean isRelStrInt(RTuple fact) {
        RType rType = m_factory.RTypeFromString("relation([str,int])");
        boolean match = rType.equals(fact.getRtype());
        
        return match;
    }

    /**
     * Check to see if the RTuple is indeed a int relation.
     * 
     * @param fact
     *            RTuple to test
     * @return True if it is the correct str,int type
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 20-2-2007
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G. 
     */
    private boolean isRelInt(RTuple fact) {
        RType rType = m_factory.RTypeFromString("relation([int])");
        boolean match = rType.equals(fact.getRtype());

        return match;
    }
    
    /**
       /**
     * Check to see if the RTuple is indeed a str,int relation.
     * 
     * @param fact
     *            RTuple to test
     * @return True if it is the correct str,int type
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 20-2-2007
     * @todo Needs better implementation needs to be resolved reflection, dynamic 
     * dispatch... in a the base or utility class for all plugins, remark by Anton G.     * 
     */
    private boolean isRelIntStr(RTuple fact) {
        RType rType = m_factory.RTypeFromString("relation([int,str])");
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
     * Create the pie chart.
     * 
     * @param name
     *            Name to display on screen
     * @param dataset
     *            Dataset to show
     * @return a JFreeChart chart
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    private JFreeChart createPieChart(String name, DefaultPieDataset dataset) {
        // Initialise the chart.
        JFreeChart chart = ChartFactory.createPieChart(name, // chart title
                dataset, // data
                true, // include legend
                true, // include tooltips
                false); // incluse urls

        // Set the charts format options.
        PiePlot plot = (PiePlot) chart.getPlot();
        plot.setSectionOutlinesVisible(false);
        plot.setLabelFont(new Font("SansSerif", Font.PLAIN, 12));
        plot.setNoDataMessage("No data available");
        plot.setCircular(false);
        plot.setLabelGap(0.02);

        return chart;
    }

    /**
     * Convert RTuple into a PieChart Dataset.
     * 
     * @param fact
     *            RTuple with the data
     * @return PieChart dataset
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah (Fix)
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public DefaultPieDataset convertRTupleToDataset(RTuple fact) {
        RElem set = fact.getValue();
        RElemElements elements = set.getElements();
        
        DefaultPieDataset dataset = new DefaultPieDataset();
        
        String name = "";
        nl.cwi.sen1.relationstores.types.Integer value;
        int counter = 0;
        
        while (elements.hasTail()) {
            RElem headElement = elements.getHead();
            // Replace the current looping set with: ( set - head ).
            elements = elements.getTail();

            // HeadElement itselfs is a tuple <str,int>, <int,str>.
            RElemElements tuple = headElement.getElements();

            if (isRelStrInt(fact)) {
                name = tuple.getRElemAt(0).getStrCon();
                value = tuple.getRElemAt(1).getInteger();
            }else if (isRelIntStr(fact)) {
                name = tuple.getRElemAt(1).getStrCon();
                value = tuple.getRElemAt(0).getInteger();
            }else if (isRelInt(fact)) {
                value = tuple.getRElemAt(0).getInteger();
                name = new String(++counter + ": " + value);
            }else{
            	throw new RuntimeException("Unknown relation type.");
            }
                
            // Store the current tuple in the dataset.
            dataset.setValue(name, new Double(value.getNatCon()));
        }
        return dataset;
    }

 }