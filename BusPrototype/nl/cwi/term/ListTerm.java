package nl.cwi.term;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ListTerm extends Term{
	public final static String TYPE = "list";
	
	private List children = null;

	/**
	 * Default constructor.
	 */
	public ListTerm(){
		super(TYPE);
		
		children = new ArrayList();
	}
	
	/**
	 * Adds a child to this term.
	 * 
	 * @param child
	 *            Subordinate of this term.
	 */
	public void addChild(Term child){
		children.add(child);
	}

	/**
	 * Returns an array containing all the children of this term.
	 * 
	 * @return An array containing all the children of this term.
	 */
	public Term[] getChildren(){
		Object[] childObjs = children.toArray();
		Term[] childTerms = new Term[childObjs.length];
		System.arraycopy(childObjs, 0, childTerms, 0, childTerms.length);

		return childTerms;
	}

	/**
	 * Dettaches a child from this term.
	 * 
	 * @param child
	 *            The child that needs to be dettached.
	 */
	public void removeChild(Term child){
		children.remove(child);
	}
	
	/**
	 * Returns the signature of this term.
	 * 
	 * @see Term#getSignature()
	 * @return The signature of this term.
	 */
	public String getSignature(){
		StringBuilder signatureBuilder = new StringBuilder();
		
		signatureBuilder.append(getType());
		signatureBuilder.append(OPENTOKEN);
		
		Term[] childTerms = getChildren();
		for(int i = 0; i < childTerms.length; i++){
			signatureBuilder.append(childTerms[i].getSignature());
			if(i != (childTerms.length - 1)) signatureBuilder.append(SEPERATORTOKEN);
		}
		
		signatureBuilder.append(CLOSETOKEN);

		return signatureBuilder.toString();
	}
	
	/**
	 * Converts this term to a string.
	 * 
	 * @see Term#serialize()
	 * @return The serialized term.
	 */
	public String serialize(){
		StringBuilder signatureBuilder = new StringBuilder();

		// Add type
		signatureBuilder.append(getType());

		// Add children
		signatureBuilder.append(OPENTOKEN);
		Term[] childTerms = getChildren();
		for(int i = 0; i < childTerms.length; i++){
			signatureBuilder.append(childTerms[i].serialize());
			if(i != (childTerms.length - 1)) signatureBuilder.append(SEPERATORTOKEN);
		}

		signatureBuilder.append(CLOSETOKEN);

		return signatureBuilder.toString();
	}
	
	/**
	 * Parses the given serialized term and transforms it into a Term object.
	 * @param serializedTerm The serialized term that needs to be parsed.
	 * @return The created term object.
	 */
	public static Term parse(String serializedTerm){
		int openTokenIndex = serializedTerm.indexOf(OPENTOKEN);
		int closeTokenIndex = serializedTerm.lastIndexOf(CLOSETOKEN);
		String listContentSubString = serializedTerm.substring(openTokenIndex + OPENTOKEN.length(), closeTokenIndex);
		
		ListTerm listTerm = new ListTerm();
		
		StringTokenizer termTokenizer = new StringTokenizer(listContentSubString, SEPERATORTOKEN, false);
		while(termTokenizer.hasMoreTokens()){
			String term = termTokenizer.nextToken();
			Term childTerm = Term.parse(term);
			listTerm.addChild(childTerm);
		}
		
		return listTerm;
	}
}
