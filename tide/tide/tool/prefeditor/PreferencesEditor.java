package tide.tool.prefeditor;

//{{{ imports

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.event.*;

import tide.*;
import tide.tool.*;

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

    setSize(500, 350);
    setTitle("Edit Preferences");
    setBackground(Color.white);

    preferences = manager.getPreferences();
    preferences.addPreferenceListener(this);

    //{{{ Listen to internalFrameClosed events

    addInternalFrameListener(new InternalFrameAdapter() 
      {
        public void internalFrameClosed(InternalFrameEvent event) {
	  cleanup();
	}
      }
    );

    //}}}

    JTabbedPane pane = new JTabbedPane();
    fontPrefs = new FontPreferenceEditor(this, preferences);
    pane.addTab("Fonts", null, fontPrefs, "Edit font preferences");

    Container content = getContentPane();
    content.setLayout(new BorderLayout());
    content.add("Center", pane);

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

    content.add("South", buttons);
  }

  //}}}
  //{{{ private void cleanup()

  private void cleanup()
  {
    fontPrefs.cleanup();
    preferences.removePreferenceListener(this);
    getManager().removeTool(this);
  }

  //}}}

  //{{{ public void preferenceChanged(prefs, name, oldValue, newValue)

  public void preferenceChanged(PreferenceSet prefs, String name,
				String oldValue, String newValue)
  {
  }

  //}}}
  //{{{ public void preferencesChanged(PreferenceSet prefs)

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

