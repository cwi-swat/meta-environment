package toolbus.process;

import toolbus.atom.*;

abstract public class AbstractProcessExpression implements ProcessExpression {
  private State first;
  private State follow;
  
  public AbstractProcessExpression() {
    first = new State();
  }
  
  public State getFirst() {
    return first;
  }
  
  protected void setFirst(State first) {
    this.first = first;
  } 
  
  public State getStartState(){
    return first;
  }
  
  protected void addToFirst(StateElement a) {
    first.add(a);
  }

  public State getFollow() {
    return follow;
  }
  
  protected void addToFollow(State set) {
    follow = follow.union(set);
  }
  
  protected void setFollow(State follow) {
    this.follow = follow;
  }

}
