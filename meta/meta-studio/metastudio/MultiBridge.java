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

	public void displayGraph(String id, ATerm graphTerm) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.displayGraph(id, graphTerm);
		}
	}

	public void renderGraph(String id, ATerm graphTerm) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.renderGraph(id, graphTerm);
		}
	}

	public void addEvents(ATerm type, ATerm events) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.addEvents(type, events);
		}
	}

	public void addEvents(ATerm type, String moduleId, ATerm events) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.addEvents(type, moduleId, events);
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

	public void showListChoice(String s0, String s1, ATerm t1) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.showListChoice(s0, s1, t1);
		}
	}

	public void displayTreelist(String id, ATerm treeList) {
		Iterator iter = getToolComponents().iterator();

		while (iter.hasNext()) {
			UserInterfaceTif tif = (UserInterfaceTif) iter.next();
			tif.displayTreelist(id, treeList);
		}
	}

	public void recAckEvent(ATerm event) {
	}

	public void recTerminate(ATerm t0) {
		System.exit(0);
	}
}
