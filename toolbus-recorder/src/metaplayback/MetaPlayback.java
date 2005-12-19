package metaplayback;

import aterm.*;
import aterm.pure.PureFactory;
//import java.awt.*;
import java.awt.event.*;
import java.io.*;

//import javax.swing.JFrame;
//import javax.swing.JButton;
//import javax.swing.JOptionPane;
//import javax.swing.JTextField;
import javax.swing.Timer;

public class MetaPlayback implements MetaPlaybackTif{
	private static PureFactory factory;	
	private boolean firstMessage;
	private boolean verboseModus;
	private MetaPlaybackBridge bridge;
	private MetaFilter filter;
	private ActionList actionList;
	private ActionList valueList;
	private MetaLoad load;
	private MetaMessageList messageList;
	private File saveFile;
	private File saveMap;
	private File sharedActionFile;
	private File startFile;
	private int timer;
	private int actionNo;
	private int executeCounter;
	private FileWriter writer;
	private BufferedWriter buffer;
	private Timer eventCounter;
	
	public static void main(String[] args) throws IOException{	
		MetaPlayback recorder = new MetaPlayback(args);	
	}
	public void showProgress(String message){
		if(verboseModus){
			System.out.println("Progress: " + message);
		}
	}
	public MetaPlayback(String[] args) throws IOException{
		firstMessage = false;
		verboseModus = false;
		timer = 0;
		actionNo = 0;

		Runtime rt = Runtime.getRuntime();
        Process proc = rt.exec("which meta");
        InputStream stderr = proc.getInputStream();
        InputStreamReader isr = new InputStreamReader(stderr);
        BufferedReader br = new BufferedReader(isr);
        File meta = new File(br.readLine());
        File changingTerms = new File(new File(meta.getParent()).getParent() + "/share/meta-test/changingterms.atl");
        File playbackSettings = new File(new File(meta.getParent()).getParent() + "/share/meta-test/playbacksettings.atl");
		File startSettingFile = new File(System.getProperty("user.dir"),"metaplaybacksettings.atl");
		
		
		
        if(!changingTerms.exists()){
        	System.out.println("ERROR: Can't locate changingTerms");
        	System.out.println(changingTerms.toString());
        	System.exit(0);
        }
        if(!playbackSettings.exists()){
        	System.out.println("ERROR: Can't locate playbackSettings");
        	System.out.println(playbackSettings.toString());
        	System.exit(0);
        }
		if(!startSettingFile.exists()){
			System.out.println("ERROR: No startSettingFile found");
			System.exit(0);
		}
		
        loadSettings(playbackSettings);
        loadStartSettings(startSettingFile);
        
		factory =  new PureFactory();
		bridge = new MetaPlaybackBridge(factory,this);
    	filter = new MetaFilter(factory);
    	actionList = new ActionList(factory);
		load = new MetaLoad(factory, bridge);
		int temp = 0;
		showProgress("Objects created");
		if(startFile.exists()){
			load.loadTest(startFile);
			filter = load.getFilters();
			filter.setExecuteMaps(System.getProperty("user.dir"), load.getExecuteMap().toString());
			actionList = load.getActionList();
			valueList = load.getValueList();
			
			sharedActionFile = load.getSharedActionFile();
			messageList = new MetaMessageList(factory);
			messageList.addMessagesFromFileElement(load.getFileList());
			filter.setMessageList(messageList);
			filter.loadChangingTermList(changingTerms);
			showProgress("Information read");
			
	      	bridge.init(args);
		    bridge.connect();
		    
		    ActionEventCounter counter = new ActionEventCounter();
		    eventCounter = new Timer(1000, counter);
			
		    final SwingWorker worker = new SwingWorker(){
				public Object construct(){
					showProgress("Running the test: note this can take a couple of minutes");
				    eventCounter.start();
					bridge.run();
					return null;
				}
		    };
		    worker.start();
		}
		else
		{
			System.out.println("ERROR: Startfile is missing");
			System.exit(0);
		}
	}
	private File getStartFile(){
		String startMap = System.getProperty("user.dir");
		int lastUnderscore = startMap.lastIndexOf("_");
		return new File(startMap.substring(0,lastUnderscore));
	}
	private class ActionEventCounter implements ActionListener {
		public void actionPerformed(ActionEvent e){
			FileInputStream readermain;
			BufferedReader buffermain;
			String line;
			
			timer++;
			if(timer > executeCounter){
				if(sharedActionFile.exists()){
					try{
						readermain = new FileInputStream(sharedActionFile);
						buffermain = new BufferedReader(new InputStreamReader(readermain));
						line = buffermain.readLine();
						if(line != null){
							sharedActionTimeout();
						}
						else{
							newSharedAction();
						}		
					}
					catch(Exception E){
						System.out.println("ERROR: Couldn't create sharedAction file\n" + E.getMessage());
						System.out.println(sharedActionFile.toString());
					}
				}
				else{
					newSharedAction();
				}
				timer = 0;
			}
		}
	}
	public void sharedActionTimeout(){
		
	}
	public void loadStartSettings(File file){
		String line;
		String setting;
		String typeSetting;
		factory = new PureFactory();
		try{
			FileInputStream readermain = new FileInputStream(file);
			BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				ATerm term = factory.make(line);
				typeSetting = term.getChildAt(0).toString();
				typeSetting = typeSetting.substring(1,typeSetting.length()-1);
				setting = term.getChildAt(1).toString();
				setting = setting.substring(1,setting.length()-1);
				if(typeSetting.equals("startFile")){
					setStartFile(setting);	
				}
			}
			buffermain.close();
			readermain.close();
		}
		catch(Exception e){
			System.out.println("ERROR: loading settings");
			System.out.println(e.getMessage());
		}
	}
	public void setStartFile(String setting){
		startFile = new File(System.getProperty("user.dir"),setting);
		
		if(!startFile.exists()){
			System.out.println("ERROR: No startFile found");
			System.exit(0);
		}
	}
	public void loadSettings(File file){
		String line;
		String setting;
		String typeSetting;
		factory = new PureFactory();
		try{
			FileInputStream readermain = new FileInputStream(file);
			BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				ATerm term = factory.make(line);
				typeSetting = term.getChildAt(0).toString();
				typeSetting = typeSetting.substring(1,typeSetting.length()-1);
				setting = term.getChildAt(1).toString();
				setting = setting.substring(1,setting.length()-1);
				if(typeSetting.equals("verbose")){
					setVerbose(setting);	
				}
				else if(typeSetting.equals("timer")){
					setExecuteCounter(setting);	
				}
			}
			buffermain.close();
			readermain.close();
		}
		catch(Exception e){
			System.out.println("ERROR: loading settings");
			System.out.println(e.getMessage());
		}
	}
	private void setVerbose(String setting){
		int setVerbose = Integer.parseInt(setting);
		if(setVerbose==1){
			verboseModus = true;
		}
	}
	public void setExecuteCounter(String timerString){
		executeCounter = Integer.parseInt(timerString);
	}
	public void newSharedAction(){
		try{
			if(!sharedActionFile.exists()){
				sharedActionFile.createNewFile();
				int activeActionNo = actionList.getActiveActionNo();

				if(activeActionNo<=actionList.getActionNo()){
					actionList.setVisited(activeActionNo-1);
					String processName = actionList.getProcessName(activeActionNo);
					writeFile("performAction(\""+processName+"\", \"rec-event\")",sharedActionFile);
					writeFile(messageList.getNextMetaMessage(processName, "rec-event").toString(),sharedActionFile);
					
					showProgress("Trigger event for " + processName);
					
					actionList.setActiveActionNo(activeActionNo+1);
				}
			}
		}
		catch(Exception e){
			System.out.println("Error creating new shared action\n" + e.getMessage());
			System.out.println(sharedActionFile.toString());
		}
	}
	public void prepareValue(String processName){
		String stringdata, bafPart;
		int beginBaf;

		if(filter.getHasToolFromProcessName(processName)){
			try{
				if(!sharedActionFile.exists()){
					sharedActionFile.createNewFile();
				}
				int activeActionNo = valueList.getActiveActionNo();
				if(activeActionNo<=valueList.getActionNo()){
					valueList.setVisited(activeActionNo-1);
					writeFile("performAction(\""+processName+"\", \"rec-value\")",sharedActionFile);
				
					stringdata = messageList.getNextMetaMessage(processName, "rec-value").toString();
					beginBaf = stringdata.indexOf("\"_baf-recoded_\"(\"");
					
					while(beginBaf!=-1){
						stringdata = createMessageWithBaf(stringdata);
						beginBaf = stringdata.indexOf("\"_baf-recoded_\"(\"");
					}
					
					showProgress("Prepare value for " + processName);
							
					writeFile(stringdata,sharedActionFile);
					valueList.setActiveActionNo(activeActionNo+1);
				}
			}
			catch(Exception e){
				System.out.println("ERROR: creating new shared action.");
				System.out.println(e.getMessage());
			}
		}
	}
	public String createMessageWithBaf(String stringdata){
		int beginBaf, endBaf, hashvalue;
		String bafPart;
		beginBaf = stringdata.indexOf("\"_baf-recoded_\"(\"");
		
		if(beginBaf!=-1){
			endBaf = stringdata.indexOf("\"", beginBaf + 17);
			
			if(endBaf!=-1){
				hashvalue = Integer.parseInt(stringdata.substring(beginBaf + 17,endBaf));
				bafPart = bridge.getBaf(hashvalue);
				if(bafPart!=null){
					stringdata = stringdata.substring(0,beginBaf) + "\"_baf-encoded_\"(\"" + bafPart + stringdata.substring(endBaf);
				}
			}
		}
			return stringdata;
	}
	private String addMessageType(ATerm term){
		String varType = term.toString();
		int startPosition = varType.indexOf(",");
		if(startPosition > -1){
			int endPosition = varType.indexOf("{", startPosition);
			if (endPosition > -1){
				return "<" +varType.substring(startPosition + 1, endPosition) + ">";
			}
		}
		return "<term>";	
	}
	public void recTerminate(ATerm arg){
		showProgress("Printing the result");
		int missedMessages = messageList.getNoUnpassedMessages();
		int unexpectedMessages = filter.getUnknownMessages().getNoUnpassedMessages();
		
		if(missedMessages + unexpectedMessages == 0){
			System.out.println("Finished without errors");
		}
		else{
			if(missedMessages > 0){
				System.out.println("****************************************");
				System.out.println("* MISSED MESSAGES                      *");
				messageList.printMessages();
			}
			if(unexpectedMessages > 0){
				System.out.println("****************************************");
				System.out.println("* UNEXPECTED MESSAGES                  *");
				filter.getUnknownMessages().printMessages();
			}
		}
		System.exit(0);
	}
	 public ATerm recMonitor(ATerm t0){
	 	timer = 0;
	 	if(filter.filterTerm(t0)){
	 		int pid = Integer.parseInt(t0.getChildAt(0).toString());
	 		String communicationType = t0.getChildAt(1).toString();
			String process = filter.getProcessFromPid(pid);
			
			showProgress("Received " + communicationType + " from " + process);
			
			if(communicationType.equals("snd-do") || communicationType.equals("rec-event") || communicationType.equals("snd-ack-event") || communicationType.equals("rec-value")){	
				filter.compareMessages(t0);
			}
			if(communicationType.equals("snd-eval")){
				filter.compareMessages(t0);
				prepareValue(process);
			}
	 	}
	 	return factory.make("snd-continue(<term>)",t0.getChildAt(0)); 	
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
			System.out.println("ERROR:  writing file");
		}
	}
}
