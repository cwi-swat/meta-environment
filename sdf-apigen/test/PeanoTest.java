package test;

import aterm.*;
import aterm.pure.*;
import java.util.*;
import test.peano.types.*;
import test.peano.Factory;

public class PeanoTest {

  private Factory factory;
  private OptLayout e;

  public PeanoTest(Factory factory) {
    this.factory = factory;
    this.e = factory.makeOptLayout_Present(factory.makeCHARLIST_Chars(" "));
  }

  public Nat make(int n) {
    Nat N = factory.makeNat_Zero();
    for(int i=0 ; i<n ; i++) {
      N = factory.makeNat_Suc(e,e,N,e);
    }

    return N;
  }

  public int unmake(Nat N) {
    int n;

    for (n=0;!N.isZero();N = N.getPred(), n++);

    return n;
  }

  public void run() {
    int n = 17;
    int r = fib(n);
    Nat N = make(n);
    Nat R = fib(N);

    if (unmake(R) != r) {
      System.err.println("unexpected result of computation!");
      System.exit (1);
    }
  }

  public final static void main(String[] args) {
    PeanoTest test = new PeanoTest(new Factory(new PureFactory()));
    test.run();
  }

  public Nat plus(Nat t1, Nat t2) {
    if (t2.isZero()) {
      return t1;
    }
    else if (t2.isSuc()) {
      Nat y = t2.getPred();
      return factory.makeNat_Suc(e,e,plus(t1,y),e);
    }
    else {
      return null;
    }
  }

  public Nat fib(Nat t) {
    if (t.isZero()) {
      return factory.makeNat_Suc(e,e,factory.makeNat_Zero(),e);
    }
    else if (t.isSuc() && t.getPred().isZero()) {
      return factory.makeNat_Zero();
    }
    else {
      Nat pred1 = t.getPred();
      Nat pred2 = pred1.getPred();

      return plus(fib(pred2),fib(pred1));
    }
  }

  public int fib(int n) {
    if (n == 0) {
      return 1;
    }
    else if (n == 1) {
      return 0;
    }
    else {
      return fib(n - 2) + fib(n - 1);
    }
  }
}

