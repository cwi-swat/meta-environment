package metaedit.style;

import java.awt.Color;

import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;

import metaconfig.types.Property;

/*
 * Created on Jul 3, 2004
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

public class Focuser  extends EditorStyle{
	protected SimpleAttributeSet focusCleaner = new SimpleAttributeSet();
	private int offsetTemp=-1;
	private int lengthTemp=-1;


	
	public Focuser(Property property){
		super(property);
	}
	
	public void setFocus(StyledDocument document,  int offset, int focusLength){
		this.setStyle(document, offset, focusLength);
		offsetTemp=offset;
		lengthTemp=focusLength;
	}
	
	
	public void clearFocus(StyledDocument document, Color bgColor){	
		System.out.println("ClearFocus background: 1 "+ bgColor.toString()+"  and the areas to clear are: "+ offsetTemp + lengthTemp);
		if (offsetTemp>=0&&lengthTemp>=0){
			System.out.println("ClearFocus background: 2 "+ bgColor.toString());
			StyleConstants.setBackground(focusCleaner, bgColor);
			document.setCharacterAttributes(offsetTemp, lengthTemp, focusCleaner, false);
		}
	}

	public SimpleAttributeSet getFocusCleaner() {
		return focusCleaner;
	}

	public int getLengthTemp() {
		return lengthTemp;
	}

	public int getOffsetTemp() {
		return offsetTemp;
	}

	public void setLengthTemp(int i) {
		lengthTemp = i;
	}

	public void setOffsetTemp(int i) {
		offsetTemp = i;
	}

}
