package nl.cwi.sen1.gui;

import toolbus.AbstractTool;
import aterm.ATermFactory;

public interface Studio {
	public ATermFactory getATermFactory();

	public void connect(String toolName, AbstractTool tool);

	public void addComponent(StudioComponent component);
	
	public void removeComponent(StudioComponent component);
}