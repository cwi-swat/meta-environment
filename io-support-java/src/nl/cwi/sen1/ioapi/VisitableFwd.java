package nl.cwi.sen1.ioapi;

public class VisitableFwd extends Fwd implements jjtraveler.reflective.VisitableVisitor {
public int getChildCount() {
    return 1;
  }

  public jjtraveler.Visitable getChildAt(int i) {
    switch (i) {
    case 0: return (jjtraveler.Visitable) any;
    default: throw new IndexOutOfBoundsException();
    }
  }

  public jjtraveler.Visitable setChildAt(int i, jjtraveler.Visitable child) {
    switch (i) {
    case 0: any = (jjtraveler.reflective.VisitableVisitor) child; return this;
    default: throw new IndexOutOfBoundsException();
    }
  }

  public VisitableFwd(jjtraveler.reflective.VisitableVisitor any) {
    super(any);
  }
}
