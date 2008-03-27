package toolbus;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.pure.PureFactory;

public class JavaTif{
	private ATermList tifs = null;
	
	private final ATermFactory factory;
	
	private final Map<String, SpecOrderVector> doEvents;
	private final Map<String, SpecOrderVector> evalEvents;
	private final Map<String, SpecOrderVector> otherEvents;
	
	private boolean found_one = false;
	
	private final String package_name;
	private final String tool_interface;
	private final String tool_class;
	private final String tool_bridge;
	private final boolean swingTool;
	
	static void usage(){
		System.err.println("usage: tifstojava" + " -tool <tool> -tifs <tifs> " + "[-class <class>] [-package <package>] [-swing]");
		System.exit(0);
	}
	
	public static void main(String[] args) throws IOException{
		String tool = null, tifsfile = null;
		String package_name = null, tool_interface = null, tool_class = null;
		String tool_bridge = null;
		boolean swingTool = false;
		
		for(int i = 0; i < args.length; i++){
			if(args[i].equals("-h")){
				usage();
			}else if(args[i].equals("-tool")){
				tool = args[++i];
			}else if(args[i].equals("-tifs")){
				tifsfile = args[++i];
			}else if(args[i].equals("-package")){
				package_name = args[++i];
			}else if(args[i].equals("-tool-interface")){
				tool_interface = args[++i];
			}else if(args[i].equals("-tool-class")){
				tool_class = args[++i];
			}else if(args[i].equals("-tool-bridge")){
				tool_bridge = args[++i];
			}else if(args[i].equals("-swing")){
				swingTool = true;
			}
		}
		
		if(tool == null || tifsfile == null){
			usage();
		}else{
			String tool_name = JavaTif.capitalize(tool, true);
			if(tool_interface == null){
				tool_interface = tool_name + "Tif";
			}
			if(tool_class == null){
				tool_class = tool_name + "Tool";
			}
			if(tool_bridge == null){
				tool_bridge = tool_name + "Bridge";
			}
			
			JavaTif gen = new JavaTif(package_name, tool_interface, tool_class, tool_bridge, swingTool);
			gen.readTifs(tifsfile, tool);
			if(!gen.found_one){
				System.err.println("warning: no tifs found for tool " + tool);
			}
			gen.genTif();
			gen.genTool();
			gen.genBridge();
		}
	}
	
	public JavaTif(String pkg_name, String tool_interface, String tool_class, String tool_bridge, boolean swingTool){
		doEvents = new HashMap<String, SpecOrderVector>();
		evalEvents = new HashMap<String, SpecOrderVector>();
		otherEvents = new HashMap<String, SpecOrderVector>();
		factory = new PureFactory();
		
		this.package_name = pkg_name;
		this.tool_interface = tool_interface;
		this.tool_class = tool_class;
		this.tool_bridge = tool_bridge;
		this.swingTool = swingTool;
	}
	
	static public String capitalize(String str, boolean fc){
		boolean firstCap = fc;
		StringBuffer name = new StringBuffer();
		for(int i = 0; i < str.length(); i++){
			if(str.charAt(i) == '-')
				firstCap = true;
			else{
				if(firstCap){
					name.append(Character.toUpperCase(str.charAt(i)));
					firstCap = false;
				}else name.append(str.charAt(i));
			}
		}
		return name.toString();
	}
	
	public void readTifs(String tifsfile, String tool) throws IOException{
		ATermList empty = factory.makeList();
		ATermList allSignatures = (ATermList) factory.readFromFile(tifsfile);
		while(allSignatures != empty){
			ATermAppl toolSignature = (ATermAppl) allSignatures.getFirst();
			
			if(((ATermAppl) toolSignature.getArgument(0)).getAFun().getName().equals(tool)){
				tifs = (ATermList) toolSignature.getArgument(1);
				return;
			}
			
			allSignatures = allSignatures.getNext();
		}
		throw new RuntimeException("No tifs found for tool: "+tool);
	}
	
	public void genTif() throws IOException{
		File path;
		if(package_name != null){
			path = new File(package_name.replaceAll("[.]", File.separator));
			path.mkdirs();
		}else{
			path = new File(".");
		}
		String filename = path + File.separator + tool_interface + ".java";
		
		System.out.println("generating file " + filename);
		PrintWriter out = new PrintWriter(new FileOutputStream(filename));
		genTifHeader(out);
		genMethods(out, false);
		out.println("}");
		out.close();
	}
	
