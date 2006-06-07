package nl.cwi.term.serializable.test;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import junit.textui.TestRunner;
import nl.cwi.bus.transmission.Do;
import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.term.serializable.TermConverter;
import nl.cwi.term.serializable.collection.ImmutableTermCollection;
import nl.cwi.term.serializable.collection.MutableTermCollection;

public class ConvertionTest extends TestCase{

	public ConvertionTest(){
		super();
	}
	
	public void setUp(){}

	public void tearDown(){}
	
	public void testString(){
		String string = "testtesttest";
		TermConverter getter = new TermConverter(new SerializableStringTerm(string));
		byte[] bytes = getter.get(0, getter.length());
		
		TermConverter putter = new TermConverter();
		putter.put(bytes);
		
		if(!((SerializableStringTerm)putter.getTerm()).getValue().equals(string)) fail("String didn't match: "+((SerializableStringTerm)putter.getTerm()).getValue()+" != "+string);
	}
	
	public void testDo(){
		String string = "testtesttest";
		Do d1 = new Do(new SerializableStringTerm(string));
		TermConverter tc1 = new TermConverter(d1);
		byte[] bytes = tc1.get(0, tc1.length());
		
		TermConverter tc2 = new TermConverter();
		tc2.put(bytes);
		Do d2 = (Do)tc2.getTerm();
		SerializableStringTerm s = (SerializableStringTerm)d2.getTerm();
		
		if(!s.getValue().equals(string)) fail("Do didn't match: "+s.getValue()+" != "+string);
	}
	
	public void testCollection(){
		String string = "testtesttest";
		SerializableStringTerm sst1 = new SerializableStringTerm(string);
		SerializableStringTerm sst2 = new SerializableStringTerm(string);
		
		ImmutableTermCollection termCollection = new ImmutableTermCollection(new SerializableStringTerm[]{sst1, sst2});
		byte[] bytes = termCollection.get(0, termCollection.length());
		
		ImmutableTermCollection termCollection2 = new ImmutableTermCollection();
		termCollection2.put(bytes);
		
		for(int i = 0; i < termCollection2.size(); i++){
			SerializableStringTerm sst = (SerializableStringTerm)termCollection2.getValue(i);
			if(!sst.getValue().equals(string)) fail("Collection didn't match: "+sst.getValue()+" != "+string);
		}
	}
	
	public void testMutableCollection(){
		String string1 = "testtesttest1";
		String string2 = "testtesttest2";
		SerializableStringTerm sst1 = new SerializableStringTerm(string1);
		SerializableStringTerm sst2 = new SerializableStringTerm(string2);
		
		MutableTermCollection collection = new MutableTermCollection(true);
		collection.add(sst1);
		collection.add(sst2);
		collection.remove(sst1);
		byte[] bytes = collection.get(0, collection.length());
		
		MutableTermCollection collection2 = new MutableTermCollection(false);
		collection2.put(bytes);
		
		SerializableStringTerm sst = (SerializableStringTerm)collection2.getValue(0);
		if(!sst.getValue().equals(string2)) fail("Collection didn't match: "+sst.getValue()+" != "+string2);
	}
	
	public static void main(String[] args){
		Test t = new TestSuite(ConvertionTest.class);
		TestRunner.run(t);
	}
}
