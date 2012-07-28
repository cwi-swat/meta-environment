package nl.cwi.sen1.util;

import java.awt.Component;
import java.awt.Frame;

public class StudioUtils {
    static public Frame getFrame(Component comp) {
        Frame frame = null;
        while (comp != null && frame == null) {
            if (comp instanceof Frame) {
                frame = (Frame) comp;
            } else {
                comp = comp.getParent();
            }
        }
        return frame;
    }
}
