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

public class Constructor
  extends JavaGeneratorPlugin
{
  //{{{ public void generateConstructor(JavaGenerator generator)

  public void generateConstructor(JavaGenerator generator,
				  PropertyContext typeContext,
				  PropertyContext operationContext)
  {
    String constructorName = generator.constructorName(typeContext.getName());

    MethodBody body = new MethodBody();

    JavaMethod constructor
      = createConstructor(operationContext, constructorName, body);

    Iterator iter = typeContext.getValueSet("field").iterator();
    while (iter.hasNext()) {
      String fieldName = (String)iter.next();
      PropertyContext fieldContext
	= new PropertyContext(typeContext, "field", fieldName);
      PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
      String attrName = generator.parameterName(fieldName);
      String attrType = generator.typeName(fieldTypeContext);
      FormalParameter param = new FormalParameter(attrName, attrType);
      param.setDescription(fieldContext.getString("description"));
      constructor.addFormalParameter(param);
    }

    generator.getCompilationUnit().addMethod(constructor);
    /*
    Iterator iter = type.fetchFieldIterator();
    while (iter.hasNext()) {
      Field field = (Field)iter.next();

      BasicType fieldType = field.getType();

      if (fieldType.instanceOfCollectionType()) {
	CollectionType collection = (CollectionType)fieldType;
	String collName = collection.getCollectionName();
	String init = JavaGenerator.javaMethodName("init-" + field.getName()
					       + "-" + collName);
	body.addLine(init + "();");
      } else {
	String paramName = JavaGenerator.javaParameterName(field.getName());
	String typeName = JavaGenerator.javaTypeName(fieldType);
	FormalParameter formal = new FormalParameter(paramName, typeName);
	constructor.addFormalParameter(formal);

	String setMethod = JavaGenerator.javaMethodName("set-" + field.getName());
	body.addLine(setMethod + "(" + paramName + ");");
      }
    }

    unit.addMethod(constructor);
    */
  }

  //}}}
}
