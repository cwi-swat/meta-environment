package toolbus.tool;

import aterm.ATermList;

public class ToolDefinition {
  private String toolName;
  private String hostName;
  private String command;
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
  
  public ToolDefinition(String toolName, String host, String kind, String command){
    this.toolName = toolName;
    this.hostName = host;
    this.restartFrequency = 0;
    this.internal = true;
    this.kind = kind;
    this.command = command;
    this.functionSignatures = null;
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

  public String getName() {
    return toolName;
  }
  
  public String getCommand(){
  	return command;
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
  
  public void setFunctionSignatures(ATermList sig){
    functionSignatures = sig;
  }

}
