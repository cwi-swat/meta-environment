package org.autocode.generator.java;

//{{{ imports

import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.repository.*;

import java.io.*;
import java.util.*;

//}}}

public class JavaGenerator
  extends AutocodeGenerator
{
  //{{{ attributes 

  private Repository repository;
  private JavaCompilationUnit compilationUnit;

  private PrintWriter writer;
  private int indentLevel;

  //}}}

  //{{{ public JavaCompilationUnit getCompilationUnit()

  public JavaCompilationUnit getCompilationUnit()
  {
    return compilationUnit;
  }

  //}}}

  //{{{ public void generate(PropertyContext generatorContext)

  public void generate(PropertyContext generatorContext)
  {
    repository = new Repository();
    super.generate(generatorContext);
  }

  //}}}
  //{{{ protected void generateType(PropertyContext typeContext)

  protected void generateType(PropertyContext typeContext)
  {
    System.out.println("generating type: " + typeContext.getName());
    String typeName = typeContext.getName();
    String pkg = typeContext.getString("package");
    String className = javaTypeName(typeName);
    String superClass = "";
    String access = typeContext.getString("access");
    JavaAccessSpecifier accessSpecifier = JavaAccessSpecifier.parse(access);
    boolean isstatic = typeContext.getBoolean("static");
    boolean isabstract = typeContext.getBoolean("abstract");
    boolean isfinal = typeContext.getBoolean("final");

    compilationUnit = new JavaCompilationUnit(pkg, className, superClass,
					      accessSpecifier,
					      isstatic, isabstract, isfinal);

    repository.addCompilationUnit(compilationUnit);

    super.generateType(typeContext);
  }

  //}}}

  //{{{ public void emit(PropertyContext generatorContext) throws IOException

  public void emit(PropertyContext generatorContext) throws IOException
  {
    String root = generatorContext.getString("rootdir");

    Iterator iter = repository.fetchCompilationUnitIterator();
    while (iter.hasNext()) {
      indentLevel = 0;
      JavaCompilationUnit unit = (JavaCompilationUnit)iter.next();
      String pkgName = unit.getPackageName();
      String reldir = pkgName.replace('.', File.separatorChar);
      String absdir = root + File.separatorChar + reldir;
      File file = new File(absdir, unit.getClassName() + ".java");
      System.out.println("emitting: " + file);

      writer = new PrintWriter(new FileWriter(file));

      emitCompilationUnit(unit);

      writer.close();
    }
  }

  //}}}
  //{{{ protected void emitCompilationUnit(JavaCompilationUnit unit)

  protected void emitCompilationUnit(JavaCompilationUnit unit)
  {
    emitPackage(unit);
    emitImports(unit);
    println(unit.getAccess().yield() + " class " + unit.getClassName());
    emitExtends(unit);
    emitMethods(unit);
    println("{");
    indentLevel++;
    emitAttributes(unit);
    emitMethods(unit);
    indentLevel--;
    println("}");
  }

  //}}}
  //{{{ protected void emitPackage(JavaCompilationUnit unit)

  protected void emitPackage(JavaCompilationUnit unit)
  {
    println("package " + unit.getPackageName() + ";");
    println();
  }

  //}}}
  //{{{ protected void emitImports(JavaCompilationUnit unit)

  protected void emitImports(JavaCompilationUnit unit)
  {
    Iterator iter = unit.fetchImportedIterator();
    if (iter.hasNext()) {
      foldOpen("imports");
      while (iter.hasNext()) {
	println("import " + iter.next() + ";");
      }
      foldClose();
      println();
    }
  }

  //}}}
  //{{{ protected void emitExtends(JavaCompilationUnit unit)

  protected void emitExtends(JavaCompilationUnit unit)
  {
    String superClass = unit.getSuperClass();
    if (!superClass.equals("")) {
      indentLevel++;
      println("extends " + superClass);
      indentLevel--;
    }
  }

  //}}}
  //{{{ protected void emitAttributes(JavaCompilationUnit unit)

  protected void emitAttributes(JavaCompilationUnit unit)
  {
    Iterator iter = unit.fetchAttributeIterator();
    if (iter.hasNext()) {
      foldOpen("attributes");
      while (iter.hasNext()) {
	emitAttribute((JavaAttribute)iter.next());
      }
      foldClose();
      println();
    }
  }

  //}}}
  //{{{ protected void emitAttribute(JavaAttribute attribute)

  protected void emitAttribute(JavaAttribute attr)
  {
    String access = attr.getAccess().yield();
    String type = attr.getType();
    String name = attr.getName();

    println(access + " " + type + " " + name + ";");
  }

  //}}}
  //{{{ protected void emitMethods(JavaCompilationUnit unit)

  protected void emitMethods(JavaCompilationUnit unit)
  {
    Iterator iter = unit.fetchMethodIterator();
    while (iter.hasNext()) {
      emitMethod((JavaMethod)iter.next());
    }
  }

  //}}}
  //{{{ protected void emitMethod(JavaMethod method)

  protected void emitMethod(JavaMethod method)
  {
  }

  //}}}

  //{{{ void print(String string)

  void print(String string)
  {
    for (int i=0; i<indentLevel; i++) {
      writer.write("  ");
    }
    writer.print(string);
  }

  //}}}
  //{{{ void println(String string)

  void println(String string)
  {
    print(string);
    writer.println();
  }

  //}}}
  //{{{ void println()

  void println()
  {
    writer.println();
  }

  //}}}

  //{{{ void foldOpen(String header)

  void foldOpen(String header)
  {
    if (getGeneratorContext().getBoolean("folding")) {
      println("//{{" + "{ " + header);
      println();
    }
  }

  //}}}
  //{{{ void foldClose()

  void foldClose()
  {
    if (getGeneratorContext().getBoolean("folding")) {
      println();
      println("//}}" + "}");
    }
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
}
