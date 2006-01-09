package nl.cwi.sen1.gui.plugin;

import java.io.File;
import java.util.Arrays;
import java.util.List;

import javax.swing.filechooser.FileView;

public class DialogFileView extends FileView {
    DialogFileSystemView fsv;

    public DialogFileView(DialogFileSystemView fsv) {
        this.fsv = fsv;
    }

    public String getName(File f) {
        if (fsv.isRoot(f)) {
	    return fsv.getRootLabel(f);
        }
        return super.getName(f);
    }
}
