package nl.cwi.sen1.tide.adapters.gdb;

import java.util.LinkedList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import nl.cwi.sen1.tide.tool.support.VarFormat;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermInt;

public class RetrieveVarCmd extends Command
{
	static Pattern patternVar;

	private String var;
	private int start;
	private int end;
	private int pos;
	private int linenr;
	
	private String value = "";
	private String error = "";
	
	private static List reservedKeywords;

	static {
		patternVar = Pattern.compile("\\$[0-9]*\\s+=\\s+(.+)");
		reservedKeywords = new LinkedList();
		
		Object[] keywords = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
				"else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short",
				"signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void",
				"volatile", "while"
		};
		for (int i = 0; i < keywords.length; i++) {
			reservedKeywords.add(keywords[i]);
		}
		
	}
	public RetrieveVarCmd(GdbAdapter adapter, ATerm file, ATerm offset, ATerm line, ATerm col, ATerm text)
	{
		super(adapter);

		this.start = ((ATermInt) col).getInt();
		this.pos = ((ATermInt) offset).getInt();
		this.linenr = ((ATermInt) offset).getInt();
		this.var = locateVariableInLine(text);
	}

	private String locateVariableInLine(ATerm text) {
		String name = ((ATermAppl) text).getName();
		
		while(start >= 0) {
			char ch = name.charAt(start);
			if (!Character.isJavaIdentifierPart(ch) &&!Character.isJavaIdentifierPart(ch)) {
				break;
			}
			start--;
			pos--;
		}
		if (start > 0) {
			start += 1;
			pos += 1;
		}
		end = start;
		while (end < name.length()) {
			char ch = name.charAt(end);
			if (!Character.isJavaIdentifierPart(ch) &&!Character.isJavaIdentifierPart(ch)) {
				break;
			}
			end++;
		}

		return name.substring(start, end);
	}

	private static boolean isReserved(String name) {
		if (reservedKeywords.indexOf(name) != -1) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public String command()
	{
		if (!isReserved(var)) {
		  return "print " + var + "\n";
		}
		else {
			return "print DezeVariabeleBestaatWaarschijnlijkTochNiet";
		}
	}

	synchronized public boolean response(String line)
	{
		Matcher matcher = patternVar.matcher(line);
		
		if(matcher.matches()) {
			value = matcher.group(1);
			debugMsg("VAR found: " + value);
			notify();
			return true;
		} 
		
		if(line.startsWith("No symbol") 
				|| line.startsWith("Attempt to")
				|| line.startsWith("A parse error")) {
			error = "unknown variable: " + var; 
			return true;
		} 
		
		return false;
	}

	public String getError() {
		return error;
	}
	
	public ATerm getValue()
	{
		ATermFactory factory = adapter.getFactory();
		if (value.equals("")) {
			return VarFormat.makeVarUnknown(factory,error);
		} else {
			ATerm atValue = factory.makeAppl(factory.makeAFun(value,0,true));
			return VarFormat.makeExprVar(factory, var, atValue, pos, linenr, start, end - start);
		}
	}
}
