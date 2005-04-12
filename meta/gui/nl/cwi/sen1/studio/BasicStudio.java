package nl.cwi.sen1.studio;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JTabbedPane;
import javax.swing.SwingUtilities;

import aterm.ATerm;
import aterm.pure.PureFactory;

public class BasicStudio extends JFrame implements Studio, UserInterfaceTif {

  private PureFactory factory;
  private UserInterfaceBridge bridge;
  private JTabbedPane tabs;

  public static final void main(String args[]) throws IOException {
    /*
    try {
      UIManager.setLookAndFeel("com.sun.java.swing.plaf.gtk.GTKLookAndFeel");
    } catch(Exception e) {
      System.err.println("Could not setLookAndFeel: " + e);
    }
    JFrame.setDefaultLookAndFeelDecorated(true);
    */
    new BasicStudio(args);
  }

  public BasicStudio(String[] args) throws IOException {

    factory = new PureFactory();
    makeStudioVisible();

    bridge = new UserInterfaceBridge(factory, this);
    bridge.init(args);

    addWindowListener(new WindowAdapter(){
        public void windowClosing(WindowEvent e) {
	  System.err.println("windowClosing: " + e);
	  bridge.postEvent(factory.make("quit"));
	  System.exit(0);
	}
    });

    bridge.connect();
    //bridge.setLockObject(getTreeLock());
    bridge.run();
  }

  private void makeStudioVisible() {
    setLocationByPlatform(true);
    setLayout(new BorderLayout());
    tabs = new JTabbedPane();
    add(tabs, BorderLayout.CENTER);
    setPreferredSize(new Dimension(400, 200));
    pack();
    setVisible(true);
  }

  public int getPort() {
    return bridge.getPort();
  }

  public InetAddress getAddress() {
    return bridge.getAddress();
  }

  public void addComponent(final JComponent component) {
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
	System.err.println("adding: " + component);
	tabs.add(component);
	pack();
	repaint();
      }
    });
  }

  public void removeComponent(final JComponent component) {
    SwingUtilities.invokeLater(new Runnable() {
      public void run() {
	tabs.remove(component);
	pack();
	repaint();
      }
    });
  }

  public void loadJar(String jarName) {
    System.err.println("loadJar: " + jarName);
    URL url = null;
    try {
      url = new URL(jarName);
    }
    catch (MalformedURLException e) {
      System.err.println("Invalid URL: " + jarName);
      System.exit(1);
    }

    JarClassLoader loader = new JarClassLoader(url);
    String name = null;
    try {
      name = loader.getMainClassName();
    }
    catch(IOException e) {
      System.err.println("I/O error while loading JAR file:");
      e.printStackTrace();
      System.exit(1);
    }
    if (name == null) {
      System.err.println("Specified jar file does not contain a 'Main-Class'"
	  + " manifest attribute");
      System.exit(1);
    }

    try {
      Class cl = loader.loadClass(name);
      spawn((StudioComponent)cl.newInstance());
    }
    catch (Exception e) {
      System.err.println("Failed to create instance: " + e);
    }
  }

  private void spawn(final StudioComponent component) {
    Thread thread = new Thread(new Runnable() {
      public void run() {
	component.initStudioComponent(BasicStudio.this);
      }
    });
    thread.setName(component.getName());
    thread.start();
  }

  public void loadClass(String urlName, String className) {
    System.err.println("loadClass: " + className);
    try {
      URLClassLoader loader = new URLClassLoader(new URL[] {new URL(urlName)});
      JComponent instance;
      instance = (JComponent) loader.loadClass(className).newInstance();
      add(instance, BorderLayout.NORTH);
      pack();
    }
    catch(Exception e) {
      System.err.println("loadClass: exception: " + e);
    }
  }

  public void recTerminate(ATerm t) {
    System.err.println("recTerminate: " + t);
  }
}
