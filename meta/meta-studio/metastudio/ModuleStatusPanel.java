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

        importsBox = new JComboBox();
        importsBox.setToolTipText("imports");
        importsBox.setModel(new ComboBoxModel(imports));
        importsBox.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected = (String) importsBox.getSelectedItem();
                if (selected != null) {
                    moduleManager.selectModule(selected);
                }
            }
        });
        add(importsBox);

        importedByBox = new JComboBox();
        importedByBox.setToolTipText("imported by");
        importedByBox.setModel(new ComboBoxModel(importedBy));
        importedByBox.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected = (String) importedByBox.getSelectedItem();
                if (selected != null) {
                    moduleManager.selectModule(selected);
                }
            }
        });
        add(importedByBox);

        moduleManager.addModuleSelectionListener(this);
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
        importedBy.clear();
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
    }
}
