package toolbus.parser;

import aterm.ATerm;

public class Include {
	private String filename;
	
	private ATerm posInfo;

	public Include(String filename, ATerm posInfo){
		this.filename = filename;
		this.posInfo = posInfo;
	}
	
	public String getFilename(){
		return filename;
	}
}
