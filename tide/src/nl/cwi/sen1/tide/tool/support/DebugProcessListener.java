package nl.cwi.sen1.tide.tool.support;

public interface DebugProcessListener
{
  public void ruleCreated(DebugProcess process, Rule rule);
  public void ruleDeleted(DebugProcess process, Rule rule);
  public void ruleModified(DebugProcess process, Rule rule);
  public void ruleTriggered(DebugProcess process, Rule rule, Expr value);
  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag);
}
