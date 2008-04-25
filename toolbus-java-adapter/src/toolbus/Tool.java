package toolbus;

import java.io.IOException;
import java.net.InetAddress;
import java.net.UnknownHostException;

import aterm.ATerm;
import aterm.ATermList;

public interface Tool{
	public void init(String[] args) throws UnknownHostException;
	
	public void setLockObject(Object obj);
	
	public Object getLockObject();
	
	public void connect() throws IOException;
	
	public void connect(String tool_name, InetAddress address, int p) throws IOException;
	
	public void disconnect();
	
	public boolean isConnected();
	
	public void checkInputSignature(ATermList sig);
	
	public ATerm handler(ATerm term);
	
	public void sendTerm(ATerm term) throws IOException;
	
	public void sendEvent(ATerm term);
	
	public void postEvent(ATerm term);
	
	public ATerm postRequest(ATerm term);
}
