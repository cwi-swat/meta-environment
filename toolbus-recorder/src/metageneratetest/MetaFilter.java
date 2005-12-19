package metageneratetest;

import aterm.ATerm;
import aterm.ATermFactory;
import java.util.Vector;

public class MetaFilter {
	private ATermFactory factory;
	private Vector filterTable = new Vector();
	private boolean isPrinted = false;

	public MetaFilter(ATermFactory factory){
		this.factory = factory;
	}
	public void addFilter(String filter){
		filterTable.add(new FilterElement(filter,true));
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
			return saveProcess(term, factory, isFiltered);
		}
		else if(isInFilter(Integer.parseInt(term.getChildAt(0).toString()))){
			return true;
		}
		return false;
	}
	private boolean saveProcess(ATerm term, ATermFactory factory, boolean isFiltered){
		if(isFiltered){
			if(term.getChildAt(4).getChildCount()==1){
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
				addPid(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(2).getChildAt(1).toString()), isFiltered);
			}
			return true;
		}
		else{
			if(term.getChildAt(4).getChildCount()==1){
				addProcess(term.getChildAt(2).getChildAt(0).toString(), Integer.parseInt(term.getChildAt(4).getChildAt(0).getChildAt(1).toString()), isFiltered);
			}
			else if(term.getChildAt(4).getChildCount()==4){
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
	public void printTable(){
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
	public int getSize(){
		return filterTable.size();
	}
	public String getFilter(int place){
		FilterElement filterElem = (FilterElement)filterTable.get(place);
		return filterElem.getFilterName();
	}
}

