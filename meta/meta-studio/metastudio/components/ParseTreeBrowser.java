package metastudio.components;

import javax.swing.JSplitPane;

import metastudio.MultiBridge;
import metastudio.components.graphs.BoxTree;
import metastudio.components.graphs.ParseTreePanel;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class ParseTreeBrowser extends ToolComponent {
    public ParseTreeBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        JSplitPane pane =  
          new JSplitPane(JSplitPane.VERTICAL_SPLIT, 
                new ParseTreePanel((PureFactory)factory, getBridge()),
                new BoxTree(factory, getBridge()));
        
        pane.setDividerLocation(0.5);
        pane.setResizeWeight(0.5);
        
        add(pane);
    }

}
