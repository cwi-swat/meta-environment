package toolbus.tifs;

abstract public class Communication {
  private String name;
  
  public Communication() {
  }
  
  public Communication(String name) {
    setName(name);
  }
  
  public String getName() {
    return name;
  }

  private void setName(String name) {
    this.name = name;
  }
}
