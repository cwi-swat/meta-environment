package toolbus.process;
/**
 * @author paulk, Jul 23, 2002
 */
import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

public interface ProcessExpression {
	public void compile(ProcessInstance processInstance, AtomSet followSet) throws ToolBusException;
	public ProcessExpression copy();
	public AtomSet getFirst();
	public AtomSet getFollow();
	public void extendFollow(AtomSet followSet);
	public AtomSet getAtoms();
}
