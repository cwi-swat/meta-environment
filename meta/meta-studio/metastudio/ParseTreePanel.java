package metastudio;

import metastudio.graph.*;  
import java.awt.event.*;   


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
              if (node.hasInfo("pos-info")) {
                 //System.out.println("Node has info " + node.getInfo("pos-info"));
                 bridge.postEvent(factory.make("element-selected([\"ShowSource\"], <term>)", node.getInfo("pos-info")));
              }
            }
          }
        }
      };
    addMouseListener(listener);
  }

}
