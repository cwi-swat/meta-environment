package nl.dancingbear.visplugin.screenshotmaker;

import java.awt.Dimension;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

/**
 * ScreenshotMaker has the functionality to export a JPanel as an image
 *
 * @author R. Bergen
 * @author S. Tharmarajah
 * @date 09-03-2007
 */
public class ScreenshotMaker {

    public static final String JPEG_EXTENSION = "jpg";
    public static final String PNG_EXTENSION = "png";
    public static final String DEFAULT_EXTENSION = PNG_EXTENSION;

    /**
     * Save a JPanel as an image to a given destination.
     *
     * @param jPanel The JPanel which should be saved
     * @param exportDestination The destination of the exported image
     * @param fileExtension The extension of the exported image
     *
     * @author R. Bergen
     * @author S. Tharmarajah
     * @date 09-03-2007
     */
    public static void saveScreenshot(JPanel jPanel, String exportDestination, String fileExtension) {

        // check extensions
    	String fe = fileExtension;
        if (!fe.equals(JPEG_EXTENSION) && !fe.equals(PNG_EXTENSION)) {
            fe = DEFAULT_EXTENSION;
        }

        // make screenshot
        BufferedImage bufferedImage = createImageFromPanel(jPanel);

        // Check if file already exists, if so delete the existing file
        File file = new File(exportDestination + "." +fe);
        boolean exists = file.exists();

        if(exists)
            file.delete();

        // save to disk
        try {
            ImageIO.write(bufferedImage, fe, file);
        } catch (IOException e) {
            // TODO: Throw the exception to a dialog in the Meta Studio
        }

    }

    /**
     * Create a BufferedImage from a given JPanel.
     *
     * @param jPanel The JPanel which should be saved
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


}
