package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

public abstract class TideTool
  extends JInternalFrame
{
  private static int next_id = 0;

  private int id;
  private ToolManager manager;

  //{{{ public TideTool(ToolManager manager)

  public TideTool(ToolManager manager)
  {
    super("", true, true, true, true);

    this.manager = manager;

    id = next_id++;
  }

  //}}}

  //{{{ public ToolManager getManager()

  public ToolManager getManager()
  {
    return manager;
  }

  //}}}
  //{{{ public int getId()

  public int getId()
  {
    return id;
  }

  //}}}

  //{{{ public void displayError(Expr error)

  public void displayError(Expr error)
  {
    displayError(error.getErrorMessage(), error.getErrorData());
  }

  //}}}
  //{{{ public void displayError(Expr error)

  public void displayError(String msg, Expr data)
  {
    String string = data.toString();
    if (!string.equals("[]")) {
      msg += ": " + string;
    }



    JOptionPane.showMessageDialog(this, msg, "Tide Error",
				  JOptionPane.ERROR_MESSAGE);
    System.err.println("Tide Error: " + msg + ": " + data);
  }

  //}}}
}
