package org.autocode.generator.c.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.c.*;
import org.autocode.generator.c.repository.*;

import java.util.*;

//}}}

public class Accessor
  extends CGeneratorPlugin
{
  //{{{ private void addField(unit, typeContext, fieldContext, name, type)

  private void addField(CGenerator generator, CCompilationUnit unit,
			PropertyContext typeContext,
			PropertyContext fieldContext,
			String fieldName, String fieldType)
  {
    boolean isStatic = fieldContext.getBoolean("static");

    Field field = new Field(fieldName, fieldType, isStatic);

    String structName = generator.typeName(typeContext.getName());

    Struct structure = unit.getStruct(structName);

    if (structure == null) {
      structure = new Struct(structName);
      unit.putStruct(structName, structure);
    }

    if (!structure.containsFieldValue(field)) {
      structure.addField(field);
    }
  }

  //}}}

  //{{{ public void generateGet(generator, type, field, operation)

  public void generateGet(CGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String field_type = generator.fieldTypeName(fieldTypeContext);

    String typeName = typeContext.getName();
    String fieldName = fieldContext.getName();
    String func_name = generator.functionName("get-" + typeName
					      + "-" + fieldName);

    String field_name = generator.fieldName(fieldName);

    FormalParameter param
      = new FormalParameter("self", generator.typeName(typeName));

    FunctionBody body = new FunctionBody();
    body.addLine("return self->" + field_name + ";");

    Function function
      = createFunction(operationContext, func_name, field_type, body);

    function.addFormalParameter(param);

    CCompilationUnit unit = generator.getCompilationUnit();
    unit.addFunction(function);

    addField(generator, unit, typeContext, fieldContext,
	     field_name, field_type);
  }

  //}}}
  /*
  //{{{ public void generateSet(generator, type, field, operation)

  public void generateSet(CGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("set-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    String paramName = generator.javaParameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, attrType);
    param.setDescription(fieldContext.getString("description"));

    MethodBody body = new MethodBody();
    body.addLine(attrName + " = " + paramName + ";");
    CMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("sets the " + fieldContext.getString("description") + ".");

    CCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateInit(CGenerator generator)

  public void generateInit(CGenerator generator,
			   PropertyContext typeContext,
			   PropertyContext fieldContext,
			   PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getBoolean("collection")) {
      return;
    }

    CCompilationUnit unit = generator.getCompilationUnit();

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

    CMethod method = createMethod(operationContext, methodName, "void", body);
    method.setDescription("initializes the "
			  + fieldContext.getString("description") + ".");
    unit.addMethod(method);
  }

  //}}}
  */
}
