package examples.swing.flowershop;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.HierarchyEvent;
import java.awt.event.HierarchyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.beans.Customizer;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.SwingConstants;
import javax.swing.border.BevelBorder;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.JScrollPane;
import javax.swing.border.EtchedBorder;

public class FlowerPanelCustomizer extends javax.swing.JPanel implements
		Customizer {

	private FlowerPanel beanPanel;

	private JPanel jPanel1;

	private JButton applyButton;

	private JTextArea jTextArea1;

	private JScrollPane jScrollPane1;

	private JPanel jPanel2;

	private JLabel jLabel1;

	private JFrame frame;

	public FlowerPanelCustomizer() {
		initGUI();
	}

	/**
	* This method demonstrates setting a property in the bean we are customizing,
	* and alsoindicates how to force Jigloo to update all the code for the bean.
	*/
	protected void applyButtonMouseReleased(MouseEvent evt) {
		log("Changing flower family from "+beanPanel.getFlowerFamily()+" to Clematis");
		//fire a property change event - Jigloo detects this and updates the code
		//If you want Jigloo to update *all* the code for the bean that you are customizing,
		//and update it's display of the bean, then call firePropertyChange("UPDATE","old", "new");
		firePropertyChange("flowerFamily", beanPanel.getFlowerFamily(), FlowerPanel.CLEMATIS);
	}

	/**
	 * Initializes the GUI. Auto-generated code - any changes you make will
	 * disappear.
	 */
	public void initGUI() {
		try {
			preInitGUI();

			BorderLayout thisLayout = new BorderLayout();
			this.setLayout(thisLayout);
			thisLayout.setHgap(0);
			thisLayout.setVgap(0);
			{
				jLabel1 = new JLabel();
				this.add(jLabel1, BorderLayout.NORTH);
				jLabel1.setText("Customizer Panel");
				jLabel1.setHorizontalAlignment(SwingConstants.CENTER);
				jLabel1.setBorder(new EmptyBorder(new Insets(4, 4, 4, 4)));
			}
			{
				jPanel2 = new JPanel();
				this.add(jPanel2, BorderLayout.CENTER);
				jPanel2.setPreferredSize(new java.awt.Dimension(333, 131));
				jPanel2.setBorder(new CompoundBorder(new EmptyBorder(
						new Insets(8, 16, 8, 16)), new EtchedBorder(
						BevelBorder.LOWERED, null, null)));
				BorderLayout jPanel2Layout = new BorderLayout();
				jPanel2.setLayout(jPanel2Layout);
				{
					jScrollPane1 = new JScrollPane();
					jPanel2.add(jScrollPane1, BorderLayout.CENTER);
					{
						jTextArea1 = new JTextArea();
						jScrollPane1.setViewportView(jTextArea1);
					}
				}
			}
			{
				jPanel1 = new JPanel();
				this.add(jPanel1, BorderLayout.SOUTH);
				jPanel1.setBorder(new EmptyBorder(new Insets(4, 4, 8, 4)));
				GridBagLayout jPanel1Layout = new GridBagLayout();
				jPanel1Layout.columnWidths = new int[] { 1, 1, 1, 1, 1, 1, 1 };
				jPanel1Layout.rowHeights = new int[] { 1 };
				jPanel1Layout.columnWeights = new double[] { 0.1, 0.1, 0.1,
						0.1, 0.1, 0.1, 0.1 };
				jPanel1Layout.rowWeights = new double[] { 0.1 };
				jPanel1.setLayout(jPanel1Layout);
				{
					applyButton = new JButton();
					jPanel1.add(applyButton, new GridBagConstraints(5, 0, 1, 1,
							0.0, 0.0, GridBagConstraints.CENTER,
							GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0,
							0));
					applyButton.setText("Set as Clematis");
					applyButton.addMouseListener(new MouseAdapter() {
						public void mouseReleased(MouseEvent evt) {
							applyButtonMouseReleased(evt);
						}
					});
				}
			}
			this.setPreferredSize(new java.awt.Dimension(341, 236));

			postInitGUI();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/** Add your pre-init code in here */
	public void preInitGUI() {
	}

	/** Add your post-init code in here */
	public void postInitGUI() {
		addHierarchyListener(new HierarchyListener() {
			public void hierarchyChanged(HierarchyEvent e) {
				JFrame jf = getCustomizerFrame();
				if (jf != null && frame == null) {
					frame = jf;
					log("Customizer is in a: " + frame.getClass().getName());
					frame.setTitle("FlowerPanel Customizer");
					frame.setLocation(50, 50);
				}
			}
		});
	}

	/** Customizer specific methods */
	public void setObject(Object bean) {
		// Cast from object to your bean type
		beanPanel = (FlowerPanel) bean;
		log("Our bean is a: " + beanPanel.getClass().getName());
	}


	protected JFrame getCustomizerFrame() {
		Container o = this;
		while (o != null && !(o instanceof JFrame)) {
			o = o.getParent();
		}
		if (o == null) {
			log("Customizer is not in a JFrame yet");
		}
		return (JFrame) o;
	}

	public void log(String s) {
		jTextArea1.append(s + "\n");
	}

	/** Auto-generated main method */
	public static void main(String[] args) {
		showGUI();
	}

	/**
	 * This static method creates a new instance of this class and shows it
	 * inside a new JFrame, (unless it is already a JFrame).
	 */
	public static void showGUI() {
		try {
			javax.swing.JFrame frame = new javax.swing.JFrame();
			FlowerPanelCustomizer inst = new FlowerPanelCustomizer();
			frame.setContentPane(inst);
			frame.getContentPane().setSize(inst.getSize());
			frame
					.setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
			frame.pack();
			frame.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
