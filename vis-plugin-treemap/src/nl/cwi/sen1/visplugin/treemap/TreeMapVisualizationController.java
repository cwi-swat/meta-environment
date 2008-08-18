package nl.cwi.sen1.visplugin.treemap;
import aterm.ATerm;
import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;


/**
 * 
 * @author Qais
 */
public class TreeMapVisualizationController extends VisualizationPluginController {

    /**
     * Constructor.
     */
    public TreeMapVisualizationController() {
        super();
    }
    
	@Override
	public VisualizationPluginWindow createWindow() {
        return new TreeMapVisualizationWindow();
	}

	@Override
	public String getPluginName() {
        return "TreeMap";
	}

	@Override
	public ATerm[] getSupportedTypes() {
        ATerm[] atermList = {makeATerm("relation([loc,set(loc),relation([str,int,relation([loc,int])])])")};
        return atermList;
	}

    /**
     * Creates an aterm based on a String.
     */
    private ATerm makeATerm(String type) {
        return m_factory.RTypeFromString(type);
    }
}
