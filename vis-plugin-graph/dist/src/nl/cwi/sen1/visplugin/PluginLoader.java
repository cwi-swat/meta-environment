package nl.cwi.sen1.visplugin;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
import nl.cwi.sen1.gui.plugin.StudioPlugin;
import nl.cwi.sen1.visplugin.graphplugin.GraphVisualizationController;
import nl.cwi.sen1.visplugin.treeplugin.TreeVisualizationController;
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
		
		TreeVisualizationController treeVisualizationController = new TreeVisualizationController();
		treeVisualizationController.initStudioPlugin(studio);
		treeVisualizationController.initPluginController(pureFactory);
		
		GraphVisualizationController graphVisualizationController = new GraphVisualizationController();
		graphVisualizationController.initStudioPlugin(studio);
		graphVisualizationController.initPluginController(pureFactory);		
		
		fireStudioPluginClosed();
	}
}
