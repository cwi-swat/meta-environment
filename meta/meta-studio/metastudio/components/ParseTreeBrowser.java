package metastudio.components;

import javax.swing.JSplitPane;

import metastudio.*;
import metastudio.MultiBridge;
import metastudio.components.graphs.BoxTree;
import metastudio.components.graphs.ParseTreePanel;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class ParseTreeBrowser extends UserInterfacePanel {
    public ParseTreeBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        JSplitPane pane =  
          new JSplitPane(JSplitPane.VERTICAL_SPLIT, 
                new ParseTreePanel((PureFactory)factory, getBridge()),
                new BoxTree(factory, getBridge()));
        
        //TODO: Preferences?
        pane.setDividerLocation(0.5);
        pane.setResizeWeight(0.5);
        pane.setOneTouchExpandable(true);
        
        add(pane);
    }

}
