package toolbus.parser;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import aterm.ATerm;

/**
 * Provide access to an external parser. Used to call sglr and implode-asfix. Code borrowed from
 * JJForester and adapted/extended
 */
public class ExternalParser{
	private static long filenameCounter = System.currentTimeMillis();
	
	private final String parseCommand;
	private final String implodeCommand;
	private final String implodeOptions = "-tlILXpcO";
	private final String addPosInfoCommand;
	
	public ExternalParser(ToolBus toolbus){
		this.parseCommand = toolbus.getProperty("sglr.path") + " -p " + toolbus.getProperty("parsetable.path");
		this.implodeCommand = toolbus.getProperty("implodePT.path") + " " + implodeOptions;
		this.addPosInfoCommand = toolbus.getProperty("addPosInfo.path");
	}
	
	/**
	 * Parse the source file with the given name in an ATerm that represents its abstract syntax
	 * tree.
	 * 
	 * @param tbfactory
	 *            TODO
	 */
	public ATerm parse(String sourceFileName, TBTermFactory tbfactory) throws ExternalProcessException{
		ATerm result;
		String asfixFileName1 = getNewFileName("asfix");
		String asfixFileName2 = getNewFileName("asfix");
		execute(parseCommand, sourceFileName, asfixFileName1, "parse");
		execute(addPosInfoCommand + " -p " + sourceFileName, asfixFileName1, asfixFileName2, "parse");
		InputStream in = execute(implodeCommand, asfixFileName2, "implode");
		try{
			result = tbfactory.readFromTextFile(in);
		}catch(IOException e){
			throw new ExternalProcessException(e.getMessage(), "read ATerm from file");
		}
		delete(asfixFileName1);
		//delete(asfixFileName2); <-- Enabling this line causes an exception to occur
		return result;
	}
	
	/**
	 * Execute the given command where the given files are supplied as input and output.
	 */
	private static void execute(String command, String inFileName, String outFileName, String processType) throws ExternalProcessException{
		String commandLine = command + " -i " + inFileName + " -o " + outFileName;
		Process p = execute(commandLine, processType);
		waitForExternalResult(p, "ToolBus: external process failed to produce a result", processType);
	}
	
	/**
	 * Execute the given command where the given file is supplied as input, and the output is
	 * connected to the InputStream that is returned.
	 */
	private static InputStream execute(String command, String inFileName, String processType) throws ExternalProcessException{
		String commandLine = command + " -i " + inFileName;
		Process p = execute(commandLine, processType);
		return p.getInputStream();
	}
	
	/**
	 * Execute the given command and return the process object that is running it.
	 */
	private static Process execute(String command, String processType) throws ExternalProcessException{
		// System.err.println("ToolBus: executing external command:");
		// System.err.println(" " + command);
		try{
			return Runtime.getRuntime().exec(command);
		}catch(IOException e){
			throw new ExternalProcessException(e.getMessage(), processType);
		}
	}
	
	/**
	 * Generate a new, unique name for a temporary file.
	 */
	private static String getNewFileName(String str){
		return "/tmp/toolbus." + str + "." + (++filenameCounter);
	}
	
	// TODO Fix; this code locks the application in case the output/error stream buffer gets filled.
	/**
	 * Block the current thread until the given process has terminated. Throw an
	 * ExternalProcessException on abnormal termination.
	 */
	private static void waitForExternalResult(Process p, String msg, String processType) throws ExternalProcessException{
		int result;
		try{
			result = p.waitFor();
		}catch(InterruptedException e){
			throw new ExternalProcessException(e.getMessage(), processType);
		}
		if(result != 0){
			try{
				copyErrorStream(p);
			}catch(java.io.IOException e){
				throw new ExternalProcessException(msg, processType);
			}
			throw new ExternalProcessException(msg, processType);
		}
	}
	
	// TODO Fix; this code is 'dangerous', because it can trigger and arrayOutOfBounds exception.
	private static void copyErrorStream(Process p) throws IOException{
		byte[] b = new byte[10240];
		InputStream err = p.getErrorStream();
		int read;
		while((read = err.read(b)) >= 0){
			System.err.write(b, 0, read);
		}
	}
	
	private static void delete(String filename){
		File f = new File(filename);
		if(!f.exists()) fail("delete: no such file or directory: " + filename);
		if(!f.canWrite()) fail("delete: write protected: " + filename);
		if(f.isDirectory()){
			String[] files = f.list();
			if(files.length > 0) fail("delete: directory not empty: " + filename);
		}
		if(!f.delete()) fail("delete: deletion failed: " + filename);
	}
	
	private static void fail(String msg){
		throw new IllegalArgumentException(msg);
	}
}
