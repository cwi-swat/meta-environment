package metastudio.components;

import java.util.Set;
import java.util.TreeSet;

import javax.swing.JComponent;
import javax.swing.JOptionPane;

import metastudio.MultiBridge;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

public class ListChoicePopup extends ToolComponent {
    private JComponent parent;

    public ListChoicePopup(ATermFactory factory, MultiBridge bridge, JComponent parent) {
        super(factory, bridge);
        this.parent = parent;
    }

    public void showListChoice(String title, String question, ATerm choices) {
       Object answer = JOptionPane.showInputDialog(parent,question,title, JOptionPane.QUESTION_MESSAGE,
               null, getList((ATermList) choices), "");
       
       if (answer != null) {
           String str = (String) answer;
           getBridge().postEvent(getFactory().make("list-choice(<str>,<str>)",
                   title, str));
       }
       else {
           getBridge().postEvent(getFactory().make("cancel-list-choice(<str>)",
                   title));
       }
    }
    
    private Object[] getList(ATermList aterms) {
        Set set = new TreeSet();
        
        for (int i = 0; !aterms.isEmpty(); i++, aterms = aterms.getNext()) {
            ATerm first = aterms.getFirst();
            if (first.getType() == ATerm.APPL) {
              ATermAppl appl = (ATermAppl) first;
              set.add(appl.getName());
            }
        }

        return set.toArray();
    }
}
