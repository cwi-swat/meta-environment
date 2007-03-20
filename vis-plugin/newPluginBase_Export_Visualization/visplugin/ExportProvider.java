package nl.dancingbear.visplugin;

public abstract class ExportProvider {

	public String m_dialogTitle; 
	public String m_paths; 
	public String m_extensions;
	public String m_menuOptionName;
	
	public ExportProvider(){
		System.out.println("Class:"+this.getClass().toString()+" initiated");
		
		setDialogTitle();
		setPaths();
		setExtensions();
		setMenuOptionName();
	}
	
	public final void export(Object inputToExport, String fileName, String fileExtension){
		if(checkType(inputToExport))
			exportAction(inputToExport, fileName, fileExtension);
	}
	
	protected abstract boolean checkType(Object inputToExport);
	protected abstract void exportAction(Object inputToExport, String fileName, String fileExtension);
	
	protected abstract String setDialogTitle();
	protected abstract String setPaths();
	protected abstract String setExtensions();
	protected abstract String setMenuOptionName();

	public String getDialogTitle(){
		return m_dialogTitle;
	}
	
	public String getPaths(){
		return m_paths;
	}
	
	public String getExtensions(){
		return m_extensions;
	} 
	
	public String getMenuOptionName(){
		return m_menuOptionName;
	} 
}
