package tide;

import aterm.*;

import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import tide.tool.*;
import tide.tool.support.*;
import tide.tool.proclist.*;
import tide.tool.ruleinspector.*;
import tide.tool.srcviewer.*;
import tide.tool.prefeditor.*;
import tide.tool.stackviewer.*;

public class TideControl
  extends JFrame
  implements TideControlTif, ActionListener
{
  private static final String ITEM_EDIT_PREFERENCES = "Edit Preferences";
  private static final String ITEM_SAVE_PREFERENCES = "Save Preferences";
  private static final String ITEM_LOAD_PREFERENCES = "Load Preferences";
  private static final String ITEM_QUIT		    = "Quit";

  public static ATermFactory factory;

  private TideControlBridge bridge;
  private DebugTool    tool;

  private JDesktopPane desktop;
  private ProcessList  processList;

  private ToolManager manager;

  private JMenu fileMenu;

  //{{{ public final static void main(String[] args)

  public final static void main(String[] args)
    throws IOException
  {
    ATermFactory factory = new aterm.pure.PureFactory();

    Port.initialize(factory);
    Expr.initialize(factory);
    new TideControl(factory, args);
  }

  //}}}

  //{{{ public TideControl(ATermFactory factory)

  public TideControl(ATermFactory factory, String[] args)
    throws IOException
  {
    super("Tide - ToolBus Integrated Debug Environment");

    //{{{ Setup UI

    TideControl.factory = factory;

    setBackground(Color.white);

    bridge = new TideControlBridge(factory, this);
    tool = new DebugTool(factory);

    Container content = getContentPane();

    desktop = new JDesktopPane();
    desktop.setPreferredSize(new Dimension(1000, 700));

    String resource = "META-INF/tide-defaults.properties";
    InputStream stream =
      getClass().getClassLoader().getResourceAsStream(resource);

    Properties defaults = new Properties();
    defaults.load(stream);

    manager = new ToolManager(desktop, defaults);

    //{{{ Register debug tools

    manager.registerProcessTool(new RuleInspectorFactory(manager));
    manager.registerProcessTool(new SourceViewerFactory(manager));
    manager.registerProcessTool(new StackViewerFactory(manager));
    manager.registerTool(new PreferencesEditorFactory(manager));

    //}}}
    //{{{ Menus

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

    //}}}

    processList = new ProcessList(manager);
    tool.addDebugToolListener(processList);

    content.setLayout(new BorderLayout());
    content.add("Center", desktop);
    content.add("West",   new JScrollPane(processList));

    pack();
    setLocation(100, 100);
    setVisible(true);
    //show();

    //}}}
    //{{{ Connect ToolBus tools

    bridge.init(args);
    bridge.setLockObject(this);
    bridge.connect();

    //tool.setVerbose(true);
    tool.init(args);
    tool.setLockObject(this);
    tool.connect("debug-tool", null, -1);

    Thread thread = new Thread(tool);
    thread.start();

    thread = new Thread(bridge);
    thread.start();

    //}}}
  }

  //}}}

  //{{{ public void recTerminate(ATerm arg)

  public void recTerminate(ATerm arg)
  {
    System.exit(0);
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getActionCommand().equals(ITEM_EDIT_PREFERENCES)) {
      manager.launchTool("PreferencesEditor");
    } else if (event.getActionCommand().equals(ITEM_LOAD_PREFERENCES)) {
      loadPreferences();
    } else if (event.getActionCommand().equals(ITEM_SAVE_PREFERENCES)) {
      savePreferences();
    } else if (event.getActionCommand().equals(ITEM_QUIT)) {
      tool.postEvent(factory.make("quit-tide"));
    }
  }

  //}}}
  //{{{ public void loadPreferences()

  public void loadPreferences()
  {
    JFileChooser chooser = new JFileChooser();
    chooser.setSelectedFile(new File(PreferenceSet.PREFS_FILE));
    int option = chooser.showOpenDialog(this);
    if (option == JFileChooser.APPROVE_OPTION) {
      File file = chooser.getSelectedFile();
      if (file != null) {
	try {
	  InputStream stream = new FileInputStream(file);
	  manager.getPreferences().loadPreferences(stream);
	} catch (IOException e) {
	  JOptionPane.showInternalMessageDialog(desktop,
	    "Could not load preferences: " + e.getMessage(),
	    "Preferences Load Error",
	    JOptionPane.ERROR_MESSAGE);	    
	}
      }
    }
  }

  //}}}
  //{{{ public void savePreferences()

  public void savePreferences()
  {
    JFileChooser chooser = new JFileChooser();
    chooser.setSelectedFile(new File(PreferenceSet.PREFS_FILE));
    int option = chooser.showSaveDialog(this);
    if (option == JFileChooser.APPROVE_OPTION) {
      File file = chooser.getSelectedFile();
      if (file != null) {
	try {
	  OutputStream stream = new FileOutputStream(file);
	  manager.getPreferences().savePreferences(stream);
	} catch (IOException e) {
	  JOptionPane.showInternalMessageDialog(desktop,
	    "Could not save preferences: " + e.getMessage(),
	    "Preferences Save Error",
	    JOptionPane.ERROR_MESSAGE);	    
	}
      }
    }
  }

  //}}}

  //{{{ public static ATermFactory getFactory()

  public static ATermFactory getFactory()
  {
    return factory;
  }

  //}}}
}


