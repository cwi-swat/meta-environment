package nl.cwi.sen1.gui;

import javax.swing.Action;
import javax.swing.JMenu;

import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.gui.component.StudioComponent;
import toolbus.AbstractTool;
import aterm.ATermFactory;

public interface Studio {
    public ATermFactory getATermFactory();

    public void connect(String toolName, AbstractTool tool);

    public void addComponent(StudioComponent component);

    public void removeComponent(StudioComponent component);

    public void addComponentMenu(StudioComponent component, JMenu menu);

    public void addComponentMenu(StudioComponent component, Event menu,
            Action action);

    public void requestFocus(StudioComponent component);
}