package toolbus.tool;

import aterm.ATermList;

public class ToolDefinition {
  private String toolName;
  private String hostName;
  private int restartFrequency;
  private boolean internal;
  private String kind;
  private ATermList functionSignatures;

  public ToolDefinition(String toolName, ATermList functionSignatures) {
    this.toolName = toolName;
    this.hostName = "localhost";
    this.restartFrequency = 0;
    this.internal = true;
    this.kind = "java";
    this.functionSignatures = functionSignatures;
  }

  public String getHostName() {
    return hostName;
  }

  public boolean isInternal() {
    return internal;
  }

  public void setInternal(boolean internal) {
    this.internal = internal;
  }

  public String getKind() {
    return kind;
  }

  public String getToolName() {
    return toolName;
  }

  public int getRestartFrequency() {
    return restartFrequency;
  }

  public void setRestartFrequency(int restartFrequency) {
    this.restartFrequency = restartFrequency;
  }
  
  public ATermList getFunctionSignatures(){
    return functionSignatures;
  }

}
