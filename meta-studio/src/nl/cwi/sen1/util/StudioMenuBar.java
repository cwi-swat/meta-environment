package nl.cwi.sen1.util;

import java.awt.Component;

import javax.swing.Action;
import javax.swing.JMenu;
import javax.swing.JMenuBar;

import nl.cwi.sen1.configapi.Factory;
import nl.cwi.sen1.configapi.types.ActionDescription;
import nl.cwi.sen1.configapi.types.ActionDescriptionList;
import nl.cwi.sen1.configapi.types.Event;
import toolbus.AbstractTool;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class StudioMenuBar  {
	protected MenuBuilder menuBuilder;

	protected ATerm id;

	private JMenu menu;

	public StudioMenuBar(ATermFactory factory, AbstractTool bridge) {
		menuBuilder = new MenuBuilder(bridge);
		this.id = factory.parse("studio-menubar");
		this.menu = new JMenu();
	}

	public void add(ActionDescriptionList list) {
		add(list, null);
	}

	public void add(ActionDescriptionList list, Action action) {
		menuBuilder.fill(menu, id, list, action);
	}

	public void add(Event event, Action action) {
		Factory f = Factory.getInstance((PureFactory) id.getFactory());
		ActionDescription d = f.makeActionDescription_Description(id, event);
		ActionDescriptionList l = f.makeActionDescriptionList(d);
		add(l, action);
	}

	public void add(Event event) {
		add(event, null);
	}
	
	public void add(JMenu menu) {
		this.menu.add(menu);
	}

	public JMenuBar getMenuBar() {
		JMenuBar bar = new JMenuBar();
		for (Component d : this.menu.getMenuComponents()) {
			bar.add(d);
		}
		return bar;
	}
}
