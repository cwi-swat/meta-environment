package nl.dancingbear.visplugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.dancingbear.visplugin.barchartplugin.BarChartVisualizationController;
import nl.dancingbear.visplugin.csvexport.CsvExportController;
import nl.dancingbear.visplugin.graphplugin.GraphVisualizationController;
import nl.dancingbear.visplugin.linechartplugin.LineChartVisualizationController;
import nl.dancingbear.visplugin.piechartplugin.PieChartVisualizationController;
import nl.dancingbear.visplugin.scatterchartplugin.ScatterChartVisualizationController;
import nl.dancingbear.visplugin.table.TableVisualizationController;
import aterm.pure.PureFactory;

public class PluginLoader extends DefaultStudioPlugin{
	private final static String VISUALIZATIONPLUGIN = "Visualization plugin collection";
	
	public PluginLoader(){
		// Intentionally left empty.
	}
	
	public String getName(){
		return VISUALIZATIONPLUGIN;
	}

	public void initStudioPlugin(Studio studio){
		PureFactory pureFactory = (PureFactory) studio.getATermFactory();
		
		BarChartVisualizationController barChartVisualizationController = new BarChartVisualizationController();
		barChartVisualizationController.initStudioPlugin(studio);
		barChartVisualizationController.initPluginController(pureFactory);
		
		GraphVisualizationController graphVisualizationController = new GraphVisualizationController();
		graphVisualizationController.initStudioPlugin(studio);
		graphVisualizationController.initPluginController(pureFactory);
		
		LineChartVisualizationController lineChartVisualizationController = new LineChartVisualizationController();
		lineChartVisualizationController.initStudioPlugin(studio);
		lineChartVisualizationController.initPluginController(pureFactory);
		
		PieChartVisualizationController pieChartVisualizationController = new PieChartVisualizationController();
		pieChartVisualizationController.initStudioPlugin(studio);
		pieChartVisualizationController.initPluginController(pureFactory);
		
		ScatterChartVisualizationController scatterChartVisualizationController = new ScatterChartVisualizationController();
		scatterChartVisualizationController.initStudioPlugin(studio);
		scatterChartVisualizationController.initPluginController(pureFactory);
		
		TableVisualizationController tableVisualizationController = new TableVisualizationController();
		tableVisualizationController.initStudioPlugin(studio);
		tableVisualizationController.initPluginController(pureFactory);
		
		CsvExportController csvExportController = new CsvExportController();
		csvExportController.initStudioPlugin(studio);
		csvExportController.initPluginController(pureFactory);
	}
}
