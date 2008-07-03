package toolbus.exceptions;

public class SyntaxErrorException extends RuntimeException{
	private static final long serialVersionUID = 2315538188275748342L;
	
	public final int line;
	public final int column;
	public final int position;
	public final int sym;
	public String filename = "";

	public SyntaxErrorException(String filename, int line, int column, int position, int sym){
		this(line, column, position, sym);
		this.filename = filename;
	}
	
	public SyntaxErrorException(int line, int column, int position, int sym){
		super();
		this.line = line;
		this.column = column;
		this.position = position;
		this.sym = sym;
	}
	
	
	public String getMessage(){
		return "Syntax error in "+filename+", at line: "+line+", column: "+column+", symbol id: "+sym;
	}
}