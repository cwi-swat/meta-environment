package nl.cwi.sen1.configapi.types;

abstract public class Event extends nl.cwi.sen1.configapi.AbstractType {
  public Event(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Event peer) {
    return super.isEqual(peer);
  }

  public boolean isSortEvent()  {
    return true;
  }

  public boolean isPopup() {
    return false;
  }

  public boolean isClick() {
    return false;
  }

  public boolean isIcon() {
    return false;
  }

  public boolean isMenu() {
    return false;
  }

  public boolean isMenuShortcut() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public boolean hasButton() {
    return false;
  }

  public boolean hasTitle() {
    return false;
  }

  public boolean hasPath() {
    return false;
  }

  public boolean hasLabels() {
    return false;
  }

  public boolean hasInfo() {
    return false;
  }

  public boolean hasShortcut() {
    return false;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList getList() {
     throw new UnsupportedOperationException("This Event has no List");
  }

  public Event setList(nl.cwi.sen1.configapi.types.KeyModifierList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

  public nl.cwi.sen1.configapi.types.VirtualButton getButton() {
     throw new UnsupportedOperationException("This Event has no Button");
  }

  public Event setButton(nl.cwi.sen1.configapi.types.VirtualButton _button) {
     throw new IllegalArgumentException("Illegal argument: " + _button);
  }

  public String getTitle() {
     throw new UnsupportedOperationException("This Event has no Title");
  }

  public Event setTitle(String _title) {
     throw new IllegalArgumentException("Illegal argument: " + _title);
  }

  public String getPath() {
     throw new UnsupportedOperationException("This Event has no Path");
  }

  public Event setPath(String _path) {
     throw new IllegalArgumentException("Illegal argument: " + _path);
  }

  public nl.cwi.sen1.configapi.types.ItemLabels getLabels() {
     throw new UnsupportedOperationException("This Event has no Labels");
  }

  public Event setLabels(nl.cwi.sen1.configapi.types.ItemLabels _labels) {
     throw new IllegalArgumentException("Illegal argument: " + _labels);
  }

  public String getInfo() {
     throw new UnsupportedOperationException("This Event has no Info");
  }

  public Event setInfo(String _info) {
     throw new IllegalArgumentException("Illegal argument: " + _info);
  }

  public nl.cwi.sen1.configapi.types.ShortCut getShortcut() {
     throw new UnsupportedOperationException("This Event has no Shortcut");
  }

  public Event setShortcut(nl.cwi.sen1.configapi.types.ShortCut _shortcut) {
     throw new IllegalArgumentException("Illegal argument: " + _shortcut);
  }

}

