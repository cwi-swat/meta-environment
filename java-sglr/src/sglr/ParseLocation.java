/*
 * Created on Sep 18, 2004
 */
package sglr;

import errorapi.*;
import errorapi.types.*;

/**
 * @author Cathal Boogerd
 */
public class ParseLocation {
	private static final int LINENO_START = 1;
	private static final int COLNO_START = 0;
	private static final int OFFSET_START = 0;
	
	private int lineno;
	private int colno;
	private int offset;
	private String fileName;
	private Factory factory;
	
	public ParseLocation(Factory fac, String inputFile) {
		lineno = LINENO_START;
		colno = COLNO_START;
		offset = OFFSET_START;
		factory = fac;
		fileName = inputFile;
	}
	
	public void update(int token) {
		update((char) token);
	}
	
	public void update(char token) {
		if (token == '\n') {
			lineno++;
			colno = COLNO_START;
		}
		else {
			colno++;
		}
		offset++;
	}
	
	public int getLine() {
		return lineno;
	}
	
	public int getCol() {
		return colno;
	}
	
	public String toString() {
		return "line " + lineno + ", column " + colno;
	}
	
	public Location getLocation() {
		return factory.makeLocation_AreaInFile(fileName, factory.makeArea_Area(lineno, colno, lineno, colno, offset, 1));
	}
}
