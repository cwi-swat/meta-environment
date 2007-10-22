package toolbus.parser;

import aterm.ATerm;

public class Include{
	private final String filename;
	
	public Include(String filename, ATerm posInfo){
		this.filename = filename;
	}
	
	public String getFilename(){
		return filename;
	}
}
