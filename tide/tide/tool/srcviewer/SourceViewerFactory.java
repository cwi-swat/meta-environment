package tide.tool.srcviewer;

import javax.swing.Icon;

import tide.tool.*;
import tide.tool.support.DebugProcess;

public class SourceViewerFactory
  implements ProcessToolFactory
{
  protected static final String PREF_SOURCECODE_FONT  =
    "font.spec.sourcecode";
  protected static final String PREF_LINENUMBER_FONT  =
    "font.spec.linenumber";

  private ToolManager manager;

  //{{{ public SourceViewerFactory(ToolManager manager)

  public SourceViewerFactory(ToolManager manager)
  {
    this.manager = manager;

    manager.getPreferences().registerPreference(PREF_SOURCECODE_FONT);
    manager.getPreferences().registerPreference(PREF_LINENUMBER_FONT);
  }

  //}}}
  //{{{ public ProcessTool createTool(DebugProcess process)

  public ProcessTool createTool(DebugProcess process)
  {
    ProcessTool tool = new SourceViewer(manager, process);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "SourceViewer";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
