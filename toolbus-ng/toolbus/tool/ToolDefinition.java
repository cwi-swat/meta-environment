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
  private TBTermFactory tbfactory;
  
  public ToolDefinition(String toolName, String host, String kind, String command, TBTermFactory tbfactory){
    this.toolName = toolName;
    this.hostName = host;
    this.restartFrequency = 0;
    this.internal = true;
    this.kind = kind;
    this.command = command;
    this.tbfactory = tbfactory;
    inputSignature = tbfactory.EmptyList;
    outputSignature = tbfactory.EmptyList;
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
  	ATerm t = tbfactory.make(toolName);
  	return tbfactory.makePlaceholder(t);
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
  					inputSignature = tbfactory.makeList(sig, inputSignature);
  				} else if( sig.getName().equals("snd-event")){
  					outputSignature = tbfactory.makeList(sig, outputSignature);
  				}
  			}
  		}
  	}
  	
  	ATerm recTerminate = tbfactory.make("rec-terminate(<term>,<term>)", toolPlaceholder, tbfactory.TermPlaceholder);
  	inputSignature = tbfactory.makeList(recTerminate, inputSignature);
  	
  	if(hasRecAckEvent){
  		ATerm recAckEvent = tbfactory.make("rec-ack-event(<term>,<term>)", toolPlaceholder, tbfactory.TermPlaceholder);
  		inputSignature = tbfactory.makeList(recAckEvent, inputSignature);
  	}
  	
  	ATerm sndConnect = tbfactory.make("snd-connect(<term>)", toolPlaceholder);
  	outputSignature = tbfactory.makeList(sndConnect, outputSignature);
  	
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
