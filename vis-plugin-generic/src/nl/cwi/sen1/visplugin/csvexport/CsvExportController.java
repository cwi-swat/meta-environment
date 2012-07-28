package nl.cwi.sen1.visplugin.csvexport;

import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;
import nl.cwi.sen1.relationstores.types.rtype.Bag;
import nl.cwi.sen1.relationstores.types.rtype.Relation;
import nl.cwi.sen1.relationstores.types.rtype.Set;
import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * The CsvExportController class 
 * @author  Chris Woolderink
 * @author  Antoine Savelkoul
 * @date    13-03-2007
 */
public class CsvExportController extends VisualizationPluginController {
	

    /**************** 
     CONSTRUCTORS
    ****************/ 
    
	public CsvExportController() {
		super();
	}

    
    /**************** 
     VISUALIZATION PLUGIN CONTROLLER IMPLEMENTATION
    ****************/
    
	/**
	 * Return Table visualization window
	 * @author  Chris Woolderink
	 * @author  Antoine Savelkoul
	 * @date    13-03-2007
	 */
	public VisualizationPluginWindow createWindow() {
		CsvExportVisualizationWindow window = new CsvExportVisualizationWindow();
        
		return window;
	}
	
	
	
	/**
	 * Gets the plugin name [Table Visualization Plugin]
	 * @author  Chris Woolderink
	 * @author  Antoine Savelkoul
	 * @date    13-03-2007
	 */
	public String getPluginName(){
		return "CSV export";
	}
	
	
    /**************** 
     TOOLBUS EVENT HANDLERS 
    ****************/
    
	/**
	 * Define the supported types. Not implemented
     * because we override the isTypeSupported() 
     * function.
     * @author  Anton Lycklama  
     * @author  Bas Basten
	 * @date    13-03-2007
	 */
	public ATerm[] getSupportedTypes() {
        ATerm[] atermList = new ATerm[0];
		return atermList;
	}
    
    /**
     * Check if a type is supported
     * @param   type The type to check
     * @author  Anton Lycklama  
     * @author  Bas Basten
	 * @date    13-03-2007
     */
    protected boolean isTypeSupported(ATerm type) {        
        RType rtype = m_factory.RTypeFromTerm(type);        
        
        boolean isBag = rtype.isBag();
        boolean isRelation = rtype.isRelation();
        boolean isSet = rtype.isSet();
                
        if (isRelation) {            
            Relation relation = (Relation) rtype;
            RTypeColumnTypes columnTypes = relation.getColumnTypes();
            
            int numColumns = columnTypes.getLength();
            if (numColumns > 0) {
                for (int i = 0; i < numColumns; i++) {
                    RType childType = columnTypes.getRTypeAt(i);
                    // We don't support complex types.
                    if (isComplexType(childType)) {
                        return false;
                    }
                }
                return true;
            }            
        }
        // Maybe we can refactor this when we have more time.
        // The set and the bag use the same code to determine
        // if the type is supported or not.
        else if (isSet) {
            Set set = (Set) rtype;
            RType elementType = set.getElementType();
            // If the type is complex we don't support it,
            // otherwise we do support it.
            return !isComplexType(elementType); 
        }
        else if (isBag) {
            Bag bag = (Bag) rtype;           
            RType elementType = bag.getElementType();
            // If the type is complex we don't support it,
            // otherwise we do support it.
            return !isComplexType(elementType);            
        }        
               
        return false;
    }

    /**
     * 
     * @param   rtype  The RType to be evaluated
     * @return  true if the given RType represents a complex type (not int/string)
     * @author  Anton Lycklama  
     * @author  Bas Basten
	 * @date    13-03-2007
     */
    private boolean isComplexType(RType rtype) {
        boolean isBag = rtype.isBag();
        boolean isRelation = rtype.isRelation();
        boolean isSet = rtype.isSet();
        boolean isTuple = rtype.isTuple();
        
        if (isBag || isRelation || isSet || isTuple) {
            return true;
        }

        return false;
    }
}
