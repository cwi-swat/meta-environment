/**
 * @author paulk
 */

package toolbus;

import toolbus.atom.*;
import toolbus.process.*;

import aterm.*;

public class Main {
  private static ATermFactory aterms;

  public static void main(String[] args) {
    TBTerm.init();
    aterms = TBTerm.factory;

    //PETest();
    //CallTest();
     //CallTest2();
    //IfTest(); 
    //CreateTest();
    //NestedIterTest();
     //DisruptTest();
    //MergeTest();
    //ParseTest();
    ToolTest();
  }
 
  
  static void PETest(){
    ATermList al = aterms.makeList(aterms.make("a"));
    ATermList bl = aterms.makeList(aterms.make("b"));
    ATermList cl = aterms.makeList(aterms.make("c"));
    //ATermList dl = aterms.makeList(aterms.make("d"));
    ATermList el = aterms.makeList(aterms.make("e"));

   ProcessDefinition P1 = new ProcessDefinition("P1",
            new Iteration(
              new Alternative(new Print(al), new Print(bl)),
              new Print(cl))
             );
    System.out.println(P1);
             
    ProcessDefinition P2 = new ProcessDefinition("P2",
            new SndMsg((ATermList) aterms.make("[z]"))
    );
    
    ProcessDefinition P3 = new ProcessDefinition("P3",
            new LetDefinition((ATermList) aterms.make("[var(-1,int,Z)]"),
              new Sequence(
                new Print(el), 
                  new RecMsg((ATermList) aterms.make("[rvar(-1,int,Z)]")),
                    new Print((ATermList) aterms.make("[var(-1,int,Z)]"))
                    ))           
    );
        
    try {    
      ToolBus T = new ToolBus();
      T.addProcessDefinition(P1);
      T.addProcessDefinition(P2);
      T.addProcessDefinition(P3); 
      T.addProcess("P1");
      T.addProcess("P2");
      T.addProcess("P3");
      T.execute();
    }
    catch (ToolBusException e) {
      System.out.println(e.getMessage());
    }
  }


  static void CreateTest(){

    ProcessDefinition P1 = 
      new ProcessDefinition("P1", (ATermList) aterms.make("[var(-1,int,x)]"),
        new Sequence(new Print((ATermList) aterms.make("[\"P1: \", var(-1,int,x)]")),
               new Print((ATermList) aterms.make("[step-in-P1]"))
               )
               );
               
    ProcessDefinition P2 = new ProcessDefinition("P2",
        new LetDefinition((ATermList) aterms.make("[var(-1,int,pid)]"),
          new Sequence(
           new Print((ATermList) aterms.make("[before]")),
           new Create(aterms.make("P1(5)"), aterms.make("rvar(-1,int,pid)")),
           new Print((ATermList) aterms.make("[after, \" \", var(-1,int,pid)]"))
          )
          )
    );
    try {
      ToolBus T = new ToolBus();
      
      T.addProcessDefinition(P1);
      T.addProcessDefinition(P2);
      T.addProcess("P2");
      T.execute();
    }
    catch (ToolBusException e) { System.out.println(e.getMessage()); }
  }
  
  static void DisruptTest(){
    
    ProcessExpression Pa = new Print((ATermList) aterms.make("[a]"));
    ProcessExpression Pb = new Print((ATermList) aterms.make("[b]"));
    ProcessExpression Pc = new Print((ATermList) aterms.make("[c]"));
    ProcessExpression Pd = new Print((ATermList) aterms.make("[d]"));
    
    ProcessDefinition Pmain = new ProcessDefinition("Pmain",
      new Disrupt(
        new Sequence( Pa, Pb, Pc, Pd),
        new Alternative(new RecMsg((ATermList) aterms.make("[m1]")),
                new RecMsg((ATermList) aterms.make("[m2]"))
        )
      )
    );
    
    ProcessDefinition P1 = new ProcessDefinition("P1",
      new SndMsg((ATermList) aterms.make("[m1]"))
      );
      
     ProcessDefinition P2 = new ProcessDefinition("P2",
      new SndMsg((ATermList) aterms.make("[m2]"))
      );
    
    try {
        ToolBus T = new ToolBus();
          T.addProcessDefinition(Pmain);
          T.addProcessDefinition(P1);
          T.addProcessDefinition(P2);
 
          T.addProcess("P1");
          T.addProcess("P2");
          T.addProcess("Pmain");
          T.execute();
          
    } catch (ToolBusException e) { System.out.println(e.getMessage()); }
  }
  
