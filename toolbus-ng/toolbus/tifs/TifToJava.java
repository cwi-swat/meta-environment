package toolbus.tifs;

import java.io.*;
import java.util.*;

import aterm.*;

public class TifToJava {
  private Tif tif;
  private String outputBaseDir;

  private String capitalize(String s) {
    return s.substring(0, 1).toUpperCase() + s.substring(1);
  }

  public TifToJava(Tif tif, String outputBaseDir) {
    this.tif = tif;
    this.outputBaseDir = outputBaseDir;
  }

  private void generate() {
    Iterator iter = tif.fetchProcessIterator();
    while (iter.hasNext()) {
      Process process = (Process) iter.next();
      generateProcessInterface(process);
    }
  }

  private void generateProcessInterface(Process process) {
    String packageName = tif.getPackageName();

    String outputDirName = packageName.replace('.', File.separatorChar);
    if (!outputBaseDir.equals("")) {
      outputDirName = outputBaseDir + File.separatorChar + outputDirName;
    }
    File outputDir = new File(outputDirName);
    outputDir.mkdirs();
    
    String processName = process.getName();
    String fileName = processName + ".java";
    PrintStream out;
    try {
      File outputFile = new File(outputDir, fileName);
      out = new PrintStream(new FileOutputStream(outputFile));
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    }
    out.println("package " + packageName + ";");
    out.println();
    out.println("public interface " + process.getName());
    out.println('{');
    Iterator iter = process.fetchCommunicationIterator();
    while (iter.hasNext()) {
      Communication comm = (Communication) iter.next();
      generateCommunication(comm, out);
    }
    out.println('}');
  }

  private String makeJavaMethodName(String commName) {
    StringBuffer buf = new StringBuffer();
    StringTokenizer tokenizer = new StringTokenizer(commName, "-");
    if (tokenizer.hasMoreTokens()) {
      buf.append(tokenizer.nextToken());
    }
    while (tokenizer.hasMoreTokens()) {
      buf.append(capitalize(tokenizer.nextToken()));
    }
    return buf.toString();
  }

  public void generateCommunication(Communication comm, PrintStream out) {
    String commName = comm.getName();
    String methodName = makeJavaMethodName(commName);
    out.print("  public ");
    out.print(comm.getResultType());
    out.print(' ');
    out.print(methodName);
    out.print('(');
    Iterator iter = comm.fetchArgumentIterator();
    int argCount = 0;
    while (iter.hasNext()) {
      String type = (String) iter.next();
      out.print(type);
      out.print(' ');
      out.print("arg");
      out.print(argCount++);
      if (iter.hasNext()) {
        out.print(", ");
      }
    } 
    out.println(");");
  }

  private static boolean isCommandLineSwitch(String arg, String shortName, String longName) {
    return shortName.equals(arg) || longName.startsWith(arg);
  }

  public static void main(String[] args) {
    String fileName = "";
    String outputBaseDir = "";

    for (int i = 0; i < args.length; i++) {
      if (isCommandLineSwitch(args[i], "-t", "--tifs")) {
        fileName = args[++i];
      }
      if (isCommandLineSwitch(args[i], "-o", "--output-dir")) {
        outputBaseDir = args[++i];
      }
    }

    ATermFactory factory = new aterm.pure.PureFactory();
    ATerm tifsTerm = null;

    try {
      tifsTerm = factory.readFromFile(fileName);
    } catch (IOException e) {
      System.err.println("Error reading " + fileName + ": " + e);
    }
    Tif tif = new Tif(tifsTerm);
    TifToJava generator = new TifToJava(tif, outputBaseDir);
    generator.generate();
  }

}
