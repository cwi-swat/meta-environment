package toolbus.process;
/**
 * @author paulk, Jul 23, 2002
 */
import toolbus.*;
import toolbus.atom.*;
import toolbus.process.*;

public interface ProcessExpression {
	public String toString();
	public void compile(ProcessInstance P, AtomSet follows) throws ToolBusException;
	public ProcessExpression copy();
	public AtomSet getFirst();
	public AtomSet getFollow();
	public void extendFollow(AtomSet f);
	public AtomSet getAtoms();
}
