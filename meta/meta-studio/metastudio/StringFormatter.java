package metastudio;

import aterm.ATermAppl;
import aterm.ATermList;

public class StringFormatter {
    public static String format(String format, ATermList args) {
        int index;
        String prefix = "";
        String postfix = format;
        while ((index = postfix.indexOf("%")) != -1) {
            prefix += postfix.substring(0, index);
            switch (postfix.charAt(index + 1)) {
                case 't' :
                case 'd' :
                    prefix += args.getFirst().toString();
                    break;
                case 's' :
                    prefix += ((ATermAppl) args.getFirst()).getName();
                    break;
                default :
                    prefix += "%" + postfix.charAt(index + 1);
            }
            postfix = postfix.substring(index + 2);
            args = args.getNext();
        }
        return prefix + postfix;
    }
}
