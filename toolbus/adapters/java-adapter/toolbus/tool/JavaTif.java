
package toolbus.tool;
import java.io.*;
import java.util.*;
// jdk 1.1:
//import java.text.*;

import java.net.*;
import toolbus.aterm.*;
// jdk 1.02
import toolbus.util.Writer;
import toolbus.util.PrintWriter;
import toolbus.util.*;

public class JavaTif
{
  //{ public static void main(String[] args)

  public static void main(String[] args)
    throws IOException, ParseError
  {
    String tool = null, tifsfile = null;
    String pkg = null, javaclass = null;
    String output = null;

    for(int i=0; i<args.length; i++) {
      if(args[i].equals("-tool"))
	tool = args[++i];
      if(args[i].equals("-tifs"))
	tifsfile = args[++i];
      if(args[i].equals("-package"))
	pkg = args[++i];
      if(args[i].equals("-class"))
	javaclass = args[++i];
      if(args[i].equals("-output"))
	output = args[++i];
    }

    if(tool == null || tifsfile == null)
      System.err.println("usage: javatif -tool <tool> -tifs <tifs> " +
			 "[-class <class>][-output <file>]" +
			 "[-package <package>]");
    else {
      if(javaclass == null)
        javaclass = TifGenerator.capitalize(tool, true);
      TifGenerator gen = new TifGenerator();
      gen.readTifs(tifsfile);
      gen.selectTifs(tool);
      gen.genJavaTif(pkg, javaclass);
    }
  }

  //}
}

class TifGenerator
{
  private ATerms tifs = null;
  private World world;
  private Hashtable doEvents = null;
  private Hashtable evalEvents = null;
  private Hashtable otherEvents = null;

  //{ public TifGenerator()

  public TifGenerator()
  {
    doEvents = new Hashtable();
    evalEvents = new Hashtable();
    otherEvents = new Hashtable();
    world = ATerm.the_world;
  }

  //}

  //{ static String capitalize(String str, boolean firstCap)

  static String capitalize(String str, boolean firstCap)
  {
    StringBuffer name = new StringBuffer();
    for(int i=0; i<str.length(); i++) {
       if(str.charAt(i) == '-')
	 firstCap = true;
       else {
	 if(firstCap) {
	   name.append(Character.toUpperCase(str.charAt(i)));
	   firstCap = false;
	 } else
	   name.append(str.charAt(i));
       }
    }
    return name.toString();
  }

  //}
  //{ public void readTifs(String tifsfile)

  public void readTifs(String tifsfile)
    throws IOException, ParseError
  {
    tifs = world.empty;
    ATermAppl appl = null;

    FileInputStream s = new FileInputStream(tifsfile);
    
    do {
      if(appl != null && appl.getFun().startsWith("rec-"))
	tifs = world.makeATerms(appl, tifs);
      appl = (ATermAppl)Tool.readTerm(world, s);
    } while(!appl.getFun().equals("end-of-tifs"));
  }

  //}
  //{ public void selectTifs(String tool)

  public void selectTifs(String tool)
    throws ParseError, IOException
  {
    ATerms list = tifs;
    ATerm T = world.makePlaceholder(world.makeAppl(tool, world.empty));

    while(!list.isEmpty()) {
      ATermAppl appl = (ATermAppl)list.getFirst();
      if(!appl.getArgs().isEmpty() && appl.getFun().startsWith("rec-") &&
	 appl.getArgs().getFirst().equals(T)) {
	if(appl.getFun().equals("rec-do")) {
	  appl = (ATermAppl)appl.getArgs().getNext().getFirst();
	  appl = normalize(appl);
	  SpecOrderVector v = (SpecOrderVector)doEvents.get(appl.getFun());
	  if(v == null) {
	    v = new SpecOrderVector();
	    doEvents.put(appl.getFun(), v);
	  }
	  v.insert(appl);
        } else if(appl.getFun().equals("rec-eval")) {
	  appl = (ATermAppl)appl.getArgs().getNext().getFirst();
	  appl = normalize(appl);
	  SpecOrderVector v = (SpecOrderVector)evalEvents.get(appl.getFun());
	  if(v == null) {
	    v = new SpecOrderVector();
	    evalEvents.put(appl.getFun(), v);
	  }
	  v.insert(appl);
	} else {
	  // Dump first argument (<tool>)
	  appl = world.makeAppl(appl.getFun(), appl.getArgs().getNext());
	  appl = normalize(appl);
	  SpecOrderVector v = (SpecOrderVector)otherEvents.get(appl.getFun());
	  if(v == null) {
	    v = new SpecOrderVector();
	    otherEvents.put(appl.getFun(), v);
	  }
	  v.insert(appl);	  
	}
      }
      list = list.getNext();
    }
  }

