package errorapi.types.summary;

public class Summary extends errorapi.types.Summary {
  public Summary(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_producer = 0;
  private static int index_id = 1;
  private static int index_list = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Summary) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getErrorapiFactory().makeSummary_Summary(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSummary()
  {
    return true;
  }

  public boolean hasProducer() {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public String getProducer() {
   return ((aterm.ATermAppl) getArgument(index_producer)).getAFun().getName();
  }

  public errorapi.types.Summary setProducer(String _producer) {
    return (errorapi.types.Summary) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_producer, 0, true)), index_producer);
  }

  public String getId() {
   return ((aterm.ATermAppl) getArgument(index_id)).getAFun().getName();
  }

  public errorapi.types.Summary setId(String _id) {
    return (errorapi.types.Summary) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_id, 0, true)), index_id);
  }

  public errorapi.types.ErrorList getList() {
    return (errorapi.types.ErrorList) getArgument(index_list);
  }

  public errorapi.types.Summary setList(errorapi.types.ErrorList _list) {
    return (errorapi.types.Summary) super.setArgument(_list, index_list);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Summary should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a Summary should have type str");
        }
        break;
      case 2:
        if (!(arg instanceof errorapi.types.ErrorList)) { 
          throw new RuntimeException("Argument 2 of a Summary should have type Error-list");
        }
        break;
      default: throw new RuntimeException("Summary does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
