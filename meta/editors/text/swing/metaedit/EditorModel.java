package metaedit;

import java.util.Observable;
import java.util.Vector;

import javax.swing.JMenuBar;

import locationapi.types.Area;
import metaconfig.types.Properties;
import metaconfig.types.Property;
import metaedit.style.EditorStyle;
import metaedit.style.Focuser;
import metaedit.style.Highlighter;
import metaedit.style.NormalStyle;
import metaedit.util.MenuBar;
import texteditorapi.types.Action;
import texteditorapi.types.Menu;
import aterm.ATerm;
import aterm.ATermList;

public class EditorModel extends Observable {
	private Menu menuEvent;

	private Action action;

	private Area area;

	private Property property;

	private String message;

	private String fileName;

	private locationapi.Factory locationFactory;

	private texteditorapi.Factory textFactory;

	private metaconfig.Factory metaconfigFactory;

	private aterm.pure.PureFactory pureFactory;

	private int beginFocus;

	private int focusLength;

	private MenuBar menuBar;

	private EditorStyle editorStyle;

	private Focuser focuser;

	private Highlighter highlighter;

	private Vector highlightVector;

	private NormalStyle normalStyle;

	private ATermList slices;

	private ATerm categories;

	private Properties properties;

	public EditorModel(aterm.pure.PureFactory pureFactory) {
		this.pureFactory = pureFactory;
		locationFactory = new locationapi.Factory(pureFactory);
		textFactory = new texteditorapi.Factory(pureFactory);
		metaconfigFactory = new metaconfig.Factory(pureFactory);
		highlightVector = new Vector();
	}

	public void sendMessage(String message) {
		this.message = message;
		this.setChanged();
		this.notifyObservers("Message");
	}

	public void makeStyles() {
		highlightVector.clear();
		properties = metaconfigFactory.PropertiesFromTerm(categories);
		while (!properties.isEmpty()) {
			property = (Property) properties.getFirst();
			if (property.getCategory().isExtern()) {
				highlighter = new Highlighter(property, locationFactory, slices);
				highlightVector.add(highlighter);
			} else if (property.getCategory().isFocus()) {
				if (focuser != null) {
					focuser.makeStyle(property);
				} else {
					focuser = new Focuser(property);
				}

			} else if (property.getCategory().isNormal()) {
				normalStyle = new NormalStyle(property);
			}
			properties = (Properties) properties.getNext();
		}
	}

	public void setRegisterTextCategories(ATerm categories) {
		this.categories = categories;
	}

	public void setHighlightSlices(ATermList slices) {
		this.slices = slices;
	}

	public void editFile(String fileName) {
		this.fileName = fileName;
		this.setChanged();
		this.notifyObservers("editFile");
	}

	public void rereadContents() {
		this.setChanged();
		this.notifyObservers("editFile");
	}

	public void writeContents() {
		this.setChanged();
		this.notifyObservers("writeContents");
	}

	public void setArea(ATerm area) {
		this.area = locationFactory.AreaFromTerm(area);
	}

	public void addActions(ATermList actionList, Controller controller) {
		menuBar = new MenuBar(pureFactory);
		menuBar.addMenu(actionList);
		this.setChanged();
		this.notifyObservers("addActions");
	}

	public void setFocus() {
		if (area.hasOffset() && area.hasLength()) {
			beginFocus = area.getOffset();
			focusLength = area.getLength();
			this.setChanged();
			this.notifyObservers("setFocus");
		}
	}

	public void setStyle() {
		this.setChanged();
		this.notifyObservers("setStyles");
	}

	public void clearFocus() {
		this.setChanged();
		this.notifyObservers("clearFocus");
	}

	public int getBeginFocus() {
		return beginFocus;
	}

	public int getFocusLength() {
		return focusLength;
	}

	public Focuser getFocuser() {
		return focuser;
	}

	public NormalStyle getNormalStyle() {
		return normalStyle;
	}

	public Vector getHighlighters() {
		return highlightVector;
	}

	public ATerm getMouseEvent(int event) {
		return textFactory.makeEvent_Mouse(event).toTerm();
	}

	public ATerm getMenuEvent(String action, String menuItem) {
		texteditorapi.types.Items items;
		items = textFactory.makeItems(action, menuItem);
		menuEvent = textFactory.makeMenu_Default(items);
		return textFactory.makeEvent_Menu(menuEvent).toTerm();
	}

	public ATerm isModified(int isModified) {
		return textFactory.makeEvent_IsModified(isModified).toTerm();
	}

	public ATerm isWritten() {
		return textFactory.makeEvent_ContentsWritten().toTerm();
	}

	public ATerm contentsChanged() {
		return textFactory.makeEvent_Modified().toTerm();
	}

	public JMenuBar getMenuBar() {
		return menuBar.getJMenuBar();
	}

	public String getMessage() {
		return message;
	}

	public String getFileName() {
		return fileName;
	}

}
