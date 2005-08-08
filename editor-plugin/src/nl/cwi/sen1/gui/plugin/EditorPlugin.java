package nl.cwi.sen1.gui.plugin;

import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.JOptionPane;

import metaconfig.Factory;
import metaconfig.types.Items;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentAdapter;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class EditorPlugin implements EditorPluginTif, StudioPlugin {
	private static final String TOOL_NAME = "editor-plugin";

	private Map editors;

	private Map componentsById;

	private Studio studio;

	private EditorPluginBridge bridge;

	public EditorPlugin() {
		this.editors = new HashMap();
		this.componentsById = new HashMap();
	}

	public void isModified(ATerm editorId) {
		EditorPanel panel = getPanel(editorId.toString());
		String modified;

		if (panel.isModified()) {
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
		EditorPanel panel = getPanel(editorId.toString());

		if (panel != null) {
			try {
				panel.writeContents();
				panel.setModified(false);
				ATerm event = studio.getATermFactory().make(
						"contents-written(<term>)", editorId);
				bridge.postEvent(event);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public void setFocus(ATerm editorId, ATerm focus) {
		errorapi.Factory factory = errorapi.Factory
				.getInstance((PureFactory) studio.getATermFactory());

		EditorPanel panel = (EditorPanel) editors.get(editorId.toString());

		panel.setFocus(factory.AreaFromTerm(focus));
	}

	public void clearFocus(ATerm editorId) {
	}

	public void registerTextCategories(ATerm t0, ATerm t1) {
	}

	public void addActions(final ATerm editorId, ATerm menuList) {
		StudioComponent comp = (StudioComponent) componentsById.get(editorId
				.toString());

		addEditorMenus(editorId, comp, (ATermList) menuList);

		createFileMenu(editorId, comp);
	}

	private void addEditorMenus(final ATerm editorId, StudioComponent comp,
			ATermList menuList) {
		while (!menuList.isEmpty()) {
			final ATerm menuPath = menuList.getFirst();

			studio.addComponentMenu(comp, menuPath, new AbstractAction(menuPath
					.toString()) {
				public void actionPerformed(ActionEvent e) {
					ATerm event = studio.getATermFactory().make(
							"menu-event(<term>,<term>)", editorId, menuPath);
					bridge.postEvent(event);
				}
			});
			menuList = menuList.getNext();
		}

	}

	private void createFileMenu(final ATerm editorId, StudioComponent comp) {
		Factory factory = Factory.getInstance((PureFactory) studio
				.getATermFactory());

		Items items = factory.makeItems("File", "Save");

		ATerm menuPath = factory.makeEvent_Default(items);

		studio.addComponentMenu(comp, menuPath, new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				try {
					((EditorPanel) editors.get(editorId.toString()))
							.writeContents();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
	}

	public void displayMessage(ATerm editorId, String message) {
		StudioComponentImpl comp = (StudioComponentImpl) componentsById
				.get(editorId.toString());
		comp.setStatusMessage(message);
	}

	public void killEditor(ATerm editorId) {
		StudioComponent comp = (StudioComponent) componentsById.get(editorId
				.toString());
		if (comp != null) {
			componentsById.remove(editorId.toString());
			editors.remove(editorId.toString());
			studio.removeComponent(comp);
		}
	}

	public void setCursorAtOffset(ATerm editorId, int offset) {
		EditorPanel panel = getPanel(editorId.toString());
		panel.setCursorAtOffset(offset);
	}

	public void editFile(ATerm editorId, String filename) {
		try {
			createPanel(editorId, filename);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void highlightSlices(ATerm editorId, ATerm t1) {
	}

	public void editorToFront(ATerm editorId) {
		studio.requestFocus((StudioComponent) componentsById.get(editorId
				.toString()));
	}

	public void rereadContents(ATerm editorId) {
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new EditorPluginBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	private EditorPanel createPanel(final ATerm editorId, String filename)
			throws IOException {
		final String id = editorId.toString();
		EditorPanel editorPanel = getPanel(id);

		if (editorPanel == null) {
			final EditorPanel panel = new EditorPanel(id, filename);
			editorPanel = panel;

			final EditorTextArea textArea = panel.getTextArea();

			// Add mousemotion listener showing sorts in tooltips
			textArea.addMouseListener(new MouseAdapter() {
				public void mousePressed(MouseEvent e) {
					int l = textArea.yToLine(e.getY());
					int offset = textArea.xToOffset(l, e.getX());

					if (e.getClickCount() == 1) {
						ATerm line = studio.getATermFactory().makeInt(l + 1);
						ATerm column = studio.getATermFactory().makeInt(offset);
						ATerm event = studio.getATermFactory().make(
								"mouse-event(<term>,<term>,<term>)", editorId,
								line, column);
						bridge.postEvent(event);
					}
				}
			});

			int beginIndex = filename.lastIndexOf("/") + 1;
			String componentName = filename.substring(beginIndex, filename
					.length());

			StudioComponentImpl comp = new StudioComponentImpl(componentName,
					panel);
			comp.addStudioComponentListener(new StudioComponentAdapter() {
				public void componentRequestClose()
						throws CloseAbortedException {
					if (panel.isModified()) {
						showSaveConfirmDialog(panel, JOptionPane.YES_NO_CANCEL_OPTION);
					}
				}

				public void componentClose() {
					editors.remove(id);
					componentsById.remove(id);
					ATerm event = studio.getATermFactory().make(
							"editor-disconnected(<term>)", editorId);
					bridge.postEvent(event);
				}
			});

			editors.put(id, panel);
			componentsById.put(id, comp);
			((StudioWithPredefinedLayout) studio).addComponent(comp,
					StudioImplWithPredefinedLayout.TOP_RIGHT);
		}

		return editorPanel;
	}

	private void showSaveConfirmDialog(final EditorPanel panel, int optionType)
			throws CloseAbortedException {
		switch (JOptionPane.showConfirmDialog(null,
				"Editor is modified. Do you want to save your changes?", panel.getName(),
				optionType)) {
		case JOptionPane.YES_OPTION:
			try {
				panel.writeContents();
			} catch (IOException e) {
				e.printStackTrace();
			}
			break;
		case JOptionPane.CANCEL_OPTION:
			throw new CloseAbortedException();
		}
	}

	private EditorPanel getPanel(String id) {
		return (EditorPanel) editors.get(id);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
		Iterator iter = editors.values().iterator();
		while (iter.hasNext()) {
			EditorPanel panel = (EditorPanel) iter.next();
			if (panel.isModified()) {
				try {
					showSaveConfirmDialog(panel, JOptionPane.YES_NO_OPTION);
				} catch (CloseAbortedException e) {
					// this should never happen (no CANCEL button)
					e.printStackTrace();
				}
			}
		}
	}
}
