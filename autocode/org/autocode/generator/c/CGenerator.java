package org.autocode.generator.c;

//{{{ imports

import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.Repository;
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

  private Map unitMap;

  private String prefix;
  private String typePrefix;

  //}}}

  //{{{ public CGenerator()

  public CGenerator()
  {
    unitMap = new HashMap();
  }

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
    prefix = generatorContext.getString("prefix");
    repository = new Repository();
    super.generate(generatorContext);
  }

  //}}}
  //{{{ protected void generateType(PropertyContext typeContext)

  protected void generateType(PropertyContext typeContext)
  {
    String typeName = typeContext.getName();
    String module = typeContext.getString("module");
    typePrefix = typeContext.getString("prefix");

    compilationUnit = (CCompilationUnit)unitMap.get(module);
    if (compilationUnit == null) {
      compilationUnit = new CCompilationUnit(module);
      unitMap.put(module, compilationUnit);
      repository.addCompilationUnit(compilationUnit);
    }

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

  //{{{ protected void generateVerbatim(String source)

  protected void generateVerbatim(String source)
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
      compilationUnit = (CCompilationUnit)iter.next();
      String module = compilationUnit.getModule();
      String fileName = root + File.separatorChar + module;

      System.out.println("emitting module : " + module);

      File source = new File(fileName + ".c");
      File header = new File(fileName + ".h");

      compilationUnit.addSourceInclude(new Include(module + ".h", false));

      writer = new PrintWriter(new FileWriter(header));
      emitHeader();
      writer.close();

      writer = new PrintWriter(new FileWriter(source));
      emitSource();
      writer.close();

      writer.close();
    }
  }

  //}}}
  //{{{ protected void emitHeader()

  protected void emitHeader()
  {
    String protectionMacro
      = "__" + macroName(compilationUnit.getModule()) + "_H";
    println("#ifndef " + protectionMacro);
    println("#define " + protectionMacro);
    println();

    emitIncludes(compilationUnit.fetchHeaderIncludeIterator());

    println();
    println("#endif /* " + protectionMacro + " */");
  }

  //}}}
  //{{{ protected void emitSource()

  protected void emitSource()
  {
    emitIncludes(compilationUnit.fetchSourceIncludeIterator());
  }

  //}}}

  //{{{ protected void emitIncludes(Iterator includes)

  protected void emitIncludes(Iterator includes)
  {
    foldOpen("includes");
    while (includes.hasNext()) {
      Include include = (Include)includes.next();
      print("#include ");
      if (include.isSystem()) {
	println("<" + include.getFile() + ">");
      } else {
	println("\"" + include.getFile() + "\"");
      }
    }
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

  //{{{ private String prefix(String name)

  private String prefix(String name)
  {
    if (typePrefix != null) {
      return typePrefix + name;
    }

    return prefix + name;
  }

  //}}}
  //{{{ public String typeName(PropertyContext fieldTypeContext)

  public String typeName(PropertyContext fieldTypeContext)
  {
    String fieldTypeName = fieldTypeContext.getName();

    String typeName = fieldTypeContext.getString("implementation");
    if (typeName != null) {
      PropertyContext interfaceContext
	= new PropertyContext(fieldTypeContext, "implementation");
      Set includes = interfaceContext.getValueSet("include");
      getCompilationUnit().mergeHeaderIncludeCollection(includes);
      return typeName;
    }

    String type = AutocodeGenerator.typeNameJava(fieldTypeContext.getName());
    return prefix(type);
  }

  //}}}
  //{{{ public String attributeName(String name)

  public String attributeName(String name)
  {
    return AutocodeGenerator.attributeNameJava(name);
  }

  //}}}
  //{{{ public String methodName(String name)

  public String methodName(String name)
  {
    String method = AutocodeGenerator.methodNameJava(name);

    return prefix(method);
  }

  //}}}
  //{{{ public String parameterName(String name)

  public String parameterName(String name)
  {
    return AutocodeGenerator.parameterNameJava(name);
  }

  //}}}
  //{{{ public String macroName(String name)

  public String macroName(String name)
  {
    return AutocodeGenerator.constantNameJava(name);
  }

  //}}}
}
