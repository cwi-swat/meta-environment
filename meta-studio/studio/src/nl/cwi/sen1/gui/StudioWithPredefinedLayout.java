package nl.cwi.sen1.gui;

import nl.cwi.sen1.gui.component.StudioComponent;


public interface StudioWithPredefinedLayout extends Studio {
    public void addComponent(StudioComponent component, String viewPosition);
}