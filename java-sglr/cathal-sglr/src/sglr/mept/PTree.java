/*
 * Created on Sep 10, 2004
 */
package sglr.mept;

import aterm.ATerm;
import sglr.ptable.Factory;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class PTree {
	public static String FORMAT_ASFIX2 = "asfix2";
	public static String FORMAT_ASFIX2ME = "asfix2me";
	
	private static String [] supportedFormats = {FORMAT_ASFIX2, FORMAT_ASFIX2ME};
	private Factory factory;
	private Tree tr;
	private int ambCount;
	private String format;
	private PTreeLeafs leafs;
	
	public PTree(PTableLabel lab, Factory fac, String ptreeFormat) {
		ambCount = 0;
		factory = fac;
		format = ptreeFormat;
		tr = factory.makeTree_Appl(lab.getProduction(), factory.makeArgs());
		
		if (ptreeFormat.equals(FORMAT_ASFIX2ME)) {
			leafs = new PTreeLeafs(fac);
		}
	}

	public PTree(int token, Factory fac, String ptreeFormat) {
		ambCount = 0;
		factory = fac;
		format = ptreeFormat;
		tr = factory.makeTree_Char(token);
		
		if (ptreeFormat.equals(FORMAT_ASFIX2ME)) {
			leafs = new PTreeLeafs(fac);
			leafs.add(tr);
		}
	}
	
	public PTree(PTableLabel lab, PTreeList kids, Factory fac, String ptreeFormat) {
		ambCount = 0;
		factory = fac;
		format = ptreeFormat;
		
		if (ptreeFormat.equals(FORMAT_ASFIX2)) {
			createDefaultNode(lab.getProduction(), kids);
		}
		else if (ptreeFormat.equals(FORMAT_ASFIX2ME)) {
			leafs = new PTreeLeafs(fac);
			Production prod = lab.getProduction();
			Symbol rhs = prod.getRhs();
			Symbols lhs = prod.getLhs();
			
			if (rhs.isCf() && rhs.getSymbol().isOpt() && rhs.getSymbol().getSymbol().isLayout()) {
				createLayoutNode(prod, kids);
			}
			else if (rhs.hasSymbol() && rhs.getSymbol().isLayout()) {
				createLeaf(prod, kids);
			}
			else if (rhs.isLit()) {
				createLiteralNode(prod, kids);
			}
			else if (rhs.isCf() && lhs.getLength() == 1 && lhs.getSymbolAt(0).isLex()) {
				createLexicalNode(prod, kids);
			}
			else if (rhs.isLex()) {
				createLeaf(prod, kids);
			}
			else if (rhs.isCf() && isIteration(rhs.getSymbol())) {
				createListNode(prod, kids);
			}
			else {
				createDefaultNode(prod, kids);
			}
		}
	}
	
	public void addAmbiguity(PTree tree) {
		Args trees;
		
		if (tr.isAmb()) {
			trees = tr.getArgs().append(tree.getTree());
		}
		else {
			trees = factory.makeArgs(tr, tree.getTree());
		}
		tr = factory.makeTree_Amb(trees);
		ambCount++;
	}
	
	public String getFormat() {
		return format;
	}
	
	public Tree getTree() {
		return tr;
	}
	
	public int getAmbCount() {
		return ambCount;
	}
	
	public String toString() {
		return factory.makeParseTree_Top(tr, ambCount).toString();
	}
	
	public ATerm toTerm() {
		return factory.makeParseTree_Top(tr, ambCount).toTerm();
	}
	
	public PTreeLeafs getLeafs() {
		return leafs;
	}
	
	public static boolean isSupportedFormat(String format) {
		for (int i = 0; i < supportedFormats.length; i++) {
			if (supportedFormats[i].equals(format)) {
				return true;
			}
		}
		return false;
	}
	
	private void createLayoutNode(Production prod, PTreeList kids) {
		PTreeLeafs trees = new PTreeLeafs(factory);
		
		for (int i = 0; i < kids.size(); i++) {
			trees.append(kids.fetch(i).getLeafs());
		}
		tr = factory.makeTree_Appl(prod, trees.toArgs());
	}
	
	private void createLexicalNode(Production prod, PTreeList kids) {
		PTreeLeafs trees = new PTreeLeafs(factory);
		
		for (int i = 0; i < kids.size(); i++) {
			trees.append(kids.fetch(i).getLeafs());
		}
		Tree listNode = factory.makeTree_Appl(
				factory.makeProduction_List(
						factory.makeSymbol_IterStar(
								factory.makeSymbol_CharClass(
										factory.makeCharRanges(
												factory.makeCharRange_Range(0, 255)
				)))), 
				trees.toArgs());
		tr = factory.makeTree_Appl(prod, factory.makeArgs(listNode));
	}
	
	private void createListNode(Production prod, PTreeList kids) {
		Tree current;
		PTreeLeafs trees = new PTreeLeafs(factory);
		
		for (int i = 0; i < kids.size(); i++) {
			current = kids.fetch(i).getTree();
			if (current.isAppl() && current.getProd().isList()) {
				trees.append(current.getArgs());
			}
			else {
				trees.add(current);
			}
		}
		tr = factory.makeTree_Appl(factory.makeProduction_List(prod.getRhs()), trees.toArgs());
	}
	
	private void createLiteralNode(Production prod, PTreeList kids) {
		leafs = new PTreeLeafs(factory);
		
		for (int i = 0; i < kids.size(); i++) {
			leafs.add(kids.fetch(i).getTree());
		}
		tr = factory.makeTree_Lit(prod.getRhs().getString());
	}
	
	private void createDefaultNode(Production prod, PTreeList kids) {
		PTree curTree;
		
		for (int i = 0; i < kids.size(); i++) {
			curTree = kids.fetch(i);
			ambCount += curTree.getAmbCount();
		}
		tr = factory.makeTree_Appl(prod, kids.toArgs(factory));
	}
	
	private void createLeaf(Production prod, PTreeList kids) {
		PTree curTree;
		
		for (int i = 0; i < kids.size(); i++) {
			curTree = kids.fetch(i);
			ambCount += curTree.getAmbCount();
			leafs.addAll(curTree.getLeafs());
		}
		tr = factory.makeTree_Appl(prod, kids.toArgs(factory));
	}

	private boolean isIteration(Symbol symb) {
		return (symb.isIterN() || symb.isIterPlus() || symb.isIterPlusSep() || symb.isIterSepN() || symb.isIterSepN() || symb.isIterStar() || symb.isIterStarSep());
	}
}
