package toolbus.parser;

/**
 * A specific exeption for signaling failures of external processes
 * called via parse methods.
 * Code borrowed from JJForester.
 */

public class ExternalProcessException extends java.io.IOException {
    private String processType;

    /**
     * Create an exception for signalling failures of external
     * processes of a specific type. Typical process types would be
     * "parse", "implode", "read from file".
     */
    public ExternalProcessException (String msg, String processType) {
	super("ToolBus: external "+processType+" process failed!\n"
	      +msg);
	this.processType = processType;
    }

    /**
     * Return the type of the process that was running while the
     * exception occured.
     */
    public String getProcessType() {
	return processType;
    }

}
