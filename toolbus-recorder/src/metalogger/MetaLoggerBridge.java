package metalogger;
// Java tool bridge LoggerBridge
// This file is generated automatically, please do not edit!
// generation time: Apr 12, 2005 3:16:09 PM

import java.io.IOException;
import java.io.InputStream;
import java.util.Vector;
import aterm.*;

public class MetaLoggerBridge extends MetaLoggerTool{
  private MetaLoggerTif tool;
	private final static int LENSPEC = 12;
	private final static int MAX_HANDSHAKE = 512;
	private final static int MIN_MSG_SIZE = 128;	
	private Vector bafTable = new Vector();
	
  //{{{  public LoggerBridge(ATermFactory factory, LoggerTif tool)
  public MetaLoggerBridge(ATermFactory factory, MetaLoggerTif tool)
  {
    super(factory);
    this.tool = tool;
  }
  //}}}
  //{{{  public void recMonitor(ATerm t0)
  public ATerm recMonitor(ATerm t0)
  {
    if (tool != null) {
      return tool.recMonitor(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recMonitor' not supported.");
    }
  }
  //}}}
  //{{{  public void recTerminate(ATerm t0)
  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }
  public ATerm readTerm(InputStream inputStream, ATermFactory factory, Object lock) throws IOException {
	ATerm result;
	byte[] lspecBuf = new byte[LENSPEC];
	int index;
	
	index = 0;
	while (index != LENSPEC) {
		int bytes_read = inputStream.read(lspecBuf, index, LENSPEC - index);
		if (bytes_read <= 0) {
			throw new IOException("ToolBus connection terminated");
		}
		index += bytes_read;
	}
	String lspec = new String(lspecBuf);
	int bytesLeft = Integer.parseInt(lspec.substring(0, LENSPEC - 1));
	if (bytesLeft < MIN_MSG_SIZE) {
		bytesLeft = MIN_MSG_SIZE;
	}
	bytesLeft -= LENSPEC;

	byte[] data = new byte[bytesLeft];
	index = 0;
	while (index != bytesLeft) {
		int bytes_read = inputStream.read(data, index, bytesLeft - index);
		if (bytes_read <= 0) {
			throw new IOException("ToolBus connection terminated");
		}
		index += bytes_read;
	}

	String stringdata = new String(data);

	//info("data read (" + bytesLeft + " bytes): '" + stringdata + "'");
	if(stringdata.indexOf("\"_baf-encoded_\"(\"")!=-1){
		stringdata = replaceBaf(stringdata, factory);
	}
	try{
	result = factory.parse(stringdata);
	}
	catch(Exception e){
	System.out.println(stringdata);	
	result = null;
	}
	return result;
}

public String replaceBaf(String stringdata, ATermFactory factory){
	int beginBaf, endBaf, endBaf1, endBaf2, hashcode, tempPlace;
	String hashstring;
	beginBaf = stringdata.indexOf("\"_baf-encoded_\"(\"");
	tempPlace = stringdata.indexOf("],[",beginBaf);
	if(tempPlace ==-1)
		tempPlace = stringdata.indexOf("\"),",beginBaf);
	endBaf = stringdata.lastIndexOf("\"",tempPlace+1);
	try{
		hashstring = stringdata.substring(beginBaf+17, endBaf);
		hashcode = hashstring.hashCode();
		addBaf(hashcode,hashstring);
		stringdata = stringdata.substring(0,beginBaf) + "\"_baf-recoded_\"(\"" + hashcode + stringdata.substring(endBaf, stringdata.length());
		if(stringdata.indexOf("\"_baf-encoded_\"(\"")!=-1){
			stringdata = replaceBaf(stringdata, factory);
		}
	}
	catch(Exception e){
		System.out.println("term:\n\n" + stringdata);
	}	
	return stringdata;
}
public void addBaf(int hashcode, String hashstring){
	ATermBaf bafpart;
	boolean containsBaf = false;
	for(int i = 0; i < bafTable.size(); i++){
		bafpart =(ATermBaf)bafTable.get(i);
		if(bafpart.isEqual(hashcode)){
			containsBaf = true;
		}
	}
	if(containsBaf==false){
		bafTable.add(new ATermBaf(hashcode, hashstring));
	}
}
public String getBaf(int hashcode){
	ATermBaf bafpart;
	for(int i = 0; i < bafTable.size(); i++){
		bafpart =(ATermBaf)bafTable.get(i);
		if(bafpart.isEqual(hashcode)){
			return bafpart.getATermvalue();
		}
	}
	return null;
}
}
