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
      String paramName = generator.parameterName(fieldName);
      String paramType = generator.typeName(fieldTypeContext);

      if (fieldTypeContext.getBoolean("collection")) {
	String collectionName = fieldTypeContext.getString("interface");
	String init = generator.javaMethodName("init-" + fieldName
					       + "-" + collectionName);
	body.addLine(init + "();");
      } else {
	FormalParameter param = new FormalParameter(paramName, paramType);
	param.setDescription("the " + fieldContext.getString("description"));
	constructor.addFormalParameter(param);

	String setMethod = generator.javaMethodName("set-" + fieldName);
	body.addLine(setMethod + "(" + paramName + ");");
      }
    }

    generator.getCompilationUnit().addMethod(constructor);
  }

  //}}}
}
