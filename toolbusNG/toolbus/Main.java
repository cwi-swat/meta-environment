/**
 * @author paulk
 */

package toolbus;
import aterm.*;
import aterm.pure.*;

import toolbus.atom.*;
import toolbus.process.*;
import toolbus.tool.*;

public class Main {
	private static PureFactory aterms = new PureFactory();

	public static void main(String[] args) {
		TBTerm.init(aterms);
		
		//atomTest();
		//PETest();
		//LetTest();
		//CallTest();
		//IfTest(); 
		//CreateTest();
		//NestedIterTest();
		//SieveTest();
		//producerTest();
		ToolTest();
	}
	
	static void atomTest(){
		Atom d = new Delta();
		Atom t = new Tau();
		AtomSet set = new AtomSet();
		
		set.add(d);
		set.add(t);
		set.add(d);
		System.out.println(set);
	}
	
	static void PETest(){
		ATermList al = aterms.makeList(aterms.make("a"));
		ATermList bl = aterms.makeList(aterms.make("b"));
		ATermList cl = aterms.makeList(aterms.make("c"));
		//ATermList dl = aterms.makeList(aterms.make("d"));
		ATermList el = aterms.makeList(aterms.make("e"));

		try {
			ToolBus T =
				new ToolBus(
					new ProcessExpression[] {
						new Iteration(
							new Alternative(new Print(al), new Print(bl)),
							new Print(cl)),
							
						new SndMsg((ATermList) aterms.make("[z]")),
						
						new LetDefinition((ATermList) aterms.make("[var(-1,int,Z)]"),
							new Sequence(
								new Print(el), 
						    	new RecMsg((ATermList) aterms.make("[rvar(-1,int,Z)]")),
						        new Print((ATermList) aterms.make("[var(-1,int,Z)]"))
						        ))           
						});
			T.execute();
		}
		catch (ToolBusException e) {
			System.out.println(e.getMessage());
		}
	}

	static void LetTest(){
		try {
			ToolBus T = new ToolBus(new ProcessExpression[] {
				new LetDefinition((ATermList) aterms.make("[var(-1,int,x), var(-1,int,y)]"),
				                  new Sequence(
				                  	new Assign(aterms.make("var(-1,qqq,x)"), aterms.make("1")),
				                  	new Assign(aterms.make("var(-1,qqq,y)"), aterms.make("add(var(-1,qqq,x),2)")),
				                    new Print((ATermList) aterms.make("[\"Value of y: \", var(-1,qqq,y)]"))
				                  )
				)       
			});
			T.execute();
		}
		catch (ToolBusException e) {
			System.out.println(e.getMessage());
		}
	}
	
	

	static void CallTest(){

		ATerm int3 = aterms.make("3");
		//ATerm int7 = aterms.make("7");
		ATerm int8 = aterms.make("8");
		ATerm int11 = aterms.make("11");
		ATerm int12 = aterms.make("12");	
		ATerm int21 = aterms.make("21");
		ATerm varx = aterms.make("var(-1,int,x)");
		ATerm vary = aterms.make("var(-1,int,y)");
		//ATerm varxx = aterms.make("var(-1,int,xx)");
		//ATerm varyy = aterms.make("var(-1,int,yy)");
	
		ProcessDefinition PD1 = 
			new ProcessDefinition("P1", (ATermList) aterms.make("[var(-1,int,x), rvar(-1,int,y)]"),
				new Sequence(new Print((ATermList) aterms.make("[\"P1: \", var(-1,int,x), \" \", var(-1,int,y)]")),
							 new Assign(vary, int11),
				 			 new ProcessCall("P2", (ATermList) aterms.make("[var(-1,int,x), var(-1,int,y)]")),
							 new Assign(vary, int12)
							 ));
		ProcessDefinition PD2 = 
			new ProcessDefinition("P2", (ATermList) aterms.make("[var(-1,int,x), var(-1,int,y)]"),
				new Sequence(new Print((ATermList) aterms.make("[\"P2: \", var(-1,int,x), \" \", var(-1,int,y)]")),
							 new Assign(vary, int21)
							 ));
							 																										
		ProcessExpression P =
			new LetDefinition((ATermList) aterms.make("[var(-1,int,x), var(-1,int,y)]"),
			 					new Sequence(new Assign(varx, int3),
			 								 new Assign(vary, int8),
				                             new Print((ATermList) aterms.make("[\"P: \", var(-1,int,x), \" \", var(-1,int,y)]")),
				                             new ProcessCall("P1", (ATermList) aterms.make("[var(-1,int,x), 2]")),
				                             new ProcessCall("P1", (ATermList) aterms.make("[var(-1,int,x), var(-1,int,y)]")),
				                             new Print((ATermList) aterms.make("[\"P: \", var(-1,int,x), \"  \", var(-1,int,y)]"))
				                             ));
			
		try {
			ToolBus T = new ToolBus();
			T.addProcessDefinition(PD1);
			T.addProcessDefinition(PD2);
			T.addProcess(P);
			T.execute();
		}
		catch (ToolBusException e) { System.out.println(e.getMessage()); }
	}

