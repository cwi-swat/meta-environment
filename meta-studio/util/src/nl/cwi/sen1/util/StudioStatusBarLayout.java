/**
 * 
 */
package nl.cwi.sen1.util;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Insets;
import java.awt.LayoutManager2;
import java.util.HashMap;
import java.util.Map;

public class StudioStatusBarLayout implements LayoutManager2 {
    private Map<Component, StudioStatusBarConstraints> constraints = new HashMap<Component, StudioStatusBarConstraints>();

    public void addLayoutComponent(String name, Component comp) {
        addLayoutComponent(comp, null);
    }

    public void addLayoutComponent(Component comp, Object constraint) {
        constraints.put(comp, (StudioStatusBarConstraints) constraint);
    }

    public void removeLayoutComponent(Component comp) {
        constraints.remove(comp);
    }

    public Dimension preferredLayoutSize(Container parent) {
        Dimension dim = new Dimension();
        for (Component comp : constraints.keySet()) {
            Dimension d = comp.getPreferredSize();
            StudioStatusBarConstraints c = constraints.get(comp);
            if (c != null) {
                Insets i = c.getInsets();
                d.width += i.left + i.right;
                d.height += i.top + i.bottom;
            }
            dim.height = Math.max(dim.height, d.height);
            dim.width += d.width;
        }

        Insets insets = parent.getInsets();
        dim.width += insets.left + insets.right;
        dim.height += insets.top + insets.bottom;

        return dim;
    }

    public Dimension minimumLayoutSize(Container parent) {
        return preferredLayoutSize(parent);
    }

    public Dimension maximumLayoutSize(Container target) {
        return new Dimension(Integer.MAX_VALUE, Integer.MAX_VALUE);
    }

    public float getLayoutAlignmentX(Container target) {
        return 0.5f;
    }

    public float getLayoutAlignmentY(Container target) {
        return 0.5f;
    }

    public void invalidateLayout(Container target) {
    }

    public void layoutContainer(Container parent) {
        double maxWeight = 0.0;
        for (Component comp : parent.getComponents()) {
            if (comp.isVisible()) {
                StudioStatusBarConstraints c = constraints.get(comp);
                if (c != null) {
                    maxWeight += c.getWeight();
                }
            }
        }
        if (maxWeight == 0) {
            maxWeight = 1.0;
        }

        Insets parentInsets = parent.getInsets();
        int availableWidth = parent.getWidth()
                - preferredLayoutSize(parent).width;
        int nextX = parentInsets.left;
        int height = parent.getHeight() - parentInsets.top
                - parentInsets.bottom;

        for (Component comp : parent.getComponents()) {
            if (comp.isVisible()) {
                StudioStatusBarConstraints c = constraints.get(comp);
                double weight = 0.0;
                Insets insets = new Insets(0, 0, 0, 0);
                if (c != null) {
                    weight = c.getWeight();
                    insets = c.getInsets();
                }
                
                int weightedWidth = 0;
                if (availableWidth > 0) {
                    weightedWidth = (int) ((weight/maxWeight) * availableWidth);
                }
                availableWidth -= weightedWidth;

                int width = comp.getPreferredSize().width + weightedWidth;

                int x = nextX + insets.left;
                int y = parentInsets.top + insets.top;
                comp.setSize(width, height);
                comp.setLocation(x, y);
                nextX = x + width + insets.right;
            }
        }
    }
}