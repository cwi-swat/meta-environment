package tide.tool.support;

import java.util.*;

import aterm.*;

public class VarFormat
  implements ExprFormat
{
  private static final String PAT_VAR =
    "var(<str>,<term>,<int>,<int>,<int>,<int>)";

  public String format(Expr expr)
  {
    Iterator args = expr.toTerm().match(PAT_VAR).iterator();
    String var = (String)args.next();
    return args.next().toString();
  }
}

