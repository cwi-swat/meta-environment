package org.autocode.generator.java;

//{{{ imports

import org.autocode.*;
import org.autocode.generator.*;
import org.autocode.bootstrap.*;
import org.autocode.bootstrap.generator.repository.*;
import org.autocode.bootstrap.generator.java.*;
import org.autocode.support.*;

//}}}

public class Accessor
  implements JavaGeneratorPlugin
{
  //{{{ private void addAttribute(application, type, field, unit)

  private void addAttribute(String application, Type type, Field field,
			    JavaCompilationUnit unit)
  {
    String fieldName = JavaGenerator.javaFieldName(field.getName());
    String typeName = JavaGenerator.javaTypeName(field.getType());
    TypedMap fieldAttributes = createFieldAttributeMap(application,
						       type.getName(),
						       field.getName());

    JavaAttribute attr = new JavaAttribute(fieldName, typeName, fieldAttributes);
    if (!unit.hasAttribute(attr)) {
      unit.addAttribute(attr);
    }
  }

  //}}}

  //{{{ public void generateGet(JavaGenerator generator)

  public void generateGet(JavaGenerator generator, PropertyContext context,
			  String typeName, String fieldName)
  {
    String fieldName = generator.attributeName(fieldName);
    String typeName = generator.className(getFieldType(context, fieldName));
    String methodName = generator.methodName("get-" + fieldName);

    MethodBody body = new MethodBody();
    body.addLine("return " + fieldName + ";");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(createFieldMethod("get", methodName, typeName, body));

    addAttribute(generator.getApplication(), type, field, unit);
  }

  //}}}
  //{{{ public void generateSet(JavaGenerator generator)

  public void generateSet(JavaGenerator generator)
  {
    Field field = getField();
    Type type = getType();

    if (field.getType().instanceOfCollectionType()) {
      return;
    }

    JavaCompilationUnit unit = generator.getCompilationUnit();

    String fieldName = JavaGenerator.javaFieldName(field.getName());
    String typeName = JavaGenerator.javaTypeName(field.getType());
    String methodName = JavaGenerator.javaMethodName("set-" + field.getName());

    String paramName = JavaGenerator.javaParameterName(field.getName());
    FormalParameter arg = new FormalParameter(paramName, typeName);


    MethodBody body = new MethodBody();
    body.addLine(fieldName + " = " + paramName + ";");
    JavaMethod method = createFieldMethod("set", methodName, "void", body);
    method.addFormalParameter(arg);

    unit.addMethod(method);

    addAttribute(generator.getApplication(), type, field, unit);
  }

  //}}}
  //{{{ public void generateInit(JavaGenerator generator)

  public void generateInit(JavaGenerator generator)
  {
    Field field = getField();
    Type type = getType();

    DataDefinition def = getDataDefinition();

    BasicType fieldType = field.getType();

    if (!fieldType.instanceOfCollectionType()) {
      return; /* <PO> need some mechanism to specify which operations
		 are valid for which builtin types */
    }

    CollectionType ctype = (CollectionType)fieldType;
    String cname = ctype.getCollectionName();

    JavaCompilationUnit unit = generator.getCompilationUnit();

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

    addAttribute(generator.getApplication(), type, field, unit);
  }

  //}}}
}
