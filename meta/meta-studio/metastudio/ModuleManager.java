package metastudio;

import java.util.*;

public class ModuleManager
{
  private Map moduleTable;
  private List moduleSelectionListeners;

  //{{{ public ModuleManager()

  public ModuleManager()
  {
    moduleTable = new HashMap();
    moduleSelectionListeners = new LinkedList();
  }

  //}}}

  //{{{ public void addModuleSelectionListener(ModuleSelectionListener listener)

  public void addModuleSelectionListener(ModuleSelectionListener listener)
  {
    moduleSelectionListeners.add(listener);
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
    moduleTable.put(module.getName(), module);
  }

  //}}}
  //{{{ public void removeModule(String name)

  public void removeModule(String name)
  {
    moduleTable.remove(name);
  }

  //}}}
  //{{{ public void clearModules()

  public void clearModules()
  {
    moduleTable.clear();
  }

  //}}}

}
