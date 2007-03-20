package nl.dancingbear.visplugin;

import java.util.ArrayList;

import com.sun.corba.se.impl.orbutil.closure.Constant;

import aterm.ATerm;

/**
 * The VisualizationPluginController class represents the base class for the different plugin controllers.
 * @author  Aldert Boerhoop
 * @date    20-2-2007
 */
public abstract class ExportPluginController extends PluginController {

	private ExportProvider m_exportProvider;
	private ATerm m_fact;

    public final void initController(){
    	m_exportProvider = getExportProviderInstance();
    }
    
    public final void vpVisualizeFact(int storeId, int factId, ATerm fact){   		
    	
    	m_fact = fact;
    	openFileDialog(m_exportProvider.getDialogTitle(), m_exportProvider.getPaths(), m_exportProvider.getExtensions());
    }  
    
    public final void vpFileDialogResult(int windowId, String fileName){
    	
    	m_exportProvider.export(m_fact, fileName, "");
    }

    protected abstract ExportProvider getExportProviderInstance();
}