	static void IfTest(){

		//ATerm atrue = aterms.make("true");
		//ATerm afalse= aterms.make("false");
		//ATerm int0 = aterms.make("0");
		ATerm int5 = aterms.make("5");
		ATerm varx = aterms.make("var(-1,int,x)");
		
		try {
		     ToolBus T = new ToolBus(new ProcessExpression[] {
		     	
		     	new LetDefinition((ATermList) aterms.make("[var(-1,int,x)]"),
		     		new Sequence(
		     			new Assign(varx, int5),
		     			new Iteration(
		     				new IfElse(aterms.make("greater(var(-1,int,x),0)"),
		     					new Sequence(
		     						new Print((ATermList) aterms.make("[var(-1,int,x)]")),
		     						new Assign(varx, aterms.make("sub(var(-1,int,x),1)"))
		     						),
		     					new Print((ATermList) aterms.make("[false]"))
		     				),
		     				new IfElse(aterms.make("equal(var(-1,int,x),0)"),
		     						new Print((ATermList) aterms.make("[done]")),
		     						new Delta()
		     				)
		     		)	)) 
		     	});
		     
			T.execute();
		}
		catch (ToolBusException e) { System.out.println(e.getMessage()); }
		}

	static void CreateTest(){

		ProcessDefinition P1 = 
			new ProcessDefinition("P1", (ATermList) aterms.make("[var(-1,int,x)]"),
				new Sequence(new Print((ATermList) aterms.make("[\"P1: \", var(-1,int,x)]")),
							 new Print((ATermList) aterms.make("[step-in-P1]"))
							 )
							 );
							 
		try {
		ToolBus T = new ToolBus(new ProcessExpression[] {
				new LetDefinition((ATermList) aterms.make("[var(-1,int,pid)]"),
				 	new Sequence(
					 new Print((ATermList) aterms.make("[before]")),
					 new Create(aterms.make("P1(5)"), aterms.make("rvar(-1,int,pid)")),
					 new Print((ATermList) aterms.make("[after, \" \", var(-1,int,pid)]"))
					)
					)
			});
			
			T.addProcessDefinition(P1);
			T.execute();
		}
		catch (ToolBusException e) { System.out.println(e.getMessage()); }
	}
	
