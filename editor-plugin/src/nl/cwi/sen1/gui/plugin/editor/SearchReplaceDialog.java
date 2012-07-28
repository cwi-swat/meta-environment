package nl.cwi.sen1.gui.plugin.editor;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;
import java.util.List;

import javax.swing.AbstractAction;
import javax.swing.ActionMap;
import javax.swing.ButtonGroup;
import javax.swing.InputMap;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.KeyStroke;

public class SearchReplaceDialog extends BaseDialog {
    private EditorPane editor;

    private JRadioButton backwardRadioButton;

    private JCheckBox caseSensitiveCheck;

    private JButton closeButton;

    private ButtonGroup directionButtonGroup;

    private JPanel directionPanel;

    private JButton findButton;

    private JComboBox findCombo;

    private JLabel findLabel;

    private JRadioButton forwardRadioButton;

    private JPanel jPanel1;

    private JPanel mainPanel;

    private JPanel optionsPanel;

    private JButton replaceAllButton;

    private JButton replaceButton;

    private JButton replaceFindButton;

    private JLabel replaceLabel;

    private JComboBox replaceWithCombo;

    private JCheckBox wrapSearchCheck;

    public String getFindText() {
        String findText = findCombo.getEditor().getItem().toString();
        return findText;
    }

    public void setFindText(String findText) {
        updateComboBox(findCombo, findText);
    }

    public boolean getFindDirection() {
        return forwardRadioButton.isSelected();
    }

    public boolean isCaseSensitiveSearch() {
        return caseSensitiveCheck.isSelected();
    }

    public boolean isWrappedSearch() {
        return wrapSearchCheck.isSelected();
    }

    public void setVisible(boolean b) {
        if (b) {
            String newSearch = editor.getSelectedText();
            if (newSearch != null && newSearch.length() != 0) {
                findCombo.insertItemAt(newSearch, 0);
                findCombo.setSelectedIndex(0);
            }
            findCombo.getEditor().selectAll();
            findCombo.requestFocus();
        }
        super.setVisible(b);
    }

    public SearchReplaceDialog(EditorPane editor, Frame frame) {
        super(frame);
        setTitle("Find/Replace");
        this.editor = editor;
        initComponents();
        forwardRadioButton.setSelected(true);
        wrapSearchCheck.setSelected(true);

        initBindings();
    }

