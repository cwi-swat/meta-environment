package argusviewer.view.architectureview;

import javax.swing.JComponent;
import javax.swing.JSplitPane;

/**
 * The {@link ArchitectureSplitPane} displays both the architecture and the tool
 * performance.
 * 
 * @author Jeldert Pol
 */
public class ArchitectureSplitPane extends JSplitPane {
	private static final long serialVersionUID = 7067976447074964309L;
	
	private static final int INITIAL_DIVIDER_LOCATION = 300;

	/**
	 * Constructor. Uses a vertical split, resulting in a top and bottom component.
	 * 
	 * @param topComponent component to add to the top of the {@link JSplitPane}.
	 * @param bottomComponent component to add to the bottom of the {@link JSplitPane}.
	 */
	public ArchitectureSplitPane(JComponent topComponent, JComponent bottomComponent) {
		super(JSplitPane.VERTICAL_SPLIT, topComponent, bottomComponent);
		
		this.setDividerLocation(INITIAL_DIVIDER_LOCATION);
	}

}
