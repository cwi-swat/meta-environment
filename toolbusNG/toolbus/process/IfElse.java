/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import aterm.*;

import toolbus.atom.*;
import toolbus.*;

public class IfElse implements ProcessExpression {
	private ATerm test;
	private ProcessExpression Pthen;
	private ProcessExpression Pelse;
	private AtomSet first;
	private AtomSet follow;
	
	public IfElse(ATerm test, ProcessExpression Pthen, ProcessExpression Pelse){
		this.test = test;
		this.Pthen = Pthen;
		this.Pelse = Pelse;
	}
	
	public ProcessExpression copy(){
		return new IfElse(test,Pthen.copy(), Pelse.copy());
	}

	public void compile(ProcessInstance P, AtomSet follows)
	throws ToolBusException
	{
		Pthen.compile(P, follows);
		Pthen.getFirst().setTest(test);
		Pelse.compile(P, follows);
		
		ATerm notTest = test.getFactory().make("not(<term>)", test);
		
		Pelse.getFirst().setTest(notTest);

		first = Pthen.getFirst().union(Pelse.getFirst());
		follow = Pthen.getFollow().union(Pelse.getFollow());
		//System.out.println("first = " + first);
		//System.out.println("follow = "+ follow);
	}

	public AtomSet getFirst(){
		return first;
	}
	
	public AtomSet getFollow(){
		return follow;
	}
	
	public void extendFollow(AtomSet f){
		//System.out.println("extendFollow(" + f + ")");
		Pthen.extendFollow(f);
		Pelse.extendFollow(f);
		if(follow.size() == 0)
			follow = follow.union(f);
	}
	
	public AtomSet getAtoms(){
		return Pthen.getAtoms().union(Pelse.getAtoms());
	}
	
	public void execute(){
	}
	
	public String toString(){
		return "IfElse(" + test + ", " + Pthen + ", " + Pelse + ")";
	}
}
