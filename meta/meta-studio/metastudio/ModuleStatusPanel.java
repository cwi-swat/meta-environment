package metastudio;

import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.util.List;

import javax.swing.*;
import javax.swing.border.*;

public class ModuleStatusPanel
  extends JPanel
  implements ModuleSelectionListener
{
  private Module module;

  private TitledBorder border;

  private JTabbedPane tabbedPane;
  private JPanel infoPanel;
  private JPanel infoKeys;
  private JPanel infoValues;

  private JScrollPane infoPane;
  private JPanel importPanel;
  private JPanel parentPanel;

  private JPanel info;
  private JList parents;
  private JList imports;

  private ModuleManager moduleManager;

  //{{{ public ModuleStatusPanel(ModuleManager moduleManager)

  public ModuleStatusPanel(final ModuleManager moduleManager)
  {
    this.moduleManager = moduleManager;
    moduleManager.addModuleSelectionListener(this);

    border = new TitledBorder(new LineBorder(Color.black), "No module");
    setBorder(border);

    setLayout(new BorderLayout());

    tabbedPane = new JTabbedPane();

    infoPanel = new JPanel();

    info = new JPanel();
    info.setBackground(Color.white);
    infoKeys = new JPanel();
    infoValues = new JPanel();
    info.setLayout(new BoxLayout(info, BoxLayout.X_AXIS));
    info.add(infoKeys);
    info.add(infoValues);
    infoPanel.setLayout(new BorderLayout());
    infoPane = new JScrollPane(info);
    infoPanel.add(infoPane, BorderLayout.CENTER);

    importPanel = new JPanel();
    imports = new JList();
    MouseListener mouseListener =
      new MouseAdapter() {
	public void mouseClicked(MouseEvent event) {
	  String selected = (String)(((JList)event.getSource()).getSelectedValue());
	  if (selected != null) {
	    moduleManager.selectModule(selected);
	  }
	}
      };
    imports.addMouseListener(mouseListener);
    imports.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    importPanel.setLayout(new BorderLayout());
    importPanel.add(new JScrollPane(imports), BorderLayout.CENTER);

    parentPanel = new JPanel();
    parents = new JList();
    parents.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    parents.addMouseListener(mouseListener);
    parentPanel.setLayout(new BorderLayout());
    parentPanel.add(new JScrollPane(parents), BorderLayout.CENTER);

    tabbedPane.add("Info", infoPanel);
    tabbedPane.add("Imports", importPanel);
    tabbedPane.add("Imported by", parentPanel);

    add(tabbedPane, BorderLayout.CENTER);
  }

  //}}}
  //{{{ public void moduleSelected(Module module)

  public void moduleSelected(Module module)
  {
    this.module = module;

    if (module == null) {
      border.setTitle("No module");
      imports.setModel(new ListListModel(new LinkedList()));
      parents.setModel(new ListListModel(new LinkedList()));
    } else {
      border.setTitle(module.getName());

      imports.setModel(module.fetchChildListModel());
      parents.setModel(module.fetchParentListModel());
    }

    clearInfo();

    repaint();
  }

  //}}}
  //{{{ public void setModuleInfo(String moduleName, List info)

  public void setModuleInfo(String moduleName, List info)
  {
    if (module != null && moduleName.equals(module.getName())) {
      updateInfo(info);
    }
  }

  //}}}

  //{{{ private void clearInfo()

  private void clearInfo()
  {
    infoKeys.removeAll();
    infoValues.removeAll();
  }

  //}}}
  //{{{ private void updateInfo(List infoList)

  private void updateInfo(List infoList)
  {
    clearInfo();

    Iterator iter = infoList.iterator();
    while (iter.hasNext()) {
      String[] pair = (String[])iter.next();
      JLabel key = new JLabel(pair[0]);
      infoKeys.add(key);

      JTextField value = new JTextField(pair[1]);
      value.setEditable(false);

      infoValues.add(value);
    }

    infoPane.invalidate();
    infoPane.revalidate();
  }

  //}}}
}

