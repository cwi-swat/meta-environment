package examples.swing.flowershop;

import javax.swing.JPanel;
import javax.swing.JFrame;

import javax.swing.JLabel;
import javax.swing.JTextField;

public class FlowerPanel extends JPanel {
	private JLabel jLabel1;

	private JLabel flowerLabel;

	private JLabel jLabel2;

	private JLabel jLabel3;

	public JTextField quantityTextField;
	
	public static final int UNDEFINED = 0;
	public static final int SUNFLOWER = 1;
	public static final int BANANA = 2;
	public static final int HOLLYHOCK = 3;
	public static final int CLEMATIS = 4;
	
	private int flowerFamily = UNDEFINED;

	/**
	 * Auto-generated main method to display this JPanel inside a new JFrame.
	 */
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.getContentPane().add(new FlowerPanel());
		frame.pack();
		frame.show();
	}

	public FlowerPanel() {
		super();
		initGUI();
	}

	private void initGUI() {
		try {
			jLabel1 = new JLabel();
			this.add(jLabel1);
			jLabel1.setText("Flower:");
			jLabel1.setPreferredSize(new java.awt.Dimension(61, 16));

			jLabel2 = new JLabel();
			this.add(jLabel2);
			jLabel2.setText("(Family)");
			jLabel2.setPreferredSize(new java.awt.Dimension(84, 16));

			flowerLabel = new JLabel();
			this.add(flowerLabel);
			flowerLabel.setText("$NAME$");
			flowerLabel.setPreferredSize(new java.awt.Dimension(90, 16));

			jLabel3 = new JLabel();
			this.add(jLabel3);
			jLabel3.setText("Quantity:");
			jLabel3.setPreferredSize(new java.awt.Dimension(61, 16));

			quantityTextField = new JTextField(10);

			this.add(quantityTextField);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * @return Returns the flowerLabel.
	 */
	public JLabel getFlowerLabel() {
		return flowerLabel;
	}

	public int getFlowerFamily() {
		return flowerFamily;
	}

	public void setFlowerFamily(int flowerFamily) {
		this.flowerFamily = flowerFamily;
		switch (flowerFamily) {
		case UNDEFINED:
			jLabel2.setText("( none )");
			break;
		case BANANA:
			jLabel2.setText("( banana )");
			break;
		case SUNFLOWER:
			jLabel2.setText("( sunflower )");
			break;
		case HOLLYHOCK:
			jLabel2.setText("( hollyhock )");
			break;
		case CLEMATIS:
			jLabel2.setText("( clematis )");
			break;
		}
	}
}
