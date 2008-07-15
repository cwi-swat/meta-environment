package argusviewer;

import argusviewer.ExceptionReporter.ExceptionState;
import argusviewer.util.ArgusSettings;

/**
 * Keeps track of application wide settings
 * 
 * @author Hidde Baggelaar
 * 
 */
public abstract class ApplicationSettings {
	private static ArgusSettings settings = ArgusSettings.getInstance();
	private static final String APPLICATION = "Application";
	private static final String HISTORY = "History";
	private static final int HISTORY_LIMIT_DEFAULT = 50;

	private static int historyLimit = -1; // -1 set to be able to check if the
											// historyValue has been retrieved
											// or not

	/**
	 * Sets the history limit
	 * 
	 * @param steps
	 *            history limit in steps
	 */
	public static void setHistoryLimit(int steps) {
		assert (steps >= 0);
		settings.setAttribute(APPLICATION, HISTORY, "" + steps);
		historyLimit = steps;
	}

	/**
	 * Retrieves the history limit
	 * 
	 * @return the history limit
	 */
	public static int getHistoryLimit() {
		if (historyLimit == -1) {
			String history = settings.getAttributeValue(APPLICATION, HISTORY,
					String.valueOf(HISTORY_LIMIT_DEFAULT));
			try {
				historyLimit = Integer.parseInt(history);
			} catch (NumberFormatException nfe) {
				historyLimit = HISTORY_LIMIT_DEFAULT;
				ExceptionReporter.process(nfe, ExceptionState.CONSUMED);
			}
		}

		return historyLimit;
	}

}
