package toolbus.parser;

import java.io.IOException;
import java.util.Hashtable;

import aterm.*;

import toolbus.*;
import toolbus.ToolBusException;
import toolbus.atom.*;
import toolbus.process.*;

public class Parser {

  private static ATermFactory factory = TBTerm.factory;

  public Parser() {
    factory = TBTerm.factory;
    initParser();
  }

  private Hashtable Funs = new Hashtable();

  private static final int AckEvent = 0;
  private static final int Assign = AckEvent + 1;
  private static final int Create = Assign + 1;
  private static final int Delta = Create + 1;
  private static final int Do = Delta + 1;
  private static final int Eval = Do + 1;
  private static final int Event = Eval + 1;
  private static final int Print = Event + 1;
  private static final int RecMsg = Print + 1;
  private static final int RecVal = RecMsg + 1;
  private static final int ShutDown = RecVal + 1;
  private static final int SndMsg = ShutDown + 1;
  private static final int Tau = SndMsg + 1;

  private static final int Alternative = Tau + 1;
  private static final int Disrupt = Alternative + 1;
  private static final int IfElse = Disrupt + 1;
  private static final int IfThen = IfElse + 1;
  private static final int Iteration = IfThen + 1;
  private static final int LetDefinition = Iteration + 1;
  private static final int Merge = LetDefinition + 1;
  private static final int ProcessCall = Merge + 1;
  private static final int Sequence = ProcessCall + 1;
  private static final int ProcessDefinition0 = Sequence + 1;
  private static final int ProcessDefinition = ProcessDefinition0 + 1;

  private static final int apply = ProcessDefinition + 1; // below args are not evaluated

  private static final int vardecl = apply + 1;
  private static final int resvardecl = vardecl + 1;
  private static final int var = resvardecl + 1;
  private static final int resvar = var + 1;

  private static final int natcon = resvar + 1;
  private static final int realcon = natcon + 1;
  private static final int posint = realcon + 1;
  private static final int negint = posint + 1;
  private static final int id = negint + 1;

  private boolean shouldBuildArgs(int op) {
    return op < apply;
  }

  private void initParser() {
    Funs.put("AckEvent", new Integer(AckEvent));
    Funs.put("Assign", new Integer(Assign));
    Funs.put("Create", new Integer(Create));
    Funs.put("Delta", new Integer(Delta));
    Funs.put("Do", new Integer(Do));
    Funs.put("Eval", new Integer(Eval));
    Funs.put("Event", new Integer(Event));
    Funs.put("Print", new Integer(Print));
    Funs.put("RecMsg", new Integer(RecMsg));
    Funs.put("RecVal", new Integer(RecVal));
    Funs.put("ShutDown", new Integer(ShutDown));
    Funs.put("SndMsg", new Integer(SndMsg));
    Funs.put("Tau", new Integer(Tau));

    Funs.put("Alternative", new Integer(Alternative));
    Funs.put("Disrupt", new Integer(Disrupt));
    Funs.put("IfElse", new Integer(IfElse));
    Funs.put("IfThen", new Integer(IfThen));
    Funs.put("Iteration", new Integer(Iteration));
    Funs.put("LetDefinition", new Integer(LetDefinition));
    Funs.put("Merge", new Integer(Merge));
    Funs.put("ProcessCall", new Integer(ProcessCall));
    Funs.put("Sequence", new Integer(Sequence));
    Funs.put("ProcessDefinition0", new Integer(ProcessDefinition0));
    Funs.put("ProcessDefinition", new Integer(ProcessDefinition));

    Funs.put("apply", new Integer(apply));
    Funs.put("vardecl", new Integer(vardecl));
    Funs.put("resvardecl", new Integer(resvardecl));
    Funs.put("var", new Integer(var));
    Funs.put("resvar", new Integer(resvar));
    Funs.put("natcon", new Integer(natcon));
    Funs.put("realcon", new Integer(realcon));
    Funs.put("posint", new Integer(posint));
    Funs.put("negint", new Integer(negint));
    Funs.put("id", new Integer(id));
  }
  
  private ATerm unquote(ATerm type){
    AFun afun = factory.makeAFun(((ATermAppl) type).getName(), 0, false);
    return factory.makeAppl(afun);
  }
  
  private ATerm mkSomeVar(String V, ATerm name, ATerm type) {
    AFun afun = factory.makeAFun(V, 3, false);
    ATerm cargs[] = new ATerm[] { factory.makeInt(-1), unquote(type), name };
    return factory.makeAppl(afun, cargs);
  }

  private ATerm mkVar(ATerm name, ATerm type) {
    return mkSomeVar("var", name, type);
  }

  private ATerm mkResVar(ATerm name, ATerm type) {
    return mkSomeVar("rvar", name, type);
  }

  public Object build(ATerm t) throws ToolBusException {

    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.LIST :
        ATermList lst = t.getFactory().makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          Object obj = build(((ATermList) t).elementAt(i));
          if (!(obj instanceof ATerm)) {
            throw new ToolBusException("non-ATerm occurs in ATermList: " + obj);
          }
          lst = lst.append((ATerm) obj);
        }
        return lst;

