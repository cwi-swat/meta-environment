package nl.cwi.sen1.configapi.types.property;

public class Editor extends nl.cwi.sen1.configapi.types.Property {
  public Editor(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_editor = 0;
  private static int index_language = 1;
  private static int index_extension = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Editor) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeProperty_Editor(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isEditor()
  {
    return true;
  }

  public boolean hasEditor() {
    return true;
  }

  public boolean hasLanguage() {
    return true;
  }

  public boolean hasExtension() {
    return true;
  }

  public String getEditor() {
   return ((aterm.ATermAppl) getArgument(index_editor)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setEditor(String _editor) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_editor, 0, true)), index_editor);
  }

  public String getLanguage() {
   return ((aterm.ATermAppl) getArgument(index_language)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setLanguage(String _language) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_language, 0, true)), index_language);
  }

  public String getExtension() {
   return ((aterm.ATermAppl) getArgument(index_extension)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setExtension(String _extension) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_extension, 0, true)), index_extension);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Editor should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a Editor should have type str");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 2 of a Editor should have type str");
        }
        break;
      default: throw new RuntimeException("Editor does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
