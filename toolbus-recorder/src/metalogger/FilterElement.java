package metalogger;

public class FilterElement {
	private int pid;
	private String filterName;
	private boolean isFiltered;
	private boolean hasImitatorTool;
	
	public FilterElement(String filterName, boolean hasImitatorTool){
		this.filterName = filterName;
		this.hasImitatorTool = hasImitatorTool;
		this.pid = -1;
		isFiltered = true;
	}
	public FilterElement(String filterName, int pid){
		this.filterName = filterName;
		this.pid = pid;
	}
	public void setFilterPid(int pid){
		this.pid = pid;
	}
	public String getFilterName(){
		return filterName;
	}
	public int getPid(){
		return pid;
	}
	public boolean isEqualFilterName(String filterName){

		if(filterName.equals(this.filterName)){
			return true;
		}
		else{
			return false;
		}
	}
	public boolean isEqualPid(int pid){
		if(this.pid == pid){
			return true;
		}
		else{
			return false;
		}
	}
	public void setFiltered(boolean isFiltered){
		this.isFiltered = isFiltered;
	}
	public boolean isFiltered(){
		return this.isFiltered;
	}
	public boolean hasImitatorTool(){
		return this.hasImitatorTool;
	}
}
