// Java tool bridge SdfImportGraphBridge
// This file is generated automatically, please do not edit!
// generation time: May 25, 2004 4:21:34 PM

package sdf;

import aterm.*;

public class SdfImportGraphBridge
  extends SdfImportGraphTool
{
  private SdfImportGraphTif tool;

  //{{{  public SdfImportGraphBridge(ATermFactory factory, SdfImportGraphTif tool)

  public SdfImportGraphBridge(ATermFactory factory, SdfImportGraphTif tool)
  {
    super(factory);
    this.tool = tool;
  }

  //}}}

  //{{{  public ATerm importRelationToGraph(ATerm t0)

  public ATerm importRelationToGraph(ATerm t0)
  {
    if (tool != null) {
      return tool.importRelationToGraph(t0);
    }
    else {
      throw new UnsupportedOperationException("method `importRelationToGraph' not supported.");
    }
  }

  //}}}
  //{{{  public void recTerminate(ATerm t0)

  public void recTerminate(ATerm t0)
  {
    if (tool != null) {
      tool.recTerminate(t0);
    }
    else {
      throw new UnsupportedOperationException("method `recTerminate' not supported.");
    }
  }

  //}}}
}
