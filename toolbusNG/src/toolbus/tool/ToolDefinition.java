package toolbus.tool;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.List;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;

public class ToolDefinition{
	private ToolBus toolbus;
	
	private final String toolName;
	
	private final String hostName;
	
	private final String command;
	
	private final String className;
	
	private final String kind;
	
	private ATermList inputSignature;
	private ATermList outputSignature;
	
	private final TBTermFactory tbfactory;
	
	private final ATerm posInfo;
	
	public ToolDefinition(String toolName, String host, String kind, String command, String className, TBTermFactory tbfactory, ATerm posInfo){
		this.toolName = toolName;
		this.hostName = host;
		this.kind = kind;
		this.command = command;
		this.className = className;
		this.tbfactory = tbfactory;
		this.posInfo = posInfo;
		
		inputSignature = tbfactory.EmptyList;
		outputSignature = tbfactory.EmptyList;
	}
	
	public boolean isDirectlyStartableJavaNGTool(){
		return ("javaNG".equals(kind) && (hostName == null || hostName == "localhost"));
	}
	
	public void setToolBus(ToolBus tb){
		toolbus = tb;
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
	
	public ATerm getPosInfo(){
		return posInfo;
	}
	
	public ATermList getInputSignature(){
		return inputSignature;
	}
	
	public ATermList getOutputSignature(){
		return outputSignature;
	}
	
	public ATerm getSignature(){
		return tbfactory.make("signature(<term>,<term>))", inputSignature, outputSignature);
	}
	
	public void setToolSignatures(ATermList sigs){
		ATermList signatures = sigs;
		ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
		while(!signatures.isEmpty()){
			ATermAppl sig = (ATermAppl) signatures.getFirst();
			signatures = signatures.getNext();
			if(sig.getArity() > 0){
				ATerm ap = sig.getArgument(0);
				if(ap.equals(toolPlaceholder)){
					if(sig.getName().equals("rec-eval") || sig.getName().equals("rec-do")){
						inputSignature = tbfactory.makeList(tbfactory.makeAppl(tbfactory.makeAFun(sig.getName(), 1, false), sig.getArgument(1)), inputSignature);
					}else if(sig.getName().equals("snd-event")){
						outputSignature = tbfactory.makeList(tbfactory.makeAppl(tbfactory.makeAFun(sig.getName(), 1, false), sig.getArgument(1)), outputSignature);
					}
				}
			}
		}
	}
	
	public ClassLoader createClassLoader(){
		return new URLClassLoader(getLoadPath());
	}
}
