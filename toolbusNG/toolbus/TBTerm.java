/**
 * @author paulk, Jul 18, 2002
 */

package toolbus;

import aterm.*;
import aterm.pure.PureFactory;

/**
 * TBTerm extends ATerms in several ways. This is achieved by staying with the ATerm representation
 * but giving a special meaning to some symbols. The extensions are:
 * - a number of standard terms and placeholders
 * - the notion of variable (var) and result variable (rvar)
 * - special functions (add, greater, ...) that can be typechecked and evaluated
 *    (see FunctionDescriptors)
 * - matching and substitution
 */

public class TBTerm {

  public static ATermFactory factory;

  private static boolean initDone = false;

  public static ATerm True;

  public static ATerm False;
  public static ATerm BoolType;
  public static ATerm IntType;
  public static ATerm RealType;
  public static ATerm StrType;
  public static ATerm TermType;
  public static ATerm ListType;

  public static ATerm VoidType; // for the benefit of JavaTools

  public static ATerm BoolPlaceholder;
  public static ATerm IntPlaceholder;
  public static ATerm RealPlaceholder;
  public static ATerm StrPlaceholder;
  public static ATerm TermPlaceholder;
  public static ATerm ListPlaceholder;

  public static ATerm TransactionIdVar;
  public static ATerm TransactionIdResVar;

  private static int nTransactions = 0;

  public static void init() {
    if (!initDone) {
      init(new PureFactory());
    }
    initDone = true;
  }

  private static void init(ATermFactory fact) {
    factory = fact;
    True = factory.make("true");
    False = factory.make("false");
    BoolType = factory.make("bool");
    IntType = factory.make("int");
    RealType = factory.make("real");
    StrType = factory.make("str");
    TermType = factory.make("term");
    ListType = factory.make("list");

    VoidType = factory.make("void");

    BoolPlaceholder = factory.makePlaceholder(BoolType);
    IntPlaceholder = factory.makePlaceholder(IntType);
    RealPlaceholder = factory.makePlaceholder(RealType);

    StrPlaceholder = factory.makePlaceholder(StrType);
    TermPlaceholder = factory.makePlaceholder(TermType);
    ListPlaceholder = factory.makePlaceholder(ListType);

    TransactionIdVar = factory.make("var(-1,transaction,TransactionId))");
    TransactionIdResVar = factory.make("rvar(-1,transaction,TransactionId))");

    FunctionDescriptors.init(factory);
  }

  public static boolean isTrue(ATerm t) {
    return t == True;
  }

  public static boolean isFalse(ATerm t) {
    return t == False;
  }

  public static boolean isBoolean(ATerm t) {
    return t == True || t == False;
  }

  public static boolean isResVar(ATerm t) {
    return t.getType() == ATerm.APPL && ((ATermAppl) t).getName() == "rvar";
  }

  public static boolean isVar(ATerm t) {
    return t.getType() == ATerm.APPL && ((ATermAppl) t).getName() == "var";
  }

  private static ATermList getVarArgs(ATerm t) {
    if (t.getType() == ATerm.APPL) {
      ATermAppl appl = (ATermAppl) t;
      if (appl.getName() == "var" || appl.getName() == "rvar") {
        return appl.getArguments(); // check length?
      }
    }
    throw new ToolBusInternalError("illegal var in getVarIndex(" + t + ")");
  }

  public static int getVarIndex(ATerm t) {
    return ((ATermInt) getVarArgs(t).elementAt(0)).getInt();
  }

  public static ATerm getVarType(ATerm t) {
    return getVarArgs(t).elementAt(1);
  }

  public static String getVarName(ATerm t) {
    return ((ATermAppl) getVarArgs(t).elementAt(2)).getName();
  }

  public static ATerm setVarIndexAndType(ATerm t, int n, ATerm type) {
    //System.out.println("setVarIndex(" + t + ", " + n + ")");
    ATermList args = ((ATermAppl) t).getArguments();
    if (((ATermInt) args.getFirst()).getInt() < 0) {
      ATerm varname = args.getLast();
      if (isVar(t))
        return TBTerm.factory.make("var(<int>,<term>,<term>)", new Integer(n), type, varname);
      else
        return TBTerm.factory.make("rvar(<int>,<term>,<term>)", new Integer(n), type, varname);
    } else
      return t;
  }

  public static ATerm changeResVarIntoVar(ATerm t) {
    if (!isResVar(t)) {
      throw new ToolBusInternalError("wrong arg in makeVar(" + t + ")");
    }
    ATermList args = ((ATermAppl) t).getArguments();
    AFun afun = t.getFactory().makeAFun("var", args.getLength(), false);
    return TBTerm.factory.makeAppl(afun, args);
  }

