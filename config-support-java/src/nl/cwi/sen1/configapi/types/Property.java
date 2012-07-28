package nl.cwi.sen1.configapi.types;

abstract public class Property extends nl.cwi.sen1.configapi.AbstractType {
  public Property(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Property peer) {
    return super.isEqual(peer);
  }

  public boolean isSortProperty()  {
    return true;
  }

  public boolean isImport() {
    return false;
  }

  public boolean isScript() {
    return false;
  }

  public boolean isScriptPath() {
    return false;
  }

  public boolean isAction() {
    return false;
  }

  public boolean isEditor() {
    return false;
  }

  public boolean isLibraryPath() {
    return false;
  }

  public boolean isModulePath() {
    return false;
  }

  public boolean isTextCategory() {
    return false;
  }

  public boolean hasPath() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public boolean hasAction() {
    return false;
  }

  public boolean hasEditor() {
    return false;
  }

  public boolean hasLanguage() {
    return false;
  }

  public boolean hasExtension() {
    return false;
  }

  public boolean hasLabel() {
    return false;
  }

  public boolean hasCategory() {
    return false;
  }

  public boolean hasMap() {
    return false;
  }

  public String getPath() {
     throw new UnsupportedOperationException("This Property has no Path");
  }

  public Property setPath(String _path) {
     throw new IllegalArgumentException("Illegal argument: " + _path);
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList getList() {
     throw new UnsupportedOperationException("This Property has no List");
  }

  public Property setList(nl.cwi.sen1.configapi.types.ActionDescriptionList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

  public String getAction() {
     throw new UnsupportedOperationException("This Property has no Action");
  }

  public Property setAction(String _action) {
     throw new IllegalArgumentException("Illegal argument: " + _action);
  }

  public String getEditor() {
     throw new UnsupportedOperationException("This Property has no Editor");
  }

  public Property setEditor(String _editor) {
     throw new IllegalArgumentException("Illegal argument: " + _editor);
  }

  public String getLanguage() {
     throw new UnsupportedOperationException("This Property has no Language");
  }

  public Property setLanguage(String _language) {
     throw new IllegalArgumentException("Illegal argument: " + _language);
  }

  public String getExtension() {
     throw new UnsupportedOperationException("This Property has no Extension");
  }

  public Property setExtension(String _extension) {
     throw new IllegalArgumentException("Illegal argument: " + _extension);
  }

  public String getLabel() {
     throw new UnsupportedOperationException("This Property has no Label");
  }

  public Property setLabel(String _label) {
     throw new IllegalArgumentException("Illegal argument: " + _label);
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName getCategory() {
     throw new UnsupportedOperationException("This Property has no Category");
  }

  public Property setCategory(nl.cwi.sen1.configapi.types.TextCategoryName _category) {
     throw new IllegalArgumentException("Illegal argument: " + _category);
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap getMap() {
     throw new UnsupportedOperationException("This Property has no Map");
  }

  public Property setMap(nl.cwi.sen1.configapi.types.TextAttributeMap _map) {
     throw new IllegalArgumentException("Illegal argument: " + _map);
  }

}

