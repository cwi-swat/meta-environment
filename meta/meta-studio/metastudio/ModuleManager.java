package metastudio;

import java.util.*;
import javax.swing.*;

public class ModuleManager
{
  private Map moduleTable;
  private List moduleList;
  private List moduleSelectionListeners;
  private ModuleManagerListModel model;

  //{{{ public ModuleManager()

  public ModuleManager()
  {
    moduleTable = new HashMap();
    moduleList = new ArrayList();
    moduleSelectionListeners = new LinkedList();

    model = new ModuleManagerListModel() {
      public Object getElementAt(int index)
      {
	return moduleList.get(index);
      }
      public int getSize() {
	return moduleList.size();
      }
    };
  }

  //}}}

  //{{{ public void addModuleSelectionListener(ModuleSelectionListener listener)

  public void addModuleSelectionListener(ModuleSelectionListener listener)
  {
    moduleSelectionListeners.add(listener);
  }

  //}}}
  //{{{ public void selectModule(String moduleName)

  public void selectModule(String moduleName)
  {
    selectModule(getModule(moduleName));
  }

  //}}}
  //{{{ public void selectModule(Module module)

  public void selectModule(Module module)
  {
    Iterator iter = moduleSelectionListeners.iterator();
    while (iter.hasNext()) {
      ModuleSelectionListener l = (ModuleSelectionListener)iter.next();
      l.moduleSelected(module);
    }
  }

  //}}}
  //{{{ public Module getModule(String name)

  public Module getModule(String name)
  {
    return (Module)moduleTable.get(name);
  }

  //}}}
  //{{{ public void addModule(Module module)

  public void addModule(Module module)
  {
    String name = module.getName();
    if (moduleTable.put(name, module) == null) {
      // Added a new module
      for (int i=0; i<moduleList.size(); i++) {
	String cur = (String)moduleList.get(i);
	if (cur.compareTo(name) > 0) {
	  moduleList.add(i, name);
	  model.fireIntervalAdded(this, i, i);
	  return;
	}
      }
      int index = moduleList.size();
      moduleList.add(name);
      model.fireIntervalAdded(this, index, index);
    }
  }

  //}}}
  //{{{ public void removeModule(String name)

  public void removeModule(String name)
  {
    moduleTable.remove(name);
    int index = moduleList.indexOf(name);
    moduleList.remove(index);
    model.fireIntervalRemoved(this, index, index);
  }

  //}}}
  //{{{ public void clearModules()

  public void clearModules()
  {
    int end = moduleList.size()-1;
    if (end >= 0) {
      moduleTable.clear();
      moduleList.clear();
      model.fireIntervalRemoved(this, 0, end);
    }
  }

  //}}}

  //{{{ public ListModel getListModel()

  public ListModel getListModel()
  {
    return model;
  }

  //}}}
}

abstract class ModuleManagerListModel
  extends AbstractListModel
{
  protected void fireIntervalAdded(Object source, int index0, int index1) {
    super.fireIntervalAdded(source, index0, index1);
  }
  protected void fireIntervalRemoved(Object source, int index0, int index1) {
    super.fireIntervalRemoved(source, index0, index1);
  }
}
