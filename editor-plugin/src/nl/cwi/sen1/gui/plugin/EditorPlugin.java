package nl.cwi.sen1.gui.plugin;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.ItemList;
import nl.cwi.sen1.configapi.types.PropertyList;
import nl.cwi.sen1.configapi.types.shortcut.Shortcut;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentAdapter;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.plugin.editor.FileToBigException;
import nl.cwi.sen1.gui.plugin.editor.SwingEditor;
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

	public EditorPlugin() {
		editors = new HashMap<String, Editor>();
		componentsById = new HashMap<String, StudioComponent>();
		statusbarsById = new HashMap<String, Map<String, JComponent>>();
	}

	public void isModified(ATerm editorId) {
		Editor panel = editors.get(editorId.toString());
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
		Editor panel = editors.get(editorId.toString());

		if (panel != null) {
			try {
				panel.writeContents();
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

		Editor panel = editors.get(editorId.toString());

		if (panel != null) {
			panel.setFocus(factory.AreaFromTerm(focus));
		}
	}

	public void clearFocus(ATerm editorId) {
	}

	public void registerTextCategories(ATerm editorId, ATerm categories) {
		Editor panel = editors.get(editorId.toString());

		if (panel != null) {
			PropertyList properties = Factory.getInstance(
					(PureFactory) categories.getFactory())
					.PropertyListFromTerm(categories);
			panel.registerCategories(properties);
		}
	}

	public void addActions(final ATerm editorId, ATerm menuList) {
		StudioComponent comp = componentsById.get(editorId.toString());

		if (comp != null) {
			addEditorMenus(editorId, comp, (ATermList) menuList);

			createFileMenu(editorId, comp);
			createEditMenu(editors.get(editorId.toString()), comp);
		}
	}

	private void addEditorMenus(final ATerm editorId, StudioComponent comp,
			ATermList menuList) {
		while (!menuList.isEmpty()) {
			final Event menuPath = configFactory.EventFromTerm(menuList
					.getFirst());

			studio.addComponentMenu(comp, menuPath, new AbstractAction(menuPath
					.toString()) {
				public void actionPerformed(ActionEvent e) {
					ATerm event = studio.getATermFactory().make(
							"menu-event(<term>,<term>)", editorId,
							menuPath.toTerm());
					bridge.postEvent(event);
				}
			});
			menuList = menuList.getNext();
		}

	}

	private void createFileMenu(final ATerm editorId, final StudioComponent comp) {
		Factory factory = Factory.getInstance((PureFactory) studio
				.getATermFactory());

		ItemList items = factory.makeItemList(factory.makeItem_Label("File"),
				factory.makeItem_Label("Save"));

		Shortcut shortcut = factory.makeShortCut_Shortcut(
				factory.makeKeyModifierList(factory
						.makeKeyModifier_MUnderscoreCTRL()), factory
						.makeVirtualKey_VKUnderscoreS());
		Event event = factory.makeEvent_MenuShortcut(items, shortcut);

		studio.addComponentMenu(comp, event, new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				Editor editor = editors.get(editorId.toString());
				try {
					editor.writeContents();
					ATerm event = studio.getATermFactory().make(
							"contents-saved(<term>)", editorId);
					bridge.postEvent(event);
				} catch (IOException e1) {
					try {
						showErrorDialog(editor, JOptionPane.OK_OPTION,
								"\n\nError saving changes.");
					} catch (CloseAbortedException e2) {
					}
				}
			}
		});

		items = factory.makeItemList(factory.makeItem_Label("File"), factory
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

		items = factory.makeItemList(factory.makeItem_Label("File"), factory
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

		Editor panel = editors.get(editorId.toString());
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
		Editor panel = editors.get(editorId.toString());

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
			JOptionPane.showMessageDialog(null, filename
					+ " could not be opened:" + e);
			editorDisconnected(editorId);
		} catch (FileToBigException e) {
			JOptionPane.showMessageDialog(null, filename
					+ " is too big to handle (>1Mbyte)");
			editorDisconnected(editorId);
		}
	}

	public void highlightSlices(ATerm editorId, ATerm slices) {
		Editor panel = editors.get(editorId.toString());
		if (panel != null) {
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
		Editor panel = editors.get(editorId.toString());
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
		studio.connect(getName(), bridge);
	}

	private Editor createPanel(final ATerm editorId, String filename)
			throws IOException, FileToBigException {
		final String id = editorId.toString();
		Editor editorPanel = editors.get(id);

		if (editorPanel == null) {
			final SwingEditor panel = new SwingEditor(id, filename);
			editorPanel = panel;

			addMouseListener(editorId, panel);
			addEditorModifiedListener(editorId, panel);

			final JLabel status = new JLabel(" ");
			status.setPreferredSize(new Dimension(100, 18));

			final JLabel module = new JLabel(" ");
			module.setPreferredSize(new Dimension(100, 18));

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

	private void addMouseListener(final ATerm editorId, final Editor panel) {
		// Add mousemotion listener showing sorts in tooltips
		panel.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				int offset = panel.getMouseOffset(e.getX(), e.getY());

				if (e.getClickCount() == 1) {
					ATerm aoffset = studio.getATermFactory().makeInt(offset);
					ATerm event = studio.getATermFactory().make(
							"mouse-event(<term>,<term>)", editorId, aoffset);
					bridge.postEvent(event);
				}
			}
		});
	}

	private void addEditorModifiedListener(final ATerm editorId,
			final Editor panel) {
		panel.addEditorModifiedListener(new EditorModifiedListener() {
			public void editorModified(EditorModifiedEvent e) {
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
						null,
						panel.getFilename()
								+ "\n\nThe editor for this file has unsaved changes.\nDo you want to save your changes?",
						panel.getFilename(), optionType)) {
		case JOptionPane.YES_OPTION:
			try {
				panel.writeContents();
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
			JOptionPane.showMessageDialog(null, panel.getFilename() + error,
					panel.getFilename(), JOptionPane.ERROR_MESSAGE);
		} else {
			option = JOptionPane.showConfirmDialog(null, panel.getFilename()
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
}