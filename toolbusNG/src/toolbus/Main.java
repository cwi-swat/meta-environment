/**
 * @author paulk
 */

package toolbus;

public class Main{

	public static void main(String[] args){
		ToolBus T = new ToolBus(args);
		try{
			if(T.parsecup()){
			//if(T.parse()){
				T.execute();
				//Atom.statistics();
			}else{
				System.err.println("Failed to parse");// Temp
			}
		}catch(Exception e){
			e.printStackTrace();
			System.exit(0);
		}

		// System.err.println(T.getTBTermFactory().statistics());
	}
}
