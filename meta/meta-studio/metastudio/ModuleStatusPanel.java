package metastudio;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JMenuItem;
import javax.swing.JPopupMenu;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;

import aterm.ATermFactory;

public class ModuleStatusPanel extends JPanelTool implements ModuleSelectionListener {
    private static final String NO_MODULE_NAME = "No module";

    private TitledBorder border;
    
    private List imports;
    private List importedBy;

    private JButton importedByMenu;
    private JButton importsMenu;

    public ModuleStatusPanel(
        ATermFactory factory,
        UserInterfaceBridge bridge,
        final ModuleTreeModel moduleManager) {
        super(factory, bridge);

        border = new TitledBorder(new LineBorder(Color.black), NO_MODULE_NAME);
        setLayout(new GridLayout());
        setBorder(border);

        imports = new LinkedList();
        importsMenu = makeModuleSelectionMenu("imports",imports,moduleManager);
        add(importsMenu);
        
        importedBy = new LinkedList();
        importedByMenu = makeModuleSelectionMenu("imported by", importedBy, moduleManager);
        add(importedByMenu);
        
        clearInfo();
        
        moduleManager.addModuleSelectionListener(this);
    }
    
    private JButton makeModuleSelectionMenu(String title, final List modules, final ModuleTreeModel manager) {
        final JButton menu = new JButton(title);
        menu.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showModuleSelectionPopup(menu, modules, manager);
            }
        });
        return menu;
    }

    protected void showModuleSelectionPopup(JButton menu, List modules, final ModuleTreeModel manager) {
        JPopupMenu popup = new JPopupMenu();
        addItems(popup, modules, manager);
        popup.show(menu,0,menu.getHeight());
    }

    private void addItems(JPopupMenu pop, List imports2, final ModuleTreeModel manager ) {
        Iterator iter = imports2.iterator();
        
        while (iter.hasNext()) {
            final String itemName = (String) iter.next();
            JMenuItem item = new JMenuItem(itemName);
            item.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    manager.selectModule(itemName);
                }
            });
            pop.add(item);
        }
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            clearInfo();
        } else {
            updateInfo(module);
        }
    }

    private void clearInfo() {
        imports.clear();
        importedBy.clear();

        setTitle(NO_MODULE_NAME);
        importsMenu.setText("no imports");
        importedByMenu.setText("not imported");
    }


    private void updateInfo(Module module) {
        imports.clear();
        List children = module.getChildren();
        if (children != null) {
            imports.addAll(children);
        }

        importedBy.clear();
        List parents = module.getParents();
        if (parents != null) {
            importedBy.addAll(parents);
        }
        
        setTitle(module.getName());
    }
    
    private void setTitle(String title) {
        border.setTitle(title);
        importsMenu.setText(imports.size() + " import" + (imports.size() > 1 ? "s" : ""));
        importedByMenu.setText("imported by " + importedBy.size());
        repaint();
    }
}
