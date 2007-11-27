package toolbus.viewer;

/**
 * Contains a list of all possible states the debug ToolBus can be in.
 * 
 * @author Arnold Lankamp
 */
public interface IViewerConstants{
	public final static int UNKNOWN_STATE = -1;
	public final static int STOPPING_STATE = 0;
	public final static int WAITING_STATE = 1;
	public final static int READY_STATE = 2;
	public final static int RUNNING_STATE = 3;
	public final static int STEPPING_STATE = 4;
}
