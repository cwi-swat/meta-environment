package tide.tool;

import aterm.*;

import java.io.*;
import java.awt.*;
import javax.swing.*;

import tide.tool.support.*;
import tide.tool.proclist.*;
import tide.tool.ruleinspector.*;
import tide.tool.srcviewer.*;

public class TideControl
  extends JFrame
  implements TideControlTif
{
  public static ATermFactory factory;

  private TideControlBridge bridge;
  private DebugTool    tool;

  private JDesktopPane desktop;
  private ProcessList  processList;

  private ToolManager manager;

  //{{{ public final static void main(String[] args)

  public final static void main(String[] args)
    throws IOException
  {
    ATermFactory factory = new aterm.pure.PureFactory();

    Port.initialize(factory);
    Expr.initialize(factory);
    TideControl control = new TideControl(factory, args);
  }

  //}}}

  //{{{ public TideControl(ATermFactory factory)

  public TideControl(ATermFactory factory, String[] args)
    throws IOException
  {
    //{{{ Setup UI

    super("Tide - ToolBus Integrated Debug Environment");
    TideControl.factory = factory;

    setBackground(Color.white);

    bridge = new TideControlBridge(factory, this);
    tool = new DebugTool(factory);

    Container content = getContentPane();

    desktop = new JDesktopPane();
    desktop.setPreferredSize(new Dimension(1000, 700));

    manager = new ToolManager(desktop);

    //{{{ Register debug tools

    manager.registerProcessTool(new RuleInspectorFactory(manager));
    manager.registerProcessTool(new SourceViewerFactory(manager));

    //}}}

    processList = new ProcessList(manager);
    tool.addDebugToolListener(processList);

    content.setLayout(new BorderLayout());
    content.add("Center", desktop);
    content.add("West",   new JScrollPane(processList));

    pack();
    show();
    setLocation(100, 100);

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
    bridge.run();

    //}}}

    throw new RuntimeException("cannot reach this!");
  }

  //}}}

  //{{{ public void recTerminate(ATerm arg)

  public void recTerminate(ATerm arg)
  {
    System.out.println("tide-control terminating: " + arg);
    System.exit(0);
  }

  //}}}

  //{{{ public static ATermFactory getFactory()

  public static ATermFactory getFactory()
  {
    return factory;
  }

  //}}}
}


