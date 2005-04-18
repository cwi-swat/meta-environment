package nl.cwi.sen1.gui;

import javax.swing.JComponent;

import toolbus.AbstractTool;
import aterm.ATermFactory;

public interface Studio {
	public ATermFactory getFactory();

	public void connect(String toolName, AbstractTool tool);

	public void addComponent(JComponent component);

	public void removeComponent(JComponent component);

}
