
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
}
