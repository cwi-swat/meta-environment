package nl.cwi.sen1.gui;

import javax.swing.JMenu;

import toolbus.AbstractTool;
import aterm.ATermFactory;

public interface Studio {
	public ATermFactory getATermFactory();

	public void connect(String toolName, AbstractTool tool);

	public void addComponent(StudioComponent component);

	public void removeComponent(StudioComponent component);

	public void addComponentMenu(StudioComponent component, JMenu menu);
}