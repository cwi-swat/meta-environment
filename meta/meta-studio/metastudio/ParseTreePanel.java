package metastudio;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.graph.MetaGraphFactory;
import metastudio.graph.Node;

public class ParseTreePanel extends GraphPanel {
	private UserInterfaceBridge bridge;
	private static MetaGraphFactory factory;

	public ParseTreePanel(UserInterfaceBridge br, MetaGraphFactory fac) {

		super("parsetree");
		bridge = br;
		factory = fac;

		MouseListener listener = new MouseAdapter() {
			public void mouseClicked(MouseEvent event) {
				Node node = getNodeAt(event.getX(), event.getY());
				if (node != getSelectedNode()) {
					if (node != null) {
						if (node.hasInfo("message")) {
							bridge.postEvent(node.getInfo("message"));
						}
					}
				}
			}
		};
		addMouseListener(listener);
	}
}