      case ATerm.APPL :
        return buildAppl((ATermAppl) t);
      default :
        throw new ToolBusException("illegal ATerm");
    }
  }

  public Object buildAppl(ATermAppl t) throws ToolBusException {

    //System.out.println(t);
    String name = t.getName();
    ATerm args[] = t.getArgumentArray();
    Object obj = Funs.get(name);

    if (obj == null) {
      if (args.length == 0)
        return t;
      else
        throw new ToolBusException("Unkown: " + name);
    }

    int index = ((Integer) obj).intValue();
    Object[] oargs = new Object[args.length];

    if (shouldBuildArgs(index)) {
      for (int i = 0; i < args.length; i++) {
        oargs[i] = build(args[i]);
        System.out.println("oargs[" + i + "] = " + oargs[i]);
      }
    }

    switch (index) {

      case vardecl : // vardecl(name, type) => var(-1,type,name)
        return mkVar(args[0], args[1]);

      case resvardecl : // resvardecl(name, type) => rvar(-1,type,name)
        return mkResVar(args[0], args[1]);

      case var : // var(name) => var(-1, -1, name)
        return mkVar(args[0], factory.make("none"));

      case resvar : // resvar(name) => rvar(-1, -1, name)
        return mkResVar(args[0], factory.make("none"));

      case apply : // apply(name, arglist)
        if (args.length != 2) {
          throw new ToolBusException("apply: wrong number of args");
        }

        String fname = ((ATermAppl) args[0]).getName();
        ATermList fargs = (ATermList) args[1];

        AFun afun = factory.makeAFun(fname, fargs.getLength(), false);
        ATermList realargs = factory.makeList();

        for (int i = 0; i < fargs.getLength(); i++) {
          realargs = realargs.append((ATerm) build(fargs.elementAt(i)));
        }

        System.out.println("fname = " + fname + "; fargs = " + fargs + " ; realargs = " + realargs);
        return factory.makeAppl(afun, realargs);

      case natcon : // natcon(str)
        return factory.makeInt(Integer.parseInt(((ATermAppl) args[0]).getName()));

      case realcon : // realcon(str, str)
        return null;

      case posint : // posint(str)
        return null;

      case negint : //negint(str)
        return null;

      case id :
        return args[0];

      case Alternative :
        return new Alternative((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);

      case Disrupt :
        return new Disrupt((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);

      case IfElse :
        return new IfElse((ATerm) oargs[0], (ProcessExpression) oargs[1], (ProcessExpression) oargs[2]);

      case IfThen :
        return new IfThen((ATerm) oargs[0], (ProcessExpression) oargs[1]);

      case Iteration :
        return new Iteration((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);

      case LetDefinition :
        return new LetDefinition((ATermList) oargs[0], (ProcessExpression) oargs[1]);

      case Merge :
        return new Merge((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);

      case ProcessCall :
        return new ProcessCall(((ATerm) oargs[0]));

      case ProcessDefinition0 :
        return new ProcessDefinition(
          ((ATermAppl) oargs[0]).getName(),
          factory.makeList(),
          (ProcessExpression) oargs[1]);

      case ProcessDefinition :
        return new ProcessDefinition(
          ((ATermAppl) oargs[0]).getName(),
          (ATermList) oargs[1],
          (ProcessExpression) oargs[2]);

      case Sequence :
        return new Sequence((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);

      case AckEvent :
        return new AckEvent((ATerm) oargs[0]);

      case Assign :
        return new Assign(mkVar((ATerm) oargs[0], factory.make("none")), (ATerm) oargs[1]);

      case Create :
        return new Create((ATerm) oargs[0], (ATerm) oargs[1]);

      case Delta :
        return new Delta();

      case Do :
        return new Do((ATerm) oargs[0]);

        //  case Eval :
        //       return new Eval((ATerm) oargs[0], (ATerm) oargs[1]);
      case Event :
        return new Event((ATerm) oargs[0]);

      case Print :
        return new Print((ATerm) oargs[0]);

      case RecMsg :
        return new RecMsg((ATerm) oargs[0]);

      case RecVal :
        return new RecVal((ATerm) oargs[0]);

      case ShutDown :
        return new ShutDown((ATerm) oargs[0]);
      case SndMsg :

        return new SndMsg((ATerm) oargs[0]);

      case Tau :
        return new Tau();

      default :
        throw new ToolBusException("illegal symbol " + name);
    }
  }

  public void parse(ToolBus toolbus, String filename) throws ToolBusException {
    ATerm interm;
    try {
      interm = factory.readFromFile(filename);
    } catch (IOException e) {
      throw new ToolBusException(e.getMessage());
    }

    if (interm.getType() != ATerm.APPL || ((ATermAppl) interm).getName() != "Tscript" || interm.getChildCount() != 2) {
      throw new ToolBusException("ill-formed tree");
    }

    ATerm args[] = ((ATermAppl) interm).getArgumentArray();

    ATermList decls = (ATermList) args[0];

    for (int i = 0; i < decls.getLength(); i++) {
      ProcessDefinition def = (ProcessDefinition) build(decls.elementAt(i));
      System.out.println(def);
      toolbus.addProcessDefinition(def);
    }
    ATermList calls = (ATermList) interm.getChildAt(1);

    for (int i = 0; i < calls.getLength(); i++) {
      ProcessCall call = (ProcessCall) build(calls.elementAt(i));
      System.out.println(call);
      toolbus.addProcess(call);
    }

  }
}
