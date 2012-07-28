package nl.cwi.sen1.visplugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.gui.plugin.StudioPlugin;
import nl.cwi.sen1.visplugin.csvexport.CsvExportController;
import nl.cwi.sen1.visplugin.table.TableVisualizationController;
import nl.cwi.sen1.visplugin.text.TextVisualizationController;
import aterm.pure.PureFactory;

/**
 * This class loads all visualization plugins.
 * 
 * @author Arnold Lankamp
 */
public class GenericVisualizationPluginsLoader extends DefaultStudioPlugin{
	private final static String VISUALIZATIONPLUGIN = "Visualization plugin collection";
	
	/**
	 * Default constructor.
	 */
	public GenericVisualizationPluginsLoader(){
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
		PureFactory factory = (PureFactory) studio.getATermFactory();
		
		TableVisualizationController table = new TableVisualizationController();
		table.initStudioPlugin(studio);
		table.initPluginController(factory);
		
		CsvExportController csv = new CsvExportController();
		csv.initStudioPlugin(studio);
		csv.initPluginController(factory);
		
		TextVisualizationController text = new TextVisualizationController();
		text.initStudioPlugin(studio);
		text.initPluginController(factory);
		
		fireStudioPluginClosed();
	}
}
