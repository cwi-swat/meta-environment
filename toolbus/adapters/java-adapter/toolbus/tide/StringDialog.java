
package toolbus.tide;
import java.awt.*;

class StringDialog extends Dialog
{
  private Frame handler;
  private int id;
  private Object arg;
  private TextField string;
  private Button ok;
  private Button cancel;

  public StringDialog(Frame handler, String title, boolean modal, int id, Object arg)
  {
    super(handler, title, modal);
    this.handler = handler;
    this.id = id;
    this.arg = arg;
    string = new TextField();
    ok = new Button("Ok");
    cancel = new Button("Cancel");
    BorderLayout layout = new BorderLayout();
    setLayout(layout);
    add("North", string);
    add("West", ok);
    add("East", cancel);
    layout.addLayoutComponent("North", string);
    layout.addLayoutComponent("West", ok);
    layout.addLayoutComponent("East", cancel);
    resize(200, 100);
    show();
  }

  public boolean action(Event evt, Object what)
  {
    if(evt.target == ok) {
      handler.action(new Event(this, id, arg), string.getText());
      dispose();
      return true;
    }
    if(evt.target == cancel) {
      handler.action(new Event(this, id, arg), null);
      dispose();
      return true;
    }
    return false;
  }
}