  public static ATerm newTransactionId() {
    AFun afun = factory.makeAFun("transaction", 1, false);
    ATerm arg = factory.makeInt(nTransactions++);
    return factory.makeAppl(afun, arg);
  }

  /**
   * Resolve the variables in ATerm t using Environment env.
   * The declaration information in env is used to replace the index and type
   * field in every variable occurrence.
   */

  public static ATerm resolveVars(ATerm t, Environment env) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t))
          return setVarIndexAndType(t, env.getVarIndex(t), env.getVarType(t));

        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        ATerm cargs[] = new ATerm[args.length];
        if (args.length == 0)
          return t;
        for (int i = 0; i < args.length; i++) {
          cargs[i] = resolveVars(args[i], env);
        }
        return TBTerm.factory.makeAppl(afun, cargs);

      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append(resolveVars(((ATermList) t).elementAt(i), env));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in compileVars: " + t);
  }

  /**
   * Check that the two sides of an assignment are "compatibele", i.e. they must be equal
   * or the type of the lhs may be more general than that of the rhs.
   */

  public static boolean assignCompatible(ATerm lhsType, ATerm rhsType) throws ToolBusException {

    if (isVar(lhsType) || isResVar(lhsType)) {
      throw new ToolBusException("variable not allowd in a type: " + lhsType);
    } else if (isVar(rhsType) || isResVar(rhsType)) {
      throw new ToolBusException("variable not allowd in a type: " + rhsType);
    }
    if (lhsType == TermType || lhsType == rhsType) {
      return true;
    }

    switch (lhsType.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.REAL :
        throw new ToolBusInternalError("assignCompatible: illegal lhsType: " + lhsType);
      case ATerm.PLACEHOLDER :
        if (lhsType == IntPlaceholder && rhsType == IntType)
          return true;
        else if (lhsType == RealPlaceholder && rhsType == RealType)
          return true;
        else if (lhsType == StrPlaceholder && rhsType == StrType)
          return true;
        else if (lhsType == ListPlaceholder && (rhsType == ListType || rhsType.getType() == ATerm.LIST))
          return true;
        else if (lhsType == TBTerm.TermPlaceholder)
          return true;
        else
          return false;
      case ATerm.APPL :
        if (rhsType == TermType) {
          return true;
        } else if (lhsType == ListType && rhsType.getType() == ATerm.LIST) {
          return true;
        } else if (((ATermAppl) lhsType).getName().equals("list")) {
          if (rhsType.getType() != ATerm.LIST) {
            return false;
          }
          ATerm lhsargs[] = ((ATermAppl) lhsType).getArgumentArray();
          if (lhsargs.length != 1) {
            throw new ToolBusException("illegal list type: " + lhsType);
          }
          for (int i = 0; i < ((ATermList) rhsType).getLength(); i++) {
            if (!assignCompatible(lhsargs[0], ((ATermList) rhsType).elementAt(i))) {
              return false;
            }
          }
          return true;
        } else if (
          rhsType.getType() != ATerm.APPL
            || !((ATermAppl) lhsType).getName().equals(((ATermAppl) rhsType).getName())) {
          return false;
        }

        ATerm lhsargs[] = ((ATermAppl) lhsType).getArgumentArray();
        ATerm rhsargs[] = ((ATermAppl) rhsType).getArgumentArray();
        if (lhsargs.length == 0) {
          return true;
        } else if (lhsargs.length != rhsargs.length) {
          return false;
        }
        for (int i = 0; i < lhsargs.length; i++) {
          if (!assignCompatible(lhsargs[i], rhsargs[i])) {
            return false;
          }
        }
        return true;
      case ATerm.LIST :
        if (((ATermList) lhsType).getLength() != ((ATermList) rhsType).getLength()) {
          return false;
        }
        for (int i = 0; i < ((ATermList) lhsType).getLength(); i++) {
          if (!assignCompatible(((ATermList) lhsType).elementAt(i), ((ATermList) rhsType).elementAt(i))) {
            return false;
          }
        }
        return true;
    }
    return false;
  }

  /**
   * Transform a term into a pattern that can be used by tool interfaces.
   */

  public static ATerm makePattern(ATerm t, Environment env, boolean recurring) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB : // ??

      case ATerm.INT :
        return IntPlaceholder;

      case ATerm.PLACEHOLDER :
        return t;

      case ATerm.REAL :
        return RealPlaceholder;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t)) {
          ATerm type = TBTerm.getVarType(t);
          return factory.makePlaceholder(type);
        }
        if (TBTerm.isBoolean(t)) {
          return BoolPlaceholder;
        }
        AFun fun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0) {
          if (fun.isQuoted())
            return StrPlaceholder;
          else
            return t;
        }
        if (!recurring)
          return factory.makePlaceholder(t);
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = makePattern(args[i], env, false);
        }
        return factory.makeAppl(fun, vargs);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(makePattern(((ATermList) t).elementAt(i), env, true), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in getType: " + t);
  }

  /**
   * Replace all variables in an ATerm by their value.
   * 
   */

  public static ATerm substitute(ATerm t, Environment env) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;
      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t)) {
          return env.getValue(t);
        }
        if (TBTerm.isBoolean(t)) {
          return t;
        }
        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0)
          return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = substitute(args[i], env);
        }
        return factory.makeAppl(afun, vargs);
      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(substitute(((ATermList) t).elementAt(i), env), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in substitute: " + t);
  }

  /**
   * Matching of two terms. Both terms use a different environment. There are two flavours of matching:
   * match      -- complete match with full treatment of variabeles
   * mightMatch -- a partial match that ignores variables.
   * 
   */

  private static Environment enva;
  private static Environment envb;
  private static boolean fullMatch = true;
  private static MatchResult mr;

  public static boolean match(ATerm ta, Environment enva, ATerm tb, Environment envb) throws ToolBusException {
    mr = new MatchResult(enva, envb);

    TBTerm.enva = enva;
    TBTerm.envb = envb;

    fullMatch = true;
    boolean res = performMatch(ta, tb);
    if (res) {
      mr.updateEnvs();
      return true;
    } else
      return false;
  }

  public static boolean mightMatch(ATerm ta, ATerm tb) {
    fullMatch = false;
    try {
      return performMatch(ta, tb);
    } catch (ToolBusException e) {
      throw new ToolBusInternalError(e.getMessage());
    }
  }

  private static boolean performMatch(ATerm ta, ATerm tb) throws ToolBusException {
    if (TBTerm.isVar(ta))
      if (fullMatch) {
        ta = enva.getValue(ta);
      } else {
        return true;
      }

    if (TBTerm.isVar(tb))
      if (fullMatch) {
        tb = envb.getValue(tb);
      } else {
        return true;
      }

    if (TBTerm.isResVar(ta)) {
      if (TBTerm.isResVar(tb)) {
        return false;
      }
      if (fullMatch) {
        mr.assignLeft(ta, tb); // check var type!
      }
      return true;
    }

    if (TBTerm.isResVar(tb)) {
      if (fullMatch) {
        mr.assignRight(tb, ta); // check var type!
      }
      return true;
    }

    switch (ta.getType()) {
      case ATerm.BLOB :
        return ta.equals(tb); // || (tb == TBTerm.BlobPlaceholder);
      case ATerm.INT :
        return ta.equals(tb) || (tb == TBTerm.IntPlaceholder);
      case ATerm.REAL :
        return ta.equals(tb) || (tb == TBTerm.RealPlaceholder);
      case ATerm.PLACEHOLDER :
        if (ta.equals(IntPlaceholder) && tb.getType() == ATerm.INT)
          return true;
        else if (ta == RealPlaceholder && tb.getType() == ATerm.REAL)
          return true;
        else if (ta == StrPlaceholder && tb.getType() == ATerm.APPL && ((ATermAppl) tb).getArity() == 0)
          return true;
        else if (ta == ListPlaceholder && tb.getType() == ATerm.LIST)
          return true;
        else if (ta == TBTerm.TermPlaceholder)
          return true;
        else
          return false;
      case ATerm.APPL :
        if (tb.getType() == ATerm.PLACEHOLDER) {
          if (tb == StrPlaceholder && ((ATermAppl) ta).getArity() == 0)
            return true;
          else if (tb == TermPlaceholder)
            return true;
          else
            return false;
        }
        if (tb.getType() != ATerm.APPL
          || ((ATermAppl) ta).getName() != ((ATermAppl) tb).getName()
          || ((ATermAppl) ta).getArity() != ((ATermAppl) tb).getArity())
          return false;
        else {
          ATerm a_args[] = ((ATermAppl) ta).getArgumentArray();
          ATerm b_args[] = ((ATermAppl) tb).getArgumentArray();
          for (int i = 0; i < a_args.length; i++) {
            if (!performMatch(a_args[i], b_args[i]))
              return false;
          }
          return true;
        }

      case ATerm.LIST :
        if (tb == ListPlaceholder) {
          return true;
        }
        if (((ATermList) ta).getLength() != ((ATermList) tb).getLength())
          return false;
        else {
          for (int i = 0; i < ((ATermList) ta).getLength(); i++) {
            if (!performMatch(((ATermList) ta).elementAt(i), ((ATermList) tb).elementAt(i)))
              return false;
          }
          return true;
        }
      default :
        throw new ToolBusInternalError("illegal ATerm in match1: " + ta);
    }
  }

}
