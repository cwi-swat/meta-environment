package org.autocode.generator.repository;

public class FormalParameter
{
  //{{{ attributes

  private String _name;
  private String _type;
  private String _description;

  //}}}

  //{{{ public FormalParameter(String name, String type)

  public FormalParameter(String name, String type)
  {
    _name = name;
    _type = type;
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return _name;
  }

  //}}}
  //{{{ public String getType()

  public String getType()
  {
    return _type;
  }

  //}}}

  //{{{ public String getDescription()

  public String getDescription()
  {
    return _description;
  }

  //}}}
  //{{{ public void setDescription(String description)

  public void setDescription(String description)
  {
    _description = description;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    return getType() + " " + getName();
  }

  //}}}
}
