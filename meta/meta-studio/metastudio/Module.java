package metastudio;

//{{{ imports

import java.util.Iterator;
import java.util.List;
import java.util.LinkedList;

import javax.swing.*;

//}}}

public class Module
  implements Comparable
{
  //{{{ Possible module states

  public static final int STATE_NORMAL = 0;
  public static final int STATE_NEW = 1;

  //}}}

  //{{{ attributes

  private String _name;

  private List _parent;

  private List _child;
  private ListListModel childListModel;
  private ListListModel parentListModel;

  private int State = STATE_NORMAL;

  //}}}

  //{{{ public Module(String name)

  public Module(String name)
  {
    setName(name);
    initParentList();

    childListModel = new ListListModel(_child);
    parentListModel = new ListListModel(_parent);
    initChildList();
  }

  //}}}

  //{{{ public int compareTo(Object o)

  public int compareTo(Object o)
  {
    return _name.compareTo(o);
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return _name;
  }

  //}}}
  //{{{ private void setName(String name)

  private void setName(String name)
  {
    _name = name;
  }

  //}}}

  //{{{ public void addParent(String parent)

  public void addParent(String parent)
  {
    _parent.add(parent);
    parentListModel.elementAdded();
  }

  //}}}
  //{{{ private void initParentList()

  private void initParentList()
  {
    _parent = new LinkedList();
  }

  //}}}
  //{{{ public Iterator fetchParentIterator()

  public Iterator fetchParentIterator()
  {
    return _parent.iterator();
  }

  //}}}
  //{{{ public ListModel fetchParentListModel()

  public ListModel fetchParentListModel()
  {
    return parentListModel;
  }

  //}}}

  //{{{ public void addChild(String child)

  public void addChild(String child)
  {
    _child.add(child);
    childListModel.elementAdded();
  }

  //}}}
  //{{{ private void initChildList()

  private void initChildList()
  {
    _child = new LinkedList();
    childListModel.setList(_child);
  }

  //}}}
  //{{{ public Iterator fetchChildIterator()

  public Iterator fetchChildIterator()
  {
    return _child.iterator();
  }

  //}}}
  //{{{ public ListModel fetchChildListModel()

  public ListModel fetchChildListModel()
  {
    return childListModel;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    return _name;
  }

  //}}}
  //{{{  public int getState()


  public int getState() {
    return State;
  }

  //}}}
  //{{{  public int setState()


  public void setState(int State) {
    this.State = State;
  }

  //}}}
}
