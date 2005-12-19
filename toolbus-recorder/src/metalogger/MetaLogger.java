package metalogger;

import aterm.*;
import aterm.pure.PureFactory;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Vector;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class MetaLogger extends JFrame implements MetaLoggerTif{
	private static PureFactory factory;	
	private MetaLoggerBridge bridge;
	private MetaFilter filter;
	private MetaRecord record;
	private File saveFile;
	private File saveMap;
	private File processFile;
	private File meta;
	private File tbMap;
	private JButton selectButton;
	private JButton deselectButton;
	private JButton setFilters;
	private JTextArea filters;
	private JFrame z;
	private JScrollPane scroller;
	private Vector fileList;
	private String processString;
	private Container zc2;
	
	public static void main(String[] args) throws IOException{	
		MetaLogger recorder = new MetaLogger(args);	
	}
	public MetaLogger(String[] args) throws IOException{
		fileList = new Vector();
		boolean saveLocationChoosen = false;
		
		Runtime rt = Runtime.getRuntime();
        Process proc = rt.exec("which meta");
        InputStream stderr = proc.getInputStream();
        InputStreamReader isr = new InputStreamReader(stderr);
        BufferedReader br = new BufferedReader(isr);
        meta = new File(br.readLine());
        tbMap = new File(new File(meta.getParent()).getParent() + "/share/meta");
        processFile = new File(new File(meta.getParent()).getParent() + "/share/meta-test/processlist.atl");

        if(!processFile.exists()){
        	System.out.println("ERROR: Can't locate processFile");  	
        	System.exit(0);
        }

        
        File startMetaFile = new File(tbMap.toString() + "/start-meta-studio.tb");
        findUsedFiles(startMetaFile);
        
	    factory =  new PureFactory();
	    bridge = new MetaLoggerBridge(factory,this);
      	bridge.init(args);
	    bridge.connect();
	    record = new MetaRecord(bridge, factory);
	    filter = new MetaFilter(factory, record);
	    record.setFilter(filter);

		ActionEventHandler handler = new ActionEventHandler();
		
		z = new JFrame("MetaEnvironment Recorder");
		z.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container zc = z.getContentPane();
		zc.setLayout(new FlowLayout());

		filters = new JTextArea(5,60);
		filters.setEditable(true);
		scroller = new JScrollPane(filters);

		
		JInternalFrame checkboxField = new JInternalFrame();
		zc2 = checkboxField.getContentPane();
		zc2.setSize(300,200);
		zc2.setLayout(new GridLayout(0,3));
		JLabel label1 = new JLabel("Select the processes you wish to log.");
		zc.add(label1);
		JLabel label2 = new JLabel("Logging processes which generate events is needed to automate the test.");
		zc.add(label2);
		setProcessCheckboxes(zc2);

		zc2.setVisible(true);
		
		setFilters = new JButton("Set filters");
		setFilters.addActionListener(handler);
		zc.add(zc2);
		
		selectButton = new JButton("Select all");
		selectButton.addActionListener(handler);
		zc.add(selectButton);
		deselectButton = new JButton("Deselect all");
		deselectButton.addActionListener(handler);
		zc.add(deselectButton);
		
		JLabel labelz = new JLabel("                                                                                                                                                ");
		zc.add(labelz);
		
		JLabel label3 = new JLabel("You can add custom filters by providing the names of processes which are not shown in the list.");
		zc.add(label3);
		JLabel label4 = new JLabel("Seperate them by an enter. Note: This is case sensitive");
		zc.add(label4);
		zc.add(scroller);
		zc.add(setFilters);
		
		z.setSize(700,700);
		z.setVisible(true);

	    while(!saveLocationChoosen){
	    	saveLocationChoosen = record.saveTest();
	    }
	}
	private class ActionEventHandler implements ActionListener {
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == selectButton){
				JCheckBox box;
				for(int i=0;i<zc2.getComponentCount();i++){
					box = (JCheckBox)zc2.getComponent(i);
					box.setSelected(true);
				}
			}
			else if(e.getSource() == deselectButton){
				JCheckBox box;
				for(int i=0;i<zc2.getComponentCount();i++){
					box = (JCheckBox)zc2.getComponent(i);
					box.setSelected(false);
				}
			}
			else if (e.getSource() == setFilters){
				String text = filters.getText();
				int enterPosition;
				String process;
				JCheckBox box;
				
				int confirmWindow = JOptionPane.showConfirmDialog(null,"Are you sure you want to start the logging with these filters?","Confirmation",JOptionPane.YES_NO_OPTION,JOptionPane.INFORMATION_MESSAGE);
				
				if(confirmWindow == JOptionPane.YES_OPTION){
					for(int i=0;i<zc2.getComponentCount();i++){
						box = (JCheckBox)zc2.getComponent(i);
						if(box.isSelected()){
							filter.addFilter(box.getText(),findProcessEvents(box.getText()));
						}
					}
					
					while((enterPosition = text.indexOf("\n"))!=-1){
						process = text.substring(0,enterPosition);
						filter.addFilter(process,findProcessEvents(process));
						text = text.substring(enterPosition+1);
					}
					if(!text.trim().equals("")){
						filter.addFilter(text,findProcessEvents(text));
					}
					z.setVisible(false);
					bridge.run();
				}
			}
		}
	}
	public void recTerminate(ATerm arg){
	    System.exit(0);
	}
	private void setProcessCheckboxes(Container placeIn){
		String line, processName;
		ATerm processLine;
		JCheckBox box;
		int selected;
		try{
	 		FileInputStream readermain = new FileInputStream(processFile);
	 		BufferedReader buffermain = new BufferedReader(new InputStreamReader(readermain));
	 		while((line = buffermain.readLine()) != null){
	 			processLine = factory.make(line);
	 			processName = processLine.getChildAt(0).toString();
	 			processName = processName.substring(1, processName.length()-1);
	 			selected = Integer.parseInt(processLine.getChildAt(1).toString());
	 			box = new JCheckBox(processName);
	 			if(selected==1){
	 				box.setSelected(true);
	 			}
	 			placeIn.add(box);
	 		}
		}
		catch(Exception e){
			System.out.println("ERROR: Can't read the processFile");
			System.out.println(e.getMessage());
			System.exit(0);
		}
	}
	public ATerm recMonitor(ATerm t0){
	 	
	 	if(filter.filterTerm(t0, factory)){
	 		record.recordTerm(t0);
	 	}
	 	return factory.make("snd-continue(<term>)",t0.getChildAt(0)); 	
	}
	public boolean findProcessEvents(String filter){
		int startDeclaration = processString.indexOf("process " + filter);
		if(startDeclaration!=-1){
			int endDeclaration = processString.indexOf("endlet",startDeclaration) + 6;
			if(endDeclaration!=-1){
				String process = processString.substring(startDeclaration,endDeclaration);
				if(process.indexOf("rec-event(")!=-1){
					return true;
				}
			}
		}
		return false;
	}
	public void findUsedFiles(File checkFile){
	 	Runtime rt = Runtime.getRuntime();
	 	Process proc;
	 	InputStream stderr;
	 	InputStreamReader isr;
	 	BufferedReader br;
	 	String line;
	 	String tempLine = "";
	 	String tempLine2="";
	 	String fileContent="";
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
}
