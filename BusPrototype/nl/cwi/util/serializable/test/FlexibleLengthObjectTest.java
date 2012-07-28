package nl.cwi.util.serializable.test;

import nl.cwi.util.serializable.FlexibleLengthObject;
import nl.cwi.util.serializable.SerializableObject;

public class FlexibleLengthObjectTest extends SerializableObject{
	private FlexibleLengthObject flo = null;

	public FlexibleLengthObjectTest(){
		super();
		
		flo = new FlexibleLengthObject();
		
		init();
	}
	
	public FlexibleLengthObjectTest(byte[] value){
		flo = new FlexibleLengthObject(value);
		
		init();
	}
	
	private void init(){
		register(flo);
	}
	
	public byte[] getValue(){
		return flo.getContent();
	}
	
	public static void main(String[] args){
		FlexibleLengthObjectTest flotFilled = new FlexibleLengthObjectTest("test".getBytes());
		FlexibleLengthObjectTest flotEmpty = new FlexibleLengthObjectTest();
		flotEmpty.put(flotFilled.get(0, flotFilled.length()));
		
		System.out.println(new String(flotEmpty.getValue()));
	}
}
