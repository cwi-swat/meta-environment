/**
 * @author paulk, Jul 16, 2002
 */

package toolbus.atom.msg;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.parsercup.PositionInformation;
import aterm.ATerm;

public abstract class MsgAtom extends Atom{
	public final ATerm msg;
	
	public MsgAtom(ATerm msg, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.msg = msg;
		setAtomArgs(new Ref[]{new Ref(msg)});
	}
}
