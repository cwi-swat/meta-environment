package nl.cwi.sen1.tide.tool.proclist;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.border.EmptyBorder;

import nl.cwi.sen1.tide.tool.AdapterAction;
import nl.cwi.sen1.tide.tool.ProcessAction;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.support.DebugAdapter;
import nl.cwi.sen1.tide.tool.support.DebugAdapterListener;
import nl.cwi.sen1.tide.tool.support.DebugProcess;
import nl.cwi.sen1.tide.tool.support.DebugTool;
import nl.cwi.sen1.tide.tool.support.DebugToolListener;
import nl.cwi.sen1.tide.tool.support.Info;
import nl.cwi.sen1.tide.tool.support.ProcessStatus;

public class ProcessList
  extends JPanel
  implements DebugToolListener
{
  private Info info;
  private Container adapterPanel;
  private Map<DebugAdapter, JComponent> adapters;
  private ToolManager toolManager;

  //{{{ public ProcessList(ToolManager manager)

  public ProcessList(ToolManager manager)
  {
    info = new Info("ProcessList");
    setBackground(new Color(0xFF, 0xFF, 0xFF));
    setLayout(new BorderLayout());

    adapterPanel = new JPanel();
    adapterPanel.setLayout(new BoxLayout(adapterPanel, BoxLayout.Y_AXIS));
    add("North", adapterPanel);

    adapters = new HashMap<DebugAdapter, JComponent>();
    setPreferredSize(new Dimension(170, 300));

    this.toolManager = manager;
  }

  //}}}

  //{{{ public void adapterConnected(DebugTool tool, DebugAdapter adapter)

  public void adapterConnected(DebugTool tool, DebugAdapter adapter)
  {
    JComponent panel = new AdapterPanel(adapter, toolManager);
    adapters.put(adapter, panel);

    adapterPanel.add(panel);
    validate();
    repaint();
  }

  //}}}
  //{{{ public void adapterDisconnected(DebugTool tool, DebugAdapter adapter)

  public void adapterDisconnected(DebugTool tool, DebugAdapter adapter)
  {
    info.info("adapterDisconnected: " + adapter);
    final JComponent panel = adapters.get(adapter);
    adapters.remove(adapter);

    // remove/validate/repaint must be called from the system
    // event queue thread, because otherwise we encounter deadlocks
    // as the 'ToolBus' thread and the 'UI' thread both want to
    // modify the component tree at the same time
    Runnable runnable = new Runnable()
    {
      public void run()
      {
	adapterPanel.remove(panel);
	validate();
	repaint();
      }
    };
    EventQueue.invokeLater(runnable);
  }

  //}}}
}

class AdapterPanel
  extends JPanel
  implements DebugAdapterListener
{
  private Info info;
  private DebugAdapter adapter;
  private Container processPanel;
  private Map<DebugProcess, Component> processes;

  private ToolManager toolManager;
  private JPopupMenu adapterMenu;

  //{{{ public AdapterPanel(DebugAdapter adapter, ToolManager manager)

  public AdapterPanel(DebugAdapter adap, ToolManager manager)
  {
    setBackground(Color.white);

    info    = new Info("AdapterPanel");
    adapter = adap;
    toolManager = manager;

    adapter.addDebugAdapterListener(this);

    setLayout(new BorderLayout());

    //{{{ Handle adapter popup menu

    adapterMenu = new JPopupMenu("Adapter Tools");
    Iterator<AdapterAction> iter = manager.adapterActionIterator();
    while (iter.hasNext()) {
      adapterMenu.add(iter.next());
    }

    //}}}
    JLabel label = new JLabel(adapter.getName())
    {
      public void processMouseEvent(MouseEvent event)
      {
	if (event.isPopupTrigger()) {
	  toolManager.setCurrentAdapter(adapter);
	  adapterMenu.show(this, event.getX(), event.getY());
	} else {
	  super.processMouseEvent(event);
	}
      }
    };
    label.addMouseListener(new MouseAdapter(){});

    label.setBorder(new EmptyBorder(2,0,2,0));
    add("North", label);

    processPanel = Box.createVerticalBox();
    add("Center", processPanel);
    add("South",  Box.createVerticalStrut(3));

    processes = new HashMap<DebugProcess, Component>();

    //{{{ Handle selection of adapters

    MouseListener selectionListener = new MouseAdapter()
      {
	public void mouseClicked(MouseEvent event)
	{
	  toolManager.setCurrentAdapter(adapter);
	}
      };
    addMouseListener(selectionListener);

    //}}}
  }

  //}}}
  //{{{ public void processCreated(DebugAdapter adapter, DebugProcess process)

  public void processCreated(DebugAdapter adapter, DebugProcess process)
  {
    info.info("processCreated: " + process.getName());

    Container panel = new ProcessPanel(toolManager, process, this);

    processPanel.add(panel);
    getParent().getParent().validate();
    getParent().getParent().repaint();

    processes.put(process, panel);
  }

  //}}}
  //{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess process)

  public void processDestroyed(DebugAdapter adapter, DebugProcess process)
  {
    Component panel = processes.get(process);
    processes.remove(process);
    processPanel.remove(panel);
  }

  //}}}
  //{{{ public void select()

  public void select()
  {
    toolManager.setCurrentAdapter(adapter);
  }

  //}}}
}

class ProcessPanel
  extends JPanel
{
  private ToolManager  toolManager;
  private DebugProcess process;
  private AdapterPanel adapterPanel;
  private JPopupMenu   processMenu;

  //{{{ public ProcessPanel(manager, process, adapterPanel)

  public ProcessPanel(ToolManager manager, DebugProcess proc,
		      AdapterPanel adapPanel)
  {
    this.toolManager  = manager;
    this.process      = proc;
    this.adapterPanel = adapPanel;

    //{{{ Handle process popup menu

    processMenu = new JPopupMenu("Process Tools");
    Iterator<ProcessAction> iter = manager.processActionIterator();
    while (iter.hasNext()) {
      processMenu.add(iter.next());
    }

    // Enable mouse events by adding a dummy listener
    addMouseListener(new MouseAdapter(){});

    //}}}

    setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
    setBackground(null);
    add(new JLabel("  " + process.getPid() + " - " + process.getName()));
    add(Box.createHorizontalGlue());
    ProcessStatus status = new ProcessStatus(process);
    status.setBackground(Color.red);
    add(status);
    add(Box.createHorizontalStrut(3));

    //{{{ Handle selection of adapters

    MouseListener selectionListener =
      new MouseAdapter()
      {
	public void mouseClicked(MouseEvent event)
	{
	  adapterPanel.select();
	  toolManager.setCurrentProcess(process);
	}
      };
    addMouseListener(selectionListener);

    //}}}
  }

  //}}}

  //{{{ public void processMouseEvent(MouseEvent event)

  public void processMouseEvent(MouseEvent event)
  {
    if (event.isPopupTrigger()) {
      adapterPanel.select();
      toolManager.setCurrentProcess(process);
      processMenu.show(this, event.getX(), event.getY());
    } else {
      super.processMouseEvent(event);
    }
  }

  //}}}
}
