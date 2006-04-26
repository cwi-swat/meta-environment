package nl.cwi.sen1.tide;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;

public class TideMainFrame extends DefaultStudioPlugin {
	
//	private ToolManager manager;
	private TideControl control;
	
//	private ATermFactory factory;

	public void initStudioPlugin(Studio studio) {
//		this.factory = studio.getATermFactory();
		
		// TODO: move control code from TideControl to this class
		TideControl control = new TideControl(studio, this);
	
//		manager = control.getManager();
		
//		Thread controlThread = new Thread(control);
//		controlThread.run();
	}

	public String getName() {
		return "TIDE";
	}

	public void closeTide() {
		fireStudioPluginClosed();
	}

//	private void createMenuBar() {
//		fileMenu = new JMenu("File");
//		fileMenu.setMnemonic('F');
//		JMenuItem item;
//
//		item = new JMenuItem(ITEM_EDIT_PREFERENCES, 'P');
//		item.addActionListener(this);
//		fileMenu.add(item);
//
//		item = new JMenuItem(ITEM_SAVE_PREFERENCES, 'S');
//		item.addActionListener(this);
//		fileMenu.add(item);
//
//		item = new JMenuItem(ITEM_LOAD_PREFERENCES, 'L');
//		item.addActionListener(this);
//		fileMenu.add(item);
//
//		fileMenu.addSeparator();
//
//		item = new JMenuItem(ITEM_QUIT, 'Q');
//		item.addActionListener(this);
//		fileMenu.add(item);
//
//		JMenuBar bar = new JMenuBar();
//		bar.add(fileMenu);
//		setJMenuBar(bar);
//	}
	
//	public void actionPerformed(ActionEvent event) {
//		if (event.getActionCommand().equals(ITEM_EDIT_PREFERENCES)) {
//			manager.launchTool("PreferencesEditor");
//		} else if (event.getActionCommand().equals(ITEM_LOAD_PREFERENCES)) {
//			control.loadPreferences();
//		} else if (event.getActionCommand().equals(ITEM_SAVE_PREFERENCES)) {
//			control.savePreferences();
//		} else if (event.getActionCommand().equals(ITEM_QUIT)) {
//			control.postEvent(factory.make("quit-tide"));
//		}
//	}
	
}
