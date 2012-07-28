package metaplayback;

public class ActionElement {

	private int elementNo;
	private String processName;
	private String actionType;
	private boolean visited;

	public ActionElement(int elementNo, String processName, String actionType){
		this.elementNo = elementNo;
		this.processName = processName;
		this.actionType = actionType;
		visited = false;
	}
	public int getElementNo(){
		return elementNo;
	}
	public String getProcessName(){
		return processName;
	}
	public String getActionType(){
		return actionType;
	}
	public boolean getVisited(){
		return visited;
	}
	public void setVisited(){
		visited = false;
	}

	public boolean isElementNo(int element){
		if(element == elementNo){
			return true;
		}
		return false;
	}
}
