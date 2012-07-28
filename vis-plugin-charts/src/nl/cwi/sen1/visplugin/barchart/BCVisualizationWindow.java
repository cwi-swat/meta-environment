package nl.cwi.sen1.visplugin.barchart;

import java.awt.Color;

import javax.swing.JLabel;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Integer;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.idcon.IdCon;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.CategoryAxis;
import org.jfree.chart.axis.CategoryLabelPositions;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.renderer.category.CategoryItemRenderer;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;

/**
 * BarChart Plugin VisualisationWindow. Shows a bar chart.
 * Original code : PieChart plugin ( A. Belgraver, R. van Remortel )
 * @author Srinivasan Tharmarajah
 */
public class BCVisualizationWindow extends VisualizationPluginWindow {

    /**
     * Render the RTuple in a Bar Chart.
     * 
     * @param fact
     *            RTuple with the information
     * @return JPanel holding the bar chart
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarjah
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
        CategoryDataset dataset = convertRTupleToDataset(fact);
        JFreeChart chart = createPieChart(name, dataset);

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
     * @author Aldert Boerhoop
     * @author Anton Gerdessen
     * @author Srinivasan Tharmarajah
     * @date 12-03-2007
     */
    public boolean isTypeSupported(RTuple fact) {
        boolean match = (isRelIntStr(fact) || isRelStrInt(fact) || isRelIntInt(fact) );

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
     * @author Srinivasan Tharmarajah
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
     * Check to see if the RTuple is indeed a str,int relation.
     * 
     * @param fact
     *            RTuple to test
     * @return True if it is the correct str,int type
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
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
     * Create the bar chart.
     * 
     * @param title
     *            Name to display on screen
     * @param dataset
     *            Dataset to show
     * @return a JFreeChart chart
     * @author Srinivasan Tharmarajah
     * @date 12-03-2007
     */
private JFreeChart createPieChart(String title, CategoryDataset dataset) {
        
    // create the chart...
    final JFreeChart chart = ChartFactory.createBarChart(
        title,                    // chart title
        "Fact",                   // domain axis label
        "Value",                  // range axis label
        dataset,                  // data
        PlotOrientation.VERTICAL, // orientation
        false,                    // include legend
        true,                     // tooltips?
        false                     // URLs?
    );

    // set the background color for the chart...
    chart.setBackgroundPaint(Color.white);

    // get a reference to the plot for further customisation...
    final CategoryPlot plot = chart.getCategoryPlot();
    plot.setBackgroundPaint(Color.lightGray);
    plot.setDomainGridlinePaint(Color.white);
    plot.setRangeGridlinePaint(Color.white);
    
    // set the range axis to display integers only...
    final NumberAxis rangeAxis = (NumberAxis) plot.getRangeAxis();
    rangeAxis.setStandardTickUnits(NumberAxis.createIntegerTickUnits());
    rangeAxis.setUpperMargin(0.15);
    
    // disable bar outlines...
    final CategoryItemRenderer renderer = plot.getRenderer();
    renderer.setSeriesItemLabelsVisible(0, Boolean.TRUE);
    
    final CategoryAxis domainAxis = plot.getDomainAxis();
    domainAxis.setCategoryLabelPositions(CategoryLabelPositions.UP_45);
    
    return chart;
        
    }

    /**
     * Convert RTuple into a BarChart Dataset.
     * 
     * @param fact
     *            RTuple with the data
     * @return BarChart dataset
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Srinivasan Tharmarajah
     * @date 12-03-2007
     */
    public CategoryDataset convertRTupleToDataset(RTuple fact) {
        RElem set = fact.getValue();
        RElemElements elements = set.getElements();
        
        final DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        
        while (elements.hasTail()) {
            RElem headElement = elements.getHead();
            // Replace the current looping set with: ( set - head ).
            elements = elements.getTail();

            // HeadElement itselfs is a tuple <str,int> or <int,str>.
            RElemElements tuple = headElement.getElements();

            // Disassemble the tuple into its parts.
            String name = "";
            nl.cwi.sen1.relationstores.types.Integer value;
            
            if (isRelStrInt(fact)) {
                name = tuple.getRElemAt(0).getStrCon();
                value = tuple.getRElemAt(1).getInteger();
            }
            else if (isRelIntStr(fact))  {
                name = tuple.getRElemAt(1).getStrCon();
                value = tuple.getRElemAt(0).getInteger();
            }
            else if (isRelIntInt(fact)) {
            	Integer i = tuple.getRElemAt(1).getInteger();
            	if (i.isNatCon()) {
            		name = "" + i.getNatCon();
            	}
            	else if (i.isNegative()) {
            		name = "-" + i.getNatCon();
            	}
            	else if (i.isPositive()) {
            		name = "+" + i.getNatCon();
            	}
            	value = tuple.getRElemAt(0).getInteger();
            }
            else{
            	throw new RuntimeException("Unknown relation type.");
            }
            
            // Store the current tuple in the dataset.
            dataset.addValue(Double.valueOf(value.getNatCon()), name, name);
        }
        return dataset;
    }

	private boolean isRelIntInt(RTuple fact) {
		 RType rType = m_factory.RTypeFromString("relation([int,int])");
	        boolean match = rType.equals(fact.getRtype());
	        
	        return match;
	}

   }