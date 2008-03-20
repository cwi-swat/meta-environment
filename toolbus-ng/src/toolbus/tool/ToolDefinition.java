package toolbus.tool;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;

public class ToolDefinition{
	private final ToolBus toolbus;
	private final TBTermFactory tbfactory;
	
	private final String toolName;
	private final String hostName;
	private final String command;
	private final String className;
	private final String kind;
	
	private volatile boolean signatureIsSet = false;
	
	private ATermList inputSignature;
	private ATermList outputSignature;
	private ATermList otherSignature;
	
	public ToolDefinition(String toolName, String host, String kind, String command, String className, ToolBus toolbus){
		this.toolName = toolName;
		this.hostName = host;
		this.kind = kind;
		this.command = command;
		this.className = className;
		this.toolbus = toolbus;
		this.tbfactory = toolbus.getTBTermFactory();
		
		inputSignature = tbfactory.EmptyList;
		outputSignature = tbfactory.EmptyList;
		otherSignature = tbfactory.EmptyList;
	}
	
	public boolean isDirectlyStartableJavaNGTool(){
		return false;//return ("javaNG".equals(kind) && (hostName == null || hostName == "localhost"));
	}
	
	public String getHostName(){
		return hostName;
	}
	
	public String getKind(){
		return kind;
	}
	
	public String getName(){
		return toolName;
	}
	
	public ATermPlaceholder getNameAsPlaceholder(){
		ATerm t = tbfactory.make(toolName);
		return tbfactory.makePlaceholder(t);
	}
	
	public URL[] getLoadPath(){
		// System.err.println("toolName = " + toolName);
		String path = toolbus.getProperty(toolName + ".classpath");
		if(path == null){
			path = toolbus.getProperty("java.classpath");
		}
		// System.err.println("path = " + path);
		String[] elems = path.split("[ ,\n\r]+");
		List<URL> urls = new ArrayList<URL>(elems.length);
		String url = "";
		for(int i = 0; i < elems.length; i++){
			try{
				url = elems[i];
				if(url.length() > 0){
					if(url.charAt(0) == File.separatorChar){
						url = "file://" + url;
					}
					// System.err.println("url = '" + url + "'");
					urls.add(new URL(url));
				}
			}catch(MalformedURLException e){
				System.err.println("Malformed URL " + url + " ignored");
			}
		}
		return urls.toArray(new URL[urls.size()]);
	}
	
	public String getCommand(){
		return command;
	}
	
	public String getClassName(){
		return className;
	}
	
	public ATermList getInputSignature(){
		return inputSignature;
	}
	
	public ATermList getOutputSignature(){
		return outputSignature;
	}
	
	public ATermList getOtherSignature(){
		return otherSignature;
	}
	
	public ATerm getSignature(){
		return tbfactory.make("signature(<term>, <term>, <term>))", inputSignature, outputSignature, otherSignature);
	}
	
	public void calculateToolSignature(List<ATermAppl> atoms){
		if(signatureIsSet) return;
		
		ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
		
		Iterator<ATermAppl> atomsIterator = atoms.iterator();
		while(atomsIterator.hasNext()){
			ATermAppl sig = atomsIterator.next();
			if(sig.getArity() > 0){
				ATerm ap = sig.getArgument(0);
				if(ap.equals(toolPlaceholder)){
					if(sig.getName().equals("rec-eval") || sig.getName().equals("rec-do")){
						inputSignature = tbfactory.makeList(sig, inputSignature);
					}else if(sig.getName().equals("snd-event") || sig.getName().equals("snd-value") || sig.getName().equals("rec-ack-event")){
						outputSignature = tbfactory.makeList(sig, outputSignature);
					}else if(sig.getName().equals("snd-connect") || sig.getName().equals("snd-disconnect")){
						otherSignature = tbfactory.makeList(sig, otherSignature);
					}
				}
			}
		}
		
		otherSignature = tbfactory.makeList(tbfactory.parse("rec-terminate(<"+toolName+">, <term>)"), otherSignature);
		
		signatureIsSet = true;
	}
	
	public ClassLoader createClassLoader(){
		return new URLClassLoader(getLoadPath());
	}
}
