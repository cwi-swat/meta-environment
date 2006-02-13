package toolbus.parser;

public class Include {
	private String filename;
	private TBTermFactory tbfactory;

	public Include(ExternalParser ep, String filename, TBTermFactory tbfactory){
		this.filename = filename;
	}
	
	public ATerm parse(){
		TscriptParser.doparse(toolbus, filename);
	}
}
