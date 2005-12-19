package nl.cwi.sen1.gui;

import javax.swing.SwingUtilities;

import net.infonode.docking.DockingWindow;
import net.infonode.docking.RootWindow;
import net.infonode.docking.SplitWindow;
import net.infonode.docking.TabWindow;
import net.infonode.docking.View;

public class StudioImplWithPredefinedLayout extends StudioImpl implements
        StudioWithPredefinedLayout {
    public static final String BOTTOM_RIGHT = "Bottom Right";

    public static final String BOTTOM_LEFT = "Bottom Left";

    public static final String TOP_RIGHT = "Top Right";

    public static final String TOP_LEFT = "Top Left";

    public static void main(String args[]) throws Exception {
        new StudioImplWithPredefinedLayout(args);
    }

    public StudioImplWithPredefinedLayout(String[] args) {
        super(args);
    }

    protected RootWindow createRootWindow() {
        RootWindow root = super.createRootWindow();

        TabWindow topleftWindow = new TabWindow();
        topleftWindow.setName(TOP_LEFT);
        TabWindow toprightWindow = new TabWindow();
        toprightWindow.setName(TOP_RIGHT);
        TabWindow bottomleftWindow = new TabWindow();
        bottomleftWindow.setName(BOTTOM_LEFT);
        TabWindow bottomrightWindow = new TabWindow();
        bottomrightWindow.setName(BOTTOM_RIGHT);

        SplitWindow leftWindow = new SplitWindow(false, 0.7f, topleftWindow,
                bottomleftWindow);
        SplitWindow rightWindow = new SplitWindow(false, 0.8f, toprightWindow,
                bottomrightWindow);

        root.setWindow(new SplitWindow(true, 0.25f, leftWindow, rightWindow));

        return root;
    }

    public void addComponent(StudioComponent component,
            final String viewPosition) {
        int id = registerComponent(component);
        final View view = createView(component, id);
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                showView(view, viewPosition);
            }
        });
    }

    private void showView(View view, String viewPosition) {
        TabWindow tabWindow = (TabWindow) getDockingWindow(rootWindow,
                viewPosition);
        if (tabWindow == null) {
            tabWindow = new TabWindow();
            tabWindow.setName(TOP_RIGHT);
            if (rootWindow.getChildWindowCount() == 0) {
                rootWindow.setWindow(tabWindow);
            } else {
                System.err.println(rootWindow.getChildWindowCount());
                SplitWindow splitWindow = new SplitWindow(true, rootWindow
                        .getWindow(), tabWindow);
                rootWindow.setWindow(splitWindow);
            }
        }
        tabWindow.addTab(view);
        view.requestFocus();
        rootWindow.revalidate();
    }

    private DockingWindow getDockingWindow(DockingWindow dockingWindow,
            String string) {
        if (string.equals(dockingWindow.getName())) {
            return dockingWindow;
        }

        for (int i = 0; i < dockingWindow.getChildWindowCount(); i++) {
            DockingWindow found = getDockingWindow(dockingWindow
                    .getChildWindow(i), string);
            if (found != null) {
                return found;
            }
        }

        return null;
    }
}
