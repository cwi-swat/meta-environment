package org.autocode.generator.c.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.c.repository.*;

//}}}

public class CGeneratorPlugin
  implements GeneratorPlugin
{
  //{{{ public Function createFunction(opContext, name, type, body, static)

  public Function createFunction(PropertyContext operationContext,
			      String functionName, String typeName,
			      FunctionBody body)
  {
    boolean isStatic = operationContext.getBoolean("static");
 
    Function function = new Function(functionName, typeName, body, isStatic);

    return function;
  }

  //}}}
}
