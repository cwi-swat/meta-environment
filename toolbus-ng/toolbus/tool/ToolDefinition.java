package toolbus.tool;

import toolbus.TBTerm;
import toolbus.tool.classic.ClassicToolShield;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;

public class ToolDefinition {
  private String toolName;
  private String hostName;
  private String command;
  private int restartFrequency;
  private boolean internal;
  private String kind;
  private ATermList inputSignature;
  private ATermList outputSignature;
  
  public ToolDefinition(String toolName, String host, String kind, String command){
    this.toolName = toolName;
    this.hostName = host;
    this.restartFrequency = 0;
    this.internal = true;
    this.kind = kind;
    this.command = command;
    inputSignature = TBTerm.factory.makeList();
    outputSignature = TBTerm.factory.makeList();
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
  
  public ATermPlaceholder getNameAsPlaceholder(){
  	ATerm t = TBTerm.factory.make(toolName);
  	return (ATermPlaceholder) TBTerm.factory.makePlaceholder(t);
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
  
  public ATermList getInputSignature(){
    return inputSignature;
  }
  
  public ATermList getOutputSignature(){
    return outputSignature;
  }
  
  public void setToolSignatures(ATermList sigs){
  	ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
  	while (!sigs.isEmpty()) {
  		ATermAppl sig = (ATermAppl) sigs.getFirst();
  		sigs = sigs.getNext();
  		//System.err.println("setToolSignatures: " + sig);
  		if(sig.getArity() > 0){
  			ATerm ap = sig.getArgument(0);
  			if(ap.equals(toolPlaceholder)){
  				if( sig.getName().equals("Eval") || sig.getName().equals("Do") || sig.getName().equals("AckEvent") ||
  						sig.getName().equals("Terminate")){
  					inputSignature = TBTerm.factory.makeList(sig, inputSignature);
  				} else if( sig.getName().equals("Event")){
  					outputSignature = TBTerm.factory.makeList(sig, outputSignature);
  				}
  			}
  		}
  	}
  	
  	ATerm recTerminate = TBTerm.factory.make("rec-terminate(<term>)", toolPlaceholder);
  	inputSignature = TBTerm.factory.makeList(recTerminate, inputSignature);
  	
  	ATerm sndConnect = TBTerm.factory.make("snd-connect(<term>)", toolPlaceholder);
  	outputSignature = TBTerm.factory.makeList(sndConnect, outputSignature);
  }
  
  public ToolShield makeToolShield(ToolInstance ti){
  	if(kind == "java")
  		return new JavaToolShield(this, ti);
  	else if(kind == "classic")
  		return new ClassicToolShield(this, ti);
  	else
  		System.err.println("Unknown tool kind:" + kind);
  	return null;
  }
}
