package nl.cwi.term.serializable.test;

import java.lang.management.ManagementFactory;

import nl.cwi.term.serializable.FlexibleLengthTerm;
import nl.cwi.term.serializable.SerializableTerm;
import nl.cwi.util.NativeTypeBuilder;

public class SerializedTermTest extends SerializableTerm{
	private byte[] longByteArray = null;
	private byte[] intByteArray = null;
	private FlexibleLengthTerm string = null;

	public SerializedTermTest(boolean filled){
		super();
		if(filled){
			longByteArray = new byte[NativeTypeBuilder.LONGBYTES];
			fillRandom(longByteArray);

			intByteArray = new byte[NativeTypeBuilder.INTBYTES];
			fillRandom(intByteArray);

			// string = new FlexibleLengthTerm("testing".getBytes());

			// Temp
			byte[] bytes = new byte[5 * 1024 * 1024];
			string = new FlexibleLengthTerm(bytes);
			// End temp
		}else{
			string = new FlexibleLengthTerm();
		}

		init();
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

		SerializedTermTest serializedTermTestEmpty = new SerializedTermTest(false);
		serializedTermTestEmpty.put(firstBytes);
		serializedTermTestEmpty.put(lastBytes);

		System.out.println("\nValid: " + serializedTermTestEmpty.isValid());

		byte[] bytes = serializedTermTestEmpty.get(0, length());

		System.out.print("\n");

		for(int i = 0; i < bytes.length; i++){
			NativeTypeBuilder.printBits(bytes[i]);
			System.out.print("\n");
		}
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
		SerializedTermTest serializedTermTestEmpty = new SerializedTermTest(false);
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
		SerializedTermTest serializedTermTestEmpty = new SerializedTermTest(false);

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
		SerializedTermTest serializedTermTest = new SerializedTermTest(true);
		// serializedTermTest.test();
		serializedTermTest.testEfficientMem();
	}
}
