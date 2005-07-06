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

    //DisruptTest();
    //MergeTest();
    ParseTest();
    //ToolTest();
    
  }

  static void DisruptTest(){
    
    ProcessExpression Pa = new Print(aterms.make("[a]"));
    ProcessExpression Pb = new Print(aterms.make("[b]"));
    ProcessExpression Pc = new Print(aterms.make("[c]"));
    ProcessExpression Pd = new Print(aterms.make("[d]"));
    
    ProcessDefinition Pmain = new ProcessDefinition("Pmain",
      new Disrupt(
        new Sequence( Pa, Pb, Pc, Pd),
        new Alternative(new RecMsg(aterms.make("[m1]")),
                new RecMsg(aterms.make("[m2]"))
        )
      )
    );
    
    ProcessDefinition P1 = new ProcessDefinition("P1",
      new SndMsg(aterms.make("[m1]"))
      );
      
     ProcessDefinition P2 = new ProcessDefinition("P2",
      new SndMsg(aterms.make("[m2]"))
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
    
    ProcessExpression Pa = new Print(aterms.make("[a]"));
    ProcessExpression Pb = new Print(aterms.make("[b]"));
    ProcessExpression Pc = new Print(aterms.make("[c]"));
    ProcessExpression Pd = new Print(aterms.make("[d]"));
    ProcessExpression Pe = new Print(aterms.make("[e]"));
    ProcessExpression Pf = new Print(aterms.make("[f]"));
 
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
  
  static void ParseTest(){
    ToolBus T = new ToolBus();

    try {
      //T.setVerbose(true);
      T.parse(ToolBus.getWorkspace() + "/toolbusNG/toolbus/tool/examples/tool1.tb");
      T.execute();
      
    } catch (ToolBusException e) { System.out.println(e.getMessage()); e.printStackTrace();}
    
  }
  
  static void ToolTest(){
    try {
    ProcessDefinition P1 =
      new ProcessDefinition("P1", (ATermList) aterms.make("[]"),
        new LetDefinition((ATermList) aterms.make("[var(-1,int,R), var(-1,str,Name), var(-1, str, M)]"),
         // new Sequence(
            new MsgPair(false, true, 
                 aterms.make("msg(rvar(-1,qqq,M))"),
                 new Tau(),
                 "Sequence",
                 new SndMsg(aterms.make("count(rvar(-1,qqq,R))"))
            )
//            new Print((ATermList) aterms.make("[var(-1,qqq,R)]")),
//            new SndAndRecMsg(true, true,
//              aterms.make("button(rvar(-1,qqq,Name))")),
//              new Print((ATermList) aterms.make("[var(-1,qqq,Name)]")),
//              new AckEvent(aterms.make("button(var(-1,qqq,Name))"))
//            ) //seq
//         ) //seq
        ) //let
      );
      
    ATerm varN = aterms.make("var(-1,int,N)");
      
    ProcessDefinition P2 =
      new ProcessDefinition("P2",
        new LetDefinition((ATermList) aterms.make("[var(-1,int, N), var(-1, str, R)]"),
          new Sequence(
            new MsgPair(true, false,
             aterms.make("msg(\"hello\")"), 
             new Tau(),
             "Sequence",
             new RecMsg(aterms.make("count(rvar(-1,qqq,R))"))
             ),
             new Print(aterms.make("[var(-1,qqq,R)]")),
            new Assign(aterms.make("var(-1,int, N)"), aterms.make("0")),
            new Iteration(
              new IfThen(aterms.make("less(<term>,15)", varN),
                new Sequence(
                  new Print(aterms.make("[<term>]", varN)),
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
  
      ToolBus T = new ToolBus();
      T.addProcessDefinition(P1);
      T.addProcessDefinition(P2);
      
      T.addProcess(new ProcessCall("P1", aterms.makeList())); //, "toolbus.tool.Example");
      T.addProcess("P2");
      ToolBus.setVerbose(true);
      T.execute();
    }
    catch (Exception e) {System.out.println(e.getMessage());  e.printStackTrace(); }
  }

}
