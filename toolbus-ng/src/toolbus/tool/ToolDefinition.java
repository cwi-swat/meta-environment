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
	
	public ATerm getSignature(){
		return tbfactory.make("signature(<term>,<term>))", inputSignature, outputSignature);
	}
	
	public void setToolSignatures(ATermList sigs){
		if(signatureIsSet) return;
		
		ATermList signatures = sigs;
		ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
		while(!signatures.isEmpty()){
			ATermAppl sig = (ATermAppl) signatures.getFirst();
			signatures = signatures.getNext();
			if(sig.getArity() > 0){
				ATerm ap = sig.getArgument(0);
				if(ap.equals(toolPlaceholder)){
					if(sig.getName().equals("rec-eval") || sig.getName().equals("rec-do")){
						inputSignature = tbfactory.makeList(sig, inputSignature);
					}else if(sig.getName().equals("snd-event") || sig.getName().equals("snd-value")){
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
	
	private final static int LENSPECSIZE = 11;
	private final static char LENSPECSEPERATOR = ':';
	private final static int SIGNATURESIZE = 256 - 11 - 1 - 1;
	private final static char ENDOFENTRYLINE = '\0';
	
	private void appendSignature(ATermList signature, StringBuilder stringBuilder){
		ATermList empty = tbfactory.EmptyList;
		ATermList signatureList = signature;
		while(signatureList != empty){
			ATerm signatureEntry = signatureList.getFirst();
			
			String serializedSignatureEntry = signatureEntry.toString();
			int serializedSignatureEntrySize = serializedSignatureEntry.length();
			int shiftableSerializedSignatureEntrySize = serializedSignatureEntrySize;
			int i = LENSPECSIZE;
			int[] lenSpec = new int[i];
			do{
				lenSpec[--i] = shiftableSerializedSignatureEntrySize % 10;
				shiftableSerializedSignatureEntrySize /= 10;
			}while(shiftableSerializedSignatureEntrySize > 0);
			
			for(i = 0; i < LENSPECSIZE; i++){
				stringBuilder.append(lenSpec[i]);
			}
			stringBuilder.append(LENSPECSEPERATOR);
			stringBuilder.append(serializedSignatureEntry);
			stringBuilder.append(ENDOFENTRYLINE);
			
			for(i = SIGNATURESIZE - serializedSignatureEntrySize - 1; i >= 0; i--){
				stringBuilder.append(' ');
			}
			
			signatureList = signatureList.getNext();
		}
	}
	
	/**
	 * Generates the tifs for this tool in exactly the same way as the 'old' C toolbus did it.
	 * @return The generated tifs for this tool.
	 */
	public String generateTifs(){
		StringBuilder sb = new StringBuilder();
		
		appendSignature(inputSignature, sb);
		appendSignature(outputSignature, sb);
		appendSignature(otherSignature, sb);
		
		return sb.toString();
	}
	
	public ClassLoader createClassLoader(){
		return new URLClassLoader(getLoadPath());
	}
}
