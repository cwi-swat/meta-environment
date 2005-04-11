/*
 * Created on 5-sep-2004
 */
package sglr;

import java.io.*;

import sglr.gss.GSS;
import sglr.gss.ParseStack;
import sglr.mept.PTable;
import sglr.util.*;

import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * @author Cathal Boogerd
 */
public class ParserCore {
	private PTable ptable;
	private ParseStack st;
	private ParseInput input;
	private ParseLocation location;
	private PureFactory factory;
	private errorapi.Factory errorFactory;
	private sglr.ptable.Factory ptFactory;
	private Log statistics;
	private boolean hybrid;
	
	public ParserCore(InputStream input, PureFactory fac, boolean flagHybrid, Log stats) throws IOException {
		statistics = stats;
		factory = fac;
		hybrid = flagHybrid;
		
		Benchmark t0 = new Benchmark();
		errorFactory = new errorapi.Factory(fac);
		ptFactory = new sglr.ptable.Factory(fac);
		Benchmark t1 = new Benchmark();
		statistics.append("initializing factories", t1.diff(t0));
		
		ptable = new PTable(input, ptFactory);
		Benchmark t2 = new Benchmark();
		statistics.append("initializing parsetable", t2.diff(t1));
	}
	
	public ATerm recognizeFromFile(File inputFile) throws FileNotFoundException, IOException {
		return parseFromFile(inputFile, null);
	}
	
	public ATerm recognizeFromString(String inputString) {
		return parseFromString(inputString, null);
	}
	
	public ATerm recognize() {
		return parse(null);
	}
	
	public ATerm parseFromFile(File inputFile, String ptreeFormat) throws FileNotFoundException, IOException {
		input = new ParseInput(inputFile);
		location = new ParseLocation(errorFactory, inputFile.getName());
		return parse(ptreeFormat);
	}
	
	public ATerm parseFromString(String inputString, String ptreeFormat) {
		input = new ParseInput(inputString);
		location = new ParseLocation(errorFactory, "");
		return parse(ptreeFormat);
	}
	
	public ATerm parse(String ptreeFormat) {
		Benchmark totalParse, totalShift, t0, t1, t2;
		int token = PTable.TOKEN_NONE;
		GSS graph;
		
		totalParse = new Benchmark(0);
		totalShift = new Benchmark(0);
		if (ptreeFormat == null) {
			graph = new GSS(ptable, ptFactory, input, statistics, hybrid);
		} 
		else {
			graph = new GSS(ptable, ptFactory, input, ptreeFormat, statistics, hybrid);
		}

		while (input.ready() && graph.hasActiveStacks()) {
			token = input.read();
			//System.err.print((char) token);
			location.update(token);
			t0 = new Benchmark();
			graph.parseCharacter(token);
			t1 = new Benchmark();
			graph.shifter();
			t2 = new Benchmark();
			totalParse.add(t1.diff(t0));
			totalShift.add(t2.diff(t1));
		}
		
		statistics.append("parsing", totalParse);
		statistics.append("shifting", totalShift);
		
		if (graph.accept()) {
			if (ptreeFormat != null) {
				t0 = new Benchmark();
				ATerm result = graph.getParseTree().toTerm();
				t1 = new Benchmark();
				statistics.append("creating parsetree term ", t1.diff(t0));
				return result;
			}
			else {
				return factory.make("accept");
			}
		}
		
		return errorFactory.makeError_Error("Parse error at " + location.toString(), errorFactory.makeSubjectList(errorFactory.makeSubject_Localized("", location.getLocation())));
	}
}
