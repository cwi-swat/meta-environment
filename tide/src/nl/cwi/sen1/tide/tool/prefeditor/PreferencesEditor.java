package nl.cwi.sen1.tide.tool.prefeditor;

//{{{ imports

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import nl.cwi.sen1.tide.PreferenceListener;
import nl.cwi.sen1.tide.PreferenceSet;
import nl.cwi.sen1.tide.tool.TideTool;
import nl.cwi.sen1.tide.tool.ToolManager;

//}}}

public class PreferencesEditor
  extends TideTool
  implements PreferenceListener, ActionListener
{
  private PreferenceSet preferences;
  private FontPreferenceEditor fontPrefs;

  private JButton buttonUpdate;
  private JButton buttonRevert;
  private JButton buttonClose;

  //{{{ public PreferencesEditor(ToolManager manager)

  public PreferencesEditor(ToolManager manager)
  {
    super(manager);

    preferences = manager.getPreferences();
    preferences.addPreferenceListener(this);

    JTabbedPane pane = new JTabbedPane();
    fontPrefs = new FontPreferenceEditor(this, preferences);
    pane.addTab("Fonts", null, fontPrefs, "Edit font preferences");

    setLayout(new BorderLayout());
    add("Center", pane);

    JPanel buttons = new JPanel();
    buttons.setLayout(new GridLayout(1,5));

    buttonUpdate = new JButton("Update");
    buttonRevert = new JButton("Revert");

    buttonUpdate.setEnabled(false);
    buttonRevert.setEnabled(false);

    buttonUpdate.addActionListener(this);
    buttonRevert.addActionListener(this);

    buttons.add(new JPanel());
    buttons.add(buttonUpdate);
    buttons.add(new JPanel());
    buttons.add(buttonRevert);
    buttons.add(new JPanel());

    add("South", buttons);
  }

  private void cleanup()
  {
    fontPrefs.cleanup();
    preferences.removePreferenceListener(this);
    getManager().removeTool(this);
  }

  public void preferenceChanged(PreferenceSet prefs, String name,
				String oldValue, String newValue)
  {
  }

  public void preferencesChanged(PreferenceSet prefs)
  {
  }

  //}}}
  //{{{ public void preferencesStatusChanged(boolean clean)

  public void preferencesStatusChanged(PreferenceSet set, boolean clean)
  {
  }

  //}}}

  //{{{ void changePending()

  void changePending()
  {
    buttonUpdate.setEnabled(true);
    buttonRevert.setEnabled(true);
  }

  //}}}
  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getSource() == buttonUpdate) {
      fontPrefs.doUpdate();
      buttonUpdate.setEnabled(false);
      buttonRevert.setEnabled(false);
    } else if (event.getSource() == buttonRevert) {
      fontPrefs.doRevert();
      buttonUpdate.setEnabled(false);
      buttonRevert.setEnabled(false);
    }
  }

  //}}}
}

