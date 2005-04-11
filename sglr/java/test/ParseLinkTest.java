/*
 * Created on Sep 16, 2004
 */
package test;

import junit.framework.TestCase;
import sglr.gss.ParseLink;
import sglr.gss.ParseStack;

/**
 * @author Cathal Boogerd
 */
public class ParseLinkTest extends TestCase {
	public void testParseLink() {
		ParseLink link;
		ParseStack linked, notLinked;
		
		linked = new ParseStack(1);
		notLinked = new ParseStack(2);
		link = new ParseLink(linked);
		
		assertEquals(true, link.isLinkedTo(linked));
		assertEquals(false, link.isLinkedTo(notLinked));
	}
}
