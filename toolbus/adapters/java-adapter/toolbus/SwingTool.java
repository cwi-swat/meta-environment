package toolbus;

import java.io.*;
import javax.swing.*;

import aterm.*;

abstract public class SwingTool
  extends AbstractTool
{

  public SwingTool(ATermFactory factory) {
    super(factory);
  }

  public void handleIncomingTerm(final ATerm t)
  {
    Runnable run = new Runnable() {
      public void run() {
	try {
	  handleTerm(t);
	} catch (IOException e) {
	  throw new RuntimeException(e);
	}
      }
    };
    SwingUtilities.invokeLater(run);
  }
}
