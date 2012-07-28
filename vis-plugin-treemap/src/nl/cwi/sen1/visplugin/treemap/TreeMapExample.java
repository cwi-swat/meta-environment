package nl.cwi.sen1.visplugin.treemap;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RTupleRtuples;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;
import prefuse.data.Tree;
import prefuse.util.io.IOLib;
import prefuse.util.ui.JSearchPanel;
import prefuse.util.ui.UILib;
import java.util.Vector;

public class TreeMapExample {
	static final String windowsTitle = "Test Treemap";
	static final String  testRstoreFile = "/prefuse.rstore";
	static final String label = "name";
	static int m_padding = 0;
	static final String sizeComboBoxName = "Size representation";
	static final String colorComboBoxName = "Color representation";
	static final String numberComboBoxName = "Number representation";
	static final String textureComboBoxName = "Texture representation";
	static final  LineBorder orangeLineBorder = new LineBorder(Color.ORANGE, 2);
	static final  LineBorder whiteLineBorder = new LineBorder(Color.WHITE, 1);
	static final double splitRatio = 0.4D;
	static HashMap<String, Integer> metricsMaxValues;

    public static void main(String argv[]) {
        UILib.setPlatformLookAndFeel();
        JComponent treemap = Treemap();

        JFrame frame = new JFrame(windowsTitle);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setContentPane(treemap);
        frame.setResizable(false);
        frame.pack();
        frame.setVisible(true);
    }

    /**
     * @return windows-panel with all initiated parts
     */
    public static JComponent Treemap() {

    	Tree tree= null;
    	Factory factory = VisualizationFactorySingleton.getFactoryInstance();
		try {
    	TreeBuilder treeBuilder = new TreeBuilder();
	    InputStream rstoreInputStream;

		rstoreInputStream = IOLib.streamFromString(testRstoreFile);

	    RStore rfact = factory.RStoreFromFile(rstoreInputStream);
	    RTupleRtuples rtuples = rfact.getRtuples();
		RTuple rt = rtuples.getHead();
    	tree = treeBuilder.buildTreeFromRStore(rt);
	    metricsMaxValues = treeBuilder.getMetricsMaxValues();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

        // create a new treemap
        final TreeMapVisualization treemap = new TreeMapVisualization(tree, label, m_padding, metricsMaxValues);

        final JPanel codeOverviewPanel = new JPanel(new BorderLayout());
        final JTextPane codeOverviewArea = new JTextPane();
        final JScrollPane scrollPane = new JScrollPane(codeOverviewArea);
        scrollPane.setBorder(orangeLineBorder);
        codeOverviewArea.setEditable(false);
        codeOverviewPanel.add(scrollPane,BorderLayout.CENTER);


        final JPanel metricViewPanel = new JPanel(new BorderLayout());
        final JTextArea metricArea = new JTextArea();
        final JScrollPane scrollmetricArea = new JScrollPane(metricArea);
        metricViewPanel.setBorder(orangeLineBorder);
        metricArea.setEditable(false);
        metricArea.setFont(new Font("Tahoma", 0, 11));
        scrollmetricArea.setBorder(whiteLineBorder);
        metricViewPanel.add(scrollmetricArea,BorderLayout.CENTER);
        // create a search panel for the tree map

        final JPanel settingPanel = new JPanel(new BorderLayout());

        JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 10, 0);
        slider.setBorder(BorderFactory.createTitledBorder("Hierarchy level"));
        slider.setMajorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        slider.addChangeListener(new SliderChangeListener(treemap, m_padding));
        settingPanel.add(slider, BorderLayout.CENTER);

        final JPanel comboPanel = new JPanel(new BorderLayout());

        final JPanel northComboPanel = new JPanel(new BorderLayout());

        JComboBox sizeComboBox = new JComboBox(treemap.getOptionalMetrics());
        sizeComboBox.setBorder(BorderFactory.createTitledBorder(sizeComboBoxName));
        sizeComboBox.addActionListener( new ActionListener(){
		    public void actionPerformed(ActionEvent e){
			 JComboBox combo = (JComboBox)e.getSource();
		     treemap.updateLayoutSelectedMetric(combo.getSelectedItem().toString());
    		}
		});
        northComboPanel.add(sizeComboBox, BorderLayout.NORTH);

		Vector<String> metrics = treemap.getOptionalMetrics();
		metrics.add(0,"None");

        JComboBox metricColorComboBox = new JComboBox(metrics);
        metricColorComboBox.setBorder(BorderFactory.createTitledBorder(colorComboBoxName));
        metricColorComboBox.setBackground(new Color(230,100,100));
        northComboPanel.add(metricColorComboBox, BorderLayout.CENTER);
        comboPanel.add(northComboPanel, BorderLayout.NORTH);

        JComboBox metricNumberComboBox = new JComboBox(metrics);
        metricNumberComboBox.setBorder(BorderFactory.createTitledBorder(numberComboBoxName));
        comboPanel.add(metricNumberComboBox, BorderLayout.CENTER);

        JComboBox metricTextureComboBox = new JComboBox(metrics);
        metricTextureComboBox.setBorder(BorderFactory.createTitledBorder(textureComboBoxName));
        comboPanel.add(metricTextureComboBox, BorderLayout.SOUTH);

        settingPanel.add(comboPanel, BorderLayout.SOUTH);
        metricViewPanel.add(settingPanel, BorderLayout.NORTH);

        JPanel searchP = new JPanel(new BorderLayout());

		final JSearchPanel search = treemap.getSearchQuery().createSearchPanel();
		search.setShowResultCount(true);
		search.setLabelText("");
		search.setFont(new Font("", Font.PLAIN, 11));

		JButton searchButton = new JButton("Search");
		searchButton.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent arg0) {
			treemap.update();
			}
		});

		searchP.add(search, BorderLayout.CENTER);
		searchP.add(searchButton, BorderLayout.EAST);
        metricViewPanel.add(searchP, BorderLayout.SOUTH);

        JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT,metricViewPanel, codeOverviewPanel);
        splitPane.setResizeWeight(splitRatio);
        Box box2 = UILib.getBox(new Component[]{splitPane}, true, 0, 0, 0);

        //add a controller handler to the treemap
        TreeMapNodeControlAdapter treeMapNodeControlAdapter = new TreeMapNodeControlAdapter(treemap, tree, codeOverviewArea, metricArea);
        treemap.addControlListener(treeMapNodeControlAdapter);
        codeOverviewArea.addMouseListener(new CodeOverviewMouseListener(codeOverviewArea, treeMapNodeControlAdapter));

        metricColorComboBox.addActionListener( new ColorComboBoxActionListener(treemap, treeMapNodeControlAdapter));
        metricNumberComboBox.addActionListener( new NumberComboBoxActionListener(treemap));
        metricTextureComboBox.addActionListener( new TextureComboBoxActionListener(treemap));

        JPanel windowPanel = new JPanel(new BorderLayout());
        windowPanel.add(box2, BorderLayout.EAST);
        windowPanel.add(treemap, BorderLayout.CENTER);


        return windowPanel;
    }

}
