/**
 * @author paulk, Jul 20, 2002
 */
package toolbus;

import java.util.Vector;

import aterm.ATerm;

/**
 * MatchResult represents the progress of a match, starting with two environments.
 * It maintains two DeltaEnvironments recording the environment changes.
 * On success, the original environments are uopdated with the delta's.
 */

public class MatchResult {
  private Environment left;
  private DeltaEnvironment deltaLeft;
  private Environment right;
  private DeltaEnvironment deltaRight;

  public MatchResult(Environment left, Environment right) {
    this.left = left;
    this.deltaLeft = new DeltaEnvironment();
    this.right = right;
    this.deltaRight = new DeltaEnvironment();
  }
  
  public void assignLeft(ATerm rvar, ATerm val){
    deltaLeft.assign(rvar, val);
  }
  
   public void assignRight(ATerm rvar, ATerm val){
    deltaRight.assign(rvar, val);
  }
  
  public void updateEnvs(){
    deltaLeft.update(left);
    deltaRight.update(right);
  }

  public String toString() {
    return "MatchResult(" + left + ", " + right + ")";
  }
}

/**
 * A DeltaEnvironment stores the environment changes as a result of a match
 * (i.e. assignments to result variables).
 * The original environment can later be updated with these changes.
 */

class DeltaEnvironment {
  private Vector dict;

  public DeltaEnvironment() {
    dict = new Vector();
  }

  public boolean assign(ATerm rvar, ATerm val) {
    ATerm var1 = TBTerm.changeResVarIntoVar(rvar);
    for (int i = 0; i < dict.size(); i += 2) {
      ATerm var2 = (ATerm) dict.elementAt(i);
      if (var2.equals(var1))
        return val.equals((ATerm) dict.elementAt(i + 1));
    }
    dict.add(var1);
    dict.add(val);
    return true;
  }

  public void update(Environment env) {
    for (int i = 0; i < dict.size(); i += 2) {
      ATerm var = (ATerm) dict.elementAt(i);
      ATerm val = (ATerm) dict.elementAt(i + 1);
      env.putVar(var, val);
    }
  }
}