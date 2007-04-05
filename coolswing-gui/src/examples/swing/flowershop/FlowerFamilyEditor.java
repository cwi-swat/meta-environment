package examples.swing.flowershop;

import java.beans.PropertyEditorSupport;

/**
 */
public class FlowerFamilyEditor extends PropertyEditorSupport {

	private FlowerPanel flowerPanel;

	private static final String SUNFLOWER="SUNFLOWER";
	private static final String BANANA="BANANA";
	private static final String HOLLYHOCK="HOLLYHOCK";
	private static final String CLEMATIS="CLEMATIS";
	private static final String[] tags = { 
			"<undefined>", SUNFLOWER, BANANA, HOLLYHOCK, CLEMATIS };

	public FlowerFamilyEditor() {
		setValue(new Integer(FlowerPanel.UNDEFINED));
	}

	public String[] getTags() {
		return tags;
	}
	
    public void setAsText(String s) {
        if (s.equals(SUNFLOWER))
            setValue(new Integer(FlowerPanel.SUNFLOWER));
        else if (s.equals(BANANA))
            setValue(new Integer(FlowerPanel.BANANA));
        else if (s.equals(HOLLYHOCK))
            setValue(new Integer(FlowerPanel.HOLLYHOCK));
        else if (s.equals(CLEMATIS))
            setValue(new Integer(FlowerPanel.CLEMATIS));
        else
            setValue(new Integer(FlowerPanel.UNDEFINED));
    }
    
    public String getAsText() {
        switch (((Integer)getValue()).intValue()) {
        case FlowerPanel.SUNFLOWER:
            return SUNFLOWER;
        case FlowerPanel.BANANA:
            return BANANA;
        case FlowerPanel.HOLLYHOCK:
            return HOLLYHOCK;
        case FlowerPanel.CLEMATIS:
            return CLEMATIS;
        }
        return "<undefined>";
    }
    
	public String getJavaInitializationString() {
        switch (((Integer)getValue()).intValue()) {
        case FlowerPanel.SUNFLOWER:
        	return "FlowerPanel.SUNFLOWER";
        case FlowerPanel.BANANA:
        	return "FlowerPanel.BANANA";
        case FlowerPanel.HOLLYHOCK:
        	return "FlowerPanel.HOLLYHOCK";
        case FlowerPanel.CLEMATIS:
        	return "FlowerPanel.CLEMATIS";
        }
        return "0";
	}
}
