package nl.cwi.sen1.tide.tool.support;

public interface DebugToolListener
{
  public void adapterConnected(DebugTool tool, DebugAdapter adapter);
  public void adapterDisconnected(DebugTool tool, DebugAdapter adapter);
}