  static void MergeTest()
  {
    
    ProcessExpression Pa = new Print((ATermList) aterms.make("[a]"));
    ProcessExpression Pb = new Print((ATermList) aterms.make("[b]"));
    ProcessExpression Pc = new Print((ATermList) aterms.make("[c]"));
    ProcessExpression Pd = new Print((ATermList) aterms.make("[d]"));
    ProcessExpression Pe = new Print((ATermList) aterms.make("[e]"));
    ProcessExpression Pf = new Print((ATermList) aterms.make("[f]"));
 
    ProcessDefinition MERGE =
      new ProcessDefinition("MERGE",
        new Merge(
          new Sequence(Pa,Pb, Pc),
          new Sequence(Pd,Pe, Pf)
        )
      );
        
    try { 
      ToolBus T = new ToolBus();
      T.addProcessDefinition(MERGE);
      T.addProcess("MERGE");
      T.execute();
    } catch (ToolBusException e) { System.out.println(e.getMessage()); }      
  }

  static void SieveTest(){

    ATerm int2 = aterms.make("2");
    ATerm int3 = aterms.make("3");
    
    ATerm FidRes = aterms.make("rvar(-1,int,Fid)");
    ATerm varN = aterms.make("var(-1,int,N)");
    ATerm varMax= aterms.make("var(-1,int,Max)");
  
    ProcessDefinition SIEVE =
    new ProcessDefinition("SIEVE", (ATermList) aterms.make("[var(-1,int,Max)]"),
      new LetDefinition((ATermList) aterms.make("[var(-1,int,N), var(-1,int,Fid)]"),
        new Sequence(
          new Create(aterms.make("FILTER(2)"), FidRes),
          new Assign(varN, int3),
          new Iteration(
            new IfThen(aterms.make("less(<term>,<term>)", varN, varMax),
              new Sequence(
                  new SndMsg((ATermList) aterms.make("[<term>,<term>]", int2, varN)),
                  //new Print((ATermList) aterms.make("[<term>]", varN)),
                  new Assign(varN, aterms.make("add(<term>, 1)", varN))
              )
            ), // if
            new Delta()
          ) // iter
        ) //seq
      ) //let
    );
    
    ATerm varP = aterms.make("var(-1,int,P)");
    ATerm Zres = aterms.make("rvar(-1,int,Z)");
    ATerm varZ = aterms.make("var(-1,int,Z)");
    ATerm Nres = aterms.make("rvar(-1,int,N)");
    
    
    ProcessDefinition FILTER =
    new ProcessDefinition("FILTER", (ATermList) aterms.make("[var(-1,int,P)]"),
      new LetDefinition((ATermList) aterms.make("[var(-1,int,Z), var(-1,int,N), var(-1,int,Fid)]"),
        new Sequence(
          new Print((ATermList) aterms.make("[var(-1,int,P)]")),
          new Iteration(
            new Sequence(
              new RecMsg((ATermList) aterms.make("[<term>,<term>]", varP, Zres)),
              //new Print((ATermList) aterms.make("[var(-1,int,P), receives, var(-1,int,Z)]")),
              new IfElse(aterms.make("equal(mod(<term>,<term>), 0)", varZ, varP),
                //new Tau(),
                new Print((ATermList) aterms.make("[var(-1,int,P), \" kills \", var(-1,int,Z)]")),
                new Sequence(
                  new Create(aterms.make("FILTER(var(-1,int,Z))"), FidRes),
                  new Iteration(
                    new Sequence(
                      new RecMsg((ATermList) aterms.make("[<term>,<term>]", varP, Nres)),
                      //new Print((ATermList) aterms.make("[var(-1,int,P), receives, var(-1,int,N)]")),
                      new IfElse(aterms.make("equal(mod(<term>,<term>), 0)", varN, varP),
                        new Tau(),
                        new SndMsg((ATermList) aterms.make("[<term>,<term>]", varZ, varN))
                      ) // if
                    ), //seq
                    new Delta()
                  ) // iter
                ) // seq
              ) // if
            ), // seq
              
            new Delta()
          ) // iter
        ) // seq
      ) // let
    ); //procdef
  
  
    try {
      ToolBus T = new ToolBus();
      
      T.addProcessDefinition(SIEVE);
      T.addProcessDefinition(FILTER);
      T.addProcess("SIEVE", (ATermList) aterms.make("[11]"));
      //T.addProcess("FILTER", (ATermList) aterms.make("[2]"));
      
      T.execute();
    } catch (ToolBusException e) { System.out.println(e.getMessage()); }
  }

// ------

static void producerTest(){
  //ATerm int0 = aterms.make("0");
  //ATerm int2 = aterms.make("2");
  //ATerm int3 = aterms.make("3");
  
  
  ATerm varN = aterms.make("var(-1,int,N)");
  ATerm varMax= aterms.make("var(-1,int,Max)");
  ATerm varStart = aterms.make("var(-1,int,Start)");

  ProcessDefinition PRODUCER =
  new ProcessDefinition("PRODUCER", (ATermList) aterms.make("[var(-1,int,Start), var(-1,int,Max)]"),
    new LetDefinition((ATermList) aterms.make("[var(-1,int,N)]"),
      new Sequence(
        new Assign(varN, varStart),
        new Iteration(
          new IfElse(aterms.make("less(<term>,<term>)", varN, varMax),
            new Sequence(
                new SndMsg((ATermList) aterms.make("[p(<term>)])", varN)),
                //new Print((ATermList) aterms.make("[<term>]", varN)),
                new Assign(varN, aterms.make("add(<term>, 1)", varN))
            ),
            new Delta()
          ),
          new IfElse(aterms.make("equal(<term>,<term>)", varN, varMax),
            new ShutDown(aterms.make("the-end")),
            new Delta()
          )
        )
      )
    )
  );
  //ATerm varP = aterms.make("var(-1,int,P)");
  ATerm Zres = aterms.make("rvar(-1,int,Z)");
  ATerm varZ = aterms.make("var(-1,int,Z)");
  //ATerm Nres = aterms.make("rvar(-1,int,N)");
  
  
  ProcessDefinition CONSUMER =
  new ProcessDefinition("CONSUMER",
    new LetDefinition((ATermList) aterms.make("[var(-1,int,Z)]"),
        new Iteration(
          new Sequence(
            new RecMsg((ATermList) aterms.make("[q(<term>)]", Zres)),
            new IfElse(aterms.make("equal(mod(<term>,2), 0)", varZ),
              //new Print((ATermList) aterms.make("[var(-1,int,Z)]")),
              new Tau(),
              new Tau()
            )
          ), // seq
          new Delta()
        ) // iter
    ) // let
  ); //procdef
  
  ProcessDefinition TRAFO =
  new ProcessDefinition("TRAFO",
    new LetDefinition((ATermList) aterms.make("[var(-1,int,Z)]"),
        new Iteration(
          new Sequence(
            new RecMsg((ATermList) aterms.make("[p(<term>)]", Zres)),
            new SndMsg((ATermList) aterms.make("[q(<term>)]", varZ))
          ), // seq
          new Delta()
        ) // iter
    ) // let
  ); //procdef
  
  try {
    ToolBus T = new ToolBus();
    T.addProcessDefinition(PRODUCER);
    T.addProcessDefinition(CONSUMER);
    T.addProcessDefinition(TRAFO);
    
    T.addProcess("CONSUMER");
    T.addProcess("PRODUCER", (ATermList) aterms.make("[100, 999]"));
    T.addProcess("PRODUCER", (ATermList) aterms.make("[1000, 1999]"));
    T.addProcess("PRODUCER", (ATermList) aterms.make("[2000, 2999]"));
    T.addProcess("TRAFO");
    T.addProcess("TRAFO");
    T.addProcess("TRAFO");
    
    T.execute();
  } catch (ToolBusException e) { System.out.println(e.getMessage()); }
  }
  
