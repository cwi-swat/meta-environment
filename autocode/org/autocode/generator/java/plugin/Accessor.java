package org.autocode.generator.java.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.*;
import org.autocode.generator.java.repository.*;

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

    String desc = fieldContext.getString("description");
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
    method.setDescription("get " + fieldContext.getString("description"));

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

    String paramName = generator.javaParameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, attrType);
    param.setDescription(fieldContext.getString("description"));

    MethodBody body = new MethodBody();
    body.addLine(attrName + " = " + paramName + ";");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("set " + fieldContext.getString("description"));

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
    String fieldName = fieldContext.getName();
    String fieldTypeName = fieldContext.getString("type");

    /*
    Field field = getField();
    Type type = getType();

    DataDefinition def = getDataDefinition();

    BasicType fieldType = field.getType();

    if (!fieldType.instanceOfCollectionType()) {
      return;
    }

    CollectionType ctype = (CollectionType)fieldType;
    String cname = ctype.getCollectionName();

    String fieldName = JavaGenerator.javaFieldName(field.getName());
    String typeName = JavaGenerator.javaTypeName(field.getType());
    String methodName = JavaGenerator.javaMethodName("init-" + field.getName()
					       + "-" + cname);

    MethodBody body = new MethodBody();

    String propName = cname + ".implementation";
    FieldProperty prop = def.getFieldProperty(propName,
					      generator.getApplication(),
					      type.getName(),
					      field.getName());
    String impl = prop.getSingletonValue();
    body.addLine(fieldName + " = new " + impl + "();");

    JavaMethod method = createFieldMethod("init", methodName, "void", body);

    unit.addMethod(method);
    */

    JavaCompilationUnit unit = generator.getCompilationUnit();

    //addAttribute(unit, fieldContext);
  }

  //}}}
}
