package toolbus.gentifs;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermList;

public class GenTifsNG{
	private final ToolBus toolBus;
	private final TBTermFactory factory;
	
	private final String outputFile;
	
	public GenTifsNG(String[] args){
		super();
		
		toolBus = new ToolBus(args);
		factory = toolBus.getTBTermFactory();
		
		outputFile = toolBus.getProperty("gentifs.output");
		if(outputFile == null) throw new RuntimeException("No output file specified.");
		
		toolBus.parsecup();
	}
	
	public void generate() throws IOException{
		AFun toolSignatureFun = factory.makeAFun("toolSignature", 4, false);
		ATermList signatures = factory.EmptyList;
		
		List<ToolDefinition> toolDefinitions = toolBus.getToolDefinitions();
		Iterator<ToolDefinition> toolDefinitionsIterator = toolDefinitions.iterator();
		while(toolDefinitionsIterator.hasNext()){
			ToolDefinition toolDefinition = toolDefinitionsIterator.next();
			
			ATerm toolName = factory.makeAppl(factory.makeAFun(toolDefinition.getName(), 0, true));
			signatures = factory.makeList(factory.makeAppl(toolSignatureFun, toolName, toolDefinition.getInputSignature(), toolDefinition.getOutputSignature(), toolDefinition.getOtherSignature()), signatures);
		}
		
		FileOutputStream fos = new FileOutputStream(outputFile);
		try{
			signatures.writeToTextFile(fos);
		}finally{
			fos.close();
		}
	}
	
	public static void main(String[] args) throws IOException{
		GenTifsNG genTifsNG = new GenTifsNG(args);
		genTifsNG.generate();
	}
}
