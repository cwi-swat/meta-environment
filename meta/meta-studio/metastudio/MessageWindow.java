package metastudio;

import java.io.*;
import javax.swing.*;
import java.awt.*;

public class MessageWindow extends JFrame {
    
    private MessageList list;
    
    public MessageWindow(MessageList l) throws IOException 
    { 
	list = l;
	
	JScrollPane pane = new JScrollPane(list);
	
	Container content = getContentPane();
	JPanel mainPanel = new JPanel();

	mainPanel.setLayout(new BorderLayout());
	mainPanel.setBorder(BorderFactory.createTitledBorder("Messages"));
	mainPanel.add(pane, BorderLayout.CENTER);
	content.setLayout(new BorderLayout());
	content.add(mainPanel, BorderLayout.CENTER);

	setTitle("Message list");
	setSize(300,400);
    }
}
