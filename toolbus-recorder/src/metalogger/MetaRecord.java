
package metalogger;
import aterm.*;

import java.io.*;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import metastudio.*;
import metastudio.utils.ExtensionFilter;

public class MetaRecord {
	private File saveFile;
	private File saveMap;
	private File mainFile;
	private File filterFile;
	private FileWriter writer;
	private BufferedWriter buffer;
	private MetaLoggerBridge bridge;
	private ATermFactory factory;
	private MetaFilter filter;
	
	public MetaRecord(MetaLoggerBridge bridge, ATermFactory factory){
		this.bridge = bridge;
		this.factory = factory;
	}
	public void setFilter(MetaFilter filter){
		this.filter = filter;
	}
	public boolean saveTest(){
	 	JFileChooser chooser = new JFileChooser();
		String[] exts = { ".rp" };
        String saveFileString;
		ExtensionFilter filter = new ExtensionFilter(exts,"Record and Playback file");
		chooser.setFileFilter(filter);
		int saveWindow = chooser.showSaveDialog(null);
		int response;
		boolean returnvalue = true;
		
		if (saveWindow ==  JFileChooser.APPROVE_OPTION)
		{
			saveFile = chooser.getSelectedFile();
			saveFileString = saveFile.toString();
			if(!saveFileString.substring(saveFileString.length()-3).equals(".rp")){
				saveFile = new File(saveFile.getParentFile(),saveFile.getName() + ".rp");
			}

			if (saveFile.exists ()) {
	             response = JOptionPane.showConfirmDialog (null,
	               "Overwrite existing file?","Confirm Overwrite",
	                JOptionPane.OK_CANCEL_OPTION,
	                JOptionPane.QUESTION_MESSAGE);
	             if (response == JOptionPane.CANCEL_OPTION)	             {
	             	returnvalue = false;
	             }
	             else if(!saveFile.canWrite()){
	             		JOptionPane.showMessageDialog(null,"Can't overwrite the current file.","Error writing file",JOptionPane.ERROR_MESSAGE);
	             		returnvalue = false;
	             }
	         }

			saveMap = new File(saveFile + "_filedir");
			if(returnvalue){
				if (saveMap.exists ()) {
		             response = JOptionPane.showConfirmDialog (null,
		               "Use current filedir: \"" + saveMap + "\" or choose new file?","Save Map",
		                JOptionPane.OK_CANCEL_OPTION,
		                JOptionPane.QUESTION_MESSAGE);
		             if (response == JOptionPane.CANCEL_OPTION) returnvalue = false;
		         }
			}
		}
	    else if(saveWindow == JFileChooser.CANCEL_OPTION){
	    	System.exit(0);
	    	returnvalue = false;	
	    }
	    else if(saveWindow == JFileChooser.ERROR_OPTION){
	    	System.exit(0);
	    	returnvalue = false;
	    }  
	    
	    if(returnvalue){
	    	try{
		    	if (saveFile.exists ()){
		    		saveFile.delete();
		    	}
	     		saveFile.createNewFile();
	     		if (saveMap.exists ()) {
	     			deleteDirContent(saveMap);
	     		}
	     		saveMap.mkdir();
	     		saveMap = new File(saveFile + "_filedir");	     		
	     		filterFile = new File(saveMap.getPath() + "/filterlist.atl");
	     		filterFile.createNewFile();
	     		mainFile = new File(saveMap.getPath() + "/maincommunication.atl");
	     		mainFile.createNewFile();
	     		saveFileName("self",saveFile.getName());
	     		saveFileName("executeMap", System.getProperty("user.dir"));
	     		saveFileName("saveMap",saveMap.getName());
	     		saveFileName("filterFile",filterFile.getName());
	     		saveFileName("mainFile",mainFile.getName());
	    	}
	    	catch (Exception e){
	    		JOptionPane.showMessageDialog(null,"Can't create the new file(s).","Error writing file",JOptionPane.ERROR_MESSAGE);
	    		returnvalue = false;
	    	}
	    }
	      return returnvalue;
	 }
	public void saveFileName(String type, String name){
		writeFile("file(\""+type+"\",\""+name+"\")",saveFile);
	}
	private boolean deleteDirContent(File checkMap){
		if(checkMap.isDirectory()){
			String[] children = checkMap.list();
			for (int i=0;i<children.length;i++){
				if(!deleteDirContent(new File(checkMap,children[i]))){
					return false;
				}
			}
		}
		return checkMap.delete();
	}
	public void recordTerm(String stringdata, File file){
		writeFile(stringdata, file);
	}
	public void recordTerm(ATerm term, File file){
		String stringdata = term.toString();
		writeFile(stringdata, file);
		if(stringdata.indexOf("\"_baf-recoded_\"(\"")!=-1){
   	 		recordBaf(stringdata);
		}
	}
	public void recordTerm(ATerm term){
		int processId = Integer.parseInt(term.getChildAt(0).toString());
		String processName = filter.getFilterName(processId);
		File singleProcess = new File(getFile("map"), processName + ".atl");
		String stringdata = term.toString();
				
		try{
			if(!singleProcess.exists()){
				singleProcess.createNewFile();
				saveFileName("processFile",singleProcess.getName());
			}
		}
		catch (Exception e){
			System.out.println("Error creating processfile");
		}
		
		String communicationType = term.getChildAt(1).toString();
		recordTerm(communicationType + ";" + createMessage(term), singleProcess);
		if(filter.getUseImitatortool(processId)){
			if(communicationType.equals("rec-event")){
				recordTerm(factory.make("event(<str>)",processName),getFile("main"));
			}
			else if(communicationType.equals("rec-value")){
				recordTerm(factory.make("eval(<str>)",processName),getFile("main"));
			}
		}
		
		if(stringdata.indexOf("\"_baf-recoded_\"(\"")!=-1){
   	 		recordBaf(stringdata);
		}
	}
	private ATerm createMessage(ATerm term){
		String varName, currentVar, line, value, result;
		int endPosFunction, endPosition;

		ATerm variables = (ATerm)term.getChildAt(4);
		ATerm pattern = (ATerm)term.getChildAt(2).getChildAt(1);
		String patternString = pattern.toString();
		endPosFunction = patternString.indexOf("(");

		if(endPosFunction != -1){
			result = patternString.substring(0,endPosFunction + 1);
			
			for(int j=0;j<pattern.getChildCount();j++){
				varName=pattern.getChildAt(j).toString();
				endPosition = varName.indexOf("$");
				
				if(endPosition!=-1){
					varName = varName.substring(0,endPosition);
					
					for(int i=0; i<variables.getChildCount();i++){
						line=variables.getChildAt(i).getChildAt(0).toString();
						endPosition = line.indexOf("$");
						
						if(endPosition!=-1){
							currentVar = line.substring(0,endPosition);
							
							if(varName.equals(currentVar)){
								result = result + variables.getChildAt(i).getChildAt(1).toString();
								if(j<pattern.getChildCount()-1){
									result = result + ",";
								}
							}	
						}
					}
				}
			}
			result = result + ")";
		}
		else{
			result = patternString;
		}
		return factory.make(result);
	}
	public File getFile(String type){
		if(type =="filter"){
			return filterFile;
		}
		else if(type =="map"){
			return saveMap;
		}
		else if(type =="main"){
			return mainFile;
		}
		else{
			return null;
		}
	}
	public void writeFile(String stringdata, File file){
		try{
			writer = new FileWriter(file,true);
    		buffer = new BufferedWriter(writer);
			buffer.write(stringdata);
			buffer.newLine();
			buffer.flush();
			buffer.close();
   	 	}
		catch(Exception e){
   	 		JOptionPane.showMessageDialog(null,"Error recording message.","Error writing file",JOptionPane.ERROR_MESSAGE);
		}
	}
	public void recordBaf(String stringdata){
		int beginBaf, endBaf, endBaf1, endBaf2, hashcode, tempPlace;
		String hashstring;
		File saveBaf;
		beginBaf = stringdata.indexOf("\"_baf-recoded_\"(\"");
		while(beginBaf!=-1){	
			tempPlace = stringdata.indexOf("],[",beginBaf);
			if(tempPlace ==-1){
				tempPlace = stringdata.indexOf("\"),",beginBaf);
			}
			endBaf = stringdata.lastIndexOf("\"",tempPlace+1);
			try{
				hashstring = stringdata.substring(beginBaf+17, endBaf);
				saveBaf = new File(saveMap.getPath() + "/b" + hashstring + ".baf");
				if(!saveBaf.exists()){
					saveBaf.createNewFile();
					if(bridge.getBaf(Integer.parseInt(hashstring))==null){
						System.out.println("ERROR: Baf doesn't exist in memory");
					}
					else{
						writeFile("file(\"bafFile\",\""+saveBaf.getName()+"\")",saveFile);
						writeFile(bridge.getBaf(Integer.parseInt(hashstring)), saveBaf);
					}
				}
			}
			catch(Exception e){
				System.out.println("ERROR: Error saving baf file.\n\n" + e.toString() + "\n\n");
				System.out.println(stringdata);
			}
			beginBaf = stringdata.indexOf("\"_baf-recoded_\"(\"", beginBaf+17);
		}
	}
}
