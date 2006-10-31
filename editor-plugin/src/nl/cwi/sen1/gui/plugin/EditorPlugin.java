package nl.cwi.sen1.gui.plugin;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.JComponent;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.event.MouseInputAdapter;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.ActionDescription;
import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.ItemLabels;
import nl.cwi.sen1.configapi.types.PropertyList;
import nl.cwi.sen1.configapi.types.shortcut.Shortcut;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentAdapter;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.editor.FileToBigException;
import nl.cwi.sen1.gui.plugin.editor.SwingEditor;
import nl.cwi.sen1.util.DefaultPopupImpl;
import nl.cwi.sen1.util.MenuAction;
import nl.cwi.sen1.util.MouseAdapter;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class EditorPlugin extends DefaultStudioPlugin implements
        EditorPluginTif {
    private static final String TOOL_NAME = "editor-plugin";

    private Factory configFactory;

    private Map<String, Editor> editors;

    private Map<String, StudioComponent> componentsById;

    private Map<String, Map<String, JComponent>> statusbarsById;

    private Studio studio;

    private EditorPluginBridge bridge;
    
    private DefaultPopupImpl popup;
    
    public EditorPlugin() {
        editors = new HashMap<String, Editor>();
        componentsById = new HashMap<String, StudioComponent>();
        statusbarsById = new HashMap<String, Map<String, JComponent>>();
        
    }

    public void isModified(ATerm editorId) {
        Editor panel = getEditorPanel(editorId);
        String modified;

        if (panel != null && panel.isModified()) {
            modified = "true";
        } else {
            modified = "false";
        }

        ATerm term = studio.getATermFactory().parse(modified);
        ATerm event = studio.getATermFactory().make(
                "is-modified(<term>,<term>)", editorId, term);
        bridge.postEvent(event);
    }

    public void writeContents(ATerm editorId) {
        Editor panel = getEditorPanel(editorId);

        if (panel != null) {
            try {
                panel.writeContents(panel.getFilename());
                panel.setModified(false);
                ATerm event = studio.getATermFactory().make(
                        "contents-written(<term>)", editorId);
                bridge.postEvent(event);
            } catch (IOException e) {
                try {
                    showErrorDialog(panel, JOptionPane.OK_OPTION,
                            "\n\nError saving changes.");
                } catch (CloseAbortedException e1) {
                }
            }
        }
    }

    public void setFocus(ATerm editorId, ATerm focus) {
        errorapi.Factory factory = errorapi.Factory
                .getInstance((PureFactory) studio.getATermFactory());

        Editor panel = getEditorPanel(editorId);

        if (panel != null) {
            panel.setFocus(factory.AreaFromTerm(focus));
        }
    }

	private Editor getEditorPanel(ATerm editorId) {
		return editors.get(editorId.toString());
	}

    public void clearFocus(ATerm editorId) {
    }

    public void registerTextCategories(ATerm editorId, ATerm categories) {
        Editor panel = getEditorPanel(editorId);

        if (panel != null) {
            PropertyList properties = Factory.getInstance(
                    (PureFactory) categories.getFactory())
                    .PropertyListFromTerm(categories);
            panel.registerCategories(properties);
        }
    }

    public void addActions(final ATerm editorId, ATerm menuList) {
        StudioComponent comp = componentsById.get(editorId.toString());
        final Editor panel = getEditorPanel(editorId);
        
        if (comp != null) {
            addEditorActions(editorId, comp, (ATermList) menuList, panel);
            createFileMenu(editorId, comp);
            createEditMenu(getEditorPanel(editorId), comp);
            panel.addMouseListener(new MouseInputAdapter() {
            	public void mousePressed(MouseEvent e) {
            		int offset = panel.getMouseOffset(e.getX(), e.getY());
            		bridge.postEvent(editorId.getFactory().make("offset-event(<term>,<int>)",
            				editorId, offset));
            	}
            });
        }
    }

    private void addEditorActions(final ATerm editorId, StudioComponent comp,
            ATermList actionList, final Editor panel) {
        while (!actionList.isEmpty()) {
        	ActionDescription desc = configFactory.ActionDescriptionFromTerm(actionList.getFirst());
        	Event action = desc.getEvent();
        	
        	if (action.isMenu() || action.isMenuShortcut()) {
        		   studio.addComponentMenu(comp, action, new MenuAction(editorId, bridge,action));
        	}
        	else if (action.isClick() || action.isPopup()) {
        		panel.addMouseListener(new MouseAdapter(editorId, bridge, action));
        	}
            actionList = actionList.getNext();
        }
    }

    private void createFileMenu(final ATerm editorId, final StudioComponent comp) {
        Factory factory = Factory.getInstance((PureFactory) studio
                .getATermFactory());

        ItemLabels items = factory.makeItemLabels(factory.makeItem_Label("File"),
                factory.makeItem_Label("Save"));

        Shortcut shortcut = factory.makeShortCut_Shortcut(
                factory.makeKeyModifierList(factory
                        .makeKeyModifier_MUnderscoreCTRL()), factory
                        .makeVirtualKey_VKUnderscoreS());
        Event event = factory.makeEvent_MenuShortcut(items, shortcut);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                Editor editor = getEditorPanel(editorId);
                try {
                    editor.writeContents(editor.getFilename());
                    ATerm event = studio.getATermFactory().make(
                            "contents-saved(<term>)", editorId);
                    bridge.postEvent(event);
                    if (comp.getName().endsWith("*")) {
                        comp.setName(comp.getName().substring(0,
                                comp.getName().length() - 1));
                    }
                } catch (IOException e1) {
                    try {
                        showErrorDialog(editor, JOptionPane.OK_OPTION,
                                "\n\nError saving changes.");
                    } catch (CloseAbortedException e2) {
                    }
                }
            }
        });

        items = factory.makeItemLabels(factory.makeItem_Label("File"), factory
                .makeItem_Label("Save a copy"));

        event = factory.makeEvent_Menu(items);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            Editor editor = getEditorPanel(editorId);

            public void actionPerformed(ActionEvent e) {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
                if (chooser.showDialog(StudioImpl.getFrame(), "Save Copy") == JFileChooser.APPROVE_OPTION) {
                    String path = chooser.getSelectedFile().getAbsolutePath();
                    try {
                        editor.writeContents(path);
                    } catch (IOException e1) {
                        try {
                            showErrorDialog(editor, JOptionPane.OK_OPTION,
                                    "\n\nError saving copy.");
                        } catch (CloseAbortedException e2) {
                        }
                    }
                }
            }
        });

        items = factory.makeItemLabels(factory.makeItem_Label("File"), factory
                .makeItem_Label("Save All"));

        shortcut = factory.makeShortCut_Shortcut(factory.makeKeyModifierList(
                factory.makeKeyModifier_MUnderscoreCTRL(), factory
                        .makeKeyModifier_MUnderscoreSHIFT()), factory
                .makeVirtualKey_VKUnderscoreA());

        event = factory.makeEvent_MenuShortcut(items, shortcut);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                for (String id : editors.keySet()) {
                    Editor editor = editors.get(id);
                    ATerm term = studio.getATermFactory().parse(id);
                    StudioComponent comp = componentsById.get(id);

                    try {
                        editor.writeContents(editor.getFilename());
                        ATerm event = studio.getATermFactory().make(
                                "contents-saved(<term>)", term);
                        bridge.postEvent(event);
                        if (comp.getName().endsWith("*")) {
                            comp.setName(comp.getName().substring(0,
                                    comp.getName().length() - 1));
                        }
                    } catch (IOException e1) {
                        try {
                            showErrorDialog(editor, JOptionPane.OK_OPTION,
                                    "\n\nError saving changes.");
                        } catch (CloseAbortedException e2) {
                        }
                    }
                }
            }
        });

        items = factory.makeItemLabels(factory.makeItem_Label("File"), factory
                .makeItem_Label("Refresh"));

        event = factory.makeEvent_Menu(items);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            Editor editor = getEditorPanel(editorId);

            public void actionPerformed(ActionEvent e) {
                editor.rereadContents();
                editor.setModified(false);
                ATerm event = studio.getATermFactory().make(
                        "contents-saved(<term>)", editorId);
                bridge.postEvent(event);
                if (comp.getName().endsWith("*")) {
                    comp.setName(comp.getName().substring(0,
                            comp.getName().length() - 1));
                }
            }
        });

        items = factory.makeItemLabels(factory.makeItem_Label("File"), factory
                .makeItem_Label("Close"));

        shortcut = factory.makeShortCut_Shortcut(
                factory.makeKeyModifierList(factory
                        .makeKeyModifier_MUnderscoreCTRL()), factory
                        .makeVirtualKey_VKUnderscoreW());
        event = factory.makeEvent_MenuShortcut(items, shortcut);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                closeEditor(comp, editorId.toString());
            }
        });

        items = factory.makeItemLabels(factory.makeItem_Label("File"), factory
                .makeItem_Label("Close All"));

        shortcut = factory.makeShortCut_Shortcut(factory.makeKeyModifierList(
                factory.makeKeyModifier_MUnderscoreCTRL(), factory
                        .makeKeyModifier_MUnderscoreSHIFT()), factory
                .makeVirtualKey_VKUnderscoreW());
        event = factory.makeEvent_MenuShortcut(items, shortcut);

        studio.addComponentMenu(comp, event, new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                Map<String, StudioComponent> editors = new HashMap<String, StudioComponent>(
                        componentsById);
                for (String id : editors.keySet()) {
                    StudioComponent component = componentsById.get(id);
                    closeEditor(component, id);
                }
            }
        });
    }

    private void createEditMenu(Editor editor, StudioComponent comp) {
        studio.addComponentMenu(comp, editor.getEditMenu());
    }

    public void displayMessage(ATerm editorId, String message) {
        Map<String, JComponent> statusBarComponents = statusbarsById
                .get(editorId.toString());

        JLabel status = (JLabel) statusBarComponents.get("Status");
        status.setText(message);
        // comp.setStatusMessage(message);
    }

    public void setEditable(ATerm editorId, ATerm editable) {
        ATermFactory factory = studio.getATermFactory();
        boolean edit = true;

        if (editable.equals(factory.make("false"))) {
            edit = false;
        }

        Editor panel = getEditorPanel(editorId);
        if (panel != null) {
            panel.setEditable(edit);
        }
    }

    public void killEditor(ATerm editorId) {
        StudioComponent comp = componentsById.get(editorId.toString());

        if (comp != null) {
            closeEditor(comp, editorId.toString());
        }
    }

    private void closeEditor(StudioComponent comp, String id) {
        Editor panel = editors.get(id);

        if (panel != null && panel.isModified()) {
            studio.requestFocus(comp);
            try {
                showSaveConfirmDialog(panel, JOptionPane.YES_NO_OPTION);
            } catch (CloseAbortedException e) {
                // this should never happen (no CANCEL button)
                e.printStackTrace();
            }
        }
        cleanupEditor(comp, id);
    }

    private void cleanupEditor(StudioComponent comp, String id) {
        studio.removeComponent(comp);
        componentsById.remove(id);
        statusbarsById.remove(id);
        editors.remove(id);
    }

    public void setCursorAtOffset(ATerm editorId, int offset) {
        Editor panel = getEditorPanel(editorId);

        if (panel != null) {
            panel.setCursorAtOffset(offset);
        }
    }

    public void editFile(ATerm editorId, String filename, String modulename) {
        try {
            createPanel(editorId, filename);
            Map<String, JComponent> statusBar = statusbarsById.get(editorId
                    .toString());
            JLabel label = (JLabel) statusBar.get("Module");
            if (modulename.equals("")) {
                label.setText(" ");
            } else {
                label.setText(modulename);
            }
        } catch (IOException e) {
            JOptionPane.showMessageDialog(StudioImpl.getFrame(), filename
                    + " could not be opened:" + e);
            editorDisconnected(editorId);
        } catch (FileToBigException e) {
            JOptionPane.showMessageDialog(StudioImpl.getFrame(), filename
                    + " is too big to handle (>1Mbyte)");
            editorDisconnected(editorId);
        }
    }

    public void highlightSlices(ATerm editorId, ATerm slices) {
        Editor panel = getEditorPanel(editorId);
        if (panel != null && !panel.isModified()) {
            panel.registerSlices(slices);
        }
    }

    public void editorToFront(ATerm editorId) {
        StudioComponent comp = componentsById.get(editorId.toString());

        if (comp != null) {
            studio.requestFocus(comp);
        }
    }

    public void rereadContents(ATerm editorId) {
        Editor panel = getEditorPanel(editorId);
        if (panel != null) {
            panel.rereadContents();
        }
    }

    public String getName() {
        return TOOL_NAME;
    }

    public void initStudioPlugin(Studio studio) {
        this.studio = studio;
        configFactory = Factory.getInstance((PureFactory) studio
                .getATermFactory());
        bridge = new EditorPluginBridge(studio.getATermFactory(), this);
        bridge.setLockObject(this);
        popup = new DefaultPopupImpl(bridge);
        studio.connect(getName(), bridge);
    }

    private Editor createPanel(final ATerm editorId, String filename)
            throws IOException, FileToBigException {
        final String id = editorId.toString();
        Editor editorPanel = editors.get(id);

        if (editorPanel == null) {
            final SwingEditor panel = new SwingEditor(id, filename);
            editorPanel = panel;

            addEditorModifiedListener(editorId, panel);

            final JLabel status = new JLabel(" ");
            status.setPreferredSize(new Dimension(250, 18));

            final JLabel module = new JLabel(" ");
            module.setPreferredSize(new Dimension(250, 18));

            Map<String, JComponent> statusBarComponents = new HashMap<String, JComponent>();
            statusBarComponents.put("Status", status);
            statusBarComponents.put("Module", module);

            int beginIndex = filename.lastIndexOf("/") + 1;
            String componentName = filename.substring(beginIndex, filename
                    .length());
            StudioComponent comp = new StudioComponentImpl(componentName, panel) {
                public JComponent[] getStatusBarComponents() {
                    return new JComponent[] { status, module };
                }
            };
            addStudioComponentListener(editorId, panel, comp);

            editors.put(id, panel);
            componentsById.put(id, comp);
            statusbarsById.put(id, statusBarComponents);
            ((StudioWithPredefinedLayout) studio).addComponent(comp,
                    StudioImplWithPredefinedLayout.TOP_RIGHT);
            // studio.addComponentStatusBar(comp, statusBarComponents);

        }

        return editorPanel;
    }
    
    private void addEditorModifiedListener(final ATerm editorId,
            final Editor panel) {
        panel.addEditorModifiedListener(new EditorModifiedListener() {
            public void editorModified(EditorModifiedEvent e) {
                StudioComponent comp = componentsById.get(editorId.toString());
                if (!comp.getName().endsWith("*")) {
                    comp.setName(comp.getName() + "*");
                }
                ATerm event = studio.getATermFactory().make(
                        "contents-changed(<term>)", editorId);
                bridge.postEvent(event);
            }
        });
    }

    private void editorDisconnected(final ATerm editorId) {
        StudioComponent comp = componentsById.get(editorId.toString());
        cleanupEditor(comp, editorId.toString());
        ATerm event = studio.getATermFactory().make(
                "editor-disconnected(<term>)", editorId);
        bridge.postEvent(event);
    }

    private void addStudioComponentListener(final ATerm editorId,
            final SwingEditor panel, StudioComponent comp) {
        comp.addStudioComponentListener(new StudioComponentAdapter() {
            public void componentRequestClose() throws CloseAbortedException {
                if (panel.isModified()) {
                    showSaveConfirmDialog(panel,
                            JOptionPane.YES_NO_CANCEL_OPTION);
                }
            }

            public void componentClose() {
                editorDisconnected(editorId);
            }

            public void componentFocusReceived() {
                panel.requestFocus();
            }
        });
    }

    private void showSaveConfirmDialog(final Editor panel, int optionType)
            throws CloseAbortedException {
        switch (JOptionPane
                .showConfirmDialog(
                        StudioImpl.getFrame(),
                        panel.getFilename()
                                + "\n\nThe editor for this file has unsaved changes.\nDo you want to save your changes?",
                        panel.getFilename(), optionType)) {
        case JOptionPane.YES_OPTION:
            try {
                panel.writeContents(panel.getFilename());
            } catch (IOException e) {
                showErrorDialog(
                        panel,
                        JOptionPane.OK_CANCEL_OPTION,
                        "\n\nError saving changes.\nClosing this editor will result in loosing your changes.");
            }
            break;
        case JOptionPane.CANCEL_OPTION:
            throw new CloseAbortedException();
        }
    }

    public void recAckEvent(ATerm t0) {
    }

    public void recTerminate(ATerm t0) {
        Iterator<Editor> iter = editors.values().iterator();
        while (iter.hasNext()) {
            Editor panel = iter.next();
            if (panel.isModified()) {
                String id = panel.getId();
                StudioComponent comp = componentsById.get(id);
                studio.requestFocus(comp);
                try {
                    showSaveConfirmDialog(panel, JOptionPane.YES_NO_OPTION);
                } catch (CloseAbortedException e) {
                    // this should never happen (no CANCEL button)
                    e.printStackTrace();
                }
            }
        }
        fireStudioPluginClosed();
    }

    public void showErrorDialog(final Editor panel, int optionType, String error)
            throws CloseAbortedException {
        int option;
        if (optionType == JOptionPane.OK_OPTION) {
            JOptionPane.showMessageDialog(StudioImpl.getFrame(), panel
                    .getFilename()
                    + error, panel.getFilename(), JOptionPane.ERROR_MESSAGE);
        } else {
            option = JOptionPane.showConfirmDialog(StudioImpl.getFrame(), panel
                    .getFilename()
                    + error, panel.getFilename(), optionType,
                    JOptionPane.ERROR_MESSAGE);
            switch (option) {
            case JOptionPane.OK_OPTION:
                break;
            case JOptionPane.CANCEL_OPTION:
                throw new CloseAbortedException();
            }
        }
    }

	public void showPopup(final ATerm editorId, ATerm menuList) {
		ActionDescriptionList l = configFactory.ActionDescriptionListFromTerm(menuList);
		popup.showPopup(editorId, l);
	}
}
