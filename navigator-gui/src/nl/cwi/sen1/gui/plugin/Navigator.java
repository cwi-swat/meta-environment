package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseEvent;

import javax.swing.JLabel;

import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.graph.Factory;
import nl.cwi.sen1.graph.types.Attribute;
import nl.cwi.sen1.graph.types.AttributeList;
import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.graph.types.Node;
import nl.cwi.sen1.graph.types.NodeList;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.StatusBar;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.plugin.data.Module;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionListener;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeModel;
import nl.cwi.sen1.ioapi.types.File;
import nl.cwi.sen1.util.PopupHandler;
import nl.cwi.sen1.util.Preferences;
import nl.cwi.sen1.util.StudioPopupMenu;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class Navigator extends DefaultStudioPlugin implements NavigatorTif {
    private static final String TOOL_NAME = "navigator";

    private static final String RESOURCE_DIR = "/resources";

    private NavigatorBridge bridge;

    private ModuleTreeModel moduleModel;

    private Studio studio;

    private StatusBar statusBar;

    private JLabel status;

    private Factory graphFactory;

    private nl.cwi.sen1.ioapi.Factory ioFactory;

    // TODO: use preferences
    private Preferences preferences;

    private boolean suspendSelectionNotification;

    private MouseEvent popupEvent;

    private StudioComponentImpl navigatorComponent;

    public Navigator() {
        String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
                + ".properties");
        this.preferences = new Preferences(getClass().getResourceAsStream(
                propertyPath));

        statusBar = new StatusBar();
        status = new JLabel(" ");
        statusBar.addComponent(status, 100);
    }

    private void setModules(Graph graph) {
        moduleModel.clearModules();

        for (NodeList nodes = graph.getNodes(); !nodes.isEmpty(); nodes = nodes
                .getTail()) {
            Node node = nodes.getHead();

            addModule(node);
        }
    }

    private Module addModule(Node node) {
        ATerm moduleId = node.getId().getId();

        Module module = moduleModel.getModule(moduleId);
        if (module == null) {
            String label = moduleId.toString();
            File file = null;
            AttributeList attrs = node.getAttributes();

            while (!attrs.isEmpty()) {
                Attribute attr = attrs.getHead();
                if (attr.isFile()) {
                    ATerm term = attr.getFile().toTerm();
                    file = ioFactory.FileFromTerm(term);
                }
                if (attr.isLabel()) {
                    label = attr.getLabel();
                }

                attrs = attrs.getTail();
            }

            module = new Module(moduleId, file, label);
            moduleModel.addModule(module);
        }

        return module;
    }

    public void setModules(ATerm graphTerm) {
        Graph graph = graphFactory.GraphFromTerm(graphTerm);

        setModules(graph);
    }

    public void postPopupRequest(MouseEvent e, Module module) {
        popupEvent = e;
        ATermFactory factory = studio.getATermFactory();
        ATerm moduleId = module.getId();
        bridge.postEvent(factory.make("request-popup-event(<term>)", moduleId));
    }

    public void showPopup(final ATerm id, ATerm menu) {
        StudioPopupMenu popup = new StudioPopupMenu((ATermList) menu);
        popup.setPopupHandler(new PopupHandler() {
            public void popupSelected(Event action) {
                bridge.postEvent(studio.getATermFactory().make(
                        "popup-menu-event(<term>,<term>)", id, action.toTerm()));
            }

        });
        popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent
                .getY());
    }

    public void recAckEvent(ATerm t0) {

    }

    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }

    public String getName() {
        return TOOL_NAME;
    }

    public void initStudioPlugin(Studio studio) {
        this.studio = studio;
        graphFactory = Factory.getInstance((PureFactory) studio
                .getATermFactory());
        ioFactory = nl.cwi.sen1.ioapi.Factory.getInstance((PureFactory) studio
                .getATermFactory());
        bridge = new NavigatorBridge(studio.getATermFactory(), this);
        bridge.setLockObject(this);
        studio.connect(getName(), bridge);

        createModel();
        addNavigatorComponent();
    }

    private void createModel() {
        moduleModel = new ModuleTreeModel();
        moduleModel.addModuleSelectionListener(new ModuleSelectionListener() {
            public void moduleSelected(Module module) {
                if (!suspendSelectionNotification) {
                    if (module != null) {
                        status.setText(module.toString());
                        bridge.postEvent(studio.getATermFactory().make(
                                "module-selected(<term>)", module.getId()));
                    }
                }
            }
        });
    }

    private void addNavigatorComponent() {
        final ModuleTree tree = new ModuleTree(this, moduleModel);
        navigatorComponent = new StudioComponentImpl("Navigator", tree) {
            public void requestClose() throws CloseAbortedException {
                throw new CloseAbortedException();
            }
        };
        ((StudioWithPredefinedLayout) studio).addComponent(navigatorComponent,
                StudioImplWithPredefinedLayout.TOP_LEFT);
        studio.addComponentStatusBar(navigatorComponent, statusBar);
        // studio.addComponentMenu(navigatorComponent, new JMenu("Navigate"));
    }

    public void selectModule(ATerm moduleId) {
        suspendSelectionNotification = true;
        moduleModel.selectModule(moduleId);
        suspendSelectionNotification = false;
    }

}
