/**
 * @author paulk, Jul 26, 2002
 */
package toolbus.process;

import toolbus.atom.Delta;

import aterm.ATerm;
public class IfThen extends IfElse {
	public IfThen(ATerm test, ProcessExpression Pthen){
		super(test, Pthen, new Delta());
	}

}
