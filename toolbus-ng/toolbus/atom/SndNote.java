/*
 * Created on Jun 25, 2005
 * @author paulk
 *
 */
package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * 
 *
 */
public class SndNote extends Atom {
	private Ref note;
	
	public SndNote(ATerm note, TBTermFactory tbfactory){
		super(tbfactory);
		this.note = new Ref(note);
		setAtomArgs(this.note);
	}

	public ProcessExpression copy() {
		Atom a = new SndNote(note.value, tbfactory);
		a.copyAtomAttributes(this);
		return a;
	}
	
	 public boolean execute() throws ToolBusException {
	    if (!isEnabled())
	      return false;
	    ATerm theNote = tbfactory.substitute(this.note.value, getEnv());
	    
	   // for(int i = 0; i < processes.size() ; i++){
	   // 	ProcessInstance pi = (ProcessInstance) processes.elementAt(i);
	    for(ProcessInstance pi : getToolBus().getProcesses()){
	    	//System.err.println(getProcess().getProcessName() + " tries to send note " + theNote + " to " + pi.getProcessName());
	    	pi.putNoteInQueue(theNote);
	    }
	    return true;
	 }
}
