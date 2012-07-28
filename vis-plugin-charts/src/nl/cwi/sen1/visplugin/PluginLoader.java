package nl.cwi.sen1.visplugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.gui.plugin.StudioPlugin;
import nl.cwi.sen1.visplugin.barchart.BCVisualizationController;
import nl.cwi.sen1.visplugin.linechart.LCVisualizationController;
import nl.cwi.sen1.visplugin.piechart.PCVisualizationController;
import nl.cwi.sen1.visplugin.scatterchart.SCVisualizationController;
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
		
		BCVisualizationController barChartVisualizationController = new BCVisualizationController();
		barChartVisualizationController.initStudioPlugin(studio);
		barChartVisualizationController.initPluginController(pureFactory);
		
		LCVisualizationController lineChartVisualizationController = new LCVisualizationController();
		lineChartVisualizationController.initStudioPlugin(studio);
		lineChartVisualizationController.initPluginController(pureFactory);
		
		PCVisualizationController pieChartVisualizationController = new PCVisualizationController();
		pieChartVisualizationController.initStudioPlugin(studio);
		pieChartVisualizationController.initPluginController(pureFactory);
		
		SCVisualizationController scatterChartVisualizationController = new SCVisualizationController();
		scatterChartVisualizationController.initStudioPlugin(studio);
		scatterChartVisualizationController.initPluginController(pureFactory);
		
		fireStudioPluginClosed();
	}
}
