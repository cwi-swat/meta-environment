package org.autocode.generator.java;

import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.bootstrap.generator.repository.*;

public class JavaGenerator
  extends AutocodeGenerator
{
  private Repository repository;
  private JavaCompilationUnit compilationUnit;

  //{{{ public void generate(PropertyContext context)

  public void generate(PropertyContext context)
  {
    repository = new Repository();
    super.generate(context);
  }

  //}}}
  //{{{ public JavaCompilationUnit getCompilationUnit()

  public JavaCompilationUnit getCompilationUnit()
  {
    return compilationUnit;
  }

  //}}}

  //{{{ public String typeName(String typeName)

  public String typeName(String typeName)
  {
    return AutocodeGenerator.javaTypeName(typeName);
  }

  //}}}
  //{{{ public String attributeName(String attributeName)

  public String attributeName(String attributeName)
  {
    return AutocodeGenerator.javaAttributeName(attributeName);
  }

  //}}}
  //{{{ public String methodName(String methodName)

  public String methodName(String methodName)
  {
    return AutocodeGenerator.javaMethodName(methodName);
  }

  //}}}
  //{{{ public String parameterName(String parameterName)

  public String parameterName(String parameterName)
  {
    return AutocodeGenerator.javaParameterName(parameterName);
  }

  //}}}

  //{{{ protected void generateType(String typeName, PropertyContext context)

  protected void generateType(String typeName, PropertyContext context)
  {
    String pkg = context.getString("package");
    String className = javaTypeName(typeName);
    String superClass = "";
    int access = context.getInteger("access");
    boolean isstatic = context.getBoolean("static");
    boolean isabstract = context.getBoolean("abstract");
    boolean isfinal = context.getBoolean("final");

    compilationUnit = new JavaCompilationUnit(pkg, className, superClass,
					      access, isstatic, isabstract,
					      isfinal);

    repository.addCompilationUnit(compilationUnit);

    super.generateType(typeName, context);
  }

  //}}}
}
