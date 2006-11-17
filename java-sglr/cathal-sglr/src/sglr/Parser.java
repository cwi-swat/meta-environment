/*
 * Parser.java - created at 2:07:38 PM Sep 3, 2004
 */
package sglr;

import aterm.ATerm;
import aterm.pure.*;
import java.io.*;

import sglr.util.*;
import sglr.mept.PTree;

import gnu.getopt.Getopt;

/**
 * @author Cathal Boogerd
 * 
 * Simple commandline interface to the ParserCore class.
 */
public class Parser {
	private static int OUTPUT_TEXT = 0;
	private static int OUTPUT_BAF = 1;
	
	private static String ptreeFormat = PTree.FORMAT_ASFIX2ME;
	private static PureFactory fac = new PureFactory();
	private static int outputFormat = OUTPUT_TEXT;
	private static String parseTable;
	private static String inputFile;
	private static InputStream input;
	private static int numTests = 1;
	private static PrintStream output;
	private static boolean flagHybrid;
	private static Log stats; 
	
	public static void main(String [] args) {
		String inputTerm;
		Benchmark t0, t1;
		ParserCore parser;
		ATerm result = null;
		flagHybrid = false;
		parseOptions(args);
		
		if (parseTable == null) {
			System.err.println("No parsetable specified");
			System.exit(1);
		}
		if (output == null) {
			output = System.out;
		}
		
		for (int i = 0; i < numTests; i++) {
			if (inputFile == null) {
				input = System.in;
			}
			else {
				try {
					input = new FileInputStream(inputFile);
				}
				catch (FileNotFoundException ex) {
					System.err.println(ex.getMessage());
				}				
			}
			
			try {
				stats = new Log();
				t0 = new Benchmark();
				inputTerm = readInput(input);
				t1 = new Benchmark();
				stats.append("total reading time ", t1.diff(t0));
				
				t0 = new Benchmark();
				parser = new ParserCore(new FileInputStream(parseTable), fac, flagHybrid, stats);
				t1 = new Benchmark();
				stats.append("total initialization time ", t1.diff(t0));
				
				if (ptreeFormat == null) {
					result = parser.recognizeFromString(inputTerm);
				}
				else {
					result = parser.parseFromString(inputTerm, ptreeFormat);
				}
				t0 = new Benchmark();
				stats.append("total parsing time ", t0.diff(t1));
			}
			catch (Exception ex) {
				System.err.println(ex.toString());
				ex.printStackTrace();
				System.exit(1);
			}
			
			t0 = new Benchmark();
			if (ptreeFormat != null) {
				output.print(result);
			}
			t1 = new Benchmark();
			stats.append("total output time ", t1.diff(t0));
			stats.print();
		}
	}

	public static void parseOptions(String [] args) {
		Getopt options = new Getopt("parser", args, "2bhi:mno:p:tes:");
		int opt;
		char curOption;
		
		while ((opt = options.getopt()) != -1) {
			curOption = (char) opt;
			switch (curOption) {
			case '2':
				ptreeFormat = PTree.FORMAT_ASFIX2;
				break;
				
			case 'b':
				outputFormat = OUTPUT_BAF;
				break;
				
			case 'h':
				printUsage();
				System.exit(0);
				break;
			
			case 'i':
				inputFile = options.getOptarg();
				break;
			
			case 'm':
				ptreeFormat = PTree.FORMAT_ASFIX2ME;
				break;
			
			case 'n':
				ptreeFormat = null;
				break;
			
			case 'o':
				try {
					output = new PrintStream(new FileOutputStream(options.getOptarg()));
				}
				catch (FileNotFoundException ex) {
					System.err.println(ex.getMessage());
				}
				break;
				
			case 'p':
				parseTable = options.getOptarg();
				break;
				
			case 't':
				outputFormat = OUTPUT_TEXT;
				break;
			
			case 'e':
				flagHybrid = true;
				break;

			case 's':
				numTests = Integer.parseInt(options.getOptarg());
			}
		}
	}
	
	public static void printUsage() {
		System.out.println("Usage:\n" +
				"sglr\t-p file [-2bhmnt] [-i file] [-o file]\n" +
				"Parameters:\n" +
				"\t-2\t\t: use AsFix2 output format\t\t\t\t[off]\n" +
				"\t-b\t\t: output AsFix in binary format (BAF)\t\t[on]]\n" +
				"\t-h\t\t: display usage information\n" +
				"\t-i file\t: input from |file|\t\t\t\t[-]\n" +
				"\t-m\t\t: use AsFix2ME output format\t\t\t[on]\n" +
				"\t-n\t\t: toggle parse tree creation\t\t\t[on]\n" +
				"\t-o file\t: output to |file|\t\t\t\t[-]\n" +
				"\t-p file\t: use parse table |file| (required)\t\t[unspecified]\n" +
				"\t-t\t\t: output AsFix in textual format\t\t\t[off]");
	}
	
	public static String readInput(InputStream in) throws IOException {
		String content = new String();
		int read, length = 1024;
		char [] buffer = new char[length];
		BufferedReader inputReader = new BufferedReader(new InputStreamReader(in));
		
		while (inputReader.ready()) {
			read = inputReader.read(buffer, 0, length);
			content += String.valueOf(buffer, 0, read);
		}
		
		return content;
	}
}
