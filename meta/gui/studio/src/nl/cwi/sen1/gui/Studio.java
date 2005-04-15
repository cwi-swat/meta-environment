package nl.cwi.sen1.gui;

import java.net.InetAddress;

import javax.swing.JComponent;

import aterm.ATermFactory;

public interface Studio {
	public ATermFactory getFactory();

	public InetAddress getAddress();

	public int getPort();

	public void addComponent(JComponent component);

	public void removeComponent(JComponent component);
}
