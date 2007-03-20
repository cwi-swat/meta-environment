package nl.dancingbear.visplugin;

import javax.swing.JPanel;

public class CsvExportProvider extends ExportProvider  {

	public boolean checkType(Object inputToExport){
		return true;
	}

	public void exportAction(Object inputToExport, String fileName, String fileExtension) {
		
	}
	
	protected String setDialogTitle() {		
		return "Export to .csv";
	}

	protected String setExtensions() {
		return ".csv";
	}

	protected String setPaths() {
		return "[]";
	}
	
	protected String setMenuOptionName() {
		return "Export to .csv";
	}
}
