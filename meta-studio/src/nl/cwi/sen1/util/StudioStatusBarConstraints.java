/**
 * 
 */
package nl.cwi.sen1.util;

import java.awt.Insets;

public class StudioStatusBarConstraints {
    Insets insets;

    double weight;

    public StudioStatusBarConstraints(Insets insets) {
        this.insets = insets;
        this.weight = 0.0;
    }

    public StudioStatusBarConstraints(double weight) {
        this.insets = new Insets(0, 0,0,0);
        this.weight = weight;
    }

    public double getWeight() {
        return weight;
    }

    public Insets getInsets() {
        return new Insets(insets.top, insets.left, insets.bottom, insets.right);
    }
}