	private void genTifHeader(PrintWriter out){
		out.println("// Java tool interface " + tool_interface);
		out.println("// This file is generated automatically, please do not edit!");
		out.print("// generation time: ");
		out.println(DateFormat.getDateTimeInstance().format(new Date()));
		
		out.println();
		if(package_name != null){
			out.println("package " + package_name + ";");
		}
		out.println();
		out.println("import aterm.*;");
		// out.println("import toolbus.*;");
		out.println();
		out.println("public interface " + tool_interface);
		out.println("{");
	}
	
	public void genTool() throws IOException{
		File path;
		if(package_name != null){
			path = new File(package_name.replaceAll("[.]", File.separator));
			path.mkdirs();
		}else{
			path = new File(".");
		}
		String filename = path + File.separator + tool_class + ".java";
		
		System.out.println("generating file " + filename);
		
		PrintWriter out = new PrintWriter(new FileOutputStream(filename));
		genHeader(out);
		
		genSigTable(out);
		genPatternAttribs(out);
		out.println();
		
		genConstructor(out);
		out.println();
		
		genInitSigTable(out);
		out.println();
		genInitPatterns(out);
		out.println();
		
		genHandler(out);
		out.println();
		genCheckInputSignature(out);
		out.println();
		genNotInInputSignature(out);
		out.println("}");
		out.close();
	}
	
	private void genSigTable(PrintWriter out){
		out.println("  // This table will hold the complete input signature");
		out.println("  private Set<ATerm> sigTable = new HashSet<ATerm>();");
		out.println();
	}
	
	private void genHeader(PrintWriter out){
		out.println("// Java tool interface class " + tool_class);
		out.println("// This file is generated automatically, please do not edit!");
		out.print("// generation time: ");
		out.println(DateFormat.getDateTimeInstance().format(new Date()));
		
		out.println();
		if(package_name != null){
			out.println("package " + package_name + ";");
		}
		out.println();
		out.println("import java.util.HashSet;");
		out.println("import java.util.List;");
		out.println("import java.util.Set;");
		out.println();
		if(swingTool){
			out.println("import toolbus.SwingTool;");
		}else{
			out.println("import toolbus.AbstractTool;");
		}
		out.println();
		out.println("import aterm.ATerm;");
		out.println("import aterm.ATermAppl;");
		out.println("import aterm.ATermFactory;");
		out.println("import aterm.ATermList;");
		out.println();
		out.println("abstract public class " + tool_class);
		if(swingTool){
			out.println("  extends SwingTool");
		}else{
			out.println("  extends AbstractTool");
		}
		out.println("  implements " + tool_interface);
		out.println("{");
	}
	
	private void genPatternAttribs(PrintWriter out){
		out.println("  // Patterns that are used to match against incoming terms");
		
		Set<String> eventKeys = doEvents.keySet();
		Iterator<String> eventKeysIterator = eventKeys.iterator();
		while(eventKeysIterator.hasNext()){
			String key = eventKeysIterator.next();
			SpecOrderVector v = doEvents.get(key);
			v.genPatternAttribs(out, capitalize(key, false));
		}
		
		Set<String> evalKeys = evalEvents.keySet();
		Iterator<String> evalKeysIterator = evalKeys.iterator();
		while(evalKeysIterator.hasNext()){
			String key = evalKeysIterator.next();
			SpecOrderVector v = evalEvents.get(key);
			v.genPatternAttribs(out, capitalize(key, false));
		}
		
		Set<String> otherEventsKeys = otherEvents.keySet();
		Iterator<String> otherEventsKeysIterator = otherEventsKeys.iterator();
		while(otherEventsKeysIterator.hasNext()){
			String key = otherEventsKeysIterator.next();
			SpecOrderVector v = otherEvents.get(key);
			v.genPatternAttribs(out, capitalize(key, false));
		}
	}
	
	private void genConstructor(PrintWriter out){
		String decl = "protected " + tool_class + "(ATermFactory factory)";
		out.println("  // Mimic the constructor from the AbstractTool class");
		out.println("  " + decl);
		out.println("  {");
		out.println("    super(factory);");
		out.println("    initSigTable();");
		out.println("    initPatterns();");
		out.println("  }");
	}
	
	private void genInitSigTable(PrintWriter out){
		String decl = "private void initSigTable()";
		out.println("  // This method initializes the table with input signatures");
		out.println("  " + decl);
		out.println("  {");
		ATermList sigs = tifs;
		while(!sigs.isEmpty()){
			ATerm sig = sigs.getFirst();
			sigs = sigs.getNext();
			out.print("    sigTable.add(factory.parse(\"");
			out.print(sig.toString());
			out.println("\"));");
		}
		out.println("  }");
	}
	
