package metastudio;

import java.util.Iterator;
import java.util.LinkedList;

import aterm.ATerm;
import aterm.ATermFactory;

public class MultiBridge extends UserInterfaceTool {
    private ATermFactory factory;
    private LinkedList toolComponents;
    
    protected MultiBridge(ATermFactory factory) {
        super(factory);
        this.factory = factory;
        toolComponents = new LinkedList();
    }
    
    private LinkedList getToolComponents() {
        return toolComponents;
    }

    public void addToolComponent(UserInterfaceTif tool) {
        getToolComponents().add(new UserInterfaceBridge(factory, tool));
    }
    
    public void newGraph(ATerm importRelations) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.newGraph(importRelations);
        }
    }

    public void displayGraph(String id, ATerm graphTerm) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.displayGraph(id, graphTerm);
        }
    }

    public void graphLayouted(String id, ATerm graphTerm) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.graphLayouted(id, graphTerm);
        }
    }
    
    public void buttonsFound(ATerm buttonType, String moduleName, ATerm buttons) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.buttonsFound(buttonType, moduleName, buttons);
        }
    }

    
    public void addStatus(ATerm id, String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.addStatus(id, message);
        }
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.addStatusf(id, format, args);
        }
    }

    public void endStatus(ATerm id) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.endStatus(id);
        }
    }

    public void displayFeedbackSummary(ATerm t0) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.displayFeedbackSummary(t0);
        }
    }

    public void updateList(String moduleName, String actions) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.updateList(moduleName, actions);
        }
    }

    public void errorf(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.errorf(format, args);
        }
    }

    public void error(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.error(message);
        }
    }

    public void messagef(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.messagef(format, args);
        }
    }

    public void message(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.message(message);
        }
    }

    public void warningf(String format, ATerm args) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.warningf(format, args);
        }
    }

    public void warning(String message) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.warning(message);
        }
    }

    public void clearHistory() {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.clearHistory();
        }
    }

    public void initializeUi(String s0) {
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            tif.initializeUi(s0);
        }
    }
    
    public ATerm showQuestionDialog(String question) {
        ATerm result = null;
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            result = tif.showQuestionDialog(question);

            if (result != null) {
                return factory.make("snd-value(<term>)", result);
            }
        }

        throw new UnsupportedOperationException("not implemented");
    }

    public ATerm showFileDialog(String label, String loc, String extension) {
        ATerm result = null;
        Iterator iter = getToolComponents().iterator();

        while (iter.hasNext()) {
            UserInterfaceTif tif = (UserInterfaceTif) iter.next();
            result = tif.showFileDialog(label, loc, extension);

            if (result != null) {
                return factory.make("snd-value(<term>)", result);
            }
        }

        throw new UnsupportedOperationException("not implemented");
    }
    
    public void recAckEvent(ATerm event) {
    }

    public void recTerminate(ATerm t0) {
        System.exit(0);
    }

   

   
}
