package org.autocode.generator.c;

//{{{ imports

import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.c.repository.*;

import java.io.*;
import java.util.*;

//}}}

public class CGenerator
  extends AutocodeGenerator
{
  //{{{ attributes 

  private Repository repository;
  private CCompilationUnit compilationUnit;

  private PrintWriter writer;
  private int indentLevel;

  //}}}

  //{{{ public CCompilationUnit getCompilationUnit()

  public CCompilationUnit getCompilationUnit()
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
    String typeName = typeContext.getName();
    String path = typeContext.getString("path");

    compilationUnit = new CCompilationUnit(path);
    repository.addCompilationUnit(compilationUnit);

    super.generateType(typeContext);
  }

  //}}}
  //{{{ protected void generateEnum(PropertyContext enumContext)

  protected void generateEnum(PropertyContext enumContext)
  {
  }

  //}}}
  //{{{ protected void generateArray(PropertyContext arrayContext)

  protected void generateArray(PropertyContext arrayContext)
  {
  }

  //}}}

  //{{{ public void emit(PropertyContext generatorContext) throws IOException

  public void emit(PropertyContext generatorContext) throws IOException
  {
    String root = generatorContext.getString("rootdir");

    Iterator iter = repository.fetchCompilationUnitIterator();
    while (iter.hasNext()) {
      indentLevel = 0;
      CCompilationUnit unit = (CCompilationUnit)iter.next();
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
  //{{{ protected void emitCompilationUnit(CCompilationUnit unit)

  protected void emitCompilationUnit(CCompilationUnit unit)
  {
    emitPackage(unit);
    emitImports(unit);
    println(unit.getAccess().yield() + " class " + unit.getClassName());
    emitExtends(unit);
    println("{");
    indentLevel++;
    emitAttributes(unit);
    emitMethods(unit);
    indentLevel--;
    println("}");
  }

  //}}}
  //{{{ protected void emitPackage(CCompilationUnit unit)

  protected void emitPackage(CCompilationUnit unit)
  {
    println("package " + unit.getPackageName() + ";");
    println();
  }

  //}}}
  //{{{ protected void emitImports(CCompilationUnit unit)

  protected void emitImports(CCompilationUnit unit)
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
  //{{{ protected void emitExtends(CCompilationUnit unit)

  protected void emitExtends(CCompilationUnit unit)
  {
    String superClass = unit.getSuperClass();
    if (!superClass.equals("")) {
      indentLevel++;
      println("extends " + superClass);
      indentLevel--;
    }
  }

  //}}}

  //{{{ protected void emitAttributes(CCompilationUnit unit)

  protected void emitAttributes(CCompilationUnit unit)
  {
    Iterator iter = unit.fetchAttributeIterator();
    if (iter.hasNext()) {
      foldOpen("attributes");
      while (iter.hasNext()) {
	emitAttribute((CAttribute)iter.next());
      }
      foldClose();
      println();
    }
  }

  //}}}
  //{{{ protected void emitAttribute(CAttribute attribute)

  protected void emitAttribute(CAttribute attr)
  {
    String access = attr.getAccess().yield();
    String type = attr.getType();
    String name = attr.getName();
    String description = attr.getDescription();

    emitAttributeDocumentation(attr);
    println(access + " " + type + " " + name + ";");
    println();
  }

  //}}}
  //{{{ protected void emitAttributeDocumentation(CAttribute attr)

  protected void emitAttributeDocumentation(CAttribute attr)
  {
    if (getGeneratorContext().getBoolean("javadoc")) {
      String desc = attr.getDescription();
      if (desc != null ) {
	println("/** " + capitalize(desc) + " */");
      }
    }
  }

  //}}}

  //{{{ protected void emitMethods(CCompilationUnit unit)

  protected void emitMethods(CCompilationUnit unit)
  {
    for (Iterator i = unit.fetchMethodIterator(); i.hasNext();) {
      emitMethod((CMethod)i.next());
    }
  }

  //}}}
  //{{{ protected void emitMethodDocumentation(CMethod method)

  protected void emitMethodDocumentation(CMethod method)
  {
    if (getGeneratorContext().getBoolean("javadoc")) {
      println("/**");

      String methodDescription = method.getDescription();
      if (methodDescription != null) {
	println("* " + capitalize(method.getDescription()));
      }

      Iterator iter = method.fetchFormalParameterIterator();
      if (iter.hasNext()) {
	println("*");
      }
      while (iter.hasNext()) {
	FormalParameter param = (FormalParameter)iter.next();
	println("* @param " + param.getName() + " " + param.getDescription());
      }

      println("*/");
    }
  }

  //}}}
  //{{{ protected void emitMethod(CMethod method)

  protected void emitMethod(CMethod method)
  {
    String decl = method.toString();

    foldOpen(decl);
    emitMethodDocumentation(method);
    println(decl);
    println("{");
    method.getBody().emit(indentLevel+1, writer);
    println("}");
    foldClose();
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

  //{{{ public String typeName(PropertyContext fieldTypeContext)

  public String typeName(PropertyContext fieldTypeContext)
  {
    String fieldTypeName = fieldTypeContext.getName();

    String typeName = fieldTypeContext.getString("interface");
    if (typeName != null) {
      PropertyContext interfaceContext
	= new PropertyContext(fieldTypeContext, "interface");
      Set imports = interfaceContext.getValueSet("import");
      getCompilationUnit().mergeImportedCollection(imports);
      return typeName;
    }

    typeName = fieldTypeContext.getString("implementation");
    if (typeName != null) {
      PropertyContext implementationContext
	= new PropertyContext(fieldTypeContext, "implementation");
      Set imports = implementationContext.getValueSet("import");
      getCompilationUnit().mergeImportedCollection(imports);
      return typeName;
    }

    return AutocodeGenerator.javaTypeName(fieldTypeContext.getName());
  }

  //}}}
  //{{{ public String attributeName(String name)

  public String attributeName(String name)
  {
    return AutocodeGenerator.javaAttributeName(name);
  }

  //}}}
  //{{{ public String methodName(String name)

  public String methodName(String name)
  {
    return AutocodeGenerator.javaMethodName(name);
  }

  //}}}
  //{{{ public String constructorName(String name)

  public String constructorName(String name)
  {
    return capitalize(methodName(name));
  }

  //}}}
  //{{{ public String parameterName(String name)

  public String parameterName(String name)
  {
    return AutocodeGenerator.javaParameterName(name);
  }

  //}}}
}
