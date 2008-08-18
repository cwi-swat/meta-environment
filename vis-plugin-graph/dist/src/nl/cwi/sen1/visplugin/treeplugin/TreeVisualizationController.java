package nl.cwi.sen1.visplugin.treeplugin;
import aterm.ATerm;
import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;


/**
 * 
 * @author Qais
 */
public class TreeVisualizationController extends VisualizationPluginController {

    /**
     * Constructor.
     */
    public TreeVisualizationController() {
        super();
    }
    
	@Override
	public VisualizationPluginWindow createWindow() {
        return new TreeVisualizationWindow();
	}

	@Override
	public String getPluginName() {
        return "Tree";
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
