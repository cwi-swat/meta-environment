package org.autocode.generator.repository;

import java.util.*;

public class Attribute
{
  private String name;
  private String type;
  private String description;

  //{{{ public Attribute(String name, String type)

  public Attribute(String name, String type)
  {
    this.name = name;
    this.type = type;
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public String getType()

  public String getType()
  {
    return type;
  }

  //}}}

  //{{{ public String getDescription()

  public String getDescription()
  {
    return description;
  }

  //}}}
  //{{{ public void setDescription(String description)

  public void setDescription(String description)
  {
    this.description = description;
  }

  //}}}

  //{{{ public boolean equals(Object suspect)

  public boolean equals(Object suspect)
  {
    if (!(suspect instanceof Attribute)) {
      return false;
    }

    Attribute peer = (Attribute)suspect;
    return name.equals(peer.name) && type.equals(peer.type);
  }

  //}}}
}
