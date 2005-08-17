package nl.cwi.sen1.gui.plugin.editor;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;

import metaconfig.types.Color;
import metaconfig.types.Properties;
import metaconfig.types.Property;
import metaconfig.types.TextAttributes;
import metaconfig.types.TextCategoryName;
import metaconfig.types.TextStyle;
import metaconfig.types.property.TextCategory;

public class StyleRegistrar {
    private static final String FOCUS_STYLE_NAME = "***focus***";

    private static final String SELECTION_STYLE_NAME = "***selection***";

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
        TextCategoryName type = category.getCategory();
        TextAttributes attrs = category.getAttributes();

        if (type.isExtern()) {
            String name = category.getCategory().getName();
            registerAttributes(editor, name, attrs);
        } else if (type.isNormal()) {
            setStyleAttributes(attrs, editor.getDefaultStyle());
        } else if (type.isSelection()) {
            Style style = registerAttributes(editor, SELECTION_STYLE_NAME,
                    attrs);
            editor.setSelectedTextColor((java.awt.Color) style
                    .getAttribute(StyleConstants.Foreground));
            editor.setSelectionColor((java.awt.Color) style
                    .getAttribute(StyleConstants.Background));
        } else if (type.isFocus()) {
            Style style = registerAttributes(editor, FOCUS_STYLE_NAME, attrs);
            editor.setFocusColor((java.awt.Color) style
                    .getAttribute(StyleConstants.Background));
        }
    }

    static private Style registerAttributes(EditorPane editor, String name,
            TextAttributes attrs) {
        Style style = editor.addStyle(name, editor.getDefaultStyle());
        setStyleAttributes(attrs, style);
        return style;
    }

    private static void setStyleAttributes(TextAttributes attrs, Style style) {
        for (; !attrs.isEmpty(); attrs = attrs.getTail()) {
            metaconfig.types.TextAttribute attr = attrs.getHead();

            if (attr.isForegroundColor()) {
                StyleConstants.setForeground(style, convertColor(attr
                        .getColor()));
            } else if (attr.isBackgroundColor()) {
                // Ignore background colors for text
                // StyleConstants.setBackground(style, convertColor(attr
                // .getColor()));
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
