package toolbus.atom;

import aterm.*;

public class Ref {
  public ATerm value;

  public Ref(ATerm at) {
    this.value = at;
  }
  public String toString() {
  	return "Ref(" + value + ")";
  }
}