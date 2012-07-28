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

    CodeBlock body = new CodeBlock();

    JavaMethod constructor
      = createConstructor(operationContext, constructorName, body);

    //{{{ Add arguments needed for call to super

    PropertyContext superArgsContext = new PropertyContext(operationContext,
							   "super", "args");
    Iterator iter = superArgsContext.getValueSet("field").iterator();
    if (iter.hasNext()) {
      StringBuffer superArgs = new StringBuffer();
      boolean first = true;
      while (iter.hasNext()) {
	String arg = (String)iter.next();
	PropertyContext argContext
	  = new PropertyContext(superArgsContext, "field", arg);
	PropertyContext argTypeContext = new PropertyContext(argContext, "type");
	String paramName = generator.parameterName(arg);
	String paramType = generator.typeName(argTypeContext);
	FormalParameter param = new FormalParameter(paramName, paramType);
	constructor.addFormalParameter(param);
	if (first) {
	  first = false;
	} else {
	  superArgs.append(", ");
	}
	superArgs.append(paramName);
      }
      body.addLine("super(" + superArgs.toString() + ");");
    }

    //}}}
    //{{{ Add field initialization arguments

    iter = typeContext.getValueSet("field").iterator();
    while (iter.hasNext()) {
      String fieldName = (String)iter.next();
      PropertyContext fieldContext
	= new PropertyContext(typeContext, "field", fieldName);
      PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
      String paramName = generator.parameterName(fieldName);
      String paramType = generator.typeName(fieldTypeContext);

      if (fieldTypeContext.getBoolean("collection")) {
	String collectionName = fieldTypeContext.getString("interface");
	String init = generator.methodName("init-" + fieldName
					   + "-" + collectionName);
	body.addLine(init + "();");
      } else {
	FormalParameter param = new FormalParameter(paramName, paramType);
	param.setDescription("the " + fieldContext.getString("description"));
	constructor.addFormalParameter(param);

	String setMethod = generator.methodName("set-" + fieldName);
	body.addLine(setMethod + "(" + paramName + ");");
      }
    }

    //}}}

    String typeName = generator.typeName(typeContext.getName());
    constructor.setDescription("creates a new " + typeName + ".");

    generator.getCompilationUnit().addMethod(constructor);
  }

  //}}}
}
