package nl.dancingbear.visbase.factbrowser;

import java.awt.Component;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Enumeration;
import java.util.Iterator;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreePath;

import nl.dancingbear.visbase.factbrowser.data.FactBrowserDataManager;
import nl.dancingbear.visbase.factbrowser.data.RStore;
import nl.dancingbear.visbase.factbrowser.data.RStoreFact;
import nl.dancingbear.visbase.factbrowser.data.VisualisationPlugin;

/**
 * This is the FactBrowserWindow responsible for displaying the tree containing
 * the rstores with all the facts for this RStore. For every fact is displays
 * the possible visualisations
 * 
 * This class has no testUnit because it is mostly GUI Related.
 * 
 * @author Renze de Vries
 * @date 12-02-2007
 * 
 */
public class FactBrowserWindow extends JPanel {
    private static final int INVALID_RSTORE = -1;

    private static final long serialVersionUID = 5095665207477698127L;

    private JScrollPane scrlTreeScroller;

    private JTree treeRstores;

    private DefaultMutableTreeNode rootNode;

    private DefaultTreeModel mdlTree;

    private FactBrowserDataManager m_dataManager;

    private Enumeration<TreePath> expansionState;

    /**
     * The constructor calling the method responsible for building the panel
     * containing the JTree
     * 
     * @author Renze de Vries
     * @date 12-02-2007
     */
    public FactBrowserWindow() {
        initComponents();
        m_dataManager = FactBrowserDataManager.getInstance();
    }

    /**
     * This method is responsible for adding the TreeListener so that a click or
     * event from the tree is responded to by the listener
     * 
     * @param listener
     *            The listener which will respond to events
     * 
     * @author Renze de Vries
     * @date 12-02-2007
     */
    public void addMouseListener(MouseListener listener) {
        treeRstores.addMouseListener(listener);
    }

    /**
     * This method returns the last selected node in the visual tree and returns
     * it to the requestor
     * 
     * @return The last selected node in the tree
     * 
     * @author Renze de Vries
     * @date 20-02-2007
     */
    public DefaultMutableTreeNode getSelectedNode() {
        return (DefaultMutableTreeNode) this.treeRstores
                .getLastSelectedPathComponent();
    }

    /**
     * This method makes it possible to see mutations in the tree when a node is
     * added.
     * 
     * @author Renze de Vries
     * @date 23-02-2007
     */
    public void redrawTree() {
    	storeExpansionState();
        this.mdlTree.reload();
        this.treeRstores.repaint();
        restoreExpansionState();
    }
    
    /**
     * Stores the current expansion state of treeRstores
     */
    private void storeExpansionState() {
		expansionState = treeRstores.getExpandedDescendants(new TreePath(treeRstores
				.getModel().getRoot()));
	}

    /**
	 * Restores the expansion state of treeRstores
     */
	private void restoreExpansionState() {
		if (expansionState != null) {
			while (expansionState.hasMoreElements()) {
				TreePath treePath = expansionState.nextElement();
				treeRstores.expandPath(treePath);
			}
		}
	}

    /**
     * This method will make it possible to display the loaded RStores with the
     * facts contained within the RStore.
     * 
     * @param rstoreName
     *            The name of the RStore
     * @param rstoreFacts
     *            A list containing all the Facts within the RStore
     * 
     * @author Renze de Vries
     * @date 12-02-2007
     */
    public void addRStore(RStore rstoreNode) {
        DefaultMutableTreeNode rstoreTreeNode;

        rstoreTreeNode = getRStoreNode(rstoreNode.getRstoreId());

        // if doesn't exists then create a new
        if (rstoreTreeNode == null) {
            rstoreTreeNode = new DefaultMutableTreeNode(rstoreNode); 
            rootNode.add(rstoreTreeNode);
        } else {
            rstoreTreeNode.removeAllChildren();
        }

        if (rstoreNode.getRstoreId() == INVALID_RSTORE) {
            DefaultMutableTreeNode invalidRStore = new DefaultMutableTreeNode(
                    "Invalid RStore");
            rstoreTreeNode.add(invalidRStore);
        }

        Iterator<RStoreFact> iterator = rstoreNode.getFactNodes().iterator();
        while (iterator.hasNext()) {
            RStoreFact rstoreFactNode = iterator.next();
            rstoreTreeNode.add(rstoreFactNode);
        }

        redrawTree();
    }

    /**
     * Gets the rstore tree node from the tree with a specified rstoreID.
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 19-03-2007
     * 
     * @param rstoreID
     * @return
     */
    public DefaultMutableTreeNode getRStoreNode(int rstoreID) {
        Enumeration enumeration = rootNode.breadthFirstEnumeration();

        while (enumeration.hasMoreElements()) {
            Object element = enumeration.nextElement();
            DefaultMutableTreeNode treeNode = (DefaultMutableTreeNode) element;
            if (treeNode.getUserObject() instanceof RStore) {
                // RStoreTreeNode rstoreNode = (RStoreTreeNode) element;
                // RStore rstoreNode = (RStore) treeNode.getUserObject();

                int nodeRStoreID = m_dataManager.getRStoreID(treeNode);

                if (rstoreID == nodeRStoreID) {
                    return treeNode;
                }
            }
        }

        return null;
    }

