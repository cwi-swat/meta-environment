package metastudio.components.graphs;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JComponent;
import javax.swing.SwingUtilities;

import metastudio.UserInterfaceBridge;
import metastudio.components.ModulePopupMenu;
import metastudio.components.ModuleSelectionListener;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class ImportGraphPanel
    extends ZoomableGraphPanel
    implements ModuleSelectionListener {
    private GraphPanel panel;
    private ModuleTreeModel manager;

    public ImportGraphPanel(
        MetaGraphFactory factory,
        UserInterfaceBridge bridge,
        final ModuleTreeModel moduleManager) {
        super(factory, bridge, "import");
        this.manager = moduleManager;

        panel = getGraphPanel();

        manager.addModuleSelectionListener(this);

        panel.addMouseListener(makeMouseListener(moduleManager));

        initialize();
    }

    private void initialize() {
        MetaGraphFactory f = getGraphFactory();
        layoutGraph(
            f.makeGraph_Default(
                f.makeNodeList_Empty(),
                f.makeEdgeList_Empty(),
                f.makeAttributeList_Empty()));
    }

    private MouseListener makeMouseListener(final ModuleTreeModel moduleManager) {
        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                Node node = panel.getNodeAt(event.getX(), event.getY());
                ModulePopupMenu.setPopupLocation(
                    (JComponent) event.getSource(),
                    event.getX(),
                    event.getY());

                Module module;

                if (node == null) {
                    module = null;
                } else {
                    module = moduleManager.getModule(node.getLabel());
                    if (event.isPopupTrigger()
                        || SwingUtilities.isRightMouseButton(event)) {
                        postEvent(
                            getFactory().make(
                                "get-buttons(module-popup,<str>)",
                                node.getLabel()));
                    }

                }
                moduleManager.selectModule(module);
            }
        };
        return listener;
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            panel.setSelectedNode(null);
        } else {
            panel.setSelectedNode(panel.getNode(module.getName()));
        }
    }

    public void newGraph(ATerm importRelation) {
        ATermList imports = (ATermList) importRelation;
        setModules(imports);
        setImports(imports);

        Graph graph = Graph.fromImportList(getGraphFactory(), imports);
        layoutGraph(graph);
    }

    private void setModules(ATermList importList) {
        manager.clearModules();

        while (!importList.isEmpty()) {
            ATermList importPair = (ATermList) importList.getFirst();
            importList = importList.getNext();
            ATermAppl moduleTerm = (ATermAppl) importPair.getFirst();
            String name = moduleTerm.getName();
            addModule(name);
        }
    }

    private Module addModule(String name) {
        Module module = manager.getModule(name);
        if (module == null) {
            module = new Module(name);
            manager.addModule(module);
        }

        return module;
    }

    private void setImports(ATermList importList) {

        while (!importList.isEmpty()) {
            ATermList importPair = (ATermList) importList.getFirst();
            importList = importList.getNext();

            ATermAppl fromTerm = (ATermAppl) importPair.getFirst();
            String from = fromTerm.getName();
            Module moduleFrom = manager.getModule(from);
            if (moduleFrom == null) {
                moduleFrom = addModule(from);
                moduleFrom.setState(Module.STATE_NEW);
            }

            ATermList imports = (ATermList) importPair.elementAt(1);

            while (!imports.isEmpty()) {
                ATermAppl toTerm = (ATermAppl) imports.getFirst();
                imports = imports.getNext();

                String to = toTerm.getName();
                Module moduleTo = manager.getModule(to);
                if (moduleTo == null) {
                    moduleTo = addModule(to);
                    moduleTo.setState(Module.STATE_NEW);
                }

                moduleFrom.addChild(to);
                moduleTo.addParent(from);
            }
        }
    }
}
