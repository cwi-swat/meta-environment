package metastudio.components;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
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

import metastudio.MultiBridge;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import aterm.ATermFactory;

// TODO: white color, and only last name in border
public class ModuleStatusPanel extends ToolComponent implements ModuleSelectionListener {
    private static final String NOT_IMPORTED = "not imported";
    private static final String NO_IMPORTS = "no imports";
    private static final String IMPORTED_BY = "imported";
    private static final String IMPORTS = "imports";
    private static final String NO_MODULE_NAME = "No module";

    private TitledBorder border;

    private List imports;
    private List importedBy;

    private JButton importedByMenu;
    private JButton importsMenu;

    public ModuleStatusPanel(
        ATermFactory factory,
        MultiBridge bridge,
        final ModuleTreeModel moduleManager) {
        super(factory, bridge);

        border = new TitledBorder(new LineBorder(Color.black), NO_MODULE_NAME);

        setBorder(border);
        setBackground(Color.white);

        imports = new LinkedList();
        importsMenu = makeModuleSelectionMenu(IMPORTS, imports, moduleManager);
        importsMenu.setBackground(Color.white);
        add(importsMenu, BorderLayout.NORTH);

        importedBy = new LinkedList();
        importedByMenu = makeModuleSelectionMenu(IMPORTED_BY, importedBy, moduleManager);
        importedByMenu.setBackground(Color.white);
        add(importedByMenu, BorderLayout.SOUTH);

        setMaximumSize(
            new Dimension(
                (int) getMaximumSize().getWidth(),
                importsMenu.getHeight() + importedByMenu.getHeight()));
        clearInfo();

        moduleManager.addModuleSelectionListener(this);
    }

    private JButton makeModuleSelectionMenu(
        String title,
        final List modules,
        final ModuleTreeModel manager) {
        final JButton menu = new JButton(title);
        menu.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showModuleSelectionPopup(menu, modules, manager);
            }
        });
        return menu;
    }

    protected void showModuleSelectionPopup(
        JButton menu,
        List modules,
        final ModuleTreeModel manager) {
        JPopupMenu popup = new JPopupMenu();
        addItems(popup, modules, manager);
        popup.show(menu, menu.getWidth(), 0);
    }

    private void addItems(JPopupMenu pop, List imports2, final ModuleTreeModel manager) {
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
        importsMenu.setText(NO_IMPORTS);

        importedBy.clear();
        importedByMenu.setText(NOT_IMPORTED);

        setTitles(NO_MODULE_NAME);
    }

    private void updateInfo(Module module) {
        updateImports(module);
        updateImportedBy(module);
        setTitles(module.getName());
    }

    private void updateImportedBy(Module module) {
        importedBy.clear();
        List parents = module.getParents();
        if (parents != null) {
            importedBy.addAll(parents);
        }
    }

    private void updateImports(Module module) {
        imports.clear();
        List children = module.getChildren();
        if (children != null) {
            imports.addAll(children);
        }
    }

    private void setTitles(String title) {
        int slash = title.lastIndexOf('/');
        border.setTitle(slash > 0 ? title.substring(slash + 1) : title);

        if (imports.size() > 0) {
            importsMenu.setText(IMPORTS);
        } else {
            importsMenu.setText(NO_IMPORTS);
        }

        if (importedBy.size() > 0) {
            importedByMenu.setText(IMPORTED_BY);
        } else {
            importedByMenu.setText(NOT_IMPORTED);
        }

        repaint();
    }
}
