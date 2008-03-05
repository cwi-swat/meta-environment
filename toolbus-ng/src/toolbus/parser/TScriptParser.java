package toolbus.parser;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.atom.Assign;
import toolbus.atom.Atom;
import toolbus.atom.Create;
import toolbus.atom.Delta;
import toolbus.atom.Print;
import toolbus.atom.ShutDown;
import toolbus.atom.Tau;
import toolbus.atom.msg.RecMsg;
import toolbus.atom.msg.SndMsg;
import toolbus.atom.note.NoNote;
import toolbus.atom.note.RecNote;
import toolbus.atom.note.SndNote;
import toolbus.atom.note.Subscribe;
import toolbus.atom.note.UnSubscribe;
import toolbus.atom.tool.AckEvent;
import toolbus.atom.tool.Connect;
import toolbus.atom.tool.DisConnect;
import toolbus.atom.tool.Do;
import toolbus.atom.tool.Eval;
import toolbus.atom.tool.Event;
import toolbus.atom.tool.Execute;
import toolbus.atom.tool.GetPerfStats;
import toolbus.atom.tool.RecPerfStats;
import toolbus.atom.tool.RecVal;
import toolbus.atom.tool.SndKill;
import toolbus.atom.tool.Terminate;
import toolbus.exceptions.ToolBusError;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.process.Alternative;
import toolbus.process.Disrupt;
import toolbus.process.IfElse;
import toolbus.process.IfThen;
import toolbus.process.Iteration;
import toolbus.process.LetDefinition;
import toolbus.process.Merge;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessDefinition;
import toolbus.process.ProcessExpression;
import toolbus.process.RightBiasedAlternative;
import toolbus.process.Sequence;
import toolbus.tool.ToolDefinition;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

/**
 * NodeBuilder: auxiliary class to represent the build function for a particular node type.
 */
abstract class NodeBuilder{
	private final String name;
	
	/**
	 * Method NodeBuilder.
	 * 
	 * @param name
	 *            the name of the cons attribute in the SDF definition
	 */
	public NodeBuilder(String name){
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	
	/**
	 * Method build. Overridden for each build function for a particular node type.
	 * 
	 * @param posInfo
	 *            TODO
	 * @param args
	 *            The already built arguments of this build function
	 * @return Object: the resulting node.
	 * @throws ToolBusException
	 */
	abstract public Object build(Object args[], ATerm posInfo) throws ToolBusException;
}

/**
 * Class TScriptNodeBuilders: define the build functions for Tscripts.
 */
class TScriptNodeBuilders{
	private final Map<String, NodeBuilder> builders;
	private final ToolBus toolbus;
	private final TBTermFactory tbfactory;
	protected String processName = "";
	
	public TScriptNodeBuilders(ToolBus tb){
		toolbus = tb;
		tbfactory = toolbus.getTBTermFactory();
		
		builders = new HashMap<String, NodeBuilder>();
		defineBuilders();
	}
	
	/**
	 * Method define: Define one build function.
	 * 
	 * @param b
	 *            description of the build function
	 */
	private void define(NodeBuilder b){
		builders.put(b.getName(), b);
	}
	
	/**
	 * Method defineBuilders. TODO: variable names in Tscripts that coincide with the names below
	 * cause havoc, e.g., the Tscript variable Delta
	 */
	protected void defineBuilders(){
		/*
		 * Variables and constants
		 */
		
		define(new NodeBuilder("ttt-vardecl"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.mkVar((ATerm) args[0], processName, (ATerm) args[1]);
			}
		});
		
		define(new NodeBuilder("ttt-resvardecl"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.mkResVar((ATerm) args[0], processName, (ATerm) args[1]);
			}
		});
		
		define(new NodeBuilder("ttt-var"){
			public Object build(Object args[], ATerm posInfo){
				String replacement = toolbus.getProperty(args[0].toString());
				if(replacement != null){
					LoggerFactory.log("unknown", "Replace (in " + processName + "): " + args[0] + " => " + replacement, IToolBusLoggerConstants.PARSING);
					return tbfactory.make(replacement);
				}
				return tbfactory.mkVar((ATerm) args[0], processName, tbfactory.make("none"));
			}
		});
		
