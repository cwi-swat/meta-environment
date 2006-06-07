package nl.cwi.bus.communication.operations;

import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.bus.variable.Variable;
import nl.cwi.bus.variable.VariableHandler;
import nl.cwi.term.serializable.AbstractTerm;
import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.term.serializable.TermConverter;
import nl.cwi.util.IDGenerator;
import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.logging.Logger;

/**
 * Represents a put operation.
 * 
 * @author Arnold Lankamp
 */
public class PutOperation extends AbstractOperation{
	private final static String OPERATION = AbstractOperation.PUT;
	
	private byte[] transactionID = null;
	             
	private byte[] sourceToolIDBytes = null;
	private byte[] sourceToolIPBytes = null;
	private byte[] sourceToolPortBytes = null;
	private byte[] variableIDBytes = null;
	private AbstractTerm signatureTerm = null;
	private TermConverter dataTermConverter = null;

	/**
	 * Default constructor.
	 */
	public PutOperation(){
		super();
		
		transactionID = new byte[NativeTypeBuilder.LONGBYTES];
		
		sourceToolIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		sourceToolIPBytes = new byte[NativeTypeBuilder.INTBYTES];
		sourceToolPortBytes = new byte[NativeTypeBuilder.INTBYTES];
		variableIDBytes = new byte[NativeTypeBuilder.LONGBYTES];
		signatureTerm = new SerializableStringTerm();
		dataTermConverter = new TermConverter();
		
		init();
	}
	
	/**
	 * Constructor.
	 * 
	 * @param sourceToolID
	 *            The id of the 'source tool'.
	 * @param sourceToolAdress
	 *            The adress of the tool that is in possesion of the value of
	 *            the variable.
	 * @param variableID
	 *            The for the 'source tool' unique variable identifier.
	 * @param signature
	 *            The (ATerm) signature of the data.
	 * @param data
	 *            The value of the variable (this is optional. Set to null if
	 *            this is a reference).
	 */
	public PutOperation(long sourceToolID, InetSocketAddress sourceToolAdress, long variableID, String signature, AbstractTerm data){
		super();

		setState(sourceToolID, sourceToolAdress, variableID, signature, data);
		
		init();
	}

	/**
	 * Convience contructor. The data will be stripped from the variable if it
	 * acceeds the threshold.
	 * 
	 * @param variable
	 *            The variable to use for constructing this put operation.
	 */
	public PutOperation(Variable variable){
		super();

		long variableID = variable.getVariableID();
		long sourceToolID = variable.getSourceToolID();
		InetSocketAddress sourceToolAdress = variable.getSourceToolAdress();
		String signature = variable.getSignature();
		AbstractTerm data = null;
		if(!variable.acceedsThreshold()) data = variable.getData();

		setState(sourceToolID, sourceToolAdress, variableID, signature, data);
		
		init();
	}

	/**
	 * Sets the instance variables, based on the given input.
	 * 
	 * @param sourceToolID
	 *            The id of the 'source tool'.
	 * @param sourceToolAdress
	 *            The adress of the tool that is in possesion of the value of
	 *            the variable.
	 * @param variableID
	 *            The for the 'source tool' unique variable identifier.
	 * @param signature
	 *            The (ATerm) signature of the data.
	 * @param data
	 *            The value of the variable (this is optional. Set to null if
	 *            this is a reference).
	 */
	private void setState(long sourceToolID, InetSocketAddress sourceToolAdress, long variableID, String signature, AbstractTerm data){
		transactionID = NativeTypeBuilder.makeBytesFromLong(IDGenerator.generate());
		
		sourceToolIDBytes = NativeTypeBuilder.makeBytesFromLong(sourceToolID);
		sourceToolIPBytes = sourceToolAdress.getAddress().getAddress();
		sourceToolPortBytes = NativeTypeBuilder.makeBytesFromInt(sourceToolAdress.getPort());
		variableIDBytes = NativeTypeBuilder.makeBytesFromLong(variableID);
		signatureTerm = new SerializableStringTerm(signature);
		if(data != null){
			dataTermConverter = new TermConverter(data);
		}else{
			dataTermConverter = new TermConverter(new SerializableStringTerm(null));
		}
	}
	
