
package metalogger;

import aterm.ATerm;
import aterm.ATermFactory;

//import java.io.File;
import java.util.Vector;

public class MetaFilter {
	private ATermFactory factory;
	private Vector filterTable;
	private boolean isPrinted;
	private MetaRecord record;

	public MetaFilter(ATermFactory factory, MetaRecord record){
		this.factory = factory;
		this.record = record;
		filterTable = new Vector();
		isPrinted = false;
	}
	public void addFilter(String filter, boolean hasImitatorTool){
		int hIT;
		if(hasImitatorTool){
			hIT = 1;
		}
		else{
			hIT = 0;
		}
		filterTable.add(new FilterElement(filter,hasImitatorTool));
		record.recordTerm(factory.make("filter(\"" + filter + "\"," + hIT + ")"),record.getFile("filter"));
	}
	public boolean filterTerm(ATerm term, ATermFactory factory)
	{
		FilterElement filterElem = null;
		boolean isFiltered = false;
		
		ATerm createTerm = factory.make("create");
		if(createTerm.isEqual((ATerm)term.getChildAt(1))){	
			if(isInFilter(term.getChildAt(2).getChildAt(0).toString())){
				isFiltered = true;
			}
			saveProcess(term, factory, isFiltered);
			return false;
		}
		else if(isInFilter(Integer.parseInt(term.getChildAt(0).toString()))){
			String communicationType = term.getChildAt(1).toString();
			if(communicationType.equals("snd-do") || communicationType.equals("rec-event") || communicationType.equals("snd-ack-event") || communicationType.equals("snd-eval") || communicationType.equals("rec-value")){
				return true;
			}
		}
		return false;
	}
	private boolean saveProcess(ATerm term, ATermFactory factory, boolean isFiltered){
		if(isFiltered){
			if(term.getChildAt(4).getChildCount()==1){
				//Bij in-output en editorhive
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
				//Bij de GUI
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(2).getChildAt(1).toString()), isFiltered);
			}
			return true;
		}
		else{
			if(term.getChildAt(4).getChildCount()==1){
				//Bij in-output en editorhive
				addProcess(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
				//Bij de GUI
				addProcess(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(2).getChildAt(1).toString()), isFiltered);
			}
			return false;
		}
	}
	private void addProcess(String processName, int pid, boolean isFiltered){
		FilterElement filterElem = new FilterElement(processName,pid);
		filterTable.add(filterElem);
	}
	private void addPid(String processName, int pid, boolean isFiltered){
		FilterElement filterElem = null;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(processName)){
				filterElem.setFilterPid(pid);
				filterElem.setFiltered(isFiltered);
				//record.recordTerm(factory.make("process(" + pid + ",\"" + processName + "\")"),record.getFile("process"));
				break;
			}
		}
	}
	private boolean isInFilter(String processName){
		FilterElement filterElem = null;
		boolean isFound = false;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualFilterName(processName) && filterElem.isFiltered()){
				isFound = true;
				break;
			}
		}
		return isFound;
	}
	private boolean isInFilter(int pid){
		FilterElement filterElem = null;
		boolean isFound = false;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualPid(pid) && filterElem.isFiltered()){
				isFound = true;
				break;
			}
		}
		return isFound;
	}
	public String getFilterName(int pid){
		FilterElement filterElem = null;
		String filterName = "notfound";
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualPid(pid)){
				filterName = filterElem.getFilterName();
				break;
			}
		}
		return filterName;
	}
	public boolean getUseImitatortool(int pid){
		FilterElement filterElem = null;
		boolean hasImitatorTool = false;
		for(int i = 0; i < filterTable.size(); i++)
		{
			filterElem = (FilterElement)filterTable.get(i);
			if(filterElem.isEqualPid(pid)){
				hasImitatorTool = filterElem.hasImitatorTool();
				break;
			}
		}
		return hasImitatorTool;
	}
	private void printTable(){
		if(isPrinted==false)
		{
			FilterElement filterElem = null;
			System.out.println("***********************");
			System.out.println("** TABLE INFORMATION **");
			for(int i = 0; i < filterTable.size(); i++)
			{
				filterElem = (FilterElement)filterTable.get(i);
				System.out.println("** PID: " + filterElem.getPid());
				System.out.println("** filterName: " + filterElem.getFilterName());
				System.out.println("** Filtered: " + filterElem.isFiltered());
				System.out.println("**");
			}
			System.out.println("***********************");
			isPrinted = true;
		}
	}
}

