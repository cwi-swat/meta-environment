
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
  //{ public LocationPort(ATermRef loc, int when)

  /**
    * Construct a new LocationPort object given the term representation
    * of the location.
    */

  public LocationPort(ATermsRef loc, int when)
  {
    super(LOCATION, when);
    location = new SourceArea(loc);
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