    /**
     * Removes a rstore tree node with a specified rstoreID from the tree.
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 19-03-2007
     * 
     * @param rstoreID
     */
    public void removeRStoreTreeNode(int rstoreID) {
        DefaultMutableTreeNode rstoreNode = getRStoreNode(rstoreID);

        if (rstoreNode != null) {
            rstoreNode.removeFromParent();

            redrawTree();
        }
    }

    /**
     * This method builds a JPanel containing the elements to display the Tree
     * with the RStores and nodes. It was generated by a GUI builder.
     * 
     * @author Renze de Vries
     * @date 12-02-2007
     */
    private void initComponents() {
        rootNode = new DefaultMutableTreeNode("ROOT");
        mdlTree = new DefaultTreeModel(rootNode);
        scrlTreeScroller = new JScrollPane();
        treeRstores = new JTree(mdlTree) {
        	public String getToolTipText(MouseEvent e) {
				Object tip = null;
				TreePath path = getPathForLocation(e.getX(), e.getY());
				if (path != null) {
					tip = path.getLastPathComponent();
				}
				return tip == null ? null : tip.toString();
			}
        };
        treeRstores.setRootVisible(false);
        treeRstores.setShowsRootHandles(true);
        treeRstores.setToolTipText("hoi");

        ImageIcon factIcon = new ImageIcon(getClass().getResource(
                "/resources/images/fact.png"));
        ImageIcon visIcon = new ImageIcon(getClass().getResource(
                "/resources/images/vis.png"));
        ImageIcon novisIcon = new ImageIcon(getClass().getResource(
                "/resources/images/novis.png"));
        ImageIcon rstoreIcon = new ImageIcon(getClass().getResource(
                "/resources/images/rstore.png"));

        treeRstores.setCellRenderer(new TreeIconCellRenderer(factIcon, visIcon,
                novisIcon, rstoreIcon));

        setLayout(new GridBagLayout());
        ((GridBagLayout) getLayout()).columnWidths = new int[] { 200, 0 };
        ((GridBagLayout) getLayout()).rowHeights = new int[] { 0, 0 };
        ((GridBagLayout) getLayout()).columnWeights = new double[] { 1.0,
                1.0E-4 };
        ((GridBagLayout) getLayout()).rowWeights = new double[] { 1.0, 1.0E-4 };

        scrlTreeScroller.setViewportView(treeRstores);
        add(scrlTreeScroller, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
                GridBagConstraints.CENTER, GridBagConstraints.BOTH, new Insets(
                        0, 0, 0, 0), 0, 0));
    }

    /**
     * Internal class responsible for painting the icons on the nodes in the
     * Tree. For different types of nodes different icons will be used
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    class TreeIconCellRenderer extends DefaultTreeCellRenderer {
        private static final long serialVersionUID = 7775610665094841024L;

        private Icon factIcon;

        private Icon visIcon;

        private Icon novisIcon;

        private Icon rstoreIcon;

        public TreeIconCellRenderer(Icon factIcon, Icon visIcon,
                Icon novisIcon, Icon rstoreIcon) {
            this.factIcon = factIcon;
            this.visIcon = visIcon;
            this.novisIcon = novisIcon;
            this.rstoreIcon = rstoreIcon;
        }

        public Component getTreeCellRendererComponent(JTree tree, Object value,
                boolean sel, boolean expanded, boolean leaf, int row,
                boolean hasFocus) {

            super.getTreeCellRendererComponent(tree, value, sel, expanded,
                    leaf, row, hasFocus);

            DefaultMutableTreeNode treeNode = (DefaultMutableTreeNode) value;
            Object userObject = treeNode.getUserObject();

            if (value instanceof RStoreFact) {
                setIcon(factIcon);
                setText(((RStoreFact) value).getFactName());
            } else if (userObject instanceof RStore) {
                setIcon(rstoreIcon);
            } else if (userObject instanceof VisualisationPlugin) {
                setIcon(visIcon);
            } else {
                setIcon(novisIcon);
            }

            return this;
        }
    }

    /**
     * Select a node at a given position (X & Y).
     * If no node can be selected the selection of the
     * tree will be cleared.
     * 
     * If we don't do this you can select a node in the
     * tree and at any point you can double click or right
     * click. With this method you need to double click or
     * right click at a specific node.
     * 
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 19-03-2007
     * 
     * @param x
     * @param y
     */
    public void selectNodeAtPosition(int x, int y) {
        int row = treeRstores.getRowForLocation(x, y);

        if (row != INVALID_RSTORE) {
            Rectangle rect = treeRstores.getRowBounds(row);
            if (rect.contains(x, y)) {
                treeRstores.setSelectionRow(row);
                return;
            }
        }

        // No row has been selected so the selection should be cleared.
        treeRstores.clearSelection();
    }
    
    
    /**
     * Get the vertical scrollbar offset.
     * @return Offset integer
     * @author A.Belgraver
     * @date 19-03-2007
     */
    public int getVerticalBarOffset() {
       JScrollBar vScroll = scrlTreeScroller.getVerticalScrollBar();
       return vScroll.getValue();
    }

    /**
     * Get the horizontal scrollbar offset.
     * @return Offset integer
     * @author A.Belgraver
     * @date 19-03-2007 
     */
    public int getHorizontalBarOffset() {
        JScrollBar hScroll = scrlTreeScroller.getHorizontalScrollBar();
        return hScroll.getValue();
    }
    
}
