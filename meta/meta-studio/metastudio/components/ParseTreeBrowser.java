package metastudio.components;

import javax.swing.JSplitPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.ValueChangedListener;
import metastudio.components.graphs.BoxTree;
import metastudio.components.graphs.ParseTreePanel;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class ParseTreeBrowser extends UserInterfacePanel {
    public ParseTreeBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        ParseTreePanel parseTreePanel = new ParseTreePanel((PureFactory)factory, getBridge());
        JSplitPane pane =  
          new JSplitPane(JSplitPane.VERTICAL_SPLIT, 
                parseTreePanel,
                new BoxTree(factory, getBridge()));
        
        parseTreePanel.addValueChangedListener(new ValueChangedListener() {
			public void valueChanged() {
				fireValueChangedListener();
			}
		});
        
        //TODO: Preferences?
        pane.setDividerLocation(0.5);
        pane.setResizeWeight(0.5);
        pane.setOneTouchExpandable(true);
        
        add(pane);
    }
}
