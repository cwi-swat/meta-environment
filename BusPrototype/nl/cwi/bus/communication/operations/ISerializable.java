package nl.cwi.bus.communication.operations;

/**
 * Implementations of this interface are able to (de-)serialize themselfs from /
 * to a byte array.
 * 
 * @author Arnold Lankamp
 */
public interface ISerializable{

	/**
	 * Gives the object (a part of) the bytes that it needs to build itself.
	 * @param bytes (A part of) the bytes that it needs to build itself.
	 */
	void put(byte[] bytes);

	/**
	 * Returns a byte array containing (a part of) the byte representation of this object.
	 * @param offset The start index.
	 * @param length The number of bytes to request.
	 * @return The constructed byte array containing (a part of) the byte representation of this object.
	 */
	byte[] get(int offset, int length);
	
	/**
	 * Returns a byte array containing the complete represenation of this object.
	 * Same as get(0, getLength()).
	 * @return A byte array containing the complete represenation of this object.
	 */
	byte[] get();

	/**
	 * Returns a byte array representation of the next 'nrOfBytes' from this object.
	 * @param nrOfBytes The number of bytes to get.
	 * @return The constructed byte array representation of the next 'nrOfBytes' from this object.
	 */
	byte[] getNext(int nrOfBytes);
	
	/**
	 * Returns the number of bytes left to serialize.
	 * @return The number of bytes left to serialize.
	 */
	int bytesLeft();

	/**
	 * Returns true of this object has been build completely.
	 * @return True of this object has been build completely; false otherwise.
	 */
	boolean isValid();
	
	/**
	 * Returns the length of the byte array representation of this object.
	 * @return The length of the byte array representation of this object.
	 */
	int getLength();
}
