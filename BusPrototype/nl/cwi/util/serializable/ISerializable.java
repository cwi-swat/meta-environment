package nl.cwi.util.serializable;

/**
 * Implement is the object is (de-)serializable.
 * 
 * @author Arnold Lankamp
 */
public interface ISerializable{

	/**
	 * Returns a part of the content of this object.
	 * 
	 * @param offset
	 *            The byte to start serializing at.
	 * @param length
	 *            The number of bytes to serialize.
	 * @return The array of bytes that is constructed.
	 */
	public byte[] get(int offset, int length);

	/**
	 * Returns the length of the byte representation of this object.
	 * 
	 * @return The length of the byte representation of this object.
	 */
	public int length();

	/**
	 * Returns the number of bytes that can maximally be handled at this moment
	 * of time.
	 * 
	 * @return The number of bytes that can maximally be handled at this moment
	 *         of time.
	 */
	public int expectingBytes();

	/**
	 * Inserts an array of bytes into this deserializable object. The array
	 * represents (a part of) this object.
	 * 
	 * @param bytes
	 *            The array representing (a part of) this object.
	 */
	public void put(byte[] bytes);

	/**
	 * Checks if the object has been build completely.
	 * 
	 * @return True if the object has been completely build; false otherwise.
	 */
	public boolean isValid();
}
