package toolbus.viewer;

import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.ArrayList;
import java.util.List;
import toolbus.ToolBus;
import toolbus.util.collections.ConcurrentHashMap;

/**
 * This store provides access to all, for the ToolBus, reachable source code. Additionally it
 * caches the already loaded code.
 * 
 * @author Arnold Lankamp
 */
public class ScriptCodeStore{
	private final ToolBus toolbus;
	private final ConcurrentHashMap<String, byte[]> scriptCodeCache;
	
	/**
	 * Constructor.
	 * 
	 * @param toolbus
	 *            The ToolBus with which this store will be associated.
	 */
	public ScriptCodeStore(ToolBus toolbus){
		super();
		
		this.toolbus = toolbus;
		
		scriptCodeCache = new ConcurrentHashMap<String, byte[]>();
	}
	
	/**
	 * Returns the list of absolute paths to all, for the ToolBus, reachable scripts. Returns null
	 * in case the scripts haven't been parsed yet.
	 * 
	 * @return The list of absolute paths to all, for the ToolBus, reachable scripts; null in case
	 * the scripts haven't been parsed yet.
	 */
	public String[] getScriptNames(){
		return toolbus.getIncludedScripts();
	}
	
	/**
	 * Retrieves the source code of the script indicated by the given path.
	 * 
	 * @param scriptPath
	 *            The path to the script we want to load.
	 * @return The retrieved source code of the script.
	 * @throws IOException Thrown when something I/O related goes wrong (obviously).
	 */
	public byte[] getCode(String scriptPath) throws IOException{
		byte[] scriptCode = scriptCodeCache.get(scriptPath);
		if(scriptCode != null) return scriptCode;
		
		File scriptFile = new File(scriptPath);
		if(!scriptFile.exists() || !scriptFile.isFile()) throw new IOException("No such script file: "+scriptPath);
		
		int fileSize = (int) scriptFile.length();
		scriptCode = new byte[fileSize];
		
		FileInputStream fis = new FileInputStream(scriptFile);
		FileChannel fc = fis.getChannel();
		
		ByteBuffer byteBuffer = ByteBuffer.wrap(scriptCode);
		try{
			fc.read(byteBuffer);
		}finally{
			try{
				fc.close();
			}finally{
				fis.close();
			}
		}
		
		scriptCodeCache.put(scriptPath, scriptCode); // Put the retrieved code in the cache.
		
		return scriptCode;
	}
}
