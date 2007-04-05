package examples.swing.flowershop;

import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import java.awt.Insets;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.BorderLayout;
import javax.swing.BorderFactory;
import javax.swing.border.BevelBorder;
import javax.swing.border.TitledBorder;

public class ShopFrame extends javax.swing.JFrame {
	public JLabel shopLabel;
	public JPanel shopPanel;
	public JButton jButton4;
	public JButton jButton3;
	public JButton jButton2;
	public JButton jButton1;

	/**
	* Auto-generated main method to display this JFrame
	*/
	public static void main(String[] args) {
		ShopFrame inst = new ShopFrame();
		inst.setVisible(true);
	}
	
	public ShopFrame() {
		super();
		initGUI();
	}
	
	private void initGUI() {
		try {
			GridBagLayout thisLayout = new GridBagLayout();
			
			thisLayout.columnWeights = new double[] {0.1,0.1,0.1,0.1};
			thisLayout.columnWidths = new int[] {7,7,7,7};
			
			thisLayout.rowWeights = new double[] {0.1,0.1,0.1,0.1};
			thisLayout.rowHeights = new int[] {7,7,7,7};
			this.getContentPane().setLayout(thisLayout);
			this.setSize(382, 283);
			
			
			shopLabel = new JLabel();
			this.getContentPane().add(shopLabel, new GridBagConstraints(0, 0, 4, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.HORIZONTAL, new Insets(0, 0, 0, 0), 0, 0));
			shopLabel.setText("$SHOP$");
			shopLabel.setHorizontalTextPosition(SwingConstants.CENTER);
			shopLabel.setHorizontalAlignment(SwingConstants.CENTER);
			
			shopPanel = new JPanel();
			this.getContentPane().add(shopPanel, new GridBagConstraints(0, 1, 4, 2, 0.0, 1.0, GridBagConstraints.CENTER, GridBagConstraints.BOTH, new Insets(0, 0, 0, 0), 0, 0));
			shopPanel.setBorder(BorderFactory.createTitledBorder(null, "$Items$", TitledBorder.LEADING, TitledBorder.TOP, new java.awt.Font("Dialog",1,12), new java.awt.Color(0,0,0)));
			shopPanel.setDoubleBuffered(false);
			
			jButton1 = new JButton();
			this.getContentPane().add(jButton1, new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
			jButton1.setText("Cancel");
			jButton1.setPreferredSize(new java.awt.Dimension(90, 30));
			
			jButton2 = new JButton();
			this.getContentPane().add(jButton2, new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
			jButton2.setText("Checkout");
			jButton2.setPreferredSize(new java.awt.Dimension(90, 30));
			
			jButton3 = new JButton();
			this.getContentPane().add(jButton3, new GridBagConstraints(2, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
			jButton3.setText("Add");
			jButton3.setPreferredSize(new java.awt.Dimension(90, 30));
			
			jButton4 = new JButton();
			this.getContentPane().add(jButton4, new GridBagConstraints(3, 3, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE, new Insets(0, 0, 0, 0), 0, 0));
			jButton4.setText("Remove");
			jButton4.setPreferredSize(new java.awt.Dimension(90, 30));

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
