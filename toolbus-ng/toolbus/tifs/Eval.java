package toolbus.tifs;

public class Eval extends Communication {
  private String resultType;
  
  public Eval(String name, String resultType) {
    super(name);
    setResultType(resultType);
  }
  
  public String getResultType() {
    return resultType;
  }

  private void setResultType(String resultType) {
    this.resultType = resultType;
  }
}
