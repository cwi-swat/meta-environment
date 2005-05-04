package nl.cwi.sen1.tide.tool;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

abstract public class TideDialog
  extends JDialog
  implements ActionListener
{
  public static final int DIALOG_OK	    = 0;
  public static final int DIALOG_OK_CANCEL  = 1;

  public static final int RESULT_OK	    = 0;
  public static final int RESULT_CANCEL	    = 1;

  private JButton ok;
  private JButton cancel;

  private int type;
  private int result;

  //{{{ public TideDialog(String title, int type)

  public TideDialog(String title, int type)
  {
    super();
    this.type = type;
  }

  //}}}
  //{{{ public void init()

  public void init()
  {
    ok = new JButton("Ok");
    cancel = new JButton("Cancel");

    ok.addActionListener(this);
    cancel.addActionListener(this);

    Container content = getContentPane();

    content.setLayout(new BorderLayout());

    JPanel body = new JPanel();

    addContent(body);

    content.add("Center", body);

    JPanel buttons = new JPanel();
    buttons.setLayout(new GridLayout(0, type == DIALOG_OK ? 1 : 2,
				     5, 5));
    buttons.add(ok);
    if (type == DIALOG_OK_CANCEL) {
      buttons.add(cancel);
    }

    JPanel buttonPanel = new JPanel();
    buttonPanel.setLayout(new BorderLayout());
    buttonPanel.add("Center", buttons);
    buttonPanel.add("West", Box.createHorizontalStrut(30));
    buttonPanel.add("East", Box.createHorizontalStrut(30));

    content.add("South", buttonPanel);
    pack();

    result = RESULT_CANCEL;
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getSource() == ok) {
      okPressed();
    } else if (event.getSource() == cancel) {
      cancelPressed();
    }
  }

  //}}}
  //{{{ public void okPressed()

  public void okPressed()
  {
      if (verifyInput()) {
	result = RESULT_OK;
	dispose();
      }
  }

  //}}}
  //{{{ public void cancelPressed()

  public void cancelPressed()
  {
    result = RESULT_CANCEL;
    dispose();
  }

  //}}}

  //{{{ public boolean verifyInput()

  public boolean verifyInput()
  {
    return true;
  }

  //}}}
  abstract public void addContent(JPanel panel);

  //{{{ public int getResult()

  public int getResult()
  {
    return result;
  }

  //}}}
}
