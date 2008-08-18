package nl.cwi.sen1.visplugin.treeplugin;

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

/**
 * @author Qais
 *
 */
public class TreePlugin {
	static String m_testRstore = "/test.rstore";
	static final Font m_font = new Font("Tahoma", 0, 11);
    static RTuple m_fact;
    static HashMap<String, Integer> metricsMaxValues;

    public TreePlugin(RTuple fact) {
    	m_fact = fact;
    }

    public JPanel getPanel(){
        return tree();
    }


    public static JPanel tree() {

    	Tree tree= null;
		try {
    	TreeBuilder treeBuilder = new TreeBuilder();
    	tree = treeBuilder.buildTreeFromRStore(m_fact);
	    metricsMaxValues = treeBuilder.getMetricsMaxValues();
		} catch (Exception e) {
			e.printStackTrace();
		}

        // create a new tree
        final TreeVisualization m_treeVisualization = new TreeVisualization(tree, metricsMaxValues);

        final JPanel codeOverviewPanel = new JPanel(new BorderLayout());
        final JTextPane codeOverviewArea = new JTextPane();
        final JScrollPane scrollPane = new JScrollPane(codeOverviewArea);
//        scrollPane.setBorder( new LineBorder(Color.ORANGE, 2) );
        codeOverviewArea.setEditable(false);
        codeOverviewPanel.add(scrollPane,BorderLayout.CENTER);

        final JPanel metricViewPanel = new JPanel(new BorderLayout());
        final JTextArea metricArea = new JTextArea();
        metricArea.setEditable(false);
        metricArea.setFont(m_font);
        final JScrollPane scrollmetricArea = new JScrollPane(metricArea);
        scrollmetricArea.setBorder( new LineBorder(Color.WHITE,1));
        metricViewPanel.add(scrollmetricArea,BorderLayout.CENTER);

        final JPanel settingPanel = new JPanel(new BorderLayout());

        JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 30, 2);
        slider.setBorder(BorderFactory.createTitledBorder("Hierarchy space"));
        slider.setMajorTickSpacing(5);
        slider.setMinorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        slider.addChangeListener(new SliderChangeListener(m_treeVisualization));
        settingPanel.add(slider, BorderLayout.NORTH);

        final JPanel comboPanel = new JPanel(new BorderLayout());
        final JPanel TopcomboPanel = new JPanel(new BorderLayout());

        JComboBox metricFirstColorComboBox = new JComboBox(m_treeVisualization.getOptionalMetrics());
        Border etchedBdr = BorderFactory.createEmptyBorder(0,0,0,0);
        Border titledBdr = BorderFactory.createTitledBorder(etchedBdr, "Red Color representation");
        metricFirstColorComboBox.setBorder(titledBdr);
        metricFirstColorComboBox.setBackground(new Color(230,100,100));
        TopcomboPanel.add(metricFirstColorComboBox, BorderLayout.NORTH);

        JComboBox metricSecondColorComboBox = new JComboBox(m_treeVisualization.getOptionalMetrics());
        etchedBdr = BorderFactory.createEmptyBorder(0,0,0,0);
        titledBdr = BorderFactory.createTitledBorder(etchedBdr, "Green Color representation");
        metricSecondColorComboBox.setBorder(titledBdr);
        metricSecondColorComboBox.setBackground(new Color(64,255,112));
        TopcomboPanel.add(metricSecondColorComboBox, BorderLayout.CENTER);

        JComboBox metricThirdColorComboBox = new JComboBox(m_treeVisualization.getOptionalMetrics());
        etchedBdr = BorderFactory.createEmptyBorder(0,0,0,0);
        titledBdr = BorderFactory.createTitledBorder(etchedBdr, "Blue Color representation");
        metricThirdColorComboBox.setBorder(titledBdr);
        metricThirdColorComboBox.setBackground(new Color(167,198,255));
		TopcomboPanel.add(metricThirdColorComboBox, BorderLayout.SOUTH);
        comboPanel.add(TopcomboPanel, BorderLayout.NORTH);

        JComboBox metricNumberComboBox = new JComboBox(m_treeVisualization.getOptionalMetrics());
        metricNumberComboBox.setBorder(BorderFactory.createTitledBorder("Number representation"));
        comboPanel.add(metricNumberComboBox, BorderLayout.CENTER);

        JComboBox metricTextureComboBox = new JComboBox(m_treeVisualization.getOptionalMetrics());;
        metricTextureComboBox.setBorder(BorderFactory.createTitledBorder("Texture representation"));
        comboPanel.add(metricTextureComboBox, BorderLayout.SOUTH);
        settingPanel.add(comboPanel, BorderLayout.CENTER);

        metricViewPanel.add(settingPanel, BorderLayout.NORTH);
   //     metricViewPanel.setBorder( new LineBorder(Color.ORANGE, 2) );
        metricViewPanel.setBackground(Color.WHITE);

        JPanel searchP = new JPanel(new BorderLayout());

		final JSearchPanel search = m_treeVisualization.getSearchQuery().createSearchPanel();
		search.setShowResultCount(true);
		search.setLabelText("");
		search.setFont(new Font("", Font.PLAIN, 11));

		JButton searchButton = new JButton("Search");
		searchButton.addActionListener(new ActionListener(){
		public void actionPerformed(ActionEvent arg0) {
			m_treeVisualization.update();
			}
		});
		searchP.add(search, BorderLayout.CENTER);
		searchP.add(searchButton, BorderLayout.EAST);
        metricViewPanel.add(searchP, BorderLayout.SOUTH);


        JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT,metricViewPanel, codeOverviewPanel);
        splitPane.setResizeWeight(0.3D);
        Box box2 = UILib.getBox(new Component[]{splitPane}, true, 0, 0, 0);

        TreeNodeControlAdapter treeMapNodeControlAdapter = new TreeNodeControlAdapter(m_treeVisualization, tree, codeOverviewArea, metricArea);
        m_treeVisualization.addControlListener(treeMapNodeControlAdapter);
        codeOverviewArea.addMouseListener(new CodeOverviewMouseListener(codeOverviewArea, treeMapNodeControlAdapter));

        metricFirstColorComboBox.addActionListener( new FirstColorComboBoxListener(m_treeVisualization, treeMapNodeControlAdapter));
        metricSecondColorComboBox.addActionListener( new SecondColorComboBoxListener(m_treeVisualization, treeMapNodeControlAdapter));
        metricThirdColorComboBox.addActionListener( new ThirdColorComboBoxListener(m_treeVisualization, treeMapNodeControlAdapter));
        metricNumberComboBox.addActionListener( new NumberComboBoxActionListener(m_treeVisualization, treeMapNodeControlAdapter));
        metricTextureComboBox.addActionListener( new TextureComboBoxActionListener(m_treeVisualization, treeMapNodeControlAdapter));

        JPanel windowPanel = new JPanel(new BorderLayout());
        windowPanel.add(box2, BorderLayout.EAST);
        windowPanel.add(m_treeVisualization, BorderLayout.CENTER);
        return windowPanel;
    }


}
