package metastudio;

import metastudio.graph.*;

import java.awt.event.*;

public class ImportGraphPanel
  extends GraphPanel
  implements ModuleSelectionListener
{
  private ModuleTreeModel moduleManager;

  //{{{ public ImportGraphPanel(final ModuleManager moduleManager)

  public ImportGraphPanel(final ModuleTreeModel moduleManager)
  {
    super("import");
    this.moduleManager = moduleManager;
    moduleManager.addModuleSelectionListener(this);

    MouseListener listener
      = new MouseAdapter() {
	public void mouseClicked(MouseEvent event)
	{
	  Node node = getNodeAt(event.getX(), event.getY());
	  if (node != getSelectedNode()) {
	    Module module;
	    if (node == null) {
	      module = null;
	    } else {
	      module = moduleManager.getModule(node.getName());
	    }
	    moduleManager.selectModule(module);
	  }
	}
      };
    addMouseListener(listener);
  }

  //}}}
  //{{{ public void moduleSelected(Module module)

  public void moduleSelected(Module module)
  {
    if (module == null) {
      setSelectedNode(null);
    } else {
      setSelectedNode(getNode(module.getName()));
    }
  }

  //}}}
}
