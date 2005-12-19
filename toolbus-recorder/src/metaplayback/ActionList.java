package metaplayback;

import java.util.Vector;
import aterm.ATerm;
import aterm.ATermFactory;

public class ActionList {
	private Vector actionList = new Vector();
	private int actionNo;
	private int activeActionNo;
	private ATermFactory factory;
	
	public ActionList(ATermFactory factory){
		this.factory = factory;
		activeActionNo = 0;
		actionNo = 0;
	}
	public void addAction(ATerm actionInfo){

		String process = actionInfo.getChildAt(0).toString();
		process = process.substring(1, process.length()-1);
		String actionType = actionInfo.toString();
		actionType = actionType.substring(0, actionType.indexOf("("));
		actionList.add(new ActionElement(actionNo , process, actionType));
		actionNo++;
	}
	public void setVisited(int action){
		ActionElement actionElement = null;
		for(int i = 0; i < actionNo; i++)
		{
			actionElement = (ActionElement)actionList.get(i);
			if(actionElement.getElementNo()==i){
				actionElement.setVisited();
			}
		}
	}
	public String getProcessName(int action){
		ActionElement actionElement = null;
		for(int i = 0; i < actionNo; i++)
		{
			actionElement = (ActionElement)actionList.get(i);
			if(actionElement.getElementNo()==action){
				return actionElement.getProcessName();
			}
		}
		return null;
	}
	public String getActionType(int action){
		ActionElement actionElement = null;
		for(int i = 0; i < actionNo; i++)
		{
			actionElement = (ActionElement)actionList.get(i);
			if(actionElement.getElementNo()==i){
				return actionElement.getActionType();
			}
		}
		return null;
	}
	public int getActionNo(){
		return actionNo;
	}
	public int getActiveActionNo(){
		return activeActionNo;
	}
	public void setActiveActionNo(int activeActionNo){
		this.activeActionNo = activeActionNo;
	}
	public void printActionList(){
		ActionElement actionElement = null;
		System.out.println("***********************");
		System.out.println("** TABLE INFORMATION **");
		for(int i = 0; i < actionNo; i++)
		{
			actionElement = (ActionElement)actionList.get(i);
			System.out.println("** Action No  : " + actionElement.getElementNo());
			System.out.println("** Processname: " + actionElement.getProcessName());
			System.out.println("**");
		}
		System.out.println("***********************");
	}
}
