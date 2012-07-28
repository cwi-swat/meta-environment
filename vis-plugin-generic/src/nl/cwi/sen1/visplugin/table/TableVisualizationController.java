package nl.cwi.sen1.visplugin.table;

import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
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
        return "Table";
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
       return true;
    }
}
