package tide.tool.prefeditor;

import java.awt.*;
import java.awt.event.*;
import java.util.Iterator;

import javax.swing.*;

import tide.*;

public class FontPreferenceEditor
  extends JPanel
  implements PreferenceListener
{
  private static final int MAX_FONTS = 16;

  private PreferencesEditor editor;
  private PreferenceSet preferences;

  private int fontCount;
  private FontPanel[] fontPanels;
  private JLabel preview;

  //{{{ public FontPreferenceEditor(editor, preferences)

  public FontPreferenceEditor(PreferencesEditor editor,
			      PreferenceSet preferences)
  {
    this.editor      = editor;
    this.preferences = preferences;

    preferences.addPreferenceListener(this);

    setLayout(new BorderLayout());
    //setBackground(Color.white);

    JPanel fontPanel = new JPanel();
    fontPanel.setLayout(new GridLayout(0,1));
    add("North", fontPanel);
    fontPanel.add(new JPanel());

    fontPanels = new FontPanel[MAX_FONTS];
    Iterator fonts = preferences.preferenceNameIterator("font.spec.");
    while (fonts.hasNext()) {
      String name = (String)fonts.next();
      String key  = name.substring("font.spec.".length());
      String fontName = preferences.getPreference("font.name." + key);
      if (fontName == null) {
	fontName = key;
      }
      //String fontSpec = preferences.getPreference("font.spec." + key);
      fontPanels[fontCount] = new FontPanel(this, preferences, key);
      fontPanel.add(fontPanels[fontCount]);
      fontCount++;
    }

    preview = new JLabel("", JLabel.CENTER);
    preview.setForeground(Color.black);
    add("Center", preview);
  }

  //}}}
  //{{{ protected void cleanup()

  protected void cleanup()
  {
    preferences.removePreferenceListener(this);
  }

  //}}}
  //{{{ protected void doRevert()

  protected void doRevert()
  {
    for (int i=0; i<fontCount; i++) {
      fontPanels[i].doRevert();
    }
  }

  //}}}
  //{{{ protected void doUpdate()

  protected void doUpdate()
  {
    for (int i=0; i<fontCount; i++) {
      fontPanels[i].doUpdate();
    }
  }

  //}}}
  //{{{ protected void changePending(FontPanel panel)

  protected void changePending(FontPanel panel)
  {
    editor.changePending();
    preview.setFont(panel.getFont());
    preview.setText("This is an example of the " + panel.getName()
		   + " font - {}();:#$*");
  }

  //}}}

  //{{{ public void preferenceChanged(prefs, name, oldValue, newValue)

  public void preferenceChanged(PreferenceSet prefs, String name,
				String oldValue, String newValue)
  {
    doRevert();
  }

  //}}}
  //{{{ public void preferencesChanged(PreferenceSet prefs)

  public void preferencesChanged(PreferenceSet prefs)
  {
    doRevert();
  }

  //}}}
  //{{{ public void preferencesStatusChanged(boolean clean)

  public void preferencesStatusChanged(PreferenceSet set, boolean clean)
  {
  }

  //}}}
}

