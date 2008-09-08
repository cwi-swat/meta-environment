package toolbus.adapter;

import java.nio.ByteBuffer;

import jjtraveler.VisitFailure;
import toolbus.IOperations;
import toolbus.TBTermFactory;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermBlob;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.pure.PureFactory;
import aterm.pure.binary.BinaryReader;
import aterm.pure.binary.BinaryWriter;

/**
 * This class facilitates the functions a tool needs to be able to functions.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractTool implements IOperations{
	protected final static PureFactory termFactory = TBTermFactory.getInstance();

	public final static String DIRECTTOOL = "direct";
	public final static String REMOTETOOL = "remote";
	
	private final static int PACKBUFFERSIZE = 65536;
	private final static AFun SYMBOL_SAF = termFactory.makeAFun("saf-encoded", 1, false);

	/**
	 * This variable MUST be set before tool interaction can take place.
	 */
	protected ToolBridge toolBridge = null;

	/**
	 * Default constructor.
	 */
	public AbstractTool(){
		super();
	}

	/**
	 * Connects to the ToolBus.
	 * 
	 * @param args
	 *            The arguments that contain the required information for running a tool (name + id
	 *            and additionally the host + port of the ToolBus, depending on how this tool is
	 *            connected to the ToolBus).
	 * @throws Exception
	 *             Thrown when something goes wrong during the parsing of the arguments or the
	 *             establishing of the connection.
	 */
	public abstract void connect(String[] args) throws Exception;
	
	/**
	 * Sets the reference ot the tool bridge we're using.
	 * 
	 * @param toolBridge
	 *            The reference ot the tool bridge we're using.
	 */
	public void setToolBridge(ToolBridge toolBridge){
		this.toolBridge = toolBridge;
	}

	/**
	 * Returns a reference to the tool bridge that we're using.
	 * 
	 * @return A reference to the tool bridge that we're using.
	 */
	public ToolBridge getToolBridge(){
		return toolBridge;
	}

	/**
	 * Returns a reference to the aterm factory.
	 * 
	 * @return A reference to the aterm factory.
	 */
	public static PureFactory getFactory(){
		return termFactory;
	}

	/**
	 * Posts an event to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains the data about the event.
	 */
	public void sendEvent(ATerm aTerm){
		toolBridge.postEvent(aTerm);
	}
	
	/**
	 * Posts a request to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains the data about the request.
	 * @return The response.
	 */
	public ATermAppl sendRequest(ATerm aTerm){
		return toolBridge.postRequest(aTerm);
	}

	/**
	 * Sends a disconnect request to the ToolBus.
	 * 
	 * @param aTerm
	 *            The term that contains information about the event.
	 */
	public void disconnect(ATerm aTerm){
		toolBridge.send(DISCONNECT, aTerm);
	}

	/**
	 * Terminated this Tool.
	 */
	public void terminate(){
		toolBridge.terminate();
	}
	
	/**
	 * Receives an acknowledgement message.
	 * 
	 * @param aTerm
	 *            The term containing information about the acknowledgement.
	 */
	public abstract void receiveAckEvent(ATerm aTerm);

	/**
	 * Receives a termination message.
	 * 
	 * @param aTerm
	 *            The term containing information about the termination.
	 */
	public abstract void receiveTerminate(ATerm aTerm);
	
	/**
	 * Packs the given term.
	 * 
	 * @param termData
	 *            The term that needs to be packed.
	 * @return
	 *            The packed version of the given term.
	 */
	public static ATerm pack(ATerm termData){
		ByteBuffer packBuffer = ByteBuffer.allocate(PACKBUFFERSIZE);
		ATermList chunkList = termFactory.getEmpty();
		BinaryWriter binaryWriter = new BinaryWriter(termData);
		do{
			packBuffer.clear();
			try{
				binaryWriter.serialize(packBuffer);
			}catch(VisitFailure vf){/*Intentionally ignore this useless exception.*/}
			
			int size = packBuffer.limit();
			byte[] data = new byte[size];
			packBuffer.get(data);
			
			ATermBlob chunk = termFactory.makeBlob(data);
			chunkList = chunkList.insert(chunk);
		}while(!binaryWriter.isFinished());
		
		return termFactory.makeAppl(SYMBOL_SAF, chunkList);
	}
	
	/**
	 * Unpacks the given term.
	 * 
	 * @param packedTerm
	 *            The term that needs to be unpacked.
	 * @return
	 *            The unpacked version of the given term.
	 */
	public static ATerm unpack(ATerm packedTerm){
		ATerm result;
		
		ATermList annos = packedTerm.getAnnotations();
		switch(packedTerm.getType()){
			case ATerm.INT:
			case ATerm.REAL:
			case ATerm.BLOB:
				result = packedTerm;
				break;
			
			case ATerm.PLACEHOLDER:
				ATerm type = ((ATermPlaceholder) packedTerm).getPlaceholder();
				ATerm unpacked_type = unpack(type);
				if(unpacked_type.equals(type)){
					result = packedTerm;
				}else{
					result = termFactory.makePlaceholder(unpacked_type);
				}
				break;
			
			case ATerm.APPL:
				ATermAppl appl = (ATermAppl)packedTerm;
				AFun fun = appl.getAFun();
				if(fun == SYMBOL_SAF){
					ATermList chunkList = (ATermList) appl.getArgument(0);
					int nrOfChunks = chunkList.getLength();
					BinaryReader binaryReader = new BinaryReader(termFactory);
					do{
						ATermBlob chunk = (ATermBlob) chunkList.elementAt(--nrOfChunks);
						byte[] data = chunk.getBlobData();
						ByteBuffer unpackBuffer = ByteBuffer.wrap(data);
						
						binaryReader.deserialize(unpackBuffer);
					}while(nrOfChunks > 0);
					
					if(!binaryReader.isDone()) throw new RuntimeException("Unpacked term was incomplete.\n");
					
					result = binaryReader.getRoot();
				}else{
					ATermList unpacked_args = termFactory.getEmpty();
					
					for(int i = fun.getArity() - 1; i >= 0; i--) {
						unpacked_args = unpacked_args.insert(unpack(appl.getArgument(i)));
					}
					
					result = termFactory.makeApplList(fun, unpacked_args);
				}
				break;
			
			case ATerm.LIST:
				ATermList list = (ATermList) packedTerm;
				ATermList unpacked_list = termFactory.getEmpty();
				
				while(!list.isEmpty()){
					unpacked_list = unpacked_list.insert(unpack(list.getFirst()));
					list = list.getNext();
				}
				
				result = unpacked_list.reverse();
				break;
			
			default:
				throw new RuntimeException("Unkown term type: "+packedTerm.getType());
		}
		
		if(annos != null){
			annos = (ATermList) unpack(annos);
			result = result.setAnnotations(annos);
		}
		  
		return result;
	}
}
