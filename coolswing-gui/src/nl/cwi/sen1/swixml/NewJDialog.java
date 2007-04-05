package nl.cwi.sen1.swixml;

import javax.swing.JFrame;

public class NewJDialog extends javax.swing.JDialog {

	/**
	* Auto-generated main method to display this JDialog
	*/
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		NewJDialog inst = new NewJDialog(frame);
		inst.setVisible(true);
	}
	
	public NewJDialog(JFrame frame) {
		super(frame);
		initGUI();
	}
	
	private void initGUI() {
		try {
			setSize(400, 300);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
