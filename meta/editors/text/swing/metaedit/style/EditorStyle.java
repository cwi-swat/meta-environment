package nl.cwi.editor.styles;
import java.awt.Color;

import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;

import metaconfig.types.Properties;
import metaconfig.types.Property;
import metaconfig.types.TextAttribute;
import metaconfig.types.TextAttributes;
import metaconfig.types.TextStyle;


public class EditorStyle {
	public String categoryName;
	private metaconfig.Factory metaconfigFactory;
	protected SimpleAttributeSet attributeSet = new SimpleAttributeSet();
	private Properties properties;
	private TextAttributes textAttributes; 
	private TextAttribute textAttribute; 
	protected Color bgColor;
	protected Color fgColor=null;
	
	
	public EditorStyle(Property property){
			this.makeStyle(property);
	
	}
	
	public void makeStyle(Property property){
		if (property.getCategory().isExtern()){
			 categoryName= property.getCategory().getName();
		   }
			  textAttributes=(TextAttributes)property.getAttributes();
			  while(!textAttributes.isEmpty()){
				  textAttribute =(TextAttribute)textAttributes.getFirst();
				  if (textAttribute.hasStyle()){
						  setStyle(textAttribute.getStyle());
				  }
					  if (textAttribute.isForegroundColor()){
						  setForegroundColor(getColor(textAttribute.getColor()));
					  }				
					  if (textAttribute.isBackgroundColor())
					  setBackgroundColor(getColor(textAttribute.getColor()));
				
				  if (textAttribute.hasPoints()){
					  setFontSize(textAttribute.getPoints());
				  }
				  textAttributes =(TextAttributes)textAttributes.getNext();
			  }
	}
	
	public java.awt.Color getColor(metaconfig.types.Color color){
				int r=color.getRed();
				int g=color.getGreen();
				int b=color.getBlue();
		 		return new Color(r, g, b);
				
		}
		
	public void setStyle(TextStyle style){
		if (style.isBold()){
			StyleConstants.setBold(attributeSet, true);
		
		}
		if (style.isUnderlined()){
			StyleConstants.setUnderline(attributeSet, true);	
		}
		if (style.isItalics()){
			StyleConstants.setItalic(attributeSet, true);
		}
	}
	
	public void setFontSize(int fontSize){
			StyleConstants.setFontSize(attributeSet, fontSize);
	}
	
	public void setFontFamily(String fontFamily){
		StyleConstants.setFontFamily(attributeSet, fontFamily);	
	}
	
	public void setBackgroundColor(Color bgColor){
		this.bgColor=bgColor;
		StyleConstants.setBackground(attributeSet, bgColor);	
	}
	
	public void setForegroundColor(Color fgColor){
		    this.fgColor=fgColor;
				StyleConstants.setForeground(attributeSet, fgColor);	
	}
	
    public void setStyle(StyledDocument document, int offset, int length){
		document.setCharacterAttributes(offset, length, attributeSet, true);
	}
	
	public Color getBgColor() {
		return bgColor;
	}

}