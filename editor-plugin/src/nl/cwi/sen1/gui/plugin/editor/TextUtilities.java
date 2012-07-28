package nl.cwi.sen1.gui.plugin.editor;

/*
 * TextUtilities.java - Utility functions used by the text area classes
 * Copyright (C) 1999 Slava Pestov
 *
 * You may use and modify this package for any purpose. Redistribution is
 * permitted, in both source and binary form, provided that this notice
 * remains intact in all source distributions of this package.
 */

import javax.swing.text.Document;
import javax.swing.text.BadLocationException;

public class TextUtilities {
    public static int findMatchingBracket(Document doc, int offset)
            throws BadLocationException {
        if (doc.getLength() == 0) {
            return -1;
        }

        char c = doc.getText(offset, 1).charAt(0);
        char cprime; // c' - corresponding character
        boolean direction; // true = back, false = forward

        switch (c) {
        case '(':
            cprime = ')';
            direction = false;
            break;
        case ')':
            cprime = '(';
            direction = true;
            break;
        case '[':
            cprime = ']';
            direction = false;
            break;
        case ']':
            cprime = '[';
            direction = true;
            break;
        case '{':
            cprime = '}';
            direction = false;
            break;
        case '}':
            cprime = '{';
            direction = true;
            break;
        default:
            return -1;
        }

        int count = 0;

        if (direction) {
            String text = doc.getText(0, offset);

            for (int i = offset - 1; i >= 0; i--) {
                char x = text.charAt(i);

                if (x == c) {
                    count++;
                } else if (x == cprime) {
                    if (count == 0) {
                        return i;
                    }
                    count--;
                }
            }
        } else {
            offset++;

            int len = doc.getLength() - offset;
            String text = doc.getText(offset, len);

            for (int i = 0; i < len; i++) {
                char x = text.charAt(i);

                if (x == c) {
                    count++;
                } else if (x == cprime) {
                    if (count == 0) {
                        return i + offset;
                    }
                    count--;
                }
            }
        }

        return -1;
    }
}
