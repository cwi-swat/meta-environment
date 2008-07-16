package toolbus.communication;

import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;

import aterm.ATerm;

/**
 * This class enables communication with clients that are running the the same VM as the server.
 * This class also facilitates the scheduling of requests to the 'direct' clients.
 * 
 * @author Arnold Lankamp
 */
public class DirectServerIOHandler implements IIOHandler{
	private final static Executor executor;
	static{
		// Create a new thread factory that constructs deamon threads, so the threads in the pool
		// will not prevent the VM from exiting.
		ThreadFactory threadFactory = new ThreadFactory(){
			public Thread newThread(Runnable r){
				Thread t = new Thread(r);
				t.setName("Direct I/O worker");
				t.setDaemon(true);

				return t;
			}
		};
		executor = Executors.newFixedThreadPool(1, threadFactory);
	}

	private final IDataHandler dataHandler;
	private DirectClientIOHandler directClientIOHandler = null;

	/**
	 * Constructor.
	 * 
	 * @param dataHandler
	 *            The data handler this I/O handler is associated with.
	 */
	public DirectServerIOHandler(IDataHandler dataHandler){
		super();

		this.dataHandler = dataHandler;
	}

	/**
	 * Links this I/O handler with its counter part.
	 * 
	 * @param directClientIOHandler
	 *            The client counter part of this I/O handler.
	 */
	public void setClientDirectIOHandler(DirectClientIOHandler directClientIOHandler){
		this.directClientIOHandler = directClientIOHandler;
	}

	/**
	 * Represents a single DO or EVAL request for the client that is associated with the
	 * encapsulating I/O handler.
	 * 
	 * @author Arnold Lankamp
	 */
	private class ExecutionRequest implements Runnable{
		private final byte operation;
		private final ATerm aTerm;

		/**
		 * Constructor.
		 * 
		 * @param operation
		 *            The operation identifier.
		 * @param aTerm
		 *            The aterm that contains the details about the request.
		 */
		public ExecutionRequest(byte operation, ATerm aTerm){
			super();

			this.operation = operation;
			this.aTerm = aTerm;
		}

		/**
		 * The execution code of this request.
		 */
		public void run(){
			directClientIOHandler.receive(operation, aTerm);
		}
	}

	/**
	 * @see IIOHandler#send(byte, ATerm)
	 */
	public void send(byte operation, ATerm aTerm){
		executor.execute(new ExecutionRequest(operation, aTerm));
	}

	/**
	 * @see IIOHandler#receive(byte, ATerm)
	 */
	public void receive(byte operation, ATerm aTerm){
		dataHandler.receive(operation, aTerm);
	}

	/**
	 * @see IIOHandler#terminate()
	 */
	public void terminate(){
		directClientIOHandler.shutDown();
	}

	/**
	 * @see IIOHandler#shutDown()
	 */
	public void shutDown(){
		dataHandler.shutDown();
	}
	
	/**
	 * @see IIOHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		dataHandler.exceptionOccured();
	}
}
