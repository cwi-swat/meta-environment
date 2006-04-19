package nl.cwi.sen1.gui.plugin;

import java.io.File;
import java.util.Arrays;
import java.util.List;

import javax.swing.filechooser.FileSystemView;

import nl.cwi.sen1.configapi.types.Property;
import nl.cwi.sen1.configapi.types.PropertyList;

public class DialogFileSystemView extends FileSystemView {
    File[] roots;
    String[] labels;

    public DialogFileSystemView(PropertyList props) {
      roots = new File[props.getLength()];
      labels = new String[props.getLength()];

      for (int i = 0; !props.isEmpty(); i++) {
	Property root = props.getHead(); 

	roots[i] = new File(root.getPath());
	labels[i] = root.getLabel();

	props = props.getTail();
      }
    }

    public File createNewFolder(File containingDir) {
        return null;
    }

    public File[] getRoots() {
        return roots;
    }

    public String getRootLabel(File root) {
      List rootList = Arrays.asList(roots);
      return labels[rootList.indexOf(root)];
    }

    public File getHomeDirectory() {
        if (roots.length > 0) {
            return roots[0];
        }
        return null;
    }

    public File getDefaultDirectory() {
        return getHomeDirectory();
    }
}
