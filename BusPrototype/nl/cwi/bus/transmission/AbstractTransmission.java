package nl.cwi.bus.transmission;

import nl.cwi.term.serializable.AbstractTerm;
import nl.cwi.term.serializable.TermConverter;

/**
 * Represents a transmission.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTransmission extends AbstractTerm{
	private TermConverter termConverter = null;

	/**
	 * Default constructor.
	 */
	public AbstractTransmission(){
		super();

		termConverter = new TermConverter();

		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param term
	 *            The term that needs to be contained in this transmission.
	 */
	public AbstractTransmission(AbstractTerm term){
		super();

		termConverter = new TermConverter(term);

		init();
	}

	/**
	 * Initializes this transmission.
	 */
	private void init(){
		register(termConverter);
	}

	/**
	 * Returns the term contained in this transmission.
	 * 
	 * @return The term contained in this transmission.
	 */
	public AbstractTerm getTerm(){
		return termConverter.getTerm();
	}

	/**
	 * @see AbstractTerm#match(String)
	 */
	public boolean match(String signature){
		return (signature.intern() == getSignature());
	}

	/**
	 * Creates a signature, based on the given start and end tokens.
	 * 
	 * @param startToken
	 *            The start token.
	 * @param endToken
	 *            the end token.
	 * @return The created signature.
	 */
	protected String createSignature(String startToken, String endToken){
		StringBuilder signatureBuilder = new StringBuilder();
		signatureBuilder.append(startToken);
		signatureBuilder.append(getTerm().getSignature());
		signatureBuilder.append(endToken);

		return signatureBuilder.toString();
	}
}