  //}

  //{ public void genJavaTif(String pkg, String javaclass)

  public void genJavaTif(String pkg, String javaclass)
    throws IOException
  {
    PrintWriter out = new PrintWriter(new FileOutputStream(javaclass + ".java"));
    System.out.println("generating header");
    genHeader(pkg, javaclass, out);

    System.out.println("generating sig table");
    genSigTable(out);
    genPatternAttribs(out);
 
    genConstructors(out, javaclass);
    genInitPatterns(out);
    genMethods(out);
    genHandler(out);
    genCheckInputSignature(out);
    genNotInInputSignature(out);
    out.println("}\n");
    out.close();
  }

  //}
  //{ private void genSigTable(PrintWriter out)

  private void genSigTable(PrintWriter out)
  {
    out.println("  // This table will hold the complete input signature");
    out.println("  private Hashtable sigTable = new Hashtable();\n");
  }

  //}
  //{ private void genHeader(String pkg, String javaclass, PrintWriter out)

  private void genHeader(String pkg, String javaclass, PrintWriter out)
    throws IOException
  {
    out.println("// Java tool interface class " + javaclass);
    out.println("// This file is generated automatically, please do not edit!");
    out.print("// generation time: ");
    // jdk 1.1
    // out.println(DateFormat.getDateInstance().format(new Date()));

    // jdk 1.02
    out.println(new Date().toLocaleString());

    out.println("");
    if(pkg != null)
      out.println("package " + pkg + ";");
    out.println("import toolbus.aterm.*;");
    out.println("import toolbus.tool.ToolException;");
    out.println("import java.net.UnknownHostException;");
    out.println("import java.net.InetAddress;");
    out.println("import java.util.Hashtable;\n\n");
    out.println("abstract public class " + javaclass + " extends toolbus.tool.Tool");
    out.println("{");
  }

  //}
  //{ private void genPatternAttribs(PrintWriter out)

