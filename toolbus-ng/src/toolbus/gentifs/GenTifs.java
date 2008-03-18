package toolbus.gentifs;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import toolbus.ToolBus;
import toolbus.tool.ToolDefinition;

public class GenTifs{
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
	
	public void generate() throws IOException{
		StringBuilder sb = new StringBuilder();
		
		List<ToolDefinition> toolDefinitions = toolBus.getToolDefinitions();
		Iterator<ToolDefinition> toolDefinitionsIterator = toolDefinitions.iterator();
		while(toolDefinitionsIterator.hasNext()){
			ToolDefinition toolDefinition = toolDefinitionsIterator.next();
			String tifsForTool = toolDefinition.generateTifs();
			sb.append(tifsForTool);
		}
		
		sb.append("00000000023:end-of-tifs");
		
		String allTifs = sb.toString();
		writeToFile(allTifs.getBytes(), outputFile);
	}
	
	public static void main(String[] args) throws IOException{
		GenTifs genTifs = new GenTifs(args);
		genTifs.generate();
	}
}
