package tide.tool.support;

public interface DebugAdapterListener
{
  public void processCreated(DebugAdapter adapter, DebugProcess process);
  public void processDestroyed(DebugAdapter adapter, DebugProcess process);
}
