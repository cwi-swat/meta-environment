package toolbus.util;

/**
 * This class handles the conversion of native types from and to their byte representation.
 * 
 * @author Arnold Lankamp
 */
public class NativeTypeConverter{
	private final static int BYTEMASK = 0xFF;

	/**
	 * Default constructor. Made private to prevent instantiation.
	 */
	private NativeTypeConverter(){
		super();
	}

	/**
	 * Merges two (little endian encoded) bytes into a unsigned short value.
	 * 
	 * @param shortBytes
	 *            The two (little endian encoded) bytes.
	 * @return The resulting short value.
	 */
	public static int makeUnsignedShort(byte[] shortBytes){
		return (shortBytes[0] & BYTEMASK) | ((shortBytes[1] & BYTEMASK) << 8);
	}

	/**
	 * Splits the given unsigned short value into two separate bytes (little endian encoded).
	 * 
	 * @param twoByteNumber
	 *            The short that needs to be split.
	 * @return Two (little endian encoded) bytes.
	 */
	public static byte[] makeBytesFromUnsignedShort(int twoByteNumber){
		byte[] shortBytes = new byte[2];

		shortBytes[0] = (byte) (twoByteNumber);
		shortBytes[1] = (byte) (twoByteNumber >>> 8);

		return shortBytes;
	}

	/**
	 * Merges four (little endian encoded) bytes into a int value.
	 * 
	 * @param intBytes
	 *            The four (little endian encoded) bytes.
	 * @return The resulting int value.
	 */
	public static int makeInt(byte[] intBytes){
		return (intBytes[0] & BYTEMASK) | ((intBytes[1] & BYTEMASK) << 8) | ((intBytes[2] & BYTEMASK) << 16) | ((intBytes[3] & BYTEMASK) << 24);
	}

	/**
	 * Splits the given int value into four separate bytes (little endian encoded).
	 * 
	 * @param fourByteNumber
	 *            The int that needs to be split.
	 * @return Four (little endian encoded) bytes.
	 */
	public static byte[] makeBytesFromInt(int fourByteNumber){
		byte[] intBytes = new byte[4];
		
		intBytes[0] = (byte) fourByteNumber;
		intBytes[1] = (byte) (fourByteNumber >>> 8);
		intBytes[2] = (byte) (fourByteNumber >>> 16);
		intBytes[3] = (byte) (fourByteNumber >>> 24);

		return intBytes;
	}
}
