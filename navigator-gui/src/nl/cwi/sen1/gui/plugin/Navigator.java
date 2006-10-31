package nl.cwi.sen1.gui.plugin;

import java.awt.Dimension;
import java.awt.event.MouseEvent;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JComponent;
import javax.swing.JLabel;

import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.graph.Factory;
import nl.cwi.sen1.graph.types.Attribute;
import nl.cwi.sen1.graph.types.AttributeList;
import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.graph.types.Node;
import nl.cwi.sen1.graph.types.NodeList;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.data.Module;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionListener;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeModel;
import nl.cwi.sen1.ioapi.types.File;
import nl.cwi.sen1.util.DefaultPopupImpl;
import nl.cwi.sen1.util.MouseAdapter;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class Navigator extends DefaultStudioPlugin implements NavigatorTif {
    private static final String TOOL_NAME = "navigator";

    private NavigatorBridge bridge;

    private ModuleTreeModel moduleModel;

    private Studio studio;

    private Map<String, JComponent> statusBarComponents;

    private JLabel status;

    private Factory graphFactory;

    private nl.cwi.sen1.ioapi.Factory ioFactory;

    private boolean suspendSelectionNotification;

    private StudioComponent navigatorComponent;

	private nl.cwi.sen1.configapi.Factory configFactory;
	
    public Navigator() {
        statusBarComponents = new HashMap<String, JComponent>();
        status = new JLabel(" ");
        status.setPreferredSize(new Dimension(100, 18));

        statusBarComponents.put("Status", status);
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
        ATermFactory factory = studio.getATermFactory();
        ATerm moduleId = module.getId();
        bridge.postEvent(factory.make("request-popup-event(<term>)", moduleId));
    }

    public void showPopup(final ATerm id, final ATerm menu) {
    	nl.cwi.sen1.configapi.Factory f = nl.cwi.sen1.configapi.Factory.getInstance((PureFactory) id.getFactory());
		ActionDescriptionList list = f.ActionDescriptionListFromTerm(menu);
		DefaultPopupImpl popup = new DefaultPopupImpl(bridge);
		popup.showPopup(id, list);
    }

    public void recAckEvent(ATerm t0) {

    }

    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }

    public String getName() {
        return TOOL_NAME;
    }
    
    private ATerm createEventId(ATerm moduleId) {
    	return studio.getATermFactory().make(TOOL_NAME + "(<term>)", moduleId);
    }

    public void initStudioPlugin(Studio studio) {
        this.studio = studio;
        graphFactory = Factory.getInstance((PureFactory) studio
                .getATermFactory());
        configFactory = nl.cwi.sen1.configapi.Factory.getInstance((PureFactory) studio.getATermFactory());
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
        final ATerm id = configFactory.getPureFactory().parse(TOOL_NAME);
        final Event popupAction = configFactory.makeEvent_Popup();
        
        tree.addMouseListener(new MouseAdapter(id, bridge, popupAction) {
			public void mousePressed(MouseEvent e) {
				ATerm moduleId = tree.selectModule(e.getX(), e.getY());
				if (moduleId != null) {
				  setId(createEventId(moduleId));
				  super.mousePressed(e);
				}
			}
		});
        
        navigatorComponent = new StudioComponentImpl("Navigator", tree) {
            public void requestClose() throws CloseAbortedException {
                throw new CloseAbortedException();
            }
            
            public JComponent[] getStatusBarComponents() {
                return new JComponent[] {status};
            }
        };
        ((StudioWithPredefinedLayout) studio).addComponent(navigatorComponent,
                StudioImplWithPredefinedLayout.TOP_LEFT);
        // studio.addComponentMenu(navigatorComponent, new JMenu("Navigate"));
    }

    public void selectModule(ATerm moduleId) {
        suspendSelectionNotification = true;
        moduleModel.selectModule(moduleId);
        suspendSelectionNotification = false;
    }

}
