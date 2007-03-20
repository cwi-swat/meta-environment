package nl.dancingbear.visplugin;

import aterm.ATerm;

public class CsvExportPluginController extends ExportPluginController {

	public String getPluginName() {
		return "Export to .csv";
	}

	protected ExportProvider getExportProviderInstance() {
		ExportProvider csvExportProvider = new CsvExportProvider();
		return csvExportProvider;
	}

	public ATerm[] getSupportedTypes() {
		return null;
	}
	
	protected boolean isTypeSupported(ATerm type) {
		return true;
	}

	
}
