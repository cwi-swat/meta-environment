package metastudio.components;

import java.awt.BorderLayout;

import javax.swing.JPanel;

import metastudio.MultiBridge;
import metastudio.UserInterfaceTif;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * This class is  the base class for all
 * MetaStudio widgets that communicate with the ToolBus.
 * 
 * For posting events, an ATermFactory and a UserInterfaceBridge is made
 * available. For dealing with the snd-do's and snd-eval's a standard
 * (empty) implementation for all methods is given. New widgets should override
 * the methods that they are interested in.
 * 
 */
public abstract class ToolComponent extends JPanel implements UserInterfaceTif {
    private ATermFactory factory;
    private MultiBridge bridge;
    
    public ToolComponent(ATermFactory factory, MultiBridge bridge) {
        this.factory = factory;
        this.bridge = bridge;
        bridge.addToolComponent(this);
        setLayout(new BorderLayout());
    }
    
    protected void postEvent(ATerm event) {
        getBridge().postEvent(event);
    }
    
    protected ATermFactory getFactory() {
        return factory;
    }
    
    protected MultiBridge getBridge() {
        return bridge;
    }

    public void messagef(String s0, ATerm t1) {
        // intentionally left empty
    }

    public void updateList(String s0, String s1) {
        // intentionally left empty
    }

    public void initializeUi(String s0) {
        // intentionally left empty
    }

    public void warningf(String s0, ATerm t1) {
        // intentionally left empty
    }

    public void message(String s0) {
        // intentionally left empty
    }

    public void newGraph(ATerm t0) {
        // intentionally left empty
    }

    public void displayGraph(String s0, ATerm t1) {
        // intentionally left empty
    }

    public void clearHistory() {
        // intentionally left empty
    }

    public void graphLayouted(String s0, ATerm t1) {
        // intentionally left empty
    }

    public void errorf(String s0, ATerm t1) {
        // intentionally left empty
    }

    public void warning(String s0) {
        // intentionally left empty
    }

    public void error(String s0) {
        // intentionally left empty
    }

    public void buttonsFound(ATerm t0, String s1, ATerm t2) {
        // intentionally left empty
    }

    public void displayFeedbackSummary(ATerm t0) {
        // intentionally left empty        
    }

    public void addStatusf(ATerm t0, String s1, ATerm t2) {
        // intentionally left empty        
    }

    public void moduleInfo(String s0, ATerm t1) {
        // intentionally left empty        
    }

    public void endStatus(ATerm t0) {
        // intentionally left empty        
    }

    public void addStatus(ATerm t0, String s1) {
        // intentionally left empty        
    }

    public ATerm showQuestionDialog(String s0) {
        // intentionally left empty
        return null;
    }

    public ATerm showFileDialog(String s0, String s1, String s2) {
        // intentionally left empty
        return null;
    }

    public void recAckEvent(ATerm t0) {
        // intentionally left empty        
    }

    public void recTerminate(ATerm t0) {
        // intentionally left empty        
    }
}
