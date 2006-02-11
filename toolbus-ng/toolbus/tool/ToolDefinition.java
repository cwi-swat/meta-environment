package toolbus.tool;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.tool.classic.ClassicToolShield;
import toolbus.tool.java.JavaToolShield;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;

public class ToolDefinition {
	private String toolName;

	private String hostName;

	private String command;

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
		this.tbfactory = tbfactory;
		inputSignature = tbfactory.EmptyList;
		outputSignature = tbfactory.EmptyList;
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

	public String getCommand() {
		return command;
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
		if (kind == null || kind == "classic")
			return new ClassicToolShield(this, ti);
		if (kind == "java")
			return new JavaToolShield(this, ti);
		else
			throw new ToolBusException("Unknown tool kind:" + kind);
	}
}
