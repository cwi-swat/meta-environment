package org.autocode.generator.java;

import org.autocode.*;
import org.autocode.generator.*;
import org.autocode.bootstrap.*;
import org.autocode.bootstrap.generator.repository.*;
import org.autocode.bootstrap.generator.java.*;

public class JavaGeneratorPlugin
  extends GeneratorPlugin
{
  //{{{ public JavaMethod createFieldMethod(op, name, typeName, body)

  public JavaMethod createFieldMethod(String operation, String methodName,
				      String typeName, MethodBody body)
  {
    JavaMethod method = new JavaMethod(methodName, typeName, body);
    DataDefinition def = getDataDefinition();
    Property prop =
      def.getFieldProperty("operations." + operation + ".access",
			   getApplication(), getType().getName(),
			   getField().getName());
    method.setAccess(JavaMethodAccess.parse(prop.getSingletonValue()));

    return method;
  }

  //}}}
  //{{{ public JavaMethod createTypeMethod(op, name, typeName, body)

  public JavaMethod createTypeMethod(String operation, String methodName,
				      String typeName, MethodBody body)
  {
    JavaMethod method = new JavaMethod(methodName, typeName, body);
    DataDefinition def = getDataDefinition();
    Property prop =
      def.getTypeProperty("operations." + operation + ".access",
			  getApplication(), getType().getName());
    method.setAccess(JavaMethodAccess.parse(prop.getSingletonValue()));

    return method;
  }

  //}}}
}
