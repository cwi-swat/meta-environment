package metastudio;

import metastudio.graph.*;  
import java.awt.event.*;   
import aterm.*;   


public class ParseTreePanel extends GraphPanel
{
  private UserInterfaceBridge bridge;
  private static MetaGraphFactory factory;

  public ParseTreePanel(UserInterfaceBridge br, MetaGraphFactory fac) {

    super("parsetree");
    bridge = br;
    factory = fac;

  MouseListener listener
      = new MouseAdapter() {
        public void mouseClicked(MouseEvent event)
        {
          Node node = getNodeAt(event.getX(), event.getY());
          if (node != getSelectedNode()) {
            if (node != null) {
              if (node.hasInfo("message")) {
                 //ATerm message = node.getInfo("message");
                 //System.out.println("Node has info " + message);
                 bridge.postEvent(node.getInfo("message"));
              }
            }
          }
        }
      };
    addMouseListener(listener);
  }

}
