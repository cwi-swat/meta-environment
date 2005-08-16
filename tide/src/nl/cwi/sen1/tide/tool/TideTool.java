package nl.cwi.sen1.tide.tool;

import java.net.URL;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.event.EventListenerList;

import nl.cwi.sen1.gui.StatusMessageEvent;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentListener;
import nl.cwi.sen1.tide.tool.support.Expr;

public abstract class TideTool extends JPanel implements StudioComponent {
	private static int next_id = 0;

	private int id;

	private ToolManager manager;

	private String name;

	private Object target;

	private String statusMessage;

	private EventListenerList listenerList = new EventListenerList();

	public TideTool(ToolManager manager) {

		this.manager = manager;

		id = next_id++;
	}

	public ToolManager getManager() {
		return manager;
	}

	// }}}
	// {{{ public int getId()

	public int getId() {
		return id;
	}

	// }}}
	// {{{ public String getName()

	public String getName() {
		return name;
	}

	// }}}
	// {{{ public Object getTarget()

	public Object getTarget() {
		return target;
	}

	// }}}
	// {{{ public void setName(String name)

	public void setName(String name) {
		this.name = name;
	}

	// }}}
	// {{{ public void setTarget(Object target)

	public void setTarget(Object target) {
		this.target = target;
	}

	protected Icon loadIcon(String name) {
		URL url = getClass().getResource("/resources/images/" + name);
		return new ImageIcon(url);
	}

	public void displayError(Expr error) {
		displayError(error.getErrorMessage(), error.getErrorData());
	}

	public void displayError(String msg, Expr data) {
		String string = data.toString();
		if (!string.equals("[]")) {
			msg += ": " + string;
		}

		manager.displayError(msg);
	}

	public void destroy() {
		manager.removeTool(this);
	}

	public Icon getIcon() {
		return null;
	}

	public JComponent getViewComponent() {
		return this;
	}

	public void addStudioComponentListener(StudioComponentListener l) {
		listenerList.add(StudioComponentListener.class, l);
	}

	public void removeStudioComponentListener(StudioComponentListener l) {
		listenerList.remove(StudioComponentListener.class, l);
	}

	// Take from javax.swing.event.EventListenerList example
	protected void fireStatusMessageChanged(String oldMessage, String newMessage) {
		StatusMessageEvent event = new StatusMessageEvent(this, oldMessage,
				newMessage);
		Object[] listeners = listenerList.getListenerList();
		for (int i = listeners.length - 2; i >= 0; i -= 2) {
			if (listeners[i] == StudioComponentListener.class) {
				((StudioComponentListener) listeners[i + 1])
						.statusMessageChanged(event);
			}
		}
	}

	protected void fireComponentFocusReceived() {
		Object[] listeners = listenerList.getListenerList();
		for (int i = listeners.length - 2; i >= 0; i -= 2) {
			if (listeners[i] == StudioComponentListener.class) {
				((StudioComponentListener) listeners[i + 1])
						.componentFocusReceived();
			}
		}
	}

	public void receiveFocus() {
		fireComponentFocusReceived();
	}

	public String getStatusMessage() {
		return statusMessage;
	}

	public void setStatusMessage(String newMessage) {
		String oldMessage = statusMessage;
		statusMessage = newMessage;
		if (newMessage == null || !newMessage.equals(oldMessage)) {
			fireStatusMessageChanged(oldMessage, newMessage);
		}
	}

	public void requestClose() {
	}

	public void close() {
	}
}
