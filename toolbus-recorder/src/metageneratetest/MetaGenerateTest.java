package metageneratetest;

import java.util.*;
import java.io.*;

import aterm.pure.PureFactory;

public class MetaGenerateTest {
	private static PureFactory factory;	
	MetaLoad load;
	MetaFilter filter;
	File meta, tbMap;
	Vector fileList = new Vector();
	String processString;
	File testEnvironment;
	boolean addedBridgeFunction=false;
	boolean toolCreated;
	
	public static void main(String[] args){
		MetaGenerateTest playbacker = new MetaGenerateTest(args);	
	}
	public MetaGenerateTest(String[] args){
		if(args.length==0){
			System.out.println("Wrong usage: metageneratetest 'testfile'");
		}
		else{
			factory =  new PureFactory();
			load = new MetaLoad(factory);
			boolean saveLocationChoosen = false;
			String processString;
			
			File loadFile = new File(System.getProperty("user.dir"),args[0]);
			if(!loadFile.exists()){
				loadFile = new File(args[0]);
			}
			if(loadFile.exists()){
		    	saveLocationChoosen = load.loadTest(loadFile);
		    	filter = load.getFilter();	
		    	
		    	System.out.println("Starting generation procedure. This may take several minutes.");
		    
			    File compile = new File("compile");
				if(compile.exists()){
					compile.delete();
				}
			    	
			    if(saveLocationChoosen){
					try
			        {            
						Runtime rt = Runtime.getRuntime();
			            Process proc = rt.exec("which meta");
			            InputStream stderr = proc.getInputStream();
			            InputStreamReader isr = new InputStreamReader(stderr);
			            BufferedReader br = new BufferedReader(isr);
			            meta = new File(br.readLine());
			            tbMap = new File(new File(meta.getParent()).getParent() + "/share/meta");
			            File startMetaFile = new File(tbMap.toString() + "/start-meta-studio.tb");
			            fileList.add(startMetaFile.toString());
			            findUsedFiles(startMetaFile);
			            testEnvironment = load.getLoadFile().getParentFile();
			            createStartFile(load.getLoadFile().getParentFile());
			            createSettingFile();
			            findFilteredProcesses();
			            rt.exec("chmod a+x " + compile.toString());
						rt.exec("./compile");
						compile.delete();
			            System.exit(0);
			        }
					catch(Exception e){
						System.out.println("ERROR: In main setup\n" + e.getMessage());
					}
			    }
			}
		}
	}
	private void createSettingFile(){
		File settingsFile = new File(System.getProperty("user.dir"),"metaplaybacksettings.atl");
		if(settingsFile.exists()){
			settingsFile.delete();
		}
		writeFile("setting(\"startFile\",\"test.rp\")",settingsFile);
	}
	private void printFileList(){
		System.out.println("------FILELIST------");
		System.out.println("Number of files: " + fileList.size());
		System.out.println("--------------------");
		for(int i=0;i<fileList.size();i++){
			System.out.println(i + " " + fileList.get(i));
		}
	}
	 public void findUsedFiles(File checkFile){
	 	Runtime rt = Runtime.getRuntime();
	 	Process proc;
	 	InputStream stderr;
	 	InputStreamReader isr;
	 	BufferedReader br;
	 	String line, tempLine = "", tempLine2="",fileContent="";
	 	File testFile = null;
	 	try{
	 		FileInputStream readermain = new FileInputStream(checkFile);
	 		BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
	 		while((line = buffermain.readLine()) != null){
	 			fileContent+=line + " ";
	 			if(line.length() > 8 && line.substring(0,8).equals("#include")){
	 				tempLine = line.substring(9,line.length());
					if(tempLine.substring(0,1).equals("\"")){
						testFile = new File(checkFile.getParent().toString() + "/" +tempLine.substring(1, tempLine.lastIndexOf("\"")));
					}
					else if(tempLine.substring(0,1).equals("<")){
						testFile = new File(checkFile.getParent().toString() + "/" +tempLine.substring(1, tempLine.lastIndexOf(">")));
					}
					
					if(testFile.exists()){
						fileList.add(testFile.toString());
						findUsedFiles(testFile);
					}
					else{
						proc = rt.exec("locate " + testFile.getName());
			            stderr = proc.getInputStream();
			            isr = new InputStreamReader(stderr);
			            br = new BufferedReader(isr);
			            while((tempLine2 = br.readLine()) != null){
			            	if(tempLine2.substring(0,tbMap.getParent().toString().length()).equals(tbMap.getParent().toString())){
			            		testFile = new File(tempLine2);
			            		if(testFile.exists()){
			            			fileList.add(tempLine2);
			            			findUsedFiles(testFile);
			            		}
			            	}
			            }
					}
	 			}
	 		}
	 		createProcessString(fileContent);
	 	}	
	 	catch(Exception e){
	 		System.out.println("ERROR reading file: " + testFile.toString());
	 	}
	 }
	 public void createProcessString(String data){
	 	processString += removeLayout(data);
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
	 public String removeLayout(String data){
	 	boolean replaced=true;
	 	String returnData = data;
	 	String equalData = data;
	 	int count=0;
	 	while(replaced)
	 	{
	 		replaced=false;
	 		returnData = returnData.replaceAll("\t"," ");
	 		returnData = returnData.replaceAll("  "," ");
	 		
	 		if(!returnData.equals(equalData)){
	 			replaced = true;
	 			equalData = returnData;
	 		}
	 	}
	 	return returnData;
	 }
	public void findFilteredProcesses(){
		File communicationFile, createMap, processFile;
		String processDecl, toolDecl;
		Runtime rt;
		Process proc;
		for(int i = 0;i<filter.getSize();i++){
			toolCreated = false;
			communicationFile = new File(load.getLoadFile().toString() + "/" + filter.getFilter(i) + ".atl");
			if(communicationFile.exists()){
				processDecl = findProcess(filter.getFilter(i));
				toolDecl = findTool(filter.getFilter(i));
				if(processDecl.indexOf("rec-event(")!=-1){
					try{
						createMap = new File(testEnvironment, getToolName(filter.getFilter(i)) + "_tooldir");
						processFile = new File(createMap, "process.tb");
						if(createMap.exists()){
							deleteDirContent(createMap);
						}
						createMap.mkdir();
						
						if(processFile.exists()){
							processFile.delete();
						}
						processFile.createNewFile();
						writeFile(toolDecl + "\n\n" + processDecl, processFile);
						rt = Runtime.getRuntime();
						proc = rt.exec("toolbus -gentifs " + processFile.toString());
						int startExecute = processDecl.indexOf("execute(");
						int endExecute = processDecl.indexOf(",", startExecute);
						String tool = processDecl.substring(startExecute + 8,endExecute).trim();
						proc = rt.exec("tifstojavaloc " + createMap.toString() +" " + tool  + " process.tifs");
						createGlobalSet(createMap,filter.getFilter(i));				
						boolean no1=false,no2=false,no3=false;
				
						while (true){
				           	Runtime rt1 = Runtime.getRuntime();
				            Process proc1 = rt1.exec("ls "+ createMap.toString());
				            InputStream stderr1 = proc1.getInputStream();
					        InputStreamReader isr1 = new InputStreamReader(stderr1);
					        BufferedReader br1 = new BufferedReader(isr1);
					        String line="";
					        while((line=br1.readLine())!=null){  
					           	 if(line.length() > 8 && line.substring(line.length()-8).equals("Tif.java")){
					           	 	no1 = true;
					           	 }
					           	 else if(line.length() > 9 && line.substring(line.length()-9).equals("Tool.java")){
					           	 	no2=true;
					           	 }
					           	 else if(line.length() > 11 && line.substring(line.length()-11).equals("Bridge.java")){
					           	 	no3=true;
					           	 }
					        }
					        if(no1==true&&no2==true&&no3==true){
					           	break;
					         }
					         else{
					           	no1 = false;
					           	no2=false;
					           	no3=false;
					         }
				         }
						rewriteFiles(createMap);
						copyMetaImitatorFiles(createMap);
						//createStartFile(createMap,getToolName(filter.getFilter(i)));
						createImitatorFile(createMap,getToolName(filter.getFilter(i)));
						createGenericFile(createMap,getToolName(filter.getFilter(i)));
						toolCreated = true;
					}
					catch(Exception e){
						System.out.println("ERROR creating processfile\n\n" + e);
					}
				}
			}
		}
	}
	
	public void rewriteFiles(File map){
		String line=null;
		Runtime rt;
		Process proc;
		InputStream stderr;
		InputStreamReader isr;
		BufferedReader br;
		File tifOld=null, toolOld=null, bridgeOld=null;

		File startMap = new File(map, "metatoolimitator");
		startMap.mkdir();
        File tif = new File(startMap, "MetaToolImitatorTif.java");
		File tool = new File(startMap, "MetaToolImitatorTool.java");
		File bridge = new File(startMap, "MetaToolImitatorBridge.java");

		if(tif.exists()){
			tif.delete();
		}
		if(tool.exists()){
			tool.delete();
		}
		if(bridge.exists()){
			bridge.delete();
		}
		
		try{
			Runtime rt1 = Runtime.getRuntime();
            Process proc1 = rt1.exec("ls "+ map.toString());
            InputStream stderr1 = proc1.getInputStream();
            InputStreamReader isr1 = new InputStreamReader(stderr1);
            BufferedReader br1 = new BufferedReader(isr1);

            while((line=br1.readLine())!=null){  
            	 if(line.length() > 8 && line.substring(line.length()-8).equals("Tif.java")){
            	 	tifOld = new File(map.toString(),line);
            	 }
            	 else if(line.length() > 9 && line.substring(line.length()-9).equals("Tool.java")){
            	 	toolOld = new File(map.toString(),line);
            	 }
            	 else if(line.length() > 11 && line.substring(line.length()-11).equals("Bridge.java")){
            	 	bridgeOld = new File(map.toString(),line);
            	 }
            }
			tif.createNewFile();
			tool.createNewFile();
			bridge.createNewFile();

			String tifName = getNameFromPattern(tifOld,"public interface");
			String toolName = getNameFromPattern(toolOld,"abstract public class");
			String bridgeName = getNameFromPattern(bridgeOld,"public class");

			rewriteTif(tifName, tifOld, tif);
			rewriteTool(toolName, tifName, toolOld, tool);		
			rewriteBridge(toolName, tifName, bridgeName, bridgeOld, bridge);

			File compile = new File("compile");
			compile.createNewFile();
			writeFile("cd " + startMap.toString() + "\njavac *.java",compile);

			tifOld.delete();
			toolOld.delete();
			bridgeOld.delete();
		}
		catch(Exception e){
			System.out.println("ERROR: rewriting files\n" + e.getMessage());
		}
	}
	public void copyMetaImitatorFiles(File createMap){
		File fromMap = new File(tbMap.getParent() + "/meta-toolimitator");
		File toMap = new File(createMap, "metatoolimitator");
		Runtime rt1 = Runtime.getRuntime();
		try{
			rt1.exec("cp " + fromMap.toString() + "/AbstractTool.java " + toMap.toString() + "/");
			rt1.exec("cp " + fromMap.toString() + "/MetaToolImitator.java " + toMap.toString() + "/");
			rt1.exec("cp " + fromMap.toString() + "/SwingWorker.java " + toMap.toString() + "/");
		}
		catch(Exception e){
			System.out.println("ERROR copy meta imitator files");
		}
	}
	public void createGlobalSet(File createMap, String process){
		File settingFile = new File(createMap, "global.set");
		writeFile("setting(\"process\",\"" + process +"\")",settingFile);
		writeFile("setting(\"selfMap\",\"" + createMap.toString() + "/metatoolimitator\")",settingFile);
		writeFile("setting(\"testEnvironment\",\"" + createMap.getParent() + "\")",settingFile);
		writeFile("setting(\"sharedActionFile\",\"" + createMap.getParent() + "/sharedActionFile.acl\")",settingFile);
	}
	public String getNameFromPattern(File file, String pattern){
		String name="";
		try{
			FileInputStream readertif = new FileInputStream(file);
			BufferedReader buffertif = new BufferedReader(new InputStreamReader(readertif));

			String line;
			while((line = buffertif.readLine()) != null){
				line = line.trim();
				if(line.length() > pattern.length() && line.substring(0,pattern.length()).equals(pattern)){
					name = line.substring(pattern.length() + 1).trim();
					break;
				}
			}
		}
		catch(Exception e){
			System.out.println("ERROR: Unable to find name");
		}
		return name;
	}
	public void rewriteTif(String tifName, File inputFile, File outputFile){
		String line;
		try{
			FileInputStream readerbridge2 = new FileInputStream(inputFile);
			BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
			writeFile("package metatoolimitator;",outputFile);
			while((line = bufferbridge2.readLine()) != null){
				line = line.replaceAll(tifName,"MetaToolImitatorTif");
				if(line.trim().equals("{")){
					line = line + "\n  /*";
				}
				else if(line.trim().equals("public void recTerminate(ATerm t0);")){
					line = "  */\n" + line;
				}
				else if(line.trim().equals("}")){
					line = "  public ATerm processCommunication();\n}";
				}
				writeFile(line,outputFile);
			}
		}
		catch(Exception e){
			System.out.println("ERROR: rewriting line in tiffile\n" + e.getMessage());
		}	
	}
	public void rewriteTool(String toolName, String tifName, File inputFile, File outputFile){
		String line, linePrevious;
		int fase = 1;
		int lastLine = 0;
		boolean write;
		try{
			FileInputStream readerbridge2 = new FileInputStream(inputFile);
			BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
			writeFile("package metatoolimitator;",outputFile);
			while((line = bufferbridge2.readLine()) != null){
				write =true;
				if(fase==1){
					line = line.replaceAll(tifName,"MetaToolImitatorTif");
					line = line.replaceAll(toolName,"MetaToolImitatorTool");
					if(line.trim().equals("public ATerm handler(ATerm term)")){
						fase = 2;
					}
				}
				else if(fase==2){
					if(lastLine==1){
						if(!line.trim().substring(0,6).equals("return")){
							write = false;
						}
						else{
							line = "      return processCommunication();";
						}
					}
					if(line.trim().equals("if (result != null) {")){
						lastLine = 1;
					}
					else{
						lastLine = 0;
					}
					if(line.trim().length() > 35 && line.trim().substring(0,36).equals("result = term.match(PrecTerminate0);")){
						fase = 3;
					}
				}
				if(write){
					writeFile(line,outputFile);
				}
			} 
		}
		catch(Exception e){
			System.out.println("ERROR: rewriting line in toolfile\n" + e.getMessage());
		}
	}
	public void rewriteBridge(String toolName, String tifName, String bridgeName, File inputFile, File outputFile){
		String line, linePrevious;
		int fase = 1;
		int lastLine = 0;
		boolean write;
		try{
			FileInputStream readerbridge2 = new FileInputStream(inputFile);
			BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
			writeFile("package metatoolimitator;",outputFile);
			while((line = bufferbridge2.readLine()) != null){
				if(fase==1){
					line = line.replaceAll(tifName,"MetaToolImitatorTif");
					line = line.replaceAll(toolName,"MetaToolImitatorTool");
					line = line.replaceAll(bridgeName,"MetaToolImitatorBridge");
					
					if(line.trim().equals("}")){
						line = line + "\n  public ATerm processCommunication()\n  {\n    if (tool != null) {\n      return tool.processCommunication();\n    }\n    else {\n      throw new UnsupportedOperationException(\"method `processCommunication' not supported.\");\n    }\n  }";
						fase = 2;
					}
				}
				else if(fase==2){

					if(line.trim().length() > 33 && line.trim().substring(0,34).equals("public void recTerminate(ATerm t0)")){
					 	fase = 3;
					}
					else if(line.trim().length() > 5 && line.trim().substring(0,5).equals("tool.")){
						line = "      tool.processCommunication();";
					}
					else if(line.trim().length() > 12 && line.trim().substring(0,12).equals("return tool.")){
						line = "      return tool.processCommunication();";
					}	
				}
				writeFile(line,outputFile);
			}
			
		}
		catch(Exception e){
			System.out.println("ERROR: rewriting line in toolfile\n" + e.getMessage());
		}
	}

	public String replaceToolName(String filter, String replaceString, String replaceSort){
		String process = findProcess(filter);

		if(!process.equals("")){
			
			int startExecute = process.indexOf("execute(");
			int endExecute = process.indexOf(",", startExecute);
			String tool = process.substring(startExecute + 8,endExecute).trim();
			if(replaceSort.equals("ALL")){
				replaceString = replaceString.replaceAll(tool, "meta-playback");
			}
			else if(replaceSort.equals("FIRST")){
				replaceString = replaceString.replaceFirst(tool, "meta-playback");
			}
		}
		return replaceString;
	}
	public String findProcess(String filter){
		int startDeclaration = processString.indexOf("process " + filter);
		int endDeclaration = processString.indexOf("endlet",startDeclaration) + 6;
		String process = processString.substring(startDeclaration,endDeclaration);
		return process;
	}
	public String getToolName(String filter){
		String process = findProcess(filter);
		String toolName = "";
		if(!process.equals("")){
			int startExecute = process.indexOf("execute(");
			int endExecute = process.indexOf(",", startExecute);
			String tool = process.substring(startExecute + 8,endExecute).trim();
			
			int startToolDecl = processString.indexOf("tool " + tool + " is");
			int startToolName = processString.indexOf("\"", startToolDecl)+1;
			int endToolName = processString.indexOf("\"", startToolName);
			toolName = processString.substring(startToolName, endToolName);
			
			endToolName = toolName.indexOf(" ");
			if(endToolName!=-1){
				toolName = toolName.substring(0,endToolName);
			}
		}
		return toolName;
	}
	public String findTool(String filter){
		String process = findProcess(filter);
		String toolDecl = "";
		if(!process.equals("")){
			int startExecute = process.indexOf("execute(");
			int endExecute = process.indexOf(",", startExecute);
			String tool = process.substring(startExecute + 8,endExecute).trim();
			
			int startToolDecl = processString.indexOf("tool " + tool + " is");
			int endToolDecl = processString.indexOf("}", startToolDecl) + 1;
			toolDecl = processString.substring(startToolDecl, endToolDecl);
		}
		return toolDecl;
	}
	public void createMap(File openedFile){
		File startMap = openedFile;
		testEnvironment = new File(startMap, "testEnvironment");
	
		if(testEnvironment.exists()){
			deleteDirContent(testEnvironment);
		}
		testEnvironment.mkdir();
		/*
		 * V 1. pak map van de geopende file
		 * V 2. creeer testomgeving map
		 * V 3. creer map voor elke filtered tool met dirnaam als in tooldeclaratie de opstartfile
		 * 4. Create processfile
		 */
	}
	public void writeFile(String stringdata, File file){
		FileWriter writer;
		BufferedWriter buffer;
		try{
			writer = new FileWriter(file,true);
    		buffer = new BufferedWriter(writer);
			buffer.write(stringdata);
			buffer.newLine();
			buffer.flush();
			buffer.close();
   	 	}
		catch(Exception e){
			System.out.println("Error saving file\n" + stringdata + "\n" + file.toString());
		}
	}
	public void createStartFile(File createMap){
		Runtime rt= Runtime.getRuntime();
		String line;
		boolean write;
		File copyFile = new File(meta.getParent(), "meta");
		//File startFile = new File(createMap.getParentFile(), "metaplayback");
		//File genericFile = new File(createMap.getParentFile(), "generic-playback");
		File startFile = new File(createMap, "metaplayback");
		File genericFile = new File(createMap, "generic-playback");

/*
		#! /bin/sh

		/opt/asfsdf-meta-1.5.3/bin/generic-meta \
		  -I /opt/asfsdf-meta-1.5.3/share/asf \
		  -I /opt/asfsdf-meta-1.5.3/share/asfsdf-meta \
		  -p /opt/asfsdf-meta-1.5.3/bin \
		  $*
	*/	
		
		if(copyFile.exists()){
			if(startFile.exists()){
				startFile.delete();
			}
			try{
				startFile.createNewFile();
				
				FileInputStream readerbridge2 = new FileInputStream(copyFile);
				BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
				while((line = bufferbridge2.readLine()) != null){
					write = true;
					if(line.indexOf("generic-meta")!=-1){
						line = genericFile.toString() + " \\";
					}
					if(line.trim().length() > 2 && line.trim().substring(0,2).equals("-p")){
						write = false;
					}
					if(write){
						writeFile(line,startFile);
					}
				}
				rt.exec("chmod a+x " + startFile.toString());
			}
			catch(Exception e){
				System.out.println("ERROR: Creating startfiles\n" + e.getMessage());
			}
		}
		else{
			System.out.println("ERROR: unable to find files needed for the creation of the startfiles");
		}
	}
	public void createImitatorFile(File createMap, String toolName){
		Runtime rt= Runtime.getRuntime();
		String line;
		int lastLine = 0;
		int lastPosition;
		File copyFile = new File(meta.getParent(), "meta-studio");
		//File startFile = new File(createMap, toolName);
		File startFile = new File(createMap, toolName);

		if(copyFile.exists()){
			if(startFile.exists()){
				startFile.delete();
			}
			try{
				startFile.createNewFile();
				
				FileInputStream readerbridge2 = new FileInputStream(copyFile);
				BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
				while((line = bufferbridge2.readLine()) != null){
					
					if(lastLine == 1){
						if(line.indexOf("metastudio.MetaStudio $@")!=-1){
							lastPosition = line.lastIndexOf("}");
							if(lastPosition!=-1){
								//line = line.substring(0,lastPosition+1) + " metatoolimitator.MetaToolImitator " + startFile.getParent() + "/metatoolimitator/ $@";
								line = line.substring(0,lastPosition+1) + " metatoolimitator.MetaToolImitator " + startFile.getParent() + "/ $@";
								lastLine = 0;
							}
						}
					}
					else if(line.trim().equals("export CLASSPATH")){
						lastLine = 1;
					}
					else if(line.trim().length() > 11 && line.trim().substring(0,11).equals("CLASSPATH=\"")){
						line = "  CLASSPATH=\"" + startFile.getParent() +":" + line.trim().substring(11);
					}
					writeFile(line,startFile);
				}
				rt.exec("chmod a+x " + startFile.toString());
			}
			catch(Exception e){
				System.out.println("ERROR: Creating startfiles\n" + e.getMessage());
			}
		}
		else{
			System.out.println("ERROR: unable to find files needed for the creation of the startfiles");
		}
	}
	public void createGenericFile(File createMap, String toolName){
		Runtime rt= Runtime.getRuntime();
		String line;
		File writeInFile;
		File copyFile = new File(meta.getParent(), "generic-meta");
		File startFile = new File(createMap.getParentFile(), "generic-playback");
		File backupFile = new File(createMap.getParentFile(),"backup");
		if(backupFile.exists()){
			backupFile.delete();
		}
		try{
			if(copyFile.exists()){
				if(startFile.exists()){
					Process proc1 = rt.exec("cp " + startFile.toString() + " " + backupFile.toString());
					proc1.waitFor();
					copyFile = backupFile;
					startFile.delete();
				}
				startFile.createNewFile();
			
				FileInputStream readerbridge2 = new FileInputStream(copyFile);
				BufferedReader bufferbridge2 = new BufferedReader(new InputStreamReader(readerbridge2));
				while((line = bufferbridge2.readLine()) != null){
					//PATH="/home/poet/afstuderen/meta-toolimitator/:
					if(line.trim().length()>18 && line.trim().substring(0,6).equals("PATH=\"")){
						line = line.trim();
						line = "PATH=\"" + createMap.toString() + "/:" + line.substring(6);
					}
					else if(line.trim().length()>10 && line.trim().substring(0,10).equals("CLASSPATH=")){
						line = line.trim();
						line = "CLASSPATH=" + createMap.toString() + "/:" + line.substring(10);
					}
					else if(line.trim().length() >=31 && line.trim().substring(0,31).equals("toolbus $xargs ${toolbusdefs} \\")){
						line = "toolbus -logger $xargs ${toolbusdefs} \\";
					}
					else if(line.trim().length() >=53 && line.trim().substring(0,53).equals("meta_script=${prefix}/share/meta/start-meta-studio.tb")){
						line = "meta_script=${prefix}/share/meta/meta-playback.tb";
					}
						
					
					
					writeFile(line,startFile);
				}
				rt.exec("chmod a+x " + startFile.toString());
				if(backupFile.exists()){
					backupFile.delete();
				}
			}
			else{
				System.out.println("ERROR: unable to find files needed for the creation of the startfiles");
			}
		}
		catch(Exception e){
			System.out.println("ERROR: Creating startfiles\n" + e.getMessage());
		}
	}
}
