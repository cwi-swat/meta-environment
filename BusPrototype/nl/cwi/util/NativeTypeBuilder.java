package nl.cwi.util;

/**
 * Class responsible for converting native types to one another.
 * 
 * @author Arnold Lankamp
 */
public class NativeTypeBuilder{
	public final static int BOOLBITS = 1;
	public final static int BYTEBITS = 8;
	public final static int CHARBITS = 8;
	public final static int BOOLEAN = 1;
	public final static int BYTE = 1;
	public final static int SHORTBYTES = 2;
	public final static int INTBYTES = 4;
	public final static int LONGBYTES = 8;
	
	private final static int BYTEMASK = 0xFF;

	/**
	 * Default constructor.
	 * Made private to prevent instantiation.
	 */
	private NativeTypeBuilder(){
		super();
	}
	
	/**
	 * Converts a byte to a boolean.
	 * @param byteBool The byte to convert.
	 * @return The created boolean.
	 */
	public static boolean makeBoolean(byte[] byteBool){
		return (byteBool[0] > 0);
	}
	
	/**
	 * Converts a byte array of 2 (16 bits) to a short.
	 * @param bytes The input byte array.
	 * @return The constructed short.
	 */
	public static short makeShort(byte[] bytes){
		short result = 0;
		
		for(int i = 0; i < SHORTBYTES; i++){
			result += (bytes[i] & BYTEMASK) << (i * BYTEBITS);
		}
		
		return result;
	}
	
	/**
	 * Converts a byte array of 4 (32 bits) to a int.
	 * @param bytes The input byte array.
	 * @return The constructed int.
	 */
	public static int makeInt(byte[] bytes){
		int result = 0;
		
		for(int i = 0; i < INTBYTES; i++){
			result += (bytes[i] & BYTEMASK) << (i * BYTEBITS);
		}
		
		return result;
	}
	
	/**
	 * Converts a byte array of 8 (64 bits) to a long.
	 * @param bytes The input byte array.
	 * @return The constructed long
	 */
	public static long makeLong(byte[] bytes){
		long result = 0;
		
		for(int i = 0; i < LONGBYTES; i++){
			result += (((long)bytes[i]) & BYTEMASK) << (i * BYTEBITS);
		}
		
		return result;
	}
	
	/**
	 * Constructs a byte of 1 (8 bits) form the given boolean.
	 * @param booleanType The boolean to convert.
	 * @return The constructed byte array.
	 */
	public static byte makeBytesFromBoolean(boolean booleanType){
		byte bool = 0;
		if(booleanType) bool = 1;
		return bool;
	}
	
	/**
	 * Constructs a byte array of 4 (32 bits) form the given short.
	 * @param shortType The short to convert.
	 * @return The constructed byte array.
	 */
	public static byte[] makeBytesFromShort(short shortType){
		byte[] bytes = new byte[SHORTBYTES];
		
		for(int i = 0; i < SHORTBYTES; i++){
			bytes[i] = (byte)((shortType >> (i * BYTEBITS)) & BYTEMASK);
		}
		
		return bytes;
	}
	
	/**
	 * Constructs a byte array of 4 (32 bits) form the given integer.
	 * @param integer The interger to convert.
	 * @return The constructed byte array.
	 */
	public static byte[] makeBytesFromInt(int integer){
		byte[] bytes = new byte[INTBYTES];
		
		for(int i = 0; i < INTBYTES; i++){
			bytes[i] = (byte)((integer >> (i * BYTEBITS)) & BYTEMASK);
		}
		
		return bytes;
	}
	
	/**
	 * Constructs a byte array of 8 (64 bits) form the given long.
	 * @param enlongatedType The long to convert.
	 * @return The constructed byte array.
	 */
	public static byte[] makeBytesFromLong(long enlongatedType){
		byte[] bytes = new byte[LONGBYTES];
		
		for(int i = 0; i < LONGBYTES; i++){
			bytes[i] = (byte)((enlongatedType >> (i * BYTEBITS)) & BYTEMASK);
		}
		
		return bytes;
	}
	
	/**
	 * Prints the bit representation of the given byte in the console.
	 * @param b The byte to print.
	 */
	public static void printBits(byte b){
		byte mask = 1;
		for(int i = 7; i >= 0; i--){
			if(((b >> i) & mask) == mask) System.out.print("1");
			else System.out.print("0");
		}
	}
}
