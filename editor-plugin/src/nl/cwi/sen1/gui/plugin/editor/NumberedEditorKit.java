package nl.cwi.sen1.gui.plugin.editor;

import java.awt.Graphics;
import java.awt.Rectangle;

import javax.swing.text.AbstractDocument;
import javax.swing.text.BoxView;
import javax.swing.text.ComponentView;
import javax.swing.text.Element;
import javax.swing.text.IconView;
import javax.swing.text.LabelView;
import javax.swing.text.ParagraphView;
import javax.swing.text.StyleConstants;
import javax.swing.text.View;
import javax.swing.text.ViewFactory;

class NumberedEditorKit extends EditorKit {
    private static final ViewFactory defaultFactory = new NumberedViewFactory();

    public NumberedEditorKit(EditorPane editor) {
        super(editor);
    }

    public ViewFactory getViewFactory() {
        return defaultFactory;
    }

    static class NumberedViewFactory implements ViewFactory {
        public View create(Element elem) {
            String kind = elem.getName();
            if (kind != null)
                if (kind.equals(AbstractDocument.ContentElementName)) {
                    return new LabelView(elem);
                } else if (kind.equals(AbstractDocument.ParagraphElementName)) {
                    // return new ParagraphView(elem);
                    return new NumberedParagraphView(elem);
                } else if (kind.equals(AbstractDocument.SectionElementName)) {
                    return new BoxView(elem, View.Y_AXIS);
                } else if (kind.equals(StyleConstants.ComponentElementName)) {
                    return new ComponentView(elem);
                } else if (kind.equals(StyleConstants.IconElementName)) {
                    return new IconView(elem);
                }
            // default to text display
            return new LabelView(elem);
        }
    }

    static class NumberedParagraphView extends ParagraphView {
        public static short NUMBERS_WIDTH = 25;

        public NumberedParagraphView(Element e) {
            super(e);
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            this.setInsets(top, left, bottom, right);
        }

        protected void setInsets(short top, short left, short bottom,
                short right) {
            super.setInsets(top, (short) (left + NUMBERS_WIDTH), bottom, right);
        }

        public void paintChild(Graphics g, Rectangle r, int n) {
            super.paintChild(g, r, n);
            int previousLineCount = getPreviousLineCount();
            int numberX = r.x - getLeftInset();
            int numberY = r.y + r.height - 5;
            g.drawString(Integer.toString(previousLineCount + n + 1), numberX,
                    numberY);
        }

        public int getPreviousLineCount() {
            int lineCount = 0;
            View parent = this.getParent();
            int count = parent.getViewCount();
            for (int i = 0; i < count; i++) {
                if (parent.getView(i) == this) {
                    break;
                }
                lineCount += parent.getView(i).getViewCount();
            }
            return lineCount;
        }
    }
}
