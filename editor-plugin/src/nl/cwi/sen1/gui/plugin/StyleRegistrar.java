package nl.cwi.sen1.gui.plugin;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;

import metaconfig.types.Color;
import metaconfig.types.Properties;
import metaconfig.types.Property;
import metaconfig.types.TextAttributes;
import metaconfig.types.TextStyle;
import metaconfig.types.property.TextCategory;

public class StyleRegistrar {
	

	static public void registerTextCategories(EditorPane editor,
			Properties categories) {
		editor.unsetStyles();
		
		for (; !categories.isEmpty(); categories = categories.getTail()) {
			Property prop = categories.getHead();

			if (prop.isTextCategory()) {
				registerTextCategory(editor, (TextCategory) prop);
			}
		}
	}

	static private void registerTextCategory(EditorPane editor,
			TextCategory category) {
		if (category.getCategory().isExtern()) {
			String name = category.getCategory().getName();
			TextAttributes attrs = category.getAttributes();
			registerAttributes(editor, name, attrs);
		}
	}

	static private void registerAttributes(EditorPane editor, String name,
			TextAttributes attrs) {
		Style style = editor.addStyle(name, editor.getDefaultStyle());

		for (; !attrs.isEmpty(); attrs = attrs.getTail()) {
			metaconfig.types.TextAttribute attr = attrs.getHead();

			if (attr.isForegroundColor()) {
				StyleConstants.setForeground(style, convertColor(attr
						.getColor()));
			} else if (attr.isBackgroundColor()) {
				StyleConstants.setBackground(style, convertColor(attr
						.getColor()));
			} else if (attr.isStyle()) {
				TextStyle textStyle = attr.getStyle();

				if (textStyle.isBold()) {
					StyleConstants.setBold(style, true);
				} else if (textStyle.isItalics()) {
					StyleConstants.setItalic(style, true);
				} else if (textStyle.isUnderlined()) {
					StyleConstants.setUnderline(style, true);
				}
			} else if (attr.isFont()) {
				StyleConstants.setFontFamily(style, attr.getName());
			} else if (attr.isSize()) {
				StyleConstants.setFontSize(style, attr.getPoints());
			}
		}
	}

	static private java.awt.Color convertColor(Color color) {
		return new java.awt.Color(color.getRed(), color.getGreen(), color
				.getBlue());
	}
}
