
package toolbus.tide;
import toolbus.aterm.*;

/**
 * The location port represents ports at a specific location in the source.
 */

public class LocationPort extends DebugPort
{
  private SourceArea location;

  //{ public LocationPort(SourceArea loc, int when)

  /**
   * Construct a new LocationPort object.
   */

  public LocationPort(SourceArea loc, int when)
  {
    super(LOCATION, when);
    location = loc;
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
}
