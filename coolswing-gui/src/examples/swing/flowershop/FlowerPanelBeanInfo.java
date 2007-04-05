package examples.swing.flowershop;

import java.awt.Image;
import java.beans.BeanDescriptor;
import java.beans.BeanInfo;
import java.beans.EventSetDescriptor;
import java.beans.IntrospectionException;
import java.beans.MethodDescriptor;
import java.beans.PropertyDescriptor;
import java.beans.SimpleBeanInfo;
import java.net.URL;
import java.util.HashMap;

import javax.swing.ImageIcon;

public class FlowerPanelBeanInfo extends SimpleBeanInfo {

	private static final Class beanClass = FlowerPanel.class;

	private HashMap images = new HashMap();

	private EventSetDescriptor[] eventDescs = new EventSetDescriptor[0];

	public BeanDescriptor getBeanDescriptor() {
		return new BeanDescriptor(FlowerPanel.class,
				FlowerPanelCustomizer.class);
	}

	private PropertyDescriptor createPropertyDescriptor(String s, Object aobj[]) {
		try {
			return new PropertyDescriptor(s, beanClass) {
			};
		} catch (IntrospectionException e) {
			e.printStackTrace();
			return null;
		}
	}

	public PropertyDescriptor[] getPropertyDescriptors() {

		PropertyDescriptor pd = null;
		try {
			pd = new PropertyDescriptor("flowerFamily", beanClass);
			pd.setPropertyEditorClass(FlowerFamilyEditor.class);
		} catch (IntrospectionException e) {
			e.printStackTrace();
		}
		return (new PropertyDescriptor[] { pd });
	}

	public MethodDescriptor[] getMethodDescriptors() {
		return null;
	}

	public java.awt.Image getIcon(int iconKind) {
		if (iconKind == BeanInfo.ICON_COLOR_16x16) {
			java.awt.Image img = loadImage("examples/swing/flowershop/icons/flower_panel.gif");
			return img;
		}
		if (iconKind == BeanInfo.ICON_COLOR_32x32) {
			java.awt.Image img = loadImage("examples/swing/flowershop/icons/flower_panel.gif");
			return img;
		}
		if (iconKind == BeanInfo.ICON_MONO_16x16) {
			java.awt.Image img = loadImage("examples/swing/flowershop/icons/flower_panel.gif");
			return img;
		}
		if (iconKind == BeanInfo.ICON_MONO_32x32) {
			java.awt.Image img = loadImage("examples/swing/flowershop/icons/flower_panel.gif");
			return img;
		}
		return null;
	}

	public Image loadImage(String imgUrl) {
		try {
			if (images.containsKey(imgUrl))
				return (Image) images.get(imgUrl);
			URL url = getClass().getClassLoader().getResource(imgUrl);
			Image img = new ImageIcon(url).getImage();
			images.put(imgUrl, img);
			return img;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}

	public EventSetDescriptor[] getEventSetDescriptors() {
		return eventDescs;
	}

	public int getDefaultEventIndex() {
		return 0;
	}

	public int getDefaultPropertyIndex() {
		return 0;
	}

	public BeanInfo[] getAdditionalBeanInfo() {
		return null;
	}
}
