package toolbus.tool;

import toolbus.TBTermFactory;
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
    inputSignature = TBTermFactory.makeList();
    outputSignature = TBTermFactory.makeList();
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
  	ATerm t = TBTermFactory.make(toolName);
  	return (ATermPlaceholder) TBTermFactory.makePlaceholder(t);
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
  	boolean hasRecAckEvent = false;
  	ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
  	while (!sigs.isEmpty()) {
  		ATermAppl sig = (ATermAppl) sigs.getFirst();
  		sigs = sigs.getNext();
  		//System.err.println("setToolSignatures: " + sig);
  		if(sig.getArity() > 0){
  			ATerm ap = sig.getArgument(0);
  			if(ap.equals(toolPlaceholder)){
  				if(sig.getName().equals("rec-ack-event")){
  					hasRecAckEvent = true;
  				}
  				if( sig.getName().equals("rec-eval") || sig.getName().equals("rec-do") ){
  						//|| sig.getName().equals("rec-ack-event") || sig.getName().equals("rec-terminate")){
  					inputSignature = TBTermFactory.makeList(sig, inputSignature);
  				} else if( sig.getName().equals("snd-event")){
  					outputSignature = TBTermFactory.makeList(sig, outputSignature);
  				}
  			}
  		}
  	}
  	
  	ATerm recTerminate = TBTermFactory.make("rec-terminate(<term>,<term>)", toolPlaceholder, TBTermFactory.TermPlaceholder);
  	inputSignature = TBTermFactory.makeList(recTerminate, inputSignature);
  	
  	if(hasRecAckEvent){
  		ATerm recAckEvent = TBTermFactory.make("rec-ack-event(<term>,<term>)", toolPlaceholder, TBTermFactory.TermPlaceholder);
  		inputSignature = TBTermFactory.makeList(recAckEvent, inputSignature);
  	}
  	
  	ATerm sndConnect = TBTermFactory.make("snd-connect(<term>)", toolPlaceholder);
  	outputSignature = TBTermFactory.makeList(sndConnect, outputSignature);
  	
  }
  
  public ToolShield makeToolShield(ToolInstance ti, boolean alreadyExecuting){
  	if(kind == null || kind == "classic")
  		return new ClassicToolShield(this, ti, alreadyExecuting);
  	if(kind == "java")
  		return new JavaToolShield(this, ti); // TODO: add alreadyExecuting
  	else
  		System.err.println("Unknown tool kind:" + kind);
  	return null;
  }
}
