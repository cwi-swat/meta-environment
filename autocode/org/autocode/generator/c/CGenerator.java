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

  private Map unitMap;

  private String typePrefix;
  private String fieldTypePrefix;

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
    Enum enumeration = new Enum(enumName(enumContext.getName()));
    Iterator elements = enumContext.getValueSet("element").iterator();
    int value = 0;
    while (elements.hasNext()) {
      String identifier = enumName((String)elements.next());
      EnumElement element = new EnumElement(identifier, value++);
      enumeration.addElement(element);
    }

    compilationUnit.addEnum(enumeration);
  }

  //}}}
  //{{{ protected void generateArray(PropertyContext arrayContext)

  protected void generateArray(PropertyContext arrayContext)
  {
  }

  //}}}

  //{{{ protected void generateField(typeContext, fieldContext)

  protected void generateField(PropertyContext typeContext,
			       PropertyContext fieldContext)
  {
    PropertyContext fieldTypeContext
      = new PropertyContext(fieldContext, "type");
    fieldTypePrefix = fieldTypeContext.getString("prefix");

    super.generateField(typeContext, fieldContext);
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
    emitEnums();
    emitTypedefs();
    emitFunctionDeclarations(false);

    println();
    println("#endif /* " + protectionMacro + " */");
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
  //{{{ protected void emitEnums()

  protected void emitEnums()
  {
    foldOpen("enums");
    Iterator iter = compilationUnit.fetchEnumIterator();
    while (iter.hasNext()) {
      Enum enumeration = (Enum)iter.next();
      emitEnum(enumeration);
    }
    foldClose();
  }

  //}}}
  //{{{ protected void emitEnum(Enum enumeration)

  protected void emitEnum(Enum enumeration)
  {
    print("typedef enum { ");
    Iterator elems = enumeration.fetchElementIterator();
    int value = 0;
    while (elems.hasNext()) {
      EnumElement elem = (EnumElement)elems.next();
      print(elem.getIdentifier());
      if (elem.getValue() != value) {
	value = elem.getValue();
	print("=" + value);
      }
      if (elems.hasNext()) {
	print(", ");
      }
      value++;
    }
    println(" } " + enumeration.getName() + ";");
  }

  //}}}
  //{{{ protected void emitTypedefs()

  protected void emitTypedefs()
  {
    foldOpen("typedefs");
    Iterator iter = compilationUnit.fetchStructIterator();
    while (iter.hasNext()) {
      Struct structure = (Struct)iter.next();
      String typeName = structure.getName();
      String structName = structName(typeName);
      println("typedef struct " + structName + " *" + typeName + ";");
    }
    foldClose();
  }

  //}}}
  //{{{ protected void emitFunctionDeclarations(boolean statics)

  protected void emitFunctionDeclarations(boolean statics)
  {
    foldOpen("function declarations");
    Iterator iter = compilationUnit.fetchFunctionIterator();
    while (iter.hasNext()) {
      Function func = (Function)iter.next();
      if (func.isStatic() == statics) {
	print(buildFunctionDeclaration(func));
	println(";");
      }
    }
    foldClose();
  }

  //}}}
  //{{{ protected String buildFunctionDeclaration(Function func)

  protected String buildFunctionDeclaration(Function func)
  {
    StringBuffer buf = new StringBuffer();

    buf.append(func.getReturnValue());
    buf.append(" ");
    buf.append(func.getName());
    buf.append("(");
    Iterator iter = func.fetchFormalParameterIterator();
    while (iter.hasNext()) {
      FormalParameter param = (FormalParameter)iter.next();
      buf.append(param.getType());
      buf.append(" ");
      buf.append(param.getName());
      if (iter.hasNext()) {
	buf.append(", ");
      }
    }
    buf.append(")");

    return buf.toString();
  }

  //}}}

  //{{{ protected void emitSource()

  protected void emitSource()
  {
    emitIncludes(compilationUnit.fetchSourceIncludeIterator());
    println();
    emitStructs();
    println();
    emitFunctions();
  }

  //}}}
  //{{{ protected void emitStructs()

  protected void emitStructs()
  {
    Iterator iter = compilationUnit.fetchStructIterator();
    while (iter.hasNext()) {
      Struct structure = (Struct)iter.next();
      emitStruct(structure);
    }
  }

  //}}}
  //{{{ protected void emitStruct(Struct structure)

  protected void emitStruct(Struct structure)
  {
    String typeName = structure.getName();
    String structName = structName(typeName);
    foldOpen("struct " + structName);
    println("struct " + structName);
    println("{");
    Iterator iter = structure.fetchFieldIterator();
    indentLevel++;
    while (iter.hasNext()) {
      Field field = (Field)iter.next();
      emitField(field);
    }
    indentLevel--;
    println("};");
    foldClose();
  }

  //}}}
  //{{{ protected void emitField(Field field)

  protected void emitField(Field field)
  {
    println(field.getType() + " " + field.getName() + ";");
  }

  //}}}
  //{{{ protected void emitFunctions()

  protected void emitFunctions()
  {
    Iterator iter = compilationUnit.fetchFunctionIterator();
    while (iter.hasNext()) {
      Function function = (Function)iter.next();
      emitFunction(function);
    }
  }

  //}}}
  //{{{ protected void emitFunction(Function function)

  protected void emitFunction(Function function)
  {
    String decl = buildFunctionDeclaration(function);
    foldOpen(decl);
    println(decl);
    println("{");
    function.getBody().emit(indentLevel+1, writer);
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
      println("/*{{" + "{  " + header + " */");
      println();
    }
  }

  //}}}
  //{{{ void foldClose()

  void foldClose()
  {
    if (getGeneratorContext().getBoolean("folding")) {
      println();
      println("/*}}" + "}  */");
    }
  }

  //}}}

  //{{{ private String typePrefix(String name)

  private String typePrefix(String name)
  {
    return typePrefix + name;
  }

  //}}}
  //{{{ private String fieldTypeprefix(String name)

  private String fieldTypePrefix(String name)
  {
    if (fieldTypePrefix != null) {
      return fieldTypePrefix + name;
    }

    return typePrefix(name);
  }

  //}}}

  //{{{ private void addHeaderIncludes(Set includes)

  private void addHeaderIncludes(Set includes)
  {
    Iterator iter = includes.iterator();

    while (iter.hasNext()) {
      String include = (String)iter.next();
      getCompilationUnit().addHeaderInclude(new Include(include, true));
    }
  }

  //}}}

  //{{{ public String fieldTypeName(PropertyContext fieldTypeContext)

  public String fieldTypeName(PropertyContext fieldTypeContext)
  {
    String fieldTypeName = fieldTypeContext.getName();

    String typeName = fieldTypeContext.getString("implementation");
    if (typeName != null) {
      PropertyContext implementationContext
	= new PropertyContext(fieldTypeContext, "implementation");
      //Set includes = implementationContext.getValueSet("include");
      Set includes = fieldTypeContext.getValueSet("include");
      addHeaderIncludes(includes);
      return typeName;
    }

    String type = AutocodeGenerator.typeNameJava(fieldTypeName);

    return fieldTypePrefix(type);
  }

  //}}}
  //{{{ public String typeName(String name)

  public String typeName(String name)
  {
    String type = AutocodeGenerator.typeNameJava(name);

    return typePrefix(type);
  }

  //}}}
  //{{{ public String fieldName(String name)

  public String fieldName(String name)
  {
    return AutocodeGenerator.fieldNameC(name);
  }

  //}}}
  //{{{ public String parameterName(String name)

  public String parameterName(String name)
  {
    return AutocodeGenerator.parameterNameJava(name);
  }

  //}}}

  //{{{ public String functionName(String name)

  public String functionName(String name)
  {
    String method = AutocodeGenerator.methodNameJava(name);

    return typePrefix(method);
  }

  //}}}
  //{{{ public String macroName(String name)

  public String macroName(String name)
  {
    return AutocodeGenerator.constantNameJava(name);
  }

  //}}}
  //{{{ public String structName(String name)

  public String structName(String name)
  {
    return "_" + name;
  }

  //}}}
  //{{{ public String enumName(String name)

  public String enumName(String name)
  {
    return typeName(name);
  }

  //}}}
  //{{{ public String enumElementName(String name)

  public String enumElementName(String name)
  {
    return macroName(name);
  }

  //}}}
}
