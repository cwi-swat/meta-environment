package nl.dancingbear.visplugin.table;

import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;
import nl.cwi.sen1.relationstores.types.rtype.Bag;
import nl.cwi.sen1.relationstores.types.rtype.Relation;
import nl.cwi.sen1.relationstores.types.rtype.Set;
import nl.dancingbear.visplugin.VisualizationPluginController;
import nl.dancingbear.visplugin.VisualizationPluginWindow;
import aterm.ATerm;

/**
 * The TableVisualizationController class
 *
 * @author Srinivasan Tharmarajah
 * @author Wasim Alsaqaf
 * @author Antoine Savelkoul
 * @author Arend van Beelen
 * @date 07-03-2007
 */
public class TableVisualizationController extends VisualizationPluginController {

    private TableVisualizationWindow m_window;

    /**
     * Default constructor.
     *
     */
    public TableVisualizationController() {
        super();

        m_window = null;
    }

    /**
     * Return Table visualization window
     *
     */
    public VisualizationPluginWindow createWindow() {
        m_window = new TableVisualizationWindow();
        return m_window;
    }

    /**
     * Gets the plugin name [Table Visualization Plugin]
     *
     */
    public String getPluginName() {
        return "Table Visualization Plugin";
    }

    /**
     * Called when a file open dialog is accepted.
     *
     * @param windowId ID of the window that requested the export.
     * @param filename Filename returned by the file open dialog.
     *
     */
    public void vpFileDialogResult(int windowId, String filename) {
        TableVisualizationWindow window = (TableVisualizationWindow) getWindowById(windowId);

        switch (getWindowExportRequestType(windowId)) {
        case rStore:
            window.exportToRStore(filename);
            break;

        default:
            super.vpFileDialogResult(windowId, filename);
        }
    }

    /**
     * Define the supported types. Not implemented because we override the
     * isTypeSupported() function.
     *
     */
    public ATerm[] getSupportedTypes() {
        ATerm[] atermList = new ATerm[0];
        return atermList;
    }

    /**
     * Check if a type is supported
     *
     * @param type The type to check
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
        } else if (isBag) {
            Bag bag = (Bag) rtype;
            RType elementType = bag.getElementType();
            // If the type is complex we don't support it,
            // otherwise we do support it.
            return !isComplexType(elementType);
	}

        return false;
    }
    /**
     * Returns if the given Rtype is either a bag, relation, set
     * or tuple.
     *
     * @param rtype the Rtpe to check
     * @return returns true if the given Rtype is complex
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