  static void ParseTest(){
    ToolBus T = new ToolBus();

    try {
      //T.setVerbose(true);
      T.parse("toolbus/test/sieve.tb");
      T.execute();
      
    } catch (ToolBusException e) { System.out.println(e.getMessage()); e.printStackTrace();}
    
  }
  
  
  static void ToolTest(){
    
    ProcessDefinition P1 =
      new ProcessDefinition("P1", (ATermList) aterms.make("[]"),
        new LetDefinition((ATermList) aterms.make("[var(-1,int,R), var(-1,str,Name)]"),
          new Sequence(
            new Eval(aterms.make("msg(\"hello\")")),
            new RecVal(aterms.make("count(rvar(-1,qqq,R))")),
            new Print((ATermList) aterms.make("[var(-1,qqq,R)]")),
            new Sequence(
              new Event(aterms.make("button(rvar(-1,qqq,Name))")),
              new Print((ATermList) aterms.make("[var(-1,qqq,Name)]")),
              new AckEvent(aterms.make("button(var(-1,qqq,Name))"))
            ) //seq
          ) //seq
        ) //let
      );
      
    ATerm varN = aterms.make("var(-1,int,N)");
      
    ProcessDefinition P2 =
      new ProcessDefinition("P2",
        new LetDefinition((ATermList) aterms.make("[var(-1,int, N)]"),
          new Sequence(
            new Assign(aterms.make("var(-1,int, N)"), aterms.make("0")),
            new Iteration(
              new IfThen(aterms.make("less(<term>,15)", varN),
                new Sequence(
                  new Print((ATermList) aterms.make("[<term>]", varN)),
                  new Assign(varN, aterms.make("add(<term>, 1)", varN))
              )
            ),
            new IfThen(aterms.make("equal(<term>,15)", varN),
              new ShutDown(aterms.make("end-of-ToolTest"))
            )
          )
        )
      )
    );  
    
    try {
      ToolBus T = new ToolBus();
      T.addProcessDefinition(P1);
      T.addProcessDefinition(P2);
      
      T.addProcess(new ProcessCall("P1", aterms.makeList()), "toolbus.tool.Example");
      T.addProcess("P2");
      T.setVerbose(true);
      T.execute();
    }
    catch (Exception e) {System.out.println(e.getMessage());  e.printStackTrace(); }
  }
  
}
