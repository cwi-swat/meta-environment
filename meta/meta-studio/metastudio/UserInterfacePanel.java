package metastudio;

import java.awt.BorderLayout;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JPanel;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * This class is the base class for all MetaStudio widgets that communicate with
 * the ToolBus.
 * 
 * For posting events, an ATermFactory and a UserInterfaceBridge is made
 * available. For dealing with the snd-do's and snd-eval's a standard (empty)
 * implementation for all methods is given. New widgets should override the
 * methods that they are interested in.
 *  
 */
public abstract class UserInterfacePanel extends JPanel
		implements
			UserInterfaceTif {
	private ATermFactory factory;
	private MultiBridge bridge;
	private List valueChangedListeners;

	public void addValueChangedListener(ValueChangedListener l) {
		valueChangedListeners.add(l);
	}

	protected void fireValueChangedListener() {
		Iterator iter = valueChangedListeners.iterator();

		while (iter.hasNext()) {
			ValueChangedListener l = (ValueChangedListener) iter.next();
			l.valueChanged();
		}
	}

	public UserInterfacePanel(ATermFactory factory, MultiBridge bridge) {
		this.factory = factory;
		this.bridge = bridge;
		this.valueChangedListeners = new LinkedList();
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

	public void updateList(String s0, String s1) {
		// intentionally left empty
	}

	public void initializeUi(String s0) {
		// intentionally left empty
	}

	public void displayGraph(String s0, ATerm t1) {
		// intentionally left empty
	}

	public void displayTreelist(String s0, ATerm t1) {
		// intentionally left empty
	}

	public void clearHistory() {
		// intentionally left empty
	}

	public void renderGraph(String s0, ATerm t1) {
		// intentionally left empty
	}

	public void addEvents(ATerm t0, ATerm t1) {
		// intentionally left empty
	}

	public void addEvents(ATerm t0, String s1, ATerm t2) {
		// intentionally left empty
	}

	public void moduleInfo(String s0, ATerm t1) {
		// intentionally left empty
	}

	public ATerm showQuestionDialog(String s0) {
		// intentionally left empty
		return null;
	}

	public void showListChoice(String s0, String s1, ATerm t2) {
		// intentionally left empty
	}

	public void recAckEvent(ATerm t0) {
		// intentionally left empty
	}

	public void recTerminate(ATerm t0) {
		// intentionally left empty
	}
}