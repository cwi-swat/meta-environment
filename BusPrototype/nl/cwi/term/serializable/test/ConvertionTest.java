package nl.cwi.term.serializable.test;

import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.term.serializable.TermConverter;

public class ConvertionTest{

	public ConvertionTest(){
		super();
	}
	
	public void test(){
		TermConverter getter = new TermConverter(new SerializableStringTerm("test"));
		byte[] bytes = getter.get(0, getter.length());
		
		TermConverter putter = new TermConverter();
		putter.put(bytes);
		
		System.out.println(((SerializableStringTerm)putter.getTerm()).getContent());
	}
	
	public static void main(String[] args){
		ConvertionTest convertionTest = new ConvertionTest();
		convertionTest.test();
	}
}
