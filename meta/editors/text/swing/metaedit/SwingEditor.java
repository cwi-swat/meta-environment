package metaedit;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;
import java.util.Vector;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTextPane;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;
import javax.swing.text.Document;
import javax.swing.text.StyledDocument;

import metaedit.style.Highlighter;


/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class SwingEditor
    extends JFrame
    implements Observer {

  private final Clipboard clipboard = Toolkit.getDefaultToolkit().
      getSystemClipboard();

  /* ---- GUI elements ---------*/
  private JToolBar editorToolBar;
  protected JTextPane swingEditorPane;
  private JScrollPane swingEditorScrollPane;
  private JPanel bottomPanel;
  private JLabel statusBar = new JLabel();
  private Controller controller;
  private StyledDocument document;
  private Document contentModel;
  private int offsetTemp=-1;
  private int lengthTemp=-1;
  private int offset;
  private int length;
  private Vector highlighters;
  private Highlighter highlighter;

  // Variables declaration for menubar and all menu items
  private JMenu fileMenu;
  private JMenu helpMenu;
  private JMenu searchMenu;
  private JMenuBar menuBar;
  protected JMenuItem aboutMenuItem;
  protected JMenuItem copyMenuItem;
  protected JMenuItem cutMenuItem;
  protected JMenu editMenu;
  protected JMenuItem exitMenuItem;
  protected JMenuItem pasteMenuItem;
  protected JMenuItem redoMenuItem;
  protected JMenuItem saveMenuItem;
  protected JMenuItem undoMenuItem;
  protected JMenuItem findMenuItem;
  protected JMenuItem replaceMenuItem;
  

  // Variables declaration for all Separators
  private JSeparator fileMenuSeparator;
  private JSeparator editMenuSeparator;

  // Variables declaration for all image icons that will be used by the buttons
  private ImageIcon undoImage,
      redoImage,
      copyImage,
      pasteImage,
      cutImage,
      messagesImageUp,
      messagesImageDown,
      closeFileImage,
      helpImage,
      saveFileImage;

  // Variables declaration for the buttons
  protected JButton undoButton,
      redoButton,
      copyButton,
      pasteButton,
      cutButton, searchButton;

  public SwingEditor() {
    initialize();
  }

  public void update(Observable o, Object arg) {
    EditorModel model = (EditorModel) o;
    if (arg.equals("writeContents")) {
      try {
        FileWriter fileWriter=new FileWriter(model.getFileName());
        swingEditorPane.write(fileWriter);
        fileWriter.close();
		System.out.println("SwingEditor: File is written......");
      }
      catch (FileNotFoundException e) {
        System.out.println("File not found");
      }
      catch (IOException e) {
        System.out.println("I/O error");
      }

    }
    else if (arg.equals("editFile")) {
      try {
		  this.setTitle(model.getFileName());
		  BufferedReader br = new BufferedReader(new FileReader(model.getFileName()));
        String nextLine = "";
        StringBuffer sb = new StringBuffer();
        int x =0;
        while ((nextLine = br.readLine()) != null) {
          if(x==0){
            sb.append(nextLine);
          }else{
            sb.append("\n"+nextLine);
          }
          x++;
        }
        swingEditorPane.setText(sb.toString());
         
      }
      catch (FileNotFoundException e) {
        System.out.println("File not found");
      }
      catch (IOException e) {
        System.out.println("I/O error");
      }
      
    }
    else if (arg.equals("setFocus")) {
	 model.getFocuser().clearFocus(document, model.getNormalStyle().getBgColor()); 
	  offset = model.getBeginFocus();
      length = model.getFocusLength();
	  highlighters=model.getHighlighters();
   	 for (int i=0; i< highlighters.size();i++){
   	 	highlighter =(Highlighter) highlighters.get(i);	
		highlighter.setHighlight(document);
 	 }
	 model.getFocuser().setFocus(document,  offset, length);
	  }  else if (arg.equals("clearFocus")) {
		model.getFocuser().clearFocus(document, model.getNormalStyle().getBgColor());
		highlighters=model.getHighlighters();
		   for (int i=0; i< highlighters.size();i++){
			  highlighter =(Highlighter) highlighters.get(i);	
			  highlighter.setHighlight(document);
		   } 
    }else if (arg.equals("Message")) {
      statusBar.setText("...:: " + model.getMessage());
    }
    else if (arg.equals("addActions")) {
      JMenuBar bar = model.getMenuBar();
      setMenuListener(bar);
      setJMenuBar(menuBar);
      bar.add(fileMenu, 0);
      bar.add(editMenu, 1);
      bar.add(searchMenu, 2);
      bar.add(helpMenu);
      setJMenuBar(bar);
      bar.updateUI();
    }
	else if (arg.equals("setStyles")) {
		model.getNormalStyle().setStyle(document, 0, contentModel.getLength());
		highlighters=model.getHighlighters();
		int i=0;
		for (i=0; i< highlighters.size();i++){
		   highlighter =(Highlighter) highlighters.get(i);	
		   highlighter.setHighlight(document);
		}
	}
 }


// This method is called from within the constructor to initialize the form.
  private void initialize() {
    getContentPane().setLayout(new BorderLayout());
    searchButton = new JButton("");
    undoButton = new JButton();
    redoButton = new JButton();
    copyButton = new JButton();
    pasteButton = new JButton();
    cutButton = new JButton();
    statusBar.setText(" ");
    this.setSize(new Dimension(600, 600));
    closeFileImage =new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/close.gif"));
    helpImage =new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/help.png"));
    saveFileImage =new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/save2.gif"));
    undoImage =new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/undo.gif"));
    redoImage = new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/redo.gif"));
    copyImage = new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/copy.gif"));
    pasteImage = new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/paste.gif"));
    cutImage = new ImageIcon(SwingEditor.class.getResource("nl/cwi/editor/images/cut.gif"));

    undoButton.setIcon(undoImage);
    undoButton.setToolTipText("Undo");
    undoButton.setBorderPainted(false);

    redoButton.setIcon(redoImage);
    redoButton.setToolTipText("Redo");
    redoButton.setBorderPainted(false);

    
    copyButton.setToolTipText("Copy");
    copyButton.setBorderPainted(false);
    copyButton.setIcon(copyImage);

    pasteButton.setToolTipText("Paste");
    pasteButton.setBorderPainted(false);
    pasteButton.setIcon(pasteImage);

    cutButton.setToolTipText("Cut");
    cutButton.setBorderPainted(false);
    cutButton.setIcon(cutImage);

    // Jtoolbar
    editorToolBar = new JToolBar();
    editorToolBar.setOrientation(JToolBar.HORIZONTAL);
    editorToolBar.setEnabled(true);
    searchButton.setIcon(messagesImageDown);
    searchButton.setBorderPainted(false);
    searchButton.setToolTipText("Cut");
    editorToolBar.add(undoButton);
    editorToolBar.add(redoButton);
    editorToolBar.add(copyButton);
    editorToolBar.add(pasteButton);
    editorToolBar.add(cutButton);
    editorToolBar.addSeparator();
    editorToolBar.addSeparator();
    editorToolBar.add(searchButton);
    
    fileMenuSeparator = new JSeparator();
    editMenuSeparator = new JSeparator();

    //menuBar and menuIems
    menuBar = new JMenuBar();
    searchMenu = new JMenu("Search");
    fileMenu = new JMenu();
    saveMenuItem = new JMenuItem();
    exitMenuItem = new JMenuItem();
    editMenu = new JMenu();
    undoMenuItem = new JMenuItem();
    redoMenuItem = new JMenuItem();
    cutMenuItem = new JMenuItem();
    copyMenuItem = new JMenuItem();
    pasteMenuItem = new JMenuItem();
    helpMenu = new JMenu();
    aboutMenuItem = new JMenuItem();
    findMenuItem = new JMenuItem("find...");
    replaceMenuItem = new JMenuItem("replace...");
   
    fileMenu.setText("File");
    fileMenu.add(saveMenuItem);
    fileMenu.add(fileMenuSeparator);

    
    //Menu item save
    saveMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_S, java.awt.event.InputEvent.CTRL_MASK));
    saveMenuItem.setText("Save File");
    saveMenuItem.setIcon(saveFileImage);
   

    exitMenuItem.setText("Close");
    exitMenuItem.setIcon(closeFileImage);
    fileMenu.add(exitMenuItem);

    menuBar.add(fileMenu);
    editMenu.setText("Edit");
    undoMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_Z, java.awt.event.InputEvent.CTRL_MASK));
    undoMenuItem.setMnemonic('U');
    undoMenuItem.setText("Undo");
    editMenu.add(undoMenuItem);

    redoMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_R, java.awt.event.InputEvent.CTRL_MASK));
    redoMenuItem.setMnemonic('R');
    redoMenuItem.setText("Redo");
    editMenu.add(redoMenuItem);

    editMenu.add(editMenuSeparator);

    cutMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_X, java.awt.event.InputEvent.CTRL_MASK));
    cutMenuItem.setText("Cut");
    editMenu.add(cutMenuItem);

    //Menu item Copy
    copyMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_C, java.awt.event.InputEvent.CTRL_MASK));
    copyMenuItem.setText("Copy");
    editMenu.add(copyMenuItem);

    //Menu item Paste
    pasteMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_V, java.awt.event.InputEvent.CTRL_MASK));
    pasteMenuItem.setText("Paste");
    editMenu.add(pasteMenuItem);

    //Menu item find
    findMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.
        VK_F, java.awt.event.InputEvent.CTRL_MASK));
    searchMenu.add(findMenuItem);

    //Menu item find
    replaceMenuItem.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.
        KeyEvent.
        VK_H, java.awt.event.InputEvent.CTRL_MASK));
    searchMenu.add(replaceMenuItem);

      //Menu item Delete
    menuBar.add(editMenu);
    menuBar.add(searchMenu);
    helpMenu.setText("Help");
    aboutMenuItem.setText("About");
    helpMenu.add(aboutMenuItem);
    menuBar.add(helpMenu);
    setJMenuBar(menuBar);

    //editorPane, scrollpane, document and editorKit
    swingEditorScrollPane = new JScrollPane();
    swingEditorPane = new JTextPane();
    swingEditorPane.setEditable(true);
    document = swingEditorPane.getStyledDocument();
    contentModel=swingEditorPane.getDocument();

    bottomPanel = new JPanel(new BorderLayout());

    swingEditorPane.setPreferredSize(new java.awt.Dimension(606, 400));
    swingEditorPane.setSelectionColor(new Color(0, 255, 0));
    swingEditorScrollPane.setViewportView(swingEditorPane);
    getContentPane().add(swingEditorScrollPane, BorderLayout.CENTER);
    getContentPane().add(statusBar, BorderLayout.SOUTH);
    this.getContentPane().add(editorToolBar, BorderLayout.NORTH);
  }

  //set menuListener for the meta-env actions
  public void setMenuListener(JMenuBar bar) {
    int MenuCount = bar.getMenuCount();
    int menuItemsCount = 0;
    for (int i = 0; i < MenuCount; i++) {
      menuItemsCount = bar.getMenu(i).getItemCount();
      for (int j = 0; j < menuItemsCount; j++) {
        bar.getMenu(i).getItem(j).addActionListener(controller);
      }
    }
  }

  public void setController(Controller controller) {
    this.controller = controller;
  }

  public void setListener() {
    //action listener for all buttons
    exitMenuItem.addActionListener(controller);
    saveMenuItem.addActionListener(controller);
    findMenuItem.addActionListener(controller);
    replaceMenuItem.addActionListener(controller);
    redoButton.addActionListener(controller);
    redoMenuItem.addActionListener(controller);
    undoButton.addActionListener(controller);
    undoMenuItem.addActionListener(controller);
	 cutMenuItem.addActionListener(controller);
    copyMenuItem.addActionListener(controller);
    pasteMenuItem.addActionListener(controller);
    cutButton.addActionListener(controller);
    copyButton.addActionListener(controller);
    pasteButton.addActionListener(controller);
   
    //mouselistener
    swingEditorPane.addMouseListener(controller);
    contentModel.addUndoableEditListener(controller);
    
    
    this.addWindowListener(controller);
    }
}