  private void genPatternAttribs(PrintWriter out)
    throws IOException
  {
    out.println("  // Declare the patterns that are used to match against incoming terms");
    Enumeration enum = doEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)doEvents.get(key);
      v.genPatternAttribs(out, capitalize(key, false));
    }

    enum = evalEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)evalEvents.get(key);
      v.genPatternAttribs(out, capitalize(key, false));
    }

    enum = otherEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)otherEvents.get(key);
      v.genPatternAttribs(out, capitalize(key, false));
    }
    out.println("");
  }

  //}
  //{ private void genConstructors(PrintWriter out)

  private void genConstructors(PrintWriter out, String javaclass)
    throws IOException
  {
    String hdr = "  protected " + javaclass;
    String trw = " throws UnknownHostException ";
    out.println("  // Mimic the three constructors from the Tool class");
    out.println(hdr + "(String name)"+trw+"{ super(name); init(); }");
    out.println(hdr + "(String name, InetAddress address, int port)"+trw+" { super(name, address, port); init(); }");
    out.println(hdr + "(String[] args)"+trw+"{ super(args); init(); }");
    out.println("");

    out.println("  // Initializations common to all constructors");
    out.println("  private void init() { initSigTable(); initPatterns(); }");
    out.println("");

    out.println("  // This method initializes the table with input signatures");
    out.println("  private void initSigTable()");
    out.println("  {");
    ATerms sigs = tifs;
    out.println("    try {");
    while(!sigs.isEmpty()) {
      ATerm sig = sigs.getFirst();
      sigs = sigs.getNext();
      out.print("      sigTable.put(world.makeSimple(\"");
      sig.print(out);
      out.println("\"), new Boolean(true));");
    }
    out.println("    } catch (ParseError e) { }");
    out.println("  }\n");
  }

  //}
  //{ private void genInitPatterns(PrintWriter out)

  private void genInitPatterns(PrintWriter out)
    throws IOException
  {
    out.println("  // Initialize the patterns that are used to match against incoming terms");
    out.println("  private void initPatterns()");
    out.println("  {");
    out.println("    try {");
    Enumeration enum = doEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)doEvents.get(key);
      v.genPatterns(out, capitalize(key, false), "rec-do");
    }

    enum = evalEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)evalEvents.get(key);
      v.genPatterns(out, capitalize(key, false), "rec-eval");
    }

    enum = otherEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)otherEvents.get(key);
      v.genPatterns(out, capitalize(key, false), null);
    }
    out.println("    } catch (ParseError e) {}");
    out.println("  }\n");
  }

  //}
  //{ private void genHandler(PrintWriter out)

  private void genHandler(PrintWriter out)
  {
    out.println("  // The generic handler calls the specific handlers");
    out.println("  protected ATerm handler(ATerm term)");
    out.println("\tthrows ToolException");
    out.print("  {\n    ");
    Enumeration enum = doEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)doEvents.get(key);
      v.genCalls(out, capitalize(key, false), false);
    }

    enum = evalEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)evalEvents.get(key);
      v.genCalls(out, capitalize(key, false), true);
    }

    enum = otherEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)otherEvents.get(key);
      v.genCalls(out, capitalize(key, false), false);
    }
    out.println("\n      notInInputSignature(term);");
    out.println("    return null;");
    out.println("  }\n");
  }

  //}
  //{ private void genMethods(PrintWriter out)

  private void genMethods(PrintWriter out)
  {
    out.println("\n  // Override these abstract methods to handle incoming ToolBus terms");
    Enumeration enum = doEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)doEvents.get(key);
      v.genMethods(out, capitalize(key, false), false);
    }

    enum = evalEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)evalEvents.get(key);
      v.genMethods(out, capitalize(key, false), true);
    }

    enum = otherEvents.keys();
    while(enum.hasMoreElements()) {
      String key = (String)enum.nextElement();
      SpecOrderVector v = (SpecOrderVector)otherEvents.get(key);
      v.genMethods(out, capitalize(key, false), false);
    }
    out.println("");
  }

  //}
  //{ private void genCheckInputSignature(PrintWriter out)

  private void genCheckInputSignature(PrintWriter out)
  {
    out.println("  // Check the input signature");
    out.println("  protected void checkInputSignature(ATermList list)");
    out.println("         throws ToolException");
    out.println("  {");
    out.println("    ATerms sigs = list.getATerms();");
    out.println("    while(!sigs.isEmpty()) {");
    out.println("      ATermAppl sig = (ATermAppl)sigs.getFirst();");
    out.println("      sigs = sigs.getNext();");
    out.println("      if(!sigTable.containsKey(sig)) {");
    out.println("        // Sorry, but the term is not in the input signature!");
    out.println("        notInInputSignature(sig);");
    out.println("      }");
    out.println("    }");
    out.println("  }\n");
  }

  //}
  //{ private void genNotInInputSignature(PrintWriter out)

  private void genNotInInputSignature(PrintWriter out)
  {
    out.println("  // This function is called when an input term");
    out.println("  // was not in the input signature.");
    out.println("  void notInInputSignature(ATerm t)");
    out.println("        throws ToolException");
    out.println("  {");
    out.println("    throw new ToolException(this, " +
		"\"term not in input signature\", t);");
    out.println("  }");
  }

  //}

  //{ private ATermAppl normalize(ATermAppl term)

  private ATermAppl normalize(ATermAppl appl)
  {
    ATerms args = appl.getArgs();
    if(!args.isEmpty()) {
      int len = args.length();
      ATerm[] newargs = new ATerm[len];
      String type = null;
    
      for(int i=0; i<len; i++) {
        ATerm arg = args.getFirst();
        args = args.getNext();
        switch(arg.getType()) {
	  case ATerm.APPL:
	    type = "appl";
	    break;
	  case ATerm.LIST:
	    type = "list";
	    break;
	  case ATerm.INT:
	    type = "int";
	    break;
	  case ATerm.REAL:
	    type = "real";
	    break;
	  case ATerm.PLACEHOLDER:
	    newargs[i] = arg;
	    break;
	}
	if(newargs[i] == null)
	  newargs[i] = world.makePlaceholder(world.makeAppl(type, world.empty));
      }
      args = world.empty;
      for(int i = len-1; i >= 0; i--)
	args = world.makeATerms(newargs[i], args);
    }
    return world.makeAppl(appl.getFun(), args);    
  }

  //}
}


