package nl.cwi.editor.styles;


import javax.swing.JEditorPane;
import metaconfig.types.Property;

/*
 * Created on Jul 3, 2004
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

/**
 * @author root
 *
 * To change the template for this generated type comment go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
public class NormalStyle  extends EditorStyle{
	public NormalStyle(Property property){
		super(property);
	}
	
	public void setEditorBackground(JEditorPane editorPane){
		if (this.bgColor!=null){
			editorPane.setBackground(this.bgColor);
		}
	}
	
}
