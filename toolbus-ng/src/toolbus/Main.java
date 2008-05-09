/**
 * @author paulk
 */

package toolbus;

public class Main{
	
	public static void main(String[] args){
		ToolBus toolbus = new ToolBus(args);
		
		try{
			if(toolbus.parsecup()){
				toolbus.prepare();
				toolbus.execute();
				//Atom.statistics();
			}else{
				System.err.println("Failed to parse");// Temp
			}
		}catch(Exception e){
			e.printStackTrace();
		}

		// System.err.println(T.getTBTermFactory().statistics());
	}
}
