package tide.tool.support;

public interface DebugProcessListener
{
  public void ruleCreated(DebugProcess process, Rule rule);
  public void ruleDeleted(DebugProcess process, Rule rule);
  public void ruleModified(DebugProcess process, Rule rule);
}