class SpecOrderVector extends Vector
{
  //{ public void insert(ATermAppl appl)

public void insert(ATermAppl appl)
{
  for(int i=0; i<size(); i++) {
    if(moreSpecific(appl, (ATermAppl)elementAt(i))) {
      insertElementAt(appl, i);
      return;
    }
  }
  addElement(appl);
}

//}
  //{ private boolean moreSpecific(ATerm a, ATerm b)

private boolean moreSpecific(ATerm a, ATerm b)
{
  if(a == b)
    return true;
  if(a.equals(b))
    return true;
  if(a.getType() > b.getType())
    return true;
  if(a.getType() < b.getType())
    return false;
  switch(a.getType()) {
    case ATerm.APPL:
      ATermAppl appl1 = (ATermAppl)a;
      ATermAppl appl2 = (ATermAppl)b;
      if(appl1.getFun().equals(appl2.getFun()))
	return moreSpecific(appl1.getArgs(), appl2.getArgs());
      if(moreSpecific(appl1.getFun(), appl2.getFun()))
	return true;
      return false;
    case ATerm.PLACEHOLDER:
      ATermPlaceholder p1 = (ATermPlaceholder)a;
      ATermPlaceholder p2 = (ATermPlaceholder)b;
      return moreSpecific(p1.getPlaceholderType(), p2.getPlaceholderType());
    case ATerm.ATERMS:
      ATerms terms1 = (ATerms)a;
      ATerms terms2 = (ATerms)b;
      if(terms1.isEmpty())
	return true;
      if(terms2.isEmpty())
	return false;
      if(terms1.getFirst().equals(terms2.getFirst()))
	return moreSpecific(terms1.getNext(), terms2.getNext());
      return moreSpecific(terms1.getFirst(), terms2.getFirst());
  }
  return false; // compiler!
}

//}
  //{ private boolean moreSpecific(String a, String b)

  private boolean moreSpecific(String a, String b)
  {
    int i;
    for(i=0; i<a.length(); i++) {
      if(i > b.length())
	return true;
      if(a.charAt(i) < b.charAt(i))
	return true;
    }
    return false;
  }

  //}
  //{ public void print(PrintWriter out)

  public void print(PrintWriter out)
  {
    for(int i=0; i<size(); i++) {
      ((ATerm)elementAt(i)).println(out);
    }
  }

  //}
  //{ public void genPatterns(PrintWriter out, String base)

