package metastudio.components;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.ValueChangedListener;
import metastudio.components.graphs.ParseTreePanel;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class ParseTreeBrowser extends UserInterfacePanel {
    public ParseTreeBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        ParseTreePanel parseTreePanel = new ParseTreePanel((PureFactory)factory, getBridge());
        
        parseTreePanel.addValueChangedListener(new ValueChangedListener() {
			public void valueChanged() {
				fireValueChangedListener();
			}
		});
        
        add(parseTreePanel);
    }
}
