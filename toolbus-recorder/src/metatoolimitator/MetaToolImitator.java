package metatoolimitator;

import aterm.*;
import aterm.pure.PureFactory;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
//import javax.swing.Timer;
import java.util.Timer;
import java.util.TimerTask;

public class MetaToolImitator implements MetaToolImitatorTif{
	private static PureFactory factory;	
	private String selfProcess;
	private int timer;
	private MetaToolImitatorBridge bridge;
	private File startLocation;
	private File selfMap;
	private File sharedActionFile;
	private File testEnvironment;
	private Timer eventCounter;
	
	public MetaToolImitator(String[] args){
		timer = 0;
		startLocation = new File(args[0]);
		setSettings();
		bridge = new MetaToolImitatorBridge(factory,this);

      	try{
      		bridge.init(args);
      		bridge.connect();
      		final SwingWorker worker = new SwingWorker(){
				public Object construct(){
					
					bridge.run();
					return null;
				}
      		};
      		worker.start();
      		eventCounter = new Timer();
	      	eventCounter.schedule(new timerTaskClass(),0,1000);
      	}
      	catch(Exception e){
      		System.out.println("ERROR: Connecting tool\n" + e.getMessage());
      	}
      	
	}
	public static void main(String[] args){	
		MetaToolImitator toolimitator = new MetaToolImitator(args);
	}
	public void recTerminate(ATerm arg){
		System.exit(0);
	}
	private class timerTaskClass extends TimerTask  {
		public void run(){
			//bridge.run();
			FileInputStream readermain;
			BufferedReader buffermain;
			String line;
			//System.out.println("ImitatorTool " + selfProcess + " is checking");
			if(sharedActionFile.exists()){
				try{
					readermain = new FileInputStream(sharedActionFile);
					buffermain = new BufferedReader(new InputStreamReader(readermain));
					line = buffermain.readLine();
					if(line != null){
						//System.out.println("ImitatorTool " + selfProcess + " found file");
						checkSharedActionFile();
					}	
					buffermain.close();
					readermain.close();
				}
				catch(Exception E){
					System.out.println("Error loading sharedActionFile by imitator tool.");
				}
			}
		}
	}
	public ATerm createNewAction(){
		FileInputStream readermain;
		BufferedReader buffermain;
		String line;
		ATerm pattern, sendMessage;
		String workTool, action;
		if(sharedActionFile.exists()){
			
			try{
				readermain = new FileInputStream(sharedActionFile);
				buffermain = new BufferedReader(new InputStreamReader(readermain));
				line = buffermain.readLine();
				if(line != null){
					pattern = factory.make(line);
					workTool = pattern.getChildAt(0).toString();
					workTool = workTool.substring(1,workTool.length()-1);
					if(workTool.equals(selfProcess)){
						action = pattern.getChildAt(1).toString();
						action = action.substring(1,action.length()-1);
						line = buffermain.readLine();
						if(line != null){
							return sendMessage = factory.make(line);
						}
					}
				}
				buffermain.close();
				readermain.close();
			}
			catch(Exception E){
				System.out.println("Error loading sharedActionFile by imitator tool.\n" + E.getMessage());
			}
		}
		return null;
	}
	public void checkSharedActionFile(){
		ATerm sendMessage = createNewAction();
		if(sendMessage!=null){
			sendEvent(sendMessage);
		}
	}
	private void sendEvent(ATerm message){
		bridge.postEvent(message);
		sharedActionFile.delete();
	}
	private void sendEval(ATerm message){
		try{
			bridge.sendTerm(message);
			sharedActionFile.delete();
		}
		catch(Exception e){
			System.out.println("ERROR sending eval");
		}
	}
	public ATerm processCommunication(){
		ATerm returnValue = createNewAction();
		while(returnValue==null){
			returnValue = createNewAction();
		}
		returnValue= factory.make("snd-value(" + returnValue.toString() + ")");
		sharedActionFile.delete();
		return returnValue;
	}
	private void setSettings(){
		String line;
		String setting;
		String typeSetting;
		
		factory =  new PureFactory();
		File loadFile = new File(startLocation, "global.set");
		try{
			FileInputStream readermain = new FileInputStream(loadFile);
			BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
			while((line = buffermain.readLine()) != null){
				ATerm term = factory.make(line);
				typeSetting = term.getChildAt(0).toString();
				typeSetting = typeSetting.substring(1,typeSetting.length()-1);
				setting = term.getChildAt(1).toString();
				setting = setting.substring(1,setting.length()-1);
				if(typeSetting.equals("process")){
					setProcess(setting);	
				}
				else if(typeSetting.equals("selfMap")){
					setSelfMap(setting);
				}
				else if(typeSetting.equals("testEnvironment")){
					setTestEnvironment(setting);
				}
				else if(typeSetting.equals("sharedActionFile")){
					setSharedActionFile(setting);
				}
			}
			buffermain.close();
			readermain.close();
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	private void setProcess(String processname){
		selfProcess = processname;
	}
	private void setSelfMap(String file){
		selfMap = new File(file);
		if(!selfMap.exists()){
			System.out.println("ERROR loading selfMap setting");
			System.exit(0);
		}
	}
	private void setTestEnvironment(String file){
		testEnvironment = new File(file);
		if(!testEnvironment.exists()){
			System.out.println("ERROR loading testEnvironment setting");
			System.exit(0);
		}
	}
	private void setSharedActionFile(String file){
		sharedActionFile = new File(file);
	}

}
