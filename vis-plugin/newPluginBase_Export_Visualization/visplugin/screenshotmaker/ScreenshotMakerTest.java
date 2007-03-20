package nl.dancingbear.visplugin.screenshotmaker;

import java.awt.Color;
import java.io.File;

import javax.swing.JLabel;
import javax.swing.JPanel;


import junit.framework.TestCase;

/**
 * Test the screenshot function with different extensions.
 *
 * @author R. Bergen
 * @author S. Tharmarajah
 * @date 09-03-2007
 */
public class ScreenshotMakerTest extends TestCase{
	
    protected void setUp() throws Exception {
        super.setUp();
    }
	 
    /**
     * Test the screenshot function with different extensions.
     *
     * @author R. Bergen
     * @author S. Tharmarajah
     * @date 09-03-2007
     */
    public void testExportScreenShot() {
    	//Create a test JPanel which can be saved
    	JPanel testPanel = new JPanel();
    	testPanel.setSize(100,100);
    	testPanel.add(new JLabel("TEST"));
    	testPanel.setBackground(Color.CYAN);
    	
    	//Testcases for supported file extensions
    	assertTrue(exportAs(testPanel, "testFile", "jpg"));
    	assertTrue(exportAs(testPanel, "testFile", "png"));
    	
    	//Testcase for unsupported file extension
    	assertFalse(exportAs(testPanel, "testFile", "bogus"));
    }
	
    /**
     * Test the screenshot function with different extensions.
     * 
     * @param testPanel The Jpanel which should be saved
     * @param exportDestination The destination of the exported image
     * @param fileExtension The extension of the exported image
     * 
     * @author R. Bergen
     * @author S. Tharmarajah
     * @date 09-03-2007
     */
	private boolean exportAs(JPanel testPanel, String exportDestination, String fileExtension) {
		ScreenshotMaker.saveScreenshot(testPanel, exportDestination, fileExtension);
		ScreenshotMaker.saveScreenshot(testPanel, exportDestination, fileExtension);
		/*
    	 * Check if a screenshot is saved using the 
    	 * given extension when a bogus extension is given
    	 */
    	File file = new File(exportDestination + "." +fileExtension);
    	boolean exists = file.exists();
    	
    	if(exists) 
    		file.delete();
    	
    	/*
    	 * Check if a screenshot is saved using the 
    	 * default extension when a bogus extension is given
    	 * 
    	 * The reason there is an extra test is that the screenshotmaker 
    	 * automatically gives a file with a bogus extension a default extension
    	 */
    	File fileWithDefaultExtension = new File(exportDestination + "." +ScreenshotMaker.DEFAULT_EXTENSION);
    	boolean fileWithDefaultExtensionExists = fileWithDefaultExtension.exists();
    	
    	if(fileWithDefaultExtensionExists) 
    		fileWithDefaultExtension.delete();
    	
    	return exists;
	}
}
