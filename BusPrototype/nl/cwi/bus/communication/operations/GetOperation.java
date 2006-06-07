package nl.cwi.bus.communication.operations;

import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

import nl.cwi.bus.config.Config;
import nl.cwi.bus.variable.Variable;
import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.logging.Logger;

/**
 * Represents a get operation.
 * 
 * @author Arnold Lankamp
 */
public class GetOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.GET;
	
	private byte[] sourceToolIDBytes = null;
	private byte[] variableIDBytes = null;
	private byte[] targetToolIPBytes = null;
	private byte[] targetToolPortBytes = null;
	
	/**
	 * Default constructor.
	 */
	public GetOperation(){
		super();
		
		sourceToolIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		variableIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		targetToolIPBytes = new byte[NativeTypeBuilder.INTBYTES];
		targetToolPortBytes = new byte[NativeTypeBuilder.INTBYTES];
		
		init();
	}

	/**
	 * Constructor.
	 * 
	 * @param sourceToolID
	 *            The id of the 'source tool'.
	 * @param variableID
	 *            The for the 'source tool' unique variable identifier.
	 * @param targetToolAdress
	 *            The IP of the tool that wants to receive the variable.
	 */
	public GetOperation(long sourceToolID, long variableID, InetSocketAddress targetToolAdress){
		super();

		sourceToolIDBytes = NativeTypeBuilder.makeBytesFromLong(sourceToolID);
		variableIDBytes = NativeTypeBuilder.makeBytesFromLong(variableID);
		targetToolIPBytes = targetToolAdress.getAddress().getAddress();
		targetToolPortBytes = NativeTypeBuilder.makeBytesFromInt(targetToolAdress.getPort());
		
		init();
	}
	
	/**
	 * Initializes this operation.
	 */
	private void init(){
		registerNativeType(sourceToolIDBytes);
		registerNativeType(variableIDBytes);
		registerNativeType(targetToolIPBytes);
		registerNativeType(targetToolPortBytes);
	}

	/**
	 * Returns the type of operation.
	 * 
	 * @see AbstractOperation#getOperation()
	 * @return The type of operation.
	 */
	public String getOperation(){
		return OPERATION;
	}
	
	/**
	 * Returns the source tool id.
	 * 
	 * @return The source tool id.
	 */
	public long getSourceToolID(){
		return NativeTypeBuilder.makeLong(sourceToolIDBytes);
	}
	
	/**
	 * Returns the id of the variable.
	 * 
	 * @return The id of the variable.
	 */
	public long getVariableID(){
		return NativeTypeBuilder.makeLong(variableIDBytes);
	}

	/**
	 * Returns the hostname of the tool that is sending the request.
	 * 
	 * @return The hostname of the 'target tool'
	 */
	public InetAddress getTargetToolHost(){
		InetAddress targetHostAdress = null;
		try{
			targetHostAdress = InetAddress.getByAddress(targetToolIPBytes);
		}catch(UnknownHostException uhex){
			Logger.getInstance().log("Unable to obtain the ip adress of the local host", Logger.ERROR, uhex);
			throw new RuntimeException(uhex);
		}

		return targetHostAdress;
	}

	/**
	 * Returns the port number of the tool that is sending the request.
	 * 
	 * @return The port number of the 'target tool'
	 */
	public int getTargetToolPort(){
		return NativeTypeBuilder.makeInt(targetToolPortBytes);
	}

	/**
	 * Creates a get requests for the given variable.
	 * 
	 * @param variable
	 *            The variable for which the get request should be created.
	 * @return The created get request.
	 */
	public static GetOperation create(Variable variable){
		long sourceToolID = variable.getSourceToolID();
		long variableID = variable.getVariableID();

		InetSocketAddress targetHostAdress = null;
		try{
			targetHostAdress = new InetSocketAddress(InetAddress.getLocalHost(), Config.getUsingPort());
		}catch(UnknownHostException uhex){
			Logger.getInstance().log("Unable to obtain the ip adress of the local host", Logger.ERROR, uhex);
			throw new RuntimeException(uhex);
		}

		return new GetOperation(sourceToolID, variableID, targetHostAdress);
	}
}