	private void genInitPatterns(PrintWriter out){
		String decl = "private void initPatterns()";
		out.println("  // Initialize the patterns that are used to match against incoming terms");
		out.println("  " + decl);
		out.println("  {");
		
		Set<String> eventKeys = doEvents.keySet();
		Iterator<String> eventKeysIterator = eventKeys.iterator();
		while(eventKeysIterator.hasNext()){
			String key = eventKeysIterator.next();
			SpecOrderVector v = doEvents.get(key);
			v.genPatterns(out, capitalize(key, false), "rec-do");
		}
		
		Set<String> evalKeys = evalEvents.keySet();
		Iterator<String> evalKeysIterator = evalKeys.iterator();
		while(evalKeysIterator.hasNext()){
			String key = evalKeysIterator.next();
			SpecOrderVector v = evalEvents.get(key);
			v.genPatterns(out, capitalize(key, false), "rec-eval");
		}
		
		Set<String> otherEventsKeys = otherEvents.keySet();
		Iterator<String> otherEventsKeysIterator = otherEventsKeys.iterator();
		while(otherEventsKeysIterator.hasNext()){
			String key = otherEventsKeysIterator.next();
			SpecOrderVector v = otherEvents.get(key);
			v.genPatterns(out, capitalize(key, false), null);
		}
		
		out.println("  }");
	}
	
	private void genHandler(PrintWriter out){
		String decl = "public ATerm handler(ATerm term)";
		out.println("  // The generic handler calls the specific handlers");
		out.println("  " + decl);
		out.println("  {");
		out.println("    List<?> result;");
		out.println();
		
		Set<String> eventKeys = doEvents.keySet();
		Iterator<String> eventKeysIterator = eventKeys.iterator();
		while(eventKeysIterator.hasNext()){
			String key = eventKeysIterator.next();
			SpecOrderVector v = doEvents.get(key);
			v.genCalls(out, capitalize(key, false), false);
		}
		
		Set<String> evalKeys = evalEvents.keySet();
		Iterator<String> evalKeysIterator = evalKeys.iterator();
		while(evalKeysIterator.hasNext()){
			String key = evalKeysIterator.next();
			SpecOrderVector v = evalEvents.get(key);
			v.genCalls(out, capitalize(key, false), true);
		}
		
		Set<String> otherEventsKeys = otherEvents.keySet();
		Iterator<String> otherEventsKeysIterator = otherEventsKeys.iterator();
		while(otherEventsKeysIterator.hasNext()){
			String key = otherEventsKeysIterator.next();
			SpecOrderVector v = otherEvents.get(key);
			v.genCalls(out, capitalize(key, false), false);
		}
		
		out.println();
		out.println("    notInInputSignature(term);");
		out.println("    return null;");
		out.println("  }");
	}
	
	private void genMethods(PrintWriter out, boolean gen_impl){
		Set<String> eventKeys = doEvents.keySet();
		Iterator<String> eventKeysIterator = eventKeys.iterator();
		while(eventKeysIterator.hasNext()){
			String key = eventKeysIterator.next();
			SpecOrderVector v = doEvents.get(key);
			v.genMethods(out, capitalize(key, false), false, gen_impl);
		}
		
		Set<String> evalKeys = evalEvents.keySet();
		Iterator<String> evalKeysIterator = evalKeys.iterator();
		while(evalKeysIterator.hasNext()){
			String key = evalKeysIterator.next();
			SpecOrderVector v = evalEvents.get(key);
			v.genMethods(out, capitalize(key, false), true, gen_impl);
		}
		
		Set<String> otherEventsKeys = otherEvents.keySet();
		Iterator<String> otherEventsKeysIterator = otherEventsKeys.iterator();
		while(otherEventsKeysIterator.hasNext()){
			String key = otherEventsKeysIterator.next();
			SpecOrderVector v = otherEvents.get(key);
			v.genMethods(out, capitalize(key, false), false, gen_impl);
		}
	}
	
	private void genCheckInputSignature(PrintWriter out){
		String decl = "public void checkInputSignature(ATermList sigs)";
		out.println("  // Check the input signature");
		out.println("  " + decl);
		out.println("  {");
		out.println("    while(!sigs.isEmpty()) {");
		out.println("      ATermAppl sig = (ATermAppl)sigs.getFirst();");
		out.println("      sigs = sigs.getNext();");
		out.println("      if (!sigTable.contains(sig)) {");
		out.println("        // Sorry, but the term is not in the input signature!");
		out.println("        notInInputSignature(sig);");
		out.println("      }");
		out.println("    }");
		out.println("  }");
	}
	
