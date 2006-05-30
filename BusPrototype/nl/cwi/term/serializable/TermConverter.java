package nl.cwi.term.serializable;

import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.logging.Logger;
import nl.cwi.util.serializable.FlexibleLengthObject;
import nl.cwi.util.serializable.SerializableObject;

/**
 * This class handles the serialization and deserialization of terms.
 * 
 * @author Arnold Lankamp
 */
public class TermConverter extends SerializableObject{
	private FlexibleLengthObject typeField = null;
	private AbstractTerm term = null;

	/**
	 * Default constructor.
	 */
	public TermConverter(){
		super();

		typeField = new FlexibleLengthObject();
		register(typeField);
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that needs to be serialized.
	 */
	public TermConverter(AbstractTerm term){
		super();

		typeField = new FlexibleLengthObject(term.getClass().getName());
		register(typeField);

		this.term = term;
		register(term);
	}

	/**
	 * @see nl.cwi.util.serializable.ISerializable#expectingBytes()
	 */
	public int expectingBytes(){
		int expecting = super.expectingBytes();

		// If the term has not been initialized yet, we do expect more bytes, so
		// return NativeTypeBuilder.INTBYTES (size of the length field of the
		// term).
		if(expecting == 0 && term == null) expecting = NativeTypeBuilder.INTBYTES;

		return expecting;
	}

	/**
	 * @see nl.cwi.util.serializable.ISerializable#put(byte[])
	 */
	public void put(byte[] bytes){
		// Construct the term if we know which one it is.
		if(term == null && typeField.isValid()){
			// Resolve it.
			byte[] typeFieldContent = typeField.getContent(typeField.getKey());
			String termClassName = new String(typeFieldContent);

			// Instantiate it.
			try{
				Class termClass = Class.forName(termClassName);
				term = (AbstractTerm) termClass.newInstance();
			}catch(ClassNotFoundException cnex){
				Logger.getInstance().log("No matching class found for the given type: " + termClassName, Logger.ERROR, cnex);
				throw new RuntimeException(cnex);
			}catch(IllegalAccessException iaex){
				Logger.getInstance().log("Don't have access to the constructor of: " + termClassName, Logger.ERROR, iaex);
				throw new RuntimeException(iaex);
			}catch(InstantiationException iex){
				Logger.getInstance().log("Cannot instantiate: " + termClassName, Logger.ERROR, iex);
				throw new RuntimeException(iex);
			}

			// Register it.
			register(term);
		}

		super.put(bytes);
	}

	/**
	 * Returns the term.
	 * 
	 * @return The term.
	 */
	public AbstractTerm getTerm(){
		return term;
	}
}
