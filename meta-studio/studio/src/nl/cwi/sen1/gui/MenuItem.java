package nl.cwi.sen1.gui;

import javax.swing.Action;

import nl.cwi.sen1.configapi.types.Event;

public class MenuItem {
    private Event event;

    private Action action;
    
    public MenuItem(Event event, Action action) {
        this.event = event;
        this.action = action;
    }

    public Event getEvent() {
        return event;
    }

    public Action getAction() {
        return action;
    }
}
