package nl.cwi.sen1.visplugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.gui.plugin.StudioPlugin;
import nl.cwi.sen1.visplugin.barchartplugin.BarChartVisualizationController;
import nl.cwi.sen1.visplugin.linechartplugin.LineChartVisualizationController;
import nl.cwi.sen1.visplugin.piechartplugin.PieChartVisualizationController;
import nl.cwi.sen1.visplugin.scatterchartplugin.ScatterChartVisualizationController;
import aterm.pure.PureFactory;

/**
 * This class loads all visualization plugins.
 * 
 * @author Arnold Lankamp
 */
public class PluginLoader extends DefaultStudioPlugin{
	private final static String VISUALIZATIONPLUGIN = "Visualization plugin collection";
	
	/**
	 * Default constructor.
	 */
	public PluginLoader(){
		super();
	}
	
	/**
	 * @see StudioPlugin#getName()
	 */
	public String getName(){
		return VISUALIZATIONPLUGIN;
	}

	/**
	 * @see StudioPlugin#initStudioPlugin(Studio)
	 */
	public void initStudioPlugin(Studio studio){
		PureFactory pureFactory = (PureFactory) studio.getATermFactory();
		
		BarChartVisualizationController barChartVisualizationController = new BarChartVisualizationController();
		barChartVisualizationController.initStudioPlugin(studio);
		barChartVisualizationController.initPluginController(pureFactory);
		
		LineChartVisualizationController lineChartVisualizationController = new LineChartVisualizationController();
		lineChartVisualizationController.initStudioPlugin(studio);
		lineChartVisualizationController.initPluginController(pureFactory);
		
		PieChartVisualizationController pieChartVisualizationController = new PieChartVisualizationController();
		pieChartVisualizationController.initStudioPlugin(studio);
		pieChartVisualizationController.initPluginController(pureFactory);
		
		ScatterChartVisualizationController scatterChartVisualizationController = new ScatterChartVisualizationController();
		scatterChartVisualizationController.initStudioPlugin(studio);
		scatterChartVisualizationController.initPluginController(pureFactory);
		
		fireStudioPluginClosed();
	}
}
