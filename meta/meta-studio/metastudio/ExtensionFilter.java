package metastudio;

import java.io.File;
import javax.swing.filechooser.*;

public class ExtensionFilter
  extends FileFilter
{
  private String[] extensions;
  private String description;

  public ExtensionFilter(String[] exts, String descr)
  {
    extensions = new String[exts.length];
    for (int i=exts.length-1; i>=0; i--) {
      extensions[i] = exts[i].toLowerCase();
    }

    description = descr;
  }

  public boolean accept(File f)
  {
    if (f.isDirectory()) {
      return true;
    }

    String name = f.getName().toLowerCase();
    for (int i=extensions.length-1; i>=0; i--) {
      if (name.endsWith(extensions[i])) {
	return true;
      }
    }

    return false;
  }

  public String getDescription()
  {
    return description;
  }
}
