package metastudio.components.dialogtool;

import java.io.File;
import java.io.IOException;
import java.util.Set;
import java.util.TreeSet;

import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

import metastudio.utils.ExtensionFilter;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class DialogTool implements DialogToolTif, Runnable {
	private DialogToolBridge bridge;
	private ATermFactory factory;
	private JComponent parent;
	
    public DialogTool(JComponent parent, ATermFactory factory, String [] args) {
    	this.parent = parent;
    	this.factory = factory;
    	
    	try {
    		bridge = new DialogToolBridge(factory, this);
    		bridge.init(args);
    		bridge.setLockObject(this);
    		bridge.connect("dialog-tool", null, -1);
    	} catch (IOException e) {
    		e.printStackTrace();
    	}
    }

    public ATerm showFileDialog(String label, String loc, String extension) {
        String location;

        if (!loc.equals("")) {
            location = loc;
        } else {
            location = System.getProperty("user.dir");
        }

        File file = showFileBrowser(label, location, extension, "*" + extension);
        String result = "";

        if (file != null) {
            result = file.getAbsolutePath();
        }

        return factory.make("snd-value(file-name(<str>))", result);
    }

    private File showFileBrowser(
        String label,
        String location,
        String extension,
        String desc) {
        JFileChooser chooser = new JFileChooser(location);
        String[] exts = { extension };
        ExtensionFilter filter = new ExtensionFilter(exts, desc);
        chooser.setFileFilter(filter);

        int option = chooser.showDialog(parent, label);
        if (option == JFileChooser.APPROVE_OPTION) {
            return chooser.getSelectedFile();
        }

        return null;
    }
    
    public ATerm showQuestionDialog(String question) {
    	int choice = JOptionPane.showConfirmDialog(parent, question);

    	if (choice == JOptionPane.YES_OPTION) {
    		return factory.make("snd-value(answer(yes))");
    	}
    	if (choice == JOptionPane.NO_OPTION) {
    		return factory.make("snd-value(answer(no))");
    	}
    	
    	return factory.make("snd-value(answer(cancel))");
    }
    
    public void showListChoice(String title, String question, ATerm choices) {
    	Object answer = JOptionPane.showInputDialog(parent,question,title, JOptionPane.QUESTION_MESSAGE,
    			null, getList((ATermList) choices), "");
    	
    	if (answer != null) {
    		String str = (String) answer;
    		bridge.postEvent(factory.make("list-choice(<str>,<str>)",
    				title, str));
    	}
    	else {
    		bridge.postEvent(factory.make("cancel-list-choice(<str>)",
    				title));
    	}
    }
    
    private Object[] getList(ATermList aterms) {
    	Set set = new TreeSet();
    	
    	for (int i = 0; !aterms.isEmpty(); i++, aterms = aterms.getNext()) {
    		ATerm first = aterms.getFirst();
    		if (first.getType() == ATerm.APPL) {
    			ATermAppl appl = (ATermAppl) first;
    			set.add(appl.getName());
    		}
    	}

    	return set.toArray();
    }

	public void recTerminate(ATerm t0) {
		
	}

 	public void run() {
		bridge.run();
		
	}

	public void recAckEvent(ATerm t0) {
		
	}
    
}

