package metastudio.components;

import java.io.File;

import javax.swing.JFileChooser;

import metastudio.MultiBridge;
import metastudio.utils.ExtensionFilter;
import aterm.ATerm;
import aterm.ATermFactory;

public class FileDialog extends ToolComponent {
    public FileDialog(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
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

        return getFactory().make("file-name(<str>)", result);
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

        int option = chooser.showDialog(this, label);
        if (option == JFileChooser.APPROVE_OPTION) {
            return chooser.getSelectedFile();
        }

        return null;
    }
    
}