		define(new NodeBuilder("ttt-resvar"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.mkResVar((ATerm) args[0], processName, tbfactory.make("none"));
			}
		});
		
		define(new NodeBuilder("ttt-placeholder"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.makePlaceholder((ATerm) args[0]);
			}
		});
		
		define(new NodeBuilder("ttt-apply"){
			public Object build(Object args[], ATerm posInfo) throws ToolBusException{
				int length = args.length;
				if(length == 0 || length > 2){
					for(int i = 0; i < length; i++){
						LoggerFactory.log("unknown", "ttt-apply: arg[" + i + "]:" + args[i], IToolBusLoggerConstants.PARSING);
					}
					throw new ToolBusException("ttt-apply: wrong number of args");
				}
				
				ATermList argList = (length == 2) ? (ATermList) args[1] : tbfactory.EmptyList;
				AFun afun = tbfactory.makeAFun(((ATermAppl) args[0]).getName(), argList.getLength(), false);
				
				ATerm vargs[] = new ATerm[argList.getLength()];
				for(int i = 0; i < vargs.length; i++){
					vargs[i] = argList.elementAt(i);
				}
				return tbfactory.makeAppl(afun, vargs);
			}
		});
		
		define(new NodeBuilder("ttt-natcon"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.makeInt(Integer.parseInt(((ATermAppl) args[0]).getName()));
			}
		});
		
		define(new NodeBuilder("ttt-realcon"){
			public Object build(Object args[], ATerm posInfo){
				String sreal = args[0].toString() + "." + args[1].toString();
				return tbfactory.makeReal(new Double(sreal).doubleValue());
			}
		});
		
		define(new NodeBuilder("ttt-strcon"){
			public Object build(Object args[], ATerm posInfo){
				return args[0];
			}
		});
		
		define(new NodeBuilder("ttt-undefined"){
			public Object build(Object args[], ATerm posInfo){
				return tbfactory.Undefined;
			}
		});
		
		/*
		 * Process constants
		 */
		
		define(new NodeBuilder("ttt-Delta"){
			public Object build(Object args[], ATerm posInfo){
				return new Delta(tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Tau"){
			public Object build(Object args[], ATerm posInfo){
				return new Tau(tbfactory, null);
			}
		});
		
		/*
		 * Process operators
		 */
		
		define(new NodeBuilder("ttt-Sequence"){
			public Object build(Object args[], ATerm posInfo){
				return new Sequence((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Alternative"){
			public Object build(Object args[], ATerm posInfo){
				return new Alternative((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-RightBiasedAlternative"){
			public Object build(Object args[], ATerm posInfo){
				return new RightBiasedAlternative((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Iteration"){
			public Object build(Object args[], ATerm posInfo){
				/*
				 * Here is a quick fix to solve the problem of nested ifs and iterations: the test
				 * of the if is attached to the second argument of the iteration BUT the first
				 * execution of the first argument may have changed the environment in such a way
				 * that the test can never become true! Temporary solution: prefix the iteration
				 * with an extra tau (so the test is always executed in an unmodified environment).
				 */
				return new Sequence(new Tau(tbfactory, null), new Iteration((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null), tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Disrupt"){
			public Object build(Object args[], ATerm posInfo){
				return new Disrupt((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Merge"){
			public Object build(Object args[], ATerm posInfo){
				return new Merge((ProcessExpression) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-IfElse"){
			public Object build(Object args[], ATerm posInfo){
				return new IfElse((ATerm) args[0], (ProcessExpression) args[1], (ProcessExpression) args[2], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-IfThen"){
			public Object build(Object args[], ATerm posInfo){
				return new IfThen((ATerm) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-LetDefinition"){
			public Object build(Object args[], ATerm posInfo){
				return new LetDefinition((ATermList) args[0], (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		/*
		 * Process definition and creation
		 */
		
		define(new NodeBuilder("ttt-ProcessCall"){
			public Object build(Object args[], ATerm posInfo){
				return new ProcessCall(((ATerm) args[0]), tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-ProcessDefinition0"){
			public Object build(Object args[], ATerm posInfo){
				return new ProcessDefinition(((ATermAppl) args[0]).getName(), tbfactory.EmptyList, (ProcessExpression) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-ProcessDefinition"){
			public Object build(Object args[], ATerm posInfo){
				return new ProcessDefinition(((ATermAppl) args[0]).getName(), (ATermList) args[1], (ProcessExpression) args[2], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Create"){
			public Object build(Object args[], ATerm posInfo){
				return new Create((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		/*
		 * Messages
		 */
		
		define(new NodeBuilder("ttt-RecMsg"){
			public Object build(Object args[], ATerm posInfo){
				if(args.length == 1){
					return new RecMsg((ATerm) args[0], tbfactory, null);
				}
				System.err.println("ttt-RecMsg: too many arguments");
				return null;
				// return new RecMsg((ATerm) args[0], (ATerm) args[1],
				// tbfactory);
			}
		});
		
		define(new NodeBuilder("ttt-SndMsg"){
			public Object build(Object args[], ATerm posInfo){
				if(args.length == 1){
					return new SndMsg((ATerm) args[0], tbfactory, null);
				}
				System.err.println("ttt-SndMsg: too many arguments");
				return null;
				// return new SndMsg((ATerm) args[0], (ATerm) args[1],
				// tbfactory);
			}
		});
		
		/*
		 * Notes
		 */
		
		define(new NodeBuilder("ttt-Subscribe"){
			public Object build(Object args[], ATerm posInfo){
				return new Subscribe((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-UnSubscribe"){
			public Object build(Object args[], ATerm posInfo){
				return new UnSubscribe((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-SndNote"){
			public Object build(Object args[], ATerm posInfo){
				return new SndNote((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-RecNote"){
			public Object build(Object args[], ATerm posInfo){
				return new RecNote((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-NoNote"){
			public Object build(Object args[], ATerm posInfo){
				return new NoNote((ATerm) args[0], tbfactory, null);
			}
		});
		
		/*
		 * Tool related atoms
		 */
		
		define(new NodeBuilder("ttt-host"){
			public Object build(Object args[], ATerm posInfo){
				return args[0];
			}
		});
		
		define(new NodeBuilder("ttt-kind"){
			public Object build(Object args[], ATerm posInfo){
				return args[0];
			}
		});
		
		define(new NodeBuilder("ttt-command"){
			public Object build(Object args[], ATerm posInfo){
				return args[0];
			}
		});
		
		define(new NodeBuilder("ttt-class"){
			public Object build(Object args[], ATerm posInfo){
				return args[0];
			}
		});
		
		define(new NodeBuilder("ttt-ToolDef"){
			public Object build(Object args[], ATerm posInfo){
				
				String name = ((ATermAppl) args[0]).getName();
				
				String host = ((ATermAppl) args[1]).getName();
				host = (host == "None") ? null : ((host == "Some") ? ((ATermAppl) ((ATermAppl) args[1]).getArgument(0)).getName() : host);
				
				String kind = ((ATermAppl) args[2]).getName();
				kind = (kind == "None") ? null : ((kind == "Some") ? ((ATermAppl) ((ATermAppl) args[2]).getArgument(0)).getName() : kind);
				
				String command = ((ATermAppl) args[3]).getName();
				command = (command == "None") ? null : ((command == "Some") ? ((ATermAppl) ((ATermAppl) args[3]).getArgument(0)).getName() : command);
				
				String clazz = ((ATermAppl) args[4]).getName();
				clazz = (clazz == "None") ? null : ((clazz == "Some") ? ((ATermAppl) ((ATermAppl) args[4]).getArgument(0)).getName() : clazz);
				
				return new ToolDefinition(name, host, kind, command, clazz, tbfactory);
			}
		});
		
		define(new NodeBuilder("ttt-Execute"){
			public Object build(Object args[], ATerm posInfo){
				Execute ex = new Execute((ATerm) args[0], (ATerm) args[1], tbfactory, null);
				Connect con = new Connect((ATerm) args[1], tbfactory, null, true);
				return new Sequence(ex, con, tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-SndTerminate"){
			public Object build(Object args[], ATerm posInfo){
				return new Terminate((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-SndKill"){
			public Object build(Object args[], ATerm posInfo){
				return new SndKill((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-RecConnect"){
			public Object build(Object args[], ATerm posInfo){
				return new Connect((ATerm) args[0], tbfactory, null, false);
			}
		});
		
		define(new NodeBuilder("ttt-RecDisConnect"){
			public Object build(Object args[], ATerm posInfo){
				return new DisConnect((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Eval"){
			public Object build(Object args[], ATerm posInfo){
				return new Eval((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-RecVal"){
			public Object build(Object args[], ATerm posInfo){
				return new RecVal((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Do"){
			public Object build(Object args[], ATerm posInfo){
				return new Do((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Event"){
			public Object build(Object args[], ATerm posInfo){
				return new Event((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-AckEvent"){
			public Object build(Object args[], ATerm posInfo){
				return new AckEvent((ATerm) args[0], (ATerm) args[1], null, tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-AckEventCB"){
			public Object build(Object args[], ATerm posInfo){
				return new AckEvent((ATerm) args[0], (ATerm) args[1], (ATerm) args[2], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-GetPerfStats"){
			public Object build(Object args[], ATerm posInfo){
				return new GetPerfStats((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-RecPerfStats"){
			public Object build(Object args[], ATerm posInfo){
				return new RecPerfStats((ATerm) args[0], (ATerm) args[1], tbfactory, null);
			}
		});
		
		/*
		 * Miscellaneous atoms
		 */
		
		define(new NodeBuilder("ttt-Assign"){
			public Object build(Object args[], ATerm posInfo){
				return new Assign(tbfactory.mkVar((ATerm) args[0], processName, tbfactory.make("none")), (ATerm) args[1], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-Print"){
			public Object build(Object args[], ATerm posInfo){
				return new Print((ATerm) args[0], tbfactory, null);
			}
		});
		
		define(new NodeBuilder("ttt-ShutDown"){
			public Object build(Object args[], ATerm posInfo){
				return new ShutDown((ATerm) args[0], tbfactory, null);
			}
		});
		
		/*
		 * Time related items
		 */
		
		define(new NodeBuilder("ttt-TimeExpr"){
			public Object build(Object args[], ATerm posInfo){
				Atom a = (Atom) args[0];
				//a.addTimeExpr((ATerm) args[1]);
				// TODO implement
				return a;
			}
		});
		
		/*
		 * #include <file>
		 */
		
		define(new NodeBuilder("ttt-Include"){
			public Object build(Object args[], ATerm posInfo){
				String filename = ((ATermAppl) args[0]).getName();
				filename = filename.substring(1, filename.length() - 1); // strip < and >
				System.err.println("Building object for Include " + filename);
				return new Include(filename, posInfo);
			}
		});
	}
	
	/**
	 * Method build traverses a given ATerm that has been produced by the parser and creates a
	 * desired structure of class instances. The ATerm is traversed in a bottom-up fashion: - ATerms
	 * are just rebuilt, only string quotes are stripped where relevant - When an application has a
	 * function name that is defined as node builder, that node builder is applied to its arguments.
	 * Since node builders can return arbitrary classes we have to be carefull with appropriate
	 * casting between ATerm and Object.
	 * 
	 * @param t
	 *            input tree as produced by the parser
	 * @return Object: the resulting tree of class instances
	 * @throws ToolBusException
	 */
	public Object build(ATerm t) throws ToolBusException{
		ATerm posInfo = t.getAnnotation(tbfactory.make("pos-info"));
		switch(t.getType()){
			case ATerm.APPL:
				// System.err.println("build: " + t);
				ATermAppl ap = (ATermAppl) t;
				String name = ap.getName();
				ATerm args[] = ap.getArgumentArray();
				NodeBuilder nd = builders.get(name);
				int argslength = args.length;
				if(nd == null){
					if(argslength == 0){
						boolean isquoted = false;
						if(name.length() > 0 && name.charAt(0) == '"'){
							name = name.substring(1, name.length() - 1);
							isquoted = true;
						}
						AFun afun = tbfactory.makeAFun(name, 0, isquoted);
						return tbfactory.makeAppl(afun);
					}
					AFun afun = tbfactory.makeAFun(name, argslength, false);
					ATerm vargs[] = new ATerm[argslength];
					for(int i = 0; i < argslength; i++){
						vargs[i] = (ATerm) build(args[i]);
					}
					return tbfactory.makeAppl(afun, vargs);
				}
				Object[] oargs = new Object[argslength];
				
				for(int i = 0; i < argslength; i++)
					oargs[i] = build(args[i]);
				
				return nd.build(oargs, posInfo);
				
			case ATerm.LIST:
				ATermList lst1 = (ATermList) t;
				ATermList lst2 = tbfactory.EmptyList;
				for(int i = lst1.getLength() - 1; i >= 0; i--){
					lst2 = tbfactory.makeList((ATerm) build(lst1.elementAt(i)), lst2);
				}
				return lst2;
				
			default:
				return t;
		}
	}
}

public class TScriptParser{
	private final TBTermFactory tbfactory;
	private final ExternalParser externalparser;
	private final HashSet<String> includedFiles;
	private final ToolBus toolbus;
	private final TScriptNodeBuilders tScriptNodeBuilders;
	private final List<ATerm> calls;
	
	public TScriptParser(ExternalParser ep, ToolBus tb){
		externalparser = ep;
		toolbus = tb;
		tbfactory = toolbus.getTBTermFactory();
		includedFiles = new HashSet<String>();
		tScriptNodeBuilders = new TScriptNodeBuilders(toolbus);
		calls = new ArrayList<ATerm>();
	}
	
	public void parse(String filename) throws ToolBusException{
		includedFiles.clear();
		calls.clear();
		
		doParse(filename);
		// System.err.println("doParse done");
		generateInitialProcessCalls();
	}
	
	private void doParse(String filename) throws ToolBusException{
		ATerm interm;
		if(includedFiles.contains(filename)){
			System.err.println("Skipping include of " + filename);
			return;
		}
		
		includedFiles.add(filename);
		try{
			System.err.println("Parse: " + filename);
			interm = externalparser.parse(filename, tbfactory);
		}catch(IOException e){
			throw new ToolBusException(e.getMessage());
		}
		
		if(interm.getType() != ATerm.APPL || ((ATermAppl) interm).getName() != "ttt-Tscript"){
			throw new ToolBusException("ill-formed tree");
		}
		
		ATerm args[] = ((ATermAppl) interm).getArgumentArray();
		
		handleDeclarations(filename, (ATermList) args[0]);
	}
	
	private void handleDeclarations(String filename, ATermList decls) throws ToolBusException{
		for(int i = 0; i < decls.getLength(); i++){
			Object decl = decls.elementAt(i);
			if(decl instanceof ATermList){
				ATermList toolbusArgs = (ATermList) decl;
				for(int j = 0; j < toolbusArgs.getLength(); j++){
					calls.add(toolbusArgs.elementAt(j));
				}
			}else{
				try{
					if(((ATermAppl) decl).getName() == "ttt-Ifndef"){
						handleIfndef(filename, (ATermAppl) decl);
					}else if(((ATermAppl) decl).getName() == "ttt-Ifdef"){
						handleIfdef(filename, (ATermAppl) decl);
					}else if(((ATermAppl) decl).getName() == "ttt-Define0"){
						handleDefine(filename, (ATermAppl) decl, 0);
					}else if(((ATermAppl) decl).getName() == "ttt-Define1"){
						handleDefine(filename, (ATermAppl) decl, 1);
					}else if(((ATermAppl) decl).getName() == "ttt-Include"){
						handleInclude(filename, (ATermAppl) decl);
					}else{
						Object def = tScriptNodeBuilders.build((ATerm) decl);
						// System.err.println(filename + "; def = " +
						// def.getClass().getCanonicalName());
						
						if(def instanceof ProcessDefinition){
							String processName = ((ProcessDefinition) def).getName();
							tScriptNodeBuilders.processName = processName;
							// System.err.println("Declare: " + processName);
							// We have already parsed def as a ProcessDefinition
							// and extracted its process name,
							// next we parse it again! so that we qualify all
							// variables with that name.
							// TODO: replace by a simple scan that replaces the
							// variables.
							toolbus.addProcessDefinition((ProcessDefinition) tScriptNodeBuilders.build((ATerm) decl));
						}else if(def instanceof ToolDefinition){
							toolbus.addToolDefinition((ToolDefinition) def);
						}else if(def instanceof Include){
							doParseInclude(((Include) def).getFilename());
						}else toolbus.error(filename, "Process or Tool definition expected");
					}
				}catch(ToolBusError e){
					toolbus.error(filename, e.getMessage());
				}
			}
		}
	}
	
	private String stripQuotes(ATerm v){
		String vname = v.toString();
		return vname.substring(1, vname.length() - 1);
	}
	
	private String getConstant(String name){
		return toolbus.getProperty(name, null);
	}
	
	private void setConstant(String name, String val){
		toolbus.setProperty(name, val);
	}
	
	private void handleDefine(String filename, ATermAppl decl, int nargs) throws ToolBusException{
		String var = stripQuotes(decl.getArgument(0).removeAnnotations());
		ATerm val;
		if(nargs == 1){
			val = (ATerm) tScriptNodeBuilders.build(decl.getArgument(1).removeAnnotations());
		}else{
			val = tbfactory.make("\"\"");
		}
		
		setConstant(var, val.toString());
		LoggerFactory.log("unknown", "Define: " + var + " = " + val, IToolBusLoggerConstants.PARSING);
	}
	
	private void handleIfdef(String filename, ATermAppl decl) throws ToolBusException{
		String var = stripQuotes(decl.getArgument(0));
		ATermList decls = (ATermList) decl.getArgument(1);
		if(getConstant(var) != null){
			handleDeclarations(filename, decls);
		}else{
			LoggerFactory.log("unknown", "Skipping declarations after ifdef", IToolBusLoggerConstants.PARSING);
		}
	}
	
	private void handleIfndef(String filename, ATermAppl decl) throws ToolBusException{
		String var = stripQuotes(decl.getArgument(0));
		ATermList decls = (ATermList) decl.getArgument(1);
		if(getConstant(var) == null){
			handleDeclarations(filename, decls);
		}else{
			LoggerFactory.log("unknown", "Skipping declarations after ifndef", IToolBusLoggerConstants.PARSING);
		}
	}
	
	private void handleInclude(String Filename, ATermAppl decl) throws ToolBusException{
		String incFilename = stripQuotes(decl.getArgument(0).removeAnnotations());
		incFilename = incFilename.substring(1, incFilename.length() - 1); // strip < and >
		LoggerFactory.log("unknown", "Include: " + incFilename, IToolBusLoggerConstants.PARSING);
		doParseInclude(incFilename);
	}
	
	private void doParseInclude(String filename) throws ToolBusException{
		if(filename.length() > 0 && filename.charAt(0) == File.separatorChar){
			File f = new File(filename);
			if(f.exists()){
				doParse(filename);
				return;
			}
		}else{
			String path = toolbus.getProperty("include.path", ".");
			LoggerFactory.log("unknown", "doParseInclude: path = " + path, IToolBusLoggerConstants.PARSING);
			String[] elems = path.split("[ ,\t\n\r]+");
			for(int i = 0; i < elems.length; i++){
				String dir = elems[i];
				
				if(dir.length() > 0){
					String absoluteName = dir + File.separator + filename;
					File f = new File(absoluteName);
					if(f.exists()){
						doParse(absoluteName);
						return;
					}
				}
			}
		}
		throw new ToolBusException("Cannot resolve include file '" + filename + "'");
	}
	
	private void generateInitialProcessCalls() throws ToolBusException{
		if(calls.size() == 0){
			throw new ToolBusError("Initial configuration of ToolBus processes is missing");
		}
		
		String allCalls = "";
		Iterator<ATerm> callsIterator = calls.iterator();
		while(callsIterator.hasNext()){
			ATerm acall = callsIterator.next();
			
			String pname = "";
			try{
				pname = "<unknown>";
				ProcessCall call = (ProcessCall) tScriptNodeBuilders.build(acall);
				allCalls += call + "\n";
				pname = call.getName();
				toolbus.addProcess(call);
			}catch(ToolBusException e){
				toolbus.error("process " + pname, e.getMessage());
			}
		}
		LoggerFactory.log("unknown", "=======\nInitial ToolBus configuration:" + allCalls + "=======\n", IToolBusLoggerConstants.PARSING);
	}
}
