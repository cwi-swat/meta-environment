package org.autocode.generator.repository.java;

//{{{ imports

import org.autocode.generator.repository.*;
import java.util.*;

//}}}

public class JavaCompilationUnit
  extends CompilationUnit
{
  //{{{ accessSpecifiers 

  private String packageName;
  private String className;
  private String superClass;
  private Set importedSet;

  private int _access;
  private boolean _static;
  private boolean _abstract;
  private boolean _final;

  //}}}

  //{{{ public JavaCompilationUnit(package, class, super, access, static, abstract, final)

  public JavaCompilationUnit(String packageName, String className,
			     String superClass, int access,
			     boolean isstatic, boolean isabstract,
			     boolean isfinal)
  {
    this.packageName = packageName;
    this.className = className;
    this.superClass = superClass;
    _access = access;
    _static = isstatic;
    _abstract = isabstract;
    _final = isfinal;
    importedSet = new HashSet();
  }

  //}}}

  //{{{ public String getPackageName()

  public String getPackageName()
  {
    return packageName;
  }

  //}}}
  //{{{ public String getClassName()

  public String getClassName()
  {
    return className;
  }

  //}}}
  //{{{ public String getSuperClass()

  public String getSuperClass()
  {
    return superClass;
  }

  //}}}
  //{{{ public void setSuperClass(String superClass)

  public void setSuperClass(String superClass)
  {
    this.superClass = superClass;
  }

  //}}}

  //{{{ public int getAccess()

  public int getAccess()
  {
    return _access;
  }

  //}}}

  //{{{ public boolean isStatic()

  public boolean isStatic()
  {
    return _static;
  }

  //}}}
  //{{{ public boolean isAbstract()

  public boolean isAbstract()
  {
    return _abstract;
  }

  //}}}
  //{{{ public boolean isFinal()

  public boolean isFinal()
  {
    return _final;
  }

  //}}}

  //{{{ public void addImported(String imported)

  public void addImported(String imported)
  {
    importedSet.add(imported);
  }

  //}}}
  //{{{ public Iterator fetchImportedIterator()

  public Iterator fetchImportedIterator()
  {
    return importedSet.iterator();
  }

  //}}}
}
