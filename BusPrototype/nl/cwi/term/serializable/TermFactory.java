package nl.cwi.term.serializable;

import java.util.HashMap;
import java.util.Map;

import nl.cwi.bus.transmission.Do;
import nl.cwi.bus.transmission.Eval;
import nl.cwi.bus.transmission.Event;
import nl.cwi.term.serializable.collection.ImmutableTermCollection;
import nl.cwi.term.serializable.collection.MutableTermCollection;
import nl.cwi.util.logging.Logger;

/**
 * A factory for generating empty terms. Follows the singleton design pattern.
 * 
 * @author Arnold Lankamp
 */
public class TermFactory{
	private Map terms = new HashMap();

	/**
	 * Default constructor.
	 */
	private TermFactory(){
		super();

		registerTerms();
	}

	/**
	 * Registers all the known terms.
	 */
	private void registerTerms(){
		terms.put(SerializableStringTerm.TYPE, SerializableStringTerm.class);
		terms.put(ImmutableTermCollection.TYPE, ImmutableTermCollection.class);
		terms.put(MutableTermCollection.TYPE, MutableTermCollection.class);
		terms.put(Do.TYPE, Do.class);
		terms.put(Eval.TYPE, Eval.class);
		terms.put(Event.TYPE, Event.class);
	}

	/**
	 * Creates a empty terms based on the given type.
	 * 
	 * @param termType
	 *            The type of the term that should be created.
	 * @return The created term.
	 */
	public AbstractTerm createEmptyTerm(String termType){
		Class termClass = (Class) terms.get(termType);

		AbstractTerm term = null;
		try{
			term = (AbstractTerm) termClass.newInstance();
		}catch(IllegalAccessException iaex){
			Logger.getInstance().log("Don't have access to the constructor of: " + termClass.getName(), Logger.ERROR, iaex);
			throw new RuntimeException(iaex);
		}catch(InstantiationException iex){
			Logger.getInstance().log("Cannot instantiate: " + termClass.getName(), Logger.ERROR, iex);
			throw new RuntimeException(iex);
		}

		return term;
	}

	/**
	 * Nested class used for ensuring thread-sage lazy initialization of this
	 * singleton.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class InstanceKeeper{
		private final static TermFactory instance = new TermFactory();
	}

	/**
	 * Returns a reference to this factory.
	 * 
	 * @return A reference to this factory.
	 */
	public static TermFactory getInstance(){
		return InstanceKeeper.instance;
	}
}
