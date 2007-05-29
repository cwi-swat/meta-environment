package nl.dancingbear.visplugin;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JLabel;
import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.types.RTuple;

/**
 * The ExampleVisualizationWindow class represents an example implementation for a plugin window.
 * @author  Aldert Boerhoop
 * @date    20-2-2007
 */
public class ExampleVisualizationWindow extends VisualizationPluginWindow {

    public JPanel render(RTuple fact) {

        JPanel controlArea;

        controlArea = new JPanel(new GridLayout(3, 1));
        controlArea.add(new JLabel("Dit is een brute plugin!!"));
        controlArea.setPreferredSize(new Dimension(400, 0));
        controlArea.setBorder(BorderFactory.createLineBorder (Color.blue, 2));
        controlArea.setBackground(Color.white);

        return controlArea;
    }

}
