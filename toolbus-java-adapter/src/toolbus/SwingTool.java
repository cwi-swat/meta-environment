package toolbus;

import java.io.IOException;
import java.net.SocketException;

import javax.swing.SwingUtilities;

import aterm.ATerm;
import aterm.ATermFactory;

abstract public class SwingTool extends AbstractTool {

    public SwingTool(ATermFactory factory) {
        super(factory);
    }

    public void handleIncomingTerm(final ATerm t) {
        Runnable run = new Runnable() {
            public void run() {
                try {
                    handleTerm(t);
                } catch (IOException e) {
                	if (e instanceof SocketException) {
                		System.exit(0);
                	}
                	e.printStackTrace();
                    throw new RuntimeException(e.getMessage());
                }
            }
        };
        SwingUtilities.invokeLater(run);
    }
}
