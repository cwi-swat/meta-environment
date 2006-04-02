package toolbus.parser;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import toolbus.TBTermFactory;
import toolbus.ToolBus;
import aterm.ATerm;

/**
 * Provide access to an external parser. Used to call sglr and implode-asfix.
 * Code borrowed from JJForester and adapted/extended
 */
public class ExternalParser {

  String parseCommand;
  String implodeCommand;
  String implodeOptions = "-tlILXpcO";
  String addPosInfoCommand;
  String addPosInfoOptions;

  /**
   * Construct an ExternalParser object without specifying a start symbol
   * for sglr. Use of this method will lead more easily to
   * unwanted ambiguities.
   */
  public ExternalParser(
    String parseTable,
    String sglrLocation,
    String sglrSwitches,
    String implodeCommand,
    String implodeOptions) {
    parseCommand = sglrLocation + "/bin/sglr " + sglrSwitches + " -p " + parseTable;
    this.implodeCommand = implodeCommand + " " + implodeOptions;
  }
  /**
   * Generate ExternalParser object which calls sglr with a specific start
   * symbol.
   */
  public ExternalParser(
    String startSymbol,
    String parseTable,
    String sglrLocation,
    String sglrSwitches,
    String implodeCommand,
    String implodeOptions) {
    parseCommand = sglrLocation + "/bin/sglr " + sglrSwitches + " -p " + parseTable + " -s " + startSymbol;
    this.implodeCommand = implodeCommand + " " + implodeOptions;
  }
  /**
   * Construct an ExternalParser method by fully specifying the commands for
   * the parse, implode, and conversion phases.
   */
  public ExternalParser(String parseCommand, String parseTable, String implodeCommand) {
    this.parseCommand = parseCommand + " -p " + parseTable;
    this.implodeCommand = implodeCommand + " " + implodeOptions;
  }
  
  public ExternalParser(ToolBus toolbus) {
	    this.parseCommand = toolbus.get("sglr.path") + " -p " + toolbus.get("parsetable.path");
	    this.implodeCommand = toolbus.get("implodePT.path") + " " + implodeOptions;
	    this.addPosInfoCommand = toolbus.get("addPosInfo.path");
	  }

  /**
   * Parse the source file with the given name in an ATerm that represents
   * its abstract syntax tree.
 * @param tbfactory TODO
   */
  public ATerm parse(String sourceFileName, TBTermFactory tbfactory) throws ExternalProcessException {
    ATerm result = null;
    String asfixFileName1 = getNewFileName("asfix");
    String asfixFileName2 = getNewFileName("asfix");
    execute(parseCommand, sourceFileName, asfixFileName1, "parse");
    execute(addPosInfoCommand + " -p " + sourceFileName, asfixFileName1, asfixFileName2, "parse");
    InputStream in = execute(implodeCommand, asfixFileName2, "implode");
    try {
    	InputStreamReader reader = new InputStreamReader(in);
      result = tbfactory.readFromTextFile(reader);
    } catch (IOException e) {
      throw new ExternalProcessException(e.getMessage(), "read ATerm from file");
    }
    //delete(asfixFileName1);
    //delete(asfixFileName2);
    return result;
  }

  /**
   * Execute the given command where the given files are supplied as
   * input and output.
   */
  public static void execute(String command, String inFileName, String outFileName, String processType)
    throws ExternalProcessException {
    String commandLine = command + " -i " + inFileName + " -o " + outFileName;
    Process p = execute(commandLine, processType);
    waitForExternalResult(p, "ToolBus: external process failed to produce a result", processType);
  }

  /**
   * Execute the given command where the given file is supplied as input, and
   * the output is connected to the InputStream that is returned.
   */
  public static InputStream execute(String command, String inFileName, String processType)
    throws ExternalProcessException {
    String commandLine = command + " -i " + inFileName;
    Process p = execute(commandLine, processType);
    return p.getInputStream();
  }

  /**
   * Execute the given command and return the process object that is running
   * it.
   */
  public static Process execute(String command, String processType) throws ExternalProcessException {
    System.err.println("ToolBus: executing external command:");
    System.err.println("  " + command);
    try {
      return Runtime.getRuntime().exec(command);
    } catch (java.io.IOException e) {
      throw new ExternalProcessException(e.getMessage(), processType);
    }
  }

  /**
   * Generate a new, unique name for a temporary file.
   */
  public static String getNewFileName(String str) {
    return "/tmp/toolbus." + str + "." + System.currentTimeMillis();
  }

  /**
   * Block the current thread until the given process has terminated. Throw
   * an ExternalProcessException on abnormal termination.
   */
  public static void waitForExternalResult(Process p, String msg, String processType) throws ExternalProcessException {
    int result;
    try {
      result = p.waitFor();
    } catch (InterruptedException e) {
      throw new ExternalProcessException(e.getMessage(), processType);
    }
    if (result != 0) {
      try {
        copyErrorStream(p);
      } catch (java.io.IOException e) {
        throw new ExternalProcessException(msg, processType);
      }
      throw new ExternalProcessException(msg, processType);
    }
  }

  public static void copyErrorStream(Process p) throws java.io.IOException {
    byte[] b = new byte[10240];
    InputStream err = p.getErrorStream();
    int read;
    while ((read = err.read(b)) >= 0) {
      System.err.write(b, 0, read);
    }
  }

  public static void delete(String filename) {
    File f = new File(filename);
    if (!f.exists())
      fail("delete: no such file or directory: " + filename);
    if (!f.canWrite())
      fail("delete: write protected: " + filename);
    if (f.isDirectory()) {
      String[] files = f.list();
      if (files.length > 0)
        fail("delete: directory not empty: " + filename);
    }
    if (!f.delete())
      fail("delete: deletion failed: " + filename);
  }

  protected static void fail(String msg) throws IllegalArgumentException {
    throw new IllegalArgumentException(msg);
  }

}
