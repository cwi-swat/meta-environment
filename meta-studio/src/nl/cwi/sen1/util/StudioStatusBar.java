package nl.cwi.sen1.util;

import java.awt.Insets;

import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.SwingConstants;

public class StudioStatusBar extends JPanel {
    public StudioStatusBar() {
        super(new StudioStatusBarLayout());
    }

    public void addSeparator() {
        JSeparator sep = new JSeparator(SwingConstants.VERTICAL);
        add(sep, new StudioStatusBarConstraints(new Insets(0, 5, 0, 5)));
    }
}