  /**
     Generate pattern declarations for the functions in this vector.
    */
  public void genPatterns(PrintWriter out, String base, String func)
    throws IOException
  {
    for(int i=0; i<size(); i++) {
      out.print("      P" + base + i + " = world.makePattern(\"");
      if(func != null)
	out.print(func + "(");
      ((ATerm)elementAt(i)).print(out);
      if(func != null)
	out.print(")");
      out.println("\");");
    }
  }

  //}
  //{ public void genPatternAttribs(PrintWriter out, String base)

  /**
     Generate pattern attributes for the functions in this vector.
    */
  public void genPatternAttribs(PrintWriter out, String base)
    throws IOException
  {
    for(int i=0; i<size(); i++)
      out.println("  private ATermPattern P" + base + i + ";");
  }

  //}
  //{ public void genCalls(PrintWriter out, String base, boolean ret)

  public void genCalls(PrintWriter out, String base, boolean ret)
  {
    for(int i=0; i<size(); i++) {
      ATermAppl appl = ((ATermAppl)elementAt(i));
      out.println("if(P" + base + i + ".match(term)) {");
      out.println("      ATermPattern P = P" + base + i + ";");
      if(ret)
        out.print("      return " + base + "(");
      else
        out.print("      " + base + "(");
      genArgs(out, appl.getArgs());
      out.print(");\n    } else ");
    }
  }

  //}
  //{ private static void genArgs(PrintWriter out, ATerms args)

  private static void genArgs(PrintWriter out, ATerms args)
  {
    int idx = 0;

    while(!args.isEmpty()) {
      ATermPlaceholder ph = (ATermPlaceholder)args.getFirst();
      String fun = ((ATermAppl)ph.getPlaceholderType()).getFun();
      args = args.getNext();
      if(fun.equals("int"))
        out.print("((Integer)P.elementAt(" + idx + ")).intValue()");
      else if(fun.equals("real"))
        out.print("((Double)P.elementAt(" + idx + ")).doubleValue()");
      else if(fun.equals("term"))
        out.print("(ATerm)P.elementAt(" + idx + ")");
      else if(fun.equals("appl"))
        out.print("(ATermAppl)P.elementAt(" + idx + ")");
      else if(fun.equals("list"))
        out.print("(ATermList)P.elementAt(" + idx + ")");
      else if(fun.equals("str"))
	out.print("(String)P.elementAt(" + idx + ")");
      else
	out.print("(ATermAppl)P.elementAt(" + idx + ")");
      if(!args.isEmpty())
        out.print(", ");
      idx++;
    }
  }

  //}
  //{ public void genMethods(PrintWriter out, String base, boolean ret)

  public void genMethods(PrintWriter out, String base, boolean ret)
  {
    for(int i=0; i<size(); i++) {
      ATermAppl appl = ((ATermAppl)elementAt(i));
      if(ret)
        out.print("  abstract ATerm " + base + "(");
      else
	out.print("  abstract void " + base + "(");
      genFormals(out, appl.getArgs());
      out.println(") throws ToolException;");
    }
  }

  //}
  //{ private static void genFormals(PrintWriter out, ATerms args)

  private static void genFormals(PrintWriter out, ATerms args)
  {
    int idx = 0;

    while(!args.isEmpty()) {
      ATermPlaceholder ph = (ATermPlaceholder)args.getFirst();
      String fun = ((ATermAppl)ph.getPlaceholderType()).getFun();
      args = args.getNext();
      if(fun.equals("int"))
        out.print("int i" + idx);
      else if(fun.equals("real"))
        out.print("double d" + idx);
      else if(fun.equals("term"))
        out.print("ATerm t" + idx);
      else if(fun.equals("appl"))
        out.print("ATermAppl a" + idx);
      else if(fun.equals("list"))
        out.print("ATermList l" + idx);
      else if(fun.equals("str"))
	out.print("String s" + idx);
      else
	out.print("ATermAppl a" + idx);

      if(!args.isEmpty())
        out.print(", ");
      idx++;
    }
  }

  //}
}