    private void initBindings() {
        InputMap inputMap = this.getRootPane().getInputMap(
                JComponent.WHEN_IN_FOCUSED_WINDOW);
        inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), "escape");
        inputMap.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "enter");

        ActionMap actionMap = this.getRootPane().getActionMap();
        actionMap.put("escape", new AbstractAction() {
            public void actionPerformed(ActionEvent evt) {
                closeButtonActionPerformed();
            }
        });
        actionMap.put("enter", new AbstractAction() {
            public void actionPerformed(ActionEvent evt) {
                System.err.println("Enter action performed");
                findButtonActionPerformed();
            }
        });

        findCombo.getEditor().getEditorComponent().addKeyListener(
                new java.awt.event.KeyAdapter() {
                    public void keyPressed(java.awt.event.KeyEvent e) {
                        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                            findButtonActionPerformed();
                            e.consume();
                        }
                    }
                });
        
        replaceWithCombo.getEditor().getEditorComponent().addKeyListener(
                new java.awt.event.KeyAdapter() {
                    public void keyPressed(java.awt.event.KeyEvent e) {
                        if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                            findButtonActionPerformed();
                            e.consume();
                        }
                    }
                });
    }

    private void initComponents() {
        GridBagConstraints gridBagConstraints;

        directionButtonGroup = new ButtonGroup();
        jPanel1 = new JPanel();
        findButton = new JButton();
        replaceFindButton = new JButton();
        replaceButton = new JButton();
        replaceAllButton = new JButton();
        closeButton = new JButton();
        mainPanel = new JPanel();
        findLabel = new JLabel();
        replaceLabel = new JLabel();
        findCombo = new JComboBox();
        replaceWithCombo = new JComboBox();
        directionPanel = new JPanel();
        forwardRadioButton = new JRadioButton();
        backwardRadioButton = new JRadioButton();
        optionsPanel = new JPanel();
        caseSensitiveCheck = new JCheckBox();
        wrapSearchCheck = new JCheckBox();

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent evt) {
                closeDialog();
            }
        });

        jPanel1.setLayout(new GridBagLayout());

        findButton.setMnemonic('n');
        findButton.setText("Find");
        findButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                findButtonActionPerformed();
            }
        });

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.weightx = 0.5;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        jPanel1.add(findButton, gridBagConstraints);

        replaceFindButton.setMnemonic('d');
        replaceFindButton.setText("Replace/Find");
        replaceFindButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                replaceFindButtonActionPerformed();
            }
        });

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 0.5;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        jPanel1.add(replaceFindButton, gridBagConstraints);

        replaceButton.setMnemonic('R');
        replaceButton.setText("Replace");
        replaceButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                replaceButtonActionPerformed();
            }
        });

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.weightx = 0.5;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        jPanel1.add(replaceButton, gridBagConstraints);

        replaceAllButton.setMnemonic('A');
        replaceAllButton.setText("Replace All");
        replaceAllButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                replaceAllButtonActionPerformed();
            }
        });

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 0.5;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        jPanel1.add(replaceAllButton, gridBagConstraints);

        closeButton.setText("Close");
        closeButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                closeButtonActionPerformed();
            }
        });

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.anchor = GridBagConstraints.NORTHEAST;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        jPanel1.add(closeButton, gridBagConstraints);

        getContentPane().add(jPanel1, BorderLayout.SOUTH);

        mainPanel.setLayout(new GridBagLayout());

        findLabel.setText("Find:");
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.insets = new Insets(2, 0, 2, 2);
        mainPanel.add(findLabel, gridBagConstraints);

        replaceLabel.setText("Replace with:");
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.insets = new Insets(2, 0, 2, 2);
        mainPanel.add(replaceLabel, gridBagConstraints);

        findCombo.setEditable(true);
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 1.0;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        mainPanel.add(findCombo, gridBagConstraints);

        replaceWithCombo.setEditable(true);
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 1.0;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        mainPanel.add(replaceWithCombo, gridBagConstraints);

        directionPanel.setLayout(new GridBagLayout());

        directionPanel.setBorder(new javax.swing.border.TitledBorder(
                "Direction"));
        forwardRadioButton.setText("Forward");
        directionButtonGroup.add(forwardRadioButton);
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 0.5;
        directionPanel.add(forwardRadioButton, gridBagConstraints);

        backwardRadioButton.setText("Backward");
        directionButtonGroup.add(backwardRadioButton);
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.weightx = 0.5;
        directionPanel.add(backwardRadioButton, gridBagConstraints);

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        mainPanel.add(directionPanel, gridBagConstraints);

        optionsPanel.setLayout(new GridBagLayout());

        optionsPanel.setBorder(new javax.swing.border.TitledBorder("Options"));
        caseSensitiveCheck.setText("Case Sensitive");
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.anchor = GridBagConstraints.WEST;
        gridBagConstraints.weightx = 0.5;
        optionsPanel.add(caseSensitiveCheck, gridBagConstraints);

        wrapSearchCheck.setText("Wrap Search");
        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.anchor = GridBagConstraints.EAST;
        gridBagConstraints.weightx = 0.5;
        optionsPanel.add(wrapSearchCheck, gridBagConstraints);

        gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        gridBagConstraints.insets = new Insets(2, 2, 2, 2);
        mainPanel.add(optionsPanel, gridBagConstraints);

        getContentPane().add(mainPanel, BorderLayout.CENTER);

        pack();
    }

    private void closeButtonActionPerformed() {
        this.setVisible(false);
    }

    private void replaceAllButtonActionPerformed() {
        String textToFind = getFindText();
        updateComboBox(findCombo, textToFind);
        String textToReplaceWith = (String) replaceWithCombo.getSelectedItem();
        updateComboBox(replaceWithCombo, textToReplaceWith);
        editor.replaceAll(textToFind, textToReplaceWith,
                !isCaseSensitiveSearch());
    }

    private void replaceButtonActionPerformed() {
        String textToFind = getFindText();
        String selectedText = editor.getSelectedText();

        if ((isCaseSensitiveSearch() && textToFind.equals(selectedText))
                || (!isCaseSensitiveSearch() && textToFind
                        .equalsIgnoreCase(selectedText))) {
            String textToReplaceWith = (String) replaceWithCombo
                    .getSelectedItem();

            if (textToReplaceWith != null) {
                updateComboBox(replaceWithCombo, textToReplaceWith);
                int selectionStart = editor.getSelectionStart();
                editor.replaceSelection(textToReplaceWith);
                editor.setSelectionStart(selectionStart);
                editor.setSelectionEnd(selectionStart
                        + textToReplaceWith.length());
            }
        }
    }

    private void findButtonActionPerformed() {
        String textToFind = getFindText();
        updateComboBox(findCombo, textToFind);
        editor.find(textToFind, !isCaseSensitiveSearch(), isWrappedSearch(),
                getFindDirection());
    }

    private void replaceFindButtonActionPerformed() {
        replaceButtonActionPerformed();
        findButtonActionPerformed();
    }

    private void updateComboBox(JComboBox combo, String latestEntry) {
        int numItems = combo.getItemCount();
        List<String> items = new ArrayList<String>();
        for (int i = 0; i < numItems; i++) {
            String current = (String) combo.getItemAt(i);
            if ((current != null) && !current.equals(latestEntry)) {
                items.add(current);
            }
        }
        numItems = items.size();
        combo.removeAllItems();
        combo.addItem(latestEntry);
        for (int i = 0; i < numItems; i++) {
            combo.addItem(items.get(i));
        }
    }
}
