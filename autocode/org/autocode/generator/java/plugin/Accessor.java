package org.autocode.generator.java.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.*;
import org.autocode.generator.java.repository.*;

import java.util.*;

//}}}

public class Accessor
  extends JavaGeneratorPlugin
{
  //{{{ private void addAttribute(compilationUnit, fieldContext, name, type)

  private void addAttribute(JavaCompilationUnit unit,
			    PropertyContext fieldContext,
			    String attrName, String attrType)
  {
    boolean isStatic = fieldContext.getBoolean("static");
    boolean isFinal = fieldContext.getBoolean("final");

    JavaAccessSpecifier access
      = JavaAccessSpecifier.parse(fieldContext.getString("access"));

    JavaAttribute attr =
      new JavaAttribute(attrName, attrType, access, isFinal, isStatic);

    String desc = "the " + fieldContext.getString("description") + ".";
    attr.setDescription(desc);

    if (!unit.hasAttribute(attr)) {
      unit.addAttribute(attr);
    }
  }

  //}}}

  //{{{ public void generateGet(generator, type, field, operation)

  public void generateGet(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("get-" + fieldName);

    String attrName = generator.attributeName(fieldName);
    MethodBody body = new MethodBody();
    body.addLine("return " + attrName + ";");

    JavaMethod method
      = createMethod(operationContext, methodName, attrType, body);
    method.setDescription("gets the " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateSet(generator, type, field, operation)

  public void generateSet(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("set-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    String paramName = generator.parameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, attrType);
    param.setDescription(fieldContext.getString("description"));

    MethodBody body = new MethodBody();
    body.addLine(attrName + " = " + paramName + ";");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("sets the " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateInit(JavaGenerator generator)

  public void generateInit(JavaGenerator generator,
			   PropertyContext typeContext,
			   PropertyContext fieldContext,
			   PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getBoolean("collection")) {
      return;
    }

    JavaCompilationUnit unit = generator.getCompilationUnit();

    String fieldName = fieldContext.getName();
    String collection = fieldTypeContext.getString("interface");
    String methodName
      = generator.javaMethodName("init-" + fieldName + "-" + collection);

    String implementation = fieldTypeContext.getString("implementation");
    PropertyContext implementationContext
      = new PropertyContext(fieldTypeContext, "implementation");
    Set imports = implementationContext.getValueSet("import");
    unit.mergeImportedCollection(imports);

    MethodBody body = new MethodBody();
    String attrName = generator.attributeName(fieldName);
    body.addLine(attrName + " = new " + implementation + "();");

    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.setDescription("initializes the "
			  + fieldContext.getString("description") + ".");
    unit.addMethod(method);

    String attrType = generator.typeName(fieldTypeContext);
    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
}
