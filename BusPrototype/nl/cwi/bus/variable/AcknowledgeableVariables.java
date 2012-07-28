package nl.cwi.bus.variable;

import java.util.ArrayList;
import java.util.List;

/**
 * Collection of variables that are awaiting acknowledgement.
 * 
 * @author Arnold Lankamp
 */
public class AcknowledgeableVariables{
	private List acknowledgeableVariables = null;

	/**
	 * Default constructor.
	 */
	public AcknowledgeableVariables(){
		super();

		acknowledgeableVariables = new ArrayList();
	}

	/**
	 * Adds a variable to the collection.
	 * 
	 * @param acknowledgeableVariable
	 */
	public void add(AcknowledgeableVariable acknowledgeableVariable){
		acknowledgeableVariable.getVariable().incrementReferenceCount();

		acknowledgeableVariables.add(acknowledgeableVariable);
	}

	/**
	 * Notifies all the variables that are waiting for an acknowledgement.
	 * 
	 * @param transactionID
	 *            The identifier of the transaction that was acknowledged.
	 */
	public void notifyAndRemove(long transactionID){
		for(int i = 0; i < acknowledgeableVariables.size(); i++){
			AcknowledgeableVariable variable = (AcknowledgeableVariable) acknowledgeableVariables.get(i);

			if(variable.getTransactionID() == transactionID){
				synchronized(variable){
					variable.notify();
					remove(variable);
				}
			}
		}
	}

	/**
	 * Invalidates all the variables associated with the given target tool
	 * identifier. This method should be called when a tool becomes
	 * disconnected, to prevent the processes from locking.
	 * 
	 * @param targetToolID
	 *            The tool identifier for which all the outstanding acks should
	 *            be invalidated.
	 */
	public void invalidateAcks(long targetToolID){
		for(int i = 0; i < acknowledgeableVariables.size(); i++){
			AcknowledgeableVariable variable = (AcknowledgeableVariable) acknowledgeableVariables.get(i);

			if(variable.getTargetToolID() == targetToolID){
				synchronized(variable){
					variable.notify();
					remove(variable);
				}
			}
		}
	}

	/**
	 * Checks if this collection contains the variable identified by the given
	 * parameters.
	 * 
	 * @param transactionID
	 *            The transaction identifier.
	 * @return True if this collection contains the variable identifier by the
	 *         given parameters; false otherwise.
	 */
	public boolean contains(long transactionID){
		boolean contains = false;

		for(int i = 0; i < acknowledgeableVariables.size(); i++){
			AcknowledgeableVariable variable = (AcknowledgeableVariable) acknowledgeableVariables.get(i);
			
			if(variable.getTransactionID() == transactionID){
				contains = true;
				break;
			}
		}

		return contains;
	}

	/**
	 * Removes the given variable from this collection.
	 * 
	 * @param acknowledgeableVariable
	 *            The variable to remove.
	 */
	public void remove(AcknowledgeableVariable acknowledgeableVariable){
		acknowledgeableVariables.remove(acknowledgeableVariable);

		acknowledgeableVariable.getVariable().decrementReferenceCount();
	}

	/**
	 * Container for variables that are transfered and require acknowledgement.
	 * 
	 * @author Arnold Lankamp
	 */
	public static class AcknowledgeableVariable{
		private FinalizableVariable finalizableVariable = null;
		private long targetToolID = -1;
		private long tranactionID = -1;

		/**
		 * Constructor.
		 * 
		 * @param finalizableVariable
		 *            The finalizable variable
		 * @param tranactionID
		 *            The identifier of the transaction.
		 * @param targetToolID
		 *            The target tool id.
		 */
		public AcknowledgeableVariable(FinalizableVariable finalizableVariable, long tranactionID, long targetToolID){
			super();

			this.finalizableVariable = finalizableVariable;
			this.tranactionID = tranactionID;
			this.targetToolID = targetToolID;
		}

		/**
		 * Returns the finalizable variable.
		 * 
		 * @return The finalizable variable.
		 */
		public FinalizableVariable getVariable(){
			return finalizableVariable;
		}

		/**
		 * Returns the transaction id.
		 * 
		 * @return The transaction id.
		 */
		public long getTransactionID(){
			return tranactionID;
		}

		/**
		 * Returns the target tool id.
		 * 
		 * @return The target tool id.
		 */
		public long getTargetToolID(){
			return targetToolID;
		}
	}
}
