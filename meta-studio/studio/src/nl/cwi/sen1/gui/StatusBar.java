package nl.cwi.sen1.gui;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.util.HashMap;
import java.util.Map;

import javax.swing.BorderFactory;
import javax.swing.JComponent;
import javax.swing.JPanel;

public class StatusBar extends JPanel {
    private Map<String, JComponent> components;

    public StatusBar() {
        super();
        setLayout(new FlowLayout(FlowLayout.LEADING,0,0));

        components = new HashMap<String, JComponent>();
    }

    public void addComponent(JComponent c, int size) {
        c.setPreferredSize(new Dimension(size, 18));
        c.setBorder(BorderFactory.createLoweredBevelBorder());
        add(c);
    }

    public void add(JComponent c, int size, String name) {
        components.put(name, c);
        addComponent(c, size);
    }

    public JComponent getComponent(String name) {
        return components.get(name);
    }
}
