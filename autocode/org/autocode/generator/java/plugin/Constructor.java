package org.autocode.generator.java;

//{{{ imports

import org.autocode.*;
import org.autocode.support.*;
import org.autocode.generator.*;
import org.autocode.bootstrap.*;
import org.autocode.bootstrap.generator.java.*;
import org.autocode.bootstrap.generator.repository.*;

import java.util.*;

//}}}

public class ConstructorPlugin
  extends JavaGeneratorPlugin
{
  //{{{ public void generateConstructors(JavaGenerator generator)

  public void generateConstructors(JavaGenerator generator)
  {
    CompoundType type = (CompoundType)getType();

    JavaCompilationUnit unit = generator.getCompilationUnit();
    String constructorName = JavaGenerator.javaTypeName(type.getName());

    DataDefinition def = generator.getDataDefinition();
    String application = generator.getApplication();

    /* Generate a constructor with all field values as parameters,
       except list, map, set */

    MethodBody body = new MethodBody();
    JavaMethod constructor = createTypeMethod("constructors",
					      constructorName, null, body);

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
  }

  //}}}
}
