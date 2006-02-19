package toolbus.tool;

import java.io.File;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Vector;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.tool.classic.ClassicToolShield;
import toolbus.tool.java.JavaToolShield;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;

public class ToolDefinition {
	
	private ToolBus toolbus;
	
	private String toolName;

	private String hostName;

	private String command;
	
	private String className;

	private String kind;

	private ATermList inputSignature;

	private ATermList outputSignature;

	private TBTermFactory tbfactory;

	public ToolDefinition(String toolName, String host, String kind,
			String command, TBTermFactory tbfactory) {
		this.toolName = toolName;
		this.hostName = host;
		this.kind = kind;
		this.command = command;
		this.className = command;
		this.tbfactory = tbfactory;
		inputSignature = tbfactory.EmptyList;
		outputSignature = tbfactory.EmptyList;
	}
	
	public void setToolBus(ToolBus tb){
		toolbus = tb;
	}

	public String getHostName() {
		return hostName;
	}

	public String getKind() {
		return kind;
	}

	public String getName() {
		return toolName;
	}

	public ATermPlaceholder getNameAsPlaceholder() {
		ATerm t = tbfactory.make(toolName);
		return tbfactory.makePlaceholder(t);
	}
	
	public URL[] getLoadPath(){
		System.err.println("toolName = " + toolName);
		String path = toolbus.get(toolName + ".classpath");
		if(path == null){
			path = toolbus.get("java.classpath");
		}
		System.err.println("path = " + path);
		String[] elems = path.split("[ ,\n\r]+");
		Vector<URL> urls = new Vector<URL>(elems.length);
		String url = "";
		for(int i = 0; i < elems.length; i++){
			try {
				url = elems[i];
				if(url.length() > 0){
					if(url.charAt(0) == File.separatorChar){
						url = "file://" + url;
					}
					System.err.println("url = '" + url + "'");
					urls.add(new URL(url));
				}
			} catch (MalformedURLException e) {
				System.err.println("Malformed URL " + url + " ignored");
			}
		}
		return (URL[]) urls.toArray(new URL[urls.size()]);
	}
	
	private boolean usesJavaAdapter(){
		if(command.matches(".*java-adapter.*")){
			String[] words = command.split("[ \t\n\r]+");
			for(int i = 0; i < words.length; i++){
				String word = words[i];
				if(word.equals("-class") && i + 1 < words.length){
					className = words[i+1];
					System.err.println("-class followed by: " + className);
					return true;
				}
			}	
		}
		return false;
	}

	public String getCommand() {
		return (command);
	}
	
	public String getClassName(){
		return toolbus.get(toolName + ".class", className);
	}

	public ATermList getInputSignature() {
		return inputSignature;
	}

	public ATermList getOutputSignature() {
		return outputSignature;
	}

	public ATerm getSignature() {
		return tbfactory.make("signature(<term>,<term>))", inputSignature,
				outputSignature);
	}

	public void setToolSignatures(ATermList sigs) {
		boolean hasRecAckEvent = false;
		ATermPlaceholder toolPlaceholder = getNameAsPlaceholder();
		while (!sigs.isEmpty()) {
			ATermAppl sig = (ATermAppl) sigs.getFirst();
			sigs = sigs.getNext();
			//System.err.println("setToolSignatures: " + sig);
			if (sig.getArity() > 0) {
				ATerm ap = sig.getArgument(0);
				if (ap.equals(toolPlaceholder)) {
					if (sig.getName().equals("rec-ack-event")) {
						hasRecAckEvent = true;
					}
					if (sig.getName().equals("rec-eval")
							|| sig.getName().equals("rec-do")) {
						//|| sig.getName().equals("rec-ack-event") || sig.getName().equals("rec-terminate")){
						inputSignature = tbfactory
								.makeList(sig, inputSignature);
					} else if (sig.getName().equals("snd-event")) {
						outputSignature = tbfactory.makeList(sig,
								outputSignature);
					}
				}
			}
		}

		ATerm recTerminate = tbfactory.make("rec-terminate(<term>,<term>)",
				toolPlaceholder, tbfactory.TermPlaceholder);
		inputSignature = tbfactory.makeList(recTerminate, inputSignature);

		if (hasRecAckEvent) {
			ATerm recAckEvent = tbfactory.make("rec-ack-event(<term>,<term>)",
					toolPlaceholder, tbfactory.TermPlaceholder);
			inputSignature = tbfactory.makeList(recAckEvent, inputSignature);
		}

		ATerm sndConnect = tbfactory.make("snd-connect(<term>)",
				toolPlaceholder);
		outputSignature = tbfactory.makeList(sndConnect, outputSignature);
	}

	public ToolShield makeToolShield(ToolInstance ti) throws ToolBusException {
		if (kind == "java" || (kind == null && usesJavaAdapter()))
			return new JavaToolShield(this, ti);
		if (kind == "classic" || kind == null)
			return new ClassicToolShield(this, ti);

		throw new ToolBusException("Unknown tool kind:" + kind);
	}
}
