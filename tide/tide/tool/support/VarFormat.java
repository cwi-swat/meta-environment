package tide.tool.support;



public class VarFormat
  implements ExprFormat
{
  private static final String PAT_VAR =
    "var(<str>,<term>,<int>,<int>,<int>,<int>)";

  public String format(Expr expr)
  {
    if (expr.isVar()) {
      return expr.getVarValue().toString();
    } else if (expr.isVarUnknown()) {
      return expr.getVarUnknownMessage();
    } else {
      return "???";
    }
  }
}

