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
import metaconfig.types.Properties;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentAdapter;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.plugin.editor.SwingEditor;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class EditorPlugin extends DefaultStudioPlugin implements
		EditorPluginTif {
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
		Editor panel = getPanel(editorId.toString());
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
		Editor panel = getPanel(editorId.toString());

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

		Editor panel = (Editor) editors.get(editorId.toString());

		panel.setFocus(factory.AreaFromTerm(focus));
	}

	public void clearFocus(ATerm editorId) {
	}

	public void registerTextCategories(ATerm editorId, ATerm categories) {
		Editor panel = getPanel(editorId.toString());

		Properties properties = Factory.getInstance(
				(PureFactory) categories.getFactory()).PropertiesFromTerm(
				categories);
		panel.registerCategories(properties);
	}

	public void addActions(final ATerm editorId, ATerm menuList) {
		StudioComponent comp = (StudioComponent) componentsById.get(editorId
				.toString());

		addEditorMenus(editorId, comp, (ATermList) menuList);

		createFileMenu(editorId, comp);
		createEditMenu((Editor) editors.get(editorId.toString()), comp);
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
					((Editor) editors.get(editorId.toString()))
							.writeContents();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
			}
		});
	}
	
	private void createEditMenu(Editor editor, StudioComponent comp) {
		studio.addComponentMenu(comp, editor.getEditMenu());
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
		Editor panel = getPanel(editorId.toString());
		panel.setCursorAtOffset(offset);
	}

	public void editFile(ATerm editorId, String filename) {
		try {
			createPanel(editorId, filename);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void highlightSlices(ATerm editorId, ATerm slices) {
		getPanel(editorId.toString()).registerSlices(slices);
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

	private Editor createPanel(final ATerm editorId, String filename)
			throws IOException {
		final String id = editorId.toString();
		Editor editorPanel = getPanel(id);

		if (editorPanel == null) {
			final SwingEditor panel = new SwingEditor(id, filename);
			editorPanel = panel;

			// Add mousemotion listener showing sorts in tooltips
			panel.addMouseListener(new MouseAdapter() {
				public void mousePressed(MouseEvent e) {
					int offset = panel.getMouseOffset(e.getX(), e.getY());

					if (e.getClickCount() == 1) {
						ATerm aoffset = studio.getATermFactory()
								.makeInt(offset);
						ATerm event = studio.getATermFactory()
								.make("mouse-event(<term>,<term>)", editorId,
										aoffset);
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
						showSaveConfirmDialog(panel,
								JOptionPane.YES_NO_CANCEL_OPTION);
					}
				}

				public void componentClose() {
					editors.remove(id);
					componentsById.remove(id);
					ATerm event = studio.getATermFactory().make(
							"editor-disconnected(<term>)", editorId);
					bridge.postEvent(event);
				}
				
				public void componentFocusReceived() {
					panel.requestFocus();
				}
			});

			editors.put(id, panel);
			componentsById.put(id, comp);
			((StudioWithPredefinedLayout) studio).addComponent(comp,
					StudioImplWithPredefinedLayout.TOP_RIGHT);
		}

		return editorPanel;
	}

	private void showSaveConfirmDialog(final Editor panel, int optionType)
			throws CloseAbortedException {
		switch (JOptionPane
				.showConfirmDialog(
						null,
						panel.getFilename()
								+ "\n\nThe editor for this file has unsaved changes.\nDo you want to save your changes?",
						panel.getFilename(), optionType)) {
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

	private Editor getPanel(String id) {
		return (Editor) editors.get(id);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
		Iterator iter = editors.values().iterator();
		while (iter.hasNext()) {
			Editor panel = (Editor) iter.next();
			if (panel.isModified()) {
				String id = panel.getId();
				StudioComponent comp = getComponentById(id);
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

	private StudioComponent getComponentById(String id) {
		return (StudioComponent) componentsById.get(id);
	}
}
