package metaedit;

import aterm.pure.PureFactory;
import aterm.ATermFactory;
import java.io.IOException;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class Main {
  private ATermFactory factory;
  public Main(String[] args) {
    factory = new aterm.pure.PureFactory();
    EditorModel editorModel = new EditorModel((PureFactory)factory);
    try{
	Controller controller = new Controller(editorModel, factory);
 	controller.getView().show();
 	controller.runBridge(args);
	}catch (IOException ex) {
        }
    }

public static void main(String[] args) throws IOException, RuntimeException  {
    Main main1 = new Main(args);
  }

}
