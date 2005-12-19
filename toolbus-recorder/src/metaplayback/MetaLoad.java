package metaplayback;

import aterm.*;
import java.io.*;
import java.util.Vector;

public class MetaLoad {
	private File loadFile;
	private File saveMap;
	private File mainCommunication;
	private File testEnvironment;
	private File sharedActionFile;
	private File executeMap;
	private MetaPlaybackBridge bridge;
	private ATermFactory factory;
	private Vector filelist;
	private MetaFilter filter;
	private ActionList valueList;
	private ActionList actionList;

	public MetaLoad(ATermFactory factory, MetaPlaybackBridge bridge){
		this.factory = factory;
		this.bridge = bridge;
		filter = new MetaFilter(factory);
		actionList = new ActionList(factory);
		valueList = new ActionList(factory);
		filelist = new Vector();
	}
	public boolean loadTest(File loadFile){
		FileInputStream readermain;
		BufferedReader buffermain;
		int response, loadWindow; 
		boolean returnvalue = true;
		FileElement fileElement;
		String fileMap = "";
		String line;
		
			if (!loadFile.exists ()) {
				System.out.println("Can't load the file.");
	     		returnvalue = false;
			}
			else{
				try{
					readermain = new FileInputStream(loadFile);
					buffermain = new BufferedReader(new InputStreamReader(readermain));
					while((line = buffermain.readLine()) != null){
						if(fileMap!=""){
							fileElement = new FileElement(factory.make(line), factory, loadFile.getParent(), fileMap);	
						}
						else{
							fileElement = new FileElement(factory.make(line), factory, loadFile.getParent());
						}
						if (!fileElement.fileExist()){
							System.out.println("Can't locate needed file: " + fileElement.getFileName() + ".");
			         		returnvalue = false;
						}
						else{
							if(fileElement.getFileType().equals("saveMap")){
								fileMap = fileElement.getFileName();
								saveMap = new File(loadFile.getParent() + "/" + fileMap);
								//testEnvironment = new File(saveMap, "testEnvironment");
								sharedActionFile = new File(loadFile.getParent(), "sharedActionFile.acl");
								if(sharedActionFile.exists()){
									sharedActionFile.delete();
								}
							}
							else if(fileElement.getFileType().equals("executeMap")){
								executeMap = fileElement.getFile();
							}
							else if(fileElement.getFileType().equals("mainFile")){
								mainCommunication = fileElement.getFile();
								loadActions(mainCommunication);
							}
							else if(fileElement.getFileType().equals("filterFile")){
								loadFilters(fileElement.getFile());
							}
							else if(fileElement.getFileType().equals("bafFile")){
								loadBaf(fileElement.getFile());
							}
							filelist.add(fileElement);
						}
					}
				}
				catch(Exception e){
					System.out.println("Error loading file.");
				}
			}
	    return returnvalue;
	}
	private void loadBaf(File file){
		FileInputStream readermain;
		BufferedReader buffermain;
		String line,bafPart, bafFile;
		
		bafPart = "";
		try{
			readermain = new FileInputStream(file);
			buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				bafPart += line;
			}
			bafFile = file.getName();
			bafFile = bafFile.substring(1,(bafFile.length()-4));
			bridge.addBaf(Integer.parseInt(bafFile), bafPart);
		}
		catch(Exception e){
			System.out.println("ERROR: loading baf file");
		}
	}
	private void loadActions(File file){
		FileInputStream readermain;
		BufferedReader buffermain;
		String line="";
		String process;
		String action;
		ATerm actionTerm;
		try{
			readermain = new FileInputStream(file);
			buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){

				action = line.substring(0, line.indexOf("("));
				actionTerm = factory.make(line);
				
				if(action.equals("eval")){
					valueList.addAction(actionTerm);
				}
				else if(action.equals("event")){
					actionList.addAction(actionTerm);
				}
			}
		}
		catch(Exception e){
			System.out.println("ERROR: loading action file");
		}
	}
	private void loadFilters(File file){

		FileInputStream readermain;
		BufferedReader buffermain;
		String line="";
		String pattern;
		ATerm atermLine;
		int imitatorTool;
		boolean hasImitatorTool;
		try{
			readermain = new FileInputStream(file);
			buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				hasImitatorTool = false;
				atermLine = factory.make(line);
				pattern = atermLine.getChildAt(0).toString();
				pattern = pattern.substring(1, pattern.length()-1);
				imitatorTool = Integer.parseInt(atermLine.getChildAt(1).toString());
				if(imitatorTool == 1){
					hasImitatorTool = true;
				}
				filter.addFilter(pattern, hasImitatorTool);
			}
		}
		catch(Exception e){
			System.out.println("Error loading filter file.");
		}
	}
	public File getLoadFile(){
		return saveMap;
	}
	public File getExecuteMap(){
		return executeMap;
	}
	public File getMainCommunication(){
		return mainCommunication;
	}
	public File getTestEnvironment(){
		return testEnvironment;
	}
	public File getSharedActionFile(){
		return sharedActionFile;
	}
	public MetaFilter getFilters(){
		return filter;
	}
	public ActionList getActionList(){
		return actionList;
	}
	public ActionList getValueList(){
		return valueList;
	}
	public Vector getFileList(){
		return filelist;
	}
}
