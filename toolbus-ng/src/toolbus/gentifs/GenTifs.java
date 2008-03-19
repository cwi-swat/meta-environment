package toolbus.gentifs;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import aterm.ATerm;
import aterm.ATermList;
import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;

public class GenTifs{
	private final static int LENSPECSIZE = 11;
	private final static char LENSPECSEPERATOR = ':';
	private final static int SIGNATURESIZE = 127;
	private final static char ENDOFENTRYLINE = '\0';
	
	private final ToolBus toolBus;
	
	private final String outputFile;
	
	public GenTifs(String[] args){
		super();
		
		toolBus = new ToolBus(args);
		
		outputFile = toolBus.getProperty("gentifs.output");
		if(outputFile == null) throw new RuntimeException("No output file specified.");
		
		toolBus.parsecup();
	}
	
	private void writeToFile(byte[] data, String filename) throws IOException{
		FileOutputStream fos = null;
		try{
			fos = new FileOutputStream(new File(filename));
			fos.write(data);
		}finally{
			if(fos != null) fos.close();
		}
	}
	
	private void appendSignature(ATermList signature, StringBuilder stringBuilder){
		ATermList empty = toolBus.getTBTermFactory().EmptyList;
		ATermList signatureList = signature;
		while(signatureList != empty){
			ATerm signatureEntry = signatureList.getFirst();
			
			String serializedSignatureEntry = signatureEntry.toString();
			int serializedSignatureEntrySize = serializedSignatureEntry.length() + LENSPECSIZE + 1;
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
	 * Generates the tifs for the given tool definition in exactly the same way as the 'old' C
	 * toolbus did it.
	 * 
	 * @param toolDefinition
	 *            The tool definition to generate the tifs for.
	 * 
	 * @return The generated tifs for this tool.
	 */
	public String generateTifs(ToolDefinition toolDefinition){
		StringBuilder sb = new StringBuilder();
		
		appendSignature(toolDefinition.getInputSignature(), sb);
		appendSignature(toolDefinition.getOutputSignature(), sb);
		appendSignature(toolDefinition.getOtherSignature(), sb);
		
		return sb.toString();
	}
	
	public void generate() throws IOException{
		StringBuilder sb = new StringBuilder();
		
		List<ToolDefinition> toolDefinitions = toolBus.getToolDefinitions();
		Iterator<ToolDefinition> toolDefinitionsIterator = toolDefinitions.iterator();
		while(toolDefinitionsIterator.hasNext()){
			ToolDefinition toolDefinition = toolDefinitionsIterator.next();
			String tifsForTool = generateTifs(toolDefinition);
			sb.append(tifsForTool);
		}
		
		sb.append("00000000023:end-of-tifs\0                                                                                                        "); // This is stupid, but necessary :-/ .
		
		String allTifs = sb.toString();
		writeToFile(allTifs.getBytes(), outputFile);
	}
	
	public static void main(String[] args) throws IOException{
		GenTifs genTifs = new GenTifs(args);
		genTifs.generate();
	}
}
