/*
 * Created on 5-sep-2004
 */
package sglr;

import java.io.*;
import java.text.CharacterIterator;
import java.text.StringCharacterIterator;

import sglr.mept.PTable;
import sglr.mept.PTableLookAhead;

/**
 * @author Cathal Boogerd
 */
public class ParseInput {
	private StringCharacterIterator iterator;
	private int first;
	
	public ParseInput(File inputFile) throws FileNotFoundException, IOException {
		String content = new String();
		FileInputStream input = new FileInputStream(inputFile);
		int current = input.read();
		
		while (current != -1) {
			content += (char) current;
			current = input.read();
		}
		
		iterator = new StringCharacterIterator(content);
		first = 1;
	}
	
	public ParseInput(String inputString) {
		iterator = new StringCharacterIterator(inputString);
		first = 1;
	}

	public int read() {
		int current;
		
		if (first == 1) {
			first = 0;
			current = iterator.first();
		}
		else {
			current = iterator.next();
		}
		
		if (current == CharacterIterator.DONE) {
			return PTable.TOKEN_EOF;
		}
		return current;
	}
	
	public boolean ready() {
		return iterator.current() != CharacterIterator.DONE;
	}
	
	public boolean lookAhead(PTableLookAhead las) {
		int index, number;
		boolean permitted = false;
		
		for (index = 0; index < las.size(); index++) {
			number = read();
			if (number == CharacterIterator.DONE || !las.inRange(index, number)) {
				index++;
				permitted = true;
				break;
			}
		}
		iterator.setIndex(iterator.getIndex() - index);
		
		return permitted;
	}
}
