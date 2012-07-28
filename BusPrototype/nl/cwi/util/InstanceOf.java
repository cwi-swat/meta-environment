package nl.cwi.util;

/**
 * Checks if a class is an instance of another class or interface.
 * 
 * @author Arnold Lankamp
 */
public class InstanceOf{

	/**
	 * Default constructor. Private to prevent instantiation.
	 */
	private InstanceOf(){
		super();
	}

	/**
	 * Checks if a class extends the given 'superclass'.
	 * 
	 * @param c1
	 *            The subclass.
	 * @param c2
	 *            The possible superclass
	 * @return True if c1 extends c2, false otherwise.
	 */
	public static boolean isExtends(Class c1, Class c2){
		Class superClass = c1.getSuperclass();
		while(superClass != null){
			if(superClass.equals(c2)) return true;
			superClass = superClass.getSuperclass();
		}

		return false;
	}

	/**
	 * Checks if a class implements the given interface.
	 * 
	 * @param c1
	 *            The implementation.
	 * @param c2
	 *            The possibly corresponding interface.
	 * @return True if c1 implements c2, false otherwise.
	 */
	public static boolean isImplementationOf(Class c1, Class c2){
		Class[] interfaces = c1.getInterfaces();

		for(int i = 0; i < interfaces.length; i++){
			Class interfaceX = interfaces[i];
			if(interfaceX.equals(c2) || isImplementationOf(interfaceX, c2)){
				return true;
			}
		}
		return false;
	}
}
