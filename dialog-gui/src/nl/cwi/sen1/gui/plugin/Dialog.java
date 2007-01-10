package nl.cwi.sen1.gui.plugin;

import java.io.File;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;
import javax.swing.filechooser.FileFilter;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImpl;
import aterm.ATerm;
import aterm.ATermList;

public class Dialog extends DefaultStudioPlugin implements DialogTif {
    private static final String WORKING_DIRECTORY = "user.dir";

    private static final String TOOL_NAME = "dialog";

    private Studio studio;

    private Factory factory;

    private ProgressList progressList;

    private JFileChooser sharedChooser;
    private FileFilter sharedFilter;

    public Dialog() {
        sharedChooser = new JFileChooser(System.getProperty(WORKING_DIRECTORY));
    }

    public String getName() {
        return TOOL_NAME;
    }

    public void initStudioPlugin(Studio studio) {
        this.studio = studio;
        DialogBridge bridge = new DialogBridge(studio.getATermFactory(), this);
        factory = Factory.getInstance((aterm.pure.PureFactory) studio
                .getATermFactory());
        studio.connect(getName(), bridge);
    }

    public ATerm showDirectoryDialog(String title, ATerm paths) {
        JFileChooser chooser = sharedChooser;

        if (!((ATermList) paths).isEmpty()) {
            DialogFileSystemView fsv = new DialogFileSystemView(factory
                    .PropertyListFromTerm(paths));
            chooser = new JFileChooser(fsv);
            chooser.setFileView(new DialogFileView(fsv));
        }
        chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

        chooser.setSelectedFile(new File(""));
        if (chooser.showDialog(StudioImpl.getFrame(), title) == JFileChooser.APPROVE_OPTION) {
            String path = chooser.getSelectedFile().getAbsolutePath();
            return studio.getATermFactory().make(
                    "snd-value(directory-dialog-approve(<str>))", path);
        }
        return studio.getATermFactory().make(
                "snd-value(directory-dialog-cancel)");
    }

    public ATerm showFileDialog(String title, ATerm paths,
            final String extension) {
        JFileChooser chooser = sharedChooser;

        if (!((ATermList) paths).isEmpty()) {
            DialogFileSystemView fsv = new DialogFileSystemView(factory
                    .PropertyListFromTerm(paths));
            chooser = new JFileChooser(fsv);
            chooser.setFileView(new DialogFileView(fsv));
        }

        chooser.removeChoosableFileFilter(sharedFilter);
        sharedFilter = new FileFilter() {
            public boolean accept(File file) {
                if (file.isDirectory()) {
                    return true;
                }

                String filename = file.getName();
                return filename.endsWith(extension);
            }

            public String getDescription() {
                return "*" + extension;
            }
        };

        chooser.setSelectedFile(new File(""));
        chooser.addChoosableFileFilter(sharedFilter);
        
        
        if (chooser.showDialog(StudioImpl.getFrame(), title) == JFileChooser.APPROVE_OPTION) {
            File file = chooser.getSelectedFile();
            
            String path = buildSelectedFile(file, extension);
            return studio.getATermFactory().make(
                    "snd-value(file-dialog-approve(<str>))", path);
        }
        return studio.getATermFactory().make("snd-value(file-dialog-cancel)");
    }
    
    private String buildSelectedFile(File file, String extension) {
    	String path = file.getAbsolutePath();
    	String last = file.getName();
    	
    	if (last.lastIndexOf('.') == -1) { 
    		/* no extension */
    		path = path.concat(extension.startsWith(".") ? extension : ("." + extension));
    	}
    	else if (last.endsWith(".")) {
    		/* file ends in . */
    		path = path.concat(extension.startsWith(".") ? extension.substring(1) : extension);
    	}
    	
    	return path;
    }

    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }

    public void showProgressMessage(String message) {
        if (progressList != null) {
            progressList.addMessage(message);
        }
    }

    public void showProgressList(final String title) {
        progressList = new ProgressList(StudioImpl.getFrame(), title, true);
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                progressList.setVisible(true);
            }
        });
    }

    public void closeProgressList() {
        if (progressList != null) {
            progressList.dispose();
        }
    }

    public void showProgressMessageWithArguments(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        if (progressList != null) {
            progressList.addMessage(message);
        }
    }

    public ATerm showQuestionDialog(String question) {
        int choice = JOptionPane.showConfirmDialog(StudioImpl.getFrame(), question);

        if (choice == JOptionPane.YES_OPTION) {
            return studio.getATermFactory().make("snd-value(answer(yes))");
        }
        if (choice == JOptionPane.NO_OPTION) {
            return studio.getATermFactory().make("snd-value(answer(no))");
        }

        return studio.getATermFactory().make("snd-value(answer(cancel))");
    }

    public void showErrorDialog(String errorMessage) {
        if (progressList != null) {
            progressList.dispose();
        }
        JOptionPane.showMessageDialog(StudioImpl.getFrame(), errorMessage, "Error",
                JOptionPane.ERROR_MESSAGE);
    }

    public void showErrorDialogWithArguments(String errorMessage, ATerm args) {
        String message = StringFormatter.format(errorMessage, (ATermList) args);
        if (progressList != null) {
            progressList.dispose();
        }
        JOptionPane.showMessageDialog(StudioImpl.getFrame(), message, "Error",
                JOptionPane.ERROR_MESSAGE);
    }
}
