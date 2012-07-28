package nl.cwi.term.test;

import nl.cwi.term.IntTerm;
import nl.cwi.term.ListTerm;
import nl.cwi.term.StringTerm;
import nl.cwi.term.Term;

/**
 * Test for the term, that just prints some stuff into the console.
 * 
 * @author Arnold Lankamp
 */
public class TestTerm{

	/**
	 * Default constructor.
	 */
	public TestTerm(){
		super();
	}

	/**
	 * Entrypoint
	 * 
	 * @param args
	 *            The arguments
	 */
	public static void main(String[] args){
		// Construct
		ListTerm term = new ListTerm();
		Term term2 = new StringTerm("stringterm");
		Term term3 = new IntTerm(14795343);
		term.addChild(term2);
		term.addChild(term3);

		// Serializing
		System.out.println("Signature: " + term.getSignature());
		System.out.println("Matches to itself: " + term.match(term.getSignature()));
		System.out.println("Serialized: " + term.serialize());

		// Deserializing
		Term t = Term.parse(term.serialize());
		System.out.println("Serialized -> Deserialized -> Serialized: " + t.serialize());
	}
}
