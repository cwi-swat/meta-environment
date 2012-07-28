package metageneratetest;

import aterm.*;
import java.io.*;
import java.util.Vector;

public class MetaLoad {
	private File loadFile, saveMap;
	private ATermFactory factory;
	private Vector filelist = new Vector();
	private MetaFilter filter;

	public MetaLoad(ATermFactory factory){
		filter = new MetaFilter(factory);
		this.factory = factory;
	}
	public boolean loadTest(File loadFile){
		FileInputStream readermain;
		BufferedReader buffermain;
		int response, loadWindow; 
		boolean returnvalue = true;
		FileElement fileElement;
		String fileMap = "";
		this.loadFile = loadFile;
		String line;

		if (!loadFile.exists ()) {
			System.out.println("ERROR: Can't load the file.");
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
							System.out.println("ERROR: Can't locate needed file: " + fileElement.getFileName() + " " + fileElement.getFileType());
					  		returnvalue = false;
					}
					else{
						if(fileElement.getFileType().equals("saveMap")){
							fileMap = fileElement.getFileName();
							saveMap = new File(loadFile.getParent() + "/" + fileMap);
						}
						else if(fileElement.getFileType().equals("filterFile")){
							loadFilters(fileElement.getFile());
						}
						filelist.add(fileElement);
					}
				}
			}
			catch(Exception e){
				System.out.println("ERROR: Error loading file.");
			}
		}
	     return returnvalue;
	 }
	private void loadFilters(File file){
		FileInputStream readermain;
		BufferedReader buffermain;
		String line="";
		String pattern;
		try{
			readermain = new FileInputStream(file);
			buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				pattern = factory.make(line).getChildAt(0).toString();
				pattern = pattern.substring(1, pattern.length()-1);
				filter.addFilter(pattern);
			}
		}
		catch(Exception e){
				System.out.println("ERROR: Error loading filters.");
		}
	}
	public File getLoadFile(){
		return saveMap;
	}
	public MetaFilter getFilter(){
		return filter;
	}
}
