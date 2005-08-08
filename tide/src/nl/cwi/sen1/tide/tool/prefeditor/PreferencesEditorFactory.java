package nl.cwi.sen1.tide.tool.prefeditor;

import javax.swing.Icon;

import nl.cwi.sen1.tide.tool.TideTool;
import nl.cwi.sen1.tide.tool.TideToolFactory;
import nl.cwi.sen1.tide.tool.ToolManager;

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
