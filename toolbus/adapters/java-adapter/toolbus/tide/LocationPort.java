
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The location port represents ports at a specific location in the source.
 */

public class LocationPort extends DebugPort
{
  private SourceArea location;
  private ATermPattern patternPort;

  //{ public LocationPort(SourceArea loc, int when)

  /**
   * Construct a new LocationPort object.
   */

  public LocationPort(SourceArea loc, int when)
  {
    super(LOCATION, when);
    location = loc;
    if(location == null)
      throw new IllegalArgumentException("location cannot be null");
    init();
  }

  //}
  //{ public LocationPort(ATermRef loc, int when)

  /**
    * Construct a new LocationPort object given the term representation
    * of the location.
    */

  public LocationPort(ATermsRef loc, int when)
  {
    super(LOCATION, when);
    location = new SourceArea(loc);
    init();
  }

  //}
  //{ private void init()

  /**
    * Initalize needed patterns.
    */

  private void init()
  {
    try {
      patternPort = new ATermPattern("[location,<term>,<str>,<int>,<int>,<int>,<int>]");
    } catch (ParseError e) {
      throw new IllegalArgumentException("internal parse error");
    }
  }

  //}
  //{ public SourceArea getLocation()

  /**
   * Retrieve the location of this port.
   */

  public SourceArea getLocation()
  {
    return location;
  }

  //}
  //{ public ATermRef onthewire()

  /**
    * Build a term representing this debug port that can be send 
    * over the ToolBus.
    */

  public ATermRef onthewire()
  {
    return patternPort.make(getWhenTerm(), location.getModule(),
			    new Integer(location.getStartLine()),
			    new Integer(location.getStartColumn()),
			    new Integer(location.getEndLine()),
			    new Integer(location.getEndColumn()));
  }

  //}
}
