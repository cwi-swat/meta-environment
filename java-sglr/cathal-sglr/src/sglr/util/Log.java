/*
 * Created on Dec 1, 2004
 */
package sglr.util;

import java.io.*;

public class Log {
	private String log;
	private PrintStream defaultStream;
	private int reductionTotal;
	private int reductionSimple;
	private int reductionSimpleLength;
	private int reductionLength;
	
	public Log() throws FileNotFoundException {
		log = new String();
		defaultStream = new PrintStream(new FileOutputStream("sglr.statistics.log"));
		reductionTotal = reductionSimple = reductionLength = 0;
	}
	
	public void appendLine(String msg) {
		append(msg + "\r\n");
	}
	
	public void append(String msg) {
		log += msg;
	}
	
	public void append(String msg, Benchmark b) {
		if (msg == null) {
			msg = "";
		}
		appendLine(msg + " [" + b.toString() + " secs]");
	}
	
	public void appendReduction(int length, boolean simple) {
		reductionTotal++;
		if (simple) {
			reductionSimple++;
			reductionSimpleLength += length;
		}
		reductionLength += length;
	}

	public void prepare() {
		appendLine("number of reductions: " + reductionTotal);
		appendLine("average reduction length: " + (float) reductionLength/(float) reductionTotal);
		appendLine("average LR reduction length: " + (float) reductionSimpleLength/(float) reductionSimple);
		appendLine("percentage of LR reductions: " + 100 * ((float) reductionSimple/(float) reductionTotal) + "%");
	}
	
	public void print() {
		print(defaultStream);
	}
	
	public void print(PrintStream stream) {
		prepare();
		stream.print(log);
	}
}
