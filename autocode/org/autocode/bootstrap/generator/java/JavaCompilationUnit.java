package org.autocode.bootstrap.generator.java;

//{{{ imports

import org.autocode.bootstrap.generator.repository.*;
import org.autocode.support.*;
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
  private TypedMap accessSpecifiers;

  //{{{ private static final EnumerationMap accessEnumerationMap

  private static final EnumerationMap accessEnumerationMap =
    new EnumerationMap() {
      public int parse(String value)
      {
	if (value.equals("private")) {
	  return 0;
	} else if (value.equals("protected")) {
	  return 1;
	} else if (value.equals("anonymous")) {
	  return 2;
	} else if (value.equals("public")) {
	  return 3;
	}

	throw new IllegalArgumentException("illegal enumeration literal: "
					   + value);
      }

      public String yield(int value)
      {
	switch (value) {
	  case 0: return "private";
	  case 1: return "protected";
	  case 2: return "anonymous";
	  case 3: return "public";
	}

	throw new IllegalArgumentException("illegal enumeration value: "
					   + value);
      }
    };

  //}}}

  //}}}

  //{{{ public JavaCompilationUnit(packageName, className, superClass, access)

  public JavaCompilationUnit(String packageName, String className,
			     String superClass, TypedMap accessSpecifiers)
  {
    this.packageName = packageName;
    this.className = className;
    this.superClass = superClass;
    importedSet = new HashSet();
    this.accessSpecifiers = accessSpecifiers;
  }

  //}}}
  //{{{ public JavaCompilationUnit(packageName, className, accessSpecifiers)

  public JavaCompilationUnit(String packageName, String className,
			     TypedMap accessSpecifiers)
  {
    this(packageName, className, null, accessSpecifiers);
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
    return accessSpecifiers.getEnumeration("access", accessEnumerationMap);
  }

  //}}}

  //{{{ public boolean isStatic()

  public boolean isStatic()
  {
    return accessSpecifiers.getBoolean("static");
  }

  //}}}
  //{{{ public boolean isAbstract()

  public boolean isAbstract()
  {
    return accessSpecifiers.getBoolean("abstract");
  }

  //}}}
  //{{{ public boolean isFinal()

  public boolean isFinal()
  {
    return accessSpecifiers.getBoolean("final");
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
