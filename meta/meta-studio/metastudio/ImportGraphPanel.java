package metastudio;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.graph.Node;

public class ImportGraphPanel extends GraphPanel implements ModuleSelectionListener {
  public ImportGraphPanel(final ModuleTreeModel moduleManager) {
    super("import");
    moduleManager.addModuleSelectionListener(this);

    MouseListener listener = new MouseAdapter() {
      public void mouseClicked(MouseEvent event) {
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

  public void moduleSelected(Module module) {
    if (module == null) {
      setSelectedNode(null);
    } else {
      setSelectedNode(getNode(module.getName()));
    }
  }
}
