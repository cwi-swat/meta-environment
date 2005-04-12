package nl.cwi.sen1.studio;

import java.net.InetAddress;

import javax.swing.JComponent;

public interface Studio {
	public InetAddress getAddress();

	public int getPort();

	public void addComponent(JComponent component);

	public void removeComponent(JComponent component);
}
