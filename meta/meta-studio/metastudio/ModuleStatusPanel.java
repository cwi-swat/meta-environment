package metastudio;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedList;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JComboBox;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

import aterm.ATermFactory;

public class ModuleStatusPanel extends JPanelTool implements ModuleSelectionListener {
    private static final String NO_MODULE_NAME = "No module";

    private TitledBorder border;
    private JComboBox importsBox;
    private JComboBox importedByBox;

    private List imports;
    private List importedBy;

    public ModuleStatusPanel(
        ATermFactory factory,
        UserInterfaceBridge bridge,
        final ModuleTreeModel moduleManager) {
        super(factory, bridge);

        imports = new LinkedList();
        importedBy = new LinkedList();

        border = new TitledBorder(new LineBorder(Color.black), NO_MODULE_NAME);
        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        setBorder(border);

        importsBox = makeComboBox(moduleManager, "Import", imports);
        add(importsBox);
        
        importedByBox = makeComboBox(moduleManager, "Imported by", importedBy);
        add(importedByBox);

      
        moduleManager.addModuleSelectionListener(this);
    }

    private JComboBox makeComboBox(final ModuleTreeModel moduleManager, String title, final List elems) {
        final JComboBox box = new JComboBox();
        box.setToolTipText(title);
        box.setModel(new ComboBoxModel(elems));
        box.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected = (String) box.getSelectedItem();
                if (selected != null) {
                  moduleManager.selectModule(selected);
                }
            }
        });
        
        return box;
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            clearInfo();
        } else {
            updateInfo(module);
        }
    }

    private void clearInfo() {
        border.setTitle(NO_MODULE_NAME);

        imports.clear();
        importsBox.removeAll();

        importedBy.clear();
        importedByBox.removeAll();

        repaint();
        importsBox.repaint();
        importedByBox.repaint();
    }

    private void updateInfo(Module module) {
        border.setTitle(module.getName());

        imports.clear();
        List children = module.getChildren();
        if (children != null) {
            imports.addAll(children);
        }
        importsBox.setSelectedItem(null);

        importedBy.clear();
        List parents = module.getParents();
        if (parents != null) {
            importedBy.addAll(parents);
        }
        importedByBox.setSelectedItem(null);

        repaint();
        importsBox.repaint();
        importedByBox.repaint();
    }
}
