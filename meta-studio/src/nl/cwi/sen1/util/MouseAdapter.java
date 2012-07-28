package nl.cwi.sen1.util;

import java.awt.event.InputEvent;
import java.awt.event.MouseEvent;

import javax.swing.event.MouseInputAdapter;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.configapi.types.KeyModifierList;
import nl.cwi.sen1.configapi.types.VirtualButton;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.pure.PureFactory;

/**
 * This is a generic MouseAdapter useful for any MetaStudio component that needs
 * to send mouse events to the ToolBus. It has some magic: if the component is a
 * subclass of JTextComponent it also stores the correct caret position, next to
 * the other details of a MouseEvent (x,y) pos. These can be used for later
 * inspection when the ToolBus scripts might ask for further details.
 * 
 * @author jurgenv
 * 
 */
public class MouseAdapter extends MouseInputAdapter {
	private Factory factory;

	private AbstractTool bridge;

	private ATerm id;

	private Event event;
	
	static private MouseEvent popupEvent;

	public void setId(ATerm id) {
		this.id = id;
	}
	
	public MouseAdapter(ATerm id, AbstractTool bridge, Event event) {
		this.factory = Factory.getInstance((PureFactory) id.getFactory());
		this.bridge = bridge;
		this.id = id;
		this.event = event;
	}

	public void mousePressed(MouseEvent e) {
		if (event.isEqual(convert(e))) {
			ATerm msg = factory.getPureFactory().make(
					"mouse-event(<term>,<term>)",
					this.id, this.event.toTerm());
			bridge.postEvent(msg);
		}
	}

	public void mouseReleased(MouseEvent e) {
		if (e.isPopupTrigger()) {
		  mousePressed(e);
		}
	}

	static public MouseEvent getPreviousPopupEvent() {
		return popupEvent;
	}
	
	private Event convert(MouseEvent e) {
		if (e.isPopupTrigger()) {
			popupEvent = e;
			return factory.makeEvent_Popup();
		}
		int mask = e.getModifiers();
		return factory.makeEvent_Click(modifiers(mask), button(mask));
	}

	private KeyModifierList modifiers(int modifiers) {
		KeyModifierList mods = factory.makeKeyModifierList();

		if ((modifiers & InputEvent.CTRL_DOWN_MASK) != 0) {
			mods.insert(factory.makeKeyModifier_M_CTRL());
		}
		if ((modifiers & InputEvent.ALT_DOWN_MASK) != 0) {
			mods.insert(factory.makeKeyModifier_M_CTRL());
		}
		if ((modifiers & InputEvent.SHIFT_DOWN_MASK) != 0) {
			mods.insert(factory.makeKeyModifier_M_CTRL());
		}

		return mods;
	}

	private VirtualButton button(int modifiers) {
		if ((modifiers & InputEvent.BUTTON1_DOWN_MASK) != 0) {
			return factory.makeVirtualButton_BUTTON1();
		}
		if ((modifiers & InputEvent.BUTTON2_DOWN_MASK) != 0) {
			return factory.makeVirtualButton_BUTTON2();
		}
		if ((modifiers & InputEvent.BUTTON3_DOWN_MASK) != 0) {
			return factory.makeVirtualButton_BUTTON3();
		}
		return factory.makeVirtualButton_NOBUTTON();
	}
}