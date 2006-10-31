package nl.cwi.sen1.util;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.Event;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class MenuAction extends AbstractAction {
	private final Factory factory;
	private final ATerm id;
	private final AbstractTool bridge;
	private final Event event;
	
	public MenuAction(ATerm id, AbstractTool bridge, Event event)  {
		super(event.toTerm().toString());
		this.factory = Factory.getInstance((PureFactory) id.getFactory());
		this.bridge = bridge;
		this.id = id;
		this.event = event;
	}
	
	public void actionPerformed(ActionEvent e) {
        ATerm event = factory.getPureFactory().make(
                "menu-event(<term>,<term>)", id, this.event.toTerm());
        bridge.postEvent(event);
    }
}
