package metaplayback;

public class FilterElement {
	private int pid;
	private String filterName;
	private boolean hasImitatorTool;
	private boolean isFiltered;
	
	public FilterElement(String filterName){
		this.filterName = filterName;	
	}
	public FilterElement(String filterName,boolean isFiltered, boolean hasImitatorTool){
		this.filterName = filterName;
		this.isFiltered = isFiltered;
		this.hasImitatorTool = hasImitatorTool;
		this.pid = -1;
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

		if(filterName.equals(this.filterName))
			return true;
		else
			return false;
	}
	public boolean isEqualPid(int pid){
		if(this.pid == pid)
			return true;
		else
			return false;
	}
	public void setFiltered(boolean isFiltered){
		this.isFiltered = isFiltered;
	}
	public boolean isFiltered(){
		return this.isFiltered;
	}
	public boolean hasImitatorTool(){
		return hasImitatorTool;
	}
}
