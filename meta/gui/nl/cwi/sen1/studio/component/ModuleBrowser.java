package nl.cwi.sen1.studio.component;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

import nl.cwi.sen1.studio.Studio;
import nl.cwi.sen1.studio.StudioComponent;

public class ModuleBrowser implements StudioComponent {

	public String getName() {
		return "ModuleBrowser";
	}

	public void initStudioComponent(final Studio studio) {
		final JButton button = new JButton("Hit me!");
		button.setName("ModuleBrowser");
		final int id = studio.addComponent(button);
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.err.println("Button was pressed!");
				studio.removeComponent(id);
			}
		});
	}

}