	private void genNotInInputSignature(PrintWriter out){
		String decl = "void notInInputSignature(ATerm t)";
		out.println("  // This function is called when an input term");
		out.println("  // was not in the input signature.");
		out.println("  " + decl);
		out.println("  {");
		out.println("    throw new RuntimeException(" + "\"term not in input signature: \" + t);");
		out.println("  }");
	}
	
	private void genBridge() throws IOException{
		File path;
		if(package_name != null){
			path = new File(package_name.replaceAll("[.]", File.separator));
			path.mkdirs();
		}else{
			path = new File(".");
		}
		String filename = path + File.separator + tool_bridge + ".java";
		
		System.out.println("generating file " + filename);
		PrintWriter out = new PrintWriter(new FileOutputStream(filename));
		genBridgeHeader(out);
		
		out.println("  private " + tool_interface + " tool;");
		out.println();
		String decl = "public " + tool_bridge + "(ATermFactory factory, " + tool_interface + " tool)";
		out.println("  " + decl);
		out.println("  {");
		out.println("    super(factory);");
		out.println("    this.tool = tool;");
		out.println("  }");
		out.println();
		
		genMethods(out, true);
		out.println("}");
		out.close();
	}
	
	private void genBridgeHeader(PrintWriter out){
		out.println("// Java tool bridge " + tool_bridge);
		out.println("// This file is generated automatically, please do not edit!");
		out.print("// generation time: ");
		out.println(DateFormat.getDateTimeInstance().format(new Date()));
		
		out.println();
		if(package_name != null){
			out.println("package " + package_name + ";");
		}
		out.println();
		out.println("import aterm.*;");
		// out.println("import toolbus.*;");
		out.println();
		out.println("public class " + tool_bridge);
		out.println("  extends " + tool_class);
		out.println("{");
	}
}

class SpecOrderVector extends ArrayList<ATermAppl>{
	private static final long serialVersionUID = -864376275786608076L;

	public void insert(ATermAppl appl){
		for(int i = 0; i < size(); i++){
			if(moreSpecific(appl, get(i))){
				add(i, appl);
				return;
			}
		}
		add(appl);
	}
	
	private boolean moreSpecific(ATerm a, ATerm b){
		if(a == b) return true;
		if(a.equals(b)) return true;
		if(a.getType() > b.getType()) return true;
		if(a.getType() < b.getType()) return false;
		switch(a.getType()){
			case ATerm.APPL:
				ATermAppl appl1 = (ATermAppl) a;
				ATermAppl appl2 = (ATermAppl) b;
				if(appl1.getName().equals(appl2.getName())) return moreSpecific(appl1.getArguments(), appl2.getArguments());
				if(moreSpecific(appl1.getName(), appl2.getName())) return true;
				return false;
			case ATerm.PLACEHOLDER:
				ATermPlaceholder p1 = (ATermPlaceholder) a;
				ATermPlaceholder p2 = (ATermPlaceholder) b;
				return moreSpecific(p1.getPlaceholder(), p2.getPlaceholder());
			case ATerm.LIST:
				ATermList terms1 = (ATermList) a;
				ATermList terms2 = (ATermList) b;
				if(terms1.isEmpty()) return true;
				if(terms2.isEmpty()) return false;
				if(terms1.getFirst().equals(terms2.getFirst())) return moreSpecific(terms1.getNext(), terms2.getNext());
				return moreSpecific(terms1.getFirst(), terms2.getFirst());
		}
		return false; // compiler!
	}
	
	private boolean moreSpecific(String a, String b){
		int i;
		for(i = 0; i < a.length(); i++){
			if(i > b.length()) return true;
			if(a.charAt(i) < b.charAt(i)) return true;
		}
		return false;
	}
	
	public void print(PrintWriter out){
		for(int i = 0; i < size(); i++){
			out.println(get(i).toString());
		}
	}
	
	public void genPatterns(PrintWriter out, String base, String func){
		for(int i = 0; i < size(); i++){
			out.print("    P" + base + i + " = factory.parse(\"");
			if(func != null){
				out.print(func + "(");
			}
			out.print(get(i).toString());
			if(func != null){
				out.print(")");
			}
			out.println("\");");
		}
	}
	
	public void genPatternAttribs(PrintWriter out, String base){
		for(int i = 0; i < size(); i++)
			out.println("  private ATerm P" + base + i + ";");
	}
	
