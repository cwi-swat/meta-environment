package nl.cwi.sen1.visplugin.treemap;
import javax.swing.JLabel;
import javax.swing.JPanel;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;


public class TreeMapVisualizationWindow extends VisualizationPluginWindow {

	@Override
	public JPanel render(RTuple fact) {
        // Check if the fact is a supported Rtype.
        if (!isTypeSupported(fact)) {
            // for not supported type show an error message.
            JPanel jp = new JPanel();
            jp.add(new JLabel("Not a supported type"+fact.getRtype().toString()));
            return jp;
        }
        
        TreeMapPlugin treeMap = new TreeMapPlugin(fact);
        return treeMap.getPanel();
	}
	
    /**
     * Check if a given RType is supported by this visualisation.
     */
    public boolean isTypeSupported(RTuple fact) {
        //boolean match = (isRequiredRel(fact) );
       // return match;
        return true;
    }
    
    private boolean isRequiredRel(RTuple fact) {
        //RType rType = m_factory.RTypeFromString("relation([loc,set(loc),relation([str,int,relation([loc,int])])])");
        //boolean match = rType.equals(fact.getRtype());        
        //return match;
        return true;
    }
}
