package org.autocode.bootstrap.generator.repository;

public class FormalParameter
{
  //{{{ attributes

  private String _name;
  private String _type;

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
}
