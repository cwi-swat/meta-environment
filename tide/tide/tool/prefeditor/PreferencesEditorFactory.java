package tide.tool.prefeditor;

import javax.swing.Icon;

import tide.tool.*;

public class PreferencesEditorFactory
  implements TideToolFactory
{
  private ToolManager manager;

  //{{{ public PreferencesEditorFactory(ToolManager manager)

  public PreferencesEditorFactory(ToolManager manager)
  {
    this.manager = manager;
  }

  //}}}
  //{{{ public TideTool createTool()

  public TideTool createTool()
  {
    TideTool tool = new PreferencesEditor(manager);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "PreferencesEditor";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
