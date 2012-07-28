import java.util.*;
import java.io.*;

public class Chunk
{
  private static int nrStores = 0;
  private static String outputFile;
  
  private static void generateMerge(String inputArgs) {
    StringBuffer buf = new StringBuffer();
    buf.append("Rstore -f merge8 -r RSTORE -o ");
    buf.append(outputFile);
    buf.append("-");
    buf.append(nrStores++);
    buf.append(".rstore ");
    buf.append(inputArgs);
    System.out.println(buf.toString());
  }

  private static void chunk(List lines) {
    StringBuffer buf = new StringBuffer();
    Iterator iter = lines.iterator();
    int count = 0;
    System.out.println("#! /bin/sh");
    System.out.println("[ ! -f empty.rstore ] && echo 'rstore()' \\");
    System.out.println("  | sglr -p $1 -o empty.rstore -s RSTORE");
    System.out.println();
    while (iter.hasNext()) {
      String line = (String) iter.next();
      buf.append("-i ");
      buf.append(line);
      buf.append(' ');
      if (count++ == 7) {
	generateMerge(buf.toString());
	buf = new StringBuffer();
	count = 0;
      }
    }
    if (count > 0) {
      while (count < 8) {
	buf.append("-i empty.rstore ");
	count++;
      }
      generateMerge(buf.toString());
    }
  }

  public static final void main(String[] args) throws Exception {
    List lines = new LinkedList();
    FileReader reader = new FileReader(args[0]);
    LineNumberReader lnr = new LineNumberReader(reader);
    String line;
    while ( (line = lnr.readLine()) != null) {
      lines.add(line);
    }
    outputFile = args[1];
    chunk(lines);
  }
}
