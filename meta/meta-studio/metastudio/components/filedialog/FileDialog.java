package metastudio.components.filedialog;

import java.io.File;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JFileChooser;

import metastudio.utils.ExtensionFilter;
import aterm.ATerm;
import aterm.ATermFactory;

public class FileDialog implements FileDialogTif, Runnable {
	private FileDialogBridge bridge;
	private ATermFactory factory;
	private JComponent parent;
	
    public FileDialog(JComponent parent, ATermFactory factory, String [] args) {
    	this.parent = parent;
    	this.factory = factory;
    	
    	try {
    		bridge = new FileDialogBridge(factory, this);
    		bridge.init(args);
    		bridge.setLockObject(this);
    		bridge.connect("file-dialog", null, -1);
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

        return factory.make("file-name(<str>)", result);
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

	/* (non-Javadoc)
	 * @see metastudio.components.filedialog.FileDialogTif#recTerminate(aterm.ATerm)
	 */
	public void recTerminate(ATerm t0) {
		// TODO Auto-generated method stub
		
	}

	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	public void run() {
		bridge.run();
		
	}
    
}

