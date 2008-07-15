package argusviewer.util;

import argusviewer.ExceptionReporter;
import aterm.ATerm;
import toolbus.StateElement;
import toolbus.TBTermVar;
import toolbus.atom.Atom;

/**
 * @author Alexander Bij
 * @author Arne Timmerman
 */
public class ToolbusUtil {

	/**
	 * Get the tool ID from a tool key. A tool key has the following format:
	 * name(id)
	 * This method parses the id part to an integer.
	 *
	 * @param key The tool key to parse
	 * @return The tool ID
	 */
	public static int getToolIdFromKey(ATerm key) {
		String toolKey = key.toString();
		int idStartIndex = toolKey.lastIndexOf('(');
		int idEndIndex = toolKey.lastIndexOf(')');

		if ((idStartIndex != -1) && (idEndIndex != -1)) {
			String toolIdText = toolKey.substring(idStartIndex + 1, idEndIndex);

			try {
				return Integer.parseInt(toolIdText);
			} catch (NumberFormatException ex) {
				return -1;
			}
		} else {
			return -1;
		}
	}

	/**
	 * Extract a tool id from a StateElement
	 *
	 * @param executedStateElement The StateElement to extract the tool id from
	 * @return The tool id
	 */
	public static String getToolIdFromStateElement(StateElement executedStateElement) {
		// Retrieve tool id from the state element
		Atom executedAtom = (Atom) executedStateElement;

		/* We don't know at which array index the TBTermVar can be found. Neither don't we
		 * know how many array elements there are. As the Atom class provides only the
		 * getAtomArgValue() getter, we cannot do any better than search from 0 upwards.
		 */
		ATerm aTerm = null;
		try {
			for (int i = 0; true; i++) {
				aTerm = executedAtom.getAtomArgValue(i);
				if (aTerm instanceof TBTermVar) {
					break; // Found it!
				}
			}
		} catch (ArrayIndexOutOfBoundsException e) {
			ExceptionReporter.process(e, ExceptionReporter.ExceptionState.CONSUMED);
			return null;
		}

		ATerm toolIdATerm = executedAtom.getEnv().getValue((TBTermVar) aTerm);
		String toolKey = toolIdATerm.toString();

		// Convert the atom toolId to an MSC Entity Id
		return getToolNameFromKey(toolKey) + ToolbusUtil.getToolIdFromKey(toolIdATerm);
	}

	/**
	 * Get the tool name from a tool key. A tool key has the following format:
	 * name(id)
	 *
	 * @param toolKey The tool key to parse
	 * @return The tool name
	 */
	private static String getToolNameFromKey(String toolKey) {
		int nameEndIndex = toolKey.lastIndexOf('(');
		return toolKey.substring(0, nameEndIndex);
	}

	/**
	 * Get a consistent String representation of the given state element.
	 *
	 * @param stateElement name of the state element to format
	 * @return a formatted state element name
	 */
	public static String getMessageFromStateElement(String stateElement) {

		int msgStartIndex = stateElement.indexOf('(');
		int msgEndIndex = stateElement.lastIndexOf(')');

		if ((msgStartIndex != -1) && (msgEndIndex != -1)) {
			return stateElement.substring(msgStartIndex + 1, msgEndIndex);
		} else {
			return stateElement;
		}
	}
}
