package nl.cwi.sen1.gui;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.util.HashMap;
import java.util.Map;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JComponent;

public class StatusBar extends Box {
    private Toolkit kit;

    private Dimension screenSize;
    
    private Map components;

    public StatusBar() {
        super(BoxLayout.X_AXIS);

        kit = Toolkit.getDefaultToolkit();
        screenSize = kit.getScreenSize();
        components = new HashMap();
    }

    public void add(JComponent c, double size) {
        c.setPreferredSize(new Dimension((int) (size * screenSize.width), 22));
        c.setBorder(BorderFactory.createLoweredBevelBorder());
        add(c);
    }

    public void add(JComponent c, double size, String name) {
        components.put(name, c);
        add(c, size);
    }
    
    public JComponent getComponent(String name) {
        return (JComponent) components.get(name);
    }
}
