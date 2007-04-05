package examples.swing.flowershop;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Component;
import javax.swing.border.TitledBorder;
import javax.swing.BorderFactory;
import java.awt.Container;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 * This class demonstrates manipulation of inherited objects and manipulation of
 * publically-accessible components of included classes.
 * 
 * This class extends ShopFrame, which has several accessible inherited objects
 * (shopPanel, shopLabel, and the buttons at the bottom of the frame).
 * Properties can be set on these objects (eg, the border and layout manager of
 * the shopPanel) and elements can also be added to them (eg, FlowerPanels are
 * added to the shopPanel). Also, events can be listened to on inherited objects
 * (eg, the "Checkout" button's action event is listened to in this class).
 * 
 * The FlowerPanels which are added to the shopPanel can also be manipulated
 * (eg, the label's text can be changed) and methods can be called on them (eg,
 * calling getText on the quantityTextField).
 * 
*/
public class FlowerShop extends ShopFrame {
	private FlowerPanel flowerPanel1;

	private FlowerPanel flowerPanel2;

	private FlowerPanel flowerPanel3;

	private FlowerPanel flowerPanel4;

	/**
	 * Auto-generated main method to display this JFrame
	 */
	public static void main(String[] args) {
		FlowerShop inst = new FlowerShop();
		inst.setVisible(true);
	}

	public FlowerShop() {
		super();
		initGUI();
	}

	private void initGUI() {
		try {

			this.setSize(550, 280);
			this.jButton2.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent evt) {
					System.out.println("CHECKOUT "
							+ flowerPanel1.quantityTextField.getText()
							+ " Petunias.");
				}
			});

			BoxLayout shopPanelLayout = new BoxLayout(this.shopPanel,
					javax.swing.BoxLayout.Y_AXIS);
			this.shopPanel.setBorder(BorderFactory.createTitledBorder(null,
					"Flowers", TitledBorder.LEADING, TitledBorder.TOP,
					new java.awt.Font("Dialog", 1, 12), new java.awt.Color(0,
							0, 0)));
			this.shopPanel.setLayout(shopPanelLayout);

			flowerPanel1 = new FlowerPanel();
			flowerPanel1.quantityTextField.setText("0");
			flowerPanel1.getFlowerLabel().setText("Musa Basjoo");
			this.shopPanel.add(flowerPanel1);
			flowerPanel1.setFlowerFamily(FlowerPanel.BANANA);

			flowerPanel2 = new FlowerPanel();
			flowerPanel2.quantityTextField.setText("0");
			flowerPanel2.getFlowerLabel().setText("Autumn Gold");
			this.shopPanel.add(flowerPanel2);
			flowerPanel2.setFlowerFamily(FlowerPanel.SUNFLOWER);

			flowerPanel4 = new FlowerPanel();
			flowerPanel4.quantityTextField.setText("0");
			flowerPanel4.getFlowerLabel().setText("Spring Glory");
			this.shopPanel.add(flowerPanel4);
			flowerPanel4.setFlowerFamily(FlowerPanel.CLEMATIS);

			flowerPanel3 = new FlowerPanel();
			flowerPanel3.quantityTextField.setText("0");
			flowerPanel3.getFlowerLabel().setText("English Blue");
			this.shopPanel.add(flowerPanel3);
			flowerPanel3.setFlowerFamily(FlowerPanel.HOLLYHOCK);

			this.shopLabel.setText("The Flower Shop");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