class FontPanel
  extends JPanel
  implements ActionListener
{
  private static final int MIN_SIZE =  8;
  private static final int MAX_SIZE = 24;

  private static final Color COLOR_UNCHANGED = Color.black;
  private static final Color COLOR_CHANGED   = Color.red;

  private FontPreferenceEditor editor;
  private PreferenceSet preferences;
  private String    key;
  private String    name;

  private JLabel    fontLabel;
  private JComboBox fontFamily;
  private JComboBox fontSize;
  private JCheckBox fontBold;
  private JCheckBox fontItalic;
  private Font      font;

  private boolean   inRevert;

  //{{{ public FontPanel(editor, prefs, key)

  public FontPanel(FontPreferenceEditor editor, PreferenceSet prefs,
		   String key)
  {
    this.editor = editor;

    setLayout(new BorderLayout());

    this.preferences = prefs;
    this.key         = key;

    GraphicsEnvironment env =
      GraphicsEnvironment.getLocalGraphicsEnvironment();
    //String[] families = env.getAvailableFontFamilyNames();
    String[] families = env.getAvailableFontFamilyNames();
    String[] sizes = new String[MAX_SIZE-MIN_SIZE+1];
    for (int i=MIN_SIZE; i<=MAX_SIZE; i++) {
      sizes[i-MIN_SIZE] = String.valueOf(i);
    }

    name = preferences.getPreference("font.name." + key);

    fontLabel  = new JLabel(name + ": ");
    fontFamily = new JComboBox(families);
    fontSize   = new JComboBox(sizes);
    fontBold   = new JCheckBox("Bold");
    fontItalic = new JCheckBox("Italic");

    fontFamily.addActionListener(this);
    fontSize.addActionListener(this);
    fontBold.addActionListener(this);
    fontItalic.addActionListener(this);

    doRevert();

    Dimension dim = new Dimension(120, 1);
    fontLabel.setPreferredSize(dim);
    fontLabel.setMaximumSize(dim);
    fontLabel.setMinimumSize(dim);

    add("West", fontLabel);
    add("Center", fontFamily);
    
    JPanel right = new JPanel();
    right.setLayout(new GridLayout(1,3));
    right.add(fontSize);
    right.add(fontBold);
    right.add(fontItalic);
    add("East", right);
  }

  //}}}
  //{{{ private String getFontSpec()

  private String getFontSpec()
  {
    String fontSpec = fontFamily.getSelectedItem() + "-";
    String style = null;
    if (fontBold.isSelected()) {
      style = "BOLD";
    }
    if (fontItalic.isSelected()) {
      if (style == null) {
	style = "ITALIC";
      } else {
	style += "ITALIC";
      }
    }
    if (style == null) {
      style = "PLAIN";
    }

    fontSpec += style + "-" + (fontSize.getSelectedIndex()+MIN_SIZE);

    /*
    String family = font.getFamily();
    String style = null;
    switch (font.getStyle()) {
      case Font.BOLD:
	style = "BOLD";
	break;
      case Font.ITALIC:
	style = "ITALIC";
	break;
      case Font.BOLD+Font.ITALIC:
	style = "BOLDITALIC";
	break;
    }
    String size = String.valueOf(font.getSize());

    return family + "-" + style + "-" + size;
    */

    return fontSpec;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public Font getFont()

  public Font getFont()
  {
    return font;
  }

  //}}}
  //{{{ protected void doRevert()

  protected void doRevert()
  {
    inRevert = true;

    String fontSpec = preferences.getPreference("font.spec." + key);

    if (fontSpec == null) {
      fontSpec = preferences.getPreference("font.spec.default");
    }

    int index;

    index = fontSpec.indexOf('-');
    String family = fontSpec.substring(0, index);

    font = Font.decode(fontSpec);
    System.out.println("selecting family: " + family);
    fontFamily.setSelectedItem(family);
    fontSize.setSelectedIndex(font.getSize()-MIN_SIZE);
    fontBold.setSelected((font.getStyle() & Font.BOLD) == Font.BOLD);
    fontItalic.setSelected((font.getStyle()
			    & Font.ITALIC) == Font.ITALIC);
    fontLabel.setForeground(COLOR_UNCHANGED);

    inRevert = false;
  }

  //}}}
  //{{{ protected void doUpdate()

  protected void doUpdate()
  {
    String fontSpec = getFontSpec();
    System.out.println("fontSpec = " + fontSpec);
    font = Font.decode(fontSpec);

    preferences.setPreference("font.spec." + key, fontSpec);
    
    fontLabel.setForeground(COLOR_UNCHANGED);
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (!inRevert) {
      font = Font.decode(getFontSpec());

      editor.changePending(this);
      fontLabel.setForeground(COLOR_CHANGED);
    }
  }

  //}}}
}
