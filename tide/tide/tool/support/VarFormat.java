package tide.tool.support;

import java.util.LinkedList;
import java.util.List;

import aterm.ATerm;
import aterm.ATermFactory;



public class VarFormat
  implements ExprFormat
{
  private static final String PAT_VAR =
    "var(<str>,<term>,<int>,<int>,<int>,<int>)";
  private static final String PAT_UNKNOWN_VAR = "var-unknown(<str)";
  
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

  public static ATerm  makeVarUnknown(ATermFactory factory, String msg)
     {            
  	       List args = new LinkedList();
  	       args.add(msg);
  	       return factory.make(PAT_UNKNOWN_VAR, args);
  	   }
   
     public static ATerm makeExprVar(ATermFactory factory, String var, ATerm value,  int pos, int line, int column, int length)
     {
  	       List args = new LinkedList();
  	       args.add(var);
  	       args.add(value);
  	       args.add(new Integer(pos));
  	       args.add(new Integer(line));
  	       args.add(new Integer(column));
  	       args.add(new Integer(length));
  	       return factory.make(PAT_VAR, args);
  	   }
  
}

