/**
 * @author paulk
 */

package toolbus;

import toolbus.commandline.CommandLine;

public class Main{
	
	public static void main(String[] args){
		ToolBus toolbus = new ToolBus(args);
		
		CommandLine.createCommandLine(toolbus);
		
		try{
			if(toolbus.parsecup()){
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
