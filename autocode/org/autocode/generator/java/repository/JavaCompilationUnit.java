package org.autocode.generator.java.repository;

//{{{ imports

import org.autocode.generator.repository.*;
import org.autocode.generator.java.repository.*;
import java.util.*;

//}}}

public class JavaCompilationUnit
  extends CompilationUnit
{
  //{{{ attributes

  private String packageName;
  private String className;
  private String superClass;
  private Set importedSet;

  private StringBuffer verbatimContent;

  private JavaAccessSpecifier _access;
  private boolean _static;
  private boolean _abstract;
  private boolean _final;

  //}}}

  //{{{ public JavaCompilationUnit(package, class, super, access, static, abstract, final)

  public JavaCompilationUnit(String packageName, String className,
			     String superClass, JavaAccessSpecifier access,
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
    verbatimContent = new StringBuffer();
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

  //{{{ public void addVerbatim(String verbatim)

  public void addVerbatim(String verbatim)
  {
    verbatimContent.append(verbatim);
  }

  //}}}
  //{{{ public String getVerbatim()

  public String getVerbatim()
  {
    return verbatimContent.toString();
  }

  //}}}

  //{{{ public JavaAccessSpecifier getAccess()

  public JavaAccessSpecifier getAccess()
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
  //{{{ public void mergeImportedCollection(Collection c)

  public void mergeImportedCollection(Collection c)
  {
    importedSet.addAll(c);
  }

  //}}}
  //{{{ public Iterator fetchImportedIterator()

  public Iterator fetchImportedIterator()
  {
    return importedSet.iterator();
  }

  //}}}

  //{{{ public String getDeclaration()

  public String getDeclaration()
  {
    StringBuffer buf = new StringBuffer();

    buf.append(getAccess().yield());

    if (isAbstract()) {
      buf.append(" abstract");
    }

    if (isStatic()) {
      buf.append(" static");
    }

    if (isFinal()) {
      buf.append(" final");
    }

    buf.append(" class ");
    buf.append(getClassName());

    return buf.toString();
  }

  //}}}
}
