/**
 * @author paulk, Jul 20, 2002
 */
package toolbus;

import java.util.Vector;

import aterm.ATerm;

/**
 * MatchResult represents the progress of a match, starting with two environments.
 * It maintains two DeltaEnvironments recording the environment changes.
 * On success, the original environments are updated with the delta's.
 */

public class MatchResult {
  private TBTermFactory tbfactory;
  private Environment left;
  private DeltaEnvironment deltaLeft;
  private Environment right;
  private DeltaEnvironment deltaRight;

  public MatchResult(TBTermFactory tbfactory) {
	  this.tbfactory = tbfactory;
	  this.deltaLeft = new DeltaEnvironment(tbfactory);
	  this.deltaRight = new DeltaEnvironment(tbfactory);
  }
  
  public void reset(Environment left, Environment right){
	  this.left = left;
	  deltaLeft.reset();
	  this.right = right;
	  deltaRight.reset();
  }
  
  public void assignLeft(TBTermVar rvar, ATerm val){
    deltaLeft.assign(rvar, val);
  }
  
   public void assignRight(TBTermVar rvar, ATerm val){
    deltaRight.assign(rvar, val);
  }
  
  public void updateEnvs(){
    deltaLeft.update(left,right);
    deltaRight.update(right,left);
  }

  public String toString() {
    return "MatchResult(" + left + ", " + right + ")";
  }
}

/**
 * A DeltaEnvironment stores the environment changes as a result of a match
 * (i.e. assignments to result variables).
 * The original environment can later be updated with these changes
 * (used by MatchResult.updateEnvs)
 */

class DeltaEnvironment {
  private Vector dict;
  private TBTermFactory tbfactory;

  public DeltaEnvironment(TBTermFactory tbfactory) {
	this.tbfactory = tbfactory;
    dict = new Vector(50);
  }
  
  public void reset(){
	  dict.removeAllElements();
  }

  public boolean assign(TBTermVar rvar, ATerm val) {
    TBTermVar var1 = tbfactory.changeResVarIntoVar(rvar);
    int dsize = dict.size();
    for (int i = 0; i < dsize; i += 2) {
      ATerm var2 = (ATerm) dict.elementAt(i);
      if (var2.equals(var1))
        return val.equals(dict.elementAt(i + 1));
    }
    dict.add(var1);
    dict.add(val);
    return true;
  }

  public void update(Environment enva, Environment envb) {
	int dsize = dict.size();
    for (int i = 0; i < dsize; i += 2) {
      ATerm var = (ATerm) dict.elementAt(i);
      ATerm val = (ATerm) dict.elementAt(i + 1);
      //System.err.println("DeltaEnvironment.update variable " + var + " with value " + val);
      try {
		enva.assignVar((TBTermVar)var, tbfactory.substitute(val, envb));
	} catch (ToolBusException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    }
  }
}