package toolbus;

import javax.swing.SwingUtilities;

import aterm.ATerm;
import aterm.ATermFactory;

abstract public class SwingTool extends AbstractTool {

    public SwingTool(ATermFactory factory) {
        super(factory);
    }

    public void handleIncomingTerm(final byte operation, final ATerm t) {
        Runnable run = new Runnable() {
            public void run() {
                handleTerm(operation, t);
            }
        };
        SwingUtilities.invokeLater(run);
    }
}
