/*
 * Created on Jun 26, 2003
 *
 * To change the template for this generated file go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
package trans;

import aterm.ATermFactory;

/**
 * @author kooiker
 *
 * To change the template for this generated type comment go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
public class Adapter {
	private ATermFactory factory;

	public static void main(String[] args) throws Exception {
		Adapter a = new Adapter();
	}
	
	public Adapter() throws Exception {
		factory = new aterm.pure.PureFactory();
		Connection1 con1 = new Connection1(factory);
		Connection2 con2 = new Connection2(factory);		
		con1.Connection2(con2);
		con2.Connection1(con1);
	}
}
