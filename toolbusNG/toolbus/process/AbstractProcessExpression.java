package toolbus.process;

import toolbus.atom.*;

abstract public class AbstractProcessExpression implements ProcessExpression {
  private AtomSet first;
  private AtomSet follow;
  
  public AbstractProcessExpression() {
    first = new AtomSet();
  }
  
  public AtomSet getFirst() {
    return first;
  }
  
  protected void setFirst(AtomSet first) {
    this.first = first;
  } 
  
  protected void addToFirst(Atom atom) {
    first.add(atom);
  }

  public AtomSet getFollow() {
    return follow;
  }
  
  protected void addToFollow(AtomSet set) {
    follow = follow.union(set);
  }
  
  protected void setFollow(AtomSet follow) {
    this.follow = follow;
  }

}
