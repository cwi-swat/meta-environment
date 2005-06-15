package nl.cwi.sen1.gui.plugin;

import java.awt.event.ComponentListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import org.syntax.jedit.JEditTextArea;
import org.syntax.jedit.TextAreaDefaults;

import errorapi.types.Area;

public class EditorTextArea extends JEditTextArea {
    public EditorTextArea() {
        this(TextAreaDefaults.getDefaults());
    }

    public EditorTextArea(TextAreaDefaults defaults) {
        super(defaults);

        ComponentListener[] comps = painter.getComponentListeners();
        MouseListener[] mouse = painter.getMouseListeners();
        MouseMotionListener[] motions = painter.getMouseMotionListeners();

        painter = new EditorPainter(this, defaults);

        for (int i = 0; i < comps.length; i++) {
            painter.addComponentListener(comps[i]);
        }
        for (int i = 0; i < mouse.length; i++) {
            painter.addMouseListener(mouse[i]);
        }
        for (int i = 0; i < motions.length; i++) {
            painter.addMouseMotionListener(motions[i]);
        }

        add(CENTER, painter);
    }

    public void setFocus(Area focus) {
        EditorPainter p = (EditorPainter) painter;
        p.setFocus(focus);
    }
}
