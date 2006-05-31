package nl.cwi.term.serializable;

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
	 * Updates the serializable object
	 */
	protected void update(){
		// Construct the term if we know which one it is.
		if(term == null && typeField.isValid()){
			// Resolve it.
			byte[] typeFieldContent = typeField.getContent();
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
		
		super.update();
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