	public void genCalls(PrintWriter out, String base, boolean ret){
		for(int i = 0; i < size(); i++){
			ATermAppl appl = get(i);
			out.println("    result = term.match(P" + base + i + ");");
			out.println("    if (result != null) {");
			if(ret){
				out.print("      return " + base + "(");
			}else{
				out.print("      " + base + "(");
			}
			
			genArgs(out, appl.getArguments());
			out.println(");");
			if(!ret){
				out.println("      return null;");
			}
			out.println("    }");
		}
	}
	
	private static void genArgs(PrintWriter out, ATermList args){
		ATermList arguments = args;
		int idx = 0;
		
		while(!arguments.isEmpty()){
			ATermPlaceholder ph = (ATermPlaceholder) arguments.getFirst();
			String fun = ((ATermAppl) ph.getPlaceholder()).getName();
			arguments = arguments.getNext();
			if(fun.equals("int"))
				out.print("((Integer)result.get(" + idx + ")).intValue()");
			else if(fun.equals("real"))
				out.print("((Double)result.get(" + idx + ")).doubleValue()");
			else if(fun.equals("term"))
				out.print("(ATerm)result.get(" + idx + ")");
			else if(fun.equals("appl"))
				out.print("(ATermAppl)result.get(" + idx + ")");
			else if(fun.equals("list"))
				out.print("(ATermList)result.get(" + idx + ")");
			else if(fun.equals("str"))
				out.print("(String)result.get(" + idx + ")");
			else out.print("(ATermAppl)result.get(" + idx + ")");
			if(!arguments.isEmpty()) out.print(", ");
			idx++;
		}
	}
	
	public void genMethods(PrintWriter out, String base, boolean ret, boolean gen_impl){
		for(int i = 0; i < size(); i++){
			ATermAppl appl = get(i);
			
			String decl;
			
			if(ret){
				decl = "public ATerm " + base + "(";
			}else{
				decl = "public void " + base + "(";
			}
			
			decl += buildFormals(appl.getArguments());
			decl += ")";
			
			out.print("  " + decl);
			
			if(gen_impl){
				out.println();
				out.println("  {");
				out.println("    if (tool != null) {");
				out.print("      " + (ret ? "return " : "") + "tool." + base + "(");
				genActuals(out, appl.getArguments());
				out.println(");");
				out.println("    }");
				if(!ret){
					out.println("    else {");
				}
				out.print("      throw new UnsupportedOperationException(");
				out.println("\"method `" + base + "' not supported.\");");
				if(!ret){
					out.println("    }");
				}
				out.println("  }");
			}else{
				out.println(";");
			}
		}
	}
	
	private static String buildFormals(ATermList args){
		ATermList arguments = args;
		int idx = 0;
		StringBuffer result = new StringBuffer();
		
		while(!arguments.isEmpty()){
			ATermPlaceholder ph = (ATermPlaceholder) arguments.getFirst();
			String fun = ((ATermAppl) ph.getPlaceholder()).getName();
			arguments = arguments.getNext();
			if(fun.equals("int")){
				result.append("int i" + idx);
			}else if(fun.equals("real")){
				result.append("double d" + idx);
			}else if(fun.equals("term")){
				result.append("ATerm t" + idx);
			}else if(fun.equals("appl")){
				result.append("ATermAppl a" + idx);
			}else if(fun.equals("list")){
				result.append("ATermList l" + idx);
			}else if(fun.equals("str")){
				result.append("String s" + idx);
			}else{
				result.append("ATermAppl a" + idx);
			}
			
			if(!arguments.isEmpty()){
				result.append(", ");
			}
			idx++;
		}
		
		return result.toString();
	}
	
	private static void genActuals(PrintWriter out, ATermList args){
		ATermList arguments = args;
		int idx = 0;
		
		while(!arguments.isEmpty()){
			ATermPlaceholder ph = (ATermPlaceholder) arguments.getFirst();
			String fun = ((ATermAppl) ph.getPlaceholder()).getName();
			arguments = arguments.getNext();
			if(fun.equals("int")){
				out.print("i" + idx);
			}else if(fun.equals("real")){
				out.print("d" + idx);
			}else if(fun.equals("term")){
				out.print("t" + idx);
			}else if(fun.equals("appl")){
				out.print("a" + idx);
			}else if(fun.equals("list")){
				out.print("l" + idx);
			}else if(fun.equals("str")){
				out.print("s" + idx);
			}else{
				out.print("a" + idx);
			}
			
			if(!arguments.isEmpty()){
				out.print(", ");
			}
			idx++;
		}
	}
}
