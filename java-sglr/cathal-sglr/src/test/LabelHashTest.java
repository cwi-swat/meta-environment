/*
 * Created on Sep 22, 2004
 */
package test;

import java.io.FileInputStream;
import java.io.IOException;

import aterm.pure.PureFactory;
import junit.framework.TestCase;

import sglr.mept.LabelHash;
import sglr.ptable.*;
import sglr.ptable.types.*;

/**
 * @author Cathal Boogerd
 */
public class LabelHashTest extends TestCase {
	public void testLabelHash() throws IOException {
		PureFactory pureFactory = new PureFactory();
		Factory factory = new Factory(pureFactory);
		ParseTable pt = factory.ParseTableFromFile(new FileInputStream("test-data/Booleans.tbl"));
		Labels labelList = pt.getLabels();
		LabelHash labels = new LabelHash(labelList);
		
		int number1, number2;
		Label label1, label2;
		number1 = 284;
		number2 = 262;
		label1 = null;
		label2 = null;
		
		// get two arbitrary labels from the list for testing purposes
		for (int i = 0; i < labelList.getLength(); i++) {
			Label current = labelList.getLabelAt(i);
			if (current.getNumber() == number1) {
				label1 = current;
			}
			else if (current.getNumber() == number2) {
				label2 = current;
			}
		}
		
		assertEquals(label1, labels.fetch(number1));
		assertEquals(label2, labels.fetch(number2));
		assertNull(labels.fetch(400));
	}
}
