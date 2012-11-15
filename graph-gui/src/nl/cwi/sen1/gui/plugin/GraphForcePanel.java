package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import nl.cwi.sen1.util.Preferences;
import prefuse.util.force.Force;
import prefuse.util.force.ForceSimulator;

/* A panel with sliders to configure a ForceSimulator. Adapted from
 * the prefuse implementation. 
 *
 */
public class GraphForcePanel extends JPanel {
    private ForceSimulator fsim;

    public GraphForcePanel(ForceSimulator fsim, Preferences prefs) {
        this.fsim = fsim;
        this.setBackground(Color.WHITE);
        initUI(prefs);
    }

    private void initUI(Preferences prefs) {
        this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        Force[] forces = fsim.getForces();
        // create a bordered box for every force, containing a
        // configurator for every parameter of that force
        for (int i = 0; i < forces.length; i++) {
            Force f = forces[i];
            Box box = new Box(BoxLayout.Y_AXIS);

            // We use the class name and the parameter name to get
            // properties from the preferences
            String name = f.getClass().getName();
            name = name.substring(name.lastIndexOf(".") + 1);

            String label = prefs.getString("force." + name + ".label");
            box.setBorder(BorderFactory.createTitledBorder(label));

            for (int j = 0; j < f.getParameterCount(); j++) {
                String parName = f.getParameterName(j);
                final float min = prefs.getFloat("force." + name + "."
                        + parName + ".min");
                final float max = prefs.getFloat("force." + name + "."
                        + parName + ".max");
                final float def = prefs.getFloat("force." + name + "."
                        + parName + ".default");

                final JSlider slider = createSlider(f, j, min, max, def);

                final String parLabel = prefs.getString("force." + name + "."
                        + parName + ".label");
                JLabel tag = new JLabel(parLabel);
                tag.setPreferredSize(new Dimension(100, 20));
                tag.setMaximumSize(new Dimension(100, 20));
                tag.setToolTipText("click to return to default");
                tag.addMouseListener(new MouseAdapter() {
                    public void mouseClicked(MouseEvent e) {
                        slider.setValue(percentage(def, min, max));
                    }
                });

                Box paramBox = new Box(BoxLayout.X_AXIS);
                paramBox.add(tag);
                paramBox.add(Box.createHorizontalStrut(10));
                paramBox.add(Box.createHorizontalGlue());
                paramBox.add(slider);
                box.add(paramBox);
            }
            this.add(box);
        }
        this.add(Box.createVerticalGlue());
    }

    private static int percentage(float value, float min, float max) {
        // first normalize the range to start at zero
        max = max - min;

        // then compute the percentage
        value = value - min;
        return (int) ((value / max) * 100);
    }

    private static float value(int percentage, float min, float max) {
        float value;
        // first normalize the range to start at zero
        max = max - min;

        // compute the value
        value = (((float) percentage) / 100) * max;

        // shift range back
        value += min;

        return value;
    }

    private JSlider createSlider(Force f, int param, final float min,
            final float max, final float def) {
        final JSlider slider = new JSlider(0, 100);
        slider.setBackground(Color.WHITE);

        // We store both a reference to the force and the index of the property
        // in the widget
        slider.putClientProperty("force", f);
        slider.putClientProperty("param", new Integer(param));
        slider.setToolTipText("" + def);
        slider.setValue(percentage(def, min, max));

        slider.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent event) {
                JSlider s = (JSlider) event.getSource();

                // retrieve the force object, and the index of the property we
                // want
                Force f = (Force) s.getClientProperty("force");
                Integer param = (Integer) s.getClientProperty("param");

                // forward the new value to the force, and update the tooltip
                float val = value(s.getValue(), min, max);
                f.setParameter(param.intValue(), val);
                s.setToolTipText("" + val);
            }
        });

        return slider;
    }
}