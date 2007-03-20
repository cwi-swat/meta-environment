package nl.dancingbear.visplugin;

import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.StatusMessageEvent;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentListener;

public class VisualizationWindowListener implements StudioComponentListener {
    VisualizationPluginWindow m_window;
    StudioComponent m_component;

    public VisualizationWindowListener(VisualizationPluginWindow window,
            StudioComponent component) {
        m_window = window;
        m_component = component;
    }

    /**
     * Disconnects a component from the Meta-Environment when its panel is
     * closed.
     * 
     * @author Arend van Beelen
     * @author Anton Gerdesse
     * @date 19-03-2007
     */
    public void componentClose() {
        m_window.disconnectComponent(m_component);
    }

    public void componentFocusReceived() {
        m_window.createExtensionMenu();
    }

    public void componentRequestClose() throws CloseAbortedException {
    }

    public void statusMessageChanged(StatusMessageEvent event) {
    }
}
