package metalogger;

public class ATermBaf {
	private int hashvalue;
	private String ATermvalue;

	public ATermBaf(int hashvalue,String ATermvalue){
		this.hashvalue = hashvalue;
		this.ATermvalue = ATermvalue;	
	}
	public String getATermvalue(){
		return ATermvalue;
	}
	public boolean isEqual(int hashvalue){
		if(this.hashvalue == hashvalue)
			return true;
		else
			return false;
	}
}