	/**
	 * Initializes this operation.
	 */
	private void init(){
		registerNativeType(transactionID);
		
		registerNativeType(sourceToolIDBytes);
		registerNativeType(sourceToolIPBytes);
		registerNativeType(sourceToolPortBytes);
		registerNativeType(variableIDBytes);
		register(signatureTerm);
		register(dataTermConverter);
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
	 * Retruns the transactionID associated with this put message.
	 * @return The transactionID associated with this put message.
	 */
	public long getTransactionID(){
		return NativeTypeBuilder.makeLong(transactionID);
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
	 * Returns the hostname of the machine the tool that is in possesion of the
	 * value of the variable is running on.
	 * 
	 * @return The hostname of the machine the 'source tool' is running on.
	 */
	public InetAddress getSourceToolHost(){
		InetAddress targetHostAdress = null;
		try{
			targetHostAdress = InetAddress.getByAddress(sourceToolIPBytes);
		}catch(UnknownHostException uhex){
			Logger.getInstance().log("Unable to obtain the ip adress of the local host", Logger.ERROR, uhex);
			throw new RuntimeException(uhex);
		}

		return targetHostAdress;
	}

	/**
	 * Returns the port number on which the tool that is in possesion of the
	 * value of the variable is reachable on.
	 * 
	 * @return The port number on which the 'source tool' is reachable.
	 */
	public int getSourceToolPort(){
		return NativeTypeBuilder.makeInt(sourceToolPortBytes);
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
	 * Returns the (ATerm) signature of the variable.
	 * 
	 * @return The (ATerm) signature.
	 */
	public String getSignature(){
		return new String(signatureTerm.getContent());
	}
	
	/**
	 * Returns the value of the variable.
	 * 
	 * @return The value of the variable.
	 */
	public AbstractTerm getData(){
		return dataTermConverter.getTerm();
	}

	/**
	 * Constructs a variable from the data present in this put operation.
	 * 
	 * @return The constructed variable.
	 */
	public Variable createVariable(){
		long variableID = getVariableID();
		String signature = getSignature();
		AbstractTerm data = getData();
		InetSocketAddress sourceToolAdress = new InetSocketAddress(getSourceToolHost(), getSourceToolPort());
		long sourceToolID = getSourceToolID();

		return new Variable(variableID, signature, data, sourceToolAdress, sourceToolID);
	}

	/**
	 * Creates a put operation for the given variable.
	 * 
	 * @param variable
	 *            The variable for which the put operation should be created.
	 * @return The created put operation.
	 */
	public static PutOperation create(Variable variable){
		long sourceToolID = variable.getSourceToolID();
		long variableID = variable.getVariableID();
		InetSocketAddress sourceToolAdress = variable.getSourceToolAdress();
		String signature = variable.getSignature();
		AbstractTerm data = variable.getData();

		return new PutOperation(sourceToolID, sourceToolAdress, variableID, signature, data);
	}

	/**
	 * Creates a put operation for the given variable of which the data has been
	 * stripped in case the threshold was acceeded.
	 * 
	 * @param variable
	 *            The variable for which the put operation should be created.
	 * @return The created put operation.
	 */
	public static PutOperation createStripped(Variable variable){
		long sourceToolID = variable.getSourceToolID();
		long variableID = variable.getVariableID();
		InetSocketAddress sourceToolAdress = variable.getSourceToolAdress();
		String signature = variable.getSignature();
		AbstractTerm data = null;
		if(variable.acceedsThreshold()){
			VariableHandler variableHandler = ToolRegistery.getInstance().getVariableHandler();
			variableHandler.add(variable);
		}else{
			data = variable.getData();
		}

		return new PutOperation(sourceToolID, sourceToolAdress, variableID, signature, data);
	}
}
