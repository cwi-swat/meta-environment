
package toolbus.tide;
import toolbus.aterm.*;

/**
 * A SourceArea object represents an area in the source code.
 */

public class SourceArea
{
  private String module;
  private int start_line;
  private int start_col;
  private int end_line;
  private int end_col;

  //{ public SourceArea(String mod, int sl, int sc, int el, int ec)

  /**
   * Create a new source area.
   * @argument module The area is in this module.
   * @argument start_line The start line of the area.
   * @argument start_col The start column of the area.
   * @argument end_line The end line of the area.
   * @argument end_col The end column of the area.
   */

  public SourceArea(String module, int start_line, int start_col, 
			int end_line, int end_col)
  {
    this.module = module;
    this.start_line = start_line;
    this.start_col = start_col;
    this.end_line = end_line;
    this.end_col = end_col;
  }

  //}
  //{ public SourceArea(ATermsRef area)

  /**
    * Construct a new SourceArea object given its term representation.
    */

  public SourceArea(ATermsRef area)
  {
    module = ((ATermApplRef)area.getFirst()).getFun();
    area = area.getNext();
    start_line = ((ATermIntRef)area.getFirst()).getInt();
    area = area.getNext();
    start_col = ((ATermIntRef)area.getFirst()).getInt();
    area = area.getNext();
    end_line = ((ATermIntRef)area.getFirst()).getInt();
    area = area.getNext();
    end_col = ((ATermIntRef)area.getFirst()).getInt();
  }

  //}
  //{ public String getModule()

  /**
    * Retrieve the module of this area.
    */

  public String getModule()
  {
    return module;
  }

  //}
  //{ public int getStartLine()

  /**
    * Retrieve the start line of the area.
    */

  public int getStartLine()
  {
    return start_line;
  }

  //}
  //{ public int getStartColumn()

  /**
    * Retrieve the start column of the area.
    */

  public int getStartColumn()
  {
    return start_col;
  }

  //}
  //{ public int getEndLine()

  /**
    * Retrieve the end line of the area.
    */

  public int getEndLine()
  {
    return end_line;
  }

  //}
  //{ public int getEndColumn()

  /**
    * Retrieve the end column of the area.
    */

  public int getEndColumn()
  {
    return end_col;
  }

  //}
  //{ public String toString()

  /**
    * Generate the string representation of this area.
    * An area is represented lie 12#23:14#7
    */

  public String toString()
  {
    String result = "" + start_line + "#";
    if(start_col == -1)
      result += "end";
    else result += start_col;

    result += ".." + end_line + "#";
    if(end_col == -1)
      result += "end";
    else
      result += end_col;

    return result;
  }

  //}
  //{ public void setModule(String mod)

  /**
    * Change the module this area refers to.
    */

  public void setModule(String mod)
  {
    module = mod;
  }

  //}
  //{ public void setStartLine(int line)

  /**
    * Change the starting line of this area.
    */

  public void setStartLine(int line)
  {
    start_line = line;
  }

  //}
  //{ public void setStartColumn(int col)

  /**
    * Change the starting column of this area.
    */

  public void setStartColumn(int col)
  {
    start_col = col;
  }

  //}
  //{ public void setEndLine(int line)

  /**
    * Change the end line of this area.
    */

  public void setEndLine(int line)
  {
    end_line = line;
  }

  //}
  //{ public void setEndColumn(int col)

  /**
    * Change the end column of this area.
    */

  public void setEndColumn(int col)
  {
    end_col = col;
  }

  //}
}
