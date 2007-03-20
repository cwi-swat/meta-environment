package nl.dancingbear.visplugin;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class ImageExportProvider extends ExportProvider {

	public static final String JPEG_EXTENSION = "jpg";
	public static final String PNG_EXTENSION = "png";
	public static final String DEFAULT_EXTENSION = JPEG_EXTENSION;
	
	public boolean checkType(Object inputToExport){
		if(inputToExport instanceof JPanel)
			return true;
		else
			return false;
	}

	/**
     * Save a JPanel as an image to a given destination.
     * 
     * @param JPanel The Jpanel which should be saved
     * @param exportDestination The destination of the exported image
     * @param fileExtension The extension of the exported image
     * 
     * @author R. Bergen
     * @author S. Tharmarajah
     * @date 09-03-2007
     */
	public void exportAction(Object inputToExport, String fileName, String fileExtension) {
		JPanel exportPanel = (JPanel) inputToExport;
		
		// check extensions
		if (!fileExtension.equals(JPEG_EXTENSION) && !fileExtension.equals(PNG_EXTENSION)) {
			fileExtension = DEFAULT_EXTENSION;
		} 
		
		// make screenshot
		BufferedImage bufferedImage = createImageFromPanel(exportPanel);
	
		// Check if file already exists, if so delete the existing file
		File file = new File(fileName + "." +fileExtension);
    	boolean exists = file.exists();
    	
    	if(exists) 
    		file.delete();
		
		// save to disk
		try {
			ImageIO.write(bufferedImage, fileExtension, file);
		} catch (IOException e) {
			// TODO: Throw the exception to a dialog in the Meta Studio
		}
	}
	
	/**
     * Create a BufferedImage from a given JPanel.
     * 
     * @param JPanel The Jpanel which should be saved
     * @return bufferedImage a BufferedImage of the given JPanel
     *
     * @author R. Bergen
     * @author S. Tharmarajah
     * @date 09-03-2007
     */
	private static BufferedImage createImageFromPanel(JPanel jPanel) {
		Dimension dimension = jPanel.getSize();
		Rectangle region = new Rectangle(0, 0, dimension.width, dimension.height);
		
		BufferedImage bufferedImage = new BufferedImage(region.width, region.height, BufferedImage.TYPE_INT_RGB);
		Graphics2D graphics2D = bufferedImage.createGraphics();
		jPanel.paint(graphics2D);
		graphics2D.dispose();
		
		return bufferedImage;
	}
	
	protected String setDialogTitle() {		
		return "Export to image";
	}

	protected String setExtensions() {
		return ".png";
	}

	protected String setPaths() {
		return "[]";
	}
	
	protected String setMenuOptionName() {
		return "Export to image";
	}
}