	static void NestedIterTest(){
		ATerm varP = aterms.make("var(-1,int,P)");
		ATerm varQ = aterms.make("var(-1,int,Q)");
		
		ProcessDefinition P =
		new ProcessDefinition("P", (ATermList) aterms.make("[]"),
			new LetDefinition((ATermList) aterms.make("[var(-1,int,P), var(-1,int,Q)]"),
				new Sequence(
					new Assign(varP, aterms.make("2")),
					new Iteration(
						new Sequence(
							new Assign(varP, aterms.make("add(var(-1,int,P),1)")),
							new Print((ATermList) aterms.make("[var(-1,int,P)]")),
							new IfElse(aterms.make("equal(mod(<term>,3), 0)", varP),
								new Print((ATermList) aterms.make("[drievoud]")),
								// else
								new Sequence(
									new Assign(varQ, aterms.make("10")),
									new Iteration(
										new Sequence(
											new Assign(varQ, aterms.make("add(var(-1,int,Q),1)")),
											new IfThen(aterms.make("less(<term>,13)", varQ),
												new Print((ATermList) aterms.make("[var(-1,int,Q)]"))
											) // if
										), //seq
										new Delta()
									) // iter
								) // seq
							), // if
							new Tau()
						), // seq
						new Delta()
					) // iter
				) // seq
			) // let
		); //procdef
		
    /*
		ProcessDefinition  Q = 
		new ProcessDefinition("Q", (ATermList) aterms.make("[]"),
			new Iteration(
				new Iteration(
					new Print((ATermList) aterms.make("[a]")),
					new Print((ATermList) aterms.make("[b]"))
				),
				new Print((ATermList) aterms.make("[c]"))
			)
		);
    */
		
		try { 
			ToolBus T = new ToolBus();
			T.addProcessDefinition(P);
			//T.addProcessDefinition(Q);
			T.addProcess(new ProcessCall("P", (ATermList) aterms.make("[]")));
			
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
			T.addProcess(new ProcessCall("SIEVE", (ATermList) aterms.make("[11]")));
			//T.addProcess(new ProcessCall("FILTER", (ATermList) aterms.make("[2]")));
			
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
						new ShutDown(),
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
	new ProcessDefinition("CONSUMER", (ATermList) aterms.make("[]"),
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
	new ProcessDefinition("TRAFO", (ATermList) aterms.make("[]"),
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
		
		T.addProcess(new ProcessCall("CONSUMER", (ATermList) aterms.make("[]")));
		T.addProcess(new ProcessCall("PRODUCER", (ATermList) aterms.make("[100, 999]")));
		T.addProcess(new ProcessCall("PRODUCER", (ATermList) aterms.make("[1000, 1999]")));
		T.addProcess(new ProcessCall("PRODUCER", (ATermList) aterms.make("[2000, 2999]")));
		T.addProcess(new ProcessCall("TRAFO", (ATermList) aterms.make("[]")));
		T.addProcess(new ProcessCall("TRAFO", (ATermList) aterms.make("[]")));
		T.addProcess(new ProcessCall("TRAFO", (ATermList) aterms.make("[]")));
		
		T.execute();
	} catch (ToolBusException e) { System.out.println(e.getMessage()); }
	}
	
	
	static void ToolTest(){
		
		ToolDefinition Tool1 = new ToolDefinition("t1", "toolbus.tool.Example");
		ProcessDefinition P1 =
			new ProcessDefinition("P1", (ATermList) aterms.make("[]"),
				new LetDefinition((ATermList) aterms.make("[var(-1,t1,tool), var(-1,int,R)]"),
					new Sequence(
						new Execute(aterms.make("t1"), aterms.make("rvar(-1,qqq,tool)")),
						new SndEval(aterms.make("var(-1,qqq,tool)"), aterms.make("aap(3)")),
						new RecVal(aterms.make("var(-1,qqq,tool)"), aterms.make("rvar(-1,qqq,R)")),
						new Print((ATermList) aterms.make("[var(-1,qqq,R)]")),
						new Sequence(
							new SndEval(aterms.make("var(-1,qqq,tool)"), aterms.make("aap(444)")),
							new RecVal(aterms.make("var(-1,qqq,tool)"), aterms.make("rvar(-1,qqq,R)")),
							new Print((ATermList) aterms.make("[var(-1,qqq,R)]"))
						)
					)
				)
			);
			
		ATerm varN = aterms.make("var(-1,int,N)");
			
		ProcessDefinition P2 =
			new ProcessDefinition("P2", (ATermList) aterms.make("[]"),
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
							new ShutDown()
						)
					)
				)
			)
		);	
		
		try {
			ToolBus T = new ToolBus();
			T.addTooldefinition(Tool1);
			T.addProcessDefinition(P1);
			T.addProcessDefinition(P2);
			
			T.addProcess(new ProcessCall("P1", (ATermList) aterms.make("[]")));
			T.addProcess(new ProcessCall("P2", (ATermList) aterms.make("[]")));
			T.execute();
		}
		catch (Exception e) {System.out.println(e.getMessage()); }
	}
	
}
