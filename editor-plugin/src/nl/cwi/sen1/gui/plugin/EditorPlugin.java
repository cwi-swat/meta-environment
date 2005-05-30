package nl.cwi.sen1.gui.plugin;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponentAdapter;
import nl.cwi.sen1.gui.StudioPlugin;
import aterm.ATerm;

public class EditorPlugin implements EditorPluginTif, StudioPlugin {
    private static final String TOOL_NAME = "editor-plugin";

    private Map editors;

    private Studio studio;

    public EditorPlugin() {
        this.editors = new HashMap();
    }

    public void isModified(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void writeContents(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void setFocus(ATerm t0, ATerm t1) {
        // TODO Auto-generated method stub

    }

    public void registerTextCategories(ATerm t0, ATerm t1) {
        // TODO Auto-generated method stub

    }

    public void addActions(ATerm t0, ATerm t1) {
        // TODO Auto-generated method stub

    }

    public void clearFocus(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void displayMessage(ATerm editorId, String message) {
        // TODO Auto-generated method stub

    }

    public void killEditor(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void setCursorAtOffset(ATerm editorId, int offset) {
        // TODO Auto-generated method stub

    }

    public void editFile(ATerm editorId, String filename) {
        try {
            createPanel(editorId.toString(), filename);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void highlightSlices(ATerm editorId, ATerm t1) {
    }

    public void editorToFront(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void rereadContents(ATerm editorId) {
        // TODO Auto-generated method stub

    }

    public void recAckEvent(ATerm t0) {
    }

    public void recTerminate(ATerm t0) {
    }

    public String getName() {
        return TOOL_NAME;
    }

    public void initStudioPlugin(Studio studio) {
        this.studio = studio;
        EditorPluginBridge bridge = new EditorPluginBridge(studio
                .getATermFactory(), this);
        bridge.setLockObject(this);
        studio.connect(getName(), bridge);
    }

    private EditorPanel createPanel(String id, String filename)
            throws IOException {
        EditorPanel panel = getPanel(id);

        if (panel == null) {
            panel = new EditorPanel(id, filename);
            StudioComponentAdapter comp = new StudioComponentAdapter(id, panel);
            editors.put(id, panel);
            studio.addComponent(comp);
            // studio.addComponentMenu(panel, createEditorMenu());
        }
        return panel;
    }

    private EditorPanel getPanel(String id) {
        return (EditorPanel) editors.get(id);
    }
}
