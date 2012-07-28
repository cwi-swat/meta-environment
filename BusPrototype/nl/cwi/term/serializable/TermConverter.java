package nl.cwi.term.serializable;

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

		typeField = new FlexibleLengthObject(term.getType());
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
			String termType = new String(typeFieldContent);

			// Instantiate it.
			term = TermFactory.getInstance().createEmptyTerm(termType);

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
