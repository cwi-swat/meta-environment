package nl.cwi.term.serializable.test;

import nl.cwi.bus.transmission.Do;
import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.term.serializable.TermConverter;

public class ConvertionTest{

	public ConvertionTest(){
		super();
	}
	
	public void test(){
		/*TermConverter getter = new TermConverter(new SerializableStringTerm("test"));
		byte[] bytes = getter.get(0, getter.length());
		
		TermConverter putter = new TermConverter();
		putter.put(bytes);
		
		System.out.println(((SerializableStringTerm)putter.getTerm()).getValue());
		*/
		/*
		SerializableStringTerm sstg = new SerializableStringTerm("testtesttest");
		byte[] bytes = sstg.get(0, sstg.length());
		SerializableStringTerm sstp = new SerializableStringTerm();
		sstp.put(bytes);
		
		System.out.println(sstp.getValue());*/
		
		Do d1 = new Do(new SerializableStringTerm("test"));
		TermConverter tc1 = new TermConverter(d1);
		byte[] bytes = tc1.get(0, tc1.length());
		/*
		for(int i = 0; i < bytes.length; i++){
			NativeTypeBuilder.printBits(bytes[i]);
			System.out.println();
		}
		
		for(int i = 0; i < bytes.length; i++){
			if(bytes[i] != 0) System.out.print(new String(new byte[]{bytes[i]}));
		}
		*/
		
		TermConverter tc2 = new TermConverter();
		tc2.put(bytes);
		Do d2 = (Do)tc2.getTerm();
		SerializableStringTerm s = (SerializableStringTerm)d2.getTerm();
		System.out.println(s.getValue());
	}
	
	public static void main(String[] args){
		ConvertionTest convertionTest = new ConvertionTest();
		convertionTest.test();
	}
}
