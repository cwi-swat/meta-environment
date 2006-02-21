package nl.cwi.sen1.gui.plugin.editor;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;

import nl.cwi.sen1.configapi.types.Color;
import nl.cwi.sen1.configapi.types.Property;
import nl.cwi.sen1.configapi.types.PropertyList;
import nl.cwi.sen1.configapi.types.TextAttribute;
import nl.cwi.sen1.configapi.types.TextAttributeMap;
import nl.cwi.sen1.configapi.types.TextCategoryName;
import nl.cwi.sen1.configapi.types.TextStyle;
import nl.cwi.sen1.configapi.types.property.TextCategory;

public class StyleRegistrar {
    private static final String FOCUS_STYLE_NAME = "***focus***";

    private static final String SELECTION_STYLE_NAME = "***selection***";

    static public void registerTextCategories(EditorPane editor,
            PropertyList categories) {
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
        TextAttributeMap attrs = category.getMap();

        if (type.isExtern()) {
            String name = category.getCategory().getName();
            registerAttributes(editor, name, attrs);
        } else if (type.isNormal()) {
            setStyleAttributes(editor, attrs, editor.getDefaultStyle());
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
            TextAttributeMap attrs) {
        Style style = editor.addStyle(name, editor.getDefaultStyle());
        setStyleAttributes(editor, attrs, style);
        return style;
    }

private static void setStyleAttributes(EditorPane editor, TextAttributeMap attrs, Style style) {
        for (; !attrs.isEmpty(); attrs = attrs.getTail()) {
            TextAttribute attr = attrs.getHead();

            if (attr.isForegroundColor()) {
                StyleConstants.setForeground(style, convertColor(attr
                        .getColor()));
            } else if (attr.isBackgroundColor()) {
                if (convertColor(attr.getColor()).equals(
                        editor.getBackgroundColor())) {
                    // the linehighlight is drawed in a lower layer than the
                    // text,
                    // so if the textbackground is the same as the background of
                    // the
                    // editor we need to remove the background attribute to
                    // prevent
                    // gaps in the linehighlight
                    style.removeAttribute(StyleConstants.Background);
                } else {
                    StyleConstants.setBackground(style, convertColor(attr
                            .getColor()));
                }
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
                StyleConstants.setFontSize(style, attr.getPoint());
            }
        }
    }    static private java.awt.Color convertColor(Color color) {
        return new java.awt.Color(color.getRed(), color.getGreen(), color
                .getBlue());
    }
}
