package org.autocode.generator.java.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.repository.*;

//}}}

public class JavaGeneratorPlugin
  implements GeneratorPlugin
{
  //{{{ public JavaMethod createMethod(operation, name, resultType, body)

  public JavaMethod createMethod(PropertyContext operationContext,
				 String methodName, String typeName,
				 MethodBody body)
  {
    boolean isAbstract = operationContext.getBoolean("abstract");
    boolean isStatic = operationContext.getBoolean("static");
    boolean isFinal = operationContext.getBoolean("final");
 
    String access = operationContext.getString("access");
    JavaAccessSpecifier accessSpecifier = JavaAccessSpecifier.parse(access);

    JavaMethod method = new JavaMethod(methodName, typeName, accessSpecifier,
				       isAbstract, isFinal, isStatic, body);

    return method;
  }

  //}}}
  //{{{ public JavaMethod createMethod(operation, name, body)

  public JavaMethod createConstructor(PropertyContext operationContext,
				      String name, MethodBody body)
  {
    return createMethod(operationContext, name, null, body);
  }

  //}}}
}
