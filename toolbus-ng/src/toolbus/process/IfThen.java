/**
 * @author paulk, Jul 26, 2002
 */
package toolbus.process;

import toolbus.TBTermFactory;
import toolbus.atom.Delta;
import toolbus.parsercup.PositionInformation;
import aterm.ATerm;

public class IfThen extends IfElse{
	
	public IfThen(ATerm test, ProcessExpression Pthen, TBTermFactory tbfactory, PositionInformation posInfo){
		super(test, Pthen, new Delta(tbfactory, posInfo), tbfactory, posInfo);
	}
}
