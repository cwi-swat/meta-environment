package nl.cwi.util.serializable.test;

import java.lang.management.ManagementFactory;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.serializable.FlexibleLengthObject;
import nl.cwi.util.serializable.SerializableObject;

public class SerializedObjectTest extends SerializableObject{
	private byte[] longByteArray = null;
	private byte[] intByteArray = null;
	private FlexibleLengthObject string = null;

	public SerializedObjectTest(boolean filled){
		super();
		
		longByteArray = new byte[NativeTypeBuilder.LONGBYTES];
		intByteArray = new byte[NativeTypeBuilder.INTBYTES];
		
		if(filled){	
			fillRandom(longByteArray);
			
			fillRandom(intByteArray);

			 string = new FlexibleLengthObject("testing".getBytes());

			// Temp
		/*	byte[] bytes = new byte[5 * 1024 * 1024];
			string = new FlexibleLengthObject(bytes);*/
			// End temp
		}else{
			string = new FlexibleLengthObject();
		}

		init();
	}
	
	public FlexibleLengthObject getString(){
		return string;
	}

	public void init(){
		registerNativeType(NativeTypeBuilder.LONGBYTES, longByteArray);
		registerNativeType(NativeTypeBuilder.INTBYTES, intByteArray);
		register(string);
	}

	public void fillRandom(byte[] bytes){
		for(int i = 0; i < bytes.length; i++){
			bytes[i] = (byte) (255 * Math.random());
		}
	}

	// Tests

	public void test(){
		byte[] firstBytes = get(0, 3);
		byte[] lastBytes = get(3, length() - 3);

		for(int i = 0; i < firstBytes.length; i++){
			NativeTypeBuilder.printBits(firstBytes[i]);
			System.out.print("\n");
		}
		for(int i = 0; i < lastBytes.length; i++){
			NativeTypeBuilder.printBits(lastBytes[i]);
			System.out.print("\n");
		}

		SerializedObjectTest serializedTermTestEmpty = new SerializedObjectTest(false);
		serializedTermTestEmpty.put(firstBytes);
		serializedTermTestEmpty.put(lastBytes);

		System.out.println("\nValid: " + serializedTermTestEmpty.isValid());

		byte[] bytes = serializedTermTestEmpty.get(0, length());

		System.out.print("\n");

		for(int i = 0; i < bytes.length; i++){
			NativeTypeBuilder.printBits(bytes[i]);
			System.out.print("\n");
		}
		
		System.out.println(new String(serializedTermTestEmpty.getString().getContent()));
	}

	public void testMemoryUsage(){
		// Run the gc
		System.gc();

		// I want to connect with JMX first, so wait a sec.
		try{
			Thread.sleep(10000);
		}catch(InterruptedException irex){
			irex.printStackTrace();
		}

		System.out.println("Started serializing: " + System.currentTimeMillis() + " mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());
		byte[] bytes = get(0, length());
		System.out.println("Done serializing: " + System.currentTimeMillis() + " mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());

		// Run the gc
		System.gc();

		// Wait a sec to make the two different actions clear on the graph.
		try{
			Thread.sleep(10000);
		}catch(InterruptedException irex){
			irex.printStackTrace();
		}

		System.out.println("Started deserializing: " + System.currentTimeMillis() + " mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());
		SerializedObjectTest serializedTermTestEmpty = new SerializedObjectTest(false);
		serializedTermTestEmpty.put(bytes);
		System.out.println("Done deserializing: " + System.currentTimeMillis() + " mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());

		// Run the gc
		System.gc();

		// Don't exit
		try{
			Object o = new Object();
			synchronized(o){
				o.wait();
			}
		}catch(InterruptedException irex){
			irex.printStackTrace();
		}
	}

	public void testEfficientMem(){
		SerializedObjectTest serializedTermTestEmpty = new SerializedObjectTest(false);

		System.gc();
		System.out.println("Start Mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());

		int blockSize = 100000;
		int position = 0;
		while(!serializedTermTestEmpty.isValid()){
			int bytesToGet = 0;
			if((position + blockSize) > length()){
				bytesToGet = length() % blockSize;
			}else{
				bytesToGet = blockSize;
			}

			byte[] bytes = get(position, bytesToGet);
			serializedTermTestEmpty.put(bytes);

			position += bytesToGet;

			System.gc();
			System.out.println("Mem: " + ManagementFactory.getMemoryMXBean().getHeapMemoryUsage());
		}
	}

	public static void main(String[] args){
		SerializedObjectTest serializedTermTest = new SerializedObjectTest(true);
		 serializedTermTest.test();
		//serializedTermTest.testEfficientMem();
	}
}
