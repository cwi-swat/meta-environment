package tide.tool.support;

import java.io.*;

public class Info
{
  PrintStream stream;
  String subject;
  boolean verbose = true;

  //{{{ public Info(String subject)

  public Info(String subject)
  {
    this.subject = subject;
    this.stream  = System.out;
  }

  //}}}

  //{{{ public void info(String what, String msg)

  public void info(String what, String msg)
  {
    if (verbose) {
      stream.println("[" + what + "] " + msg);
    }
  }

  //}}}
  //{{{ public void info(String msg)

  public void info(String msg)
  {
    info(subject, msg);
  }

  //}}}

  //{{{ public void setVerbose(boolean on)

  public void setVerbose(boolean on)
  {
    verbose = on;
  }

  //}}}
}

