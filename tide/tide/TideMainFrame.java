package tide;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

import tide.tool.ToolManager;
import aterm.ATermFactory;

public class TideMainFrame extends JFrame 
implements ActionListener {
	private JMenu fileMenu;
	
	private static final String ITEM_EDIT_PREFERENCES = "Edit Preferences";
	private static final String ITEM_SAVE_PREFERENCES = "Save Preferences";
	private static final String ITEM_LOAD_PREFERENCES = "Load Preferences";
	private static final String ITEM_QUIT = "Quit";
	
	private ToolManager manager;
	private TideControl control;
	
	private ATermFactory factory;
	
	public final static void main(String[] args) throws IOException {
		ATermFactory factory = new aterm.pure.PureFactory();
		new TideMainFrame(factory, args);
	}

	public TideMainFrame(ATermFactory factory, String[] args) throws IOException {
		super("Tide - ToolBus Integrated Debug Environment");
		
		this.factory = factory;
		Container content = getContentPane();
		
		createMenuBar();
		
	    TideControl control = new TideControl(factory, args);
		content.add(control);
		manager = control.getManager();
		
		pack();
		setLocation(100, 100);
		setVisible(true);
	}
	
	private void createMenuBar() {
		fileMenu = new JMenu("File");
		fileMenu.setMnemonic('F');
		JMenuItem item;

		item = new JMenuItem(ITEM_EDIT_PREFERENCES, 'P');
		item.addActionListener(this);
		fileMenu.add(item);

		item = new JMenuItem(ITEM_SAVE_PREFERENCES, 'S');
		item.addActionListener(this);
		fileMenu.add(item);

		item = new JMenuItem(ITEM_LOAD_PREFERENCES, 'L');
		item.addActionListener(this);
		fileMenu.add(item);

		fileMenu.addSeparator();

		item = new JMenuItem(ITEM_QUIT, 'Q');
		item.addActionListener(this);
		fileMenu.add(item);

		JMenuBar bar = new JMenuBar();
		bar.add(fileMenu);
		setJMenuBar(bar);
	}
	
	public void actionPerformed(ActionEvent event) {
		if (event.getActionCommand().equals(ITEM_EDIT_PREFERENCES)) {
			manager.launchTool("PreferencesEditor");
		} else if (event.getActionCommand().equals(ITEM_LOAD_PREFERENCES)) {
			control.loadPreferences();
		} else if (event.getActionCommand().equals(ITEM_SAVE_PREFERENCES)) {
			control.savePreferences();
		} else if (event.getActionCommand().equals(ITEM_QUIT)) {
			control.postEvent(factory.make("quit-tide"));
		}
	}
	
}
