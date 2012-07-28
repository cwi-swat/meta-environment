package nl.cwi.sen1.configapi.types.configuration;

public class Configuration extends nl.cwi.sen1.configapi.types.Configuration {
  public Configuration(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_list = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Configuration) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeConfiguration_Configuration(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isConfiguration()
  {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.PropertyList getList() {
    return (nl.cwi.sen1.configapi.types.PropertyList) getArgument(index_list);
  }

  public nl.cwi.sen1.configapi.types.Configuration setList(nl.cwi.sen1.configapi.types.PropertyList _list) {
    return (nl.cwi.sen1.configapi.types.Configuration) super.setArgument(_list, index_list);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.PropertyList)) { 
          throw new RuntimeException("Argument 0 of a Configuration should have type Property-list");
        }
        break;
      default: throw new RuntimeException("Configuration does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
